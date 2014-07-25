/********************************************************************* 
  CombLayer : MNCPX Input builder
 
 * File:   essBuild/essDBMaterial.cxx
*
 * Copyright (c) 2004-2013 by Stuart Ansell
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
#include "essDBMaterial.h"

namespace ModelSupport
{

void addESSMaterial()
  /*!
     Initialize the database of materials
   */
{

  ELog::RegMethod RegA("essDBMaterial[F]","addESSMaterial");
  ELog::EM<<"ESS Materials LOADED "<<ELog::endWarn;
  //  return;

  const std::string MLib="hlib=.70h pnlib=70u";

  ModelSupport::DBMaterial& MDB=
    ModelSupport::DBMaterial::Instance();

  MonteCarlo::Material MObj;



  // M01001 (75) h2
  MObj.setMaterial(1001,"EssH2"," 1001.70c 1.000000000 ",
                                 " HPARA.10T "," ");
  // MObj.setDensity(-7.00E-02);
  MObj.setDensity(4.18270E-02);
  MDB.resetMaterial(MObj);


  // M01015 (76) h2o
  MObj.setMaterial(1015,"EssH2O"," 1001.70c 0.666562842 "
		                  " 1002.70c 0.000103824 8016.70c 0.332540192 "
                                  " 8017.70c 0.000126332 8018.70c 0.000666810 ",
                                  " LWTR.10T "," ");
  //  MObj.setDensity(-1.0);
  MObj.setDensity(1.00282E-01);
  MDB.resetMaterial(MObj);

 
  // M02000 (77) He in Monolith
  MObj.setMaterial(2000,"EssHeMono"," 2003.70c 0.00000134 "
                                     " 2004.70c 0.99999866 " ,
                                     " "," ");
  //  MObj.setDensity(-1.74E-04);
  MObj.setDensity(2.61789E-05);
  MDB.resetMaterial(MObj);  


  // M02001 (78) He in PBW
  MObj.setMaterial(2001,"EssHePBW"," 2003.70c 0.00000134 "
                		    " 2004.70c 0.99999866 " ,
		                    " "," ");
  //  MObj.setDensity(-1.72E-03);
  MObj.setDensity(2.58780E-04);
  MDB.resetMaterial(MObj);


  // M02002 (79) He in target
  MObj.setMaterial(2002,"EssHeTarget"," 2003.70c 0.00000134 "
                                       " 2004.70c 0.99999866 " ,
                                       " "," ");
  //  MObj.setDensity(-2.58E-04);
  MObj.setDensity(3.88169E-05);
  MDB.resetMaterial(MObj);


  //M04000 (80) Be
  MObj.setMaterial(4000,"EssBe"," 4009.70c 1.0 ",
                              " BE.10T "," ");
  //  MObj.setDensity(-1.85);
  MObj.setDensity(1.23619E-01);
  MDB.resetMaterial(MObj);


  //M13060 (81) Al60
  MObj.setMaterial(13060,"EssAl60"," 12024.70c 0.008812087 "
                                   " 12025.70c 0.001115595  12026.70c 0.001228270 "
                                   " 13027.70c 0.977848644  14028.70c 0.005342094 "
                                   " 14029.70c 0.000271383  14030.70c 0.000179107 "
                                   " 22046.70c 0.000035050  22047.70c 0.000031608 "
                                   " 22048.70c 0.000313196  22049.70c 0.000022984 "
                                   " 22050.70c 0.000022007  24050.70c 0.000044183 "
                                   " 24052.70c 0.000852028  24053.70c 0.000096613 "
                                   " 24054.70c 0.000024049  25055.70c 0.000370161 "
                                   " 26054.70c 0.000099328  26056.70c 0.001559232 "
                                   " 26057.70c 0.000036009  26058.70c 0.000004792 "
                                   " 29063.70c 0.000811409  29065.70c 0.000361995 "
                                   " 30000.70c 0.000518176 ",
                                   " AL27.12T "," ");
  //  MObj.setDensity(-2.7);
  MObj.setDensity(5.99659E-02);
  MDB.resetMaterial(MObj);  


  //M13061 (82) Al61
  MObj.setMaterial(13061,"EssAl61"," 12024.70c 0.008812087  12025.70c 0.001115595 "
                                   " 12026.70c 0.001228270  13027.70c 0.977848644 "
                                   " 14028.70c 0.005342094  14029.70c 0.000271383 "
                                   " 14030.70c 0.000179107  22046.70c 0.000035050 "
                                   " 22047.70c 0.000031608  22048.70c 0.000313196 "
                                   " 22049.70c 0.000022984  22050.70c 0.000022007 "
                                   " 24050.70c 0.000044183  24052.70c 0.000852028 "
                                   " 24053.70c 0.000096613  24054.70c 0.000024049 "
                                   " 25055.70c 0.000370161  26054.70c 0.000099328 "
                                   " 26056.70c 0.001559232  26057.70c 0.000036009 "
                                   " 26058.70c 0.000004792  29063.70c 0.000811409 "
                                   " 29065.70c 0.000361995  30000.70c 0.000518176 ",
                                   " AL27.12T "," ");	 
  //  MObj.setDensity(-2.73);
  MObj.setDensity(6.06322E-02);
  MDB.resetMaterial(MObj); 


 // M26000 (83) Iron 
  MObj.setMaterial(26000,"EssFe"," 26054.70c 0.058450000  26056.70c 0.917540000 "
		                " 26057.70c 0.021190000  26058.70c 0.002820000 ",
		                " FE56.12T "," ");
  //  MObj.setDensity(-7.85);
  MObj.setDensity(8.46502E-02);
  MDB.resetMaterial(MObj);


 //M26316 (84) ss316l  
  MObj.setMaterial(26316,"EssSS316", " 06000.70c 0.001392603  14028.70c 0.007323064 "
                                       " 14029.70c 0.000372017  14030.70c 0.000245523 "
                                       " 15031.70c 0.000360008  16032.70c 0.000165168 "
                                       " 16033.70c 0.000001304  16034.70c 0.000007390 "
                                       " 16036.70c 0.000000017  24050.70c 0.007920331 "
                                       " 24052.70c 0.152735704  24053.70c 0.017319003 "
                                       " 24054.70c 0.004311066  25055.70c 0.018267327 "
                                       " 26054.70c 0.038344779  26056.70c 0.601931034 " 
                                       " 26057.70c 0.013901213  26058.70c 0.001849996 "
                                       " 27059.70c 0.000283816  28058.70c 0.080834464 "
                                       " 28060.70c 0.031137291  28061.70c 0.001353516 "
                                       " 28062.70c 0.004315603  28064.70c 0.001099057 "
		                     // lib changed:
                                       " 42092.00c 0.002145890  42094.00c 0.001341000 "
                                       " 42095.00c 0.002310064  42096.00c 0.002423388 "
                                       " 42097.00c 0.001388944  42098.00c 0.003514494 "
                                       " 42100.00c  0.001404926 ",
                                       " FE56.12T "," ");
  //  MObj.setDensity(-7.85);
  MObj.setDensity(8.47887E-02);
  MDB.resetMaterial(MObj);


 //M26317 (84) ss316l  less dense than before
  MObj.setMaterial(26317,"EssSS317", " 06000.71c 0.001392603  14028.71c 0.007323064 "
                                     " 14029.71c 0.000372017  14030.71c 0.000245523 "
                                     " 15031.71c 0.000360008  16032.71c 0.000165168 "
                                     " 16033.71c 0.000001304  16034.71c 0.000007390 "
                                     " 16036.71c 0.000000017  24050.71c 0.007920331 "
                                     " 24052.71c 0.152735704  24053.71c 0.017319003 "
                                     " 24054.71c 0.004311066  25055.71c 0.018267327 "
                                     " 26054.71c 0.038344779  26056.71c 0.601931034 " 
                                     " 26057.71c 0.013901213  26058.71c 0.001849996 "
                                     " 27059.71c 0.000283816  28058.71c 0.080834464 "
                                     " 28060.71c 0.031137291  28061.71c 0.001353516 "
                                     " 28062.71c 0.004315603  28064.71c 0.001099057 "
	                             // lib changed:
                                     " 42092.00c 0.002145890  42094.00c 0.001341000 "
                                     " 42095.00c 0.002310064  42096.00c 0.002423388 "
                                     " 42097.00c 0.001388944  42098.00c 0.003514494 "
                                     " 42100.00c  0.001404926 ",
                                     " FE56.14T "," ");
  //  MObj.setDensity(-7.76);
  MObj.setDensity(8.38166E-02);
  MDB.resetMaterial(MObj);

  //M74001 (85)    (ess tungsten)
  MObj.setMaterial(74001,"EssW", " 74180.50c 0.001200000  74182.70c 0.265000000 "
		                 " 74183.70c 0.143100000  74184.70c 0.306400000 "
		                 " 74186.70c 0.284300000 ",
                                 " "," ");
  //  MObj.setDensity(-19.20);
  MObj.setDensity(6.28928E-02);
  MDB.resetMaterial(MObj);




  ModelSupport::DBMaterial& DB=ModelSupport::DBMaterial::Instance();  

    DB.initMXUnitsEss();
  
  return;
}

} // NAMESPACE ModelSupport
