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
#include "inputParam.h"

#include "sbadDetector.h"
  
namespace sinbadSystem
{

sbadDetector::sbadDetector(const std::string& Key,const size_t ID) :
  attachSystem::ContainedComp(),
  attachSystem::FixedComp(Key+StrFunc::makeString(ID),6),
  baseName(Key),detID(ID),
  detIndex(ModelSupport::objectRegister::Instance().cell(keyName)),
  cellIndex(detIndex+1),active(0)
  /*!
    Constructor BUT ALL variable are left unpopulated.
    \param Key :: Name for item in search
  */
{}

sbadDetector*
sbadDetector::clone() const
  /*!
    Clone funciton
    \return new(this)
  */
{
  return new sbadDetector(*this);
}

sbadDetector::sbadDetector(const sbadDetector& A) : 
  attachSystem::ContainedComp(A),attachSystem::FixedComp(A),
  baseName(A.baseName),detID(A.detID),detIndex(A.detIndex),
  cellIndex(A.cellIndex),active(A.active),xStep(A.xStep),
  yStep(A.yStep),zStep(A.zStep),xyAngle(A.xyAngle),
  zAngle(A.zAngle),diameter(A.diameter),length(A.length),
  mat(A.mat),xOffset(A.xOffset),yOffset(A.yOffset),
  zOffset(A.zOffset),detT(A.detT)
  /*!
    Copy constructor
    \param A :: sbadDetector to copy
  */
{}

sbadDetector&
sbadDetector::operator=(const sbadDetector& A)
  /*!
    Assignment operator
    \param A :: sbadDetector to copy
    \return *this
  */
{
  if (this!=&A)
    {
      attachSystem::ContainedComp::operator=(A);
      attachSystem::FixedComp::operator=(A);
      cellIndex=A.cellIndex;
      active=A.active;
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
    }
  return *this;
}


sbadDetector::~sbadDetector() 
  /*!
    Destructor
  */
{}


std::string
sbadDetector::getDet(const mainSystem::inputParam& IParam) const
{


 int t(0);
  //  const std::string detT;
  while(t<10 && IParam.getValue<std::string>("detType",t).size()!=0)
	//  const std::string detT=IParam.getValue<std::string>("detType",2);
    {
     const std::string detT=IParam.getValue<std::string>("detType",t);
     int  TT(0);
     TT=t;
       ELog::EM<<" XX "<<TT<<" X "<<t<<" Det TypeXxX == "<<detT<<" sizeXXX "<< IParam.getValue<std::string>("detType",t).size()<<ELog::endDiag;
       //     buildDetectorsAM(*SimPtr,detT,TT);
     t=t+1;
    }
  return detT;
}

void
sbadDetector::populate(const FuncDataBase& Control)
  /*
    Populate all the variables
    \param System :: Simulation to use
  */
{
  ELog::RegMethod RegA("sbadDetector","populate");

  active=Control.EvalVar<int>(keyName+"Active");
  xStep=Control.EvalPair<double>(keyName,baseName,"StepX");
  yStep=Control.EvalPair<double>(keyName,baseName,"StepY");
  zStep=Control.EvalPair<double>(keyName,baseName,"StepZ");
  xyAngle=Control.EvalPair<double>(keyName,baseName,"XYAngle");
  zAngle=Control.EvalPair<double>(keyName,baseName,"ZAngle");

	  ELog::EM<<"baseName "<<baseName<<ELog::endDiag;
	  ELog::EM<<"keyName "<<keyName<<ELog::endDiag;

  std::string keyName1("49DetectorRh");

  xOffset=Control.EvalDefVar<double>(baseName+"OffSetX",0.0);
  yOffset=Control.EvalDefVar<double>(baseName+"OffSetY",0.0);
  zOffset=Control.EvalDefVar<double>(baseName+"OffSetZ",0.0);

  length=Control.EvalPair<double>(keyName,baseName,"Thick");
  diameter=Control.EvalPair<double>(keyName,baseName,"Diam");

  mat=ModelSupport::EvalMat<int>(Control,keyName+"Mat",baseName+"Mat");

  return;
}

void
sbadDetector::createUnitVector(const attachSystem::FixedComp& FC)
  /*!
    Create the unit vectors
    \param FC :: FixedComponent for origin
  */
{
  ELog::RegMethod RegA("sbadDetector","createUnitVector");

  FixedComp::createUnitVector(FC);
  applyShift(xOffset+xStep,yOffset+yStep,zOffset+zStep);
  applyAngleRotate(xyAngle,zAngle);

  return;
}

void
sbadDetector::createUnitVectorAM(const attachSystem::FixedComp& FC, const double& offSet)
  /*!
    Create the unit vectors
    \param FC :: FixedComponent for origin
  */
{
  ELog::RegMethod RegA("sbadDetector","createUnitVector");

  FixedComp::createUnitVector(FC);
  applyShift(xOffset+xStep,yOffset+yStep,zOffset+zStep);
  // applyShift(xStep,yStep,zStep);
 ELog::EM<<" offSet===="<<offSet<<ELog::endDiag;
  applyAngleRotate(xyAngle,zAngle);

  return;
}


void
sbadDetector::createSurfaces()
  /*!
    Create All the surfaces
   */
{
  ELog::RegMethod RegA("sbadDetector","createSurface");

  // ModelSupport::buildPlane(SMap,detIndex+1,Origin-Y*(length/2.0),Y);
  // ModelSupport::buildPlane(SMap,detIndex+2,Origin+Y*(length/2.0),Y);
  ModelSupport::buildPlane(SMap,detIndex+1,Origin,Y);
  ModelSupport::buildPlane(SMap,detIndex+2,Origin+Y*length,Y);

  ModelSupport::buildCylinder(SMap,detIndex+7,Origin,Y,diameter/2);

  return;
}

void
sbadDetector::createObjects(Simulation& System)
  /*!
    Adds the detector to the simulation
    \param System :: Simulation to create objects in
  */
{
  ELog::RegMethod RegA("sbadDetector","createObjects");

  std::string Out;
 
  Out=ModelSupport::getComposite(SMap,detIndex,"1 -2 -7");
  System.addCell(MonteCarlo::Qhull(cellIndex++,mat,0.0,Out)); 
  addOuterSurf(Out);
  
  return;
}

void
sbadDetector::createLinks()
  /*
    Create all the links
  */
{
  ELog::RegMethod RegA("sbadDetector","createLinks");
  
  FixedComp::setLinkSurf(0,-SMap.realSurf(detIndex+1));
  FixedComp::setLinkSurf(1,SMap.realSurf(detIndex+2));
  FixedComp::setLinkSurf(2,SMap.realSurf(detIndex+7));
  FixedComp::setLinkSurf(3,SMap.realSurf(detIndex+7));
  FixedComp::setLinkSurf(4,SMap.realSurf(detIndex+7));
  FixedComp::setLinkSurf(5,SMap.realSurf(detIndex+7));

  FixedComp::setConnect(0,Origin-Y*(length/2.0),-Y);
  FixedComp::setConnect(1,Origin+Y*(length/2.0),Y);
  FixedComp::setConnect(2,Origin-X*(diameter/2),-X);
  FixedComp::setConnect(3,Origin-X*(diameter/2),X);
  FixedComp::setConnect(4,Origin-Z*(diameter/2),-Z);
  FixedComp::setConnect(5,Origin+Z*(diameter/2),Z);

  return;
}

void
sbadDetector::createAll(Simulation& System,
			const attachSystem::FixedComp& FC)
  /*!
    Generic function to create everything
    \param System :: Simulation item
    \param FC :: Fixed Component for origin
  */
{
  ELog::RegMethod RegA("sbadDetector","createAll");

  populate(System.getDataBase());
  createUnitVector(FC);
  createUnitVector(FC);
  createSurfaces();
  createObjects(System);
  createLinks();
  insertObjects(System);

  return;
}


void
sbadDetector::createAllAM(Simulation& System,const mainSystem::inputParam& IParam,
			  const attachSystem::FixedComp& FC,
                          const double& offSet)
  /*!
    Generic function to create everything
    \param System :: Simulation item
    \param FC :: Fixed Component for origin
  */
{
  ELog::RegMethod RegA("sbadDetector","createAll");
  getDet(IParam);
  populate(System.getDataBase());
  createUnitVector(FC);
  createUnitVectorAM(FC,offSet);
  createSurfaces();
  if(active==1)
  createObjects(System);
  createLinks();
  insertObjects(System);

  return;
}




  
}  // NAMESPACE sinbadSystem
