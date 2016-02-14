/********************************************************************* 
  CombLayer : MNCPX Input builder
 
 * File:   transport/DetGroup.cxx
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
#include <map>
#include <string>
#include <boost/format.hpp>
#include <boost/bind.hpp>
#include <boost/multi_array.hpp>

#include "MersenneTwister.h"
#include "RefCon.h"
#include "Exception.h"
#include "FileReport.h"
#include "GTKreport.h"
#include "NameStack.h"
#include "RegMethod.h"
#include "OutputLog.h"
#include "BaseVisit.h"
#include "BaseModVisit.h"
#include "mathSupport.h"
#include "MatrixBase.h"
#include "Matrix.h"
#include "Vec3D.h"
#include "Surface.h"
#include "neutron.h"
#include "Detector.h"
#include "DetGroup.h"

namespace Transport
{

DetGroup::DetGroup() 
  /*!
    Constructor
   */
{}

DetGroup::DetGroup(const DetGroup& A)
  /*!
    Copy constructor
    \param A :: Group to copy
   */
{
  std::vector<Detector*>::const_iterator vc;
  for(vc=A.DetVec.begin();vc!=A.DetVec.end();vc++)
    DetVec.push_back((*vc)->clone());
  return;
}


DetGroup&
DetGroup::operator=(const DetGroup& A) 
  /*!
    Copy constructor
    \param A :: Group to copy
    \return *this
   */
{
  if (this!=&A)
    {
      eraseGrp();
      std::vector<Detector*>::const_iterator vc;
      for(vc=A.DetVec.begin();vc!=A.DetVec.end();vc++)
	DetVec.push_back((*vc)->clone());
    }
  return *this;
}

DetGroup::~DetGroup()
  /*!
    Destructor
  */
{
  eraseGrp();
}

void
DetGroup::eraseGrp()
  /*!
    Delete everything.
  */
{
  std::vector<Detector*>::iterator vc;
  for(vc=DetVec.begin();vc!=DetVec.end();vc++)
    delete *vc;
  DetVec.clear(); 
  return;

}

void
DetGroup::clear()
  /*!
    Clear all the array
  */
{
  for_each(DetVec.begin(),DetVec.end(),
	   boost::bind(&Detector::clear,_1));
  return;
}
		       
void 
DetGroup::manageDetector(Detector* DP)
  /*!
    Add a detector as managed
    \param DP :: Detector Pointer to add and manage
  */
{
  if (DP)
    DetVec.push_back(DP);
  return;
}

void 
DetGroup::addDetector(const Detector& DP)
  /*!
    Add a detector as managed
    \parma DP :: Detector Object to clone
  */
{
  DetVec.push_back(DP.clone());
  return;
}

Detector& 
DetGroup::getDet(const size_t Index)
  /*!
    Access to detector element
    \param Index :: Element to get
    \return Detector object
  */
{
  if (Index>=DetVec.size())
    {
      ELog::RegMethod RegA("DetGrp","getDet");
      throw ColErr::IndexError<size_t>(Index,DetVec.size(),"Index");
    }
  return *DetVec[Index];
}


const Detector& 
DetGroup::getDet(const size_t Index) const
  /*!
    Access to detector element
    \param Index :: Element to get
    \return Detector object
  */  
{
  if (Index>=DetVec.size())
    {
      ELog::RegMethod RegA("DetGrp","getDet(const)");
      throw ColErr::IndexError<size_t>(Index,DetVec.size(),"Index");
    }
  return *DetVec[Index];
}

void
DetGroup::write(std::ostream& OX,const double ) const
{
  return;
}



} // NAMESPACE Transport


  