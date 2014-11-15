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



// #include "Exception.h"
// #include "FileReport.h"
// #include "GTKreport.h"
// #include "NameStack.h"
// #include "RegMethod.h"
// #include "OutputLog.h"
// #include "surfRegister.h"
// #include "objectRegister.h"
// #include "BaseVisit.h"
// #include "BaseModVisit.h"
// #include "MatrixBase.h"
// #include "Matrix.h"
// #include "Vec3D.h"
// #include "Quaternion.h"
// #include "Surface.h"
// #include "surfIndex.h"
// #include "Quadratic.h"
// #include "Rules.h"
// #include "varList.h"
// #include "Code.h"
// #include "FuncDataBase.h"
// #include "Object.h"
// #include "Qhull.h"
// #include "Simulation.h"
// #include "ModelSupport.h"
// #include "generateSurf.h"
// #include "support.h"
// #include "stringCombine.h"
// #include "LinkUnit.h"
// #include "FixedComp.h"
// #include "ContainedComp.h"


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
#include "Triple.h"
#include "NRange.h"
#include "NList.h"
#include "Tally.h"
#include "Quaternion.h"
#include "localRotate.h"
#include "masterRotate.h"
#include "Surface.h"
#include "surfIndex.h"
#include "surfRegister.h"
#include "objectRegister.h"
#include "surfEqual.h"
#include "surfDivide.h"
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
#include "KGroup.h"
#include "Source.h"
#include "Simulation.h"
#include "ModelSupport.h"
#include "generateSurf.h"
#include "SimProcess.h"
#include "chipDataStore.h"
#include "LinkUnit.h"
#include "FixedComp.h"
#include "LinearComp.h"
#include "ContainedComp.h"
#include "channel.h"
#include "boxValues.h"
#include "boxUnit.h"
#include "BoxLine.h"

#include "BasementRooms.h"


namespace essSystem
{

  essBasementRooms::essBasementRooms(const std::string& Key) :
  attachSystem::ContainedComp(),attachSystem::FixedComp(Key,3),
  roomIndex(ModelSupport::objectRegister::Instance().cell(Key)),
  cellIndex(roomIndex+1)

  /*!
    Constructor
    \param Key :: Name of construction key
  */
{}

  essBasementRooms::essBasementRooms(const essBasementRooms& A) : 
  attachSystem::ContainedComp(A),attachSystem::FixedComp(A),
  roomIndex(A.roomIndex),cellIndex(A.cellIndex),xStep(A.xStep),
  yStep(A.yStep),zStep(A.zStep),xyAngle(A.xyAngle),
  zAngle(A.zAngle),width(A.width),heightY(A.heightY),
  heightX1(A.heightX1),heightX2(A.heightX2),heightX3(A.heightX3),
  length(A.length),innerRadius(A.innerRadius),outerRadius(A.outerRadius),
  wallThickTop(A.wallThickTop),wallThickTopMax(A.wallThickTopMax),
  wallThickDown(A.wallThickDown),wallThickSide(A.wallThickSide),
  wallThickInner(A.wallThickInner),wallAngleInner(A.wallAngleInner),
  wallMat(A.wallMat),MainCell(A.MainCell)

  {}


