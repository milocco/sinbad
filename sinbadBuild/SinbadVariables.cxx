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

  Control.addVariable("49ShieldNSlab",26);
  
  Control.addVariable("49ShieldWidth",182.9);   
  Control.addVariable("49ShieldHeight",191.0);  

  // Control.addVariable("49ShieldThick0",0.70); 
  Control.addVariable("49ShieldThick0",4.04); 

  Control.addVariable("49ShieldMat0","Void"); 
  Control.addVariable("49ShieldThick1",0.50); 
  Control.addVariable("49ShieldMat1","Boral5"); 
  // Control.addVariable("49ShieldThick2",0.0015);
  Control.addVariable("49ShieldThick2",0.56);

  Control.addVariable("49ShieldMat2","Void");  
  Control.addVariable("49ShieldThick3",5.08); 
  Control.addVariable("49ShieldMat3","49MildSteel1");  
  Control.addVariable("49ShieldThick4",0.70); 
  Control.addVariable("49ShieldMat4","Void");  
  Control.addVariable("49ShieldThick5",5.08); 
  Control.addVariable("49ShieldMat5","49MildSteel1");  
  Control.addVariable("49ShieldThick6",0.70); 
  Control.addVariable("49ShieldMat6","Void");  
  Control.addVariable("49ShieldThick7",5.08); 
  Control.addVariable("49ShieldMat7","49MildSteel1");  
  Control.addVariable("49ShieldThick8",0.70); 
  Control.addVariable("49ShieldMat8","Void");  
  Control.addVariable("49ShieldThick9",3.00); 
  Control.addVariable("49ShieldMat9","Stainless304");  
  Control.addVariable("49ShieldThick10",18.31); 
  Control.addVariable("49ShieldMat10","H2O");  
  Control.addVariable("49ShieldThick11",3.00); 
  Control.addVariable("49ShieldMat11","Stainless304");  
  Control.addVariable("49ShieldThick12",0.70); 
  Control.addVariable("49ShieldMat12","Void");  
  Control.addVariable("49ShieldThick13",5.08); 
  Control.addVariable("49ShieldMat13","49MildSteel1");  
  Control.addVariable("49ShieldThick14",0.70); 
  Control.addVariable("49ShieldMat14","Void");  
  Control.addVariable("49ShieldThick15",2.50); 
  Control.addVariable("49ShieldMat15","Void");
  Control.addVariable("49ShieldThick16",19.80); 
  Control.addVariable("49ShieldMat16","H2O");  
  Control.addVariable("49ShieldThick17",2.50); 
  Control.addVariable("49ShieldMat17","Stainless304");  
  Control.addVariable("49ShieldThick18",0.70); 
  Control.addVariable("49ShieldMat18","Void");  
  Control.addVariable("49ShieldThick19",5.08); 
  Control.addVariable("49ShieldMat19","49MildSteel1");  
  Control.addVariable("49ShieldThick20",0.70); 
  Control.addVariable("49ShieldMat20","Void");  
  Control.addVariable("49ShieldThick21",5.08); 
  Control.addVariable("49ShieldMat21","49MildSteel1");  
  Control.addVariable("49ShieldThick22",30.70); 
  Control.addVariable("49ShieldMat22","Void");  
  Control.addVariable("49ShieldThick23",15.24); 
  Control.addVariable("49ShieldMat23","Concrete");  
  Control.addVariable("49ShieldThick24",2.00); 
  Control.addVariable("49ShieldMat24","Void");  
  Control.addVariable("49ShieldThick25",15.24); 
  Control.addVariable("49ShieldMat25","Concrete");  



  /////////////////////////////////////////////////
  // 49 NestorSide 
  // (The part of the experimental array between Nestor reactor and fission plate)


  // Control.addVariable("49NestorSideXStep",91.45);  
  // Control.addVariable("49NestorSideYStep",-1.45);  
  // Control.addVariable("49NestorSideZStep",95.5);  

  Control.addVariable("49NestorSideXStep",0);
  // the Y step is set so that the fission plate centre is at the origin  
  Control.addVariable("49NestorSideYStep",-26.71);  
  Control.addVariable("49NestorSideZStep",0);  

  Control.addVariable("49NestorSideXYAngle",0.0);  
  Control.addVariable("49NestorSideZAngle",0.0);  

  Control.addVariable("49NestorSideWidth",182.9);   
  Control.addVariable("49NestorSideHeight",191.0);  

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

