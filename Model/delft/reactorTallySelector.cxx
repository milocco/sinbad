/********************************************************************* 
  CombLayer : MNCPX Input builder
 
 * File:   build/reactorTallySelector.cxx
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
#include <memory>

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
#include "Tensor.h"
#include "Vec3D.h"
#include "Triple.h"
#include "support.h"
#include "NRange.h"
#include "NList.h"
#include "Tally.h"
#include "TallyCreate.h"
#include "Code.h"
#include "varList.h"
#include "FuncDataBase.h"
#include "MainProcess.h"
#include "inputParam.h"

#include "basicConstruct.h"
#include "fissionConstruct.h"
#include "reactorTallyConstruct.h"
#include "tallyConstructFactory.h"
#include "tallyConstruct.h"
#include "TallySelector.h" 

int
reactorTallySelection(Simulation& System,
		      const mainSystem::inputParam& IParam)
  /*!
    An amalgumation of values to determine what sort of tallies to put
    in the system.
    \param System :: Simulation to add tallies
    \param IParam :: InputParam
    \return flag to indicate that more work is required after renumbering
  */
{
  ELog::RegMethod RegA("reactorTallySelector[F]","reactorTallySelection");

  tallySystem::tallyConstructFactory FC;
  tallySystem::tallyConstruct TallyBuilder(FC);
  TallyBuilder.setFission(new tallySystem::reactorTallyConstruct());
  return TallyBuilder.tallySelection(System,IParam);
}
 

void
reaactorTallyRenumberWork(Simulation& System,
			  const mainSystem::inputParam& IParam)
  /*!
    An amalgumation of values to determine what sort of tallies to put
    in the system.
    \param System :: Simulation to add tallies
    \param IParam :: Input Parameters
  */
{
  ELog::RegMethod RegA("reactorTallySelector[F]","beamTallyRenumberWork");

  tallySystem::tallyConstructFactory FC;
  tallySystem::tallyConstruct TallyBuilder(FC);
  TallyBuilder.tallyRenumber(System,IParam);
 
  return;
}


