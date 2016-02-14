/*********************************************************************
CombLayer : MNCPX Input builder
* File: essBuild/BlockAddition.cxx
*
* Copyright (c) 2004-2013 by Stuart Ansell
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

#include "Exception.h"
#include "FileReport.h"
#include "GTKreport.h"
#include "NameStack.h"
#include "RegMethod.h"
#include "OutputLog.h"
#include "surfRegister.h"
#include "objectRegister.h"
#include "BaseVisit.h"
#include "BaseModVisit.h"
#include "MatrixBase.h"
#include "Matrix.h"
#include "Vec3D.h"
#include "Quaternion.h"
#include "Surface.h"
#include "surfIndex.h"
#include "Quadratic.h"
#include "Plane.h"
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
#include "generateSurf.h"
#include "support.h"
#include "stringCombine.h"
#include "LinkUnit.h"
#include "FixedComp.h"
#include "LayerComp.h"
#include "ContainedComp.h"
#include "BlockAddition.h"

namespace essSystem
{

BlockAddition::BlockAddition(const std::string& Key) :
  attachSystem::ContainedComp(),attachSystem::LayerComp(0),
  attachSystem::FixedComp(Key,6),
  blockIndex(ModelSupport::objectRegister::Instance().cell(Key)),
  cellIndex(blockIndex+1),active(0),edgeSurf(0)
  /*!
Constructor
\param Key :: Name of construction key
*/
{}

BlockAddition::BlockAddition(const BlockAddition& A) :
  attachSystem::ContainedComp(A),attachSystem::LayerComp(A),
  attachSystem::FixedComp(A),
  blockIndex(A.blockIndex),cellIndex(A.cellIndex),
  active(A.active),xStep(A.xStep),yStep(A.yStep),zStep(A.zStep),
  xyAngle(A.xyAngle),zAngle(A.zAngle),length(A.length),
  height(A.height),width(A.width),waterMat(A.waterMat),
  waterTemp(A.waterTemp),wallThick(A.wallThick),
  wallMat(A.wallMat),wallTemp(A.wallTemp),
  edgeSurf(A.edgeSurf)
  /*!
Copy constructor
\param A :: BlockAddition to copy
*/
{}

BlockAddition&
BlockAddition::operator=(const BlockAddition& A)
  /*!
Assignment operator
\param A :: BlockAddition to copy
\return *this
*/
{
  if (this!=&A)
    {
      attachSystem::ContainedComp::operator=(A);
      attachSystem::LayerComp::operator=(A);
      attachSystem::FixedComp::operator=(A);
      cellIndex=A.cellIndex;
      active=A.active;
      xStep=A.xStep;
      yStep=A.yStep;
      zStep=A.zStep;
      xyAngle=A.xyAngle;
      zAngle=A.zAngle;
      length=A.length;
      height=A.height;
      width=A.width;
      waterMat=A.waterMat;
      waterTemp=A.waterTemp;
      wallThick=A.wallThick;
      wallMat=A.wallMat;
      wallTemp=A.wallTemp;

      edgeSurf=A.edgeSurf;
    }
  return *this;
}

BlockAddition::~BlockAddition()
  /*!
Destructor
*/
{}

std::string
BlockAddition::getLinkComplement(const size_t sideIndex) const
  /*!
Accessor to the link surface string [negative]
\param Index :: Link number
\return String of link
*/
{
  if (active)
    return FixedComp::getLinkComplement(sideIndex);
  return std::string("");
}

std::string
BlockAddition::getLinkString(const size_t sideIndex) const
  /*!
Accessor to the link surface string [negative]
\param Index :: Link number
\return String of link
*/
{
  if (active)
    return FixedComp::getLinkString(sideIndex);
  return std::string("");
}

