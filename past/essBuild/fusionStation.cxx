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
#include <boost/array.hpp>
#include <boost/shared_ptr.hpp>

#include "Exception.h"
#include "FileReport.h"
#include "GTKreport.h"
#include "NameStack.h"
#include "RegMethod.h"
#include "OutputLog.h"
#include "BaseVisit.h"
#include "BaseModVisit.h"
#include "support.h"
#include "MatrixBase.h"
#include "Matrix.h"
#include "Vec3D.h"
#include "Triple.h"
#include "NRange.h"
#include "NList.h"
#include "Quaternion.h"
#include "Surface.h"
#include "surfIndex.h"
#include "surfRegister.h"
#include "objectRegister.h"
#include "surfEqual.h"
#include "localRotate.h"
#include "masterRotate.h"
#include "surfDivide.h"
#include "surfDIter.h"
#include "Quadratic.h"
#include "Plane.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "Rules.h"
#include "varList.h"
#include "Code.h"
#include "FuncDataBase.h"
#include "HeadRule.h"
#include "Object.h"
#include "Qhull.h"
#include "KGroup.h"
#include "SrcData.h"
#include "SrcItem.h"
#include "Source.h"
#include "Simulation.h"
#include "ModelSupport.h"
#include "MaterialSupport.h"
#include "generateSurf.h"
#include "LinkUnit.h"
#include "FixedComp.h"
#include "support.h"
#include "stringCombine.h"
#include "ContainedComp.h"
#include "BeamWindow.h"
#include "fusionStation.h"