// correct but to avoid geom error it is the same as other slabs
  Control.addVariable("49FissionPlateHeight",191.1);  
  Control.addVariable("49FissionPlateWidth",182.9);  
  Control.addVariable("49FissionPlateNSlab",6);

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


  Control.addVariable("49FissionPlateDivIndex0",3);   

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

  double  Xarray[16]={ -49.75, -46.58, -43.32, -37.08, -33.92, -27.58, -11.75, -2.25,  7.25, 16.75, 32.58, 38.92, 42.08, 48.42, 51.58, 54.75 };

  double Zarray[16]={ -51.44, -47.63, -40.64, -35.56, -31.75, -19.69, -15.88,  -5.29,  5.29, 15.88, 19.69, 31.75, 35.56, 40.64, 47.63, 51.44};


  int nx=sizeof(Xarray)/sizeof(double);
  int nz=sizeof(Zarray)/sizeof(double);

  Control.addVariable("49FissionPlateNXSpace",nx);   
  Control.addVariable("49FissionPlateNZSpace",nz);   

  for(int i=0;i<nx;i++)
    {
      const std::string baseKey=
  	StrFunc::makeString("49FissionPlateXPt",i);
      // BeamLine in guide bay
      Control.addVariable(baseKey,Xarray[i]);  
    }

  for(int i=0;i<nz;i++)
    {
      const std::string baseKey=
  	StrFunc::makeString("49FissionPlateZPt",i);
      // BeamLine in guide bay
      Control.addVariable(baseKey,Zarray[i]);  
    }


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

  for(size_t ix=0;ix<nx-1;ix++)

    for(size_t iz=0;iz<nz-1;iz++)


     {
 
      const std::string baseKey=
  	StrFunc::makeString("49FissionPlateYPt",i);

        Control.addVariable(baseKey,fissionSource49[iz][ix]);
      i+=1;


	// ELog::EM<<" ix "<<ix<<" iz "<<iz<<" i "<<i<<" 49FissionPlateYpt "<<baseKey<<" fissionSource49[ix][iz]) "<<fissionSource49[ix][iz]<<ELog::endWarn;
 

   }


  //     const std::string baseKeyxz=
  // 	StrFunc::makeString(ix,iz);
  //     // BeamLine in guide bay
  //     const std::string baseKey=
  // 	StrFunc::makeString("49FissionPlatePt",ix,iz);

  //     Control.addVariable(baseKey,fissionSource49[ix][iz]);  




  Control.addVariable("49FissionPlateMatInL0","49Fuel");   
  Control.addVariable("49FissionPlateMatOutL0","49Aluminium");   

  Control.addVariable("49FissionPlateMatTempL0",300.0);   

  // Control.addVariable("49FissionPlateMatL1","Aluminium");   
  // Control.addVariable("49FissionPlateMatTempL1",300.0);   






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

  //////////////////////////////////////////////////////////////
  // DETECTORS

  //Sulphur





  Control.addVariable("49SN",9);  

  Control.addVariable("49SMat","49S");  
  Control.addVariable("49SDiam",5.10);   
  Control.addVariable("49SThick",0.56); 
  Control.addVariable("49SXYAngle",0.0);  
  Control.addVariable("49SZAngle",0.0);  
  // Control.addVariable("49SOffSetY",-0.56);  


  Control.addVariable("49S0Active",1);   
  Control.addVariable("49S0StepX",2.5);  
  Control.addVariable("49S0StepY",0.0);
  Control.addVariable("49S0StepZ",-6.6);  


  Control.addVariable("49S1Active",1);   
  Control.addVariable("49S1StepX",2.5);  
  Control.addVariable("49S1StepY",5.1);  
  Control.addVariable("49S1StepZ",-6.6);  

  Control.addVariable("49S2Active",1);   
  Control.addVariable("49S2StepX",2.5);  
  Control.addVariable("49S2StepY",10.18);  
  Control.addVariable("49S2StepZ",-6.6);  

  Control.addVariable("49S3Active",1);   
  Control.addVariable("49S3StepX",2.5);  
  Control.addVariable("49S3StepY",15.96);  
  Control.addVariable("49S3StepZ",-6.6);  


  Control.addVariable("49S4Active",1);   
  Control.addVariable("49S4StepX",2.5);  
  Control.addVariable("49S4StepY",21.74);  
  Control.addVariable("49S4StepZ",-6.6);  


  Control.addVariable("49S5Active",1);   
  Control.addVariable("49S5StepX",2.5);  
  Control.addVariable("49S5StepY",29.94);  
  Control.addVariable("49S5StepZ",-6.6);  


  Control.addVariable("49S6Active",1);   
  Control.addVariable("49S6StepX",2.5);  
  Control.addVariable("49S6StepY",34.44);  
  Control.addVariable("49S6StepZ",-6.6);  


  Control.addVariable("49S7Active",1);   
  Control.addVariable("49S7StepX",2.5);  
  Control.addVariable("49S7StepY",46.75);  
  Control.addVariable("49S7StepZ",-6.6);  


  Control.addVariable("49S8Active",1);   
  Control.addVariable("49S8StepX",2.5);  
  Control.addVariable("49S8StepY", 52.53);  
  Control.addVariable("49S8StepZ",-6.6);  





  //Rhodium

 Control.addVariable("49RhN",13);

  Control.addVariable("49RhMat","Rh");  
  Control.addVariable("49RhRadius",10.27);   
  Control.addVariable("49RhLength",0.4); 
  Control.addVariable("49RhXYAngle",0.0);  
  Control.addVariable("49RhZAngle",0.0);  
  Control.addVariable("49Rh1Active",1);   
  Control.addVariable("49Rh1StepX",2.5);  
  Control.addVariable("49Rh1StepY",5.1);  
  Control.addVariable("49Rh1StepZ",-6.6);  

  Control.addVariable("49Rh2Active",1);   
  Control.addVariable("49Rh2StepX",2.5);  
  Control.addVariable("49Rh2StepY",10.18001);  
  Control.addVariable("49Rh2StepZ",-6.6);  

  Control.addVariable("49Rh3Active",1);   
  Control.addVariable("49Rh3StepX",2.5);  
  Control.addVariable("49Rh3StepY",15.96);  
  Control.addVariable("49Rh3StepZ",-6.6);  


 //  Control.addVariable("49RhActive",0);   
 //  Control.addVariable("49RhStepX",2.5);  
 //  // Control.addVariable("49RhOffStepY0",0.56);  
 // Control.addVariable("49RhStepY",1.45);
 // Control.addVariable("49RhStepZ",-6.6);  

  Control.addVariable("49Rh0Active",1);   
  Control.addVariable("49Rh0StepX",2.5);  
  // Control.addVariable("49RhOffStepY0",0.56);  
  Control.addVariable("49Rh0StepY",1.5);
  Control.addVariable("49Rh0StepZ",-6.6);  


  Control.addVariable("49Rh1Active",1);   
  Control.addVariable("49Rh1StepX",2.5);  
  Control.addVariable("49Rh1StepY",5.1);  
  Control.addVariable("49Rh1StepZ",-6.6);  

  Control.addVariable("49Rh2Active",1);   
  Control.addVariable("49Rh2StepX",2.5);  
  Control.addVariable("49Rh2StepY",10.18001);  
  Control.addVariable("49Rh2StepZ",-6.6);  

  Control.addVariable("49Rh3Active",1);   
  Control.addVariable("49Rh3StepX",2.5);  
  Control.addVariable("49Rh3StepY",15.96);  
  Control.addVariable("49Rh3StepZ",-6.6);  

  Control.addVariable("49Rh4Active",1);   
  Control.addVariable("49Rh4StepX",2.5);  
  Control.addVariable("49Rh4StepY",21.74);  
  Control.addVariable("49Rh4StepZ",-6.6);  

  Control.addVariable("49Rh5Active",1);   
  Control.addVariable("49Rh5StepX",2.5);  
  Control.addVariable("49Rh5StepY",25.44);  
  Control.addVariable("49Rh5StepZ",-6.6);  

  Control.addVariable("49Rh6Active",1);   
  Control.addVariable("49Rh6StepX",2.5);  
  Control.addVariable("49Rh6StepY",27.44);  
  Control.addVariable("49Rh6StepZ",-6.6);  

  Control.addVariable("49Rh7Active",1);   
  Control.addVariable("49Rh7StepX",2.5);  
  Control.addVariable("49Rh7StepY",29.44);  
  Control.addVariable("49Rh7StepZ",-6.6);  

  Control.addVariable("49Rh8Active",1);   
  Control.addVariable("49Rh8StepX",2.5);  
  Control.addVariable("49Rh8StepY",29.94);  
  Control.addVariable("49Rh8StepZ",-6.6);  

  Control.addVariable("49Rh9Active",0);   
  Control.addVariable("49Rh9StepX",2.5);  
  Control.addVariable("49Rh9StepY",32.94);  
  Control.addVariable("49Rh9StepZ",-6.6);  

  Control.addVariable("49Rh10Active",1);   
  Control.addVariable("49Rh10StepX",2.5);  
  Control.addVariable("49Rh10StepY",34.44);  
  Control.addVariable("49Rh10StepZ",-6.6);  

  Control.addVariable("49Rh11Active",1);   
  Control.addVariable("49Rh11StepX",2.5);  
  Control.addVariable("49Rh11StepY",38.94);  
  Control.addVariable("49Rh11StepZ",-6.6);  
  //attenzione!!!!!
  Control.addVariable("49Rh12Active",0);   
  Control.addVariable("49Rh12StepX",2.5);  
  Control.addVariable("49Rh12StepY",40.44);  
  Control.addVariable("49Rh12StepZ",-6.6);  

  Control.addVariable("49Rh13Active",1);   
  Control.addVariable("49Rh13StepX",2.5);  
  Control.addVariable("49Rh13StepY",43.44);  
  Control.addVariable("49Rh13StepZ",-6.6);  

  Control.addVariable("49Rh14Active",1);   
  Control.addVariable("49Rh14StepX",2.5);  
  Control.addVariable("49Rh14StepY",46.75);  
  Control.addVariable("49Rh14StepZ",-6.6);  

  Control.addVariable("49Rh15Active",1);   
  Control.addVariable("49Rh15StepX",2.5);  
  Control.addVariable("49Rh15StepY",52.53);  
  Control.addVariable("49Rh15StepZ",-6.6);  

  Control.addVariable("49Rh16Active",1);   
  Control.addVariable("49Rh16StepX",2.5);  
  Control.addVariable("49Rh16StepY",55.73);  
  Control.addVariable("49Rh16StepZ",-6.6);  

  Control.addVariable("49Rh17Active",1);   
  Control.addVariable("49Rh17StepX",2.5);  
  Control.addVariable("49Rh17StepY",57.33);  
  Control.addVariable("49Rh17StepZ",-6.6);  

  Control.addVariable("49Rh18Active",1);   
  Control.addVariable("49Rh18StepX",2.5);  
  Control.addVariable("49Rh18StepY",59.73);  
  Control.addVariable("49Rh18StepZ",-6.6);  

  Control.addVariable("49Rh19Active",1);   
  Control.addVariable("49Rh19StepX",2.5);  
  Control.addVariable("49Rh19StepY",63.73);  
  Control.addVariable("49Rh19StepZ",-6.6);  

  Control.addVariable("49Rh20Active",1);   
  Control.addVariable("49Rh20StepX",2.5);  
  Control.addVariable("49Rh20StepY",65.83);  
  Control.addVariable("49Rh20StepZ",-6.6);  

  Control.addVariable("49Rh21Active",1);   
  Control.addVariable("49Rh21StepX",2.5);  
  Control.addVariable("49Rh21StepY",71.43);  
  Control.addVariable("49Rh21StepZ",-6.6);  

  Control.addVariable("49Rh22Active",1);   
  Control.addVariable("49Rh22StepX",2.5);  
  Control.addVariable("49Rh22StepY",74.53);  
  Control.addVariable("49Rh22StepZ",-6.6);  










 //  Control.addVariable("49DetectorPositionN",3);  
 //  // Control.addVariable("49DetectorRhPositionN",3);  
 //  // Control.addVariable("49DetectorSPositionN",3);  
 //  // Control.addVariable("49DetectorAuPositionN",3);  

 //  Control.addVariable("49Detector0Active",1);   
 //  Control.addVariable("49Detector1Active",1);   
 //  Control.addVariable("49Detector2Active",1);   
 //  Control.addVariable("49Detector3Active",0);   

 //  // Control.addVariable("49DetectorXStep",2.5);  
 //  // Control.addVariable("49DetectorYStep",20.0);  
 //  // Control.addVariable("49DetectorZStep",-6.6);  
 //  Control.addVariable("49DetectorXYAngle",0.0);  
 //  Control.addVariable("49DetectorZAngle",0.0);  

 //  Control.addVariable("49DetectorRhMat","Rh");  
 //  Control.addVariable("49DetectorRhRadius",10.27);   
 //  Control.addVariable("49DetectorRhLength",0.5); 

 //  Control.addVariable("49Detector0Active",1);   
 //  Control.addVariable("49Detector0XStep",2.5);  
 //  Control.addVariable("49Detector0YStep",31.3);  
 //  Control.addVariable("49Detector0ZStep",-6.6);  

 // Control.addVariable("49Detector1XStep",2.5);  
 //  Control.addVariable("49Detector1YStep",20.0);  
 //  Control.addVariable("49Detector1ZStep",-6.6);  
 //  Control.addVariable("49Detector1XYAngle",0.0);  
 //  Control.addVariable("49Detector1ZAngle",0.0);  

 // Control.addVariable("49Detector2XStep",2.5);  
 //  Control.addVariable("49Detector2YStep",30.0);  
 //  Control.addVariable("49Detector2ZStep",-6.6);  
 //  Control.addVariable("49Detector2XYAngle",0.0);  
 //  Control.addVariable("49Detector2ZAngle",0.0);  
 

 //  // Control.addVariable("49Detector1Active",1);   
 //  // Control.addVariable("49Detector1XStep",2.5);  
 //  // Control.addVariable("49Detector1YStep",50.3);  
 //  // Control.addVariable("49Detector1ZStep",-6.6);  


 //  // Control.addVariable("49DetectorYStep1",5.1);  

 //  Control.addVariable("49DetectorLayerN",1);

 // Rh
  // Control.addVariable("49DetectorDiameterLayer0",10.27);   
  // Control.addVariable("49DetectorWidthLayer0",10.0015); 
  // Control.addVariable("49DetectorMaterialLayer0","Rh");   

  // S cast
  // Control.addVariable("49DetectorDiameterLayer0",5.1);   
  // Control.addVariable("49DetectorWidthLayer0",0.56); 
  // Control.addVariable("49DetectorMaterialLayer0",101);   

  // Cd
  // Control.addVariable("49DetectorDiameterLayer0",1.27);   
  // Control.addVariable("49DetectorWidthLayer0",0.127); //0.0 
  // Control.addVariable("49DetectorMaterialLayer0",106);   

  // Mn
  // Control.addVariable("49DetectorDiameterLayer1",1.27);   
  // Control.addVariable("49DetectorWidthLayer1",0.015); 
  // Control.addVariable("49DetectorMaterialLayer1",104);   

  // S cast

 //Cd
  // Control.addVariable("49DetectorDiameterLayer2",1.27);   
  // Control.addVariable("49DetectorWidthLayer2",0.127); //0.0 
  // Control.addVariable("49DetectorMaterialLayer2","Cadnium");   

  // // Au
  // Control.addVariable("49DetectorDiameterLayer4",1.27);   
  // Control.addVariable("49DetectorWidthLayer4",0.0005); 
  // Control.addVariable("49DetectorMaterialLayer4","Gold");   

  // // S pressed
  // Control.addVariable("49DetectorDiameterLayerX",3.81);   
  // Control.addVariable("49DetectorWidthLayerX",0.241); 
  // Control.addVariable("49DetectorMateriaLayerX","Rh");   




  // Control.addVariable("49DetectorYStep1",3.1);  

  // Control.addVariable("49DetectorYStep2",10.18);  
  // Control.addVariable("49DetectorYStep3",15.96);  
  // Control.addVariable("49DetectorYStep4",21.74);  
  // Control.addVariable("49DetectorYStep5",25.44);  
  // Control.addVariable("49DetectorYStep6",27.44);  
  // Control.addVariable("49DetectorYStep7",29.44);  

  // Control.addVariable("49DetectorYStep8",29.94);  
  // Control.addVariable("49DetectorYStep9",32.94);  
  // Control.addVariable("49DetectorYStep10",34.44);  


  // // Control.addVariable("49Detector0Active",1);   
  // // Control.addVariable("49DetectorXStep",2.5);  
  // // Control.addVariable("49DetectorYStep",50.3);  
  // // Control.addVariable("49DetectorZStepZ1",-6.6);  

  // // Control.addVariable("49Detector1Active",1);   
  // // Control.addVariable("49DetectorXStep",2.5);  
  // // Control.addVariable("49DetectorYStep",55.3);  
  // // Control.addVariable("49DetectorZStepZ1",-6.6);  

  // Control.addVariable("49DetectorActive1",1);   
  // Control.addVariable("49DetectorStepX1",2.5);  
  // Control.addVariable("49DetectorStepY1",5.1);  
  // Control.addVariable("49DetectorStepZ1",-6.6);  

  // Control.addVariable("49DetectorActive2",1);   
  // Control.addVariable("49DetectorStepX2",2.5);  
  // Control.addVariable("49DetectorStepY2",10.18001);  
  // Control.addVariable("49DetectorStepZ2",-6.6);  

  // Control.addVariable("49DetectorActive3",1);   
  // Control.addVariable("49DetectorStepX3",2.5);  
  // Control.addVariable("49DetectorStepY3",15.96);  
  // Control.addVariable("49DetectorStepZ3",-6.6);  

  // Control.addVariable("49DetectorActive4",1);   
  // Control.addVariable("49DetectorStepX4",2.5);  
  // Control.addVariable("49DetectorStepY4",21.74);  
  // Control.addVariable("49DetectorStepZ4",-6.6);  

  // Control.addVariable("49DetectorActive5",1);   
  // Control.addVariable("49DetectorStepX5",2.5);  
  // Control.addVariable("49DetectorStepY5",25.44);  
  // Control.addVariable("49DetectorStepZ5",-6.6);  

  // Control.addVariable("49DetectorActive6",0);   
  // Control.addVariable("49DetectorStepX6",2.5);  
  // Control.addVariable("49DetectorStepY6",27.44);  
  // Control.addVariable("49DetectorStepZ6",-6.6);  

  // Control.addVariable("49DetectorActive7",0);   
  // Control.addVariable("49DetectorStepX7",2.5);  
  // Control.addVariable("49DetectorStepY7",29.44);  
  // Control.addVariable("49DetectorStepZ7",-6.6);  

  // Control.addVariable("49DetectorActive8",0);   
  // Control.addVariable("49DetectorStepX8",2.5);  
  // Control.addVariable("49DetectorStepY8",29.94);  
  // Control.addVariable("49DetectorStepZ8",-6.6);  

  // Control.addVariable("49DetectorActive9",1);   
  // Control.addVariable("49DetectorStepX9",2.5);  
  // Control.addVariable("49DetectorStepY9",32.94);  
  // Control.addVariable("49DetectorStepZ9",-6.6);  

  // Control.addVariable("49DetectorActive10",0);   
  // Control.addVariable("49DetectorStepX10",2.5);  
  // Control.addVariable("49DetectorStepY10",34.44);  
  // Control.addVariable("49DetectorStepZ10",-6.6);  

  // Control.addVariable("49DetectorActive11",0);   
  // Control.addVariable("49DetectorStepX11",2.5);  
  // Control.addVariable("49DetectorStepY11",38.94);  
  // Control.addVariable("49DetectorStepZ11",-6.6);  

  // Control.addVariable("49DetectorActive12",1);   
  // Control.addVariable("49DetectorStepX12",2.5);  
  // Control.addVariable("49DetectorStepY12",40.44);  
  // Control.addVariable("49DetectorStepZ12",-6.6);  

  // Control.addVariable("49DetectorActive13",0);   
  // Control.addVariable("49DetectorStepX13",2.5);  
  // Control.addVariable("49DetectorStepY13",43.44);  
  // Control.addVariable("49DetectorStepZ13",-6.6);  

  // Control.addVariable("49DetectorActive14",1);   
  // Control.addVariable("49DetectorStepX14",2.5);  
  // Control.addVariable("49DetectorStepY14",46.75);  
  // Control.addVariable("49DetectorStepZ14",-6.6);  

  // Control.addVariable("49DetectorActive15",1);   
  // Control.addVariable("49DetectorSetX15",2.5);  
  // Control.addVariable("49DetectorSetY15",52.53);  
  // Control.addVariable("49DetectorSetZ15",-6.6);  

  // Control.addVariable("49DetectorActive16",1);   
  // Control.addVariable("49DetectorSetX16",2.5);  
  // Control.addVariable("49DetectorSetY16",55.73);  
  // Control.addVariable("49DetectorSetZ16",-6.6);  

  // Control.addVariable("49DetectorActive17",1);   
  // Control.addVariable("49DetectorSetX17",2.5);  
  // Control.addVariable("49DetectorSetY17",57.33);  
  // Control.addVariable("49DetectorSetZ17",-6.6);  

  // Control.addVariable("49DetectorActive18",1);   
  // Control.addVariable("49DetectorSetX18",2.5);  
  // Control.addVariable("49DetectorSetY18",59.73);  
  // Control.addVariable("49DetectorSetZ18",-6.6);  

  // Control.addVariable("49DetectorActive19",1);   
  // Control.addVariable("49DetectorSetX19",2.5);  
  // Control.addVariable("49DetectorSetY19",63.73);  
  // Control.addVariable("49DetectorSetZ19",-6.6);  

  // Control.addVariable("49DetectorActive20",1);   
  // Control.addVariable("49DetectorSetX20",2.5);  
  // Control.addVariable("49DetectorSetY20",65.83);  
  // Control.addVariable("49DetectorSetZ20",-6.6);  

  // Control.addVariable("49DetectorActive21",1);   
  // Control.addVariable("49DetectorSetX21",2.5);  
  // Control.addVariable("49DetectorSetY21",71.43);  
  // Control.addVariable("49DetectorOffSetZ21",-6.6);  

  // Control.addVariable("49DetectorActive22",1);   
  // Control.addVariable("49DetectorOffSetX22",2.5);  
  // Control.addVariable("49DetectorOffSetY22",74.53);  
  // Control.addVariable("49DetectorOffSetZ22",-6.6);  



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

  return;
}

}  // NAMESPACE setVariable
