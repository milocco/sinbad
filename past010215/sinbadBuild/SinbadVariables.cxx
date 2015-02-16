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
#include "Code.h"
#include "varList.h"
#include "FuncDataBase.h" 
#include "variableSetup.h"
#include "stringCombine.h"

namespace setVariable
{

void
SinbadVariables(FuncDataBase& Control)
  /*!
    Function to set the control variables and constants
    -- This version is for Sinbad ()
    \param Control :: Function data base to add constants too
  */
{

  /////////////////////////////////////////////////////////////////////////////////
  // EXPERIMENT 49 (ASPIS Neutron/Gamma-Ray Transport Through Water/Steel Arrays)
  /////////////////////////////////////////////////////////////////////////////////


  ///////////////////////
  // 49 Shield array

  // define centre
  Control.addVariable("49ShieldXStep",0.0);  
  Control.addVariable("49ShieldYStep",0.0);  
  Control.addVariable("49ShieldZStep",0.0);  
  Control.addVariable("49ShieldXYAngle",0.0);  
  Control.addVariable("49ShieldZAngle",0.0);  
  //number of slabs
  Control.addVariable("49ShieldNSlab",26);
  Control.addVariable("49ShieldWidth",182.9);   
  Control.addVariable("49ShieldHeight",191.0);  
  Control.addVariable("49ShieldThick0",4.60); 
  Control.addVariable("49ShieldMat0","Void"); 
  Control.addVariable("49ShieldThick1",0.50); 
  Control.addVariable("49ShieldMat1","49Boral"); 
  // fictitious layer to accomodate the detectors when the boral is shifted back
  Control.addVariable("49ShieldThick2",0.0);
  Control.addVariable("49ShieldMat2","Void");
  Control.addVariable("49ShieldThick3",5.08); 
  Control.addVariable("49ShieldMat3","49MildSteel7");  
  Control.addVariable("49ShieldThick4",0.70); 
  Control.addVariable("49ShieldMat4","Void");  
  Control.addVariable("49ShieldThick5",5.08); 
  Control.addVariable("49ShieldMat5","49MildSteel7");  
  Control.addVariable("49ShieldThick6",0.70); 
  Control.addVariable("49ShieldMat6","Void");  
  Control.addVariable("49ShieldThick7",5.08); 
  Control.addVariable("49ShieldMat7","49MildSteel7");  
  Control.addVariable("49ShieldThick8",0.70); 
  Control.addVariable("49ShieldMat8","Void");  
  Control.addVariable("49ShieldThick9",3.00); 
  Control.addVariable("49ShieldMat9","49StainlessSteel");  
  Control.addVariable("49ShieldThick10",18.31); 
  Control.addVariable("49ShieldMat10","49Water");  
  Control.addVariable("49ShieldThick11",3.00); 
  Control.addVariable("49ShieldMat11","49StainlessSteel");  
  Control.addVariable("49ShieldThick12",0.70); 
  Control.addVariable("49ShieldMat12","Void");  
  Control.addVariable("49ShieldThick13",5.08); 
  Control.addVariable("49ShieldMat13","49MildSteel7");  
  Control.addVariable("49ShieldThick14",0.70); 
  Control.addVariable("49ShieldMat14","Void");  
  Control.addVariable("49ShieldThick15",2.50); 
  Control.addVariable("49ShieldMat15","49MildSteel10");
  Control.addVariable("49ShieldThick16",19.80); 
  Control.addVariable("49ShieldMat16","49Water");  
  Control.addVariable("49ShieldThick17",2.50); 
  Control.addVariable("49ShieldMat17","49StainlessSteel");  
  Control.addVariable("49ShieldThick18",0.70); 
  Control.addVariable("49ShieldMat18","Void");  
  Control.addVariable("49ShieldThick19",5.08); 
  Control.addVariable("49ShieldMat19","49MildSteel7");  
  Control.addVariable("49ShieldThick20",0.70); 
  Control.addVariable("49ShieldMat20","Void");  
  Control.addVariable("49ShieldThick21",5.08); 
  Control.addVariable("49ShieldMat21","49MildSteel7");  
  Control.addVariable("49ShieldThick22",30.70); 
  Control.addVariable("49ShieldMat22","Void");  
  Control.addVariable("49ShieldThick23",15.24); 
  Control.addVariable("49ShieldMat23","49Concrete");  
  Control.addVariable("49ShieldThick24",2.00); 
  Control.addVariable("49ShieldMat24","Void");  
  Control.addVariable("49ShieldThick25",15.24); 
  Control.addVariable("49ShieldMat25","49Concrete");  



  /////////////////////////////////////////////////
  // 49 NestorSide (The array between Nestor reactor and fission plate)


  Control.addVariable("49NestorSideXStep",0);
  // the Y step is set so that the fission plate centre is at the origin  
  Control.addVariable("49NestorSideYStep",-26.71);  
  Control.addVariable("49NestorSideZStep",0);  
  Control.addVariable("49NestorSideXYAngle",0.0);  
  Control.addVariable("49NestorSideZAngle",0.0);  
  Control.addVariable("49NestorSideWidth",182.9);   
  Control.addVariable("49NestorSideHeight",191.0);  
  // number of slabs
  Control.addVariable("49NestorSideNSlab",6);
  Control.addVariable("49NestorSideThick0",3.18); 
  Control.addVariable("49NestorSideMat0","49MildSteel1");  
  Control.addVariable("49NestorSideAlWindowRadius",56.06); 
  Control.addVariable("49NestorSideThick1",0.70); 
  Control.addVariable("49NestorSideMat1","Void");  
  Control.addVariable("49NestorSideThick2",5.08); 
  Control.addVariable("49NestorSideMat2","49Lead");  
  Control.addVariable("49NestorSideThick3",0.60); 
  Control.addVariable("49NestorSideMat3","Void");  
  Control.addVariable("49NestorSideThick4",15.0); 
  Control.addVariable("49NestorSideMat4","49Graphite"); 
  Control.addVariable("49NestorSideThick5",0.70); 
  Control.addVariable("49NestorSideMat5","Void"); 



  ////////////////////////////////////////////////
  // 49 Fission Plate

  Control.addVariable("49FissionPlateXStep",0.0);  
  Control.addVariable("49FissionPlateYStep",0.0);   
  Control.addVariable("49FissionPlateZStep",0.0);  
  Control.addVariable("49FissionPlateXYAngle",0.0);   
  Control.addVariable("49FissionPlateZAngle",0.0);   
  //fission plate layers  
  Control.addVariable("49FissionPlateNSlab",6);
  //correct but to avoid geom error it is the same as other slabs
  Control.addVariable("49FissionPlateHeight",191.1);  
  Control.addVariable("49FissionPlateWidth",182.9); 
  Control.addVariable("49FissionPlateThick0",1.2);
  Control.addVariable("49FissionPlateMat0","49Aluminium");   
  Control.addVariable("49FissionPlateThick1",0.1); 
  Control.addVariable("49FissionPlateMat1","Void");   
  Control.addVariable("49FissionPlateThick2",0.1); 
  Control.addVariable("49FissionPlateMat2","49Aluminium");   
  Control.addVariable("49FissionPlateThick3",0.2); 
  Control.addVariable("49FissionPlateMat3","49Fuel");   
  Control.addVariable("49FissionPlateThick4",0.1); 
  Control.addVariable("49FissionPlateMat4","49Aluminium");   
  Control.addVariable("49FissionPlateThick5",1.2); 
  Control.addVariable("49FissionPlateMat5","49Aluminium");   
  //fuel plate index
  Control.addVariable("49FissionPlateDivIndex0",3);
  //////////////////////////////////////////////////////////////
  // imports of fission source specificationsfrom SINBAD     
  //49 X-Z sectioning of fuel plate
  double  Xarray[16]={ -49.75, -46.58, -43.32, -37.08, -33.92, -27.58, -11.75, -2.25,  7.25, 16.75, 32.58, 38.92, 42.08, 48.42, 51.58, 54.75 };
  double Zarray[16]={ -51.44, -47.63, -40.64, -35.56, -31.75, -19.69, -15.88,  -5.29,  5.29, 15.88, 19.69, 31.75, 35.56, 40.64, 47.63, 51.44};
  //49 source specification
  double fissionSource49 [15] [15] = {
 {    0  ,    0  ,    0  ,    0  ,    0  ,    0  , 2.935, 2.967, 2.861,   0  ,   0  ,   0  ,   0  ,   0  ,   0   },
 {    0  ,    0  ,    0  ,    0  ,    0  ,  3.222, 3.529, 3.567, 3.446, 3.023,   0  ,   0  ,   0  ,   0  ,   0	 },
 {    0  ,    0  ,    0  ,    0  ,  3.228,  3.782, 4.152, 4.208, 4.082, 3.615, 2.959,   0  ,   0  ,   0  ,   0	 },
 {    0  ,    0  ,    0  ,  3.234,  3.566,  4.164, 4.575, 4.648, 4.523, 4.025, 3.317, 2.915,   0  ,   0  ,   0	 },
 {    0  ,    0  ,  3.350,  3.745,  4.099,  4.750, 5.220, 5.325, 5.205, 4.658, 3.867, 3.423, 2.916,   0  ,   0	 },
 {    0  ,  3.300,  3.756,  4.168,  4.538,  5.226, 5.743, 5.874, 5.760, 5.174, 4.315, 3.838, 3.305, 2.738,   0	 },
 {  3.172,  3.522,  3.990,  4.412,  4.790,  5.499, 6.042, 6.186, 6.076, 5.466, 4.569, 4.073, 3.526, 2.951, 2.558 },
 {  3.281,  3.641,  4.119,  4.546,  4.928,  5.645, 6.199, 6.350, 6.239, 5.613, 4.690, 4.184, 3.631, 3.056, 2.670 },
 {  3.145,  3.500,  3.967,  4.382,  4.750,  5.440, 5.972, 6.117, 6.003, 5.379, 4.466, 3.970, 3.433, 2.883, 2.519 },
 {    0  ,  3.275,  3.721,  4.114,  4.461,  5.109, 5.611, 5.746, 5.632, 5.021, 4.132, 3.654, 3.142, 2.625,   0	 },
 {    0  ,    0  ,  3.294,  3.645,  3.954,  4.535, 4.990, 5.113, 5.003, 4.421, 3.583, 3.139, 2.674,   0  ,   0	 },
 {    0  ,    0  ,    0  ,  3.052,  3.317,  3.824, 4.229, 4.340, 4.236, 3.699, 2.937, 2.541,   0  ,   0  ,   0	 },
 {    0  ,    0  ,    0  ,    0  ,  2.888,  3.359, 3.739, 3.841, 3.742, 3.244, 2.545,   0  ,   0  ,   0  ,   0	 },
 {    0  ,    0  ,    0  ,    0  ,    0  ,  2.681, 3.036, 3.124, 3.032, 2.607,   0  ,   0  ,   0  ,   0  ,   0	 },
 {    0  ,    0  ,    0  ,    0  ,    0  ,    0  , 2.399, 2.470, 2.382,   0  ,   0  ,   0  ,   0  ,   0  ,   0	 }
 } ; 
  //set CombLayer variables and keys for fission plate sectioning and source
  int nx=sizeof(Xarray)/sizeof(double);
  int nz=sizeof(Zarray)/sizeof(double);
  Control.addVariable("49FissionPlateNXSpace",nx);   
  Control.addVariable("49FissionPlateNZSpace",nz);   
  for(int i=0;i<nx;i++)
    {
     const std::string baseKey=StrFunc::makeString("49FissionPlateXPt",i);
     Control.addVariable(baseKey,Xarray[i]);  
    }
  for(int i=0;i<nz;i++)
    {
     const std::string baseKey=StrFunc::makeString("49FissionPlateZPt",i);
     Control.addVariable(baseKey,Zarray[i]);  
    }
  int ny=10;
// sizeof(Zarray)/sizeof(double);

  // for(int i=0;i<ny;i++)
  //   {
  //     const std::string baseKey=
  // 	StrFunc::makeString("49FissionPlateYPt",i);
  //     // BeamLine in guide bay
  //     Control.addVariable(baseKey,Xarray[i]);  
  //   }

  int i(0);
  size_t nx1(10);
  size_t nz1(10);
  const size_t ix(10);
  const unsigned long iz(10);
  std::string bz;

  for(size_t ix=0;ix<nx-1;ix++)
    {
     std::string SX=StrFunc::makeString("49SourceX",ix);
     for(size_t iz=0;iz<nz-1;iz++)
       {
	 //        std::string bz=StrFunc::makeString(iz);
        std::string SXZ=StrFunc::makeString(SX+"Z",iz);
        Control.addVariable(SXZ,fissionSource49[iz][ix]);
	//  ELog::EM<<" KZ "<<SXZ<<ELog::endDiag;

      }
    }

  Control.addVariable("49FissionPlateMatInL0","49Fuel");   
  Control.addVariable("49FissionPlateMatOutL0","49Aluminium");   
  Control.addVariable("49FissionPlateMatTempL0",300.0);   
  Control.addVariable("49FissionPlateMatL1","Aluminium");   
  Control.addVariable("49FissionPlateMatTempL1",300.0);   


    //////////////////////////////////////////////////////////////
  // DETECTORS




  Control.addVariable("49DetOffsetX",2.5);  
  Control.addVariable("49DetOffsetZ",-6.6);
  // possible detector positions along Y axis 
  Control.addVariable("49DetNY",33);    

  Control.addVariable("49DetStepX",0.0);  
  Control.addVariable("49DetStepZ",0.0);  


  // monitor
  Control.addVariable("49StepY0",0.0);  
  // pos 0
  //Detector 1 needs this depth; the boral is then moved accordingly
  Control.addVariable("49StepY1",5.1);  
  // pos 1
  Control.addVariable("49StepY2",10.18);  
  // pos 2
  Control.addVariable("49StepY3",15.96);
  // pos 3  
  Control.addVariable("49StepY4",21.74);
  // pos F0 (water shield front)  
  Control.addVariable("49StepY5",25.44);
  // pos F0.4
  Control.addVariable("49StepY6",25.84);  
  // pos F2  
  Control.addVariable("49StepY7",27.44);  
  // pos F4
  Control.addVariable("49StepY8",29.44);  
  // pos F4.5
  Control.addVariable("49StepY9",29.94);
  // pos F5
  Control.addVariable("49StepY10",30.44);
  // pos F7.5  
  Control.addVariable("49StepY11",32.94);
  // pos F9  
  Control.addVariable("49StepY12",34.44);
  // pos F9.3  
  Control.addVariable("49StepY13",34.74);
  // pos F13.5  
  Control.addVariable("49StepY14",38.94); 
  // pos F13.7  
  Control.addVariable("49StepY15",39.14); 
  // pos F13.8  
  Control.addVariable("49StepY16",39.24); 
  // pos F14.3  
  Control.addVariable("49StepY17",39.74); 
  // pos F14.6  
  Control.addVariable("49StepY18",40.04); 
  // pos F14.8  
  Control.addVariable("49StepY19",40.24); 
  // pos F15   
  Control.addVariable("49StepY20",40.44);
  // pos F18  
  Control.addVariable("49StepY21",43.44);
  // pos 4
  Control.addVariable("49StepY22",46.75);  
  // pos 5
  Control.addVariable("49StepY23",52.53);  
  // pos R0
  Control.addVariable("49StepY24",55.73);
  // pos R1.1  
  Control.addVariable("49StepY25", 56.83);  
  // pos R1.6  
  Control.addVariable("49StepY26", 57.33);  
  // pos R4
  Control.addVariable("49StepY27", 59.73);  
  // pos R8
  Control.addVariable("49StepY28",63.73);  
  // POS 9.8
  Control.addVariable("49StepY29",65.53);  
  // pos R10.1
  Control.addVariable("49StepY30",65.83);
  // pos R15.7  
  Control.addVariable("49StepY31",71.43);  
  // pos R18.8
  Control.addVariable("49StepY32",74.53);  

  // possible detectors for vertical scans
  Control.addVariable("49DetNZ",7);    
  Control.addVariable("49StepZ0",75.0);  
  Control.addVariable("49StepZ1",50.0);  
  Control.addVariable("49StepZ2",25.0);  
  Control.addVariable("49StepZ3",0.0);
  Control.addVariable("49StepZ4",-25.0);
  Control.addVariable("49StepZ5",-50.0);
  Control.addVariable("49StepZ6",-75.0);  




 
  //Sulphur
  Control.addVariable("49SMat","49S");  
  Control.addVariable("49SDiam",5.10);   
  Control.addVariable("49SThick",0.56); 
  // active detector positions along Y axis
  Control.addVariable("49SActiveY0",1);   
  Control.addVariable("49SActiveY1",1);   
  Control.addVariable("49SActiveY2",1);   
  Control.addVariable("49SActiveY3",1);   
  Control.addVariable("49SActiveY4",1);   
  Control.addVariable("49SActiveY5",0);   
  Control.addVariable("49SActiveY6",0);   
  Control.addVariable("49SActiveY7",0);   
  Control.addVariable("49SActiveY8",0);   
  Control.addVariable("49SActiveY9",1);   
  Control.addVariable("49SActiveY10",0);   
  Control.addVariable("49SActiveY11",0);   
  Control.addVariable("49SActiveY12",1);   
  Control.addVariable("49SActiveY13",0);   
  Control.addVariable("49SActiveY14",0);   
  Control.addVariable("49SActiveY15",0);   
  Control.addVariable("49SActiveY16",0);   
  Control.addVariable("49SActiveY17",0);   
  Control.addVariable("49SActiveY18",0);   
  Control.addVariable("49SActiveY19",0);   
  Control.addVariable("49SActiveY20",0);   
  Control.addVariable("49SActiveY21",0);   
  Control.addVariable("49SActiveY22",1);   
  Control.addVariable("49SActiveY23",1);   
  Control.addVariable("49SActiveY24",0);   
  Control.addVariable("49SActiveY25",0);   
  Control.addVariable("49SActiveY26",0);   
  Control.addVariable("49SActiveY27",0);   
  Control.addVariable("49SActiveY28",0);   
  Control.addVariable("49SActiveY29",0);   
  Control.addVariable("49SActiveY30",0);   
  Control.addVariable("49SActiveY31",0);   
  Control.addVariable("49SActiveY32",0);   
  // number of vertical scans
  Control.addVariable("49SVscanNY",0);           


  // Rhodium
  Control.addVariable("49RhMat","49Rh");  
  Control.addVariable("49RhDiam",1.27);   
  Control.addVariable("49RhThick",0.0015); 
  // Rh positions are the nominal ones; in case of detector stack these are arranged consequently
  // active detector positions along Y axis
  Control.addVariable("49RhActiveY0",0);   
  Control.addVariable("49RhActiveY1",1);   
  Control.addVariable("49RhActiveY2",1);   
  Control.addVariable("49RhActiveY3",1);   
  Control.addVariable("49RhActiveY4",1);   
  Control.addVariable("49RhActiveY5",1);   
  Control.addVariable("49RhActiveY6",0);   
  Control.addVariable("49RhActiveY7",0);   
  Control.addVariable("49RhActiveY8",0);   
  Control.addVariable("49RhActiveY9",0);   
  Control.addVariable("49RhActiveY10",0);   
  Control.addVariable("49RhActiveY11",1);   
  Control.addVariable("49RhActiveY12",0);   
  Control.addVariable("49RhActiveY13",0);   
  Control.addVariable("49RhActiveY14",0);   
  Control.addVariable("49RhActiveY15",0);   
  Control.addVariable("49RhActiveY16",0);   
  Control.addVariable("49RhActiveY17",0);   
  Control.addVariable("49RhActiveY18",1);   
  Control.addVariable("49RhActiveY19",0);   
  Control.addVariable("49RhActiveY20",0);   
  Control.addVariable("49RhActiveY21",0);   
  Control.addVariable("49RhActiveY22",1);   
  Control.addVariable("49RhActiveY23",1);   
  Control.addVariable("49RhActiveY24",0);   
  Control.addVariable("49RhActiveY25",0);   
  Control.addVariable("49RhActiveY26",0);   
  Control.addVariable("49RhActiveY27",0);   
  Control.addVariable("49RhActiveY28",0);   
  Control.addVariable("49RhActiveY29",0);   
  Control.addVariable("49RhActiveY30",0);   
  Control.addVariable("49RhActiveY31",0);   
  Control.addVariable("49RhActiveY32",0);   
  // number of vertical scans
  Control.addVariable("49RhVscanNY",0);           

  // Manganese
  Control.addVariable("49MnMat","49Mn");  
  Control.addVariable("49MnDiam",1.27);   
  Control.addVariable("49MnThick",0.015);
  // active detectors along axial direction
  Control.addVariable("49MnActiveY0",0);   
  Control.addVariable("49MnActiveY1",1);   
  Control.addVariable("49MnActiveY2",1);   
  Control.addVariable("49MnActiveY3",1);   
  Control.addVariable("49MnActiveY4",1);   
  Control.addVariable("49MnActiveY5",1);   
  Control.addVariable("49MnActiveY6",0);   
  Control.addVariable("49MnActiveY7",1); 
  // deactivate next if performing axial and vertical scan at the same time  
  Control.addVariable("49MnActiveY8",0);   
  Control.addVariable("49MnActiveY9",1);   
  Control.addVariable("49MnActiveY10",0);   
  Control.addVariable("49MnActiveY11",1);   
  Control.addVariable("49MnActiveY12",1);   
  Control.addVariable("49MnActiveY13",0);   
  Control.addVariable("49MnActiveY14",1);   
  Control.addVariable("49MnActiveY15",0);   
  Control.addVariable("49MnActiveY16",0);   
  Control.addVariable("49MnActiveY17",0);   
  Control.addVariable("49MnActiveY18",1);   
  Control.addVariable("49MnActiveY19",0);   
  Control.addVariable("49MnActiveY20",0);   
  Control.addVariable("49MnActiveY21",1);   
  Control.addVariable("49MnActiveY22",1);   
  Control.addVariable("49MnActiveY23",1);   
  Control.addVariable("49MnActiveY24",1);   
  Control.addVariable("49MnActiveY25",0);   
  Control.addVariable("49MnActiveY26",1);   
  Control.addVariable("49MnActiveY27",1);   
  Control.addVariable("49MnActiveY28",1);   
  Control.addVariable("49MnActiveY29",0);   
  Control.addVariable("49MnActiveY30",1);   
  Control.addVariable("49MnActiveY31",1);   
  Control.addVariable("49MnActiveY32",1);
  // number of vertical scans
  Control.addVariable("49MnVscanNY",1);           
  // Axial offset for vertical scan
  Control.addVariable("49MnVscanY0",29.44);   
  // active detectors along vertical direction
  // Control.addVariable("49MnVscanNY",7);           
  Control.addVariable("49MnY0ActiveZ0",1);   
  Control.addVariable("49MnY0ActiveZ1",1);   
  Control.addVariable("49MnY0ActiveZ2",1);   
  Control.addVariable("49MnY0ActiveZ3",1);   
  Control.addVariable("49MnY0ActiveZ4",1);   
  Control.addVariable("49MnY0ActiveZ5",1);   
  Control.addVariable("49MnY0ActiveZ6",1);   

  //TLD
  Control.addVariable("49TldMat","49LiF");  
  Control.addVariable("49TldDiam",1.27);   
  Control.addVariable("49TldThick",0.415); 
  // active detectors along axial direction
  Control.addVariable("49TldActiveY0",0);   
  Control.addVariable("49TldActiveY1",0);   
  Control.addVariable("49TldActiveY2",1);   
  Control.addVariable("49TldActiveY3",1);   
  Control.addVariable("49TldActiveY4",1);   
  Control.addVariable("49TldActiveY5",0);   
  Control.addVariable("49TldActiveY6",1);   
  Control.addVariable("49TldActiveY7",0);   
  Control.addVariable("49TldActiveY8",0);   
  Control.addVariable("49TldActiveY9",0);   
  Control.addVariable("49TldActiveY10",1);   
  Control.addVariable("49TldActiveY11",0);   
  Control.addVariable("49TldActiveY12",0);   
  Control.addVariable("49TldActiveY13",1);   
  Control.addVariable("49TldActiveY14",0);   
  Control.addVariable("49TldActiveY15",1);   
  Control.addVariable("49TldActiveY16",0);   
  Control.addVariable("49TldActiveY17",0);   
  Control.addVariable("49TldActiveY18",0);   
  Control.addVariable("49TldActiveY19",0);   
  Control.addVariable("49TldActiveY20",0);   
  Control.addVariable("49TldActiveY21",1);   
  Control.addVariable("49TldActiveY22",1);   
  Control.addVariable("49TldActiveY23",1);   
  Control.addVariable("49TldActiveY24",0);   
  Control.addVariable("49TldActiveY25",1);   
  Control.addVariable("49TldActiveY26",0);   
  Control.addVariable("49TldActiveY27",0);   
  Control.addVariable("49TldActiveY28",0);   
  Control.addVariable("49TldActiveY29",1);   
  Control.addVariable("49TldActiveY30",0);   
  Control.addVariable("49TldActiveY31",0);   
  Control.addVariable("49TldActiveY32",0);   
  // number of vertical scans
  Control.addVariable("49TldVscanNY",4);           
  // Axial offset for vertical scan
  Control.addVariable("49TldVscanY0",21.74);   
  Control.addVariable("49TldVscanY1",39.24);   
  Control.addVariable("49TldVscanY2",39.74);   
  Control.addVariable("49TldVscanY3",40.24);   
  // active detectors along vertical direction
  Control.addVariable("49TldY0ActiveZ0",1);   
  Control.addVariable("49TldY0ActiveZ1",1);   
  Control.addVariable("49TldY0ActiveZ2",1);   
  Control.addVariable("49TldY0ActiveZ3",1);   
  Control.addVariable("49TldY0ActiveZ4",1);   
  Control.addVariable("49TldY0ActiveZ5",1);   
  Control.addVariable("49TldY0ActiveZ6",1); 
  //  
  Control.addVariable("49TldY1ActiveZ0",1);   
  Control.addVariable("49TldY1ActiveZ1",1);   
  Control.addVariable("49TldY1ActiveZ2",1);   
  Control.addVariable("49TldY1ActiveZ3",1);   
  Control.addVariable("49TldY1ActiveZ4",1);   
  Control.addVariable("49TldY1ActiveZ5",1);   
  Control.addVariable("49TldY1ActiveZ6",1);
  //   
  Control.addVariable("49TldY2ActiveZ0",1);   
  Control.addVariable("49TldY2ActiveZ1",1);   
  Control.addVariable("49TldY2ActiveZ2",1);   
  Control.addVariable("49TldY2ActiveZ3",1);   
  Control.addVariable("49TldY2ActiveZ4",1);   
  Control.addVariable("49TldY2ActiveZ5",1);   
  Control.addVariable("49TldY2ActiveZ6",1);
  //   
  Control.addVariable("49TldY3ActiveZ0",1);   
  Control.addVariable("49TldY3ActiveZ1",1);   
  Control.addVariable("49TldY3ActiveZ2",1);   
  Control.addVariable("49TldY3ActiveZ3",1);   
  Control.addVariable("49TldY3ActiveZ4",1);   
  Control.addVariable("49TldY3ActiveZ5",1);   
  Control.addVariable("49TldY3ActiveZ6",1);   

  //Ionisation chamber
  Control.addVariable("49IcMat","49Ic");  
  Control.addVariable("49IcDiam",1.27);   
  Control.addVariable("49IcThick",0.015); 
  //
  Control.addVariable("49IcActiveY0",0);   
  Control.addVariable("49IcActiveY1",0);   
  Control.addVariable("49IcActiveY2",0);   
  Control.addVariable("49IcActiveY3",0);   
  Control.addVariable("49IcActiveY4",0);   
  Control.addVariable("49IcActiveY5",0);   
  Control.addVariable("49IcActiveY6",0);   
  Control.addVariable("49IcActiveY7",0);   
  Control.addVariable("49IcActiveY8",1);   
  Control.addVariable("49IcActiveY9",0);   
  Control.addVariable("49IcActiveY10",0);   
  Control.addVariable("49IcActiveY11",0);   
  Control.addVariable("49IcActiveY12",0);   
  Control.addVariable("49IcActiveY13",0);   
  Control.addVariable("49IcActiveY14",0);   
  Control.addVariable("49IcActiveY15",0);   
  Control.addVariable("49IcActiveY16",0);   
  Control.addVariable("49IcActiveY17",1);   
  Control.addVariable("49IcActiveY18",0);   
  Control.addVariable("49IcActiveY19",0);   
  Control.addVariable("49IcActiveY20",0);   
  Control.addVariable("49IcActiveY21",0);   
  Control.addVariable("49IcActiveY22",0);   
  Control.addVariable("49IcActiveY23",0);   
  Control.addVariable("49IcActiveY24",0);   
  Control.addVariable("49IcActiveY25",0);   
  Control.addVariable("49IcActiveY26",0);   
  Control.addVariable("49IcActiveY27",1);   
  Control.addVariable("49IcActiveY28",0);   
  Control.addVariable("49IcActiveY29",0);   
  Control.addVariable("49IcActiveY30",0);
  //in reality: R15.8 rather then R15.7   
  Control.addVariable("49IcActiveY31",1);   
  Control.addVariable("49IcActiveY32",0);   

  //Cd
  Control.addVariable("49CdMat","49Cd");  
  Control.addVariable("49CdDiam",1.27);   
  Control.addVariable("49CdThick",0.127);

  // S pressed
  Control.addVariable("49CdMat","49Sp");  
  Control.addVariable("49CdDiam",3.81);   
  Control.addVariable("49CdThick",0.241);



  /////////////////////////////////////////////////////////////
  // EXPERIMENT 75 
  ////////////////////////////////////////////////////////////

  //NestorSide

  Control.addVariable("75CaveOffSetX",0.0);  
  Control.addVariable("75CaveOffSetY",0.0);  
  Control.addVariable("75CaveOffSetZ",0.0);  

  //L: left, R: right, U: up, D: down, I: in (towards nestor), O: out
  Control.addVariable("75CaveLengthL",90);   
  Control.addVariable("75CaveLengthR",90.);   
  Control.addVariable("75CaveHeightU",90.);  
  Control.addVariable("75CaveHeightD",90.);  
  Control.addVariable("75CaveWidthI",17.0);  
  Control.addVariable("75CaveWidthO",135.29);
  // filled up with water  
  Control.addVariable("75CaveMaterial","Uranium"); 
  Control.addVariable("75CaveTemperature",300.0); 


  Control.addVariable("75CaveSlabN",4);

  // incremental thickness
  Control.addVariable("75CaveLengthLSlab0",2.5);   
  Control.addVariable("75CaveLengthRSlab0",2.5);
  // h inventate   
  Control.addVariable("75CaveHeightUSlab0",2.5);  
  Control.addVariable("75CaveHeightDSlab0",2.5);  
  Control.addVariable("75CaveWidthISlab0",3.21);  
  Control.addVariable("75CaveWidthOSlab0",0.0);  
  Control.addVariable("75CaveMaterialSlab0","Void"); 
  // the al window in slab 0
  Control.addVariable("75CaveAlWindowRadius",56.06); 
  //

  Control.addVariable("75CaveLengthLSlab1",0.0);   
  Control.addVariable("75CaveLengthRSlab1",0.0);   
  Control.addVariable("75CaveHeightUSlab1",0.0);  
  Control.addVariable("75CaveHeightDSlab1",0.0);  
  Control.addVariable("75CaveWidthISlab1",5.38);  
  Control.addVariable("75CaveWidthOSlab1",0.0);  
  Control.addVariable("75CaveMaterialSlab1","Void"); 

  Control.addVariable("75CaveLengthLSlab2",-30.5);   
  Control.addVariable("75CaveLengthRSlab2",-30.5);   
  Control.addVariable("75CaveHeightUSlab2",0.0);  
  Control.addVariable("75CaveHeightDSlab2",0.0);  
  Control.addVariable("75CaveWidthISlab2",0.65);  
  Control.addVariable("75CaveWidthOSlab2",0.0);  
  Control.addVariable("75CaveMaterialSlab2","sbadLead");

  Control.addVariable("75CaveLengthLSlab3",0.0);   
  Control.addVariable("75CaveLengthRSlab3",0.0);   
  Control.addVariable("75CaveHeightUSlab3",0.0);  
  Control.addVariable("75CaveHeightDSlab3",0.0);  
  Control.addVariable("75CaveWidthISlab3",28.91);  
  Control.addVariable("75CaveWidthOSlab3",0.0);  
  Control.addVariable("75CaveMaterialSlab3",1); 



  Control.addVariable("75CaveWidthSlab0",2.0); 

  Control.addVariable("75CaveMaterialSlab0","Void"); 


  Control.addVariable("75CaveWidthSlab1",15.0); 
  Control.addVariable("75CaveMaterialSlab1",1); 









  // Control.addVariable("49FissionPlateDivIndex1",4);   

  // Control.addVariable("49FissionPlateNXSpace",5);   
  // Control.addVariable("49FissionPlateNZSpace",5);   
  

  // Control.addVariable("49FissionPlateXPt0",-30.0);   
  // Control.addVariable("49FissionPlateXPt1",-10.0);   
  // Control.addVariable("49FissionPlateXPt2",0.0);   
  // Control.addVariable("49FissionPlateXPt3",10.0);   
  // Control.addVariable("49FissionPlateXPt4",-30.0);

  // Control.addVariable("49FissionPlateZPt0",-30.0);   
  // Control.addVariable("49FissionPlateZPt1",-10.0);   
  // Control.addVariable("49FissionPlateZPt2",0.0);   
  // Control.addVariable("49FissionPlateZPt3",10.0);   
  // Control.addVariable("49FissionPlateZPt4",-30.0);
  // Control.addVariable("49FissionPlateZPt0",-30.0);   

  //49NestorSide side

  // Control.addVariable("49NestorSideXStep",91.45);  
  // Control.addVariable("49NestorSideYStep",-1.45);  
  // Control.addVariable("49NestorSideZStep",95.5);  

  // Control.addVariable("49NestorSideXStep",0);  
  // Control.addVariable("49NestorSideYStep",0);  
  // Control.addVariable("49NestorSideZStep",0);  



  // Control.addVariable("49NestorSideXYAngle",0.0);  
  // Control.addVariable("49NestorSideZAngle",0.0);  

  // Control.addVariable("49NestorSideWidth",182.9);   
  // Control.addVariable("49NestorSideHeight",191.0);  

  // Control.addVariable("49NestorSideNSlab",6);
  // Control.addVariable("49NestorSideThick0",0.70); 
  // Control.addVariable("49NestorSideMat0","Void"); 
  // Control.addVariable("49NestorSideThick1",15.0); 
  // Control.addVariable("49NestorSideMat1","Graphite"); 
  // Control.addVariable("49NestorSideThick2",0.60); 
  // Control.addVariable("49NestorSideMat2","Void");  
  // Control.addVariable("49NestorSideThick3",5.08); 
  // Control.addVariable("49NestorSideMat3","sbadLead");  
  // Control.addVariable("49NestorSideThick4",0.70); 
  // Control.addVariable("49NestorSideMat4","Void");  
  // Control.addVariable("49NestorSideThick5",3.18); 
  // Control.addVariable("49NestorSideMat5","49MildSteel1");  
  // Control.addVariable("49NestorSideAlWindowRadius",56.06); 



  return;
 }

}  // NAMESPACE setVariable
