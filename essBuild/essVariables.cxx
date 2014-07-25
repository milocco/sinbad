/********************************************************************* 
  CombLayer : MNCPX Input builder
 
 * File:   essBuild/essVariables.cxx
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. 
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
#include <iterator>
#include <boost/array.hpp>
#include <boost/shared_ptr.hpp>

#include "Exception.h"
#include "FileReport.h"
#include "NameStack.h"
#include "RegMethod.h"
#include "GTKreport.h"
#include "OutputLog.h"
#include "support.h"
#include "stringCombine.h"
#include "MatrixBase.h"
#include "Matrix.h"
#include "Vec3D.h"
#include "Code.h"
#include "varList.h"
#include "FuncDataBase.h"
#include "variableSetup.h"

namespace setVariable
{
  void EssBeamLinesVariables(FuncDataBase&);
  void EssConicModerator(FuncDataBase&);
  void ESSWheel(FuncDataBase&);

void
EssWheel(FuncDataBase& Control)
  /*!
    Variables that are used for the segmented wheel
    \param Control :: Segment variables
   */
{



  //////////////////////////////////////////////////////////////////
  // WHEEL AND SHAFT (DETAILED: --targetType SegWheel )
  //////////////////////////////////////////////////////////////////


  //SHAFT
  Control.addVariable("SegWheelShaftNLayers",6);
  Control.addVariable("SegWheelShaftTopHeight",400.0);
  Control.addVariable("SegWheelShaftBaseHeight",-13.5);
  // Control.addVariable("SegWheelShaftHeight",435.0);
  // Control.addVariable("SegWheelShaftRadius",25.0);
  // see WheelInnerRadius below (28cm): it's the external joint radius
  Control.addVariable("SegWheelShaftJointThick",3.0);
  Control.addVariable("SegWheelShaftCoolThick",4.0);
  Control.addVariable("SegWheelShaftCladThick",3.0);
  Control.addVariable("SegWheelShaftVoidThick",1.0);
  Control.addVariable("SegWheelShaftSupportRadius",40.0);
  Control.addVariable("SegWheelShaftSupportThick",2.5);
  Control.addVariable("SegWheelShaftBaseThick",3.0);
  Control.addVariable("SegWheelShaftBaseFootThick",13.5);
  Control.addVariable("SegWheelCladShaftMat","EssSS317");
  Control.addVariable("SegWheelCoolingShaftMatInt","EssHeTarget");
  Control.addVariable("SegWheelCoolingShaftMatExt","EssHeMono");
 
  // TARGET
  Control.addVariable("SegWheelXStep",0.0);  
  Control.addVariable("SegWheelYStep",115.0);  
  Control.addVariable("SegWheelZStep",0.0);
  Control.addVariable("SegWheelXYangle",0.0); 
  Control.addVariable("SegWheelZangle",0.0);
  Control.addVariable("SegWheelTargetHeight",8.0);
  Control.addVariable("SegWheelTargetSectorOffsetX",0.0);  
  Control.addVariable("SegWheelTargetSectorOffsetY",142.6476749356);
  Control.addVariable("SegWheelTargetSectorOffsetZ",0.0);
  Control.addVariable("SegWheelTargetSectorAngleXY",1.1234180949);
  Control.addVariable("SegWheelTargetSectorAngleZ",0.0);
  Control.addVariable("SegWheelTargetSectorApertureXY",2.2468361899);
  Control.addVariable("SegWheelTargetSectorApertureZ",0.0);
  Control.addVariable("SegWheelTargetSectorNumber",33);
  Control.addVariable("SegWheelCoolantThickOut",0.15);
  Control.addVariable("SegWheelCoolantThickIn",0.65);
  Control.addVariable("SegWheelCaseThickZ",0.5);
  Control.addVariable("SegWheelCaseThickX",0.1);
  Control.addVariable("SegWheelVoidThick",2.15);//dist target-ion tube height
  Control.addVariable("SegWheelInnerRadius",28.0);
  Control.addVariable("SegWheelCoolantRadiusOut",124.8);
  Control.addVariable("SegWheelCoolantRadiusIn",114.5);
  Control.addVariable("SegWheelCaseRadius",125.0);
  Control.addVariable("SegWheelVoidRadius",126.0);
  // Material types 1:2:3
  Control.addVariable("SegWheelWMat","EssW");
  Control.addVariable("SegWheelSteelMat","EssSS317");
  Control.addVariable("SegWheelHeMat","EssHeTarget");
  Control.addVariable("SegWheelInnerMat",3);
  Control.addVariable("SegWheelNLayers",25);
  Control.addVariable("SegWheelRadius1",84.27);
  Control.addVariable("SegWheelMatTYPE1",1);
  Control.addVariable("SegWheelRadius2",85.65);
  Control.addVariable("SegWheelMatTYPE2",2);
  Control.addVariable("SegWheelRadius3",97.02);
  Control.addVariable("SegWheelMatTYPE3",3);
  Control.addVariable("SegWheelRadius4",97.52);
  Control.addVariable("SegWheelMatTYPE4",2);
  Control.addVariable("SegWheelRadius5",102.37); 
  Control.addVariable("SegWheelMatTYPE5",3);
  Control.addVariable("SegWheelRadius6",102.77);
  Control.addVariable("SegWheelMatTYPE6",2);
  Control.addVariable("SegWheelRadius7",106.97);
  Control.addVariable("SegWheelMatTYPE7",3);
  Control.addVariable("SegWheelRadius8",107.29);
  Control.addVariable("SegWheelMatTYPE8",2);
  Control.addVariable("SegWheelRadius9",110.49);
  Control.addVariable("SegWheelMatTYPE9",3);
  Control.addVariable("SegWheelRadius10",110.78);
  Control.addVariable("SegWheelMatTYPE10",2); 
  Control.addVariable("SegWheelRadius11",112.78);
  Control.addVariable("SegWheelMatTYPE11",3); 
  Control.addVariable("SegWheelRadius12",113.05);
  Control.addVariable("SegWheelMatTYPE12",2); 
  Control.addVariable("SegWheelRadius13",114.65);
  Control.addVariable("SegWheelMatTYPE13",3); 
  Control.addVariable("SegWheelRadius14",114.9);
  Control.addVariable("SegWheelMatTYPE14",2); 
  Control.addVariable("SegWheelRadius15",116.5);
  Control.addVariable("SegWheelMatTYPE15",3); 
  Control.addVariable("SegWheelRadius16",116.75);
  Control.addVariable("SegWheelMatTYPE16",2); 
  Control.addVariable("SegWheelRadius17",118.35);
  Control.addVariable("SegWheelMatTYPE17",3); 
  Control.addVariable("SegWheelRadius18",118.6);
  Control.addVariable("SegWheelMatTYPE18",2); 
  Control.addVariable("SegWheelRadius19",120.0);
  Control.addVariable("SegWheelMatTYPE19",3); 
  Control.addVariable("SegWheelRadius20",120.25);
  Control.addVariable("SegWheelMatTYPE20",2); 
  Control.addVariable("SegWheelRadius21",121.65);
  Control.addVariable("SegWheelMatTYPE21",3); 
  Control.addVariable("SegWheelRadius22",121.9);
  Control.addVariable("SegWheelMatTYPE22",2); 
  Control.addVariable("SegWheelRadius23",123.1);
  Control.addVariable("SegWheelMatTYPE23",3); 
  Control.addVariable("SegWheelRadius24",123.35);
  Control.addVariable("SegWheelMatTYPE24",2); 
  Control.addVariable("SegWheelRadius25",124.55);
  Control.addVariable("SegWheelMatTYPE25",3); 


  return;

}