void
BlockAddition::populate(const FuncDataBase& Control)
  /*!
Populate all the variables
\param Control :: Variable table to use
*/
{
  ELog::RegMethod RegA("BlockAddition","populate");

  xStep=Control.EvalDefVar<double>(keyName+"XStep",0.0);
  yStep=Control.EvalDefVar<double>(keyName+"YStep",0.0);
  zStep=Control.EvalDefVar<double>(keyName+"ZStep",0.0);
  xyAngle=Control.EvalDefVar<double>(keyName+"XYangle",0.0);
  zAngle=Control.EvalDefVar<double>(keyName+"Zangle",0.0);

  // Extension
  length=Control.EvalVar<double>(keyName+"Length");
  width=Control.EvalVar<double>(keyName+"Width");
  height=Control.EvalVar<double>(keyName+"Height");
  waterMat=ModelSupport::EvalMat<int>(Control,keyName+"Mat");
  waterTemp=Control.EvalVar<double>(keyName+"Temp");
  nLayers=Control.EvalVar<size_t>(keyName+"NLayers");   



  double WT(0.0);
  double T(0.0);
  int M;

  for(size_t i=0;i<nLayers;i++)
    {
      WT+=Control.EvalVar<double>
	(StrFunc::makeString(keyName+"WallThick",i+1));   
      M=ModelSupport::EvalMat<int>(Control,
	StrFunc::makeString(keyName+"WallMat",i+1));   
      const std::string TStr=StrFunc::makeString(keyName+"WallTemp",i+1);
      T=(!M || !Control.hasVariable(TStr)) ?
	0.0 : Control.EvalVar<double>(TStr); 
      
      wallThick.push_back(WT);
      wallMat.push_back(M);
      wallTemp.push_back(T);
    }


  // wallThick=Control.EvalVar<double>(keyName+"WallThick");
  // gap=Control.EvalVar<double>(keyName+"Gap");
 
  // wallMat=ModelSupport::EvalMat<int>(Control,keyName+"WallMat");

  
  return;
}

void
BlockAddition::createUnitVector(const Geometry::Vec3D& O,
const Geometry::Vec3D& YAxis,
const Geometry::Vec3D& ZAxis)
  /*!
Create the unit vectors
\param O :: Origin [calc from edge point]
\param YAxis :: Direction of Y Axis
\param FC :: FixedComp [for Z]
*/
{
  ELog::RegMethod RegA("BlockAddition","createUnitVector");
  const Geometry::Plane* PPtr=
    SMap.realPtr<Geometry::Plane>(edgeSurf);
  
  Origin=O;
  Z=ZAxis;
  Y=YAxis;
  X=Z*Y;

  size_t Xext(0);
  Xext=wallThick.size()-1;
  applyShift(xStep+wallThick[Xext],yStep,zStep);
  applyAngleRotate(xyAngle,zAngle);
  //     ELog::EM<<" BLOCK Ori "<<Origin<<ELog::endWarn;

  if (PPtr && PPtr->getNormal().dotProd(X)<0.0)
    X*=-1.0;
  return;
}

