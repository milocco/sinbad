/*********************************************************************
CombLayer : MNCPX Input builder
* File: essBuild/SupplyPipe.cxx
*
* Copyright (c) 2004-2014 by Stuart Ansell
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
****************************************************************************/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cmath>
#include <complex>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <boost/shared_ptr.hpp>
#include <boost/array.hpp>

#include "Exception.h"
#include "FileReport.h"
#include "GTKreport.h"
#include "NameStack.h"
#include "RegMethod.h"
#include "OutputLog.h"
#include "BaseVisit.h"
#include "BaseModVisit.h"
#include "support.h"
#include "stringCombine.h"
#include "MatrixBase.h"
#include "Matrix.h"
#include "Vec3D.h"
#include "Quaternion.h"
#include "localRotate.h"
#include "masterRotate.h"
#include "Surface.h"
#include "surfIndex.h"
#include "surfRegister.h"
#include "objectRegister.h"
#include "surfEqual.h"
#include "surfDIter.h"
#include "Quadratic.h"
#include "Plane.h"
#include "Cylinder.h"
#include "Line.h"
#include "Rules.h"
#include "varList.h"
#include "Code.h"
#include "FuncDataBase.h"
#include "HeadRule.h"
#include "Object.h"
#include "Qhull.h"
#include "Simulation.h"
#include "ModelSupport.h"
#include "MaterialSupport.h"
#include "LinkUnit.h"
#include "FixedComp.h"
#include "ContainedComp.h"
#include "LayerComp.h"
#include "pipeUnit.h"
#include "PipeLine.h"
#include "essSupplyPipe.h"