  essBasementRooms&
  essBasementRooms::operator=(const essBasementRooms& A)
  /*!
    Assignment operator
    \param A :: essBasementRooms to copy
    \return *this
  */
{
  if (this!=&A)
    {
      attachSystem::ContainedComp::operator=(A);
      attachSystem::FixedComp::operator=(A);
      cellIndex=A.cellIndex;
      xStep=A.xStep;
      yStep=A.yStep;
      zStep=A.zStep;
      xyAngle=A.xyAngle;
      zAngle=A.zAngle;
      width=A.width;
      heightY=A.heightY;
      heightX1=A.heightX1;
      heightX2=A.heightX2;
      heightX3=A.heightX3;
      length=A.length;
      innerRadius=A.innerRadius;
      outerRadius=A.outerRadius;
      wallThickTop=A.wallThickTop;
      wallThickTopMax=A.wallThickTopMax;
      wallThickDown=A.wallThickDown;
      wallThickSide=A.wallThickSide;
      wallThickInner=A.wallThickInner;
      wallAngleInner=A.wallAngleInner;
      wallMat=A.wallMat;
      MainCell=A.MainCell;

    }
  return *this;
}




essBasementRooms::~essBasementRooms()
  /*!
    Destructor
   */
{}

void
essBasementRooms::populate(const FuncDataBase& Control)
  /*!
    Populate all the variables
    \param Control :: Variable table to use
  */
{
  ELog::RegMethod RegA("essBasementRooms","populate");


    // Master values
  xStep=Control.EvalVar<double>(keyName+"XStep");
  yStep=Control.EvalVar<double>(keyName+"YStep");
  zStep=Control.EvalVar<double>(keyName+"ZStep");
  xyAngle=Control.EvalVar<double>(keyName+"XYangle");
  zAngle=Control.EvalVar<double>(keyName+"Zangle");
  width=Control.EvalVar<double>(keyName+"Width");   

  //height romms: beam dump and forward
  heightY=Control.EvalVar<double>(keyName+"YHeight");   

  //height right back room (looking from beam dir) 
  heightX1=Control.EvalVar<double>(keyName+"X1Height");   

  //height left room (looking from beam dir) 
  heightX2=Control.EvalVar<double>(keyName+"X2Height");

  //height right front room (looking from beam dir)   
  heightX3=Control.EvalVar<double>(keyName+"X3Height");   

  length=Control.EvalVar<double>(keyName+"Length"); 
  innerRadius=Control.EvalVar<double>(keyName+"InnerRadius");   
  outerRadius=Control.EvalVar<double>(keyName+"OuterRadius"); 

  wallThickTopMax=Control.EvalVar<double>(keyName+"TopWallThickMax");   
  wallThickTop=Control.EvalVar<double>(keyName+"TopWallThick");   
  wallThickDown=Control.EvalVar<double>(keyName+"BottomWallThick");   
  wallThickSide=Control.EvalVar<double>(keyName+"SideWallThick");   
  wallThickInner=Control.EvalVar<double>(keyName+"InnerWallThick");   
  wallAngleInner=Control.EvalVar<double>(keyName+"InnerWallAngle");   

 wallMat=Control.EvalVar<int>(keyName+"WallMat");
 
 
  return;
}

void
essBasementRooms::createUnitVector(const attachSystem::FixedComp& FC)
  /*!
    Create the unit vectors
    \param FC :: Fixed Component
  */
{
  ELog::RegMethod RegA("essBasementRooms","createUnitVector");
  attachSystem::FixedComp::createUnitVector(FC);


  //  Origin1=Origin;
  //  std::cout<<" OOO "<<Origin1<<std::endl;
  Origin+=X*xStep+Y*yStep+Z*zStep;

  return;
}

void
essBasementRooms::createSurfaces()
  /*!
    Create Surfaces for the Be
  */
{
  ELog::RegMethod RegA("essBasementRooms","createSurfaces");
  
  ModelSupport::buildPlane(SMap,roomIndex+1,Origin-X*(width/2.0),X);  
  ModelSupport::buildPlane(SMap,roomIndex+2,Origin+X*(width/2.0),X);  

  ModelSupport::buildPlane(SMap,roomIndex+3,Origin-Y*(length/2.0),Y);  
  ModelSupport::buildPlane(SMap,roomIndex+4,Origin+Y*(length/2.0),Y);      

  //height romms: beam dump and forward room 
  ModelSupport::buildPlane(SMap,roomIndex+5,Origin,Z);  
  ModelSupport::buildPlane(SMap,roomIndex+6,Origin+Z*heightY,Z);  

  //height right back room (looking from beam dir) 
  // ModelSupport::buildPlane(SMap,roomIndex+25,Origin-Z*(heightX1/2.0),Z);  
  ModelSupport::buildPlane(SMap,roomIndex+16,Origin+Z*heightX1,Z);  

  //height left room (looking from beam dir) 
  // ModelSupport::buildPlane(SMap,roomIndex+35,Origin-Z*(heightX2/2.0),Z);  
  ModelSupport::buildPlane(SMap,roomIndex+26,Origin+Z*heightX2,Z);  

  //height right front room (looking from beam dir)
  // ModelSupport::buildPlane(SMap,roomIndex+45,Origin-Z*(heightX3/2.0),Z);  
  ModelSupport::buildPlane(SMap,roomIndex+36,Origin+Z*heightX3,Z);  

  // walls

  ModelSupport::buildPlane(SMap,roomIndex+101,Origin-X*(width/2.0+wallThickSide),X);  
  ModelSupport::buildPlane(SMap,roomIndex+102,Origin+X*(width/2.0+wallThickSide),X);  

  ModelSupport::buildPlane(SMap,roomIndex+103,Origin-Y*(length/2.0+wallThickSide),Y);  
  ModelSupport::buildPlane(SMap,roomIndex+104,Origin+Y*(length/2.0+wallThickSide),Y);      

  ModelSupport::buildPlane(SMap,roomIndex+105,Origin-Z*wallThickDown,Z);
  
  ModelSupport::buildPlane(SMap,roomIndex+106,Origin+Z*(heightY+wallThickTop),Z);  
  ModelSupport::buildPlane(SMap,roomIndex+116,Origin+Z*(heightX1+wallThickTop),Z);  
  ModelSupport::buildPlane(SMap,roomIndex+126,Origin+Z*(heightX2+wallThickTop),Z);  
  ModelSupport::buildPlane(SMap,roomIndex+136,Origin+Z*(heightX3+wallThickTopMax),Z);  
 
  ModelSupport::buildPlane(SMap,roomIndex+100,Origin,X);  
  ModelSupport::buildPlane(SMap,roomIndex+300,Origin,Y);  

  double innerOffset(0);
  double outerOffset(0);
  const double pi(3.14159265359); 


  innerOffset=length/2-1000/tan((90-wallAngleInner)/180*pi);
  outerOffset=wallThickInner/sin((90-wallAngleInner)/180*pi);

  Geometry::Vec3D Origin1(Origin);
  Origin1=Origin+Y*innerOffset; 

  Geometry::Vec3D X1(X);
  Geometry::Vec3D Y1(Y);
  Geometry::Vec3D Z1(Z);

  const Geometry::Quaternion Qz=
    Geometry::Quaternion::calcQRotDeg(0,X1);
  const Geometry::Quaternion Qxy=
    Geometry::Quaternion::calcQRotDeg(wallAngleInner,Z1);

   Qz.rotate(Y1);
   Qz.rotate(Z1);
   Qxy.rotate(Y1);
   Qxy.rotate(X1);
   Qxy.rotate(Z1);



  ModelSupport::buildPlane(SMap,roomIndex+23,Origin1,Y1);  
  ModelSupport::buildPlane(SMap,roomIndex+24,Origin1-Y*outerOffset,Y1);  


   Qz.rotate(Y1);
   Qz.rotate(Z1);
   Qxy.rotate(Y1);
   Qxy.rotate(X1);
   Qxy.rotate(Z1);

  ModelSupport::buildPlane(SMap,roomIndex+33,Origin1,Y1);  
  ModelSupport::buildPlane(SMap,roomIndex+34,Origin1-Y*outerOffset,Y1);  



  Geometry::Vec3D Origin2(Origin);
  Origin2=Origin-Y*innerOffset; 

  Geometry::Vec3D X2(X);
  Geometry::Vec3D Y2(Y);
  Geometry::Vec3D Z2(Z);

  const Geometry::Quaternion Qz1=
    Geometry::Quaternion::calcQRotDeg(0,X2);
  const Geometry::Quaternion Qxy1=
    Geometry::Quaternion::calcQRotDeg(-wallAngleInner,Z2);

   Qz1.rotate(Y2);
   Qz1.rotate(Z2);
   Qxy1.rotate(Y2);
   Qxy1.rotate(X2);
   Qxy1.rotate(Z2);


  ModelSupport::buildPlane(SMap,roomIndex+43,Origin2,Y2);  
  ModelSupport::buildPlane(SMap,roomIndex+44,Origin2+Y*outerOffset,Y2);  


   Qz1.rotate(Y2);
   Qz1.rotate(Z2);
   Qxy1.rotate(Y2);
   Qxy1.rotate(X2);
   Qxy1.rotate(Z2);


  ModelSupport::buildPlane(SMap,roomIndex+53,Origin2,Y2);  
  ModelSupport::buildPlane(SMap,roomIndex+54,Origin2+Y*outerOffset,Y2);  


  ModelSupport::buildPlane(SMap,roomIndex+600,Origin+Y*(400),Z);  

  ModelSupport::buildCylinder(SMap,roomIndex+7,Origin,Z,innerRadius);  
  ModelSupport::buildCylinder(SMap,roomIndex+17,Origin,Z,outerRadius);  


  return; 
}



void
essBasementRooms::addToInsertChain(attachSystem::ContainedComp& CC) const
  /*!
    Adds this object to the containedComp to be inserted.
    \param CC :: ContainedComp object to add to this
  */
{
  for(int i=roomIndex+1;i<cellIndex;i++)
    CC.addInsertCell(i);
    
  return;
}





void
  essBasementRooms::createObjects(Simulation& System)
  /*!
    Create the vaned moderator
    \param System :: Simulation to add results
   */
{
  ELog::RegMethod RegA("essBasementRooms","createObjects");

  std::string Out;
  

  //forward room 
  Out=ModelSupport::getComposite(SMap,roomIndex," (300 -4 5 -6 17 23 -33) ");
  System.addCell(MonteCarlo::Qhull(cellIndex++,0,0.0,Out));

  Out=ModelSupport::getComposite(SMap,roomIndex," (300 -4 5 -6 7 -17 23 -33) ");
  System.addCell(MonteCarlo::Qhull(cellIndex++,wallMat,0.0,Out));

  Out=ModelSupport::getComposite(SMap,roomIndex," ( 300 -2  -4 5 -136 7 -23 24");
  System.addCell(MonteCarlo::Qhull(cellIndex++,wallMat,0.0,Out));

  Out=ModelSupport::getComposite(SMap,roomIndex," (300 -4 6 -106 7 23 -33) ");
  System.addCell(MonteCarlo::Qhull(cellIndex++,wallMat,0.0,Out));

 
  // dummy cell
  Out=ModelSupport::getComposite(SMap,roomIndex," (300 -4 106 -136  7 23 -33) ");
  System.addCell(MonteCarlo::Qhull(cellIndex++,0,0.0,Out));

  // Out=ModelSupport::getComposite(SMap,roomIndex," ( 300 -2  -4 106 -136 7 -23 24");
  // System.addCell(MonteCarlo::Qhull(cellIndex++,0,0.0,Out));


  // right room (2)
  Out=ModelSupport::getComposite(SMap,roomIndex," ( -2 3 5 -136 7 43 -44 100");
  System.addCell(MonteCarlo::Qhull(cellIndex++,wallMat,0.0,Out));

  // right front
  Out=ModelSupport::getComposite(SMap,roomIndex," ( -2 100 300 5 -36 7 44 -24)");
  System.addCell(MonteCarlo::Qhull(cellIndex++,0,0.0,Out));


  Out=ModelSupport::getComposite(SMap,roomIndex," ( -2 100 300 36 -136 7 44 -24)");
  System.addCell(MonteCarlo::Qhull(cellIndex++,wallMat,0.0,Out));


  // right back
  Out=ModelSupport::getComposite(SMap,roomIndex," ( -2 100 -300 5 -16 7 44 -24)");
  System.addCell(MonteCarlo::Qhull(cellIndex++,0,0.0,Out));

  Out=ModelSupport::getComposite(SMap,roomIndex," ( -2 100 -300 16 -116 7 44 -24)");
  System.addCell(MonteCarlo::Qhull(cellIndex++,wallMat,0.0,Out));

  Out=ModelSupport::getComposite(SMap,roomIndex," ( -2 100 -300 116 -136 7 44 -24)");
  System.addCell(MonteCarlo::Qhull(cellIndex++,wallMat,0.0,Out));



  // dump room
  //wall
  Out=ModelSupport::getComposite(SMap,roomIndex," ( 1 -2 3 -4 5 -136 7 -53 54 -100");
  System.addCell(MonteCarlo::Qhull(cellIndex++,wallMat,0.0,Out));

  Out=ModelSupport::getComposite(SMap,roomIndex," (-300 3  5 -6 17 53 -43)");
  System.addCell(MonteCarlo::Qhull(cellIndex++,0,0.0,Out));

  Out=ModelSupport::getComposite(SMap,roomIndex," (-300 3  5 -6 7 -17 53 -43)");
  System.addCell(MonteCarlo::Qhull(cellIndex++,wallMat,0.0,Out));

  Out=ModelSupport::getComposite(SMap,roomIndex," (-300 3 6 -106 7 53 -43)");
  System.addCell(MonteCarlo::Qhull(cellIndex++,wallMat,0.0,Out));
  // dummy
  Out=ModelSupport::getComposite(SMap,roomIndex," (-300 3  106 -136 7 53 -43)");
  System.addCell(MonteCarlo::Qhull(cellIndex++,0,0.0,Out));



  // left room
  Out=ModelSupport::getComposite(SMap,roomIndex," ( 1  -4 5 -136 7 33 -34 300");
  System.addCell(MonteCarlo::Qhull(cellIndex++,wallMat,0.0,Out));

  Out=ModelSupport::getComposite(SMap,roomIndex," ( 1  5 -26 7 -54 34 -100)");
  System.addCell(MonteCarlo::Qhull(cellIndex++,0,0.0,Out));

  Out=ModelSupport::getComposite(SMap,roomIndex," ( 1 26 -126 7 -54 34 -100)");
  System.addCell(MonteCarlo::Qhull(cellIndex++,wallMat,0.0,Out));
  //dummy
  Out=ModelSupport::getComposite(SMap,roomIndex," ( 1  126 -136 7 -54 34 -100)");
  System.addCell(MonteCarlo::Qhull(cellIndex++,0,0.0,Out));

  // Out=ModelSupport::getComposite(SMap,roomIndex," ( 1  -4 5 126 -136 7 33 -34 300");
  // System.addCell(MonteCarlo::Qhull(cellIndex++,0,0.0,Out));


  MainCell=cellIndex-1;

  // block below monolith (16 is top surf of 2m room)
  Out=ModelSupport::getComposite(SMap,roomIndex," ( -7 105 -16 )");
  System.addCell(MonteCarlo::Qhull(cellIndex++,wallMat,0.0,Out));

  // base
  Out=ModelSupport::getComposite(SMap,roomIndex," ( 101 -102 103 -104 105 7  -5 ");
  System.addCell(MonteCarlo::Qhull(cellIndex++,wallMat,0.0,Out));


  // side 
  Out=ModelSupport::getComposite(SMap,roomIndex," ( 101 -102 103 -104 5 -136 (-1 : 2 : -3 : 4 )");
  System.addCell(MonteCarlo::Qhull(cellIndex++,wallMat,0.0,Out));

  // top of side walls 
  // Out=ModelSupport::getComposite(SMap,roomIndex," ( 101 -102 103 -104 6 -136  7 (-1 : 2 : -3 : 4 )");
  // System.addCell(MonteCarlo::Qhull(cellIndex++,wallMat,0.0,Out));


  Out=ModelSupport::getComposite(SMap,roomIndex," ( (101 -102 103 -104 105 -136 7 ):( -7 105 -16 )");
  addOuterSurf(Out);

  return; 

}


void
essBasementRooms::createLinks()
  /*!
    Creates a full attachment set
  */
{
  
  return;
}


void
essBasementRooms::createAll(Simulation& System,
			   const attachSystem::FixedComp& FC)
  /*!
    Extrenal build everything
    \param System :: Simulation
    \param FC :: FixedComponent for origin
   */
{
  ELog::RegMethod RegA("essBasementRooms","createAll");
  populate(System.getDataBase());

  createUnitVector(FC);
  createSurfaces();
  createObjects(System);
  createLinks();
  insertObjects(System);       

  return;
}

}  // NAMESPACE instrumentSystem