void
BlockAddition::createSurfaces()
  /*!
Create planes for box layers
*/
{
  ELog::RegMethod RegA("BlockAddition","createSurfaces");

  // Inner planes

  if (fabs(xyAngle)<Geometry::zeroTol)
    SMap.addMatch(blockIndex+1,edgeSurf);
  else
    {
      ModelSupport::buildRotatedPlane(SMap,blockIndex+1,
SMap.realPtr<Geometry::Plane>(edgeSurf),
xyAngle,Z,rotCent);
    }
  ModelSupport::buildPlane(SMap,blockIndex+2,Origin+Y*length,Y);
  ModelSupport::buildPlane(SMap,blockIndex+3,Origin,X);
  ModelSupport::buildPlane(SMap,blockIndex+4,Origin+X*width,X);
  ModelSupport::buildPlane(SMap,blockIndex+5,Origin-Z*height/2.0,Z);
  ModelSupport::buildPlane(SMap,blockIndex+6,Origin+Z*height/2.0,Z);

  // Walls planes
  int SI(blockIndex);

  for(size_t i=0;i<nLayers;i++)
    {
     ModelSupport::buildPlane(SMap,blockIndex+12,
                   Origin+Y*(length+wallThick[i]),Y);
     ModelSupport::buildPlane(SMap,blockIndex+13,
                   Origin-X*wallThick[i],X);
     ModelSupport::buildPlane(SMap,blockIndex+14,
                   Origin+X*(width+wallThick[i]),X);
     ModelSupport::buildPlane(SMap,blockIndex+15,
                   Origin-Z*(height/2.0+wallThick[i]),Z);
     ModelSupport::buildPlane(SMap,blockIndex+16,
                   Origin+Z*(height/2.0+wallThick[i]),Z);
      SI+=10;
    }

  // Gap planes
//   ModelSupport::buildPlane(SMap,blockIndex+22,
// Origin+Y*(length+wallThick+gap),Y);
//   ModelSupport::buildPlane(SMap,blockIndex+23,
// Origin-X*(wallThick+gap),X);
//   ModelSupport::buildPlane(SMap,blockIndex+24,
// Origin+X*(width+wallThick+gap),X);
//   ModelSupport::buildPlane(SMap,blockIndex+25,
// Origin-Z*(height/2.0+wallThick+gap),Z);
//   ModelSupport::buildPlane(SMap,blockIndex+26,
// Origin+Z*(height/2.0+wallThick+gap),Z);


  return;
}

std::string
BlockAddition::rotateItem(std::string LString)
  /*!
Given a string convert to an angle rotate form
\param LString :: Link string
\return string
*/
{
  ELog::RegMethod RegA("BlockAddtion","rotateItem");

  if (fabs(xyAngle)<Geometry::zeroTol)
    return LString;

  std::ostringstream cx;
  std::string S;

  const Geometry::Quaternion QrotXY=
    Geometry::Quaternion::calcQRotDeg(xyAngle,Z);

  int BI(blockIndex+1000);
  while(StrFunc::section(LString,S))
    {
      int N;
      if (StrFunc::convert(S,N))
{
const Geometry::Plane* PN=
dynamic_cast<const Geometry::Plane*>
(SMap.realSurfPtr(abs(N)));
if (PN)
{
BI++;
ModelSupport::buildRotatedPlane(SMap,BI,PN,
xyAngle,Z,rotCent);
cx<<" "<<((N>0) ? BI : -BI);
}
else
cx<<" "<<S;
}
      else
cx<<" "<<S;
    }
  return cx.str();
}


void
BlockAddition::createObjects(Simulation& System,
const attachSystem::LayerComp& PMod,
const size_t layerIndex,
const size_t sideIndex)
  /*!
Create the block object
\param System :: Simulation to add results
\param CMod :: Moderator fixed unit
\param layerIndex :: Layer number
\param sideIndex :: surface number
*/
{
  ELog::RegMethod RegA("BlockAddition","createObjects");

  std::string Out;

  if (active)
    {
      Out=PMod.getLayerString(layerIndex,sideIndex);
      preModInner=rotateItem(Out);
      Out=PMod.getLayerString(layerIndex+2,sideIndex);
      preModOuter=rotateItem(Out);

      Out=ModelSupport::getComposite(SMap,blockIndex,"1 -2 3 -4 5 -6 ");
      Out+=preModInner;
      System.addCell(MonteCarlo::Qhull(cellIndex++,waterMat,0.0,Out));
 
  int SI(blockIndex);
  for(size_t i=0;i<nLayers;i++)
    { 
      Out=ModelSupport::getComposite(SMap,SI,
          "1 -12 13 -14 15 -16 (2:-3:4:-5:6)");
      // if(i==0)
      // Out+=preModInner;
      // else
      Out+=preModOuter;
      System.addCell(MonteCarlo::Qhull(cellIndex++,wallMat[i],0.0,Out));
      SI+=10;
    }
       
//       Out=ModelSupport::getComposite(SMap,blockIndex,
// "1 -22 23 -24 25 -26 (12:-13:14:-15:16)");
//       Out+=preModOuter;
//       System.addCell(MonteCarlo::Qhull(cellIndex++,0,0.0,Out));
            
      // Out=ModelSupport::getComposite(SMap,blockIndex,"1 -22 23 -24 25 -26 ");

      // Out+=PMod.getLinkString(layerIndex+2,sideIndex);

      Out=ModelSupport::getComposite(SMap,SI-10,"1 -12 13 -14 15 -16 ");
      addOuterSurf(Out);
    }
  return;
}

