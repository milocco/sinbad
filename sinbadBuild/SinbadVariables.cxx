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

  // general declarations of arrays

  //  std::vector<double> Xarray;
  // double Xarray[];
  // std::vector<double> Zarray;
  //  double Zarray[];






  /////////////////////////////////////////////////////////////////////////////////
  // EXPERIMENT 35 (ASPIS Winfrith Iron 88 Benchmark 
  /////////////////////////////////////////////////////////////////////////////////


  ///////////////////////
  // 35 Shield array

  // define centre
  Control.addVariable("35ShieldXStep",0.0);  
  Control.addVariable("35ShieldYStep",0.0);  
  Control.addVariable("35ShieldZStep",0.0);  
  Control.addVariable("35ShieldXYAngle",0.0);  
  Control.addVariable("35ShieldZAngle",0.0);  
  //number of slabs
  Control.addVariable("35ShieldNSlab",33);
  Control.addVariable("35ShieldWidth",182.9);   
  Control.addVariable("35ShieldHeight",191.0);  
  Control.addVariable("35ShieldThick0",0.74); 
  Control.addVariable("35ShieldMat0","Void"); 
  Control.addVariable("35ShieldThick1",5.10); 
  Control.addVariable("35ShieldMat1","35MildSteel6"); 
  Control.addVariable("35ShieldThick2",0.74);
  Control.addVariable("35ShieldMat2","Void");
  Control.addVariable("35ShieldThick3",5.12); 
  Control.addVariable("35ShieldMat3","35MildSteel6");  
  Control.addVariable("35ShieldThick4",0.74); 
  Control.addVariable("35ShieldMat4","Void");  
  Control.addVariable("35ShieldThick5",5.12); 
  Control.addVariable("35ShieldMat5","35MildSteel6");  
  Control.addVariable("35ShieldThick6",0.74); 
  Control.addVariable("35ShieldMat6","Void");  
  Control.addVariable("35ShieldThick7",5.10); 
  Control.addVariable("35ShieldMat7","35MildSteel6");  
  Control.addVariable("35ShieldThick8",0.74); 
  Control.addVariable("35ShieldMat8","Void");  
  Control.addVariable("35ShieldThick9",5.20); 
  Control.addVariable("35ShieldMat9","35MildSteel6");  
  Control.addVariable("35ShieldThick10",0.74); 
  Control.addVariable("35ShieldMat10","Void");  
  Control.addVariable("35ShieldThick11",5.15); 
  Control.addVariable("35ShieldMat11","35MildSteel6");  
  Control.addVariable("35ShieldThick12",0.74); 
  Control.addVariable("35ShieldMat12","Void");  
  Control.addVariable("35ShieldThick13",5.20); 
  Control.addVariable("35ShieldMat13","35MildSteel6");  
  Control.addVariable("35ShieldThick14",0.74); 
  Control.addVariable("35ShieldMat14","Void");  
  Control.addVariable("35ShieldThick15",5.20); 
  Control.addVariable("35ShieldMat15","35MildSteel6");
  Control.addVariable("35ShieldThick16",0.74); 
  Control.addVariable("35ShieldMat16","Void");  
  Control.addVariable("35ShieldThick17",5.25); 
  Control.addVariable("35ShieldMat17","35MildSteel6");  
  Control.addVariable("35ShieldThick18",0.74); 
  Control.addVariable("35ShieldMat18","Void");  
  Control.addVariable("35ShieldThick19",5.18); 
  Control.addVariable("35ShieldMat19","35MildSteel6");  
  Control.addVariable("35ShieldThick20",0.74); 
  Control.addVariable("35ShieldMat20","Void");  
  Control.addVariable("35ShieldThick21",5.07); 
  Control.addVariable("35ShieldMat21","35MildSteel6");  
  Control.addVariable("35ShieldThick22",0.74); 
  Control.addVariable("35ShieldMat22","Void");  
  Control.addVariable("35ShieldThick23",5.12); 
  Control.addVariable("35ShieldMat23","35MildSteel6");  
  Control.addVariable("35ShieldThick24",0.74); 
  Control.addVariable("35ShieldMat24","Void");  
  Control.addVariable("35ShieldThick25",5.18); 
  Control.addVariable("35ShieldMat25","35MildSteel6");  
  Control.addVariable("35ShieldThick26",0.74); 
  Control.addVariable("35ShieldMat26","Void");  
  Control.addVariable("35ShieldThick27",5.10); 
  Control.addVariable("35ShieldMat27","35MildSteel6");  
  Control.addVariable("35ShieldThick28",5.25); 
  Control.addVariable("35ShieldMat28","35MildSteel6");  
  Control.addVariable("35ShieldThick29",5.00); 
  Control.addVariable("35ShieldMat29","35MildSteel6");  
  Control.addVariable("35ShieldThick30",4.97); 
  Control.addVariable("35ShieldMat30","35MildSteel6");  
  Control.addVariable("35ShieldThick31",22.41); 
  Control.addVariable("35ShieldMat31","35StainlessSteel");  
  Control.addVariable("35ShieldThick32",100); 
  Control.addVariable("35ShieldMat32","35Concrete");  

  /////////////////////////////////////////////////
  // 35 NestorSide (The array between Nestor reactor and fission plate)

  // the X and Z Steps are such that the geometry centre is at the nuclear centre
  Control.addVariable("35NestorSideXStep",2.55);
  // the Y step is set so that the fission plate centre is at the origin  
  Control.addVariable("35NestorSideYStep",-21.25);  
  Control.addVariable("35NestorSideZStep",-6.6);  
  Control.addVariable("35NestorSideXYAngle",0.0);  
  Control.addVariable("35NestorSideZAngle",0.0);  
  Control.addVariable("35NestorSideWidth",182.9);   
  Control.addVariable("35NestorSideHeight",191.0);  
  // number of slabs
  Control.addVariable("35NestorSideNSlab",4);
  Control.addVariable("35NestorSideThick0",3.18); 
  Control.addVariable("35NestorSideMat0","35MildSteel1");  
  Control.addVariable("35NestorSideWindowRadius",56.06); 
  Control.addVariable("35NestorSideWindowMat","35Aluminium2"); 
  Control.addVariable("35NestorSideThick1",0.52); 
  Control.addVariable("35NestorSideMat1","Void"); 
  Control.addVariable("35NestorSideThick2",15.0); 
  Control.addVariable("35NestorSideMat2","35Graphite");  
  Control.addVariable("35NestorSideThick3",1.1); 
  Control.addVariable("35NestorSideMat3","Void");  


  ////////////////////////////////////////////////////
  // 35 Fission Plate

  Control.addVariable("35FissionPlateXStep",0.0);  
  Control.addVariable("35FissionPlateYStep",0.0);   
  Control.addVariable("35FissionPlateZStep",0.0);  
  // simply report here the shift in Nestor Side
  Control.addVariable("35FissionPlateXNucCentre",2.55);   
  Control.addVariable("35FissionPlateZNucCentre",-6.6);   
  Control.addVariable("35FissionPlateXYAngle",0.0);   
  Control.addVariable("35FissionPlateZAngle",0.0);   

  //fission plate layers  
  Control.addVariable("35FissionPlateNSlab",6);
  //correct but to avoid geom error it is the same as other slabs
  Control.addVariable("35FissionPlateHeight",191.);  
  Control.addVariable("35FissionPlateWidth",182.9); 
  Control.addVariable("35FissionPlateThick0",1.2);
  Control.addVariable("35FissionPlateMat0","35Aluminium5");   
  Control.addVariable("35FissionPlateThick1",0.1); 
  Control.addVariable("35FissionPlateMat1","Void");   
  Control.addVariable("35FissionPlateThick2",0.1); 
  Control.addVariable("35FissionPlateMat2","35Aluminium5");   
  Control.addVariable("35FissionPlateThick3",0.2); 
  Control.addVariable("35FissionPlateMat3","35Fuel");   
  Control.addVariable("35FissionPlateThick4",0.1); 
  Control.addVariable("35FissionPlateMat4","35Aluminium5");   
  Control.addVariable("35FissionPlateThick5",1.2); 
  Control.addVariable("35FissionPlateMat5","35Aluminium5");   
  //fuel plate index
  Control.addVariable("35FissionPlateDivIndex0",3);
  //////////////////////////////////////////////////////////////
  // imports of fission source specificationsfrom SINBAD     
  //35 X-Z sectioning of fuel plate

  // already set to be zero in the nucleaar centre

  double Xarray35[16]={-52.25, -49.08, -45.92, -39.58, -36.42, -30.08, -14.25, -4.75, 4.75, 14.25, 30.08, 36.42, 39.58, 45.92, 49.08, 52.25};
  // original from sinbad
 // {-49.75, -46.58, -43.32, -37.08, -33.92, -27.58, -11.75, -2.25,  7.25, 16.75, 32.58, 38.92, 42.08, 48.42, 51.58, 54.75 };
  double Zarray35[16]={ -51.44, -47.63, -40.64, -35.56, -31.75, -19.69, -15.88,  -5.29,  5.29, 15.88, 19.69, 31.75, 35.56, 40.64, 47.63, 51.44};

  int nx=sizeof(Xarray35)/sizeof(double);
  int nz=sizeof(Zarray35)/sizeof(double);
  Control.addVariable("35FissionPlateNXSpace",nx);   
  Control.addVariable("35FissionPlateNZSpace",nz);   

  //35 source specification
  double fissionSource35 [15] [15] = {
 {  0  ,   0  ,   0  ,   0  ,   0  ,   0  , 2.973, 2.994, 2.865,   0  ,   0  ,   0  ,   0  ,   0  ,   0       },
 {  0  ,   0  ,   0  ,   0  ,   0  , 3.173, 3.496, 3.537, 3.404, 2.975,   0  ,   0  ,   0  ,   0  ,   0       },
 {  0  ,   0  ,   0  ,   0  , 3.176, 3.711, 4.088, 4.149, 4.015, 3.529, 2.890,   0  ,   0  ,   0  ,   0       },
 {  0  ,   0  ,   0  , 3.186, 3.500, 4.092, 4.514, 4.587, 4.446, 3.925, 3.240, 2.886,   0  ,   0  ,   0       },
 {  0  ,   0  , 3.249, 3.635, 3.999, 4.696, 5.197, 5.286, 5.130, 4.555, 3.807, 3.422, 3.009,   0  ,   0       },
 {  0  , 3.150, 3.575, 4.003, 4.412, 5.202, 5.770, 5.870, 5.699, 5.080, 4.282, 3.873, 3.431, 2.970,   0       },
 {  3.040, 3.322, 3.769, 4.223, 4.660, 5.505, 6.110, 6.215, 6.034, 5.387, 4.559, 4.133, 3.673, 3.188, 2.850   },
 {  3.132, 3.427, 3.893, 4.364, 4.815, 5.684, 6.304, 6.412, 6.227, 5.563, 4.710, 4.270, 3.792, 3.287, 2.932   },
 {  3.026, 3.325, 3.784, 4.239, 4.669, 5.491, 6.079, 6.183, 6.009, 5.364, 4.523, 4.084, 3.607, 3.103, 2.751   },
 {  0  , 3.136, 3.574, 4.001, 4.400, 5.157, 5.701, 5.802, 5.643, 5.031, 4.221, 3.795, 3.331, 2.843,   0       },
 {  0  ,   0  , 3.182, 3.562, 3.912, 4.572, 5.053, 5.149, 5.013, 4.461, 3.713, 3.317, 2.887,   0  ,   0       },
 {  0  ,   0  ,   0  , 3.004, 3.299, 3.855, 4.267, 4.357, 4.247, 3.766, 3.101, 2.748,   0  ,   0  ,   0       },
 {  0  ,   0  ,   0  ,   0  , 2.896, 3.396, 3.770, 3.855, 3.758, 3.320, 2.712,   0  ,   0  ,   0  ,   0       },
 {  0  ,   0  ,   0  ,   0  ,   0  , 2.745, 3.072, 3.150, 3.067, 2.685,   0  ,   0  ,   0  ,   0  ,   0       },
 {  0  ,   0  ,   0  ,   0  ,   0  ,   0  , 2.458, 2.525, 2.448,   0  ,   0  ,   0  ,   0  ,   0  ,   0       }
 } ; 

  //set CombLayer variables and keys for fission plate sectioning and source
  for(int i=0;i<nx;i++)
    {
     const std::string baseKey=StrFunc::makeString("35FissionPlateXPt",i);
     Control.addVariable(baseKey,Xarray35[i]);  
    }
  for(int i=0;i<nz;i++)
    {
     const std::string baseKey=StrFunc::makeString("35FissionPlateZPt",i);
     Control.addVariable(baseKey,Zarray35[i]);  
    }

  for(size_t ix=0;ix<nx-1;ix++)
   {
    std::string SX=StrFunc::makeString("35FissionPlateSourceX",ix);
    for(size_t iz=0;iz<nz-1;iz++)
     {
      std::string SXZ=StrFunc::makeString(SX+"Z",iz);
      Control.addVariable(SXZ,fissionSource35[iz][ix]);
     }
   }


  Control.addVariable("35FissionPlateMatInL0","35Fuel");   
  Control.addVariable("35FissionPlateMatOutL0","35Aluminium5");   
  Control.addVariable("35FissionPlateMatTempL0",300.0);   
  Control.addVariable("35FissionPlateMatL1","35Aluminium5");   
  Control.addVariable("35FissionPlateMatTempL1",300.0);   

 
    //////////////////////////////////////////////////////////////
  // 35 DETECTORS



  // detectors take the origin of the shield: get nuclear center by counter-traslation
  Control.addVariable("35DetOffsetX",0.0);  
  Control.addVariable("35DetOffsetZ",0.0);
  // possible detector positions along Y axis 
  Control.addVariable("35DetNY",14);    

  Control.addVariable("35DetStepX",-2.55);  
  Control.addVariable("35DetStepZ",6.6);  


  // detector positions are given in Sinbad as cumulative iron thicknesses;
  // here these are summed with the void layers in between (0.74 cm each)
  // monitor A2
  Control.addVariable("35StepY0",0.0+0.74*1);  
  // pos A3  
  Control.addVariable("35StepY1",5.1+0.74*2);  
  // pos A4
  Control.addVariable("35StepY2",10.22+0.74*3);  
  // pos A5
  Control.addVariable("35StepY3",15.34+0.74*4);
  // pos A6  
  Control.addVariable("35StepY4",20.44+0.74*5);
  // pos A7  
  Control.addVariable("35StepY5",25.64+0.74*6);
  // pos A8
  Control.addVariable("35StepY6",30.79+0.74*7);  
  // pos A9  
  Control.addVariable("35StepY7",35.99+0.74*8);  
  // pos A10
  Control.addVariable("35StepY8",41.19+0.74*9);  
  // pos A11
  Control.addVariable("35StepY9",46.44+0.74*10);
  // pos A12
  Control.addVariable("35StepY10",51.62+0.74*11);
  // pos A13  
  Control.addVariable("35StepY11",56.69+0.74*12);
  // pos A14  
  Control.addVariable("35StepY12",61.81+0.74*13);
  // pos A15  
  Control.addVariable("35StepY13",66.99+0.74*14);


  // possible detectors for vertical scans
  Control.addVariable("35DetNZ",0);    

 
  //Sulphur cast pellet
  Control.addVariable("35SMat","35S");  
  Control.addVariable("35SDiam",5.10);   
  Control.addVariable("35SThick",0.56);
  // Sulphur pressed pellet (monitor)
  Control.addVariable("35SMatM","35Spressed");  
  Control.addVariable("35SDiamM",3.81);   
  Control.addVariable("35SThickM",0.241);

  // active detector positions along Y axis
  Control.addVariable("35SActiveY0",1);   
  Control.addVariable("35SActiveY1",1);   
  Control.addVariable("35SActiveY2",1);   
  Control.addVariable("35SActiveY3",1);   
  Control.addVariable("35SActiveY4",1);   
  Control.addVariable("35SActiveY5",1);   
  Control.addVariable("35SActiveY6",1);   
  Control.addVariable("35SActiveY7",1);   
  Control.addVariable("35SActiveY8",1);   
  Control.addVariable("35SActiveY9",1);   
  Control.addVariable("35SActiveY10",1);   
  Control.addVariable("35SActiveY11",1);   
  Control.addVariable("35SActiveY12",1);   
  Control.addVariable("35SActiveY13",1);   
  // number of vertical scans
  Control.addVariable("35SVscanNY",0);           


  // Rhodium
  Control.addVariable("35RhMat","35Rh");  
  Control.addVariable("35RhDiam",1.27);   
  Control.addVariable("35RhThick",0.0015); 
  // Rh positions are the nominal ones; in case of detector stack these are arranged consequently
  // active detector positions along Y axis
  Control.addVariable("35RhActiveY0",1);   
  Control.addVariable("35RhActiveY1",1);   
  Control.addVariable("35RhActiveY2",1);   
  Control.addVariable("35RhActiveY3",1);   
  Control.addVariable("35RhActiveY4",1);   
  Control.addVariable("35RhActiveY5",1);   
  Control.addVariable("35RhActiveY6",1);   
  Control.addVariable("35RhActiveY7",1);   
  Control.addVariable("35RhActiveY8",1);   
  Control.addVariable("35RhActiveY9",1);   
  Control.addVariable("35RhActiveY10",1);   
  Control.addVariable("35RhActiveY11",1);   
  Control.addVariable("35RhActiveY12",1);   
  Control.addVariable("35RhActiveY13",0);   
  // number of vertical scans
  Control.addVariable("35RhVscanNY",0);           





  // Al foil
  Control.addVariable("35AlMat","35AlDet");  
  Control.addVariable("35AlDiam",5.0);   
  Control.addVariable("35AlThick",0.31); 
  // Al positions are the nominal ones; in case of detector stack these are arranged consequently
  // active detector positions along Y axis
  Control.addVariable("35AlActiveY0",0);   
  Control.addVariable("35AlActiveY1",1);   
  Control.addVariable("35AlActiveY2",1);   
  Control.addVariable("35AlActiveY3",1);   
  Control.addVariable("35AlActiveY4",1);   
  Control.addVariable("35AlActiveY5",1);   
  Control.addVariable("35AlActiveY6",0);   
  Control.addVariable("35AlActiveY7",0);   
  Control.addVariable("35AlActiveY8",0);   
  Control.addVariable("35AlActiveY9",0);   
  Control.addVariable("35AlActiveY10",0);   
  Control.addVariable("35AlActiveY11",0);   
  Control.addVariable("35AlActiveY12",0);   
  Control.addVariable("35AlActiveY13",0);   
  // number of vertical scans
  Control.addVariable("35AlVscanNY",0);           




  // In
  Control.addVariable("35InMat","35In");  
  Control.addVariable("35InDiam",3.8);   
  Control.addVariable("35InThick",0.163); 
  // In positions are the nominal ones; in case of detector stack these are arranged consequently
  // active detector positions along Y axis
  Control.addVariable("35InActiveY0",1);   
  Control.addVariable("35InActiveY1",1);   
  Control.addVariable("35InActiveY2",1);   
  Control.addVariable("35InActiveY3",1);   
  Control.addVariable("35InActiveY4",1);   
  Control.addVariable("35InActiveY5",1);   
  Control.addVariable("35InActiveY6",1);   
  Control.addVariable("35InActiveY7",1);   
  Control.addVariable("35InActiveY8",1);   
  Control.addVariable("35InActiveY9",1);   
  Control.addVariable("35InActiveY10",0);   
  Control.addVariable("35InActiveY11",0);   
  Control.addVariable("35InActiveY12",0);   
  Control.addVariable("35InActiveY13",0);   
  // number of vertical scans
  Control.addVariable("35InVscanNY",0);           





  // Gold
  Control.addVariable("35AuMat","35Au");  
  Control.addVariable("35AuDiam",1.27);   
  Control.addVariable("35AuThick",0.005);
  // Control.addVariable("35AuThick",0.5);
  // active detectors along axial direction
  Control.addVariable("35AuActiveY0",1);   
  Control.addVariable("35AuActiveY1",1);   
  Control.addVariable("35AuActiveY2",1);   
  Control.addVariable("35AuActiveY3",1);   
  Control.addVariable("35AuActiveY4",1);   
  Control.addVariable("35AuActiveY5",1);   
  Control.addVariable("35AuActiveY6",1);   
  Control.addVariable("35AuActiveY7",1); 
  // deactivate next if performing axial and vertical scan at the same time  
  Control.addVariable("35AuActiveY8",1);   
  Control.addVariable("35AuActiveY9",1);   
  Control.addVariable("35AuActiveY10",1);   
  Control.addVariable("35AuActiveY11",1);   
  Control.addVariable("35AuActiveY12",1);   
  Control.addVariable("35AuActiveY13",1);   
  // number of vertical scans
  Control.addVariable("35AuVscanNY",0);           


  // Cadmium front cover
  Control.addVariable("35FCdMat","35Cd");  
  Control.addVariable("35FCdDiam",1.27);   
  Control.addVariable("35FCdThick",0.127);
  // Control.addVariable("35FCdThick",0.0635);
  // active detectors along axial direction
  Control.addVariable("35FCdActiveY0",1);   
  Control.addVariable("35FCdActiveY1",1);   
  Control.addVariable("35FCdActiveY2",1);   
  Control.addVariable("35FCdActiveY3",1);   
  Control.addVariable("35FCdActiveY4",1);   
  Control.addVariable("35FCdActiveY5",1);   
  Control.addVariable("35FCdActiveY6",1);   
  Control.addVariable("35FCdActiveY7",1); 
  // deactivate next if performing axial and vertical scan at the same time  
  Control.addVariable("35FCdActiveY8",1);   
  Control.addVariable("35FCdActiveY9",1);   
  Control.addVariable("35FCdActiveY10",1);   
  Control.addVariable("35FCdActiveY11",1);   
  Control.addVariable("35FCdActiveY12",1);   
  Control.addVariable("35FCdActiveY13",1);   
  // number of vertical scans
  Control.addVariable("35FCdVscanNY",0);           


  // Cadmium back cover
  Control.addVariable("35BCdMat","35Cd");  
  Control.addVariable("35BCdDiam",1.27);   
  //  Control.addVariable("35BCdThick",0.127);
  Control.addVariable("35BCdThick",0.0635);

  // active detectors along axial direction
  Control.addVariable("35BCdActiveY0",1);   
  Control.addVariable("35BCdActiveY1",1);   
  Control.addVariable("35BCdActiveY2",1);   
  Control.addVariable("35BCdActiveY3",1);   
  Control.addVariable("35BCdActiveY4",1);   
  Control.addVariable("35BCdActiveY5",1);   
  Control.addVariable("35BCdActiveY6",1);   
  Control.addVariable("35BCdActiveY7",1); 
  // deactivate next if performing axial and vertical scan at the same time  
  Control.addVariable("35BCdActiveY8",1);   
  Control.addVariable("35BCdActiveY9",1);   
  Control.addVariable("35BCdActiveY10",1);   
  Control.addVariable("35BCdActiveY11",1);   
  Control.addVariable("35BCdActiveY12",1);   
  Control.addVariable("35BCdActiveY13",1);   
  // number of vertical scans
  Control.addVariable("35BCdVscanNY",0);           



  /////////////////////////////////////////////////////////////////////////////////
  // EXPERIMENT 36 (ASPIS Winfrith Graphite Benchmark Experiment )
  /////////////////////////////////////////////////////////////////////////////////

  // define centre
  Control.addVariable("36ShieldXStep",0.0);  
  Control.addVariable("36ShieldYStep",0.0);  
  Control.addVariable("36ShieldZStep",0.0);  
  Control.addVariable("36ShieldXYAngle",0.0);  
  Control.addVariable("36ShieldZAngle",0.0);  
  //number of slabs

  Control.addVariable("36ShieldNSlab",5);
  //dummy variables, rewritten afterwards
  Control.addVariable("36ShieldWidth",180.34);   
  Control.addVariable("36ShieldHeight",180.34);
  

  // first al slab   
  // Control.addVariable("36ShieldThick0",1.27);
  // Control.addVariable("36ShieldCutN0",1);
  // Control.addVariable("36ShieldCylDiam0",0);
  // Control.addVariable("36ShieldCylMat0","36Aluminium");
  // Control.addVariable("36ShieldInnerWidth0",0);
  // Control.addVariable("36ShieldInnerHeight0",0);
  // Control.addVariable("36ShieldInnerMat0","36Aluminium");
  // Control.addVariable("36ShieldMidWidth0",0);
  // Control.addVariable("36ShieldMidHeight0",0);
  // Control.addVariable("36ShieldMidMat0","36Aluminium");
  // Control.addVariable("36ShieldOuterWidth0",180.34);
  // Control.addVariable("36ShieldOuterHeight0",180.34);
  // Control.addVariable("36ShieldOuterMat0","36Aluminium");

  // Control.addVariable("36Shield0SlotN",0);
  // Control.addVariable("36Shield0SlotSide",0.0);
  // Control.addVariable("36Shield0SlotThick",0.0);
  // Control.addVariable("36Shield0SlotAngle",0.0);

  //special slabs with inner cylinder,outer regions for variance reduction and slots at 20 cm steps
  Control.addVariable("36ShieldThick0",20.25);
  // inner body
  Control.addVariable("36ShieldCutN0",4);
  Control.addVariable("36ShieldCylDiam0",12.90);
  Control.addVariable("36ShieldCylMat0","36Graphite2");
  Control.addVariable("36ShieldInnerWidth0",17.78);
  Control.addVariable("36ShieldInnerHeight0",15.58);
  Control.addVariable("36ShieldInnerMat0","36Graphite3");
  Control.addVariable("36ShieldMidWidth0",47.5);
  Control.addVariable("36ShieldMidHeight0",68.5);
  Control.addVariable("36ShieldMidMat0","36Graphite1");
  Control.addVariable("36ShieldOuterWidth0",180.34);
  Control.addVariable("36ShieldOuterHeight0",180.34);
  Control.addVariable("36ShieldOuterMat0","36Graphite1");
  // slots included in first chunk
  Control.addVariable("36Shield0SlotN",10);
		      //10);
  Control.addVariable("36Shield0SlotSide",3);
  Control.addVariable("36Shield0SlotThick",0.5);
  Control.addVariable("36Shield0SlotAngle",0.0);

  // Y is at slot centre from shield start, they double up (by X/Z split) and are relative to previous slot couple
  Control.addVariable("36Shield0SlotY0",0.25);
  Control.addVariable("36Shield0SlotX0",-4.95);
  Control.addVariable("36Shield0SlotZ0",0.0);
  Control.addVariable("36Shield0SlotMat0","Void");
  Control.addVariable("36Shield0SlotY1",0.25);
  Control.addVariable("36Shield0SlotX1",4.95);
  Control.addVariable("36Shield0SlotZ1",0.0);
  Control.addVariable("36Shield0SlotMat1","Void");
  Control.addVariable("36Shield0SlotY2",4.75);
  Control.addVariable("36Shield0SlotX2",0.0);
  Control.addVariable("36Shield0SlotZ2",-4.95);
  Control.addVariable("36Shield0SlotMat2","Void");
  Control.addVariable("36Shield0SlotX3",0.0);
  Control.addVariable("36Shield0SlotY3",4.75);
  Control.addVariable("36Shield0SlotZ3",4.95);
  Control.addVariable("36Shield0SlotMat3","Void");
  Control.addVariable("36Shield0SlotY4",5.);
  Control.addVariable("36Shield0SlotX4",-4.95);
  Control.addVariable("36Shield0SlotZ4",0.0);
  Control.addVariable("36Shield0SlotMat4","Void");
  Control.addVariable("36Shield0SlotY5",5.);
  Control.addVariable("36Shield0SlotX5",4.95);
  Control.addVariable("36Shield0SlotZ5",0.0);
  Control.addVariable("36Shield0SlotMat5","Void");
  Control.addVariable("36Shield0SlotY6",5.);
  Control.addVariable("36Shield0SlotX6",0.0);
  Control.addVariable("36Shield0SlotZ6",-4.95);
  Control.addVariable("36Shield0SlotMat6","Void");
  Control.addVariable("36Shield0SlotX7",0.0);
  Control.addVariable("36Shield0SlotY7",5.);
  Control.addVariable("36Shield0SlotZ7",4.95);
  Control.addVariable("36Shield0SlotMat7","Void");
  Control.addVariable("36Shield0SlotY8",5.);
  Control.addVariable("36Shield0SlotX8",-4.95);
  Control.addVariable("36Shield0SlotZ8",0.0);
  Control.addVariable("36Shield0SlotMat8","Void");
  Control.addVariable("36Shield0SlotX9",4.95);
  Control.addVariable("36Shield0SlotY9",5.);
  Control.addVariable("36Shield0SlotZ9",0.0);
  Control.addVariable("36Shield0SlotMat9","Void");
  //second chunk
  Control.addVariable("36ShieldThick1",20);
  Control.addVariable("36ShieldCutN1",4);
  Control.addVariable("36ShieldCylDiam1",12.90);
  Control.addVariable("36ShieldCylMat1","36Graphite2");
  Control.addVariable("36ShieldInnerWidth1",17.78);
  Control.addVariable("36ShieldInnerHeight1",15.58);
  Control.addVariable("36ShieldInnerMat1","36Graphite3");
  Control.addVariable("36ShieldMidWidth1",47.5);
  Control.addVariable("36ShieldMidHeight1",68.5);
  Control.addVariable("36ShieldMidMat1","36Graphite1");
  Control.addVariable("36ShieldOuterWidth1",180.34);
  Control.addVariable("36ShieldOuterHeight1",180.34);
  Control.addVariable("36ShieldOuterMat1","36Graphite1");
  // slots included in chunk
  Control.addVariable("36Shield1SlotN",8);
		      //8);
  Control.addVariable("36Shield1SlotSide",3);
  Control.addVariable("36Shield1SlotThick",0.5);
  Control.addVariable("36Shield1SlotAngle",0.0);
  // 
  Control.addVariable("36Shield1SlotY0",5);
  Control.addVariable("36Shield1SlotX0",0.0);
  Control.addVariable("36Shield1SlotZ0",-4.95);
  Control.addVariable("36Shield1SlotMat0","Void");
  Control.addVariable("36Shield1SlotX1",0.0);
  Control.addVariable("36Shield1SlotY1",5);
  Control.addVariable("36Shield1SlotZ1",4.95);
  Control.addVariable("36Shield1SlotMat1","Void");
  Control.addVariable("36Shield1SlotY2",5.);
  Control.addVariable("36Shield1SlotX2",-4.95);
  Control.addVariable("36Shield1SlotZ2",0.0);
  Control.addVariable("36Shield1SlotMat2","Void");
  Control.addVariable("36Shield1SlotY3",5.);
  Control.addVariable("36Shield1SlotX3",4.95);
  Control.addVariable("36Shield1SlotZ3",0.0);
  Control.addVariable("36Shield1SlotMat3","Void");
  Control.addVariable("36Shield1SlotY4",5.);
  Control.addVariable("36Shield1SlotX4",0.0);
  Control.addVariable("36Shield1SlotZ4",-4.95);
  Control.addVariable("36Shield1SlotMat4","Void");
  Control.addVariable("36Shield1SlotX5",0.0);
  Control.addVariable("36Shield1SlotY5",5.);
  Control.addVariable("36Shield1SlotZ5",4.95);
  Control.addVariable("36Shield1SlotMat5","Void");
  Control.addVariable("36Shield1SlotY6",5.);
  Control.addVariable("36Shield1SlotX6",-4.95);
  Control.addVariable("36Shield1SlotZ6",0.0);
  Control.addVariable("36Shield1SlotMat6","Void");
  Control.addVariable("36Shield1SlotX7",4.95);
  Control.addVariable("36Shield1SlotY7",5.);
  Control.addVariable("36Shield1SlotZ7",0.0);
  Control.addVariable("36Shield1SlotMat7","Void");

  //third chunk
  Control.addVariable("36ShieldThick2",40);
  Control.addVariable("36ShieldCutN2",4);
  Control.addVariable("36ShieldCylDiam2",12.90);
  Control.addVariable("36ShieldCylMat2","36Graphite2");
  Control.addVariable("36ShieldInnerWidth2",17.78);
  Control.addVariable("36ShieldInnerHeight2",15.58);
  Control.addVariable("36ShieldInnerMat2","36Graphite3");
  Control.addVariable("36ShieldMidWidth2",47.5);
  Control.addVariable("36ShieldMidHeight2",68.5);
  Control.addVariable("36ShieldMidMat2","36Graphite1");
  Control.addVariable("36ShieldOuterWidth2",180.34);
  Control.addVariable("36ShieldOuterHeight2",180.34);
  Control.addVariable("36ShieldOuterMat2","36Graphite1");

  Control.addVariable("36Shield2SlotN",12);
		      //12);
  Control.addVariable("36Shield2SlotSide",3);
  Control.addVariable("36Shield2SlotThick",0.5);
  Control.addVariable("36Shield2SlotAngle",0.0);
  // 
  Control.addVariable("36Shield2SlotY0",5);
  Control.addVariable("36Shield2SlotX0",0.0);
  Control.addVariable("36Shield2SlotZ0",-4.95);
  Control.addVariable("36Shield2SlotMat0","Void");
  Control.addVariable("36Shield2SlotX1",0.0);
  Control.addVariable("36Shield2SlotY1",5);
  Control.addVariable("36Shield2SlotZ1",4.95);
  Control.addVariable("36Shield2SlotMat1","Void");
  Control.addVariable("36Shield2SlotY2",5.);
  Control.addVariable("36Shield2SlotX2",-4.95);
  Control.addVariable("36Shield2SlotZ2",0.0);
  Control.addVariable("36Shield2SlotMat2","Void");
  Control.addVariable("36Shield2SlotY3",5.);
  Control.addVariable("36Shield2SlotX3",4.95);
  Control.addVariable("36Shield2SlotZ3",0.0);
  Control.addVariable("36Shield2SlotMat3","Void");
  Control.addVariable("36Shield2SlotY4",5.);
  Control.addVariable("36Shield2SlotX4",0.0);
  Control.addVariable("36Shield2SlotZ4",-4.95);
  Control.addVariable("36Shield2SlotMat4","Void");
  Control.addVariable("36Shield2SlotX5",0.0);
  Control.addVariable("36Shield2SlotY5",5.);
  Control.addVariable("36Shield2SlotZ5",4.95);
  Control.addVariable("36Shield2SlotMat5","Void");
  Control.addVariable("36Shield2SlotY6",5.);
  Control.addVariable("36Shield2SlotX6",-4.95);
  Control.addVariable("36Shield2SlotZ6",0.0);
  Control.addVariable("36Shield2SlotMat6","Void");
  Control.addVariable("36Shield2SlotX7",4.95);
  Control.addVariable("36Shield2SlotY7",5.);
  Control.addVariable("36Shield2SlotZ7",0.0);
  Control.addVariable("36Shield2SlotMat7","Void");
  Control.addVariable("36Shield2SlotY8",5);
  Control.addVariable("36Shield2SlotX8",0.0);
  Control.addVariable("36Shield2SlotZ8",-4.95);
  Control.addVariable("36Shield2SlotMat8","Void");
  Control.addVariable("36Shield2SlotX9",0.0);
  Control.addVariable("36Shield2SlotY9",5);
  Control.addVariable("36Shield2SlotZ9",4.95);
  Control.addVariable("36Shield2SlotMat9","Void");
  Control.addVariable("36Shield2SlotY10",5.);
  Control.addVariable("36Shield2SlotX10",-4.95);
  Control.addVariable("36Shield2SlotZ10",0.0);
  Control.addVariable("36Shield2SlotMat10","Void");
  Control.addVariable("36Shield2SlotY11",5.);
  Control.addVariable("36Shield2SlotX11",4.95);
  Control.addVariable("36Shield2SlotZ11",0.0);
  Control.addVariable("36Shield2SlotMat11","Void");

  //forth chunk without any slot
  Control.addVariable("36ShieldThick3",67.07);

  Control.addVariable("36ShieldCutN3",4);
  Control.addVariable("36ShieldCylDiam3",12.90);
  Control.addVariable("36ShieldCylMat3","36Graphite2");
  Control.addVariable("36ShieldInnerWidth3",17.78);
  Control.addVariable("36ShieldInnerHeight3",15.58);
  Control.addVariable("36ShieldInnerMat3","36Graphite3");
  Control.addVariable("36ShieldMidWidth3",47.5);
  Control.addVariable("36ShieldMidHeight3",68.5);
  Control.addVariable("36ShieldMidMat3","36Graphite1");
  Control.addVariable("36ShieldOuterWidth3",180.34);
  Control.addVariable("36ShieldOuterHeight3",180.34);
  Control.addVariable("36ShieldOuterMat3","36Graphite1");

  Control.addVariable("36Shield3SlotN",0);
  Control.addVariable("36Shield3SlotSide",0.0);
  Control.addVariable("36Shield3SlotThick",0.0);
  Control.addVariable("36Shield3SlotAngle",0.0);



  //fifth chunk - end slab
  Control.addVariable("36ShieldThick4",30);
  Control.addVariable("36ShieldCutN4",1);
  Control.addVariable("36ShieldCylDiam4",0);
  Control.addVariable("36ShieldCylMat4","36Graphite1");
  Control.addVariable("36ShieldInnerWidth4",0);
  Control.addVariable("36ShieldInnerHeight4",0);
  Control.addVariable("36ShieldInnerMat4","36Graphite1");
  Control.addVariable("36ShieldMidWidth4",0);
  Control.addVariable("36ShieldMidHeight4",0);
  Control.addVariable("36ShieldMidMat4","36Graphite1");
  Control.addVariable("36ShieldOuterWidth4",180.34);
  Control.addVariable("36ShieldOuterHeight4",180.34);
  Control.addVariable("36ShieldOuterMat4","36Graphite1");

  Control.addVariable("36Shield4SlotN",0);
  Control.addVariable("36Shield4SlotSide",0.0);
  Control.addVariable("36Shield4SlotThick",0.0);
  Control.addVariable("36Shield4SlotAngle",0.0);

  // nestor side

  Control.addVariable("36NestorSideXStep",0);
  // the Y step is set so that the fission plate centre is at the origin 
  // that is:cumulative nestor side+fission plate thickness/2 
  Control.addVariable("36NestorSideYStep",-20.78);  
  Control.addVariable("36NestorSideZStep",0);  
  Control.addVariable("36NestorSideXYAngle",0.0);  
  Control.addVariable("36NestorSideZAngle",0.0);  
  Control.addVariable("36NestorSideWidth",180.34);   
  Control.addVariable("36NestorSideHeight",180.34);  
  // number of slabs
  Control.addVariable("36NestorSideNSlab",3);

  Control.addVariable("36NestorSideThick0",3.18); 
  Control.addVariable("36NestorSideMat0","36MildSteel");  
  Control.addVariable("36NestorSideWindowRadius",56.06); 
  Control.addVariable("36NestorSideWindowMat","36Aluminium"); 
  Control.addVariable("36NestorSideThick1",15); 
  Control.addVariable("36NestorSideMat1","36Graphite3");  
  Control.addVariable("36NestorSideThick2",1.9); 
  Control.addVariable("36NestorSideMat2","Void");  
 


  ////////////////////////////////////////////////////
  // 36 Fission Plate

  Control.addVariable("36FissionPlateXStep",0.0);  
  Control.addVariable("36FissionPlateYStep",0.0);   
  Control.addVariable("36FissionPlateZStep",0.0);  
  // simply report here the shift in Nestor Side
  Control.addVariable("36FissionPlateXNucCentre",0);   
  Control.addVariable("36FissionPlateZNucCentre",0);   
  Control.addVariable("36FissionPlateXYAngle",0.0);   
  Control.addVariable("36FissionPlateZAngle",0.0);   

  //fission plate layers  
  Control.addVariable("36FissionPlateNSlab",6);
  //correct but to avoid geom error it is the same as other slabs
  Control.addVariable("36FissionPlateHeight",180.34);  
  Control.addVariable("36FissionPlateWidth",180.34); 
  Control.addVariable("36FissionPlateThick0",0.4);
  Control.addVariable("36FissionPlateMat0","36Aluminium");   
  Control.addVariable("36FissionPlateThick1",0.1); 
  Control.addVariable("36FissionPlateMat1","Void");   
  Control.addVariable("36FissionPlateThick2",0.4); 
  Control.addVariable("36FissionPlateMat2","36Fuel");   
  Control.addVariable("36FissionPlateThick3",0.1); 
  Control.addVariable("36FissionPlateMat3","Void");   
  Control.addVariable("36FissionPlateThick4",0.4); 
  Control.addVariable("36FissionPlateMat4","36Aluminium");

  Control.addVariable("36FissionPlateThick5",1.27); 
  Control.addVariable("36FissionPlateMat5","36Aluminium");

  //fuel plate index
  Control.addVariable("36FissionPlateDivIndex0",2);
  //////////////////////////////////////////////////////////////
  // imports of fission source specificationsfrom SINBAD     
  //36 X-Z sectioning of fuel plate

  // already set to be zero in the nuclear centre

  double Xarray36[6]= { -20.10, -12.10, -4.10, 4.10, 12.10, 20.10 };
  double Zarray36[12]={-31.75, -26.32, -20.58, -15.44, -10.00, -3.33, 3.33, 10.00, 15.44, 20.58, 26.32, 31.75};


  nx=sizeof(Xarray36)/sizeof(double);
  nz=sizeof(Zarray36)/sizeof(double);
  Control.addVariable("36FissionPlateNXSpace",nx);   
  Control.addVariable("36FissionPlateNZSpace",nz);   

  //36 source specification
  double fissionSource36[11][5]={            
    {  4.884E+07, 4.734E+07,  4.705E+07, 4.695E+07, 5.055E+07 },           
    {  4.849E+07, 4.533E+07,  4.505E+07, 4.534E+07, 5.031E+07 },
    {  4.987E+07, 4.573E+07,  4.554E+07,  4.606E+07,  5.166E+07 },
    {  5.178E+07, 4.713E+07,  4.698E+07,  4.763E+07,  5.351E+07 },
    {  5.363E+07, 4.871E+07,  4.853E+07,  4.930E+07,  5.533E+07 },
    {  5.459E+07, 4.957E+07,  4.931E+07,  5.015E+07,  5.629E+07 },
    {  5.418E+07, 4.914E+07,  4.883E+07,  4.973E+07,  5.589E+07 },
    {  5.288E+07, 4.794E+07,  4.769E+07,  4.860E+07,  5.457E+07 },
    {  5.157E+07, 4.689E+07,  4.678E+07,  4.765E+07,  5.324E+07 },
    {  5.058E+07, 4.666E+07,  4.671E+07,  4.744E+07,  5.227E+07 },
    {  5.092E+07, 4.870E+07,  4.873E+07,  4.920E+07,  5.280E+07 },
    };

  //set CombLayer variables and keys for fission plate sectioning and source
  for(int i=0;i<nx;i++)
    {
     const std::string baseKey=StrFunc::makeString("36FissionPlateXPt",i);
     Control.addVariable(baseKey,Xarray36[i]);  
    }
  for(int i=0;i<nz;i++)
    {
     const std::string baseKey=StrFunc::makeString("36FissionPlateZPt",i);
     Control.addVariable(baseKey,Zarray36[i]);  
    }

  for(size_t ix=0;ix<nx-1;ix++)
   {
    std::string SX=StrFunc::makeString("36FissionPlateSourceX",ix);
    for(size_t iz=0;iz<nz-1;iz++)
     {
      std::string SXZ=StrFunc::makeString(SX+"Z",iz);
      Control.addVariable(SXZ,fissionSource36[iz][ix]);
     }
   }

  Control.addVariable("36FissionPlateMatInL0","36Fuel");   
  Control.addVariable("36FissionPlateMatOutL0","36Aluminium");   
  Control.addVariable("36FissionPlateMatTempL0",300.0);   
  Control.addVariable("36FissionPlateMatL1","36Aluminium");   
  Control.addVariable("36FissionPlateMatTempL1",300.0);   

  // detectors


  Control.addVariable("36DetOffsetX",0.0);  
  Control.addVariable("36DetOffsetZ",0.0);
  // possible detector positions along Y axis 
  Control.addVariable("36DetNY",14);    

  Control.addVariable("36DetStepX",4.95);  
  Control.addVariable("36DetStepZ",0.0);  

  Control.addVariable("36StepY0",0.25);
  Control.addVariable("36StepY1",5);  
  Control.addVariable("36StepY2",10);  
  Control.addVariable("36StepY3",15);
  Control.addVariable("36StepY4",20);
  Control.addVariable("36StepY5",25);
  Control.addVariable("36StepY6",30);  
  Control.addVariable("36StepY7",35); 
  Control.addVariable("36StepY8",40);  
  Control.addVariable("36StepY9",45);
  Control.addVariable("36StepY10",50);
  Control.addVariable("36StepY11",55);
  Control.addVariable("36StepY12",60);  
  Control.addVariable("36StepY13",65);  
  Control.addVariable("36StepY14",70);


  //Sulphur
  Control.addVariable("49SMat","49S");  
  Control.addVariable("49SDiam",5.10);   
  Control.addVariable("49SThick",0.56); 
  //
  Control.addVariable("36SActiveY0",1);   
  Control.addVariable("36SActiveY1",1);   
  Control.addVariable("36SActiveY2",1);   
  Control.addVariable("36SActiveY3",1);   
  Control.addVariable("36SActiveY4",1);   
  Control.addVariable("36SActiveY5",0);   
  Control.addVariable("36SActiveY6",0);   
  Control.addVariable("36SActiveY7",0);   
  Control.addVariable("36SActiveY8",0);   
  Control.addVariable("36SActiveY9",1);   
  Control.addVariable("36SActiveY10",0);   
  Control.addVariable("36SActiveY11",0);   
  Control.addVariable("36SActiveY12",1);   
  Control.addVariable("36SActiveY13",0);   
  Control.addVariable("36SActiveY14",0);   


  // Rhodium
  Control.addVariable("36RhMat","36Rh");  
  Control.addVariable("36RhDiam",1.27);   
  Control.addVariable("36RhThick",0.0015); 
  // Rh positions are the nominal ones; in case of detector stack these are arranged consequently
  // active detector positions along Y axis
  Control.addVariable("36RhActiveY0",1);   
  Control.addVariable("36RhActiveY1",0);   
  Control.addVariable("36RhActiveY2",1);   
  Control.addVariable("36RhActiveY3",0);   
  Control.addVariable("36RhActiveY4",1);   
  Control.addVariable("36RhActiveY5",0);   
  Control.addVariable("36RhActiveY6",1);   
  Control.addVariable("36RhActiveY7",0);   
  Control.addVariable("36RhActiveY8",1);   
  Control.addVariable("36RhActiveY9",0);   
  Control.addVariable("36RhActiveY10",1);   
  Control.addVariable("36RhActiveY11",0);   
  Control.addVariable("36RhActiveY12",1);   
  Control.addVariable("36RhActiveY13",0);   
  Control.addVariable("36RhActiveY14",1);   
 
  //Indium
  Control.addVariable("36InMat","36In");  
  Control.addVariable("36InDiam",1.27);   
  Control.addVariable("36InThick",0.015); 
  //
  // active detector positions along Y axis
  Control.addVariable("36InActiveY0",1);   
  Control.addVariable("36InActiveY1",0);   
  Control.addVariable("36InActiveY2",1);   
  Control.addVariable("36InActiveY3",0);   
  Control.addVariable("36InActiveY4",1);   
  Control.addVariable("36InActiveY5",0);   
  Control.addVariable("36InActiveY6",1);   
  Control.addVariable("36InActiveY7",0);   
  Control.addVariable("36InActiveY8",1);   
  Control.addVariable("36InActiveY9",0);   
  Control.addVariable("36InActiveY10",1);   
  Control.addVariable("36InActiveY11",0);   
  Control.addVariable("36InActiveY12",1);   
  Control.addVariable("36InActiveY13",0);   
  Control.addVariable("36InActiveY14",1);   


  // Al foil
  Control.addVariable("36AlMat","36AlDet");  
  Control.addVariable("36AlDiam",5.0);   
  Control.addVariable("36AlThick",0.31); 
  // Al positions are the nominal ones; in case of detector stack these are arranged consequently
  // active detector positions along Y axis
  Control.addVariable("36AlActiveY0",0);   
  Control.addVariable("36AlActiveY1",1);   
  Control.addVariable("36AlActiveY2",1);   
  Control.addVariable("36AlActiveY3",1);   
  Control.addVariable("36AlActiveY4",1);   
  Control.addVariable("36AlActiveY5",1);   
  Control.addVariable("36AlActiveY6",0);   
  Control.addVariable("36AlActiveY7",0);   
  Control.addVariable("36AlActiveY8",0);   
  Control.addVariable("36AlActiveY9",0);   
  Control.addVariable("36AlActiveY10",0);   
  Control.addVariable("36AlActiveY11",0);   
  Control.addVariable("36AlActiveY12",0);   
  Control.addVariable("36AlActiveY13",0);   
  Control.addVariable("36AlActiveY14",0);   




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


  Control.addVariable("49NestorSideXStep",2.55);
  // the Y step is set so that the fission plate centre is at the origin  
  Control.addVariable("49NestorSideYStep",-26.71);  
  Control.addVariable("49NestorSideZStep",6.6);  
  Control.addVariable("49NestorSideXYAngle",0.0);  
  Control.addVariable("49NestorSideZAngle",0.0);  
  Control.addVariable("49NestorSideWidth",182.9);   
  Control.addVariable("49NestorSideHeight",191.0);  
  // number of slabs
  Control.addVariable("49NestorSideNSlab",6);
  Control.addVariable("49NestorSideThick0",3.18); 
  Control.addVariable("49NestorSideMat0","49MildSteel1");  
  Control.addVariable("49NestorSideWindowRadius",56.06); 
  Control.addVariable("49NestorSideWindowMat","49Aluminium"); 

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
  // simply report here the shift in Nestor Side
  Control.addVariable("49FissionPlateXNucCentre",2.55);   
  Control.addVariable("49FissionPlateZNucCentre",6.6);   
  Control.addVariable("49FissionPlateXYAngle",0.0);   
  Control.addVariable("49FissionPlateZAngle",0.0);   

  //fission plate layers  
  Control.addVariable("49FissionPlateNSlab",6);
  //correct but to avoid geom error it is the same as other slabs
  Control.addVariable("49FissionPlateHeight",191.);  
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

  // already set to be zero in the nucleaar centre
  double Xarray49[16]={-52.25, -49.08, -45.92, -39.58, -36.42, -30.08, -14.25, -4.75, 4.75, 14.25, 30.08, 36.42, 39.58, 45.92, 49.08, 52.25};

  // original from sinbad
  // {-49.75, -46.58, -43.32, -37.08, -33.92, -27.58, -11.75, -2.25,  7.25, 16.75, 32.58, 38.92, 42.08, 48.42, 51.58, 54.75 };

  double Zarray49[16]={ -51.44, -47.63, -40.64, -35.56, -31.75, -19.69, -15.88,  -5.29,  5.29, 15.88, 19.69, 31.75, 35.56, 40.64, 47.63, 51.44};
  nx=sizeof(Xarray49)/sizeof(double);
  nz=sizeof(Zarray49)/sizeof(double);
  Control.addVariable("49FissionPlateNXSpace",nx);   
  Control.addVariable("49FissionPlateNZSpace",nz);   


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
  for(int i=0;i<nx;i++)
    {
     const std::string baseKey=StrFunc::makeString("49FissionPlateXPt",i);
     Control.addVariable(baseKey,Xarray49[i]);  
    }
  for(int i=0;i<nz;i++)
    {
     const std::string baseKey=StrFunc::makeString("49FissionPlateZPt",i);
     Control.addVariable(baseKey,Zarray49[i]);  
    }

  for(size_t ix=0;ix<nx-1;ix++)
    {
     std::string SX=StrFunc::makeString("49FissionPlateSourceX",ix);
     for(size_t iz=0;iz<nz-1;iz++)
       {
        std::string SXZ=StrFunc::makeString(SX+"Z",iz);
        Control.addVariable(SXZ,fissionSource49[iz][ix]);
      }
    }

  Control.addVariable("49FissionPlateMatInL0","49Fuel");   
  Control.addVariable("49FissionPlateMatOutL0","49Aluminium");   
  Control.addVariable("49FissionPlateMatTempL0",300.0);   
  Control.addVariable("49FissionPlateMatL1","49Aluminium");   
  Control.addVariable("49FissionPlateMatTempL1",300.0);   


    //////////////////////////////////////////////////////////////
  // DETECTORS



  // detectors take the origin of the shield: get nuclear center by counter-traslation
  Control.addVariable("49DetOffsetX",0.0);  
  Control.addVariable("49DetOffsetZ",0.0);
  // possible detector positions along Y axis 
  Control.addVariable("49DetNY",33);    

  Control.addVariable("49DetStepX",-2.55);  
  Control.addVariable("49DetStepZ",-6.6);  


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
  // -6.6 is a temp fix to take into account of the nuclear centre shift 
  Control.addVariable("49StepZ0",75.0-6.6);  
  Control.addVariable("49StepZ1",50.0-6.6);  
  Control.addVariable("49StepZ2",25.0-6.6);  
  Control.addVariable("49StepZ3",0.0-6.6);
  Control.addVariable("49StepZ4",-25.0-6.6);
  Control.addVariable("49StepZ5",-50.0-6.6);
  Control.addVariable("49StepZ6",-75.0-6.6);  




 
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


  // Cadmium fron cover
  Control.addVariable("49FCdMat","49Cd");  
  Control.addVariable("49FCdDiam",1.27);   
  //  Control.addVariable("49FCdThick",0.127);
  Control.addVariable("49FCdThick",0.0635);
  // active detectors along axial direction
  Control.addVariable("49FCdActiveY0",0);   
  Control.addVariable("49FCdActiveY1",1);   
  Control.addVariable("49FCdActiveY2",1);   
  Control.addVariable("49FCdActiveY3",1);   
  Control.addVariable("49FCdActiveY4",1);   
  Control.addVariable("49FCdActiveY5",1);   
  Control.addVariable("49FCdActiveY6",0);   
  Control.addVariable("49FCdActiveY7",1); 
  // deactivate next if performing axial and vertical scan at the same time  
  Control.addVariable("49FCdActiveY8",0);   
  Control.addVariable("49FCdActiveY9",1);   
  Control.addVariable("49FCdActiveY10",0);   
  Control.addVariable("49FCdActiveY11",1);   
  Control.addVariable("49FCdActiveY12",1);   
  Control.addVariable("49FCdActiveY13",0);   
  Control.addVariable("49FCdActiveY14",1);   
  Control.addVariable("49FCdActiveY15",0);   
  Control.addVariable("49FCdActiveY16",0);   
  Control.addVariable("49FCdActiveY17",0);   
  Control.addVariable("49FCdActiveY18",1);   
  Control.addVariable("49FCdActiveY19",0);   
  Control.addVariable("49FCdActiveY20",0);   
  Control.addVariable("49FCdActiveY21",1);   
  Control.addVariable("49FCdActiveY22",1);   
  Control.addVariable("49FCdActiveY23",1);   
  Control.addVariable("49FCdActiveY24",1);   
  Control.addVariable("49FCdActiveY25",0);   
  Control.addVariable("49FCdActiveY26",1);   
  Control.addVariable("49FCdActiveY27",1);   
  Control.addVariable("49FCdActiveY28",1);   
  Control.addVariable("49FCdActiveY29",0);   
  Control.addVariable("49FCdActiveY30",1);   
  Control.addVariable("49FCdActiveY31",1);   
  Control.addVariable("49FCdActiveY32",1);
  // number of vertical scans
  Control.addVariable("49FCdVscanNY",1);           
  // Axial offset for vertical scan
  Control.addVariable("49FCdVscanY0",29.44);   
  // active detectors along vertical direction
  // Control.addVariable("49FCdVscanNY",7);           
  Control.addVariable("49FCdY0ActiveZ0",1);   
  Control.addVariable("49FCdY0ActiveZ1",1);   
  Control.addVariable("49FCdY0ActiveZ2",1);   
  Control.addVariable("49FCdY0ActiveZ3",1);   
  Control.addVariable("49FCdY0ActiveZ4",1);   
  Control.addVariable("49FCdY0ActiveZ5",1);   
  Control.addVariable("49FCdY0ActiveZ6",1);   



  // Cadmium fron cover
  Control.addVariable("49BCdMat","49Cd");  
  Control.addVariable("49BCdDiam",1.27);   
  //  Control.addVariable("49BCdThick",0.127);
  Control.addVariable("49BCdThick",0.0635);
  // active detectors along axial direction
  Control.addVariable("49BCdActiveY0",0);   
  Control.addVariable("49BCdActiveY1",1);   
  Control.addVariable("49BCdActiveY2",1);   
  Control.addVariable("49BCdActiveY3",1);   
  Control.addVariable("49BCdActiveY4",1);   
  Control.addVariable("49BCdActiveY5",1);   
  Control.addVariable("49BCdActiveY6",0);   
  Control.addVariable("49BCdActiveY7",1); 
  // deactivate next if performing axial and vertical scan at the same time  
  Control.addVariable("49BCdActiveY8",0);   
  Control.addVariable("49BCdActiveY9",1);   
  Control.addVariable("49BCdActiveY10",0);   
  Control.addVariable("49BCdActiveY11",1);   
  Control.addVariable("49BCdActiveY12",1);   
  Control.addVariable("49BCdActiveY13",0);   
  Control.addVariable("49BCdActiveY14",1);   
  Control.addVariable("49BCdActiveY15",0);   
  Control.addVariable("49BCdActiveY16",0);   
  Control.addVariable("49BCdActiveY17",0);   
  Control.addVariable("49BCdActiveY18",1);   
  Control.addVariable("49BCdActiveY19",0);   
  Control.addVariable("49BCdActiveY20",0);   
  Control.addVariable("49BCdActiveY21",1);   
  Control.addVariable("49BCdActiveY22",1);   
  Control.addVariable("49BCdActiveY23",1);   
  Control.addVariable("49BCdActiveY24",1);   
  Control.addVariable("49BCdActiveY25",0);   
  Control.addVariable("49BCdActiveY26",1);   
  Control.addVariable("49BCdActiveY27",1);   
  Control.addVariable("49BCdActiveY28",1);   
  Control.addVariable("49BCdActiveY29",0);   
  Control.addVariable("49BCdActiveY30",1);   
  Control.addVariable("49BCdActiveY31",1);   
  Control.addVariable("49BCdActiveY32",1);
  // number of vertical scans
  Control.addVariable("49BCdVscanNY",1);           
  // Axial offset for vertical scan
  Control.addVariable("49BCdVscanY0",29.44);   
  // active detectors along vertical direction
  // Control.addVariable("49BCdVscanNY",7);           
  Control.addVariable("49BCdY0ActiveZ0",1);   
  Control.addVariable("49BCdY0ActiveZ1",1);   
  Control.addVariable("49BCdY0ActiveZ2",1);   
  Control.addVariable("49BCdY0ActiveZ3",1);   
  Control.addVariable("49BCdY0ActiveZ4",1);   
  Control.addVariable("49BCdY0ActiveZ5",1);   
  Control.addVariable("49BCdY0ActiveZ6",1);   








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


  ///////////////////////
  // 75 Shield array

  // define centre
  Control.addVariable("75ShieldXStep",0.0);  
  Control.addVariable("75ShieldYStep",0.0);  
  Control.addVariable("75ShieldZStep",0.0);  
  Control.addVariable("75ShieldXYAngle",0.0);  
  Control.addVariable("75ShieldZAngle",0.0);  
  //number of slabs
  Control.addVariable("75ShieldNSlab",9);
  Control.addVariable("75ShieldWidth",180.0);   
  Control.addVariable("75ShieldHeight",180.0);  
  Control.addVariable("75ShieldThick0",1.91); 
  Control.addVariable("75ShieldMat0","75Aluminium");
  // fictitious cut in Al (only useful for variance reduction) 
  Control.addVariable("75ShieldCutZ0",68.5);
  Control.addVariable("75ShieldCutX0",68.5);
  Control.addVariable("75ShieldCutOutMat0","75Aluminium");
  Control.addVariable("75ShieldThick1",12.1); 
  Control.addVariable("75ShieldMat1","75H2O");
  // fictitoius cuts in water (only useful for variance reduction) 
  Control.addVariable("75ShieldCutZ1",68.5);
  Control.addVariable("75ShieldCutX1",68.5);
  Control.addVariable("75ShieldCutOutMat1","75H2O");
  Control.addVariable("75ShieldThick2",5.9);
  Control.addVariable("75ShieldMat2","75StainlessSteel");
  Control.addVariable("75ShieldCutZ2",68.5);
  Control.addVariable("75ShieldCutX2",68.5);
  // mat called by index rather than by string
  Control.addVariable("75ShieldCutOutMat2","75H2O");
  Control.addVariable("75ShieldThick3",12.7); 
  Control.addVariable("75ShieldMat3","75H2O");  
  Control.addVariable("75ShieldCutZ3",68.5);
  Control.addVariable("75ShieldCutX3",68.5);
  Control.addVariable("75ShieldCutOutMat3","75H2O");
  Control.addVariable("75ShieldThick4",22.5); 
  Control.addVariable("75ShieldMat4","75MildSteel");
  Control.addVariable("75ShieldCutZ4",68.5);
  Control.addVariable("75ShieldCutX4",68.5);
  Control.addVariable("75ShieldCutOutMat4","75H2O");
  Control.addVariable("75ShieldThick5",0.3); 
  Control.addVariable("75ShieldMat5","75Aluminium");  
  Control.addVariable("75ShieldCutZ5",60.0);
  Control.addVariable("75ShieldCutX5",60.0);
  Control.addVariable("75ShieldCutOutMat5","75H2O");
  Control.addVariable("75ShieldThick6",29.58);
  Control.addVariable("75ShieldMat6","Void"); 
  Control.addVariable("75ShieldCutZ6",59.4);
  Control.addVariable("75ShieldCutX6",59.4);
  Control.addVariable("75ShieldCutOutMat6","75H2O");
  Control.addVariable("75ShieldThick7",0.3); 
  Control.addVariable("75ShieldMat7","75Aluminium");  
  Control.addVariable("75ShieldCutZ7",60.0);
  Control.addVariable("75ShieldCutX7",60.0);
  Control.addVariable("75ShieldCutOutMat7","75H2O");
  Control.addVariable("75ShieldThick8",50.0); 
  Control.addVariable("75ShieldMat8","75H2O");  
  Control.addVariable("75ShieldCutZ8",50.0);
  Control.addVariable("75ShieldCutX8",50.0);
  Control.addVariable("75ShieldCutOutMat8","75H2O");




  /////////////////////////////////////////////////
  // 75 NestorSide (The array between Nestor reactor and fission plate)


  Control.addVariable("75NestorSideXStep",0.0);
  // the Y step is set so that the fission plate centre is at the origin  
  Control.addVariable("75NestorSideYStep",-18.81);  
  Control.addVariable("75NestorSideZStep",0.0);  
  Control.addVariable("75NestorSideXYAngle",0.0);  
  Control.addVariable("75NestorSideZAngle",0.0);  
  Control.addVariable("75NestorSideWidth",180.0);   
  Control.addVariable("75NestorSideHeight",180.0);  
  // number of slabs
  Control.addVariable("75NestorSideNSlab",3);
  Control.addVariable("75NestorSideThick0",3.21); 
  Control.addVariable("75NestorSideMat0","75MildSteel");  
  Control.addVariable("75NestorSideWindowRadius",56.06); 
  Control.addVariable("75NestorSideWindowMat","75Aluminium"); 
  Control.addVariable("75NestorSideThick1",15.0); 
  Control.addVariable("75NestorSideMat1","75Graphite");  
  Control.addVariable("75NestorSideThick2",0.60); 
  Control.addVariable("75NestorSideMat2","Void");  


  ////////////////////////////////////////////////
  // 75 Fission Plate

  Control.addVariable("75FissionPlateXStep",0.0);  
  Control.addVariable("75FissionPlateYStep",0.0);   
  Control.addVariable("75FissionPlateZStep",0.0);  
  // simply report here the shift in Nestor Side
  Control.addVariable("75FissionPlateXNucCentre",0.0);   
  Control.addVariable("75FissionPlateZNucCentre",0.0);   
  Control.addVariable("75FissionPlateXYAngle",0.0);   
  Control.addVariable("75FissionPlateZAngle",0.0);   

  //fission plate layers  
  Control.addVariable("75FissionPlateNSlab",5);
  //correct but to avoid geom error it is the same as other slabs
  // Control.addVariable("75FissionPlateHeight",68.5);  
  // Control.addVariable("75FissionPlateWidth",47.5); 
  Control.addVariable("75FissionPlateHeight",180);  
  Control.addVariable("75FissionPlateWidth",180); 

  Control.addVariable("75FissionPlateThick0",0.4);
  Control.addVariable("75FissionPlateMat0","75Aluminium");   
  Control.addVariable("75FissionPlateThick1",0.1); 
  Control.addVariable("75FissionPlateMat1","Void");   
  Control.addVariable("75FissionPlateThick2",0.4); 
  Control.addVariable("75FissionPlateMat2","75Fuel");   
  Control.addVariable("75FissionPlateThick3",0.1); 
  Control.addVariable("75FissionPlateMat3","Void");   
  Control.addVariable("75FissionPlateThick4",0.4); 
  Control.addVariable("75FissionPlateMat4","75Aluminium");   
  //fuel plate index
  Control.addVariable("75FissionPlateDivIndex0",2);
  //////////////////////////////////////////////////////////////
  // imports of fission source specificationsfrom SINBAD     
  //75 X-Z sectioning of fuel plate

  // already set to be zero in the nucleaar centre
  double Xarray75[6]={ -20.10, -12.10, -4.10, 4.10, 12.10, 20.10};
  double Zarray75[12]={ -31.75, -26.32, -20.58, -15.44, -10.00, -3.33, 3.33, 10.00, 15.44, 20.58, 26.32, 31.75};

  nx=sizeof(Xarray75)/sizeof(double);
  nz=sizeof(Zarray75)/sizeof(double);
  Control.addVariable("75FissionPlateNXSpace",nx);   
  Control.addVariable("75FissionPlateNZSpace",nz);   

  //75 source dist specification
  double fissionSource75 [11] [5] = {
    { 4.723E+07, 4.670E+07, 4.778E+07, 4.756E+07, 4.874E+07 },           
    { 4.802E+07, 4.642E+07, 4.684E+07, 4.699E+07, 4.964E+07 },
    { 5.006E+07, 4.764E+07, 4.806E+07, 4.855E+07, 5.144E+07 },
    { 5.231E+07, 4.927E+07, 4.996E+07, 5.069E+07, 5.351E+07 },
    { 5.426E+07, 5.078E+07, 5.179E+07, 5.264E+07, 5.531E+07 },
    { 5.500E+07, 5.135E+07, 5.252E+07, 5.332E+07, 5.601E+07 },
    { 5.393E+07, 5.055E+07, 5.160E+07, 5.217E+07, 5.505E+07 },
    { 5.157E+07, 4.885E+07, 4.690E+07, 4.989E+07, 5.293E+07 },
    { 4.885E+07, 4.696E+07, 4.744E+07, 4.747E+07, 5.040E+07 },
    { 4.609E+07, 4.518E+07, 4.557E+07, 4.535E+07, 4.772E+07 },
    { 4.424E+07, 4.418E+07, 4.495E+07, 4.448E+07, 4.560E+07 },
 } ; 

  //set CombLayer variables and keys for fission plate sectioning and source

  for(int i=0;i<nx;i++)
    {
     const std::string baseKey=StrFunc::makeString("75FissionPlateXPt",i);
     Control.addVariable(baseKey,Xarray75[i]);  
    }

  for(int i=0;i<nz;i++)
    {
     const std::string baseKey=StrFunc::makeString("75FissionPlateZPt",i);
     Control.addVariable(baseKey,Zarray75[i]);  
    }

  for(size_t ix=0;ix<nx-1;ix++)
    {
     std::string SX=StrFunc::makeString("75FissionPlateSourceX",ix);
     for(size_t iz=0;iz<nz-1;iz++)
       {
        std::string SXZ=StrFunc::makeString(SX+"Z",iz);
        Control.addVariable(SXZ,fissionSource75[iz][ix]);
      }
    }

  Control.addVariable("75FissionPlateMatInL0","75Fuel");   
  Control.addVariable("75FissionPlateMatOutL0","75Aluminium");   
  Control.addVariable("75FissionPlateMatTempL0",300.0);   
  Control.addVariable("75FissionPlateMatL1","75Aluminium");   
  Control.addVariable("75FissionPlateMatTempL1",300.0);   


    //////////////////////////////////////////////////////////////
  // DETECTORS



  // detectors take the origin of the shield: get nuclear center by counter-traslation
  Control.addVariable("75DetOffsetX",0.0);  
  Control.addVariable("75DetOffsetZ",0.0);
  // possible detector positions along Y axis 
  Control.addVariable("75DetNY",41);    

  Control.addVariable("75DetStepX",0.0);  
  Control.addVariable("75DetStepZ",0.0);  


  // list of all possible positions
  // 12 cm water gap
  Control.addVariable("75StepY0",1.91);  
  Control.addVariable("75StepY1",2.41);  
  Control.addVariable("75StepY2",3.41);  
  Control.addVariable("75StepY3",4.41);
  Control.addVariable("75StepY4",5.41);
  Control.addVariable("75StepY5",6.41);
  Control.addVariable("75StepY6",7.41);  
  Control.addVariable("75StepY7",7.51); 
  Control.addVariable("75StepY8",8.41);  
  Control.addVariable("75StepY9",9.41);  
  Control.addVariable("75StepY10",10.51);
  // pos A1
  Control.addVariable("75StepY11",11.36);
  Control.addVariable("75StepY12",11.41);
  Control.addVariable("75StepY13",12.41);
  Control.addVariable("75StepY14",13.51); 
  Control.addVariable("75StepY15",14.01);
  // 13 cm water gap 
  Control.addVariable("75StepY16",19.91); 
  Control.addVariable("75StepY17",20.41); 
  Control.addVariable("75StepY18",21.41); 
  Control.addVariable("75StepY19",22.11); 
  Control.addVariable("75StepY20",22.41);
  // pos A2  
  Control.addVariable("75StepY21",23.26);
  Control.addVariable("75StepY22",23.41);
  Control.addVariable("75StepY23",24.11);  
  Control.addVariable("75StepY24",24.41);  
  Control.addVariable("75StepY25",25.41);
  Control.addVariable("75StepY26",26.11);  
  Control.addVariable("75StepY27",26.41);  
  Control.addVariable("75StepY28",27.41);  
  Control.addVariable("75StepY29",28.11);  
  Control.addVariable("75StepY30",29.11);
  // pos A3
  Control.addVariable("75StepY31",29.16);
  Control.addVariable("75StepY32",30.11);
  Control.addVariable("75StepY33",30.41);
  Control.addVariable("75StepY34",31.11);
  Control.addVariable("75StepY35",32.11);
  Control.addVariable("75StepY36",32.61);
  // pos T/4 (A4)
  Control.addVariable("75StepY37",39.01);
  // pos T/2 (A5)
  Control.addVariable("75StepY38",44.21);
  // pos 3T/4 (A6)
  Control.addVariable("75StepY39",49.61);
  // void box (A7)
  Control.addVariable("75StepY40",58.61);



  // possible S detectors for vertical scans
  Control.addVariable("75SDetNZ",19);    
  Control.addVariable("75SStepZ0",31.55);  
  Control.addVariable("75SStepZ1",30.75);  
  Control.addVariable("75SStepZ2",28.05);  
  Control.addVariable("75SStepZ3",20.50);
  Control.addVariable("75SStepZ4",18.70);
  Control.addVariable("75SStepZ5",12.85);
  Control.addVariable("75SStepZ6",10.25);  
  Control.addVariable("75SStepZ7",9.35);  
  Control.addVariable("75SStepZ8",3.50);  
  Control.addVariable("75SStepZ9",0.0);  
  Control.addVariable("75SStepZ10",-5.80);  
  Control.addVariable("75SStepZ11",-9.35);  
  Control.addVariable("75SStepZ12",-10.25);  
  Control.addVariable("75SStepZ13",-15.20);
  Control.addVariable("75SStepZ14",-18.70);
  Control.addVariable("75SStepZ15",-20.50);
  Control.addVariable("75SStepZ16",-24.20);  
  Control.addVariable("75SStepZ17",-26.70);  
  Control.addVariable("75SStepZ18",-30.75);  






  // possible Rh detectors for vertical scans
  Control.addVariable("75RhDetNZ",23);    
  Control.addVariable("75RhStepZ0",40.0);  
  Control.addVariable("75RhStepZ1",30.0);  
  Control.addVariable("75RhStepZ2",25.8);  
  Control.addVariable("75RhStepZ3",25.4);
  Control.addVariable("75RhStepZ4",22.5);
  Control.addVariable("75RhStepZ5",20.0);
  Control.addVariable("75RhStepZ6",16.3);  
  Control.addVariable("75RhStepZ7",15.9);  
  Control.addVariable("75RhStepZ8",15.0);  
  Control.addVariable("75RhStepZ9",10.0);  
  Control.addVariable("75RhStepZ10",7.5);  
  Control.addVariable("75RhStepZ11",6.8);  
  Control.addVariable("75RhStepZ12",0.0);  
  Control.addVariable("75RhStepZ13",-3.0);
  Control.addVariable("75RhStepZ14",-7.5);
  Control.addVariable("75RhStepZ15",-10.0);
  Control.addVariable("75RhStepZ16",-12.2);  
  Control.addVariable("75RhStepZ17",-15.0);  
  Control.addVariable("75RhStepZ18",-20.0);  
  Control.addVariable("75RhStepZ19",-21.7);  
  Control.addVariable("75RhStepZ20",-22.5);  
  Control.addVariable("75RhStepZ21",-30.0);  
  Control.addVariable("75RhStepZ22",-31.0);  


 
  //Sulphur
  Control.addVariable("75SMat","75S");  
  Control.addVariable("75SDiam",5.10);   
  Control.addVariable("75SThick",0.56); 
  // active detector positions along Y axis
  Control.addVariable("75SActiveY0",0);   
  Control.addVariable("75SActiveY1",0);   
  Control.addVariable("75SActiveY2",0);   
  Control.addVariable("75SActiveY3",0);   
  Control.addVariable("75SActiveY4",0);   
  Control.addVariable("75SActiveY5",0);   
  Control.addVariable("75SActiveY6",0);   
  Control.addVariable("75SActiveY7",0);   
  Control.addVariable("75SActiveY8",0);   
  Control.addVariable("75SActiveY9",0);   
  Control.addVariable("75SActiveY10",0);   
  Control.addVariable("75SActiveY11",0);   
  Control.addVariable("75SActiveY12",0);   
  Control.addVariable("75SActiveY13",0);   
  Control.addVariable("75SActiveY14",0);   
  Control.addVariable("75SActiveY15",0);   
  Control.addVariable("75SActiveY16",0);   
  Control.addVariable("75SActiveY17",0);   
  Control.addVariable("75SActiveY18",0);   
  Control.addVariable("75SActiveY19",0);   
  Control.addVariable("75SActiveY20",0);   
  Control.addVariable("75SActiveY21",0);   
  Control.addVariable("75SActiveY22",0);   
  Control.addVariable("75SActiveY23",0);   
  Control.addVariable("75SActiveY24",0);   
  Control.addVariable("75SActiveY25",0);   
  Control.addVariable("75SActiveY26",0);   
  Control.addVariable("75SActiveY27",0);   
  Control.addVariable("75SActiveY28",0);   
  Control.addVariable("75SActiveY29",0);   
  Control.addVariable("75SActiveY30",0);   
  Control.addVariable("75SActiveY31",0);   
  Control.addVariable("75SActiveY32",0);   
  Control.addVariable("75SActiveY33",0);   
  Control.addVariable("75SActiveY34",0);   
  Control.addVariable("75SActiveY35",0);   
  Control.addVariable("75SActiveY36",0);   
  Control.addVariable("75SActiveY37",1);   
  Control.addVariable("75SActiveY38",0);   
  Control.addVariable("75SActiveY39",1);   
  Control.addVariable("75SActiveY40",1);   

  // number of vertical scans
  Control.addVariable("75SVscanNY",2);           
  // Axial offset for vertical scan
  // the positions refer to the vertical scans along 
  // the central axis (table 10 in SINBAD)
  // The horizontal scans are not an option now, but 
  // it shoud be possible to tweak with variables for individual
  // insertion of horizontal detectors if this is very interesting 
  Control.addVariable("75SVscanY0",39.01);   
  Control.addVariable("75SVscanY1",49.61);   
  Control.addVariable("75SVscanY2",58.61);   
 
  // active detectors along vertical direction (table 11)
  // A4
  Control.addVariable("75SY0ActiveZ0",0);   
  Control.addVariable("75SY0ActiveZ1",1);   
  Control.addVariable("75SY0ActiveZ2",0);   
  Control.addVariable("75SY0ActiveZ3",1);   
  Control.addVariable("75SY0ActiveZ4",0);   
  Control.addVariable("75SY0ActiveZ5",0);   
  Control.addVariable("75SY0ActiveZ6",1);   
  Control.addVariable("75SY0ActiveZ7",0);   
  Control.addVariable("75SY0ActiveZ8",0);   
  Control.addVariable("75SY0ActiveZ9",0);   
  Control.addVariable("75SY0ActiveZ10",0);
  Control.addVariable("75SY0ActiveZ11",0);   
  Control.addVariable("75SY0ActiveZ12",1);   
  Control.addVariable("75SY0ActiveZ13",0);   
  Control.addVariable("75SY0ActiveZ14",0);   
  Control.addVariable("75SY0ActiveZ15",1);   
  Control.addVariable("75SY0ActiveZ16",0);   
  Control.addVariable("75SY0ActiveZ17",0);   
  Control.addVariable("75SY0ActiveZ18",1);   

  // A6
  Control.addVariable("75SY1ActiveZ0",0);   
  Control.addVariable("75SY1ActiveZ1",1);   
  Control.addVariable("75SY1ActiveZ2",0);   
  Control.addVariable("75SY1ActiveZ3",1);   
  Control.addVariable("75SY1ActiveZ4",0);   
  Control.addVariable("75SY1ActiveZ5",0);   
  Control.addVariable("75SY1ActiveZ6",1);   
  Control.addVariable("75SY1ActiveZ7",0);   
  Control.addVariable("75SY1ActiveZ8",0);   
  Control.addVariable("75SY1ActiveZ9",0);   
  Control.addVariable("75SY1ActiveZ10",0);
  Control.addVariable("75SY1ActiveZ11",0);   
  Control.addVariable("75SY1ActiveZ12",1);   
  Control.addVariable("75SY1ActiveZ13",0);   
  Control.addVariable("75SY1ActiveZ14",0);   
  Control.addVariable("75SY1ActiveZ15",1);   
  Control.addVariable("75SY1ActiveZ16",0);   
  Control.addVariable("75SY1ActiveZ17",0);   
  Control.addVariable("75SY1ActiveZ18",1);   

  // A7
  Control.addVariable("75SY2ActiveZ0",1);   
  Control.addVariable("75SY2ActiveZ1",0);   
  Control.addVariable("75SY2ActiveZ2",1);   
  Control.addVariable("75SY2ActiveZ3",0);   
  Control.addVariable("75SY2ActiveZ4",1);   
  Control.addVariable("75SY2ActiveZ5",1);   
  Control.addVariable("75SY2ActiveZ6",0);   
  Control.addVariable("75SY2ActiveZ7",1);   
  Control.addVariable("75SY2ActiveZ8",1);   
  Control.addVariable("75SY2ActiveZ9",0);   
  Control.addVariable("75SY2ActiveZ10",1);
  Control.addVariable("75SY2ActiveZ11",1);   
  Control.addVariable("75SY2ActiveZ12",0);   
  Control.addVariable("75SY2ActiveZ13",1);   
  Control.addVariable("75SY2ActiveZ14",1);   
  Control.addVariable("75SY2ActiveZ15",0);   
  Control.addVariable("75SY2ActiveZ16",1);   
  Control.addVariable("75SY2ActiveZ17",1);   
  Control.addVariable("75SY2ActiveZ18",0);   


  // Rhodium
  Control.addVariable("75RhMat","75Rh");  
  Control.addVariable("75RhDiam",1.27);   
  Control.addVariable("75RhThick",0.0015); 
  // Rh positions are the nominal ones; in case of detector stack these are arranged consequently
  // active detector positions along Y axis
  Control.addVariable("75RhActiveY0",1);   
  Control.addVariable("75RhActiveY1",0);   
  Control.addVariable("75RhActiveY2",0);   
  Control.addVariable("75RhActiveY3",0);   
  Control.addVariable("75RhActiveY4",0);   
  Control.addVariable("75RhActiveY5",0);   
  Control.addVariable("75RhActiveY6",1);   
  Control.addVariable("75RhActiveY7",0);   
  Control.addVariable("75RhActiveY8",0);   
  Control.addVariable("75RhActiveY9",0);   
  Control.addVariable("75RhActiveY10",0);   
  Control.addVariable("75RhActiveY11",0);   
  Control.addVariable("75RhActiveY12",0);   
  Control.addVariable("75RhActiveY13",1);   
  Control.addVariable("75RhActiveY14",0);   
  Control.addVariable("75RhActiveY15",0);   
  Control.addVariable("75RhActiveY16",1);   
  Control.addVariable("75RhActiveY17",0);   
  Control.addVariable("75RhActiveY18",0);   
  Control.addVariable("75RhActiveY19",0);   
  Control.addVariable("75RhActiveY20",0);   
  Control.addVariable("75RhActiveY21",0);   
  Control.addVariable("75RhActiveY22",0);   
  Control.addVariable("75RhActiveY23",0);   
  Control.addVariable("75RhActiveY24",0);   
  Control.addVariable("75RhActiveY25",1);   
  Control.addVariable("75RhActiveY26",0);   
  Control.addVariable("75RhActiveY27",0);   
  Control.addVariable("75RhActiveY28",0);   
  Control.addVariable("75RhActiveY29",0);   
  Control.addVariable("75RhActiveY30",0);   
  Control.addVariable("75RhActiveY31",0);   
  Control.addVariable("75RhActiveY32",0);
  Control.addVariable("75RhActiveY33",1);   
  Control.addVariable("75RhActiveY34",0);   
  Control.addVariable("75RhActiveY35",0);   
  Control.addVariable("75RhActiveY36",0);   
  Control.addVariable("75RhActiveY37",1);   
  Control.addVariable("75RhActiveY38",0);   
  Control.addVariable("75RhActiveY39",1);   
  Control.addVariable("75RhActiveY40",1);     
  // number of vertical scans
  Control.addVariable("75RhVscanNY",4);           
  // Axial offset for vertical scan
  // the positions refer to the vertical scans along 
  // the central axis (table 10 in SINBAD)
  // The horizontal scans are not an option now, but 
  // it shoud be possible to tweak with variables for individual
  // insertion of horizontal detectors if this is very interesting 
  Control.addVariable("75RhVscanY0",14.01);   
  Control.addVariable("75RhVscanY1",19.91);   
  Control.addVariable("75RhVscanY2",39.01);   
  Control.addVariable("75RhVscanY3",49.61);   
 
  // active detectors along vertical direction (table 10)
  // front thermal shield
  Control.addVariable("75RhY0ActiveZ0",0);   
  Control.addVariable("75RhY0ActiveZ1",1);   
  Control.addVariable("75RhY0ActiveZ2",0);   
  Control.addVariable("75RhY0ActiveZ3",0);   
  Control.addVariable("75RhY0ActiveZ4",0);   
  Control.addVariable("75RhY0ActiveZ5",1);   
  Control.addVariable("75RhY0ActiveZ6",0);   
  Control.addVariable("75RhY0ActiveZ7",0);   
  Control.addVariable("75RhY0ActiveZ8",0);   
  Control.addVariable("75RhY0ActiveZ9",1);   
  Control.addVariable("75RhY0ActiveZ10",0);
  Control.addVariable("75RhY0ActiveZ11",0);  
  //  
  Control.addVariable("75RhY0ActiveZ12",1);   
  Control.addVariable("75RhY0ActiveZ13",0);   
  Control.addVariable("75RhY0ActiveZ14",0);   
  Control.addVariable("75RhY0ActiveZ15",1);   
  Control.addVariable("75RhY0ActiveZ16",0);   
  Control.addVariable("75RhY0ActiveZ17",0);   
  Control.addVariable("75RhY0ActiveZ18",1);   
  Control.addVariable("75RhY0ActiveZ19",0);   
  Control.addVariable("75RhY0ActiveZ20",0);
  Control.addVariable("75RhY0ActiveZ21",1);   
  Control.addVariable("75RhY0ActiveZ22",0);   

  // rear thermal shield
  Control.addVariable("75RhY1ActiveZ0",1);   
  Control.addVariable("75RhY1ActiveZ1",1);   
  Control.addVariable("75RhY1ActiveZ2",0);   
  Control.addVariable("75RhY1ActiveZ3",0);   
  Control.addVariable("75RhY1ActiveZ4",0);   
  Control.addVariable("75RhY1ActiveZ5",1);   
  Control.addVariable("75RhY1ActiveZ6",0);   
  Control.addVariable("75RhY1ActiveZ7",0);   
  Control.addVariable("75RhY1ActiveZ8",0);   
  Control.addVariable("75RhY1ActiveZ9",1);   
  Control.addVariable("75RhY1ActiveZ10",0);
  Control.addVariable("75RhY1ActiveZ11",0);   
  Control.addVariable("75RhY1ActiveZ12",0);   
  Control.addVariable("75RhY1ActiveZ13",0);   
  Control.addVariable("75RhY1ActiveZ14",0);   
  Control.addVariable("75RhY1ActiveZ15",1);   
  Control.addVariable("75RhY1ActiveZ16",0);   
  Control.addVariable("75RhY1ActiveZ17",0);   
  Control.addVariable("75RhY1ActiveZ18",1);   
  Control.addVariable("75RhY1ActiveZ19",0);   
  Control.addVariable("75RhY1ActiveZ20",0);
  Control.addVariable("75RhY1ActiveZ21",0);   
  Control.addVariable("75RhY1ActiveZ22",0);   

  // A4
  Control.addVariable("75RhY2ActiveZ0",0);   
  Control.addVariable("75RhY2ActiveZ1",0);   
  Control.addVariable("75RhY2ActiveZ2",1);   
  Control.addVariable("75RhY2ActiveZ3",0);   
  Control.addVariable("75RhY2ActiveZ4",0);   
  Control.addVariable("75RhY2ActiveZ5",0);   
  Control.addVariable("75RhY2ActiveZ6",1);   
  Control.addVariable("75RhY2ActiveZ7",0);   
  Control.addVariable("75RhY2ActiveZ8",0);   
  Control.addVariable("75RhY2ActiveZ9",0);   
  Control.addVariable("75RhY2ActiveZ10",0);
  Control.addVariable("75RhY2ActiveZ11",1);   
  Control.addVariable("75RhY2ActiveZ12",0);   
  Control.addVariable("75RhY2ActiveZ13",0);   
  Control.addVariable("75RhY2ActiveZ14",0);   
  Control.addVariable("75RhY2ActiveZ15",0);   
  Control.addVariable("75RhY2ActiveZ16",1);   
  Control.addVariable("75RhY2ActiveZ17",0);   
  Control.addVariable("75RhY2ActiveZ18",0);   
  Control.addVariable("75RhY2ActiveZ19",1);   
  Control.addVariable("75RhY2ActiveZ20",0);
  Control.addVariable("75RhY2ActiveZ21",0);   
  Control.addVariable("75RhY2ActiveZ22",1);   

  // A6
  Control.addVariable("75RhY3ActiveZ0",0);   
  Control.addVariable("75RhY3ActiveZ1",0);   
  Control.addVariable("75RhY3ActiveZ2",0);   
  Control.addVariable("75RhY3ActiveZ3",1);   
  Control.addVariable("75RhY3ActiveZ4",0);   
  Control.addVariable("75RhY3ActiveZ5",0);   
  Control.addVariable("75RhY3ActiveZ6",0);   
  Control.addVariable("75RhY3ActiveZ7",1);   
  Control.addVariable("75RhY3ActiveZ8",0);   
  Control.addVariable("75RhY3ActiveZ9",0);   
  Control.addVariable("75RhY3ActiveZ10",0);
  Control.addVariable("75RhY3ActiveZ11",0);   
  Control.addVariable("75RhY3ActiveZ12",0);   
  Control.addVariable("75RhY3ActiveZ13",1);   
  Control.addVariable("75RhY3ActiveZ14",0);   
  Control.addVariable("75RhY3ActiveZ15",0);   
  Control.addVariable("75RhY3ActiveZ16",0);   
  Control.addVariable("75RhY3ActiveZ17",0);   
  Control.addVariable("75RhY3ActiveZ18",0);   
  Control.addVariable("75RhY3ActiveZ19",0);   
  Control.addVariable("75RhY3ActiveZ20",0);
  Control.addVariable("75RhY3ActiveZ21",0);   
  Control.addVariable("75RhY3ActiveZ22",1);   



  // Manganese
  Control.addVariable("75MnMat","75Mn");  
  Control.addVariable("75MnDiam",1.27);   
  Control.addVariable("75MnThick",0.015);
  // active detectors along axial direction
  Control.addVariable("75MnActiveY0",1);   
  Control.addVariable("75MnActiveY1",1);   
  Control.addVariable("75MnActiveY2",1);   
  Control.addVariable("75MnActiveY3",1);   
  Control.addVariable("75MnActiveY4",1);   
  Control.addVariable("75MnActiveY5",1);   
  Control.addVariable("75MnActiveY6",0);   
  Control.addVariable("75MnActiveY7",1);  
  Control.addVariable("75MnActiveY8",1);   
  Control.addVariable("75MnActiveY9",1);   
  Control.addVariable("75MnActiveY10",1);   
  Control.addVariable("75MnActiveY11",0);   
  Control.addVariable("75MnActiveY12",1);   
  Control.addVariable("75MnActiveY13",0);   
  Control.addVariable("75MnActiveY14",1);   
  Control.addVariable("75MnActiveY15",1);   
  Control.addVariable("75MnActiveY16",1);   
  Control.addVariable("75MnActiveY17",1);   
  Control.addVariable("75MnActiveY18",1);   
  Control.addVariable("75MnActiveY19",1);   
  Control.addVariable("75MnActiveY20",1);   
  Control.addVariable("75MnActiveY21",0);   
  Control.addVariable("75MnActiveY22",1);   
  Control.addVariable("75MnActiveY23",1);   
  Control.addVariable("75MnActiveY24",1);   
  Control.addVariable("75MnActiveY25",0);   
  Control.addVariable("75MnActiveY26",0);   
  Control.addVariable("75MnActiveY27",1);   
  Control.addVariable("75MnActiveY28",0);   
  Control.addVariable("75MnActiveY29",1);   
  Control.addVariable("75MnActiveY30",1);   
  Control.addVariable("75MnActiveY31",0);   
  Control.addVariable("75MnActiveY32",1);
  Control.addVariable("75MnActiveY33",0);   
  Control.addVariable("75MnActiveY34",1);   
  Control.addVariable("75MnActiveY35",1);   
  Control.addVariable("75MnActiveY36",1);   
  Control.addVariable("75MnActiveY37",0);   
  Control.addVariable("75MnActiveY38",0);   
  Control.addVariable("75MnActiveY39",0);   
  Control.addVariable("75MnActiveY40",0);   

  // number of vertical scans
  Control.addVariable("75MnVscanNY",0);           
   

  //Indium
  Control.addVariable("75InMat","75In");  
  Control.addVariable("75InDiam",1.27);   
  Control.addVariable("75InThick",0.015); 
  //
  // active detector positions along Y axis
  Control.addVariable("75InActiveY0",0);   
  Control.addVariable("75InActiveY1",0);   
  Control.addVariable("75InActiveY2",0);   
  Control.addVariable("75InActiveY3",0);   
  Control.addVariable("75InActiveY4",0);   
  Control.addVariable("75InActiveY5",0);   
  Control.addVariable("75InActiveY6",0);   
  Control.addVariable("75InActiveY7",0);   
  Control.addVariable("75InActiveY8",0);   
  Control.addVariable("75InActiveY9",0);   
  Control.addVariable("75InActiveY10",0);   
  Control.addVariable("75InActiveY11",0);   
  Control.addVariable("75InActiveY12",0);   
  Control.addVariable("75InActiveY13",0);   
  Control.addVariable("75InActiveY14",0);   
  Control.addVariable("75InActiveY15",0);   
  Control.addVariable("75InActiveY16",0);   
  Control.addVariable("75InActiveY17",0);   
  Control.addVariable("75InActiveY18",0);   
  Control.addVariable("75InActiveY19",0);   
  Control.addVariable("75InActiveY20",0);   
  Control.addVariable("75InActiveY21",0);   
  Control.addVariable("75InActiveY22",0);   
  Control.addVariable("75InActiveY23",0);   
  Control.addVariable("75InActiveY24",0);   
  Control.addVariable("75InActiveY25",0);   
  Control.addVariable("75InActiveY26",0);   
  Control.addVariable("75InActiveY27",0);   
  Control.addVariable("75InActiveY28",0);   
  Control.addVariable("75InActiveY29",0);   
  Control.addVariable("75InActiveY30",0);   
  Control.addVariable("75InActiveY31",0);   
  Control.addVariable("75InActiveY32",0);   
  Control.addVariable("75InActiveY33",0);   
  Control.addVariable("75InActiveY34",0);   
  Control.addVariable("75InActiveY35",0);   
  Control.addVariable("75InActiveY36",0);   
  Control.addVariable("75InActiveY37",1);   
  Control.addVariable("75InActiveY38",0);   
  Control.addVariable("75InActiveY39",1);   
  Control.addVariable("75InActiveY40",1);   


  //Spectrometer
  Control.addVariable("75IcMat","Void");  
  Control.addVariable("75IcDiam",1.27);   
  Control.addVariable("75IcThick",0.015); 
  //
  // active detector positions along Y axis
  Control.addVariable("75IcActiveY0",0);   
  Control.addVariable("75IcActiveY1",0);   
  Control.addVariable("75IcActiveY2",0);   
  Control.addVariable("75IcActiveY3",0);   
  Control.addVariable("75IcActiveY4",0);   
  Control.addVariable("75IcActiveY5",0);   
  Control.addVariable("75IcActiveY6",0);   
  Control.addVariable("75IcActiveY7",0);   
  Control.addVariable("75IcActiveY8",0);   
  Control.addVariable("75IcActiveY9",0);   
  Control.addVariable("75IcActiveY10",0);   
  Control.addVariable("75IcActiveY11",0);   
  Control.addVariable("75IcActiveY12",0);   
  Control.addVariable("75IcActiveY13",0);   
  Control.addVariable("75IcActiveY14",0);   
  Control.addVariable("75IcActiveY15",0);   
  Control.addVariable("75IcActiveY16",0);   
  Control.addVariable("75IcActiveY17",0);   
  Control.addVariable("75IcActiveY18",0);   
  Control.addVariable("75IcActiveY19",0);   
  Control.addVariable("75IcActiveY20",0);   
  Control.addVariable("75IcActiveY21",0);   
  Control.addVariable("75IcActiveY22",0);   
  Control.addVariable("75IcActiveY23",0);   
  Control.addVariable("75IcActiveY24",0);   
  Control.addVariable("75IcActiveY25",0);   
  Control.addVariable("75IcActiveY26",0);   
  Control.addVariable("75IcActiveY27",0);   
  Control.addVariable("75IcActiveY28",0);   
  Control.addVariable("75IcActiveY29",0);   
  Control.addVariable("75IcActiveY30",0);   
  Control.addVariable("75IcActiveY31",0);   
  Control.addVariable("75IcActiveY32",0);   
  Control.addVariable("75IcActiveY33",1);   
  Control.addVariable("75IcActiveY34",0);   
  Control.addVariable("75IcActiveY35",0);   
  Control.addVariable("75IcActiveY36",0);   
  Control.addVariable("75IcActiveY37",1);   
  Control.addVariable("75IcActiveY38",0);   
  Control.addVariable("75IcActiveY39",1);   
  Control.addVariable("75IcActiveY40",1);   




  //Cd
  Control.addVariable("75CdMat","75Cd");  
  Control.addVariable("75CdDiam",1.27);   
  Control.addVariable("75CdThick",0.127);





  return;
 }

}  // NAMESPACE setVariable