void
EssVariables(FuncDataBase& Control)
  /*!
    Function to set the control variables and constants
    -- This version is for ESS ()
    \param Control :: Function data base to add constants too
  */
{
// -----------
// GLOBAL stuff
// -----------

  Control.addVariable("zero",0.0);     // Zero
  Control.addVariable("one",1.0);      // one



  //////////////////////////////////////////////////////////////////
  //  WHEEL AND SHAFT (SIMPLIFIED)
  //////////////////////////////////////////////////////////////////

  //SHAFT
  Control.addVariable("WheelShaftNLayers",3);
  Control.addVariable("WheelShaftHeight",435.0);
  Control.addVariable("WheelShaftRadius",32.0);
  Control.addVariable("WheelShaftCoolThick",1.0);
  Control.addVariable("WheelShaftCladThick",0.5);
  Control.addVariable("WheelShaftVoidThick",0.8);
  Control.addVariable("WheelCladShaftMat","Stainless304");
  Control.addVariable("WheelMainShaftMat","Stainless304");

  //TARGET
  Control.addVariable("WheelXStep",0.0);  
  Control.addVariable("WheelYStep",115.0);  
  Control.addVariable("WheelZStep",0.0);
  Control.addVariable("WheelXYangle",0.0); 
  Control.addVariable("WheelZangle",0.0);
  Control.addVariable("WheelTargetHeight",8.0);
  Control.addVariable("WheelCoolantThick",0.5);
  Control.addVariable("WheelCaseThick",0.5);
  Control.addVariable("WheelVoidThick",1.0);
  Control.addVariable("WheelInnerRadius",82.0);
  Control.addVariable("WheelCoolantRadius",125.0);
  Control.addVariable("WheelCaseRadius",127.0);
  Control.addVariable("WheelVoidRadius",130.0);
  Control.addVariable("WheelWMat","Tungsten");
  Control.addVariable("WheelSteelMat","Stainless304");
  Control.addVariable("WheelHeMat","helium");
  Control.addVariable("WheelInnerMat","Stainless304");
  Control.addVariable("WheelNLayers",28);
  Control.addVariable("WheelRadius1",83.87);
  Control.addVariable("WheelMatTYPE1",1);
  Control.addVariable("WheelRadius2",85.25);
  Control.addVariable("WheelMatTYPE2",2);
  Control.addVariable("WheelRadius3",96.62);
  Control.addVariable("WheelMatTYPE3",3);
  Control.addVariable("WheelRadius4",97.12);
  Control.addVariable("WheelMatTYPE4",2);
  Control.addVariable("WheelRadius5",100.00);    // WRONG
  Control.addVariable("WheelMatTYPE5",3);
  Control.addVariable("WheelRadius6",101.97);
  Control.addVariable("WheelMatTYPE6",2);
  Control.addVariable("WheelRadius7",102.17);
  Control.addVariable("WheelMatTYPE7",1);
  Control.addVariable("WheelRadius8",102.57);
  Control.addVariable("WheelMatTYPE8",2);
  Control.addVariable("WheelRadius9",106.77);
  Control.addVariable("WheelMatTYPE9",3);
  Control.addVariable("WheelRadius10",107.09);
  Control.addVariable("WheelMatTYPE10",2);
  Control.addVariable("WheelRadius11",110.29);
  Control.addVariable("WheelMatTYPE11",3);
  Control.addVariable("WheelRadius12",110.58);
  Control.addVariable("WheelMatTYPE12",2); 
  Control.addVariable("WheelRadius13",112.58);
  Control.addVariable("WheelMatTYPE13",3); 
  Control.addVariable("WheelRadius14",113.3);
  Control.addVariable("WheelMatTYPE14",2); 
  Control.addVariable("WheelRadius15",114.45);
  Control.addVariable("WheelMatTYPE15",3); 
  Control.addVariable("WheelRadius16",114.7);
  Control.addVariable("WheelMatTYPE16",2); 
  Control.addVariable("WheelRadius17",114.9);
  Control.addVariable("WheelMatTYPE17",1); 
  Control.addVariable("WheelRadius18",116.5);
  Control.addVariable("WheelMatTYPE18",3); 
  Control.addVariable("WheelRadius19",116.75);
  Control.addVariable("WheelMatTYPE19",2); 
  Control.addVariable("WheelRadius20",118.35);
  Control.addVariable("WheelMatTYPE20",3); 
  Control.addVariable("WheelRadius21",118.6);
  Control.addVariable("WheelMatTYPE21",2); 
  Control.addVariable("WheelRadius22",120.0);
  Control.addVariable("WheelMatTYPE22",3); 
  Control.addVariable("WheelRadius23",120.25);
  Control.addVariable("WheelMatTYPE23",2); 
  Control.addVariable("WheelRadius24",121.65);
  Control.addVariable("WheelMatTYPE24",3); 
  Control.addVariable("WheelRadius25",121.9);
  Control.addVariable("WheelMatTYPE25",2); 
  Control.addVariable("WheelRadius26",123.1);
  Control.addVariable("WheelMatTYPE26",3); 
  Control.addVariable("WheelRadius27",123.35);
  Control.addVariable("WheelMatTYPE27",2); 
  Control.addVariable("WheelRadius28",124.55);
  Control.addVariable("WheelMatTYPE28",3); 



  ////////////////////////////////////////////////////////////////////
  // TOP MODERATOR
  ///////////////////////////////////////////////////////////////////
 

  Control.addVariable("TopModXStep",0.0);  
  Control.addVariable("TopModYStep",0.0);  
  Control.addVariable("TopModZStep",18.0);
  Control.addVariable("TopModXYangle",57.5); 
  Control.addVariable("TopModZangle",0.0);
  Control.addVariable("TopModRadius",8.0);
  Control.addVariable("TopModHeight",13.0);
  Control.addVariable("TopModMat","EssH2");
  Control.addVariable("TopModTemp",20.0);
  Control.addVariable("TopModNLayers",3); // 3 layers: the mod is included
  Control.addVariable("TopModHGap1",0.3); // al layer
  Control.addVariable("TopModRadGap1",0.3);
  Control.addVariable("TopModMaterial1","EssAl61");
  Control.addVariable("TopModTemp1",20.0);  
  Control.addVariable("TopModHGap2",0.5); // Vac gap
  Control.addVariable("TopModRadGap2",0.5);
  Control.addVariable("TopModMaterial2","Void"); 
  Control.addVariable("TopModTemp2",20.0);    
  Control.addVariable("TopModNConic",0); // flag for no conic mod



  ////////////////////////////////////////////////////////////////////
  //   LOWER MODERATOR
  ////////////////////////////////////////////////////////////////////


  Control.addVariable("LowModXStep",0.0);  
  Control.addVariable("LowModYStep",0.0);  
  Control.addVariable("LowModZStep",-18.0);
  Control.addVariable("LowModXYangle",125.15); 
  Control.addVariable("LowModZangle",0.0);
  Control.addVariable("LowModRadius",8.0);
  Control.addVariable("LowModHeight",13.0);
  Control.addVariable("LowModMat","EssH2");
  Control.addVariable("LowModTemp",20.0);
  Control.addVariable("LowModNLayers",3); // 3 layers: the mod is included
  Control.addVariable("LowModHGap1",0.3); // al layer
  Control.addVariable("LowModRadGap1",0.3);
  Control.addVariable("LowModMaterial1","EssAl61");
  Control.addVariable("LowModTemp1",20.0);  
  Control.addVariable("LowModHGap2",0.5); // Vac gap
  Control.addVariable("LowModRadGap2",0.5);
  Control.addVariable("LowModMaterial2","Void"); 
  Control.addVariable("LowModTemp2",20.0);  

  Control.addVariable("LowModNWedge",0); // because of new CylMod  


  // CONIC LOW MODERATOR (STUART) 
  Control.addVariable("LowModNConic",0);
  Control.addVariable("LowModConic1Cent",Geometry::Vec3D(0,0,1));
  Control.addVariable("LowModConic1Axis",Geometry::Vec3D(0,0,1));
  Control.addVariable("LowModConic1Angle",65.0);
  Control.addVariable("LowModConic1Mat","Void");
  Control.addVariable("LowModConic1WallMat","Aluminium");
  Control.addVariable("LowModConic1Wall",0.2);
  Control.addVariable("LowModConic2Cent",Geometry::Vec3D(0,0,-1));
  Control.addVariable("LowModConic2Axis",Geometry::Vec3D(0,0,-1));
  Control.addVariable("LowModConic2Angle",65.0);
  Control.addVariable("LowModConic2Mat","Void");
  Control.addVariable("LowModConic2WallMat","Aluminium");
  Control.addVariable("LowModConic2Wall",0.2);
  Control.addVariable("LowModConic4Cent",Geometry::Vec3D(-1,0,0));
  Control.addVariable("LowModConic4Axis",Geometry::Vec3D(-1,0,0));
  Control.addVariable("LowModConic4Angle",25.0);
  Control.addVariable("LowModConic4Mat","Void");
  Control.addVariable("LowModConic4WallMat","Aluminium");
  Control.addVariable("LowModConic4Wall",0.2);
  Control.addVariable("LowModConic3Cent",Geometry::Vec3D(1,0,0));
  Control.addVariable("LowModConic3Axis",Geometry::Vec3D(1,0,0));
  Control.addVariable("LowModConic3Angle",25.0);
  Control.addVariable("LowModConic3Mat","Void");
  Control.addVariable("LowModConic3WallMat","Aluminium");
  Control.addVariable("LowModConic3Wall",0.2);



  ////////////////////////////////////////////////////////////////////
  //   TOP PRE-MODERATOR 
  ////////////////////////////////////////////////////////////////////
 

  // OUTER LAYERS 
  Control.addVariable("TopPreNLayers",4); 

  Control.addVariable("TopPreHeight1",0.2);
  Control.addVariable("TopPreDepth1",0.2);
  Control.addVariable("TopPreThick1",0.2);  
  Control.addVariable("TopPreMaterial1","EssAl60"); 
  // Control.addVariable("LowModTemp1",20.0);  
  Control.addVariable("TopPreHeight2",1.0);  
  Control.addVariable("TopPreDepth2",2.0);  
  Control.addVariable("TopPreThick2",1.0);  
  Control.addVariable("TopPreMaterial2","EssH2O");
  Control.addVariable("TopPreHeight3",0.2);  
  Control.addVariable("TopPreDepth3",0.2);  
  Control.addVariable("TopPreThick3",0.2);  
  Control.addVariable("TopPreMaterial3","EssAl60");
  Control.addVariable("TopPreHeight4",0.0);  
  Control.addVariable("TopPreDepth4",2.15);  
  Control.addVariable("TopPreThick4",0.0);  
  Control.addVariable("TopPreMaterial4","EssHeMono");  
 
  // FLIGHTLINE APERTURES
  Control.addVariable("TopPreNView",2);  

  Control.addVariable("TopPreViewHeight1",12.0);  
  Control.addVariable("TopPreViewWidth1",14.2);  
  Control.addVariable("TopPreViewAngle1",2.75);
  Control.addVariable("TopPreViewOpenAngle1",30.0);  

  Control.addVariable("TopPreViewHeight2",12.0);  
  Control.addVariable("TopPreViewWidth2",14.0);  
  Control.addVariable("TopPreViewAngle2",177.25);
  Control.addVariable("TopPreViewOpenAngle2",30.0);  

  // THERMAL BLOCK ADDITIONS
  Control.addVariable("TopPreABlockActive",1);  
  Control.addVariable("TopPreABlockSide",0);  
  Control.addVariable("TopPreABlockWidth",4.0);  
  Control.addVariable("TopPreABlockHeight",18.0);  
  Control.addVariable("TopPreABlockLength",10.4);  
  Control.addVariable("TopPreABlockMat","EssH2O");
  Control.addVariable("TopPreABlockTemp",20);
  Control.addVariable("TopPreABlockNLayers",1);  
  Control.addVariable("TopPreABlockWallThick1",0.2);   
  Control.addVariable("TopPreABlockWallMat1","EssAl60");  
  Control.addVariable("TopPreABlockWallTemp1",20.0);  

  Control.addVariable("TopPreBBlockActive",1);  
  Control.addVariable("TopPreBBlockSide",0);  
  Control.addVariable("TopPreBBlockWidth",4.0); // geometry error block-FL  
  Control.addVariable("TopPreBBlockHeight",18.0);  
  Control.addVariable("TopPreBBlockLength",10.4);  
  Control.addVariable("TopPreBBlockMat","EssH2O");
  Control.addVariable("TopPreBBlockTemp",20);
  Control.addVariable("TopPreBBlockNLayers",1);  
  Control.addVariable("TopPreBBlockWallThick1",0.2);   
  Control.addVariable("TopPreBBlockWallMat1","EssAl60");  
  Control.addVariable("TopPreBBlockWallTemp1",20.0);  



 //////////////////////////////////////////////////////////////////////
 // LOW PREMODERATOR
 //////////////////////////////////////////////////////////////////////


  // OUTER LAYERS
  Control.addVariable("LowPreNLayers",4);  

  Control.addVariable("LowPreHeight1",0.2);  
  Control.addVariable("LowPreDepth1",0.2);  
  Control.addVariable("LowPreThick1",0.2);  
  Control.addVariable("LowPreMaterial1","EssAl60");  
  Control.addVariable("LowPreHeight2",2.0);  
  Control.addVariable("LowPreDepth2",1.0);  
  Control.addVariable("LowPreThick2",1.0);  
  Control.addVariable("LowPreMaterial2","EssH2O");
  Control.addVariable("LowPreHeight3",0.2);  
  Control.addVariable("LowPreDepth3",0.2);  
  Control.addVariable("LowPreThick3",0.2);  
  Control.addVariable("LowPreMaterial3","EssAl60");  
  Control.addVariable("LowPreHeight4",2.15);  
  Control.addVariable("LowPreDepth4",0.0);  
  Control.addVariable("LowPreThick4",0.0);  
  Control.addVariable("LowPreMaterial4","EssHeMono"); 

  // FLIGHTLINE APERTURES
  Control.addVariable("LowPreNView",2);  

  Control.addVariable("LowPreViewHeight1",12.0);  
  Control.addVariable("LowPreViewWidth1",13.8);  
  Control.addVariable("LowPreViewAngle1",0.0);  
  Control.addVariable("LowPreViewOpenAngle1",30.0);  

  Control.addVariable("LowPreViewHeight2",12.0);  
  Control.addVariable("LowPreViewWidth2",13.85);  
  Control.addVariable("LowPreViewAngle2",175.2);  
  Control.addVariable("LowPreViewOpenAngle2",30.0);  

  // THERMAL BLOCK ADDITIONS
  Control.addVariable("LowPreABlockActive",1);  
  Control.addVariable("LowPreABlockSide",0);  
  Control.addVariable("LowPreABlockWidth",4.0);  
  Control.addVariable("LowPreABlockHeight",18.0);  
  Control.addVariable("LowPreABlockLength",10.4);
  Control.addVariable("LowPreABlockMat","EssH2O");  
  Control.addVariable("LowPreABlockTemp",20);
  Control.addVariable("LowPreABlockNLayers",1);  
  Control.addVariable("LowPreABlockWallThick1",0.2);   
  Control.addVariable("LowPreABlockWallMat1","EssAl60");  
  Control.addVariable("LowPreABlockWallTemp1",20.0);  

  Control.addVariable("LowPreBBlockActive",1);  
  Control.addVariable("LowPreBBlockSide",0);  
  Control.addVariable("LowPreBBlockWidth",4.0);  
  Control.addVariable("LowPreBBlockHeight",18.0);  
  Control.addVariable("LowPreBBlockLength",10.4);  
  Control.addVariable("LowPreBBlockMat","EssH2O");  
  Control.addVariable("LowPreBBlockTemp",20);
  Control.addVariable("LowPreBBlockNLayers",1);  
  Control.addVariable("LowPreBBlockWallThick1",0.2);   
  Control.addVariable("LowPreBBlockWallMat1","EssAl60");  
  Control.addVariable("LowPreBBlockWallTemp1",20.0);  



  ////////////////////////////////////////////////////////////////////
  // BE REFLECTOR
  ////////////////////////////////////////////////////////////////////


  Control.addVariable("BeRefXStep",0.0);  
  Control.addVariable("BeRefYStep",0.0);  
  Control.addVariable("BeRefZStep",0.0);
  Control.addVariable("BeRefXYangle",0.0); 
  Control.addVariable("BeRefZangle",0.0);
  Control.addVariable("BeRefRadius",30.0);
  Control.addVariable("BeRefHeight",90.0);
  Control.addVariable("BeRefWallThick",0.0);
  Control.addVariable("BeRefRefMat","EssBe");
  Control.addVariable("BeRefWallMat","Void");
  Control.addVariable("BeRefTargSepThick",12.30);
  Control.addVariable("BeRefTargSepMat","EssSS316");
 


  ////////////////////////////////////////////////////////////////////
  // FE REFLECTOR AND BULK SHIELD
  ////////////////////////////////////////////////////////////////////


  Control.addVariable("BulkXStep",0.0);
  Control.addVariable("BulkYStep",0.0);
  Control.addVariable("BulkZStep",0.0);
  Control.addVariable("BulkXYangle",0.0);
  Control.addVariable("BulkZangle",0.0);
  Control.addVariable("BulkNLayer",3);
  Control.Parse("BeRefRadius+0.0"); //gap layer (here set to null)
  Control.addVariable("BulkRadius1");
  Control.addVariable("BulkHeight1",45.0);
  Control.addVariable("BulkDepth1",45.0);
  Control.addVariable("BulkMat1","Void");

  // FE REFLECTOR
  Control.addVariable("BulkRadius2",65.0);
  Control.addVariable("BulkHeight2",75.0);
  Control.addVariable("BulkDepth2",75.0);
  Control.addVariable("BulkMat2","EssSS316");           // stainless

  // BULK SHIELD
  Control.addVariable("BulkRadius3",200.0);
  Control.addVariable("BulkHeight3",200.0);
  Control.addVariable("BulkDepth3",200.0);
  Control.addVariable("BulkMat3","EssFe");           // Bulk Steel



  ///////////////////////////////////////////////////////////////////////////
  // SHUTTER BAY
  ///////////////////////////////////////////////////////////////////////////


  Control.addVariable("ShutterBayXStep",0.0);  
  Control.addVariable("ShutterBayYStep",0.0);  
  Control.addVariable("ShutterBayZStep",0.0);
  Control.addVariable("ShutterBayXYangle",0.0); 
  Control.addVariable("ShutterBayZangle",0.0);
  Control.addVariable("ShutterBayRadius",600.0);
  Control.addVariable("ShutterBayHeight",400.0);
  Control.addVariable("ShutterBayDepth",400.0);
  Control.addVariable("ShutterBayMat","EssFe");



  ////////////////////////////////////////////////////////////////////////////
  // FLIGHTLINES
  ////////////////////////////////////////////////////////////////////////////

 
  // TOP LEFT
  Control.addVariable("TopAFlightXStep",-6.0);      // Step from centre
  Control.addVariable("TopAFlightZStep",0.0);      // Step from centre
  Control.addVariable("TopAFlightAngleXY1",29.22);  // Angle out
  Control.addVariable("TopAFlightAngleXY2",27.05);  // Angle out
  Control.addVariable("TopAFlightAngleZTop",0.0);  // Step down angle
  Control.addVariable("TopAFlightAngleZBase",0.0); // Step up angle
  Control.addVariable("TopAFlightHeight",12.0);     // Full height
  Control.addVariable("TopAFlightWidth",25.8);     // Full width
  Control.addVariable("TopAFlightNLiner",0);      // Liner (thickn and Matn)

  // TOP RIGHT
  Control.addVariable("TopBFlightXStep",6.0);     // Angle
  Control.addVariable("TopBFlightZStep",0.0);      // Step from centre
  Control.addVariable("TopBFlightAngleXY1",27.0);  // Angle out
  Control.addVariable("TopBFlightAngleXY2",29.25);  // Angle out
  Control.addVariable("TopBFlightAngleZTop",0.0);  // Step down angle
  Control.addVariable("TopBFlightAngleZBase",0.0); // Step up angle
  Control.addVariable("TopBFlightHeight",12.0);     // Full height
  Control.addVariable("TopBFlightWidth",25.6);     // Full width
  Control.addVariable("TopBFlightNLiner",0);      // Liner

  //LOW RIGHT
  Control.addVariable("LowAFlightXStep",-5.3);      // Step from centre
  Control.addVariable("LowAFlightZStep",0.0);      // Step from centre
  Control.addVariable("LowAFlightAngleXY1",26.5);  // Angle out
  Control.addVariable("LowAFlightAngleXY2",29.8);  // Angle out
  Control.addVariable("LowAFlightAngleZTop",0.0);  // Step down angle
  Control.addVariable("LowAFlightAngleZBase",0.0); // Step up angle
  Control.addVariable("LowAFlightHeight",12.0);     // Full height
  Control.addVariable("LowAFlightWidth",25.3);     // Full width
  Control.addVariable("LowAFlightNLiner",0);      // Liner

  //LOW LEFT
  Control.addVariable("LowBFlightXStep",6.55);     // Angle
  Control.addVariable("LowBFlightZStep",0.0);      // Step from centre
  Control.addVariable("LowBFlightMasterXY",0.0);  // Angle out
  Control.addVariable("LowBFlightAngleXY1",24.4);  // Angle out
  Control.addVariable("LowBFlightAngleXY2",32.0);  // Angle out
  Control.addVariable("LowBFlightAngleZTop",0.0);  // Step down angle
  Control.addVariable("LowBFlightAngleZBase",0.0); // Step up angle
  Control.addVariable("LowBFlightHeight",12.0);     // Full height
  Control.addVariable("LowBFlightWidth",25.5);     // Full width
  Control.addVariable("LowBFlightNLiner",0);      // Liner



  ///////////////////////////////////////////////////////////////////////////////////////
  // GUIDE BAY [ All 4 same ]
  ///////////////////////////////////////////////////////////////////////////////////////


  Control.addVariable("GuideBayXStep",0.0);  
  Control.addVariable("GuideBayYStep",0.0);  
  Control.addVariable("GuideBayZStep",0.0);
  Control.addVariable("GuideBayZangle",0.0);
  Control.addVariable("GuideBayViewAngle",65.0); 
  Control.addVariable("GuideBayInnerHeight",11.0);
  Control.addVariable("GuideBayInnerDepth",11.0);
  Control.addVariable("GuideBayMidRadius",170.0);
  Control.addVariable("GuideBayHeight",32.0);
  Control.addVariable("GuideBayDepth",40.0);
  Control.addVariable("GuideBayMat","EssFe");
  Control.addVariable("GuideBay1XYangle",0.0); 
  Control.addVariable("GuideBay2XYangle",175.0); 
  Control.addVariable("GuideBay3XYangle",2.5); 
  Control.addVariable("GuideBay4XYangle",177.5); 
  Control.addVariable("GuideBay1NItems",11);//attenzione  
  Control.addVariable("GuideBay2NItems",12);  
  Control.addVariable("GuideBay3NItems",12);  
  Control.addVariable("GuideBay4NItems",12);  



  ///////////////////////////////////////////////////////////////////////////////////////
  // BEAMLINES
  ///////////////////////////////////////////////////////////////////////////////////////


  for(int i=0;i<4;i++)
    {
      const std::string baseKey=
	StrFunc::makeString("G",i+1)+"BLine";
      // BeamLine in guide bay
      Control.addVariable(baseKey+"XStep",0.0);  
      Control.addVariable(baseKey+"YStep",0.0);  
      Control.addVariable(baseKey+"ZStep",0.0);
      Control.addVariable(baseKey+"Zangle",0.0);
      Control.addVariable(baseKey+"Mat","EssSS316");
      Control.addVariable(baseKey+"BeamXYAngle",0.0); 
      Control.addVariable(baseKey+"BeamZAngle",0.0);
      Control.addVariable(baseKey+"BeamXStep",0.0);
      Control.addVariable(baseKey+"BeamZStep",0.0);
      Control.addVariable(baseKey+"BeamHeight",7.2);
      Control.addVariable(baseKey+"BeamWidth",7.6);
      Control.addVariable(baseKey+"NSegment",3);
      Control.addVariable(baseKey+"Width1",22.0);
      Control.addVariable(baseKey+"Height1",22.0);
      Control.addVariable(baseKey+"Width2",28.0);
      Control.addVariable(baseKey+"Height2",44.0);
      Control.addVariable(baseKey+"Width3",40.0);
      Control.addVariable(baseKey+"Height3",60.0);
      Control.addVariable(baseKey+"Length1",170.0);
      Control.addVariable(baseKey+"Length2",170.0);
      Control.addVariable(baseKey+"1XYangle",27.50); 
      Control.addVariable(baseKey+"2XYangle",22.5); 
      Control.addVariable(baseKey+"3XYangle",17.5); 
      Control.addVariable(baseKey+"4XYangle",12.5); 
      Control.addVariable(baseKey+"5XYangle",7.5); 
      Control.addVariable(baseKey+"6XYangle",2.5); 
      Control.addVariable(baseKey+"7XYangle",-2.5); 
      Control.addVariable(baseKey+"8XYangle",-7.5);
      Control.addVariable(baseKey+"9XYangle",-12.5); 
      Control.addVariable(baseKey+"10XYangle",-17.5); 
      Control.addVariable(baseKey+"11XYangle",-22.5); 
      Control.addVariable(baseKey+"12XYangle",-27.50); 
    }




  ///////////////////////////////////////////////////////////////////////////
  // MODERATOR PIPES (SUPPLY/RETURN THROUGH PREMODERATOR AND REFLECTOR)
  ///////////////////////////////////////////////////////////////////////////


  // TOP MOD SUPPLY
  Control.addVariable("TopModSupplyNSegIn",2);
  Control.addVariable("TopModSupplyPPt0",Geometry::Vec3D(0.0,0.0,0.0));
  Control.addVariable("TopModSupplyPPt1",Geometry::Vec3D(0.0,-19.25,0.0));
  Control.addVariable("TopModSupplyPPt2",Geometry::Vec3D(-64.999,-19.25,0.0085)); // mod xyangle (125.5)+pipe xyangle (57.5)
  Control.addVariable("TopModSupplyNRadii",5);
  Control.addVariable("TopModSupplyRadius0",1.5);
  Control.addVariable("TopModSupplyRadius1",1.7);
  Control.addVariable("TopModSupplyRadius2",1.8);
  Control.addVariable("TopModSupplyRadius3",2.3);
  Control.addVariable("TopModSupplyRadius4",2.5);
  Control.addVariable("TopModSupplyMat0","EssH2");
  Control.addVariable("TopModSupplyMat1","EssAl61");
  Control.addVariable("TopModSupplyMat2","EssAl61");
  Control.addVariable("TopModSupplyMat3","Void");
  Control.addVariable("TopModSupplyMat4","EssAl60");
  Control.addVariable("TopModSupplyTemp0",25.0);
  Control.addVariable("TopModSupplyTemp1",25.0);
  Control.addVariable("TopModSupplyTemp2",25.0);
  Control.addVariable("TopModSupplyTemp3",25.0);
  Control.addVariable("TopModSupplyTemp4",25.0);
  Control.addVariable("TopModSupplyActive0",3);
  Control.addVariable("TopModSupplyActive1",5);
  Control.addVariable("TopModSupplyActive2",29);
  Control.addVariable("TopModSupplyActive3",29);
  Control.addVariable("TopModSupplyActive4",29);
  
  // TOP MOD RETURN
  Control.addVariable("TopModReturnNSegIn",1);
  Control.addVariable("TopModReturnPPt0",Geometry::Vec3D(0.2,-0.2,-5.0));
  Control.addVariable("TopModReturnPPt1",Geometry::Vec3D(0.2,57.0,-5.0));
  Control.addVariable("TopModReturnNRadii",4);
  Control.addVariable("TopModReturnRadius0",1.5);
  Control.addVariable("TopModReturnRadius1",1.8);
  Control.addVariable("TopModReturnRadius2",2.3);
  Control.addVariable("TopModReturnRadius3",2.5);
  Control.addVariable("TopModReturnMat0","EssH2");
  Control.addVariable("TopModReturnMat1","EssAl61");
  Control.addVariable("TopModReturnMat2","Void");
  Control.addVariable("TopModReturnMat3","EssAl60");
  Control.addVariable("TopModReturnTemp0",25.0);
  Control.addVariable("TopModReturnTemp1",25.0);
  Control.addVariable("TopModReturnTemp2",25.0);
  Control.addVariable("TopModReturnTemp3",25.0);
  Control.addVariable("TopModReturnActive0",1);
  Control.addVariable("TopModReturnActive1",3);
  Control.addVariable("TopModReturnActive2",15);

  // LOW MOD SUPPLY
  Control.addVariable("LSupplyNSegIn",2);
  Control.addVariable("LSupplyPPt0",Geometry::Vec3D(0.0,0.0,0.0));
  Control.addVariable("LSupplyPPt1",Geometry::Vec3D(0,-19.25,0.0));
  Control.addVariable("LSupplyPPt2",Geometry::Vec3D(-64.930,-19.25,3.005));
  Control.addVariable("LSupplyNRadii",5);
  Control.addVariable("LSupplyRadius0",1.5);
  Control.addVariable("LSupplyRadius1",1.7);
  Control.addVariable("LSupplyRadius2",1.8);
  Control.addVariable("LSupplyRadius3",2.3);
  Control.addVariable("LSupplyRadius4",2.5);
  Control.addVariable("LSupplyMat0","EssH2");
  Control.addVariable("LSupplyMat1","EssAl61");
  Control.addVariable("LSupplyMat2","EssAl61");
  Control.addVariable("LSupplyMat3","Void");
  Control.addVariable("LSupplyMat4","EssAl60");
  Control.addVariable("LSupplyTemp0",25.0);
  Control.addVariable("LSupplyTemp1",25.0);
  Control.addVariable("LSupplyTemp2",25.0);
  Control.addVariable("LSupplyTemp3",25.0);
  Control.addVariable("LSupplyActive0",3);
  Control.addVariable("LSupplyActive1",5);
  Control.addVariable("LSupplyActive2",29);
  Control.addVariable("LSupplyActive3",29);
  Control.addVariable("LSupplyActive4",29);

  // LOW MOD RETURN
  Control.addVariable("LReturnNSegIn",1);
  Control.addVariable("LReturnPPt0",Geometry::Vec3D(0.2,-0.2,5.0));
  Control.addVariable("LReturnPPt1",Geometry::Vec3D(0.2,57.0,5.0));
  Control.addVariable("LReturnNRadii",4);
  Control.addVariable("LReturnRadius0",1.5);
  Control.addVariable("LReturnRadius1",1.8);
  Control.addVariable("LReturnRadius2",2.3);
  Control.addVariable("LReturnRadius3",2.5);
  Control.addVariable("LReturnMat0","EssH2");
  Control.addVariable("LReturnMat1","EssAl61");
  Control.addVariable("LReturnMat2","Void");
  Control.addVariable("LReturnMat3","EssAl60");
  Control.addVariable("LReturnTemp0",25.0);
  Control.addVariable("LReturnTemp1",25.0);
  Control.addVariable("LReturnTemp2",25.0);
  Control.addVariable("LReturnTemp3",25.0);
  Control.addVariable("LReturnActive0",1);
  Control.addVariable("LReturnActive1",3);
  Control.addVariable("LReturnActive2",15);



  ///////////////////////////////////////////////////////////////////////////
  // PRE-MODERATOR PIPES
  ///////////////////////////////////////////////////////////////////////////


  // TOP A BLOCK SUPPLY
  Control.addVariable("TopPreModASupplyNSegIn",1); 
  Control.addVariable("TopPreModASupplyPPt0",Geometry::Vec3D(2.0,0.0,0.0));
  Control.addVariable("TopPreModASupplyPPt1",Geometry::Vec3D(2.0,48.0,0.0));
  Control.addVariable("TopPreModASupplyNRadii",2);
  Control.addVariable("TopPreModASupplyRadius0",1.5);
  Control.addVariable("TopPreModASupplyRadius1",1.7);
  Control.addVariable("TopPreModASupplyMat0","EssH2O");
  Control.addVariable("TopPreModASupplyMat1","EssAl60");
  Control.addVariable("TopPreModASupplyTemp0",25.0);
  Control.addVariable("TopPreModASupplyTemp1",25.0);
  Control.addVariable("TopPreModASupplyActive0",3);

  // TOP A BLOCK RETURN UP
  Control.addVariable("TopPreModAReturnUpNSegIn",1); 
  Control.addVariable("TopPreModAReturnUpPPt0",Geometry::Vec3D(2.0,0.0,7.5));
  Control.addVariable("TopPreModAReturnUpPPt1",Geometry::Vec3D(2.0,48.0,7.5));
  Control.addVariable("TopPreModAReturnUpNRadii",2);
  Control.addVariable("TopPreModAReturnUpRadius0",1.5);
  Control.addVariable("TopPreModAReturnUpRadius1",1.7);
  Control.addVariable("TopPreModAReturnUpMat0","EssH2O");
  Control.addVariable("TopPreModAReturnUpMat1","EssAl60");
  Control.addVariable("TopPreModAReturnUpTemp0",25.0);
  Control.addVariable("TopPreModAReturnUpTemp1",25.0);
  Control.addVariable("TopPreModAReturnUpActive0",3);

  // TOP A BLOCK RETURN DOWN
  Control.addVariable("TopPreModAReturnDownNSegIn",1); 
  Control.addVariable("TopPreModAReturnDownPPt0",Geometry::Vec3D(2.0,0.0,-7.5));
  Control.addVariable("TopPreModAReturnDownPPt1",Geometry::Vec3D(2.0,48.0,-7.5));
  Control.addVariable("TopPreModAReturnDownNRadii",2);
  Control.addVariable("TopPreModAReturnDownRadius0",1.5);
  Control.addVariable("TopPreModAReturnDownRadius1",1.7);
  Control.addVariable("TopPreModAReturnDownMat0","EssH2O");
  Control.addVariable("TopPreModAReturnDownMat1","EssAl60");
  Control.addVariable("TopPreModAReturnDownTemp0",25.0);
  Control.addVariable("TopPreModAReturnDownTemp1",25.0);
  Control.addVariable("TopPreModAReturnDownActive0",3);

  // TOP B BLOCK SUPPLY
  Control.addVariable("TopPreModBSupplyNSegIn",1); 
  Control.addVariable("TopPreModBSupplyPPt0",Geometry::Vec3D(2.0,0.0,0.0));
  Control.addVariable("TopPreModBSupplyPPt1",Geometry::Vec3D(2.0,48.0,0.0));
  Control.addVariable("TopPreModBSupplyNRadii",2);
  Control.addVariable("TopPreModBSupplyRadius0",1.5);
  Control.addVariable("TopPreModBSupplyRadius1",1.7);
  Control.addVariable("TopPreModBSupplyMat0","EssH2O");
  Control.addVariable("TopPreModBSupplyMat1","EssAl60");
  Control.addVariable("TopPreModBSupplyTemp0",25.0);
  Control.addVariable("TopPreModBSupplyTemp1",25.0);
  Control.addVariable("TopPreModBSupplyActive0",3);

  // TOP B BLOCK RETURN UP
  Control.addVariable("TopPreModBReturnUpNSegIn",1); 
  Control.addVariable("TopPreModBReturnUpPPt0",Geometry::Vec3D(2.0,0.0,7.5));
  Control.addVariable("TopPreModBReturnUpPPt1",Geometry::Vec3D(2.0,48.0,7.5));
  Control.addVariable("TopPreModBReturnUpNRadii",2);
  Control.addVariable("TopPreModBReturnUpRadius0",1.5);
  Control.addVariable("TopPreModBReturnUpRadius1",1.7);
  Control.addVariable("TopPreModBReturnUpMat0","EssH2O");
  Control.addVariable("TopPreModBReturnUpMat1","EssAl60");
  Control.addVariable("TopPreModBReturnUpTemp0",25.0);
  Control.addVariable("TopPreModBReturnUpTemp1",25.0);
  Control.addVariable("TopPreModBReturnUpActive0",3);

  // TOP B BLOCK RETURN DOWN
  Control.addVariable("TopPreModBReturnDownNSegIn",1); 
  Control.addVariable("TopPreModBReturnDownPPt0",Geometry::Vec3D(2.0,0.0,-7.5));
  Control.addVariable("TopPreModBReturnDownPPt1",Geometry::Vec3D(2.0,48.0,-7.5));
  Control.addVariable("TopPreModBReturnDownNRadii",2);
  Control.addVariable("TopPreModBReturnDownRadius0",1.5);
  Control.addVariable("TopPreModBReturnDownRadius1",1.7);
  Control.addVariable("TopPreModBReturnDownMat0","EssH2O");
  Control.addVariable("TopPreModBReturnDownMat1","EssAl60");
  Control.addVariable("TopPreModBReturnDownTemp0",25.0);
  Control.addVariable("TopPreModBReturnDownTemp1",25.0);
  Control.addVariable("TopPreModBReturnDownActive0",3);

  // LOW A BLOCK SUPPLY
  Control.addVariable("LowPreModASupplyNSegIn",1); 
  Control.addVariable("LowPreModASupplyPPt0",Geometry::Vec3D(2.0,0.0,0.0));
  Control.addVariable("LowPreModASupplyPPt1",Geometry::Vec3D(2.0,48.0,0.0));
  Control.addVariable("LowPreModASupplyNRadii",2);
  Control.addVariable("LowPreModASupplyRadius0",1.5);
  Control.addVariable("LowPreModASupplyRadius1",1.7);
  Control.addVariable("LowPreModASupplyMat0","EssH2O");
  Control.addVariable("LowPreModASupplyMat1","EssAl60");
  Control.addVariable("LowPreModASupplyTemp0",25.0);
  Control.addVariable("LowPreModASupplyTemp1",25.0);
  Control.addVariable("LowPreModASupplyActive0",3);

  // LOW A BLOCK RETURN UP
  Control.addVariable("LowPreModAReturnUpNSegIn",1); 
  Control.addVariable("LowPreModAReturnUpPPt0",Geometry::Vec3D(2.0,0.0,7.5));
  Control.addVariable("LowPreModAReturnUpPPt1",Geometry::Vec3D(2.0,48.0,7.5));
  Control.addVariable("LowPreModAReturnUpNRadii",2);
  Control.addVariable("LowPreModAReturnUpRadius0",1.5);
  Control.addVariable("LowPreModAReturnUpRadius1",1.7);
  Control.addVariable("LowPreModAReturnUpMat0","EssH2O");
  Control.addVariable("LowPreModAReturnUpMat1","EssAl60");
  Control.addVariable("LowPreModAReturnUpTemp0",25.0);
  Control.addVariable("LowPreModAReturnUpTemp1",25.0);
  Control.addVariable("LowPreModAReturnUpActive0",3);

  // LOW A BLOCK RETURN DOWN
  Control.addVariable("LowPreModAReturnDownNSegIn",1); 
  Control.addVariable("LowPreModAReturnDownPPt0",Geometry::Vec3D(2.0,0.0,-7.5));
  Control.addVariable("LowPreModAReturnDownPPt1",Geometry::Vec3D(2.0,48.0,-7.5));
  Control.addVariable("LowPreModAReturnDownNRadii",2);
  Control.addVariable("LowPreModAReturnDownRadius0",1.5);
  Control.addVariable("LowPreModAReturnDownRadius1",1.7);
  Control.addVariable("LowPreModAReturnDownMat0","EssH2O");
  Control.addVariable("LowPreModAReturnDownMat1","EssAl60");
  Control.addVariable("LowPreModAReturnDownTemp0",25.0);
  Control.addVariable("LowPreModAReturnDownTemp1",25.0);
  Control.addVariable("LowPreModAReturnDownActive0",3);

  // LOW B BLOCK SUPPLY
  Control.addVariable("LowPreModBSupplyNSegIn",1); 
  Control.addVariable("LowPreModBSupplyPPt0",Geometry::Vec3D(2.0,0.0,0.0));
  Control.addVariable("LowPreModBSupplyPPt1",Geometry::Vec3D(2.0,48.0,0.0));
  Control.addVariable("LowPreModBSupplyNRadii",2);
  Control.addVariable("LowPreModBSupplyRadius0",1.5);
  Control.addVariable("LowPreModBSupplyRadius1",1.7);
  Control.addVariable("LowPreModBSupplyMat0","EssH2O");
  Control.addVariable("LowPreModBSupplyMat1","EssAl60");
  Control.addVariable("LowPreModBSupplyTemp0",25.0);
  Control.addVariable("LowPreModBSupplyTemp1",25.0);
  Control.addVariable("LowPreModBSupplyActive0",3);

  // LOW B BLOCK RETURN UP
  Control.addVariable("LowPreModBReturnUpNSegIn",1); 
  Control.addVariable("LowPreModBReturnUpPPt0",Geometry::Vec3D(2.0,0.0,7.5));
  Control.addVariable("LowPreModBReturnUpPPt1",Geometry::Vec3D(2.0,48.0,7.5));
  Control.addVariable("LowPreModBReturnUpNRadii",2);
  Control.addVariable("LowPreModBReturnUpRadius0",1.5);
  Control.addVariable("LowPreModBReturnUpRadius1",1.7);
  Control.addVariable("LowPreModBReturnUpMat0","EssH2O");
  Control.addVariable("LowPreModBReturnUpMat1","EssAl60");
  Control.addVariable("LowPreModBReturnUpTemp0",25.0);
  Control.addVariable("LowPreModBReturnUpTemp1",25.0);
  Control.addVariable("LowPreModBReturnUpActive0",3);

  // LOW B BLOCK RETURN DOWN
  Control.addVariable("LowPreModBReturnDownNSegIn",1); 
  Control.addVariable("LowPreModBReturnDownPPt0",Geometry::Vec3D(2.0,0.0,-7.5));
  Control.addVariable("LowPreModBReturnDownPPt1",Geometry::Vec3D(2.0,48.0,-7.5));
  Control.addVariable("LowPreModBReturnDownNRadii",2);
  Control.addVariable("LowPreModBReturnDownRadius0",1.5);
  Control.addVariable("LowPreModBReturnDownRadius1",1.7);
  Control.addVariable("LowPreModBReturnDownMat0","EssH2O");
  Control.addVariable("LowPreModBReturnDownMat1","EssAl60");
  Control.addVariable("LowPreModBReturnDownTemp0",25.0);
  Control.addVariable("LowPreModBReturnDownTemp1",25.0);
  Control.addVariable("LowPreModBReturnDownActive0",3);


 
  /////////////////////////////////////////////////////////////
  // PROTON TUBE
  /////////////////////////////////////////////////////////////


  
  Control.addVariable("ProtonTubeXStep",0.0);  
  Control.addVariable("ProtonTubeYStep",87.0); // mod centre (link point is at target inner radius (28 cm, thus: 115-28)  
  Control.addVariable("ProtonTubeZStep",0.0);
  Control.addVariable("ProtonTubeXYangle",0.0); 
  Control.addVariable("ProtonTubeZangle",0.0);

  Control.addVariable("ProtonTubeNSection",4);

  Control.addVariable("ProtonTubeRadius1",11.5);
  Control.addVariable("ProtonTubeLength1",120.0); //from mod centre leftside
  Control.addVariable("ProtonTubeZcut1",5.35); //cut Z planes
  Control.addVariable("ProtonTubeWallThick1",0.0);
  Control.addVariable("ProtonTubeInnerMat1","EssHeMono");  // mat : 2000
  Control.addVariable("ProtonTubeWallMat1","EssSS316"); // mat : 26316

  Control.addVariable("ProtonTubeRadius2",11.5);
  Control.addVariable("ProtonTubeLength2",200.0);
  Control.addVariable("ProtonTubeZcut2",0.0); 
  Control.addVariable("ProtonTubeWallThick2",0.0);
  Control.addVariable("ProtonTubeInnerMat2","EssHeMono");  // mat : 2000
  Control.addVariable("ProtonTubeWallMat2","EssSS316"); // mat : 26316

  Control.addVariable("ProtonTubeRadius3",10.5);
  Control.addVariable("ProtonTubeLength3",127.5);
  Control.addVariable("ProtonTubeZcut3",0.0);
  Control.addVariable("ProtonTubeWallThick3",1.0);
  Control.addVariable("ProtonTubeInnerMat3","EssHeMono");   // mat : 2000
  Control.addVariable("ProtonTubeWallMat3","EssSS316");  // mat : 26316

  Control.addVariable("ProtonTubeRadius4",10.5);
  // Control.addVariable("ProtonTubeLength4",147.5);
  Control.addVariable("ProtonTubeLength4",152.5);
  Control.addVariable("ProtonTubeZcut4",0.0);
  Control.addVariable("ProtonTubeWallThick4",1.0);
  Control.addVariable("ProtonTubeInnerMat4","Void");
  Control.addVariable("ProtonTubeWallMat4","EssSS316");  // mat: 26316


  /////////////////////////////////////////////////////////////
  // BEAM MONITOR
  /////////////////////////////////////////////////////////////


  Control.addVariable("BeamMonitorXStep",0.0);
  Control.addVariable("BeamMonitorYStep",-450.0);
  Control.addVariable("BeamMonitorZStep",0.0);

  //TEMP
  Control.addVariable("BeamMonitorOffsetX",0.0);
  Control.addVariable("BeamMonitorOffsetY",0.0);
  Control.addVariable("BeamMonitorOffsetZ",0.0);


  Control.addVariable("BeamMonitorXYangle",0.0);
  Control.addVariable("BeamMonitorZangle",0.0);
  
  Control.addVariable("BeamMonitorBoxSide",70.0);
  Control.addVariable("BeamMonitorBoxNSections",5); //other are symmetric

  Control.addVariable("BeamMonitorBoxRadius1",11.5);
  Control.addVariable("BeamMonitorBoxThick1",2.5);
  Control.addVariable("BeamMonitorBoxMat1","EssHePBW");  // mat:2000
  Control.addVariable("BeamMonitorBoxRadius2",32.5);
  Control.addVariable("BeamMonitorBoxThick2",10.0);
  Control.addVariable("BeamMonitorBoxMat2","EssFe");  // mat: 26000
  Control.addVariable("BeamMonitorBoxRadius3",20.0);
  Control.addVariable("BeamMonitorBoxThick3",2.5);
  Control.addVariable("BeamMonitorBoxMat3","EssFe");  // mat 26316
  Control.addVariable("BeamMonitorBoxRadius4",17.5);
  Control.addVariable("BeamMonitorBoxThick4",17.5);
  Control.addVariable("BeamMonitorBoxMat4","EssFe");  // mat 26316
  Control.addVariable("BeamMonitorBoxRadius5",25.0);
  Control.addVariable("BeamMonitorBoxThick5",5.0);
  Control.addVariable("BeamMonitorBoxMat5","EssAl60");  // mat 13060

  Control.addVariable("BeamMonitorBoxSide5",50.0);
  Control.addVariable("BeamMonitorBoxHeightA5",14.60);
  Control.addVariable("BeamMonitorBoxHeightB5",8.60);
  Control.addVariable("BeamMonitorBoxHeightC5",7.5);
  Control.addVariable("BeamMonitorBoxHeightD5",7.0);

  Control.addVariable("BeamMonitorBoxWidthA5",21.40);
  Control.addVariable("BeamMonitorBoxWidthB5",20.30);
  Control.addVariable("BeamMonitorBoxWidthC5",19.80);

  Control.addVariable("BeamMonitorBoxThickA5",3.2);
  Control.addVariable("BeamMonitorBoxThickB5",0.5);
  Control.addVariable("BeamMonitorBoxThickC5",0.2);

  Control.addVariable("BeamMonitorBoxTubeN",33);
  Control.addVariable("BeamMonitorBoxTubeRadius",0.27);
  Control.addVariable("BeamMonitorBoxTubeThick",0.03);

  // Control.addVariable("BeamMonitorBoxTubeThick",0.03);
  Control.addVariable("BeamMonitorBoxTubeHeMat","EssHePBW");
  Control.addVariable("BeamMonitorBoxTubeAlMat","EssAl60");
  Control.addVariable("BeamMonitorBoxExtHeMat","EssHePBW");


  Control.addVariable("ProtonBeamViewRadius",4.0);  
 


  /////////////////////////////////////////////////////////////
  // FUSION TEST STATION
  /////////////////////////////////////////////////////////////


  Control.addVariable("fusionTestStationOffsetX",0.0);  
  Control.addVariable("fusionTestStationOffsetY",0.0);  
  Control.addVariable("fusionTestStationOffsetZ",7.0);   
  Control.addVariable("fusionTestStationAngleXY",0.0);
  Control.addVariable("fusionTestStationAngleZ",0.0);
  Control.addVariable("fusionTestStationSampleBlockLength",6.0);
  Control.addVariable("fusionTestStationSampleBlockWidth",6.0);
  Control.addVariable("fusionTestStationSampleBlockHeight",1.0);
  Control.addVariable("fusionTestStationSampleBlockColumns",6.0);
  Control.addVariable("fusionTestStationSampleBlockRows",6.0);
  Control.addVariable("fusionTestStationSampleBlockMaterial","EssFe");
  Control.addVariable("fusionTestStationSampleBlockTemperature",300.0);
  Control.addVariable("fusionTestStationSampleCladdingMaterial","EssSS316");
  Control.addVariable("fusionTestStationSampleCladdingThickness",0.0);
  Control.addVariable("fusionTestStationSampleCladdingTemperature",300.0);
  Control.addVariable("fusionTestStationBaffleMaterial","EssHeTarget");
  Control.addVariable("fusionTestStationBaffleThickness",0.05);
  Control.addVariable("fusionTestStationBaffleTemperature",300.0);
  Control.addVariable("fusionTestStationBaffleCladdingMaterial","EssSS316");
  Control.addVariable("fusionTestStationBaffleCladdingThickness",0.05);
  Control.addVariable("fusionTestStationBaffleCladdingTemperature",300.0);
  Control.addVariable("fusionTestStationCoolingMaterial","EssH2O");
  Control.addVariable("fusionTestStationCoolingThickness",0.1);
  Control.addVariable("fusionTestStationCoolingTemperature",300.0);
  Control.addVariable("fusionTestStationCoolingCladdingMaterial","EssSS316");
  Control.addVariable("fusionTestStationCoolingCladdingThickness",0.05);
  Control.addVariable("fusionTestStationCoolingCladdingTemperature",300.0);



  EssWheel(Control);


  Control.addVariable("sdefEnergy",2000.0);  


  return;
}















































