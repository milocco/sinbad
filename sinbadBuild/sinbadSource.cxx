 /********************************************************************* 
  CombLayer : MNCPX Input builder
 
 * File:   source/sinbadSource.cxx
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
// #include <fstream>
// #include <iomanip>
// #include <iostream>
// #include <sstream>
// #include <cmath>
// #include <complex>
// #include <list>
// #include <vector>
// #include <set>
// #include <map>
// #include <string>
// #include <algorithm>
// #include <boost/shared_ptr.hpp>
// #include <boost/array.hpp>

// #include "Exception.h"
// #include "FileReport.h"
// #include "GTKreport.h"
// #include "NameStack.h"
// #include "RegMethod.h"
// #include "OutputLog.h"
// #include "BaseVisit.h"
// #include "BaseModVisit.h"
// #include "support.h"
// #include "stringCombine.h"
// #include "MatrixBase.h"
// #include "Matrix.h"
// #include "Vec3D.h"
// #include "Quaternion.h"
// #include "doubleErr.h"
// #include "Triple.h"
// #include "NRange.h"
// #include "NList.h"
// #include "varList.h"
// #include "Code.h"
// #include "FuncDataBase.h"
// #include "KCode.h"
// #include "Source.h"
// #include "SrcItem.h"
// #include "SrcData.h"
// #include "surfRegister.h"
// #include "HeadRule.h"
// #include "LinkUnit.h"
// #include "FixedComp.h"
// #include "LinearComp.h"
// #include "SecondTrack.h"
// #include "inputParam.h"
// #include "PhysCard.h"
// #include "LSwitchCard.h"
// #include "ModeCard.h"
// #include "PhysImp.h"
// #include "PhysicsCards.h"
// #include "Simulation.h"
// #include "SourceCreate.h"
// #include "localRotate.h"
// #include "masterRotate.h"
// #include "objectRegister.h"
// #include "ChipIRSource.h"


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
#include <functional>
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
#include "ManagedPtr.h"
#include "mathSupport.h"
#include "support.h"
#include "MatrixBase.h"
#include "Matrix.h"
#include "Vec3D.h"
#include "Code.h"
#include "varList.h"
#include "MaterialSupport.h"
#include "stringCombine.h"
#include "FuncDataBase.h"
#include "SrcData.h"
#include "SrcItem.h"
#include "DSTerm.h"
#include "Source.h"
#include "inputParam.h"
#include "PhysCard.h"
#include "LSwitchCard.h"
#include "ModeCard.h"
#include "PhysImp.h"
#include "Simulation.h"
// #include "PhysicsCards.h"
// #include "NList.h"
// #include "NRange.h"
#include "varList.h"
#include "Code.h"
#include "FuncDataBase.h"
#include "KCode.h"

#include "stringCombine.h"


#include "sinbadSource.h"


namespace SDef
{

// void 
// setSinbadSource(Simulation& System,
// 		const mainSystem::inputParam& IParam)
//   /*!
//     Build the source based on the input parameter table
//     \param System :: Simulation to use
//     \param IParam :: Input parameter
//   */
// {
//   ELog::RegMethod RegA("SourceSelector","sourceSelection");
//   const FuncDataBase& Control=System.getDataBase();
//   SDef::Source& sourceCard=System.getPC().getSDefCard();
//   const masterRotate& MR = masterRotate::Instance();
//   ModelSupport::objectRegister& OR=
//     ModelSupport::objectRegister::Instance();

//     const std::string expN=IParam.getValue<std::string>("preName");
//    SDef::SinbadSource(Control,sourceCard,expN);
//   return;
// }



