/********************************************************************* 
  CombLayer : MNCPX Input builder
 
 * File:   imat/makeIMat.cxx
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
#include <complex>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iterator>
#include <boost/array.hpp>
#include <boost/format.hpp>
#include <boost/shared_ptr.hpp>

#include "Exception.h"
#include "FileReport.h"
#include "NameStack.h"
#include "RegMethod.h"
#include "GTKreport.h"
#include "OutputLog.h"
#include "BaseVisit.h"
#include "BaseModVisit.h"
#include "MatrixBase.h"
#include "Matrix.h"
#include "Vec3D.h"
#include "inputParam.h"
#include "Triple.h"
#include "NRange.h"
#include "NList.h"
#include "Surface.h"
#include "surfIndex.h"
#include "surfRegister.h"
#include "objectRegister.h"
#include "Rules.h"
#include "Code.h"
#include "varList.h"
#include "FuncDataBase.h"
#include "HeadRule.h"
#include "Object.h"
#include "Qhull.h"
#include "KGroup.h"
#include "Source.h"
#include "insertInfo.h"
#include "insertBaseInfo.h"
#include "InsertComp.h"
#include "Simulation.h"
#include "LinkUnit.h"
#include "FixedComp.h"
#include "SecondTrack.h"
#include "TwinComp.h"
#include "ContainedComp.h"
#include "ContainedGroup.h"
#include "LinearComp.h"
#include "shutterBlock.h"
#include "GeneralShutter.h"
#include "IMatShutter.h"
#include "BulkInsert.h"
#include "BulkShield.h"
#include "IMatGuide.h"
#include "makeIMat.h"

namespace imatSystem
{

makeIMat::makeIMat()  :
  G1Obj(new IMatGuide("imatGuide"))
 /*!
    Constructor
  */
{
  ELog::RegMethod RegA("makeIMat","Constructor");
  
  ModelSupport::objectRegister& OR=
    ModelSupport::objectRegister::Instance();

  OR.addObject(G1Obj);
}

makeIMat::~makeIMat()
  /*!
    Destructor
   */
{}

void 
makeIMat::build(Simulation* SimPtr,
		const mainSystem::inputParam& IParam,
		const shutterSystem::BulkShield& BulkObj)
  /*!
    Carry out the full build
    \param SimPtr :: Simulation system
    \param IParam :: Input parameters
    \param BulkObj :: BulkShield object
   */
{
  // For output stream
  ELog::RegMethod RControl("makeIMat","build");
  
  int isoFlag(0);
  // Exit if no work to do:
  if (IParam.flag("exclude") && 
      (IParam.compValue("E",std::string("IMat")) ||
       IParam.compValue("E",std::string("Imat"))) ) 
    return;

  if (IParam.flag("isolate") && 
      (IParam.compValue("I",std::string("IMat")) ||
       IParam.compValue("I",std::string("Imat"))) )
    isoFlag=1;

  const int isNumber(shutterSystem::BulkShield::imatShutter);

  const shutterSystem::BulkInsert* IS=
    dynamic_cast<const shutterSystem::BulkInsert*>
    (BulkObj.getInsert(isNumber));
  if (!IS)
    ELog::EM<<"NO Insert "<<ELog::endErr;

  if (IS)
    {
      G1Obj->addInsertCell("Wall",74123);
      G1Obj->createAll(*SimPtr,*IS);
    }
 
  return;
}

}   // NAMESPACE IMatSystem
