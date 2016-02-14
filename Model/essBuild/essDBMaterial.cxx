/********************************************************************* 
  CombLayer : MCNP(X) Input builder
 
 * File:   essBuild/essDBMaterial.cxx
 *
 * Copyright (c) 2004-2015 by Stuart Ansell
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
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>

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
#include "essDBMaterial.h"

namespace ModelSupport
{

void addESSMaterial()
  /*!
     Initialize the database of materials
   */
{

  ELog::RegMethod RegA("essDBMaterial[F]","addESSMaterial");

  const std::string MLib="hlib=.70h pnlib=70u";
  ModelSupport::DBMaterial& MDB=ModelSupport::DBMaterial::Instance();

  MonteCarlo::Material MObj;
  // ESS materials

  MObj.setMaterial(1001,"HPARA"," 1001.70c 1.0 ","hpara.10t", MLib);
  MObj.setDensity(-7.0e-2);
  MDB.resetMaterial(MObj);
  
  MObj.setMaterial(1002,"HORTHO"," 1004.70c 1.0 ","hortho.10t", MLib);
  MObj.setDensity(-7.0e-2);
  MDB.resetMaterial(MObj);

  MObj.setMaterial(1003, "LH05ortho", " 1001.70c 99.5 "
                   "1004.70c 0.5 ","hpara.10t hortho.10t", MLib);
  MObj.setDensity(-7.0e-2*(0.07/0.0689677));
  // 0.07/0.0689677 because CL for some reason changes the density !!! todo !!!
  MDB.resetMaterial(MObj);

  // Generic light water
  // Simplified light water for  basic neutronic simulations
  MObj.setMaterial(110, "H2O", " 1001.70c 0.66666667 "
		   " 8016.70c 0.33333333 ", "lwtr.10t", MLib);
  MObj.setDensity(-1.0);
  MDB.resetMaterial(MObj);

  MObj.setMaterial(1300, "Aluminium", " 13027.70c 1.0 ", "al27.12t", MLib);
  MObj.setDensity(-2.7);
  MDB.resetMaterial(MObj); 

  MObj.setMaterial(1301, "Aluminium20K", " 13027.70c 1.0 ", "al27.10t", MLib);
  MObj.setDensity(-2.73);
  MDB.resetMaterial(MObj); 

  // ESS Iron
  MObj.setMaterial(2600, "Iron",
		   " 26054.70c  0.058450000 "
		   " 26056.70c  0.917540000 "
		   " 26057.70c  0.021190000 "
		   " 26058.70c  0.002820000 ", "fe56.12t", MLib);
  //  MObj.setMXitem(6000, 70, 'c', "h", "06012");
  MObj.setDensity(-7.85);
  MDB.resetMaterial(MObj);


  // ESS  SS316L
  MObj.setMaterial(2636, "SS316L",
		   " 06000.71c  0.001392603 "
		   " 14028.71c  0.007323064 "
		   " 14029.71c  0.000372017 "
		   " 14030.71c  0.000245523 "
		   " 15031.71c  0.000360008 "
		   " 16032.71c  0.000165168 "
		   " 16033.71c  0.000001304 "
		   " 16034.71c  0.000007390 "
		   " 16036.71c  0.000000017 "
		   " 24050.71c  0.007920331 "
		   " 24052.71c  0.152735704 "
		   " 24053.71c  0.017319003 "
		   " 24054.71c  0.004311066 "
		   " 25055.71c  0.018267327 "
		   " 26054.71c  0.038344779 "
		   " 26056.71c  0.601931034 "
		   " 26057.71c  0.013901213 "
		   " 26058.71c  0.001849996 "
		   " 27059.71c  0.000283816 "
		   " 28058.71c  0.080834464 "
		   " 28060.71c  0.031137291 "
		   " 28061.71c  0.001353516 "
		   " 28062.71c  0.004315603 "
		   " 28064.71c  0.001099057 "
		   " 42092.71c  0.002145890 "
		   " 42094.71c  0.001341000 "
		   " 42095.71c  0.002310064 "
		   " 42096.71c  0.002423388 "
		   " 42097.71c  0.001388944 "
		   " 42098.71c  0.003514494 "
		   " 42100.71c  0.001404926 ", "fe56.14t", MLib);
  MObj.setMXitem(6000, 71, 'c', "h", "06012");
  MObj.setDensity(-7.76);
  MDB.resetMaterial(MObj);

  // Be + 5% H2O coolant - generated by mixtures.py 7 May 2015
  MObj.setMaterial(4005, "Be5H2O",
		   " 1001.70c 0.0272983770406 "
		   " 4009.70c 0.959052434439 "
		   " 8016.70c 0.0136491885203 ", "lwtr.10t be.10t", MLib);
  MObj.setMXitem(4009,70,'c',"h","model");
  MObj.setDensity(-1.8075);
  MDB.resetMaterial(MObj);

  // Be + 10% H2O coolant
  MObj.setMaterial(4010, "Be10H2O",
		   " 1001.70c 0.055140611 "
		   " 4009.70c 0.91728908 "
		   " 8016.70c 0.027570305 ", "lwtr.10t be.10t", MLib);
  MObj.setMXitem(4009,70,'c',"h","model");
  MObj.setDensity(-1.76);
  MDB.resetMaterial(MObj);


  // ESS M74000 - same ase 74001 but at 300 K
  // T = 300 K
  MObj.setMaterial(7400, "Tungsten",
		   "74180.50c  0.001200000 "
		   "74182.71c  0.265000000 "
		   "74183.71c  0.143100000 "
		   "74184.71c  0.306400000 "
		   "74186.71c  0.284300000 ",
		   "",MLib);
  MObj.setDensity(-19.3);
  MDB.resetMaterial(MObj);  

  
  
  return;
}

} // NAMESPACE ModelSupport