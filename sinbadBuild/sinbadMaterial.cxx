#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cmath>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <boost/bind.hpp>
#include <boost/tuple/tuple.hpp>

#include "Exception.h"
#include "FileReport.h"
#include "GTKreport.h"
#include "NameStack.h"
#include "RegMethod.h"
#include "OutputLog.h"
#include "support.h"
#include "BaseVisit.h"
#include "BaseModVisit.h"
#include "Element.h"
#include "Zaid.h"
#include "MXcards.h"
#include "Material.h"
#include "DBMaterial.h"
#include "sinbadMaterial.h"

namespace ModelSupport
{

  void addSinbadMaterial(std::string& lib,std::string& expNum)
  /*!
     Initialize the database of materials
   */
{
  ELog::RegMethod RegA("sinbadMaterial","addSinbadMaterial");

  // Get Main database
  DBMaterial& DBObj=DBMaterial::Instance();
 
  std::string ext;
  if(lib=="ENDF/B-VII.1") ext=".80c";
  else if (lib=="ENDF/B-VII.0") ext=".70c";
  else if (lib=="JEFF3.2") ext=".31c";
  else  ext=lib;

  const std::string MLib="";

  ELog::EM<<" Transport data library: "<<lib<<"  file extention: "<<ext<<ELog::endBasic;
  ELog::EM<<" Dosimetry file: IRDFF-v1.05    "<<ELog::endBasic;
 ELog::EM<<"\n "<<ELog::endBasic;

  MonteCarlo::Material MObj;


  ///////////////////////  EXPERIMENT 35 /////////////////////////////
  if(expNum=="35")
    {
  MObj.setMaterial(1,"35MildSteel1", 
     "  6000"+ext+"  8.6424E-04 "
     " 14028"+ext+"  6.1977E-05 "
     " 14029"+ext+"  3.1470E-06 "
     " 14030"+ext+"  2.0745E-06 "
     " 25055"+ext+"  9.3612E-04 "
     " 26054"+ext+"  4.8717E-03 "
     " 26056"+ext+"  7.6475E-02 "
     " 26057"+ext+"  1.7661E-03 "
     " 26058"+ext+"  2.3504E-04 ",
 		        "","");

  DBObj.resetMaterial(MObj);
  MObj.setMaterial(2,"35Aluminium2",
    " 13027"+ext+"  6.0261E-02 " ,
              	         "","");

  DBObj.resetMaterial(MObj);
  MObj.setMaterial(3,"35Graphite",
    "  6000"+ext+"  8.2729E-02 ",
 	       "grph.20t","");

  DBObj.resetMaterial(MObj);
  MObj.setMaterial(4,"35Fuel",
     " 13027"+ext+"  5.8122E-02 "
     " 92235"+ext+"  1.5550E-03 "
     " 92238"+ext+"  1.1367E-04 " ,
           	        "","");

  DBObj.resetMaterial(MObj);
  MObj.setMaterial(5,"35Aluminium5",
    " 13027"+ext+"  5.9080E-02 "
     " 14028"+ext+"  7.9083E-05 "
     " 14029"+ext+"  4.0156E-06 "
     " 14030"+ext+"  2.6471E-06 "
     " 26054"+ext+"  9.4100E-06 "
     " 26056"+ext+"  1.4772E-04 "
     " 26057"+ext+"  3.4114E-06 "
     " 26058"+ext+"  4.5400E-07 ",
                         "","");
 
  DBObj.resetMaterial(MObj);
  MObj.setMaterial(6,"35MildSteel6",
     " 26054"+ext+"  4.8998E-03 "
     " 26056"+ext+"  7.6916E-02 "
     " 26057"+ext+"  1.7763E-03 "
     " 26058"+ext+"  2.3640E-04 "
     " 25055"+ext+"  6.3675E-04 "
     "  6000"+ext+"  9.0525E-04 ",
                        "","");

  DBObj.resetMaterial(MObj);
  MObj.setMaterial(7,"35StainlessSteel",
     "  6000"+ext+"  9.0525E-04 "
     " 14028"+ext+"  7.8282E-04 "
     " 14029"+ext+"  3.9750E-05 "
     " 14030"+ext+"  2.6203E-05 "
     " 15031"+ext+"  4.6177E-05 "
     " 16032"+ext+"  2.8230E-05 "
     " 16033"+ext+"  2.2600E-07 "
     " 16034"+ext+"  1.2757E-06 "
     " 16036"+ext+"  5.9474E-09 "
     " 24050"+ext+"  6.6812E-04 "
     " 24052"+ext+"  1.2884E-02 "
     " 24053"+ext+"  1.4609E-03 "
     " 24054"+ext+"  3.6366E-04 "
     " 25055"+ext+"  1.3625E-03 "
     " 26054"+ext+"  3.3408E-03 "
     " 26056"+ext+"  5.2444E-02 "
     " 26057"+ext+"  1.2112E-03 "
     " 26058"+ext+"  1.6118E-04 "
     " 28058"+ext+"  6.4478E-03 "
     " 28060"+ext+"  2.4837E-03 "
     " 28061"+ext+"  1.0796E-04 "
     " 28062"+ext+"  3.4424E-04 "
     " 28064"+ext+"  8.7667E-05 "
     " 42092"+ext+"  1.7994E-04 "
     " 42094"+ext+"  1.1216E-04 "
     " 42095"+ext+"  1.9303E-04 "
     " 42096"+ext+"  2.0225E-04 "
     " 42097"+ext+"  1.1580E-04 "
     " 42098"+ext+"  2.9258E-04 "
     " 42100"+ext+"  1.1677E-04 ",
             	             "","");

  DBObj.resetMaterial(MObj);
  MObj.setMaterial(8,"35Concrete",
     "  1001"+ext+"  1.3420E-02 " 
     "  1002"+ext+"  1.5435E-06 " 
     "  8016"+ext+"  4.4621E-02 "
     "  8017"+ext+"  1.0869E-04 "
     //8018 added to 8017
     // "  8017.71c  1.6997E-05 "
     // "  8018.71c  9.1696E-05 "
     " 11023"+ext+"  9.4741E-04 "
     " 13027"+ext+"  1.7047E-03 "
     " 14028"+ext+"  1.4967E-02 "
     " 14029"+ext+"  7.5999E-04 "
     " 14030"+ext+"  5.0099E-04 "
     " 19039"+ext+"  6.4536E-04 "
     " 19040"+ext+"  8.0966E-08 "
     " 19041"+ext+"  4.6574E-05 "
     " 20040"+ext+"  1.2402E-03 "
     " 20042"+ext+"  8.2772E-06 "
     " 20043"+ext+"  1.7271E-06 "
     " 20044"+ext+"  2.6687E-05 "
     " 20046"+ext+"  5.1173E-08 "
     " 20048"+ext+"  2.3923E-06 "
     " 26054"+ext+"  1.9965E-05 "
     " 26056"+ext+"  3.1340E-04 "
     " 26057"+ext+"  7.2379E-06 "
     " 26058"+ext+"  9.6323E-07 ",
                	         "","");

  DBObj.resetMaterial(MObj);
  MObj.setMaterial(101,"35S",
     " 16032"+ext+"  3.4287E-02 "
     " 16033"+ext+"  2.7450E-04 "
     " 16034"+ext+"  1.5495E-03 "
     " 16036"+ext+"  7.2236E-06 ",
 		   "",MLib);
  //  MObj.setDensity(3.6118E-02);
 
  DBObj.resetMaterial(MObj);
  MObj.setMaterial(102,"35Spressed",
     " 16032"+ext+"  3.2443E-02 "
     " 16033"+ext+"  2.5974E-04 "
     " 16034"+ext+"  1.4661E-03 "
     " 16036"+ext+"  6.8352E-06 ",
 		      "",MLib);
  //  MObj.setDensity(3.4176E-02);

  DBObj.resetMaterial(MObj);
  MObj.setMaterial(103,"35Rh",
    " 45103"+ext+"  7.2625e-02 ",
		     "",MLib);
  //  MObj.setDensity(7.2625E-02);

  DBObj.resetMaterial(MObj);
  MObj.setMaterial(104,"35Mn",
    " 25055"+ext+"  7.9034E-02 ",
		     "",MLib);
  //  MObj.setDensity(7.9034E-02);

  DBObj.resetMaterial(MObj);
  MObj.setMaterial(105,"35Au",
    " 79197"+ext+"  5.9009E-02 ",
		     "",MLib);
  //  MObj.setDensity(5.9009E-02);

  DBObj.resetMaterial(MObj);
  MObj.setMaterial(106,"35Cd",
     " 48106"+ext+"  5.7925E-04 "  
     " 48108"+ext+"  4.1243E-04 "
     " 48110"+ext+"  5.7879E-03 " 
     " 48111"+ext+"  5.9315E-03 "
     " 48112"+ext+"  1.1182E-02 "
     " 48113"+ext+"  5.6628E-03 "  
     " 48114"+ext+"  1.3314E-02 " 
     " 48116"+ext+"  3.4709E-03 ",
         	     "",MLib);
  //  MObj.setDensity(4.6340E-02);
 
  DBObj.resetMaterial(MObj);
  MObj.setMaterial(107,"35In",
      " 49113"+ext+"  1.5568E-03 "
      " 49115"+ext+"  3.4731E-02 ",
		     "",MLib);

  DBObj.resetMaterial(MObj);
  MObj.setMaterial(108,"35AlHolder",
    " 13027"+ext+"  6.0261E-02 ",
 		     "",MLib);

  DBObj.resetMaterial(MObj);
  MObj.setMaterial(109,"35AlDet",
  " 13027"+ext+"  6.1308E-02 ",
 		     "",MLib);
  DBObj.resetMaterial(MObj);

    }
  ///////////////////////  EXPERIMENT 36 /////////////////////////////

  if(expNum=="36")
    {
  MObj.setMaterial(1,"36Graphite1", 
         "  6000"+ext+"  8.2729E-02 ",
 	   	    "grph.20t","");

  DBObj.resetMaterial(MObj);
  MObj.setMaterial(2,"36Graphite2",
         "  6000"+ext+"  8.0723E-02 ",
              	    "grph.20t","");

  DBObj.resetMaterial(MObj);
  MObj.setMaterial(3,"36Graphite3",
         "  6000"+ext+"  8.8545E-02 ",
     	            "grph.20t","");

  DBObj.resetMaterial(MObj);
  MObj.setMaterial(4,"36Aluminium",
         " 13027"+ext+"  6.0261E-02 ",
              	            "","");
 
  DBObj.resetMaterial(MObj);
  MObj.setMaterial(5,"36Fuel",
          " 13027"+ext+"  5.8122E-02 "
          " 92235"+ext+"  1.5516E-03 "
          " 92238"+ext+"  1.1531E-04 ",
                        "","");

  DBObj.resetMaterial(MObj);
  MObj.setMaterial(6,"36MildSteel",
        "  6000"+ext+"  8.6426E-04 "
        " 15031"+ext+"  1.5233E-05 "
        " 16032"+ext+"  4.4700E-05 "
        " 16033"+ext+"  3.5787E-07 "
        " 16034"+ext+"  2.0201E-06 "
        " 16036"+ext+"  9.4176E-09 "
        " 25055"+ext+"  9.3615E-04 "
        " 26054"+ext+"  4.8717E-03 "
        " 26056"+ext+"  7.6475E-02 "
        " 26057"+ext+"  1.7661E-03 "
        " 26058"+ext+"  2.3504E-04 ",
             	             "","");

  DBObj.resetMaterial(MObj);
  MObj.setMaterial(7,"36Concrete",
     "  1001"+ext+"  1.3740E-02 " 
     "  1002"+ext+"  1.5803E-06 "
     "  8016"+ext+"  4.5685E-02 "
     "  8017"+ext+"  1.1129E-04 "
     // "  8017"+ext+"  1.7403E-05 "
     // "  8018"+ext+"  9.3882E-05 "
     " 11023"+ext+"  9.6397E-04 "
     " 13027"+ext+"  1.7454E-03 "
     " 14028"+ext+"  1.5328E-02 "
     " 14029"+ext+"  7.7834E-04 "
     " 14030"+ext+"  5.1309E-04 "
     " 19039"+ext+"  5.2860E-04 "
     " 19040"+ext+"  6.6317E-08 "
     " 19041"+ext+"  3.8148E-05 "
     " 20040"+ext+"  1.4741E-03 "
     " 20042"+ext+"  9.8385E-06 "
     " 20043"+ext+"  2.0529E-06 "
     " 20044"+ext+"  3.1720E-05 "
     " 20046"+ext+"  6.0825E-08 "
     " 20048"+ext+"  2.8436E-06 "
     " 26054"+ext+"  2.0296E-05 "
     " 26056"+ext+"  3.1860E-04 "
     " 26057"+ext+"  7.3579E-06 "
     " 26058"+ext+"  9.7920E-07 ",
             	         "","");
  //detectors
  DBObj.resetMaterial(MObj);
  MObj.setMaterial(101,"36S",
     " 16032"+ext+"  3.4287E-02 "
     " 16033"+ext+"  2.7450E-04 "
     " 16034"+ext+"  1.5495E-03 "
     " 16036"+ext+"  7.2236E-06 ",
 		   "",MLib);
  //  MObj.setDensity(3.6118E-02);
 
  DBObj.resetMaterial(MObj);
  MObj.setMaterial(102,"36Spressed",
     " 16032"+ext+"  3.2443E-02 "
     " 16033"+ext+"  2.5974E-04 "
     " 16034"+ext+"  1.4661E-03 "
     " 16036"+ext+"  6.8352E-06 ",
 		      "",MLib);
  //  MObj.setDensity(3.4176E-02);

  DBObj.resetMaterial(MObj);
  MObj.setMaterial(103,"36Rh",
    " 45103"+ext+"  7.2625e-02 ",
		     "",MLib);
  //  MObj.setDensity(7.2625E-02);

  DBObj.resetMaterial(MObj);
  MObj.setMaterial(104,"36Mn",
    " 25055"+ext+"  7.9034E-02 ",
		     "",MLib);
  //  MObj.setDensity(7.9034E-02);

  DBObj.resetMaterial(MObj);
  MObj.setMaterial(105,"36Au",
    " 79197"+ext+"  5.9009E-02 ",
		     "",MLib);
  //  MObj.setDensity(5.9009E-02);

  DBObj.resetMaterial(MObj);
  MObj.setMaterial(106,"36Cd",
     " 48106"+ext+"  5.7925E-04 "  
     " 48108"+ext+"  4.1243E-04 "
     " 48110"+ext+"  5.7879E-03 " 
     " 48111"+ext+"  5.9315E-03 "
     " 48112"+ext+"  1.1182E-02 "
     " 48113"+ext+"  5.6628E-03 "  
     " 48114"+ext+"  1.3314E-02 " 
     " 48116"+ext+"  3.4709E-03 ",
         	     "",MLib);
  //  MObj.setDensity(4.6340E-02);
 
  DBObj.resetMaterial(MObj);
  MObj.setMaterial(107,"36In",
      " 49113"+ext+"  1.5568E-03 "
      " 49115"+ext+"  3.4731E-02 ",
		     "",MLib);

  DBObj.resetMaterial(MObj);
  MObj.setMaterial(108,"36AlHolder",
    " 13027"+ext+"  6.0261E-02 ",
 		     "",MLib);

  DBObj.resetMaterial(MObj);
  MObj.setMaterial(109,"36AlDet",
  " 13027"+ext+"  6.1308E-02 ",
 		     "",MLib);
  DBObj.resetMaterial(MObj);

    }



  ///////////////////////  EXPERIMENT 49 /////////////////////////////
  if(expNum=="49")
   {
    MObj.setMaterial(1,"49MildSteel1", 
     " 6000"+ext+"   0.00086921 "
     //GRAPHITE ISOTOPES
     // "  6012"+ext+"  8.5991E-04 "             
     // "  6013"+ext+"  9.3006E-06 "              
     " 14028"+ext+"  5.5017e-05  " 
     " 14029"+ext+"  2.7936E-06 "
     " 14030"+ext+"  1.8416e-06 "
     " 25055"+ext+"  0.00093739 "
     " 26054"+ext+"  0.0048719 "
     " 26056"+ext+"  0.076478 "
     " 26057"+ext+"  0.0017662 "
     " 26058"+ext+"  0.00023505 ",
 		        "","");
  // MObj.setDensity(0.085217l);
  // MObj.setDensity(-7.835);

  DBObj.resetMaterial(MObj);


  MObj.setMaterial(2,"49Lead",
      " 82204"+ext+"  4.6183E-04 "
      " 82206"+ext+"  7.9501E-03 "
      " 82207"+ext+"  7.2904E-03 "
      " 82208"+ext+"  1.7286E-02 ",
             	         "","");
  //  MObj.setDensity(3.2988e-02);

  DBObj.resetMaterial(MObj);


  MObj.setMaterial(3,"49Graphite",
    " 6000"+ext+"   8.2730E-02 ",
 // "  6012"+ext+"  8.1845E-02 "
 // "  6013"+ext+"  8.8522E-04 " ,
	       "grph.20t","");
  // MObj.setDensity(8.2731E-02);
  DBObj.resetMaterial(MObj);


  MObj.setMaterial(4,"49Fuel",
    " 13027"+ext+"  5.8127E-02 "
    " 92235"+ext+"  1.5547E-03 "
    " 92238"+ext+"  1.1361E-04 " ,
          	        "","");
  // MObj.setDensity(5.9795E-02);
  DBObj.resetMaterial(MObj);



  MObj.setMaterial(5,"49Aluminium",
         " 13027"+ext+"  5.9086E-02 " 
         " 14028"+ext+"  7.6607E-05 " 
         " 14029"+ext+"  3.8899E-06 " 
         " 14030"+ext+"  2.5642E-06 " 
         " 26054"+ext+"  9.3630E-06 " 
         " 26056"+ext+"  1.4698E-04 " 
         " 26057"+ext+"  3.3944E-06 " 
         " 26058"+ext+"  4.5173E-07 ", 
                 	    "","");
  //  MObj.setDensity(5.9329E-02);
  DBObj.resetMaterial(MObj);


  MObj.setMaterial(6,"49Boral",
     "  5010"+ext+"  4.4316E-03 "
     "  5011"+ext+"  1.7712E-02 "
     " 6000"+ext+"   5.4576E-03 "
  // "  6012"+ext+"  5.3992E-03 "
  // "  6013"+ext+"  5.8397E-05 "
     " 13027"+ext+"  4.5167E-02 ",  
                        "","");
  //  MObj.setDensity(7.2768E-02);
  DBObj.resetMaterial(MObj);


  MObj.setMaterial(7,"49MildSteel7",
          "  1001"+ext+"  2.5616E-05 " 
          "  1002"+ext+"  2.9462E-09 " 
          "  6000"+ext+"  9.0522E-04 "
       // "  6012"+ext+"  8.9553E-04 " 
       // "  6013"+ext+"  9.6858E-06 " 
          " 25055"+ext+"  6.4048E-04 " 
          " 26054"+ext+"  4.8997E-03 " 
          " 26056"+ext+"  7.6914E-02 " 
          " 26057"+ext+"  1.7763E-03 " 
          " 26058"+ext+"  2.3639E-04 ", 
             	             "","");
  // MObj.setDensity(8.5398E-02);
  DBObj.resetMaterial(MObj);


  MObj.setMaterial(8,"49StainlessSteel",
              "  6000"+ext+"  7.7436E-05 "
           // "  6012"+ext+"  7.6607E-05 " 
           // "  6013"+ext+"  8.2856E-07 "
              " 15031"+ext+"  4.3020E-05 "
              " 16032"+ext+"  8.1678E-06 "
              " 16033"+ext+"  6.5390E-08 "
              " 16034"+ext+"  3.6911E-07 "
              " 16036"+ext+"  1.7208E-09 "
              " 22046"+ext+"  1.0222E-04 "
              " 22047"+ext+"  9.2180E-05 "
              " 22048"+ext+"  9.1337E-04 "
              " 22049"+ext+"  6.7029E-05 "
              " 22050"+ext+"  6.4179E-05 "
              " 24050"+ext+"  7.1591E-04 "
              " 24052"+ext+"  1.3806E-02 "
              " 24053"+ext+"  1.5654E-03 "
              " 24054"+ext+"  3.8967E-04 "
              " 25055"+ext+"  1.2304E-03 "
              " 26054"+ext+"  3.4494E-03 "
              " 26056"+ext+"  5.4148E-02 "
              " 26057"+ext+"  1.2505E-03 "
              " 26058"+ext+"  1.6642E-04 "
              " 28058"+ext+"  5.5938E-03 "
              " 28060"+ext+"  2.1547E-03 "
              " 28061"+ext+"  9.3664E-05 "
              " 28062"+ext+"  2.9864E-04 "
              " 28064"+ext+"  7.6055E-05 ",   
                	         "","");
  // MObj.setDensity(8.6307E-02);
  DBObj.resetMaterial(MObj);


  MObj.setMaterial(9,"49Water",
     "  1001"+ext+"  6.6857E-02 "
     "  1002"+ext+"  7.6895E-06 "
     "  8016"+ext+"  3.3346E-02 "
     "  8017"+ext+"  8.1228E-05 ",
  // sum of 17 and 18 
  // "  8017"+ext+"  1.2702E-05 "
  // "  8018"+ext+"  6.8526E-05 ",
             	         "lwtr.20t","");
  //  MObj.setDensity(1.0029E-01);
  DBObj.resetMaterial(MObj);


  MObj.setMaterial(10,"49MildSteel10",
            "  6000"+ext+"  1.6983E-04 "
         // "  6012"+ext+"  1.6801E-04 "
         // "  6013"+ext+"  1.8172E-06 "
            " 15031"+ext+"  1.6983E-05 "
            " 16032"+ext+"  2.4183E-05 "
            " 16033"+ext+"  1.9361E-07 "
            " 16034"+ext+"  1.0929E-06 "
            " 16036"+ext+"  5.0949E-09 "
            " 25055"+ext+"  1.9530E-04 "
            " 26054"+ext+"  4.9394E-03 "
            " 26056"+ext+"  7.7539E-02 "
            " 26057"+ext+"  1.7907E-03 "
            " 26058"+ext+"  2.3831E-04 ",       
             	               "","");
  //  MObj.setDensity(8.4915E-02);
  DBObj.resetMaterial(MObj);


  MObj.setMaterial(11,"49Concrete",
         "  1001"+ext+"  1.3905E-02 " 
         "  1002"+ext+"  1.5993E-06 "
         "  8016"+ext+"  4.7111E-02 "
         "  8017"+ext+"  1.1476E-04 "
      // "  8017"+ext+"  1.7946E-05 "
      // "  8018"+ext+"  9.6812E-05 "
         " 11023"+ext+"  9.7923E-04 "
         " 13027"+ext+"  1.7692E-03 "
         " 14028"+ext+"  1.5513E-02 "
         " 14029"+ext+"  7.8770E-04 "
         " 14030"+ext+"  5.1926E-04 "
         " 20040"+ext+"  1.2843E-03 "
         " 20042"+ext+"  8.5718E-06 "
         " 20043"+ext+"  1.7885E-06 "
         " 20044"+ext+"  2.7636E-05 "
         " 20046"+ext+"  5.2994E-08 "
         " 20048"+ext+"  2.4775E-06 "
         " 26054"+ext+"  2.0682E-05 "
         " 26056"+ext+"  3.2466E-04 "
         " 26057"+ext+"  7.4979E-06 "
         " 26058"+ext+"  9.9783E-07 ",
                             "","");
  //  MObj.setDensity(8.2379E-02);
  DBObj.resetMaterial(MObj);


  MObj.setMaterial(101,"49S",
     " 16032"+ext+"  3.4287E-02 "
     " 16033"+ext+"  2.7450E-04 "
     " 16034"+ext+"  1.5495E-03 "
     " 16036"+ext+"  7.2236E-06 ",
 		   "",MLib);
  MObj.setDensity(3.6118E-02);
  DBObj.resetMaterial(MObj);


  MObj.setMaterial(102,"49Spressed",
     " 16032"+ext+"  3.2443E-02 "
     " 16033"+ext+"  2.5974E-04 "
     " 16034"+ext+"  1.4661E-03 "
     " 16036"+ext+"  6.8352E-06 ",
 		      "",MLib);
  MObj.setDensity(3.4176E-02);
  DBObj.resetMaterial(MObj);


  MObj.setMaterial(103,"49Rh",
    " 45103"+ext+"  7.2625e-02 ",
		     "",MLib);
  //  MObj.setDensity(7.2625E-02);
  DBObj.resetMaterial(MObj);


  MObj.setMaterial(104,"49Mn",
    " 25055"+ext+"  7.9034E-02 ",
		     "",MLib);
  MObj.setDensity(7.9034E-02);
  DBObj.resetMaterial(MObj);


  MObj.setMaterial(105,"49Au",
    " 79197"+ext+"  5.9009E-02 ",
		     "",MLib);
  MObj.setDensity(5.9009E-02);
  DBObj.resetMaterial(MObj);


  MObj.setMaterial(106,"49Cd",
     " 48106"+ext+"  5.7925E-04 "  
     " 48108"+ext+"  4.1243E-04 "
     " 48110"+ext+"  5.7879E-03 " 
     " 48111"+ext+"  5.9315E-03 "
     " 48112"+ext+"  1.1182E-02 "
     " 48113"+ext+"  5.6628E-03 "  
     " 48114"+ext+"  1.3314E-02 " 
     " 48116"+ext+"  3.4709E-03 ",
         	     "",MLib);
  //  MObj.setDensity(4.6340E-02);
  DBObj.resetMaterial(MObj);


  MObj.setMaterial(107,"49LiF",
    " 3006"+ext+"  4.5968E-03 "
    " 3007"+ext+"  5.6694E-02 "
    " 9018"+ext+"  6.1290E-02 ",
		     "",MLib);
  //  MObj.setDensity(7.2625E-02);
  // assumed density in matssf = 2.65 g/cm3
  DBObj.resetMaterial(MObj);


  MObj.setMaterial(108,"49BeO",
    " 4009"+ext+"  2.4077E-02"
    " 8016"+ext+"  2.4077E-02",
		     "",MLib);
  //  MObj.setDensity(7.2625E-02);
  // assumed temtative density in matssf = 3 g/cm3
  DBObj.resetMaterial(MObj);
    }

  ///////////////////////  EXPERIMENT 75 /////////////////////////////

  if(expNum=="75")
   {
    MObj.setMaterial(1,"75Graphite",
    "  1001"+ext+"  6.6857E-02 "
    "  1002"+ext+"  7.6895E-06 "
    "  8016"+ext+"  3.3346E-02 "
     // b71 8018 use models: 8018 added to 8017
    "  8017"+ext+"  8.1228E-05 ",
            	        "","");
    DBObj.resetMaterial(MObj);


    MObj.setMaterial(2,"75Aluminium",
    " 13027"+ext+"  6.0290E-02 ",
             	         "","");
    DBObj.resetMaterial(MObj);


    MObj.setMaterial(3,"75Fuel",
    " 13027"+ext+"  5.8180E-02 "
    " 92235"+ext+"  1.5520E-03 "
    " 92238"+ext+"  1.1540E-04 ",
	                  "","");
    DBObj.resetMaterial(MObj);

    MObj.setMaterial(4,"75H2O",
    "  1001"+ext+"  6.6857E-02 "
    "  1002"+ext+"  7.6895E-06 "
    "  8016"+ext+"  3.3346E-02 "
    // 8018 added to 8017
    "  8017"+ext+"  8.1228E-05 ",
            	        "","");
    DBObj.resetMaterial(MObj);



  MObj.setMaterial(5,"75StainlessSteel",
     "  6000"+ext+"  6.7168E-05 "
     " 14028"+ext+"  6.8568E-04 " 
     " 14029"+ext+"  3.4817E-05 " 
     " 14030"+ext+"  2.2952E-05 " 
     // copiato da compilazione sinbad
     " 15031"+ext+"  3.8320E-05 "
     " 16032"+ext+"  8.4295E-06 "
     " 16033"+ext+"  6.7486E-08 "
     " 16034"+ext+"  3.8094E-07 "
     " 16036"+ext+"  1.7759E-09 "
     " 22046"+ext+"  7.3610E-07 "
     " 22047"+ext+"  6.6383E-07 "
     " 22048"+ext+"  6.5776E-06 "
     " 22049"+ext+"  4.8270E-07 "
     " 22050"+ext+"  4.6218E-07 "
     " 24050"+ext+"  7.2965E-04 "
     " 24052"+ext+"  1.4071E-02 "
     " 24053"+ext+"  1.5955E-03 "
     " 24054"+ext+"  3.9715E-04 "
     " 25055"+ext+"  1.3561E-03 "
     " 26054"+ext+"  3.4524E-03 "
     " 26056"+ext+"  5.4195E-02 "
     " 26057"+ext+"  1.2516E-03 "
     " 26058"+ext+"  1.6656E-04 "
     " 28058"+ext+"  5.1739E-03 "
     " 28060"+ext+"  1.9930E-03 "
     " 28061"+ext+"  8.6633E-05 "
     " 28062"+ext+"  2.7622E-04 "
     " 28064"+ext+"  7.0346E-05 ",
                   	    "","");
     DBObj.resetMaterial(MObj);


     MObj.setMaterial(6,"75MildSteel",
     "  6000"+ext+"  8.6426E-04 "
     // "  6012.  8.5501E-04 " 
     // "  6013.  9.2476E-06 "
     " 15031"+ext+"  1.5233E-05 "
     " 16032"+ext+"  4.4700E-05 "
     " 16033"+ext+"  3.5787E-07 "
     " 16034"+ext+"  2.0201E-06 "
     " 16036"+ext+"  9.4176E-09 "
     " 25055"+ext+"  9.3615E-04 "
     " 26054"+ext+"  4.8717E-03 "
     " 26056"+ext+"  7.6475E-02 "
     " 26057"+ext+"  1.7661E-03 "
     " 26058"+ext+"  2.3504E-04 ",
                        "","");
     DBObj.resetMaterial(MObj);

     MObj.setMaterial(7,"75Concrete",
     "  1001"+ext+"  1.3740E-02 " 
     "  1002"+ext+"  1.5803E-06 "
     "  8016"+ext+"  4.5685E-02 "
     "  8017"+ext+"  1.1129E-04 "
     " 11023"+ext+"  9.6397E-04 "
     " 13027"+ext+"  1.7454E-03 "
     " 14028"+ext+"  1.5328E-02 "
     " 14029"+ext+"  7.7834E-04 "
     " 14030"+ext+"  5.1309E-04 "
     " 19039"+ext+"  5.2860E-04 "
     " 19040"+ext+"  6.6317E-08 "
     " 19041"+ext+"  3.8148E-05 "
     " 20040"+ext+"  1.4741E-03 "
     " 20042"+ext+"  9.8385E-06 "
     " 20043"+ext+"  2.0529E-06 "
     " 20044"+ext+"  3.1720E-05 "
     " 20046"+ext+"  6.0825E-08 "
     " 20048"+ext+"  2.8436E-06 "
     " 26054"+ext+"  2.0296E-05 "
     " 26056"+ext+"  3.1860E-04 "
     " 26057"+ext+"  7.3579E-06 "
     " 26058"+ext+"  9.7920E-07 ",
                        "","");
     DBObj.resetMaterial(MObj);

     MObj.setMaterial(101,"75S",
     " 16032"+ext+"  3.4287E-02 "
     " 16033"+ext+"  2.7450E-04 "
     " 16034"+ext+"  1.5495E-03 "
     " 16036"+ext+"  7.2236E-06 ",
 		   "",MLib);
     DBObj.resetMaterial(MObj);


     MObj.setMaterial(102,"75Spressed",
     " 16032"+ext+"  3.2443E-02 "
     " 16033"+ext+"  2.5974E-04 "
     " 16034"+ext+"  1.4661E-03 "
     " 16036"+ext+"  6.8352E-06 ",
 		      "",MLib);
     DBObj.resetMaterial(MObj);


    MObj.setMaterial(103,"75Rh",
    " 45103"+ext+"  7.2625e-02 ",
		     "",MLib);
    DBObj.resetMaterial(MObj);


    MObj.setMaterial(104,"75Mn",
    " 25055"+ext+"  7.9034E-02 ",
		     "",MLib);
    DBObj.resetMaterial(MObj);


    MObj.setMaterial(105,"75Au",
    " 79197"+ext+"  5.9009E-02 ",
		     "",MLib);
    DBObj.resetMaterial(MObj);


    MObj.setMaterial(106,"75Cd",
     " 48106"+ext+"  5.7925E-04 "  
     " 48108"+ext+"  4.1243E-04 "
     " 48110"+ext+"  5.7879E-03 " 
     " 48111"+ext+"  5.9315E-03 "
     " 48112"+ext+"  1.1182E-02 "
     " 48113"+ext+"  5.6628E-03 "  
     " 48114"+ext+"  1.3314E-02 " 
     " 48116"+ext+"  3.4709E-03 ",
         	     "",MLib);
     DBObj.resetMaterial(MObj);


     MObj.setMaterial(107,"75In",
     " 49113"+ext+"  1.5568E-03 "
     " 49115"+ext+"  3.4731E-02 ",
         	     "",MLib);
     DBObj.resetMaterial(MObj);


   }






  return;
}

} // NAMESPACE ModelSupport
