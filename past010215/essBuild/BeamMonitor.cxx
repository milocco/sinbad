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
#include <numeric>
#include <boost/shared_ptr.hpp>
#include <boost/array.hpp>
#include <boost/multi_array.hpp>

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
#include "generateSurf.h"
#include "SimProcess.h"
#include "LinkUnit.h"
#include "FixedComp.h"
#include "ContainedComp.h"
#include "ContainedGroup.h"

#include "BeamMonitor.h"

namespace essSystem
{

BeamMonitor::BeamMonitor(const std::string& Key) :
  attachSystem::ContainedComp(),attachSystem::FixedComp(Key,3),
  monIndex(ModelSupport::objectRegister::Instance().cell(Key)),
  cellIndex(monIndex+1)
  /*!
    Constructor
    \param Key :: Keyname for system
  */
{}

BeamMonitor::BeamMonitor(const BeamMonitor& A) :
  attachSystem::ContainedComp(A),attachSystem::FixedComp(A),
  monIndex(A.monIndex),cellIndex(A.cellIndex),
  // xStep(A.xStep),yStep(A.yStep),zStep(A.zStep),
  // xyAngle(A.xyAngle),zAngle(A.zAngle),nSecT(A.nSecT),
  // radiusT(A.radiusT),lengthT(A.lengthT),cutT(A.cutT),
  // thickT(A.thickT),inMatT(A.inMatT),wallMatT(A.wallMatT),
  // XsetW(A.XsetW),YsetW(A.YsetW),ZsetW(A.ZsetW),sideW(A.sideW),
  // nSecW(A.nSecW),radiusW(A.radiusW), thickW(A.thickW),
  matW(A.matW)
  // ,
  // frameSide(A.frameSide),frameHeightA(A.frameHeightA),
  // frameHeightB(A.frameHeightB),frameHeightC(A.frameHeightC),
  // frameHeightD(A.frameHeightD),  
  // frameWidthA(A.frameWidthA),frameWidthB(A.frameWidthB),
  // frameWidthC(A.frameWidthC),frameThickA(A.frameThickA),
  // frameThickB(A.frameThickB),frameThickC(A.frameThickC),
  // tubeN(A.tubeN),tubeRadius(A.tubeRadius),tubeThick(A.tubeThick),
  // tubeHe(A.tubeHe),tubeAl(A.tubeAl),extTubeHe(A.extTubeHe),
  // mainPBeamACell(A.mainPBeamACell)