namespace essSystem
{

fusionStation::fusionStation(const std::string& Key) :
  attachSystem::ContainedComp(),attachSystem::FixedComp(Key,6),
  TSTIndex(ModelSupport::objectRegister::Instance().cell(Key)),
  cellIndex(TSTIndex+1)
  /*!
    Constructor BUT ALL variable are left unpopulated.
    \param Key :: Name for item in search
  */
{}

fusionStation::fusionStation(const fusionStation& A) :
  attachSystem::ContainedComp(A),attachSystem::FixedComp(A),
  TSTIndex(A.TSTIndex), cellIndex(A.cellIndex), OffsetX(A.OffsetX),
  OffsetY(A.OffsetY), OffsetZ(A.OffsetX),AngleXY(A.AngleXY),AngleZ(A.AngleZ),
  SampleBlockLength(A.SampleBlockLength),SampleBlockWidth(A.SampleBlockWidth),
  SampleBlockHeight(A.SampleBlockHeight),SampleBlockColumns(A.SampleBlockColumns),
  SampleBlockRows(A.SampleBlockRows),SampleBlockMaterial(A.SampleBlockMaterial),
  SampleBlockTemperature(A.SampleBlockTemperature),
  SampleCladdingMaterial(A.SampleCladdingMaterial),
  SampleCladdingThickness(A.SampleCladdingThickness),
  SampleCladdingTemperature(A.SampleCladdingTemperature),
  BaffleMaterial(A.BaffleMaterial),
  BaffleThickness(A.BaffleThickness),
  BaffleTemperature(A.BaffleTemperature),
  BaffleCladdingMaterial(A.BaffleCladdingMaterial),
  BaffleCladdingThickness(A.BaffleCladdingThickness),
  BaffleCladdingTemperature(A.BaffleCladdingTemperature),
  CoolingMaterial(A.CoolingMaterial),
  CoolingThickness(A.CoolingThickness),
  CoolingTemperature(A.CoolingTemperature),
  CoolingCladdingMaterial(A.CoolingCladdingMaterial),
  CoolingCladdingThickness(A.CoolingCladdingThickness),
  CoolingCladdingTemperature(A.CoolingCladdingTemperature),
  mainDetCell(A.mainDetCell)
  /*!
    Constructor BUT ALL variable are left unpopulated.
  */
{}

fusionStation&
fusionStation::operator=(const fusionStation& A) 
{
  if (&A!=this)
    {
     attachSystem::ContainedComp::operator=(A);
     attachSystem::FixedComp::operator=(A);
     cellIndex=A.cellIndex;
     OffsetX=A.OffsetX;
     OffsetY=A.OffsetY;
     OffsetZ=A.OffsetZ;
     AngleXY=A.AngleXY;
     AngleZ=A.AngleZ;

     SampleBlockLength=A.SampleBlockLength;
     SampleBlockWidth=A.SampleBlockWidth;
     SampleBlockHeight=A.SampleBlockHeight;
     SampleBlockColumns=A.SampleBlockColumns;
     SampleBlockRows=A.SampleBlockRows;
     SampleBlockMaterial=A.SampleBlockMaterial;
     SampleBlockTemperature=A.SampleBlockTemperature;

     SampleCladdingMaterial=A.SampleCladdingMaterial;
     SampleCladdingThickness=A.SampleCladdingThickness;
     SampleCladdingTemperature=A.SampleCladdingTemperature;

     BaffleMaterial=A.BaffleMaterial;
     BaffleThickness=A.BaffleThickness;
     BaffleTemperature=A.BaffleTemperature;

     BaffleCladdingMaterial=A.BaffleCladdingMaterial;
     BaffleCladdingThickness=A.BaffleCladdingThickness;
     BaffleCladdingTemperature=A.BaffleCladdingTemperature;

     CoolingMaterial=A.CoolingMaterial;
     CoolingThickness=A.CoolingThickness;
     CoolingTemperature=A.CoolingTemperature;

     CoolingCladdingMaterial=A.CoolingCladdingMaterial;
     CoolingCladdingThickness=A.CoolingCladdingThickness;
     CoolingCladdingTemperature=A.CoolingCladdingTemperature;

    }
  return *this;
}

fusionStation*
fusionStation::clone() const
  /*!
    Clone funciton
    \return new(this)
  */
{
  return new fusionStation(*this);
}

fusionStation::~fusionStation() 
  /*!
    Destructor
  */
{}

void
fusionStation::populate(const Simulation& System)
  /*!
    Populate all the variables
    \param System :: Simulation to use
  */
{
  ELog::RegMethod RegA("fusionStation","populate");

  const FuncDataBase& Control=System.getDataBase();

  OffsetX=Control.EvalVar<double>(keyName+"OffsetX");
  OffsetY=Control.EvalVar<double>(keyName+"OffsetY");
  OffsetZ=Control.EvalVar<double>(keyName+"OffsetZ");

  AngleXY=Control.EvalVar<double>(keyName+"AngleXY");
  AngleZ=Control.EvalVar<double>(keyName+"AngleZ");

  SampleBlockLength=Control.EvalVar<double>(keyName+"SampleBlockLength");
  SampleBlockWidth=Control.EvalVar<double>(keyName+"SampleBlockWidth");
  SampleBlockHeight=Control.EvalVar<double>(keyName+"SampleBlockHeight");
  SampleBlockColumns=Control.EvalVar<int>(keyName+"SampleBlockColumns");
  SampleBlockRows=Control.EvalVar<int>(keyName+"SampleBlockRows");
  SampleBlockMaterial=ModelSupport::EvalMat<int>(Control,keyName+"SampleBlockMaterial");
  SampleBlockTemperature=Control.EvalVar<double>(keyName+"SampleBlockTemperature");

  SampleCladdingMaterial=ModelSupport::EvalMat<int>(Control,keyName+"SampleCladdingMaterial");
  SampleCladdingThickness=Control.EvalVar<double>(keyName+"SampleCladdingThickness");
  SampleCladdingTemperature=Control.EvalVar<double>(keyName+"SampleCladdingTemperature");

  BaffleMaterial=ModelSupport::EvalMat<int>(Control,keyName+"BaffleMaterial");
  BaffleThickness=Control.EvalVar<double>(keyName+"BaffleThickness");
  BaffleTemperature=Control.EvalVar<double>(keyName+"BaffleTemperature");

  BaffleCladdingMaterial=ModelSupport::EvalMat<int>(Control,keyName+"BaffleCladdingMaterial");
  BaffleCladdingThickness=Control.EvalVar<double>(keyName+"BaffleCladdingThickness");
  BaffleCladdingTemperature=Control.EvalVar<double>(keyName+"BaffleCladdingTemperature");

  CoolingMaterial=ModelSupport::EvalMat<int>(Control,keyName+"CoolingMaterial");
  CoolingThickness=Control.EvalVar<double>(keyName+"CoolingThickness");
  CoolingTemperature=Control.EvalVar<double>(keyName+"CoolingTemperature");

  CoolingCladdingMaterial=ModelSupport::EvalMat<int>(Control,keyName+"CoolingCladdingMaterial");
  CoolingCladdingThickness=Control.EvalVar<double>(keyName+"CoolingCladdingThickness");
  CoolingCladdingTemperature=Control.EvalVar<double>(keyName+"CoolingCladdingTemperature");
 
  return;
}

void
fusionStation::createUnitVector(const attachSystem::FixedComp& FC)
  /*!
    Create the unit vectors
    \param FC :: FixedComponent for origin
  */
{
  ELog::RegMethod RegA("fusionStation","createUnitVector");

  FixedComp::createUnitVector(FC);
  Origin+=X*OffsetX+Y*OffsetY+Z*OffsetZ;

  const Geometry::Quaternion Qz=
    Geometry::Quaternion::calcQRotDeg(AngleZ,X);
  const Geometry::Quaternion Qxy=
    Geometry::Quaternion::calcQRotDeg(AngleXY,Z);
  Qz.rotate(Y);
  Qz.rotate(Z);
  Qxy.rotate(Y);
  Qxy.rotate(X);
  Qxy.rotate(Z);

 return;
}


void
fusionStation::createSurfaces()
  /*!
    Create All the surfaces
   */
{
  ELog::RegMethod RegA("fusionStation","createSurface");
  
  int TI(TSTIndex+3);
  for(size_t i=0;i<SampleBlockRows+1;i++)  
     {
       ModelSupport::buildPlane(SMap,TI,Origin-X*
       (SampleBlockLength/2-SampleBlockLength/SampleBlockRows*(i)),X);
       TI+=10;
     }

  TI=TSTIndex+1;
  for(size_t i=0;i<SampleBlockColumns+1;i++)  
     {
       ModelSupport::buildPlane(SMap,TI,Origin-Y*
      (SampleBlockWidth/2-SampleBlockLength/SampleBlockColumns*(i)),Y);
       TI+=10;
     }
  ModelSupport::buildPlane(SMap,TSTIndex+5,
			   Origin-Z*(SampleBlockHeight/2.0),Z);
  ModelSupport::buildPlane(SMap,TSTIndex+6,
			   Origin+Z*(SampleBlockHeight/2.0),Z);

  // Sample Cladding

     double SampleCladdingLayerX(SampleBlockLength/2+SampleCladdingThickness);
     ModelSupport::buildPlane(SMap,TSTIndex+7,Origin-X*(SampleCladdingLayerX),X);
     ModelSupport::buildPlane(SMap,TSTIndex+17,Origin+X*(SampleCladdingLayerX),X);

     double SampleCladdingLayerY(SampleBlockWidth/2+SampleCladdingThickness);
     ModelSupport::buildPlane(SMap,TSTIndex+8,Origin-Y*(SampleCladdingLayerY),Y);
     ModelSupport::buildPlane(SMap,TSTIndex+18,Origin+Y*(SampleCladdingLayerY),Y);

     double SampleCladdingLayerZ(SampleBlockHeight/2+SampleCladdingThickness);
     ModelSupport::buildPlane(SMap,TSTIndex+9,Origin-Z*(SampleCladdingLayerZ),Z);
     ModelSupport::buildPlane(SMap,TSTIndex+19,Origin+Z*(SampleCladdingLayerZ),Z);
   
   // Baffle

     double BaffleLayerX(SampleCladdingLayerX+BaffleThickness);
     ModelSupport::buildPlane(SMap,TSTIndex+27,Origin-X*(BaffleLayerX),X);
     ModelSupport::buildPlane(SMap,TSTIndex+37,Origin+X*(BaffleLayerX),X);

     double BaffleLayerY(SampleCladdingLayerY+BaffleThickness);
     ModelSupport::buildPlane(SMap,TSTIndex+28,Origin-Y*(BaffleLayerY),Y);
     ModelSupport::buildPlane(SMap,TSTIndex+38,Origin+Y*(BaffleLayerY),Y);

     double BaffleLayerZ(SampleCladdingLayerZ+BaffleThickness);
     ModelSupport::buildPlane(SMap,TSTIndex+29,Origin-Z*(BaffleLayerZ),Z);
     ModelSupport::buildPlane(SMap,TSTIndex+39,Origin+Z*(BaffleLayerZ),Z);

   // Baffle Cladding

     double BaffleCladdingLayerX(BaffleLayerX+BaffleCladdingThickness);
     ModelSupport::buildPlane(SMap,TSTIndex+47,Origin-X*(BaffleCladdingLayerX),X);
     ModelSupport::buildPlane(SMap,TSTIndex+57,Origin+X*(BaffleCladdingLayerX),X);

     double BaffleCladdingLayerY(BaffleLayerY+BaffleCladdingThickness);
     ModelSupport::buildPlane(SMap,TSTIndex+48,Origin-Y*(BaffleCladdingLayerY),Y);
     ModelSupport::buildPlane(SMap,TSTIndex+58,Origin+Y*(BaffleCladdingLayerY),Y);

     double BaffleCladdingLayerZ(BaffleLayerZ+BaffleCladdingThickness);
     ModelSupport::buildPlane(SMap,TSTIndex+49,Origin-Z*(BaffleCladdingLayerZ),Z);
     ModelSupport::buildPlane(SMap,TSTIndex+59,Origin+Z*(BaffleCladdingLayerZ),Z);

     // Cooling

     double CoolingLayerX(BaffleCladdingLayerX+CoolingThickness);
     ModelSupport::buildPlane(SMap,TSTIndex+67,Origin-X*(CoolingLayerX),X);
     ModelSupport::buildPlane(SMap,TSTIndex+77,Origin+X*(CoolingLayerX),X);

     double CoolingLayerY(BaffleCladdingLayerY+CoolingThickness);
     ModelSupport::buildPlane(SMap,TSTIndex+68,Origin-Y*(CoolingLayerY),Y);
     ModelSupport::buildPlane(SMap,TSTIndex+78,Origin+Y*(CoolingLayerY),Y);

     double CoolingLayerZ(BaffleCladdingLayerZ+CoolingThickness);
     ModelSupport::buildPlane(SMap,TSTIndex+69,Origin-Z*(CoolingLayerZ),Z);
     ModelSupport::buildPlane(SMap,TSTIndex+79,Origin+Z*(CoolingLayerZ),Z);

     // Cooling Cladding

     double CoolingCladdingLayerX(CoolingLayerX+CoolingCladdingThickness);
     ModelSupport::buildPlane(SMap,TSTIndex+87,Origin-X*(CoolingCladdingLayerX),X);
     ModelSupport::buildPlane(SMap,TSTIndex+97,Origin+X*(CoolingCladdingLayerX),X);

     double CoolingCladdingLayerY(CoolingLayerY+CoolingCladdingThickness);
     ModelSupport::buildPlane(SMap,TSTIndex+88,Origin-Y*(CoolingCladdingLayerY),Y);
     ModelSupport::buildPlane(SMap,TSTIndex+98,Origin+Y*(CoolingCladdingLayerY),Y);

     double CoolingCladdingLayerZ(CoolingLayerZ+CoolingCladdingThickness);
     ModelSupport::buildPlane(SMap,TSTIndex+89,Origin-Z*(CoolingCladdingLayerZ),Z);
     ModelSupport::buildPlane(SMap,TSTIndex+99,Origin+Z*(CoolingCladdingLayerZ),Z);




   return;
}



void
fusionStation::addToInsertChain(attachSystem::ContainedComp& CC) const
  /*!
    Adds this object to the containedComp to be inserted.
    \param CC :: ContainedComp object to add to this
  */
{

  for(int i=TSTIndex+1;i<TSTIndex;i++)
    CC.addInsertCell(i);
    
  return;
}




void
fusionStation::createObjects(Simulation& System)
  /*!
    Create all the objects
    \param System :: Simulation to create objects in
  */
{
  ELog::RegMethod RegA("fusionStation","createObjects");
  std::string Out;

  const std::string gapStr=
    ModelSupport::getComposite(SMap,TSTIndex," 5 -6 ");

  int TIx(TSTIndex);
  int TIy(TSTIndex);
     
  TIx=TSTIndex; 
  for(size_t i=0;i<SampleBlockRows;i++)  
    {
     TIy=TSTIndex; 
     for(size_t j=0;j<SampleBlockColumns;j++)  
	{
	  Out=ModelSupport::getComposite(SMap,TIx,TIy,"1 -11 3M -13M");
	  System.addCell(MonteCarlo::Qhull(cellIndex++,SampleBlockMaterial,
          SampleBlockTemperature,Out+gapStr));
	  TIy+=10;
	}
     TIx+=10;
    }
  
  

          Out=ModelSupport::getComposite(SMap,TSTIndex,TIy-10,
          "7 -17 8 -18 9 -19  (-1 : 11M : -3 : 13M : -5 : 6)");
	  System.addCell(MonteCarlo::Qhull(cellIndex++,SampleCladdingMaterial,
          SampleCladdingTemperature,Out));

          Out=ModelSupport::getComposite(SMap,TSTIndex,
          "27 -37 28 -38 29 -39 (-7 : 17 : -8 : 18 : -9 : 19)");
	  System.addCell(MonteCarlo::Qhull(cellIndex++,BaffleMaterial,
          BaffleTemperature,Out));

          Out=ModelSupport::getComposite(SMap,TSTIndex,
          "47 -57 48 -58 49 -59  (-27 : 37 : -28 : 38 : -29 : 39)");
	  System.addCell(MonteCarlo::Qhull(cellIndex++,BaffleCladdingMaterial,
          BaffleCladdingTemperature,Out));

          Out=ModelSupport::getComposite(SMap,TSTIndex,
          "67 -77 68 -78 69 -79 (-47 : 57 : -48 : 58 : -49 : 59)");
	  System.addCell(MonteCarlo::Qhull(cellIndex++,CoolingMaterial,
          CoolingTemperature,Out));

          Out=ModelSupport::getComposite(SMap,TSTIndex,
          "87 -97 88 -98 89 -99 (-67 : 77 : -68 : 78 : -69 : 79)");
	  System.addCell(MonteCarlo::Qhull(cellIndex++,CoolingCladdingMaterial,
          CoolingCladdingTemperature,Out));

          Out=ModelSupport::getComposite(SMap,TSTIndex,"87 -97 88 -98 89 -99");
          addOuterSurf(Out);

  return;
}

void
fusionStation::createLinks()
  /*!
    Create all the links
  */
{

  return;
}

void
fusionStation::createAll(Simulation& System,
		 const attachSystem::FixedComp& FC)
  /*!
    Generic function to create everything
    \param System :: Simulation item
    \param FC :: Fixed Component for origin
  */
{
  ELog::RegMethod RegA("fusionStation","createAll");

  populate(System);
  createUnitVector(FC);
  createSurfaces();
  createObjects(System);
  createLinks();
  insertObjects(System);

  return;
}
  
}  // NAMESPACE TMRsystem