// void
// EssConicModerator(FuncDataBase& Control)
//   /*!
//     Create all the Conic moderator option variables
//     \param Control :: DataBase
//   */
// {
//   ELog::RegMethod RegA("essVariables[F]","EssConicModerator");
  
//   //  Control.addVariable("LowAFlightXStep",0.0);      // Step from centre


//   // CONE MODERATOR
//   Control.addVariable("LowConeModXStep",-0.0);      
//   Control.addVariable("LowConeModYStep",4.0);      
//   Control.addVariable("LowConeModZStep",-18.0);      
//   Control.addVariable("LowConeModXYAngle",125.15);      
//   Control.addVariable("LowConeModZAngle",0.0);      

//   Control.addVariable("LowConeModIWidth",2.0);      
//   Control.addVariable("LowConeModIHeight",2.0);      
//   Control.addVariable("LowConeModOWidth",20.0);      
//   Control.addVariable("LowConeModOHeight",10.0);      
//   Control.addVariable("LowConeModLength",20.0);      
//   Control.addVariable("LowConeModFaceThick",2.0);      
//   Control.addVariable("LowConeModThick",1.5);      

//   Control.addVariable("LowConeModAlThick",0.5);      

//   Control.addVariable("LowConeModVacGap",0.3);      
//   Control.addVariable("LowConeModWaterAlThick",0.5);      
//   Control.addVariable("LowConeModWaterThick",2.0);      
//   Control.addVariable("LowConeModVoidGap",0.3);      
//   Control.addVariable("LowConeModWaterMat","H2O");      

