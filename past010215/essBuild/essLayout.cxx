/********************************************************************* 
  CombLayer : MNCPX Input builder
 
 * File:   delft/essLayout.cxx
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
#include "MatrixBase.h"
#include "Matrix.h"
#include "Vec3D.h"
#include "inputParam.h"
#include "Code.h"
#include "varList.h"
#include "FuncDataBase.h"
#include "variableSetup.h"
#include "stringCombine.h"

namespace setVariable
{

  void ESSStandardModel(FuncDataBase&);
  void ESSISISModel(FuncDataBase&);

// void
// ESSISISModel(const mainSystem::inputParam& IParam,
// 	     FuncDataBase& Control)

void
ESSISISModel(FuncDataBase& Control)

  /*!
    \param IParam :: Input param
   */
{
  ELog::RegMethod RegA("essLayout[f]","ESSISISModel");
 
  // const std::string MatName=
  //     IParam.dataCnt("matType") ? IParam.getValue<std::string>("matType") :
  //       "Standard";
  // if (MatName=="ISIS")
  //   {
      //      ISISMaterial(Control);
      ELog::EM<<"ISIS MAT"<<ELog::endWarn;
  Control.addVariable("SegWheelCladShaftMat","Stainless304");
  Control.addVariable("SegWheelCoolingShaftMatInt","Stainless304");
  Control.addVariable("SegWheelCoolingShaftMatExt","Void");

  Control.addVariable("SegWheelWMat","Tungsten");
  Control.addVariable("SegWheelSteelMat","Stainless304");
  Control.addVariable("SegWheelHeMat","helium");

  Control.addVariable("SegWheelInnerMat","Stainless304");


  Control.addVariable("LSupplyMat0","ParaH2");
  Control.addVariable("LSupplyMat1","Aluminium");
  Control.addVariable("LSupplyMat2","Aluminium");
  Control.addVariable("LSupplyMat3","Void");
  Control.addVariable("LSupplyMat4","Aluminium");
  Control.addVariable("LSupplyMat5","Void");
  Control.addVariable("LSupplyMat6","Aluminium");
  Control.addVariable("LSupplyMat7","Void");
  Control.addVariable("LSupplyMat8","Aluminium");


  Control.addVariable("LReturnMat0","ParaH2");
  Control.addVariable("LReturnMat1","Aluminium");
  Control.addVariable("LReturnMat2","Void");
  Control.addVariable("LReturnMat3","Aluminium");
  Control.addVariable("LReturnMat4","Void");
  Control.addVariable("LReturnMat5","Aluminium");
  Control.addVariable("LReturnMat6","Void");
  Control.addVariable("LReturnMat7","Aluminium");

  Control.addVariable("LowModMat","ParaH2");
  Control.addVariable("LowModMat","ParaH2");

  Control.addVariable("LowModMaterial1","Aluminium");  // Al materk
  Control.addVariable("LowModMaterial2","Void"); 
  Control.addVariable("LowModMaterial3","Aluminium"); 
  Control.addVariable("LowModMaterial4","Void"); 
  Control.addVariable("LowModMaterial5","Aluminium"); 
  Control.addVariable("LowModMaterial6","Void"); 

  Control.addVariable("LowModConic1WallMat","Aluminium");
  Control.addVariable("LowModConic2WallMat","Aluminium");
  Control.addVariable("LowModConic3WallMat","Aluminium");
  Control.addVariable("LowModConic4Mat","Void");

  Control.addVariable("LowAFlightLinerMat1","Aluminium");      // Liner
  Control.addVariable("LowAFlightLinerMat2","H2O");      // Liner
  Control.addVariable("LowAFlightLinerMat3","Aluminium");      // Liner
  Control.addVariable("LowAFlightLinerMat4","Void");      // Liner

  Control.addVariable("LowBFlightLinerMat1","Aluminium");      


  Control.addVariable("LowPreMaterial1","Aluminium");  
  Control.addVariable("LowPreMaterial2","H2O");  
  Control.addVariable("LowPreMaterial3","Aluminium");  
  Control.addVariable("LowPreMaterial4","Void"); 

  Control.addVariable("LowPreABlockWallMat","Aluminium");  
  Control.addVariable("LowPreABlockWaterMat","H2O");  

  Control.addVariable("TopPreBBlockWallMat","Aluminium");  
  Control.addVariable("TopPreBBlockWaterMat","H2O");  

  Control.addVariable("TopPreMaterial1","Void");  
  Control.addVariable("TopPreMaterial2","Aluminium");  
  Control.addVariable("TopPreMaterial3","H2O");  
  Control.addVariable("TopPreMaterial4","Aluminium");  
  Control.addVariable("TopPreMaterial5","Void"); 

  Control.addVariable("TopPreABlockWallMat","Aluminium");  
  Control.addVariable("TopPreABlockWaterMat","H2O");  

  Control.addVariable("TopPreBBlockWallMat","Aluminium");  
  Control.addVariable("TopPreBBlockWaterMat","H2O");  

  Control.addVariable("LowPreBBlockWallMat","Aluminium");  
  Control.addVariable("LowPreBBlockWaterMat","H2O");  



  Control.addVariable("TopModMat","ParaH2");
  Control.addVariable("TopModMaterial1","Aluminium");  // Al materk
  Control.addVariable("TopModMaterial2","Void"); 
  Control.addVariable("TopModMaterial3","Aluminium"); 
  Control.addVariable("TopModMaterial4","Void"); 
  Control.addVariable("TopModMaterial5","Aluminium"); 
  Control.addVariable("TopModMaterial6","Void"); 

  Control.addVariable("TopAFlightLinerMat1","Aluminium");      // Liner
  Control.addVariable("TopBFlightLinerMat1","Aluminium");      

  Control.addVariable("ProtonTubeInnerMat1","helium");  // mat : 2000
  Control.addVariable("ProtonTubeWallMat1","CastIron"); // mat : 26316
  Control.addVariable("ProtonTubeInnerMat2","helium");  // mat : 2000
  Control.addVariable("ProtonTubeWallMat2","CastIron"); // mat : 26316
  Control.addVariable("ProtonTubeInnerMat3","helium");   // mat : 2000
  Control.addVariable("ProtonTubeWallMat3","CastIron");  // mat : 26316
  Control.addVariable("ProtonTubeInnerMat4","Void");
  Control.addVariable("ProtonTubeWallMat4","CastIron");  // mat: 26316

  Control.addVariable("BeamMonitorBoxMat1","helium");  // mat:2000
  Control.addVariable("BeamMonitorBoxMat2","CastIron");  // mat: 26000
  Control.addVariable("BeamMonitorBoxMat3","CastIron");  // mat 26316
  Control.addVariable("BeamMonitorBoxMat4","CastIron");  // mat 26316
  Control.addVariable("BeamMonitorBoxMat5","Aluminium");  // mat 13060

  Control.addVariable("BeamMonitorBoxTubeHeMat","helium");
  Control.addVariable("BeamMonitorBoxTubeAlMat","Aluminium");
  Control.addVariable("BeamMonitorBoxExtHeMat","helium");

  Control.addVariable("WheelCladShaftMat","Stainless304");
  Control.addVariable("WheelMainShaftMat","Stainless304");

  Control.addVariable("WheelWMat","Tungsten");
  Control.addVariable("WheelSteelMat","Stainless304");
  Control.addVariable("WheelHeMat","helium");
  Control.addVariable("WheelInnerMat","Stainless304");

  Control.addVariable("BeRefRefMat","Be300K");
  Control.addVariable("BeRefWallMat","Aluminium");
  Control.addVariable("BeRefTargSepMat","Stainless304");

  Control.addVariable("BulkMat1","Void");
  Control.addVariable("BulkMat2","Stainless304");           // stainless
  Control.addVariable("BulkMat3","CastIron");           // Bulk Steel
  Control.addVariable("ShutterBayMat","CastIron");
  Control.addVariable("GuideBayMat","CastIron");

  Control.addVariable("LowConeModWaterMat","H2O");      
  Control.addVariable("LowConeModModMat","ParaH2");            // Liquid H2
  Control.addVariable("LowConeModAlMat","Aluminium");              // Aluminium
  Control.addVariable("LowConeModBWaterMat","H2O");      
  Control.addVariable("LowConeModBModMat","ParaH2");        // Liquid H2
  Control.addVariable("LowConeModBAlMat","Aluminium");       // Aluminium

  // ELog::RegMethod RegA("essVariables[F]","EssBeamLinesVariables");
  for(int i=0;i<4;i++)
    {
      const std::string baseKey=
	StrFunc::makeString("G",i+1)+"BLine";
     Control.addVariable(baseKey+"Mat","CastIron");
 
    }



      // return;
  //   }
  // if (MatName=="Standard")
  //   {
  //     return;
  //   }
  // throw ColErr::InContainerError<std::string>(CoreName,"Mat name unknown");
  return;
}


void
ESSStandardModel(FuncDataBase& Control)

  /*!
    \param IParam :: Input param
   */
{
  return;
}






// void
// ISISMaterial(FuncDataBase& Control)
//   /*!
//     Function to set system for a given form of reactor.
//     \param Control :: Function data base to add constants too
//   */
// {
//   ELog::RegMethod RegA("essLayout[f]","ISISMaterial");

//   Control.addVariable("SegWheelCladShaftMat","Stainless304");
//   Control.addVariable("SegWheelCoolingShaftMatInt","helium");
//   Control.addVariable("SegWheelCoolingShaftMatExt","helium");

//   Control.addVariable("SegWheelWMat","Tungsten");
//   Control.addVariable("SegWheelSteelMat","Stainless304");
//   Control.addVariable("SegWheelHeMat","helium");

//   Control.addVariable("SegWheelInnerMat","Stainless304");

//   Control.addVariable("TopPreABlockWallMat","Aluminium");  
//   Control.addVariable("TopPreABlockWaterMat","H2O");

//   Control.addVariable("TopPreBBlockWallMat","Aluminium");  
//   Control.addVariable("TopPreBBlockWaterMat","H2O");  

  
   
//   return;
// }

} // NAMESPACE setVariable