std::string
BlockAddition::createCut(const size_t layerIndex) const
  /*!
Ugly function to create the cuts for the pre-moderator
\param layerIndex :: layer for string
\return string at layer
*/
{
  ELog::RegMethod RegA("BlockAddition","createCut");
  if (layerIndex>=3)
    throw ColErr::IndexError<size_t>(layerIndex,3,"layerIndex");
  
  std::string Out;
  if (active)
    {
      const int SI(10*static_cast<int>(layerIndex)+blockIndex);
      Out=ModelSupport::getComposite(SMap,SI,blockIndex,
" (-1M:-3:4:-5:6) ");
    }
  return Out;
}

void
BlockAddition::createLinks()
  /*!
Creates a full attachment set
*/
{
  ELog::RegMethod RegA("BlockAddition","createLinks");


  if (nLayers)
    {
  
     FixedComp::setConnect(0,Origin-Y*(length+wallThick[nLayers-1]),-Y);
     FixedComp::setLinkSurf(0,SMap.realSurf(blockIndex+1));

     FixedComp::setConnect(1,Origin+Y*(length+5+wallThick[nLayers-1]),Y);
     FixedComp::setLinkSurf(1,SMap.realSurf(blockIndex+2));

     FixedComp::setConnect(2,Origin-X*(wallThick[nLayers-1]),-X);
     FixedComp::setLinkSurf(2,SMap.realSurf(blockIndex+3));

     FixedComp::setConnect(3,Origin+X*(width+wallThick[nLayers-1]),X);
     FixedComp::setLinkSurf(3,SMap.realSurf(blockIndex+4));

     FixedComp::setConnect(4,Origin-Z*(height/2.0+wallThick[nLayers-1]),-Z);
     FixedComp::setLinkSurf(4,SMap.realSurf(blockIndex+5));

     FixedComp::setConnect(5,Origin+Z*(height/2.0+wallThick[nLayers-1]),Z);
     FixedComp::setLinkSurf(5,SMap.realSurf(blockIndex+6));
    }
  else 
    ELog::EM<<"NO Layers in CylPreMod"<<ELog::endErr;
 
  return;
}

Geometry::Vec3D
BlockAddition::getSurfacePoint(const size_t layerIndex,
const size_t sideIndex) const
  /*!
Given a side and a layer calculate the link point
\param sideIndex :: Side [0-5]
\param layerIndex :: Layer, 0 is inner moderator [0-6]
\return Surface point
*/
{
  ELog::RegMethod RegA("BlockAddition","getSurfacePoint");

  if (layerIndex>nLayers)
    throw ColErr::IndexError<size_t>(layerIndex,nLayers,"layer");

  // double outDist(0.0);
  // if (layerIndex>0) outDist+=wallThick;
  // if (layerIndex>1) outDist+=gap;


 if (layerIndex>0)
    {
  
  switch(sideIndex)
    {
    case 0:
      // return Origin-Y*(length+wallThick[layerIndex-1]);
      return Origin;
    case 1:
      return Origin+Y*(length+wallThick[layerIndex-1]);
    case 2:
      return Origin-Z*(height/2.0+wallThick[layerIndex-1]);
    case 3:
      return Origin+Z*(height/2.0+wallThick[layerIndex-1]);
    case 4:
      return Origin-X*(width/2.0+wallThick[layerIndex-1]);
    case 5:
      return Origin+X*(width/2.0+wallThick[layerIndex-1]);
     }
    }
  else
    {
      switch(sideIndex)
	{
    case 0:
      return Origin;
    case 1:
      return Origin+Y*(length);
    case 2:
      return Origin-Z*(height/2.0);
    case 3:
      return Origin+Z*(height/2.0);
    case 4:
      return Origin-X*(width/2.0);
    case 5:
      return Origin+X*(width/2.0);

	}
    }

  throw ColErr::IndexError<size_t>(sideIndex,6,"sideIndex ");
}