namespace essSystem
{

essSupplyPipe::essSupplyPipe(const std::string& Key) :
  attachSystem::FixedComp(Key,0),
  //ALB attachSystem::LayerComp(0),
  optName(""),
  pipeIndex(ModelSupport::objectRegister::Instance().cell(Key)),
  cellIndex(pipeIndex+1),Coaxial(Key+"CoAx"),nAngle(6)
  /*!
Constructor BUT ALL variable are left unpopulated.
\param Key :: Name for item in search
\param Opt :: optName
*/
{}

essSupplyPipe::essSupplyPipe(const essSupplyPipe& A) :
  attachSystem::FixedComp(A),
  //ALB attachSystem::LayerComp(A),
  optName(A.optName),
  pipeIndex(A.pipeIndex),cellIndex(A.cellIndex),
  NSegIn(A.NSegIn),Radii(A.Radii),Mat(A.Mat),Temp(A.Temp),
  ActiveFlag(A.ActiveFlag),Coaxial(A.Coaxial),
  layerOffset(A.layerOffset),PPts(A.PPts),
  nAngle(A.nAngle)
  /*!
Copy constructor
\param A :: essSupplyPipe to copy
*/
{}

essSupplyPipe&
essSupplyPipe::operator=(const essSupplyPipe& A)
  /*!
Assignment operator
\param A :: essSupplyPipe to copy
\return *this
*/
{
  if (this!=&A)
    {
      attachSystem::FixedComp::operator=(A);
      //ALB  attachSystem::LayerComp::operator=(A);
      cellIndex=A.cellIndex;
      NSegIn=A.NSegIn;
      Radii=A.Radii;
      Mat=A.Mat;
      Temp=A.Temp;
      ActiveFlag=A.ActiveFlag;
      Coaxial=A.Coaxial;
      layerOffset=A.layerOffset;
      PPts=A.PPts;
      nAngle=A.nAngle;
    }
  return *this;
}


essSupplyPipe::~essSupplyPipe()
  /*!
Destructor
*/
{}

void
essSupplyPipe::populate(const Simulation& System)
  /*!
Populate all the variables
\param System :: Simulation to use
*/
{
  ELog::RegMethod RegA("essSupplyPipe","populate");
  
  const FuncDataBase& Control=System.getDataBase();
  
  
  std::string numStr;
  NSegIn=Control.EvalPair<size_t>(optName+"NSegIn",keyName+"NSegIn");
  for(size_t i=0;i<=NSegIn;i++)
    {
      numStr=StrFunc::makeString(i);
      PPts.push_back(Control.EvalPair<Geometry::Vec3D>
(optName+"PPt"+numStr,keyName+"PPt"+numStr));
    }

  size_t aN(0);
  numStr=StrFunc::makeString(aN);
  while(Control.hasVariable(keyName+"Active"+numStr))
    {
      ActiveFlag.push_back
(Control.EvalVar<size_t>(keyName+"Active"+numStr));
      numStr=StrFunc::makeString(++aN);
    }

  const size_t NRadii=Control.EvalVar<size_t>(keyName+"NRadii");
  for(size_t i=0;i<NRadii;i++)
    {
      const std::string numStr=StrFunc::makeString(i);
      Radii.push_back(Control.EvalVar<double>(keyName+"Radius"+numStr));
      Mat.push_back
(ModelSupport::EvalMat<int>(Control,keyName+"Mat"+numStr));
      Temp.push_back(Control.EvalDefVar<double>(keyName+"Temp"+numStr,0.0));
    }
  return;
}
  

void
essSupplyPipe::createUnitVector(const attachSystem::FixedComp& FC,
const size_t layerIndex,
const size_t sideIndex)
  /*!
Create the unit vectors
\param FC :: Fixed unit that it is connected to
\param sideIndex :: Connection point to use as origin [0 for origin]
*/
{
  ELog::RegMethod RegA("essSupplyPipe","createUnitVector");

  FixedComp::createUnitVector(FC);
  const attachSystem::LayerComp* LC=
    dynamic_cast<const attachSystem::LayerComp*>(&FC);

  if (LC && sideIndex)
    {
      Origin=LC->getSurfacePoint(layerIndex,sideIndex-1);
      FC.selectAltAxis(sideIndex-1,X,Y,Z);
      //      ELog::EM<<"PIPE Ori "<<Origin<< " X "<<X<<" Y "<<Y<<" Z "<<Z<<ELog::endWarn;
    }
  return;
}

void
essSupplyPipe::insertInlet(const attachSystem::FixedComp& FC,
const size_t lSideIndex)
  /*!
Add a pipe to the hydrogen system:
\remark This should be called after the moderator has
been constructed and all objects inserted.
\param FC :: layer values
\param lSideIndex :: point for side of moderator
*/
{
  ELog::RegMethod RegA("essSupplyPipe","insertInlet");
  const attachSystem::LayerComp* LC=
    dynamic_cast<const attachSystem::LayerComp*>(&FC);
 
  if (!LC)
    throw ColErr::CastError<void>(0,"FixedComp to LayerComp");
  layerOffset=X*PPts[0].X()+Z*PPts[0].Z();
  Geometry::Vec3D Pt= Origin+layerOffset+Y*PPts[0].Y();
  //  ELog::EM<<"PIPE Origin  "<<Origin<<" layOff "<<layerOffset<<"Pt  "<<Pt<<ELog::endWarn;

  // GET Z Point from layer
  Geometry::Vec3D PtZ=LC->getSurfacePoint(0,lSideIndex);
  PtZ+=layerOffset;


  const int commonSurf=LC->getCommonSurf(lSideIndex);
  const std::string commonStr=(commonSurf) ?
    StrFunc::makeString(commonSurf) : "";
  if (PtZ!=Pt)
    Coaxial.addPoint(Pt);
  const size_t NL(LC->getNLayers());
  Coaxial.addSurfPoint
    (PtZ,LC->getLayerString(0,lSideIndex),commonStr);
  
  for(size_t index=2;index<NL;index+=2)
    {
      PtZ=LC->getSurfacePoint(index,lSideIndex);
      PtZ+=layerOffset;
      Coaxial.addSurfPoint
        (PtZ,LC->getLayerString(index,lSideIndex),commonStr);

    }

  for(size_t i=0;i<Radii.size();i++)
    Coaxial.addRadius(Radii[i],Mat[i],Temp[i]);

  return;
}

void
essSupplyPipe::addExtraLayer(const attachSystem::LayerComp& LC,
const size_t lSideIndex)
  /*!
Add extra Layer for a pre-mod or such
\param LC :: LayerComp Point [pre-mod for example]
\parma lSideIndex :: Layer to track through
*/
{
  ELog::RegMethod RegA("essSupplyPipe","addExtraLayer");
  
  const int commonSurf=LC.getCommonSurf(lSideIndex);
  const size_t NL(LC.getNLayers());

  const std::string commonStr=(commonSurf) ?
    StrFunc::makeString(commonSurf) : "";
  const Geometry::Vec3D PtZ=
    LC.getSurfacePoint(NL-1,lSideIndex)+
    layerOffset;
  Coaxial.addSurfPoint
    (PtZ,LC.getLayerString(NL-1,lSideIndex),commonStr);

  return;
}

void
essSupplyPipe::addOuterPoints()
  /*!
Add outside point to the pipework
*/
{
  ELog::RegMethod RegA("essSupplyPipe","addOuterPoints");

  Geometry::Vec3D Pt;
  // Outer Points
  for(size_t i=1;i<=NSegIn;i++)
    {
       Pt=Origin+X*PPts[i].X()+Y*PPts[i].Y()+Z*PPts[i].Z();
       Coaxial.addPoint(Pt);
    }
  return;
}

void
essSupplyPipe::setActive()
  /*!
Simple set the active units
*/
{
  ELog::RegMethod RegA("essSupplyPipe","setActive");
  //  ELog::EM<<"PIPE Active  "<<ActiveFlag.size()<<" ActiveFlag[0] "<<ActiveFlag[0]<<" ActiveFlag[1] "<<ActiveFlag[1]<<" ActiveFlag[2] "<<ActiveFlag[2]<<ELog::endWarn;

  for(size_t i=0;i<ActiveFlag.size();i++)
    Coaxial.setActive(i,ActiveFlag[i]);

  return;
}
  
void
essSupplyPipe::createAll(Simulation& System,
const attachSystem::FixedComp& FC,
const size_t orgLayerIndex,
const size_t orgSideIndex,
const size_t exitSideIndex)
  /*!
Generic function to create everything
\param System :: Simulation to create objects in
\param FC :: Fixed Base unit
\param sideIndex :: Link point for origin
\param sideIndex :: Link point for origin
\param laySideIndex :: layer to pass pipe though
*/
{
  ELog::RegMethod RegA("essSupplyPipe","createAll");
  populate(System);

  createUnitVector(FC,orgLayerIndex,orgSideIndex);
  insertInlet(FC,exitSideIndex);
  addOuterPoints();
  setActive();

  Coaxial.setNAngle(nAngle);
  Coaxial.createAll(System);

  return;
}



void
essSupplyPipe::createAll(Simulation& System,
const attachSystem::FixedComp& FC,
const size_t orgLayerIndex,
const size_t orgSideIndex,
const size_t exitSideIndex,
const attachSystem::LayerComp& LC,
const size_t extraSide)
  /*!
Generic function to create everything
\param System :: Simulation to create objects in
\param FC :: Fixed Base unit
\param orgLayerIndex :: Link point for origin
\param orgSideIndex :: Link point for start point
\param exitSideIndex :: layer to pass pipe out via
\param ExtraLC :: Point to extra Layer Object if exist [pre-mod]
\param extraSide :: Side to track through object
*/
{
  ELog::RegMethod RegA("essSupplyPipe","createAll<LC>");
  populate(System);

  createUnitVector(FC,orgLayerIndex,orgSideIndex);
  insertInlet(FC,exitSideIndex);
  addExtraLayer(LC,extraSide);
  addOuterPoints();
  setActive();
  Coaxial.setNAngle(nAngle);
  Coaxial.createAll(System);
  return;
}
  
} // NAMESPACE moderatorSystem
