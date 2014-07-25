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

void addSinbadMaterial()
  /*!
     Initialize the database of materials
   */
{
  ELog::RegMethod RegA("sinbadMaterial","addSinbadMaterial");

  // Get Main database
  DBMaterial& DBObj=DBMaterial::Instance();
 
  const std::string MLib="";

  MonteCarlo::Material MObj;
  MObj.setMaterial(1,"49MildSteel1", 
      "  6000.00c  8.6922E-04 "
     //GRAPHITE IS FROM ENDFB70
     // "  6012.71c  8.5991E-04 "             
     // "  6013.71c  9.3006E-06 "              
     " 14028.71c  5.5017E-05 " 
     " 14029.71c  2.7936E-06 "
     " 14030.71c  1.8416E-06 "
     " 25055.71c  9.3739E-04 "
     " 26054.71c  4.8719E-03 "
     " 26056.71c  7.6478E-02 "
     " 26057.71c  1.7662E-03 "
     " 26058.71c  2.3505E-04 ",
 		        "","");
  MObj.setDensity(8.5217e-02);
  // MObj.setDensity(-7.835);

  DBObj.resetMaterial(MObj);


  MObj.setMaterial(2,"49Lead",
      " 82204.71c  4.6183E-04 "
      " 82206.71c  7.9501E-03 "
      " 82207.71c  7.2904E-03 "
      " 82208.71c  1.7286E-02 ",
             	         "","");
  MObj.setDensity(3.2988e-02);
  DBObj.resetMaterial(MObj);


  MObj.setMaterial(3,"49Graphite",
    " 6000.00c   8.2730E-02 ",
 // "  6012.71c  8.1845E-02 "
 // "  6013.71c  8.8522E-04 " ,
	       "Graph.00t","");
  MObj.setDensity(8.2731E-02);
  DBObj.resetMaterial(MObj);


  MObj.setMaterial(4,"49Fuel",
    " 13027.71c  5.8127E-02 "
    " 92235.71c  1.5547E-03 "
    " 92238.71c  1.1361E-04 " ,
          	        "","");
  MObj.setDensity(5.9795E-02);
  DBObj.resetMaterial(MObj);


  MObj.setMaterial(5,"49Aluminium",
         " 13027.71c  5.9086E-02 " 
         " 14028.71c  7.6607E-05 " 
         " 14029.71c  3.8899E-06 " 
         " 14030.71c  2.5642E-06 " 
         " 26054.71c  9.3630E-06 " 
         " 26056.71c  1.4698E-04 " 
         " 26057.71c  3.3944E-06 " 
         " 26058.71c  4.5173E-07 ", 
                 	    "","");
  MObj.setDensity(5.9329E-02);
  DBObj.resetMaterial(MObj);


  MObj.setMaterial(6,"49Boral",
     "  5010.71c  4.4316E-03 "
     "  5011.71c  1.7712E-02 "
     " 6000.00c   5.4576E-03 "
  // "  6012.71c  5.3992E-03 "
  // "  6013.71c  5.8397E-05 "
     " 13027.71c  4.5167E-02 ",  
                        "","");
  MObj.setDensity(7.2768E-02);
  DBObj.resetMaterial(MObj);


  MObj.setMaterial(7,"49MildSteel7",
          "  1001.71c  2.5616E-05 " 
          "  1002.71c  2.9462E-09 " 
          "  6000.00c  9.0522E-04 "
       // "  6012.71c  8.9553E-04 " 
       // "  6013.71c  9.6858E-06 " 
          " 25055.71c  6.4048E-04 " 
          " 26054.71c  4.8997E-03 " 
          " 26056.71c  7.6914E-02 " 
          " 26057.71c  1.7763E-03 " 
          " 26058.71c  2.3639E-04 ", 
             	             "","");
  MObj.setDensity(8.5398E-02);
  DBObj.resetMaterial(MObj);


  MObj.setMaterial(8,"49StainlessSteel",
              "  6000.00c  7.7436E-05 "
           // "  6012.71c  7.6607E-05 " 
           // "  6013.71c  8.2856E-07 "
              " 15031.71c  4.3020E-05 "
              " 16032.71c  8.1678E-06 "
              " 16033.71c  6.5390E-08 "
              " 16034.71c  3.6911E-07 "
              " 16036.71c  1.7208E-09 "
              " 22046.71c  1.0222E-04 "
              " 22047.71c  9.2180E-05 "
              " 22048.71c  9.1337E-04 "
              " 22049.71c  6.7029E-05 "
              " 22050.71c  6.4179E-05 "
              " 24050.71c  7.1591E-04 "
              " 24052.71c  1.3806E-02 "
              " 24053.71c  1.5654E-03 "
              " 24054.71c  3.8967E-04 "
              " 25055.71c  1.2304E-03 "
              " 26054.71c  3.4494E-03 "
              " 26056.71c  5.4148E-02 "
              " 26057.71c  1.2505E-03 "
              " 26058.71c  1.6642E-04 "
              " 28058.71c  5.5938E-03 "
              " 28060.71c  2.1547E-03 "
              " 28061.71c  9.3664E-05 "
              " 28062.71c  2.9864E-04 "
              " 28064.71c  7.6055E-05 ",   
                	         "","");
  MObj.setDensity(8.6307E-02);
  DBObj.resetMaterial(MObj);


  MObj.setMaterial(9,"49Water",
     "  1001.71c  6.6857E-02 "
     "  1002.71c  7.6895E-06 "
     "  8016.71c  3.3346E-02 "
     "  8017.71c  8.1228E-05 ",
  // "  8017.71c  1.2702E-05 "
  // "  8018.71c  6.8526E-05 ",
             	         "","");
  MObj.setDensity(1.0029E-01);
  DBObj.resetMaterial(MObj);


  MObj.setMaterial(10,"49MildSteel10",
            "  6000.00c  1.6983E-04 "
         // "  6012.71c  1.6801E-04 "
         // "  6013.71c  1.8172E-06 "
            " 15031.71c  1.6983E-05 "
            " 16032.71c  2.4183E-05 "
            " 16033.71c  1.9361E-07 "
            " 16034.71c  1.0929E-06 "
            " 16036.71c  5.0949E-09 "
            " 25055.71c  1.9530E-04 "
            " 26054.71c  4.9394E-03 "
            " 26056.71c  7.7539E-02 "
            " 26057.71c  1.7907E-03 "
            " 26058.71c  2.3831E-04 ",       
             	               "","");
  MObj.setDensity(8.4915E-02);
  DBObj.resetMaterial(MObj);


  MObj.setMaterial(11,"49Concrete",
         "  1001.71c  1.3905E-02 " 
         "  1002.71c  1.5993E-06 "
         "  8016.71c  4.7111E-02 "
         "  8017.71c  1.1476E-04 "
      // "  8017.71c  1.7946E-05 "
      // "  8018.71c  9.6812E-05 "
         " 11023.71c  9.7923E-04 "
         " 13027.71c  1.7692E-03 "
         " 14028.71c  1.5513E-02 "
         " 14029.71c  7.8770E-04 "
         " 14030.71c  5.1926E-04 "
         " 20040.71c  1.2843E-03 "
         " 20042.71c  8.5718E-06 "
         " 20043.71c  1.7885E-06 "
         " 20044.71c  2.7636E-05 "
         " 20046.71c  5.2994E-08 "
         " 20048.71c  2.4775E-06 "
         " 26054.71c  2.0682E-05 "
         " 26056.71c  3.2466E-04 "
         " 26057.71c  7.4979E-06 "
         " 26058.71c  9.9783E-07 ",
                             "","");
  MObj.setDensity(8.2379E-02);
  DBObj.resetMaterial(MObj);







  MObj.setMaterial(204,"Rh","45103.71c  7.2625e-02 ",
		   "",MLib);
  DBObj.setMaterial(MObj);

  MObj.setMaterial(205,"Gold",
		   " 79197.71c  5.9009E-02 ",
		   "",MLib);
  DBObj.setMaterial(MObj);

     //M103 Rh


  return;
}

} // NAMESPACE ModelSupport