  /*!
    Constructor
    \param Key :: Name of construction key
  */
{}

BeamMonitor&
BeamMonitor::operator=(const BeamMonitor& A) 
{
  if (&A!=this)
    {
     attachSystem::ContainedComp::operator=(A);
     attachSystem::FixedComp::operator=(A);
     //    wheelIndex=A.wheelIndex;
     // cellIndex=A.cellIndex;
     // xStep=A.xStep;
     // yStep=A.yStep;
     // zStep=A.zStep;
     // xyAngle=A.xyAngle;
     // zAngle=A.zAngle;
     // nSecT=A.nSecT;
     // radiusT=A.radiusT;
     // lengthT=A.lengthT;
     // cutT=A.cutT;
     // thickT=A.thickT;
     // inMatT=A.inMatT;
     // wallMatT=A.wallMatT;
     // XsetW=A.XsetW;
     // YsetW=A.YsetW;
     // ZsetW=A.ZsetW;
     // sideW=A.sideW;
     // nSecW=A.nSecW;
     // radiusW=A.radiusW;
     // thickW=A.thickW;
     matW=A.matW;    
     // frameSide=A.frameSide;
     // frameHeightA=A.frameHeightA;
     // frameHeightB=A.frameHeightB;
     // frameHeightC=A.frameHeightC;  
     // frameHeightD=A.frameHeightD;  
     // frameWidthA=A.frameWidthA;
     // frameWidthB=A.frameWidthB;
     // frameWidthC=A.frameWidthC;
     // frameThickA=A.frameThickA;
     // frameThickB=A.frameThickB;
     // frameThickC=A.frameThickC;
     // tubeN=A.tubeN;
     // tubeRadius=A.tubeRadius;
     // tubeThick=A.tubeThick;
     // tubeHe=A.tubeHe;
     // tubeAl=A.tubeAl;
     // extTubeHe=A.extTubeHe;
     // mainPBeamACell=A.mainPBeamACell;

    }
  return *this;
}



BeamMonitor::~BeamMonitor()
  /*!
    Destructor
   */
{}

void
BeamMonitor::populate(const FuncDataBase& Control)
  /*!
    Populate all the variables
    \param Control :: Variable table to use
  */
{
  ELog::RegMethod RegA("BeamMonitor","populate");


    // Master values
  xStep=Control.EvalVar<double>(keyName+"XStep");
  yStep=Control.EvalVar<double>(keyName+"YStep");
  zStep=Control.EvalVar<double>(keyName+"ZStep");

  xyAngle=Control.EvalVar<double>(keyName+"XYangle");
  zAngle=Control.EvalVar<double>(keyName+"Zangle");



  XsetW=Control.EvalVar<double>(keyName+"OffsetX");   
  YsetW=Control.EvalVar<double>(keyName+"OffsetY");   
  ZsetW=Control.EvalVar<double>(keyName+"OffsetZ");   

  sideW=Control.EvalVar<double>(keyName+"BoxSide");   

  nSecW=Control.EvalVar<size_t>(keyName+"BoxNSections");   
  double RW(0.0);
  double TW(0.0);
  int MW(0);

  /// ALB
  for(size_t i=0;i<nSecW;i++)
    {
     RW=Control.EvalVar<double>
	(StrFunc::makeString(keyName+"BoxRadius",i+1));   
     TW+=Control.EvalVar<double>
	(StrFunc::makeString(keyName+"BoxThick",i+1));     
     MW=ModelSupport::EvalMat<int>(Control,
         StrFunc::makeString(keyName+"BoxMat",i+1));   
	 ELog::EM<<" tubeAl "<<i<<" nSecW "<<MW<<ELog::endTrace;

      radiusW.push_back(RW);
      thickW.push_back(TW);
      matW.push_back(MW);
    }

  frameSide=Control.EvalVar<double>(keyName+"BoxSide5");    
  frameHeightA=Control.EvalVar<double>(keyName+"BoxHeightA5");    
  frameHeightB=Control.EvalVar<double>(keyName+"BoxHeightB5");    
  frameHeightC=Control.EvalVar<double>(keyName+"BoxHeightC5");    
  frameHeightD=Control.EvalVar<double>(keyName+"BoxHeightD5");    
  frameWidthA=Control.EvalVar<double>(keyName+"BoxWidthA5");    
  frameWidthB=Control.EvalVar<double>(keyName+"BoxWidthB5");    
  frameWidthC=Control.EvalVar<double>(keyName+"BoxWidthC5");    
  frameThickA=Control.EvalVar<double>(keyName+"BoxThickA5");    
  frameThickB=Control.EvalVar<double>(keyName+"BoxThickB5");    
  frameThickC=Control.EvalVar<double>(keyName+"BoxThickC5");    

  tubeN=Control.EvalVar<int>(keyName+"BoxTubeN");      
  tubeRadius=Control.EvalVar<double>(keyName+"BoxTubeRadius");    
  tubeThick=Control.EvalVar<double>(keyName+"BoxTubeThick");    
  
  tubeHe=ModelSupport::EvalMat<int>
	     (Control,keyName+"BoxTubeHeMat");   
  tubeAl=ModelSupport::EvalMat<int>
	     (Control,keyName+"BoxTubeAlMat");  
  extTubeHe=ModelSupport::EvalMat<int>
	     (Control,keyName+"BoxExtHeMat");

  
  ///ALB

  return;
}

void
BeamMonitor::createUnitVector(const attachSystem::FixedComp& FC)
// ,
// 			      const long int linkIndex)
  /*!
    Create the unit vectors
    \param FC :: Fixed Component
    \param linkIndex :: Link index position
  */
{
  ELog::RegMethod RegA("BeamMonitor","createUnitVector");
  attachSystem::FixedComp::createUnitVector(FC);
// ,linkIndex);
  applyShift(xStep,yStep,zStep);
  applyAngleRotate(xyAngle,zAngle);

  return;
}

void
BeamMonitor::createSurfaces()
  /*!
    Create beamline surface
  */
{
  ELog::RegMethod RegA("BeamMonitor","createSurfaces");

  // halfThick=std::accumulate(thick.begin(),thick.end(),
  // 			    0.0,std::plus<double>())/2.0;

  // int BM(monIndex);
  // double T(-halfThick);
  // for(size_t i=0;i<nSec;i++)
  //   {
  //     ModelSupport::buildPlane(SMap,BM+1,Origin+Y*T,Y);  
  //     ModelSupport::buildCylinder(SMap,BM+7,Origin,Y,radius[i]);  
  //     ELog::EM<<"I == "<<i<<" "<<T<<" "<<thick[i]<<" "
  // 	      <<Origin+Y*T<<ELog::endTrace;
  //     T+=thick[i];
      
  //     BM+=10;
  //   }
  // // Back plane
  // ModelSupport::buildPlane(SMap,BM+1,Origin+Y*T,Y);

  ModelSupport::buildCylinder(SMap,monIndex+38,Origin,Y,radiusW[0]);  
 

  int PW(monIndex+1000);
  ModelSupport::buildPlane(SMap,PW+1,Origin+X*(XsetW-sideW/2.0)+Y*YsetW+Z*ZsetW,X);  
  ModelSupport::buildPlane(SMap,PW+2,Origin+X*(XsetW+sideW/2.0)+Y*YsetW+Z*ZsetW,X);  
  ModelSupport::buildPlane(SMap,PW+3,Origin+X*XsetW+Y*(YsetW+sideW/2.0)+Z*ZsetW,Y);  
  ModelSupport::buildPlane(SMap,PW+4,Origin+X*XsetW+Y*(YsetW-sideW/2.0)+Z*ZsetW,Y);  
  ModelSupport::buildPlane(SMap,PW+5,Origin+X*XsetW+Y*YsetW+Z*(ZsetW-sideW/2.0),Z);  
  ModelSupport::buildPlane(SMap,PW+6,Origin+X*XsetW+Y*YsetW+Z*(ZsetW+sideW/2.0),Z);  

  for(size_t i=0;i<nSecW+3;i++)
    {
     PW+=10;
     if(i>=nSecW)
       { 
         radiusW[i]=radiusW[nSecW-(i-nSecW+2)];
         thickW[i]=thickW[i-1]+(thickW[nSecW-(i-nSecW+2)]-thickW[nSecW-(i-nSecW+3)]);
         matW[i]=matW[nSecW-(i-nSecW+2)];
	   }
     if(i==nSecW+2) thickW[i]+=thickW[0];
     ModelSupport::buildCylinder(SMap,PW+7,Origin,Y,radiusW[i]);  
     ModelSupport::buildPlane(SMap,PW+3,Origin+Y*(YsetW+sideW/2.0-thickW[i]),Y);
    }

  int TI(monIndex+2000);

  ModelSupport::buildPlane(SMap,TI+1,Origin+X*(XsetW-frameSide/2.0)+Y*YsetW+Z*ZsetW,X);  
  ModelSupport::buildPlane(SMap,TI+2,Origin+X*(XsetW+frameSide/2.0)+Y*YsetW+Z*ZsetW,X);  
  ModelSupport::buildPlane(SMap,TI+3,Origin+X*XsetW+Y*(YsetW-frameSide/2.0)+Z*ZsetW,Y);  
  ModelSupport::buildPlane(SMap,TI+4,Origin+X*XsetW+Y*(YsetW+frameSide/2.0)+Z*ZsetW,Y);  
  ModelSupport::buildPlane(SMap,TI+5,Origin+X*XsetW+Y*YsetW+Z*(ZsetW-frameSide/2.0),Z);  
  ModelSupport::buildPlane(SMap,TI+6,Origin+X*XsetW+Y*YsetW+Z*(ZsetW+frameSide/2.0),Z);  

  ModelSupport::buildPlane(SMap,TI+11,Origin+X*(XsetW-frameWidthA/2.0)+Y*YsetW+Z*ZsetW,X);  
  ModelSupport::buildPlane(SMap,TI+12,Origin+X*(XsetW+frameWidthA/2.0)+Y*YsetW+Z*ZsetW,X);  
  ModelSupport::buildPlane(SMap,TI+13,Origin+X*XsetW+Y*(YsetW-frameThickA/2.0)+Z*ZsetW,Y);  
  ModelSupport::buildPlane(SMap,TI+14,Origin+X*XsetW+Y*(YsetW+frameThickA/2.0)+Z*ZsetW,Y);  
  ModelSupport::buildPlane(SMap,TI+15,Origin+X*XsetW+Y*YsetW+Z*(ZsetW-frameHeightA/2.0),Z);  
  ModelSupport::buildPlane(SMap,TI+16,Origin+X*XsetW+Y*YsetW+Z*(ZsetW+frameHeightA/2.0),Z);  

  ModelSupport::buildPlane(SMap,TI+21,Origin+X*(XsetW-frameWidthB/2.0)+Y*YsetW+Z*ZsetW,X);  
  ModelSupport::buildPlane(SMap,TI+22,Origin+X*(XsetW+frameWidthB/2.0)+Y*YsetW+Z*ZsetW,X);  
  ModelSupport::buildPlane(SMap,TI+23,Origin+X*XsetW+Y*(YsetW-frameThickB/2.0)+Z*ZsetW,Y);  
  ModelSupport::buildPlane(SMap,TI+24,Origin+X*XsetW+Y*(YsetW+frameThickB/2.0)+Z*ZsetW,Y);  
  ModelSupport::buildPlane(SMap,TI+25,Origin+X*XsetW+Y*YsetW+Z*(ZsetW-frameHeightB/2.0),Z);  
  ModelSupport::buildPlane(SMap,TI+26,Origin+X*XsetW+Y*YsetW+Z*(ZsetW+frameHeightB/2.0),Z);  

  ModelSupport::buildPlane(SMap,TI+31,Origin+X*(XsetW-frameWidthC/2.0)+Y*YsetW+Z*ZsetW,X);  
  ModelSupport::buildPlane(SMap,TI+32,Origin+X*(XsetW+frameWidthC/2.0)+Y*YsetW+Z*ZsetW,X);  
  ModelSupport::buildPlane(SMap,TI+33,Origin+X*XsetW+Y*(YsetW-frameThickC/2.0)+Z*ZsetW,Y);  
  ModelSupport::buildPlane(SMap,TI+34,Origin+X*XsetW+Y*(YsetW+frameThickC/2.0)+Z*ZsetW,Y);  
  ModelSupport::buildPlane(SMap,TI+35,Origin+X*XsetW+Y*YsetW+Z*(ZsetW-frameHeightC/2.0),Z);  
  ModelSupport::buildPlane(SMap,TI+36,Origin+X*XsetW+Y*YsetW+Z*(ZsetW+frameHeightC/2.0),Z);  

  ModelSupport::buildPlane(SMap,TI+45,Origin+X*XsetW+Y*YsetW+Z*(ZsetW-frameHeightD/2.0),Z);  
  ModelSupport::buildPlane(SMap,TI+46,Origin+X*XsetW+Y*YsetW+Z*(ZsetW+frameHeightD/2.0),Z);  


  for(int i=0;i<tubeN;i++)
    {
      ModelSupport::buildCylinder(SMap,TI+7,
				  Origin+X*(XsetW-frameWidthC/2.0+0.3+i*2*(tubeRadius+tubeThick))
				  +Y*YsetW+Z*ZsetW,Z,tubeRadius);  
      ModelSupport::buildCylinder(SMap,TI+8,
				  Origin+X*(XsetW-frameWidthC/2.0+0.3+i*2*(tubeRadius+tubeThick))
				  +Y*YsetW+Z*ZsetW,Z,tubeRadius+tubeThick);
      TI+=10;
    }
  return; 
}

std::string
BeamMonitor::calcExclude(const size_t index,
			 const attachSystem::ContainedGroup& CG, 
			 const std::string& CName) const
  /*!
    Calculate if the ContainedGroup needs to be excluded from the 
    object
    \param index :: Index value
    \param CG :: contained group
    \param CName :: Contained Name
    \return Exclude string
  */
{
  ELog::RegMethod RegA("BeamMonitor","calcExclude");
  
  const double totalThick=
    std::accumulate(thick.begin(),thick.begin()+
		    static_cast<std::ptrdiff_t>(index),
		    0.0,std::plus<double>());

  const Geometry::Vec3D PtA(Origin+Y*(totalThick-halfThick));
  const Geometry::Vec3D PtB(Origin+Y*(totalThick-halfThick+thick[index]));

  std::string Out;
  for(size_t i=0;i<CG.nGroups();i++)
    {
      const std::string CKey=CName+StrFunc::makeString(i);
      if (CG.hasKey(CKey))
	{
	  const ContainedComp& CA=CG.getKey(CKey);
	  if (CA.isOuterLine(PtA,PtB))
	    {
	      ELog::EM<<"Found["<<index<<"] "<<i<<ELog::endTrace;
	      Out+=CA.getExclude();
	    }
	}
    }
  ELog::EM<<"Pts = "<<PtA<<" :: "<<PtB<<ELog::endTrace;
  ELog::EM<<"Exclude["<<index<<"] == "<<Out<<ELog::endTrace;
      
  return Out;
}


void
BeamMonitor::createObjects(Simulation& System)
// ,
// 			   const attachSystem::ContainedGroup& CG, 
// 			   const std::string& CName)
  /*!
    Adds the components
    \param System :: Simulation to create objects in
    \param CG :: Contained Group
    \param CName :: Contained Segment name      
  */
{
  ELog::RegMethod RegA("BeamMonitor","createObjects");
    
  // std::string Out;
  // int BM(monIndex);
  // for(size_t i=0;i<nSec;i++)
  //   {
  //     Out=ModelSupport::getComposite(SMap,BM,"1 -11 -7 ");      
  //     addOuterSurf(Out);
  //     const std::string Exclude=
  // 	calcExclude(i,CG,CName);

  //     System.addCell(MonteCarlo::Qhull(cellIndex++,mat[i],0.0,Out+Exclude));
  //     BM+=10;
  //   }

  ///ALB


    int protonVoidCell;           ///< Inner void cell

  std::string OutTot;
  std::string OutTube;

  std::string OutLeft;
  //  OutLeft=TargetSurfBoundary;
  std::string Out;
  int PT(monIndex);
  int PW(monIndex+1000);	    

  for(size_t i=0;i<nSecW+3;i++)
    {
     Out=ModelSupport::getComposite(SMap,monIndex,PW,"(38 -17M -3M 13M)");
     OutTot+=":"+Out;

     if(i==nSecW-1) 
       {
        Out=ModelSupport::getComposite(SMap,monIndex,"( 38 ");
        Out+=ModelSupport::getComposite(SMap,monIndex+1000,PW," 1 -2 -3 13M 5 -6 )");
        OutTot+=":"+Out;  
        Out=ModelSupport::getComposite(SMap,monIndex,"( 38 ");
        Out+=ModelSupport::getComposite(SMap,monIndex+1000,PW," 1 -2 4 -3M 5 -6 )");
        OutTot+=":"+Out;  
        Out=ModelSupport::getComposite(SMap,monIndex+1000,PW,"( 1 -2 -3M 13M 5 -6 )");
        OutTot+=":"+Out;  

	// 
        int TI(monIndex+2000);

        for(int i=0;i<tubeN;i++)
          {
	    Out=ModelSupport::getComposite(SMap,monIndex+2000,TI,"-7M 25 -26");
	    System.addCell(MonteCarlo::Qhull(cellIndex++,tubeHe,0.0,Out));
	    Out=ModelSupport::getComposite(SMap,monIndex+2000,TI,"7M -8M 25 -26");
	    System.addCell(MonteCarlo::Qhull(cellIndex++,tubeAl,0.0,Out));
	    OutTube+=ModelSupport::getComposite(SMap,TI," 8M ");
	    
	    TI+=10;  
	  }
	// hugly piece by piece

        Out=ModelSupport::getComposite(SMap,monIndex+2000,PW,
                                       "(-11:12:-15:16) 1 -2 5 -6 -3M 13M");
        System.addCell(MonteCarlo::Qhull(cellIndex++,matW[i],0.0,Out));

        Out=ModelSupport::getComposite(SMap,monIndex+2000,PW, " 11 -12 13 -14 15 -16 (-25:26)");
        System.addCell(MonteCarlo::Qhull(cellIndex++,tubeHe,0.0,Out));

        Out=ModelSupport::getComposite(SMap,monIndex+2000,PW," 11 -12 -3M 14 15 -16 (-35:36) ");
        System.addCell(MonteCarlo::Qhull(cellIndex++,tubeAl,0.0,Out));

        Out=ModelSupport::getComposite(SMap,monIndex+2000,PW," 11 -12 13M -13 15 -16 (-35:36) ");
        System.addCell(MonteCarlo::Qhull(cellIndex++,tubeAl,0.0,Out));

        Out=ModelSupport::getComposite(SMap,monIndex+2000," 11 -12 13 -14 25 -26 (-45:46)");
        System.addCell(MonteCarlo::Qhull(cellIndex++,tubeAl,0.0,Out+OutTube));

        Out=ModelSupport::getComposite(SMap,monIndex+2000," (11 -12 33 -34  45 -46) ");
        System.addCell(MonteCarlo::Qhull(cellIndex++,tubeAl,0.0,Out+OutTube));

        Out=ModelSupport::getComposite(SMap,monIndex+2000,PW, " 31 -32 -33 13 45 -46");
        System.addCell(MonteCarlo::Qhull(cellIndex++,0,0.0,Out+OutTube));

        Out=ModelSupport::getComposite(SMap,monIndex+2000,PW, " 11 -12 (-31: 32) -33 13 45 -46");
        System.addCell(MonteCarlo::Qhull(cellIndex++,tubeAl,0.0,Out+OutTube));

        Out=ModelSupport::getComposite(SMap,monIndex+2000, " 31 -32 34 -14 45 -46");
        System.addCell(MonteCarlo::Qhull(cellIndex++,extTubeHe,0.0,Out+OutTube));

        Out=ModelSupport::getComposite(SMap,monIndex+2000,PW,"11 -12 (-31 : 32) 34 -14 45 -46");
        System.addCell(MonteCarlo::Qhull(cellIndex++,tubeAl,0.0,Out+OutTube));

       Out=ModelSupport::getComposite(SMap,monIndex+2000,PW, " 11 -12 13M -13 35 -36");
       System.addCell(MonteCarlo::Qhull(cellIndex++,0,0.0,Out));

        Out=ModelSupport::getComposite(SMap,monIndex+2000,PW, " 11 -12 -3M 14 35 -36");
        System.addCell(MonteCarlo::Qhull(cellIndex++,extTubeHe,0.0,Out));
      }
     else
       {
        System.addCell(MonteCarlo::Qhull(cellIndex++,matW[i],0.0,Out));
       }

     Out=ModelSupport::getComposite(SMap,monIndex+1000," 1 -2 5 -6 ");

     if(i==nSecW-1) 
       {
	 Out+=ModelSupport::getComposite(SMap,monIndex+2000,PW,"(-1:2:-5:6)-3M 13M ");
       }
     else
       {
     Out+=ModelSupport::getComposite(SMap,PW,"17M -3M 13M ");
       }
     System.addCell(MonteCarlo::Qhull(cellIndex++,0,0.0,Out));

     PW+=10; 
     }
    addOuterSurf(OutTot);

    ///ALB

  return;
}


void
BeamMonitor::createLinks()
  /*!
    Creates a full attachment set
  */
{
  
  return;
}

void
BeamMonitor::createAll(Simulation& System,
		       const attachSystem::FixedComp& FC)
// ,
// 		       const long int linkIndex,
// 		       const attachSystem::ContainedGroup& CG,
// 		       const std::string& CGName)
  /*!
    Global creation of the hutch
    \param System :: Simulation to add vessel to
    \param FC :: Proton beam FixedComp for origin
    \param linkIndex :: link point on FC
    \param CG :: Contained group unit
    \parm CGName :: Contained Group sequence name
  */
{
  ELog::RegMethod RegA("BeamMonitor","createAll");
  populate(System.getDataBase());

  std::string PBeam;

  // createUnitVector(FC,linkIndex);
  createUnitVector(FC);

  createSurfaces();
  // createObjects(System,CG,CGName);
 createObjects(System);
  
 createLinks();
  insertObjects(System); 
  return;
}

}  // NAMESPACE instrumentSystem