//   Control.addVariable("LowConeModModTemp",20.0);         // Temperature of H2 
//   Control.addVariable("LowConeModModMat","ParaH2");            // Liquid H2
//   Control.addVariable("LowConeModAlMat","Aluminium");              // Aluminium


//   // CONE MODERATOR
//   Control.addVariable("LowConeModBXStep",-0.0);      
//   Control.addVariable("LowConeModBYStep",4.0);      
//   Control.addVariable("LowConeModBZStep",-18.0);      
//   Control.addVariable("LowConeModBXYAngle",125.15-180.0);      
//   Control.addVariable("LowConeModBZAngle",0.0);      

//   Control.addVariable("LowConeModBIWidth",2.0);      
//   Control.addVariable("LowConeModBIHeight",2.0);      
//   Control.addVariable("LowConeModBOWidth",20.0);      
//   Control.addVariable("LowConeModBOHeight",10.0);      
//   Control.addVariable("LowConeModBLength",20.0);      
//   Control.addVariable("LowConeModBFaceThick",2.0);      
//   Control.addVariable("LowConeModBThick",1.5);      

//   Control.addVariable("LowConeModBAlThick",0.5);      

//   Control.addVariable("LowConeModBVacGap",0.3);      
//   Control.addVariable("LowConeModBWaterAlThick",0.5);      
//   Control.addVariable("LowConeModBWaterThick",2.0);      
//   Control.addVariable("LowConeModBVoidGap",0.3);      
//   Control.addVariable("LowConeModBWaterMat","H2O");      

