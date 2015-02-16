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
#include <cstring>
#include <algorithm>
#include <boost/array.hpp>
#include <boost/shared_ptr.hpp>
//
#include <boost/regex.hpp>

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
#include "ContainedComp.h"
#include "AttachSupport.h"
//
#include "support.h"
#include "regexSupport.h"
#include <stdio.h>
#include <string.h>

#include "inputParam.h"
#include "ImportControl.h"
#include "MainProcess.h"
#include "LayerPlate.h"
#include "makeSinbad.h"

#include "Detectors.h"

namespace sinbadSystem
{

  Detectors::Detectors(const std::string& DKey,const std::string& YKey,const std::string& ZKey,const size_t ID) :
    // Detectors::Detectors(const std::string& Key) :
  attachSystem::ContainedComp(),
  attachSystem::FixedComp(DKey+YKey+ZKey+StrFunc::makeString(ID),6),
  keyName(DKey),YName(YKey),ZName(ZKey),detID(ID),
  detIndex(ModelSupport::objectRegister::Instance().cell(keyName+YName+ZName)),
  cellIndex(detIndex+1),activeY(0),activeZ(0)
  /*!
    Constructor BUT ALL variable are left unpopulated.
    \param Key :: Name for item in search
  */
{}

Detectors*
Detectors::clone() const
  /*!
    Clone funciton
    \return new(this)
  */
{
  return new Detectors(*this);
}

Detectors::Detectors(const Detectors& A) : 
  attachSystem::ContainedComp(A),attachSystem::FixedComp(A),
  keyName(A.keyName),YName(A.YName),ZName(A.ZName),baseName(A.baseName),
  detID(A.detID),detIndex(A.detIndex),
  cellIndex(A.cellIndex),activeY(A.activeY),activeZ(A.activeZ),xStep(A.xStep),
  yStep(A.yStep),zStep(A.zStep),xyAngle(A.xyAngle),
  zAngle(A.zAngle),diameter(A.diameter),length(A.length),
  mat(A.mat),xOffset(A.xOffset),yOffset(A.yOffset),
  zOffset(A.zOffset),detT(A.detT),VscanNY(A.VscanNY),
  VscanY(A.VscanY),VscanNZ(A.VscanNZ),VscanZ(A.VscanZ)
  /*!
    Copy constructor
    \param A :: Detectors to copy
  */
{}

Detectors&
Detectors::operator=(const Detectors& A)
  /*!
    Assignment operator
    \param A :: Detectors to copy
    \return *this
  */
{
  if (this!=&A)
    {
      attachSystem::ContainedComp::operator=(A);
      attachSystem::FixedComp::operator=(A);
      cellIndex=A.cellIndex;
      activeY=A.activeY;
      activeZ=A.activeZ;
      xStep=A.xStep;
      yStep=A.yStep;
      zStep=A.zStep;
      xyAngle=A.xyAngle;
      zAngle=A.zAngle;
      diameter=A.diameter;
      length=A.length;
      mat=A.mat;
      xOffset=A.xOffset;
      yOffset=A.yOffset;
      zOffset=A.zOffset;
      detT=A.detT;
      VscanNY=A.VscanNY;
      VscanY=A.VscanY;
      VscanNZ=A.VscanNZ;
      VscanZ=A.VscanZ;
     baseName=A.baseName;
  
   }
  return *this;
}


Detectors::~Detectors() 
  /*!
    Destructor
  */
{}



void
Detectors::populate(const FuncDataBase& Control, const std::string& DF)
  /*
    Populate all the variables
    \param System :: Simulation to use
  */
{

  ELog::RegMethod RegA("Detectors","populate");

  std::string YIndex("");
  std::string ZIndex("");
  YIndex=YName;     
  ZIndex+=ZName;     

  std::string expName(""); 
  for(size_t i=0;i<2;i++)
   expName+=keyName[i];     

  std::string baseNameV("");
  baseNameV=keyName;
  baseName=keyName+YName+ZName;

  std::string detAny(expName+"Det");

  if(DF=="Axial")

    {
     xStep=Control.EvalPair<double>(detAny,baseName,"StepX");
     yStep=Control.EvalPair<double>(expName,baseName,"Step"+YIndex);
     zStep=Control.EvalPair<double>(detAny,baseName,"StepZ");
     activeY=Control.EvalVar<int>(baseNameV+"Active"+YIndex);
    }
  else if(DF=="Vertical")
    {
     xStep=Control.EvalPair<double>(detAny,baseName,"StepX");
     zStep=Control.EvalPair<double>(expName,baseNameV,"Step"+ZIndex);      
     yStep=Control.EvalVar<double>(baseNameV+"Vscan"+YIndex);
     activeZ=Control.EvalVar<int>(baseNameV+YIndex+"Active"+ZIndex);
    }
   else
     {
       ELog::EM<<" NO DETECTOR? AXIAL ADVERICAL?"<<ELog::endDiag;
     }


  xOffset=Control.EvalDefVar<double>(baseName+"OffSetX",0.0);
  yOffset=Control.EvalDefVar<double>(baseName+"OffSetY",0.0);
  zOffset=Control.EvalDefVar<double>(baseName+"OffSetZ",0.0);


  length=Control.EvalPair<double>(baseName,baseNameV,"Thick");
  diameter=Control.EvalPair<double>(keyName,baseNameV,"Diam");
  mat=ModelSupport::EvalMat<int>(Control,keyName+"Mat",baseNameV+"Mat");

  // first is S monitor
  if(DF=="Axial" && YIndex=="Y0" && keyName=="35S")
   {
    length=Control.EvalPair<double>(baseName,baseNameV,"ThickM");
    diameter=Control.EvalPair<double>(keyName,baseNameV,"DiamM");
    mat=ModelSupport::EvalMat<int>(Control,keyName+"MatM",baseNameV+"MatM");
   }
  return;
}

void
Detectors::createUnitVector(const attachSystem::FixedComp& FC)
  /*!
    Create the unit vectors
    \param FC :: FixedComponent for origin
  */
{
  ELog::RegMethod RegA("Detectors","createUnitVector");

  FixedComp::createUnitVector(FC);
  applyShift(xOffset+xStep,yOffset+yStep,zOffset+zStep);
  applyAngleRotate(xyAngle,zAngle);

  return;
}

void
Detectors::createUnitVectorAM(const attachSystem::FixedComp& FC, const double& offSet)
  /*!
    Create the unit vectors
    \param FC :: FixedComponent for origin
  */
{
  ELog::RegMethod RegA("Detectors","createUnitVector");

  FixedComp::createUnitVector(FC);
  applyShift(xOffset+xStep,yOffset+yStep+offSet,zOffset+zStep);

  return;
}


void
Detectors::createSurfaces()
  /*!
    Create All the surfaces
   */
{
  ELog::RegMethod RegA("Detectors","createSurface");

  ModelSupport::buildPlane(SMap,detIndex+1,Origin,Y);
  ModelSupport::buildPlane(SMap,detIndex+2,Origin+Y*length,Y);

  ModelSupport::buildCylinder(SMap,detIndex+7,Origin,Y,diameter/2);

  return;
}

void
Detectors::createObjects(Simulation& System)
  /*!
    Adds the detector to the simulation
    \param System :: Simulation to create objects in
  */
{
  ELog::RegMethod RegA("Detectors","createObjects");

  std::string Out;
 
  Out=ModelSupport::getComposite(SMap,detIndex,"1 -2 -7");

  System.addCell(MonteCarlo::Qhull(cellIndex++,mat,0.0,Out)); 

  addOuterSurf(Out);
  
  return;
}

void
Detectors::createLinks()
  /*
    Create all the links
  */
{
  ELog::RegMethod RegA("Detectors","createLinks");
  
  FixedComp::setLinkSurf(0,-SMap.realSurf(detIndex+1));
  FixedComp::setLinkSurf(1,SMap.realSurf(detIndex+2));
  FixedComp::setLinkSurf(2,SMap.realSurf(detIndex+7));
  FixedComp::setLinkSurf(3,SMap.realSurf(detIndex+7));
  FixedComp::setLinkSurf(4,SMap.realSurf(detIndex+7));
  FixedComp::setLinkSurf(5,SMap.realSurf(detIndex+7));

  FixedComp::setConnect(0,Origin,-Y);
  FixedComp::setConnect(1,Origin+Y*(length),Y);
  FixedComp::setConnect(2,Origin-X*(diameter/2),-X);
  FixedComp::setConnect(3,Origin-X*(diameter/2),X);
  FixedComp::setConnect(4,Origin-Z*(diameter/2),-Z);
  FixedComp::setConnect(5,Origin+Z*(diameter/2),Z);

  return;
}

void
Detectors::createAll(Simulation& System,
			const attachSystem::FixedComp& FC)
  /*!
    Generic function to create everything
    \param System :: Simulation item
    \param FC :: Fixed Component for origin
  */
{
  ELog::RegMethod RegA("Detectors","createAll");

  // populate(System.getDataBase());
  createUnitVector(FC);
  createUnitVector(FC);
  createSurfaces();
  createObjects(System);
  createLinks();
  insertObjects(System);

  return;
}


void
Detectors::createAllAM(Simulation& System,const mainSystem::inputParam& IParam,
			  const attachSystem::FixedComp& FC,
                          const double& offSet, const std::string& detFlag)
  /*!
    Generic function to create everything
    \param System :: Simulation item
    \param FC :: Fixed Component for origin
  */
{
  ELog::RegMethod RegA("Detectors","createAll");
  //  getDet(IParam);


  populate(System.getDataBase(),detFlag);
  createUnitVector(FC);
  createUnitVectorAM(FC,offSet);
  createSurfaces();
  if(activeY==1 || activeZ==1)
  createObjects(System);
  createLinks();
  insertObjects(System);

  return;
}




  
}  // NAMESPACE sinbadSystem