void
SinbadSource(const FuncDataBase& Control,Source& sourceCard,const std::string& expN)
  /*!
    Create a fisson source for a cylinder/rectangular unit 
    \param Control :: Funcdat data base for values
    \param sourceCard :: Source system
  */
{  
  ELog::RegMethod RegA("SinbadSource","createSinbadSource");
  sourceCard.clear();

  const size_t NX=Control.EvalVar<size_t>(expN+"FissionPlateNXSpace");
  const size_t NZ=Control.EvalVar<size_t>(expN+"FissionPlateNZSpace");

  double PT;
  std::vector<double> Xpt;
  std::vector<double> Zpt;
  std::vector<std::vector<double> > Ypt;  

  for(size_t i=0;i<NX;i++)
    {
      PT=Control.EvalVar<double>
	(StrFunc::makeString(expN+"FissionPlateXPt",i));
      Xpt.push_back(PT);
    }

  for(size_t i=0;i<NZ;i++)
    {
      PT=Control.EvalVar<double>
	(StrFunc::makeString(expN+"FissionPlateZPt",i));
      Zpt.push_back(PT);
    }

  for(size_t ix=0;ix<NX-1;ix++)
    {
     std::vector<double> YPtsRow;
     std::string SX=StrFunc::makeString("49SourceX",ix);
     for(size_t iz=0;iz<NZ-1;iz++)
     {
      std::string SXZ=StrFunc::makeString(SX+"Z",iz);	
      PT=Control.EvalVar<double>(SXZ);
      YPtsRow.push_back(PT);
     }
     Ypt.push_back(YPtsRow);
   }

// 640 energy group structure
 
  const double XBase[]=  
    { 1.000000,  1.100000, 
      1.200000,   1.300000,  1.400000, 
      1.500000,   1.600000,  1.700000,   
      1.800000,   1.900000,  2.000000, 
      2.100000,   2.200000,  2.300000,
      2.400000,   2.500000,  2.600000,
      2.700000,   2.800000,  2.900000,
      3.000000,   3.100000,  3.200000,
      3.300000,   3.400000,  3.500000,
      3.600000,   3.700000,  3.800000,
      3.900000,   4.000000,  4.100000,   
      4.200000,   4.300000,  4.400000, 
      4.500000,   4.600000,  4.700000,
      4.800000,   4.900000,  5.000000 , 
      5.100000,   5.200000 , 5.300000 , 
      5.400000,   5.500000 , 5.600000 , 
      5.700000,   5.800000 , 5.900000 , 
      6.000000,   6.100000 , 6.200000 ,   
      6.300000,   6.400000 , 6.500000 ,
      6.600000,   6.700000 , 6.800000 , 
      6.900000,   7.000000 , 7.100000 , 
      7.200000,   7.300000 , 7.400000 , 
      7.500000,   7.600000 , 7.700000 , 
      7.800000,   7.900000 , 8.000000 , 
      8.100000,   8.200000 , 8.300000 , 
      8.400000,   8.500000 , 8.600000 , 
      8.700000,   8.800000 , 8.900000 , 
      9.000000,   9.100000 , 9.200000 , 
      9.300000,   9.400000 , 9.500000 , 
      9.600000,   9.700000 , 9.800000 , 
      9.900000,   10.0000000};

  const double XTop[]={
      1.020000E+1 , 
      1.040000E+1,  1.060000E+1 ,   1.080000E+1 , 
      1.100000E+1,  1.120000E+1 ,   1.140000E+1 , 
      1.160000E+1,  1.180000E+1 ,   1.200000E+1 , 
      1.220000E+1,  1.240000E+1 ,   1.260000E+1 , 
      1.280000E+1,  1.300000E+1 ,   1.320000E+1 , 
      1.340000E+1,  1.360000E+1 ,   1.380000E+1 , 
      1.400000E+1,  1.420000E+1 ,   1.440000E+1 , 
      1.460000E+1,  1.480000E+1 ,   1.500000E+1 , 
      1.520000E+1,  1.540000E+1 ,   1.560000E+1 , 
      1.580000E+1,  1.600000E+1 ,   1.620000E+1 , 
      1.640000E+1,  1.660000E+1 ,   1.680000E+1 , 
      1.700000E+1,  1.720000E+1 ,   1.740000E+1 , 
      1.760000E+1,  1.780000E+1 ,   1.800000E+1 , 
      1.820000E+1,  1.840000E+1 ,   1.860000E+1 , 
      1.880000E+1,  1.900000E+1 ,   1.920000E+1 , 
      1.940000E+1,  1.960000E+1 ,   1.980000E+1 , 
      2.000000E+1,  2.020000E+1 ,   2.040000E+1 , 
      2.060000E+1,  2.080000E+1 ,   2.100000E+1 , 
      2.120000E+1,  2.140000E+1 ,   2.160000E+1 , 
      2.180000E+1,  2.200000E+1 ,   2.220000E+1 , 
      2.240000E+1,  2.260000E+1 ,   2.280000E+1 , 
      2.300000E+1,  2.320000E+1 ,   2.340000E+1 , 
      2.360000E+1,  2.380000E+1 ,   2.400000E+1 , 
      2.420000E+1,  2.440000E+1 ,   2.460000E+1 , 
      2.480000E+1,  2.500000E+1 ,   2.520000E+1 , 
      2.540000E+1,  2.560000E+1 ,   2.580000E+1 , 
      2.600000E+1,  2.620000E+1 ,   2.640000E+1 , 
      2.660000E+1,  2.680000E+1 ,   2.700000E+1 , 
      2.720000E+1,  2.740000E+1 ,   2.760000E+1 , 
      2.780000E+1,  2.800000E+1 ,   2.820000E+1 , 
      2.840000E+1,  2.860000E+1 ,   2.880000E+1 , 
      2.900000E+1,  2.920000E+1 ,   2.940000E+1 , 
      2.960000E+1,  2.980000E+1 ,   3.000000E+1 , 
      3.100000E+1   } ;

  std::vector<double> Xerg7;
  Xerg7.push_back(0.0);
  const size_t XBaseSize=sizeof(XBase)/sizeof(double);

  double scaleFactor(1e-5);
  for(size_t i=0;i<5;i++)
    {
      for(size_t j=0;j<XBaseSize;j++)
	Xerg7.push_back(XBase[j]*scaleFactor);
      scaleFactor*=10.0;
    }


  const size_t XTopSize=sizeof(XTop)/sizeof(double);
  for(size_t j=0;j<XTopSize;j++)
    Xerg7.push_back(XTop[j]);
 
  // U-235 fission spectrum from ENDF/B-VII.1
                   
  double Yerg7[]     =
       { 0.000000E+0 ,  1.850569E-9 ,  1.940894E-9  ,
         2.027196E-9 ,  2.109973E-9 ,  2.189621E-9  ,
         2.266473E-9 ,  2.340803E-9 ,  2.412844E-9  ,
         2.482795E-9 ,  2.550829E-9 ,  2.617094E-9  ,
         2.681723E-9 ,  2.744830E-9 ,  2.806519E-9  ,
         2.866880E-9 ,  2.925996E-9 ,  2.983942E-9  ,
         3.040783E-9 ,  3.096582E-9 ,  3.151392E-9  ,
         3.205264E-9 ,  3.258247E-9 ,  3.310381E-9  ,
         3.361708E-9 ,  3.412261E-9 ,  3.462077E-9  ,
         3.511186E-9 ,  3.559617E-9 ,  3.607400E-9  ,
         3.654556E-9 ,  3.701112E-9 ,  3.747089E-9  ,
         3.792509E-9 ,  3.837391E-9 ,  3.881754E-9  ,
         3.925616E-9 ,  3.968994E-9 ,  4.011902E-9  ,
         4.054356E-9 ,  4.096371E-9 ,  4.137958E-9  ,
         4.179131E-9 ,  4.219903E-9 ,  4.260285E-9  ,
         4.300288E-9 ,  4.339921E-9 ,  4.379197E-9  ,
         4.418123E-9 ,  4.456708E-9 ,  4.494963E-9  ,
         4.532894E-9 ,  4.570511E-9 ,  4.607821E-9  ,
         4.644831E-9 ,  4.681548E-9 ,  4.717980E-9  ,
         4.754132E-9 ,  4.790012E-9 ,  4.825625E-9  ,
         4.860977E-9 ,  4.896073E-9 ,  4.930920E-9  ,
         4.965522E-9 ,  4.999885E-9 ,  5.034012E-9  ,
         5.067911E-9 ,  5.101584E-9 ,  5.135036E-9  ,
         5.168271E-9 ,  5.201295E-9 ,  5.234109E-9  ,
         5.266719E-9 ,  5.299129E-9 ,  5.331342E-9  ,
         5.363361E-9 ,  5.395190E-9 ,  5.426832E-9  ,
         5.458290E-9 ,  5.489569E-9 ,  5.520670E-9  ,
         5.551597E-9 ,  5.582353E-9 ,  5.612940E-9  ,
         5.643361E-9 ,  5.673619E-9 ,  5.703717E-9  ,
         5.733656E-9 ,  5.763440E-9 ,  5.793071E-9  ,
         5.822551E-9 ,  5.851882E-9 ,  6.137490E-9  ,
         6.410384E-9 ,  6.672121E-9 ,  6.923971E-9  ,
         7.166972E-9 ,  7.401998E-9 ,  7.629785E-9  ,
         7.850964E-9 ,  8.066079E-9 ,  8.275601E-9  ,
         8.479947E-9 ,  8.679481E-9 ,  8.874527E-9  ,
         9.065376E-9 ,  9.252286E-9 ,  9.435494E-9  ,
         9.615210E-9 ,  9.791625E-9 ,  9.964917E-9  ,
         1.013525E-8 ,  1.030276E-8 ,  1.046758E-8  ,
         1.062985E-8 ,  1.078968E-8 ,  1.094717E-8  ,
         1.110243E-8 ,  1.125555E-8 ,  1.140661E-8  ,
         1.155569E-8 ,  1.170287E-8 ,  1.184822E-8  ,
         1.199181E-8 ,  1.213370E-8 ,  1.227395E-8  ,
         1.241261E-8 ,  1.254974E-8 ,  1.268539E-8  ,
         1.281960E-8 ,  1.295241E-8 ,  1.308388E-8  ,
         1.321404E-8 ,  1.334292E-8 ,  1.347057E-8  ,
         1.359703E-8 ,  1.372231E-8 ,  1.384647E-8  ,
         1.396952E-8 ,  1.409149E-8 ,  1.421240E-8  ,
         1.433231E-8 ,  1.445121E-8 ,  1.456915E-8  ,
         1.468614E-8 ,  1.480219E-8 ,  1.491735E-8  ,
         1.503162E-8 ,  1.514504E-8 ,  1.525759E-8  ,
         1.536934E-8 ,  1.548027E-8 ,  1.559041E-8  ,
         1.569977E-8 ,  1.580839E-8 ,  1.591626E-8  ,
         1.602340E-8 ,  1.612982E-8 ,  1.623555E-8  ,
         1.634060E-8 ,  1.644498E-8 ,  1.654868E-8  ,
         1.665175E-8 ,  1.675418E-8 ,  1.685598E-8  ,
         1.695718E-8 ,  1.705778E-8 ,  1.715777E-8  ,
         1.725720E-8 ,  1.735606E-8 ,  1.745434E-8  ,
         1.755208E-8 ,  1.764928E-8 ,  1.774594E-8  ,
         1.784208E-8 ,  1.793771E-8 ,  1.803282E-8  ,
         1.812744E-8 ,  1.822156E-8 ,  1.831520E-8  ,
         1.840836E-8 ,  1.850104E-8 ,  1.940357E-8  ,
         2.026585E-8 ,  2.109283E-8 ,  2.188850E-8  ,
         2.265618E-8 ,  2.339860E-8 ,  2.411811E-8  ,
         2.481669E-8 ,  2.549608E-8 ,  2.615775E-8  ,
         2.680303E-8 ,  2.743307E-8 ,  2.804890E-8  ,
         2.865144E-8 ,  2.924150E-8 ,  2.981983E-8  ,
         3.038710E-8 ,  3.094391E-8 ,  3.149083E-8  ,
         3.202834E-8 ,  3.255693E-8 ,  3.307702E-8  ,
         3.358901E-8 ,  3.409326E-8 ,  3.459011E-8  ,
         3.507987E-8 ,  3.556283E-8 ,  3.603927E-8  ,
         3.650946E-8 ,  3.697361E-8 ,  3.743196E-8  ,
         3.788472E-8 ,  3.833208E-8 ,  3.877424E-8  ,
         3.921136E-8 ,  3.964363E-8 ,  4.007118E-8  ,
         4.049418E-8 ,  4.091275E-8 ,  4.132705E-8  ,
         4.173720E-8 ,  4.214331E-8 ,  4.254551E-8  ,
         4.294388E-8 ,  4.333857E-8 ,  4.372965E-8  ,
         4.411721E-8 ,  4.450137E-8 ,  4.488219E-8  ,
         4.525978E-8 ,  4.563419E-8 ,  4.600553E-8  ,
         4.637385E-8 ,  4.673924E-8 ,  4.710174E-8  ,
         4.746145E-8 ,  4.781841E-8 ,  4.817269E-8  ,
         4.852434E-8 ,  4.887342E-8 ,  4.922000E-8  ,
         4.956412E-8 ,  4.990582E-8 ,  5.024517E-8  ,
         5.058221E-8 ,  5.091697E-8 ,  5.124953E-8  ,
         5.157989E-8 ,  5.190812E-8 ,  5.223425E-8  ,
         5.255833E-8 ,  5.288039E-8 ,  5.320046E-8  ,
         5.351858E-8 ,  5.383479E-8 ,  5.414912E-8  ,
         5.446161E-8 ,  5.477227E-8 ,  5.508117E-8  ,
         5.538829E-8 ,  5.569369E-8 ,  5.599740E-8  ,
         5.629943E-8 ,  5.659982E-8 ,  5.689859E-8  ,
         5.719577E-8 ,  5.749139E-8 ,  5.778546E-8  ,
         5.807801E-8 ,  5.836906E-8 ,  6.120187E-8  ,
         6.390639E-8 ,  6.649828E-8 ,  6.899021E-8  ,
         7.139264E-8 ,  7.371432E-8 ,  7.596264E-8  ,
         7.814394E-8 ,  8.026365E-8 ,  8.232654E-8  ,
         8.433676E-8 ,  8.629799E-8 ,  8.821349E-8  ,
         9.008618E-8 ,  9.191865E-8 ,  9.371326E-8  ,
         9.547215E-8 ,  9.719724E-8 ,  9.889030E-8  ,
         1.005529E-7 ,  1.021866E-7 ,  1.037927E-7  ,
         1.053725E-7 ,  1.069272E-7 ,  1.084578E-7  ,
         1.099652E-7 ,  1.114505E-7 ,  1.129146E-7  ,
         1.143581E-7 ,  1.157820E-7 ,  1.171867E-7  ,
         1.185733E-7 ,  1.199421E-7 ,  1.212938E-7  ,
         1.226290E-7 ,  1.239482E-7 ,  1.252519E-7  ,
         1.265405E-7 ,  1.278146E-7 ,  1.290745E-7  ,
         1.303205E-7 ,  1.315533E-7 ,  1.327731E-7  ,
         1.339802E-7 ,  1.351751E-7 ,  1.363579E-7  ,
         1.375290E-7 ,  1.386888E-7 ,  1.398375E-7  ,
         1.409754E-7 ,  1.421026E-7 ,  1.432195E-7  ,
         1.443263E-7 ,  1.454233E-7 ,  1.465105E-7  ,
         1.475884E-7 ,  1.486570E-7 ,  1.497166E-7  ,
         1.507673E-7 ,  1.518093E-7 ,  1.528429E-7  ,
         1.538680E-7 ,  1.548850E-7 ,  1.558941E-7  ,
         1.568951E-7 ,  1.578886E-7 ,  1.588745E-7  ,
         1.598528E-7 ,  1.608240E-7 ,  1.617879E-7  ,
         1.627447E-7 ,  1.636947E-7 ,  1.646379E-7  ,
         1.655743E-7 ,  1.665042E-7 ,  1.674276E-7  ,
         1.683445E-7 ,  1.692553E-7 ,  1.701598E-7  ,
         1.710583E-7 ,  1.719508E-7 ,  1.728373E-7  ,
         1.737182E-7 ,  1.745931E-7 ,  1.754626E-7  ,
         1.763265E-7 ,  1.771848E-7 ,  1.780378E-7  ,
         1.788853E-7 ,  1.797277E-7 ,  1.878767E-7  ,
         1.955684E-7 ,  2.028536E-7 ,  2.097738E-7  ,
         2.163633E-7 ,  2.226501E-7 ,  2.286576E-7  ,
         2.344065E-7 ,  2.399146E-7 ,  2.451976E-7  ,
         2.502693E-7 ,  2.551414E-7 ,  2.598248E-7  ,
         2.643292E-7 ,  2.686635E-7 ,  2.728355E-7  ,
         2.768522E-7 ,  2.807201E-7 ,  2.844444E-7  ,
         2.880290E-7 ,  2.914800E-7 ,  2.948012E-7  ,
         2.979947E-7 ,  3.010642E-7 ,  3.040154E-7  ,
         3.068522E-7 ,  3.095810E-7 ,  3.122060E-7  ,
         3.147276E-7 ,  3.171490E-7 ,  3.194710E-7  ,
         3.216904E-7 ,  3.238020E-7 ,  3.258003E-7  ,
         3.276796E-7 ,  3.294435E-7 ,  3.311039E-7  ,
         3.326695E-7 ,  3.341500E-7 ,  3.355530E-7  ,
         3.368817E-7 ,  3.381350E-7 ,  3.393089E-7  ,
         3.403998E-7 ,  3.414036E-7 ,  3.423157E-7  ,
         3.431423E-7 ,  3.438922E-7 ,  3.445729E-7  ,
         3.451919E-7 ,  3.457555E-7 ,  3.462689E-7  ,
         3.467341E-7 ,  3.471537E-7 ,  3.475310E-7  ,
         3.478668E-7 ,  3.481599E-7 ,  3.484092E-7  ,
         3.486161E-7 ,  3.487823E-7 ,  3.489091E-7  ,
         3.489987E-7 ,  3.490531E-7 ,  3.490737E-7  ,
         3.490615E-7 ,  3.490170E-7 ,  3.489408E-7  ,
         3.488347E-7 ,  3.487002E-7 ,  3.485388E-7  ,
         3.483514E-7 ,  3.481389E-7 ,  3.479022E-7  ,
         3.476420E-7 ,  3.473592E-7 ,  3.470544E-7  ,
         3.467281E-7 ,  3.463811E-7 ,  3.460147E-7  ,
         3.456295E-7 ,  3.452265E-7 ,  3.448058E-7  ,
         3.443675E-7 ,  3.439118E-7 ,  3.434397E-7  ,
         3.429511E-7 ,  3.424460E-7 ,  3.419244E-7  ,
         3.413862E-7 ,  3.408314E-7 ,  3.344139E-7  ,
         3.266933E-7 ,  3.181551E-7 ,  3.089767E-7  ,
         2.992498E-7 ,  2.890636E-7 ,  2.784857E-7  ,
         2.675919E-7 ,  2.564713E-7 ,  2.452123E-7  ,
         2.339058E-7 ,  2.226394E-7 ,  2.114964E-7  ,
         2.005485E-7 ,  1.898564E-7 ,  1.794722E-7  ,
         1.694365E-7 ,  1.597780E-7 ,  1.505184E-7  ,
         1.416708E-7 ,  1.332408E-7 ,  1.252289E-7  ,
         1.176305E-7 ,  1.104378E-7 ,  1.036396E-7  ,
         9.722309E-8 ,  9.117350E-8 ,  8.547540E-8  ,
         8.011238E-8 ,  7.506803E-8 ,  7.032591E-8  ,
         6.586982E-8 ,  6.168401E-8 ,  5.775315E-8  ,
         5.406242E-8 ,  5.059781E-8 ,  4.734590E-8  ,
         4.429392E-8 ,  4.142990E-8 ,  3.874255E-8  ,
         3.622122E-8 ,  3.385584E-8 ,  3.163705E-8  ,
         2.955604E-8 ,  2.760456E-8 ,  2.577490E-8  ,
         2.405981E-8 ,  2.245245E-8 ,  2.094643E-8  ,
         1.953575E-8 ,  1.821478E-8 ,  1.697819E-8  ,
         1.582102E-8 ,  1.473855E-8 ,  1.372630E-8  ,
         1.278008E-8 ,  1.189593E-8 ,  1.107009E-8  ,
         1.029902E-8 ,  9.579367E-9 ,  8.907964E-9  ,
         8.281814E-9 ,  7.698076E-9 ,  7.154075E-9  ,
         6.647284E-9 ,  6.175315E-9 ,  5.735914E-9  ,
         5.326960E-9 ,  4.946457E-9 ,  4.592522E-9  ,
         4.263383E-9 ,  3.957381E-9 ,  3.672953E-9  ,
         3.408633E-9 ,  3.163043E-9 ,  2.934899E-9  ,
         2.722996E-9 ,  2.526204E-9 ,  2.343472E-9  ,
         2.173816E-9 ,  2.016320E-9 ,  1.870126E-9  ,
         1.734434E-9 ,  1.608503E-9 ,  1.491638E-9  ,
         1.383194E-9 ,  1.282571E-9 ,  1.189211E-9  ,
         1.102593E-9 ,  1.022235E-9 ,  8.78187E-10  ,
         7.54438E-10 ,  6.48127E-10 ,  5.56796E-10  ,
         4.78336E-10 ,  4.10482E-10 ,  3.52254E-10  ,
         3.02286E-10 ,  2.59406E-10 ,  2.22609E-10  ,
         1.90782E-10 ,  1.63506E-10 ,  1.40129E-10  ,
         1.20095E-10 ,  1.02925E-10 ,  8.81159E-11  ,
         7.54377E-11 ,  6.45835E-11 ,  5.52911E-11  ,
         4.73358E-11 ,  4.04774E-11 ,  3.46128E-11  ,
         2.95978E-11 ,  2.53095E-11 ,  2.16425E-11  ,
         1.84867E-11 ,  1.57910E-11 ,  1.34884E-11  ,
         1.15216E-11 ,  9.84163E-12 ,  8.39862E-12  ,
         7.16718E-12 ,  6.11631E-12 ,  5.21952E-12  ,
         4.45422E-12 ,  3.79766E-12 ,  3.23789E-12  ,
         2.76062E-12 ,  2.35370E-12 ,  2.00677E-12  ,
         1.70943E-12 ,  1.45614E-12 ,  1.24039E-12  ,
         1.05660E-12 ,  9.00051E-13 ,  7.66025E-13  ,
         6.51957E-13 ,  5.54875E-13 ,  4.72250E-13  ,
         4.01928E-13 ,  3.41805E-13 ,  2.90676E-13  ,
         2.47195E-13 ,  2.10218E-13 ,  1.78773E-13  ,
         1.51925E-13 ,  1.29109E-13 ,  1.09720E-13  ,
         9.32431E-14 ,  7.92402E-14 ,  6.73001E-14  ,
         5.71591E-14 ,  4.85462E-14 ,  4.12312E-14  ,
         3.50184E-14 ,  2.97261E-14 ,  2.52336E-14  ,
         2.14201E-14 ,  1.81829E-14 ,  1.54350E-14  ,
         1.30957E-14 ,  1.11109E-14 ,  9.42699E-15  ,
         7.99825E-15 ,  6.78606E-15 ,  5.75458E-15  ,
         4.87990E-15 ,  4.13816E-15 ,  3.50916E-15  ,
         2.97578E-15 ,  2.52208E-15 ,  2.13755E-15  ,
         1.81165E-15 ,  1.53544E-15 ,  1.30134E-15  ,
         1.10227E-15 ,  9.33655E-16 ,  7.90833E-16  ,
         6.69858E-16 ,  5.67389E-16 ,  4.80294E-16  ,
         4.06568E-16 ,  3.44159E-16 ,  2.91330E-16  ,
         2.46611E-16 ,  2.08625E-16 ,  1.76491E-16  ,
	 1.49306E-16 , 1.26309E-16 , 1.06854E-16,  0};

  const size_t YSize(Xerg7.size());

  // write source cards

  sourceCard.setActive();
  SDef::SrcData D1(1);
  SDef::SrcInfo SI1('A');
  SDef::SrcProb SP1(' ');

   for(size_t ii=1;ii<YSize;ii++) 
   {  
    SI1.addData(Xerg7[ii]);
    SP1.addData(Yerg7[ii]);
    D1.addUnit(SI1);  
    D1.addUnit(SP1);
   }  

   sourceCard.setData("1erg",D1);  


// the NestorSide Y step is set so that the fission plate centre is at the origin, hence this is in the 3rd layer of the fission plate  


  sourceCard.setComp("2vec",Geometry::Vec3D(0.0,1.0,0.0 ));


  SDef::SrcData D2(2);
  // SDef::SrcInfo SI2('A');
  // SDef::SrcProb SP2(' ');
  SDef::SrcBias SB2('A ');
  //(' ');
 
  // SI2.addData(-1);
  // SI2.addData(1);
  // SP2.addData(1);
  // SP2.addData(1);  
  SB2.addData(-31);
  SB2.addData(1);
  D2.addUnit(SB2);
 
  sourceCard.setData("3dir",D2);
  


  size_t nSlab;
  double Len(0.0);
  int M(0);
  std::vector<double> thick;

  nSlab=Control.EvalVar<size_t>(expN+"FissionPlateNSlab");
  for(size_t i=0;i<nSlab;i++)
    {
     const std::string NStr(StrFunc::makeString(i));
     Len+=Control.EvalVar<double>(expN+"FissionPlateThick"+NStr);
     if(ModelSupport::EvalMat<int>(Control,expN+"FissionPlateMat"+NStr)==4)
       M=i;
     thick.push_back(Len);   
    }


  SDef::SrcData D3(3);
  SDef::SrcInfo SI3;
  SDef::SrcProb SP3; 
  SI3.addData(thick.at(M-1)-thick.back()/2);
  SI3.addData(thick.at(M)-thick.back()/2);
  SP3.addData(0);
  SP3.addData(1.0);
  D3.addUnit(SI3);  
  D3.addUnit(SP3);  
  sourceCard.setData("4y",D3);  






  // CARD 2 :: Z  card
  // // Check 

  // model 0 (Stuart)


  // SDef::SrcData D4(4);
  // SDef::SrcInfo SI4('A');
  // SDef::SrcProb SP4(' ');

  // std::vector<int> zeroFlag(NZ,0);

  // SP4.addData(0.0);  
  // SI4.addData(Zpt[0]);   
  // for(size_t iz=0;iz<NZ-1;iz++)   
  //   {
  //     SI4.addData(Zpt[iz+1]);   
  //     double hVal(0.0);
  //     for(size_t ix=0;ix<NX-1;ix++)
  // 	hVal+=Ypt.at(iz).at(ix)*(Xpt[ix+1]-Xpt[ix]);
  //     if (hVal<1e-5) zeroFlag[iz]=1;
  //     SP4.addData(hVal*(Zpt[iz+1]-Zpt[iz]));   
  //   }  



  // model 1 (old)

  SDef::SrcData D4(4);
  SDef::SrcInfo SI4('A');
  SDef::SrcProb SP4(' ');

  std::vector<int> zeroFlag(NZ,0);

  // SP4.addData(0.0);  
  // SI4.addData(Zpt[0]);   
  double YptO(0);
  double YptS2 [2*(NX-1)][NZ-1];
  
 std::vector<double> YptS1;

  std::vector<double> hVal1;
  std::vector<double> hVal2;

 for(int i=0;i<NX;i++)   
    YptS1.push_back(0.0);
    
  for(int i=0;i<NZ;i++)   
   {
    hVal1.push_back(0.0);
    hVal2.push_back(0.0);
   }

// brain-storming translation of an original excel table that models the sinbad source 
// (the only model that in fact works fine: interpolate the pdf conserving areas and 
// starting from the centre)

// from centre to lowest value of z coord 
  for(size_t iz=NZ/2-1;iz<NZ-1;iz++)   
   {  
// from centre to max x coord, calculate interpolation values
    for(size_t ix=NX/2-1;ix<NX;ix++)
     {
      if(ix==NX/2-1||ix==NX/2)  
       {
        YptS1.at(NX/2)=(Ypt.at(NX/2-1).at(iz));
        YptS1.at(NX/2-1)=(Ypt.at(NX/2-1).at(iz));
       }
      else
       {
        YptS1.at(ix)=2*Ypt.at(ix-1).at(iz)-YptS1.at(ix-1);
        if(Ypt.at(ix-1).at(iz)==0) 
         YptS1.at(ix)=0;
       }
 
//  from center to lowest x coord
      for(size_t ix=0;ix<NX/2-1;ix++)
       {
	YptS1.at(NX/2-2-ix)=2*Ypt.at(NX/2-2-ix).at(iz)-YptS1.at(NX/2-1-ix);
        if(Ypt.at(NX/2-2-ix).at(iz)==0)
         YptS1.at(NX/2-2-ix)=0; 
       }
   }
 
// create the arrows of the mcnp distribution for each row; double up points to conserve 
// Monte Carlo areas in form of histogram

 std::vector<double> YptS1R;

    for(size_t ix=0;ix<NX;ix++)
      {
	if(ix!=NX/2)
	  YptS1R.push_back(YptS1.at(ix));
      }
    for(size_t ix=0;ix<YptS1R.size();ix++)
     {
      if(ix==0)   
       {
        YptS2[2*ix][iz]=0;
        YptS2[2*ix+1][iz]=YptS1R.at(ix);
       }
      else if(ix==YptS1R.size()-1)   
       {
        YptS2[2*ix][iz]=YptS1R.at(ix);
        YptS2[2*ix+1][iz]=0;
       }
      else if (YptS1R.at(ix-1)==0 && YptS1R.at(ix)!=0 && ix<YptS1R.size() &&ix>0)
       {   
        YptS2[2*ix][iz]=0;
        YptS2[2*ix+1][iz]=YptS1R.at(ix);
       }
      else if(YptS1R.at(ix)!=0 && YptS1R.at(ix+1)==0 && ix<YptS1R.size()-1 &&ix>0)   
       {
        YptS2[2*ix][iz]=YptS1R.at(ix);
        YptS2[2*ix+1][iz]=0;
       }
      else
       { 
        YptS2[2*ix][iz]=YptS1R.at(ix);
        YptS2[2*ix+1][iz]=YptS1R.at(ix);
       }
     }
 
	// sums pdf's for y coord
    if(iz==NZ/2-1)  
     {
      hVal1.at(iz)=0.0;
      for(size_t ix=0;ix<NX-1;ix++)
       hVal1.at(iz)+=Ypt.at(ix).at(NZ/2-1);
      hVal2.at(iz)=hVal1.at(NZ/2-1);
      ELog::EM<<" AAAA "<<iz<<" "<<hVal2.at(iz)<<ELog::endDiag;
     }
    else if(iz==NZ/2)  
     {
        hVal1.at(iz)=0.0;
      for(size_t ix=0;ix<NX-1;ix++)
      hVal1.at(iz)+=Ypt.at(ix).at(NZ/2);
      hVal2.at(iz)=hVal1.at(NZ/2-1);
     }
    else
     {
      hVal1.at(iz)=0.0;
      for(size_t ix=0;ix<NX-1;ix++)
       hVal1.at(iz)+=Ypt.at(ix).at(iz); 
      hVal2.at(iz)=2*hVal1.at(iz-1)-hVal2.at(iz-1);    
     }
   }
  
// last line 
  hVal2.at(NZ-1)=2*hVal1.at(NZ-2)-hVal2.at(NZ-2);    

// lower part of the excel table
  for(size_t iz=0;iz<NZ/2-1;iz++)   
   {

    for(size_t ix=NX/2-1;ix<NX;ix++)
     {
      if(ix==NX/2-1||ix==NX/2)  
       {
	YptS1.at(NX/2)=(Ypt.at(NX/2-1).at(NZ/2-1-iz-1));
	YptS1.at(NX/2-1)=(Ypt.at(NX/2-1).at(NZ/2-1-iz-1));
       }
      else
       {
	YptS1.at(ix)=2*Ypt.at(ix-1).at(NZ/2-1-iz-1)-YptS1.at(ix-1);
        if(Ypt.at(ix-1).at(NZ/2-1-iz-1)==0) 
	 YptS1.at(ix)=0;
       }
     }
    for(size_t ix=0;ix<NX/2-1;ix++)
     {
      YptS1.at(NX/2-2-ix)=2*Ypt.at(NX/2-2-ix).at(NZ/2-1-iz-1)-YptS1.at(NX/2-ix-1);
      if(Ypt.at(NX/2-2-ix).at(NZ/2-1-iz-1)==0)
       YptS1.at(NX/2-2-ix)=0; 
       ELog::EM<<" A02 "<<iz<<" "<<ix<<" "<<YptS1.at(NX/2-2-ix)<<" "<<Ypt.at(NX/2-2-ix).at(NZ/2-1-iz-1)<<" "<<YptS1.at(NX/2-ix-1)<<ELog::endDiag;
     }

    // dist rows
 std::vector<double> YptS1S;

    for(size_t ix=0;ix<NX;ix++)
      {
	if(ix!=NX/2)
	  YptS1S.push_back(YptS1.at(ix));
      }

    for(size_t ix=0;ix<YptS1S.size();ix++)
     {

      if(ix==0)   
       {
        YptS2[2*ix][NZ/2-2-iz]=0;
        YptS2[2*ix+1][NZ/2-2-iz]=YptS1S.at(ix);
       }
      else if(ix==YptS1S.size()-1)   
       {
        YptS2[2*ix][NZ/2-2-iz]=YptS1S.at(ix);
        YptS2[2*ix+1][NZ/2-2-iz]=0;
       }
      else if (YptS1S.at(ix-1)==0 && YptS1S.at(ix)!=0 && ix<YptS1S.size() && ix>0)
       {   
        YptS2[2*ix][NZ/2-2-iz]=0;
        YptS2[2*ix+1][NZ/2-2-iz]=YptS1S.at(ix);
       }
      else if(YptS1S.at(ix)!=0 && YptS1S.at(ix+1)==0 && ix<YptS1S.size()-1 &&ix>0)   
       {
        YptS2[2*ix][NZ/2-2-iz]=YptS1S.at(ix);
        YptS2[2*ix+1][NZ/2-2-iz]=0;
       }
      else
       { 
        YptS2[2*ix][NZ/2-2-iz]=YptS1S.at(ix);
        YptS2[2*ix+1][NZ/2-2-iz]=YptS1S.at(ix);
       }
      ELog::EM<< "XX "<<YptS1S.at(ix)<<" "<<YptS2[2*ix][NZ/2-2-iz]<<"  "<<YptS2[2*ix+1][NZ/2-2-iz]<<ELog::endDiag;

      }
 
	// sums
      hVal1.at(NZ/2-2-iz)=0.0;        
      for(size_t ix=0;ix<NX-1;ix++)
	{
       hVal1.at(NZ/2-2-iz)+=Ypt.at(ix).at(NZ/2-2-iz);
 
	}
      hVal2.at(NZ/2-2-iz)=2*hVal1.at(NZ/2-2-iz)-hVal2.at(NZ/2-1-iz);    
  }  

   for(size_t iz=0;iz<NZ;iz++)   
    {
     SI4.addData(Zpt[iz]);
    }   

   double hVal(0.0);
   for(size_t iz=0;iz<NZ;iz++)   
    {
     hVal=hVal2.at(NZ-1-iz);   
     SP4.addData(hVal);
    }   

   D4.addUnit(SI4 );  
   D4.addUnit(SP4);  
   sourceCard.setData("5z",D4);  

   SDef::SrcData D5(5);
   SDef::DSTerm<int>* DS5=D5.getDS<int>(); 
   DS5->setType("z",'s');
   SDef::DSIndex DIZ(std::string("z"));

   std::vector<double> Xpt1;
   double x1;
   double x2;
   std::vector<double> Ypt1;
   for(size_t ix=0;ix<NX-1;ix++)
     {
      x1=Xpt[ix]-0.01;
      x2=Xpt[ix]+0.01;
      Xpt1.push_back(x1);
      Xpt1.push_back(x2);
     }


   for(size_t iz=0;iz<NZ-1;iz++)
    {
     SDef::SrcInfo SIX;
     SDef::SrcProb SPX;
     //     SPX.addData(0.0);
     for(size_t ix=0;ix<Xpt1.size();ix++) 
      {
       SIX.addData(Xpt1[ix]); 
       SPX.addData(YptS2[ix][iz]);
      }
      DIZ.addData(iz+6,&SIX,0,&SPX);
    }
   
   D5.addUnit(&DIZ);
   sourceCard.setData("6x",D5); 






  //model 2 ()



 
  size_t S=Control.EvalVar<size_t>(expN+"ShieldNSlab");
  size_t NS=Control.EvalVar<size_t>(expN+"NestorSideNSlab");
  size_t FPX=Control.EvalVar<size_t>(expN+"FissionPlateNXSpace");
  size_t FPZ=Control.EvalVar<size_t>(expN+"FissionPlateNZSpace");
  size_t cellStart=3+NS+S+10;
  size_t cellEnd=cellStart+(FPX-1)*(FPZ-1); 
//  ELog::EM<<" SO "<<cellStart<<" "<<cellEnd<<ELog::endDiag;
  



   // SDef::SrcData D5(5);
   // SDef::DSTerm<int>* DS5=D5.getDS<int>(); 
   // DS5->setType("z",'s');
   // SDef::DSIndex DIZ(std::string("z"));

   // for(size_t iz=0;iz<NZ-1;iz++)
   //  {
   //   SDef::SrcInfo SIX;
   //   SDef::SrcProb SPX;
   //   SPX.addData(0.0);
   //   SIX.addData(Xpt[0]); 
   //   for(size_t ix=0;ix<NX-1;ix++) 
   //    {
   //     SIX.addData(Xpt[ix+1]); 
   //     if (zeroFlag[iz])
   //      SPX.addData(1e-5);
   //     else
   //      SPX.addData(Ypt.at(iz).at(ix)*(Xpt[ix+1]-Xpt[ix]));
   //    }
   //    DIZ.addData(iz+6,&SIX,0,&SPX);
   //  }
   
   // D5.addUnit(&DIZ);
   // sourceCard.setData("6x",D5); 







  sourceCard.setComp("7eff", 0.00000001);


  // sourceCard.write(std::ostream& OX);

  return;
}  






}  // NAMESPACE SDef



  // REVERST ALL THE VALUES:
  // double tmpX;
  // for(size_t i=0;i<NZ/2;i++)
  //   {
  //     for(size_t j=0;j<NX;j++)
  // 	{
  // 	  tmpX=sinbadSource[i][j];
  // 	  sinbadSource[i][j]=sinbadSource[i][NZ-j];
  // 	  sinbadSource[i][NZ-j]=tmpX;
  // 	}
  //   }	  