//   Control.addVariable("LowConeModBModTemp",20.0);        // Temp. of H2
//   Control.addVariable("LowConeModBModMat","ParaH2");        // Liquid H2
//   Control.addVariable("LowConeModBAlMat","Aluminium");       // Aluminium

// }











// void
// EssBeamLinesVariables(FuncDataBase& Control)
//   /*!
//     Create all the beamline variabes
//     \param Control :: DataBase
//   */
// {
//   ELog::RegMethod RegA("essVariables[F]","EssBeamLinesVariables");
//   for(int i=0;i<4;i++)
//     {
//       const std::string baseKey=
// 	StrFunc::makeString("G",i+1)+"BLine";
//       // BeamLine in guide bay
//       Control.addVariable(baseKey+"XStep",0.0);  
//       Control.addVariable(baseKey+"YStep",0.0);  
//       Control.addVariable(baseKey+"ZStep",0.0);
//       Control.addVariable(baseKey+"Zangle",0.0);
//       Control.addVariable(baseKey+"Mat","CastIron");
//       Control.addVariable(baseKey+"BeamXYAngle",0.0); 
//       Control.addVariable(baseKey+"BeamZAngle",0.0);
//       Control.addVariable(baseKey+"BeamXStep",0.0);
//       Control.addVariable(baseKey+"BeamZStep",0.0);
//       Control.addVariable(baseKey+"BeamHeight",7.2);
//       Control.addVariable(baseKey+"BeamWidth",7.6);
//       Control.addVariable(baseKey+"NSegment",3);
//       Control.addVariable(baseKey+"Width1",22.0);
//       Control.addVariable(baseKey+"Height1",22.0);
//       Control.addVariable(baseKey+"Width2",28.0);
//       Control.addVariable(baseKey+"Height2",44.0);
//       Control.addVariable(baseKey+"Width3",40.0);
//       Control.addVariable(baseKey+"Height3",60.0);
//       Control.addVariable(baseKey+"Length1",170.0);
//       Control.addVariable(baseKey+"Length2",170.0);
//       Control.addVariable(baseKey+"1XYangle",27.50); 
//       Control.addVariable(baseKey+"2XYangle",22.5); 
//       Control.addVariable(baseKey+"3XYangle",17.5); 
//       Control.addVariable(baseKey+"4XYangle",12.5); 
//       Control.addVariable(baseKey+"5XYangle",7.5); 
//       Control.addVariable(baseKey+"6XYangle",2.5); 
//       Control.addVariable(baseKey+"7XYangle",-2.5); 
//       Control.addVariable(baseKey+"8XYangle",-7.5);
//       Control.addVariable(baseKey+"9XYangle",-12.5); 
//       Control.addVariable(baseKey+"10XYangle",-17.5); 
//       Control.addVariable(baseKey+"11XYangle",-22.5); 
//       Control.addVariable(baseKey+"12XYangle",-27.50); 
//     }
//   return;
// }

}  // NAMESPACE setVariable