int
BlockAddition::getLayerSurf(const size_t layerIndex,
const size_t sideIndex) const
  /*!
Given a side and a layer calculate the layerSurface
\param sideIndex :: Side [0-5]
\param layerIndex :: layer, 0 is inner moderator [0-4]
\return Surface string
*/
{
  ELog::RegMethod RegA("BlockAddition","getLayerSurf");

  if (layerIndex>nLayers)
    throw ColErr::IndexError<size_t>(layerIndex,nLayers,"layer");

  if (sideIndex>5)
    throw ColErr::IndexError<size_t>(sideIndex,6,"sideIndex");
  const int SI(blockIndex+10*static_cast<int>(layerIndex));
  const int SN(static_cast<int>(sideIndex+1));


  switch(sideIndex)
    {
    case 0:
     return SMap.realSurf(SI+2);
 
    case 1:
     return SMap.realSurf(SI+3);

    case 2:
     return SMap.realSurf(SI+4);

    case 3:
      return SMap.realSurf(SI+5);

    case 4:
      return SMap.realSurf(SI+6);

    case 5:
      return SMap.realSurf(SI+7);

    }


  // if (sideIndex)
  //   return (sideIndex % 2) ? SMap.realSurf(SN+SI) :
  //     -SMap.realSurf(SN+SI);
  
  // return -SMap.realSurf(blockIndex+1);
}

std::string
BlockAddition::getLayerString(const size_t layerIndex,
const size_t sideIndex) const
  /*!
Given a side and a layer calculate the layerSurface
\param sideIndex :: Side [0-5]
\param layerIndex :: layer, 0 is inner moderator [0-4]
\return Surface string
*/
{
  ELog::RegMethod RegA("BlockAddition","getLayerString");

  if (layerIndex>2)
    throw ColErr::IndexError<size_t>(layerIndex,2,"layer");

  if (sideIndex>5)
    throw ColErr::IndexError<size_t>(sideIndex,6,"sideIndex");

  // NEED To get conditional surface [IFF sideIndex==0]

  const int SI(blockIndex+10*static_cast<int>(layerIndex));
  const int SN(static_cast<int>(sideIndex+1));

  if (sideIndex>0)
    {
      const int SurfN=(sideIndex % 2) ?
SMap.realSurf(SN+SI) : -SMap.realSurf(SN+SI);
      return StrFunc::makeString(SurfN);
    }
  return preModInner+" "+StrFunc::makeString(-SMap.realSurf(blockIndex+1));
}

void
BlockAddition::createAll(Simulation& System,
const Geometry::Vec3D& O,
const attachSystem::LayerComp& CylPreMod,
const size_t layerIndex,
const size_t sideIndex)
  /*!
Extrenal build everything
\param System :: Simulation
\param O :: Origin (from track intersect)
\param FC :: FixedComp for the angle
\param CylPeMod :: Cylindrical moderator [3 surfaces]
\param sideIndex :: Index object direction
\param layerIndex :: Level to join to
*/
{
  ELog::RegMethod RegA("BlockAddition","createAll");

  const attachSystem::FixedComp* FC=
    dynamic_cast<const attachSystem::FixedComp*>(&CylPreMod);

  if (FC)
    {
      populate(System.getDataBase());
      createUnitVector(O,FC->getLinkAxis(sideIndex),FC->getZ());

      createSurfaces();
      createObjects(System,CylPreMod,layerIndex,sideIndex);
      createLinks();
      insertObjects(System);
    }

  return;
}

} // NAMESPACE instrumentSystem