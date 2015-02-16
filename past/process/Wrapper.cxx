/********************************************************************* 
  CombLayer : MNCPX Input builder
 
 * File:   process/Wrapper.cxx
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
#include <cmath>
#include <complex> 
#include <vector>
#include <map> 
#include <list> 
#include <set>
#include <string>
#include <algorithm>
#include <functional>
#include <boost/array.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/regex.hpp>

#include "Exception.h"
#include "FileReport.h"
#include "NameStack.h"
#include "RegMethod.h"
#include "GTKreport.h"
#include "OutputLog.h"
#include "BaseVisit.h"
#include "BaseModVisit.h"
#include "mathSupport.h"
#include "support.h"
#include "regexSupport.h"
#include "MatrixBase.h"
#include "Matrix.h"
#include "Vec3D.h"
#include "Triple.h"
#include "Rules.h"
#include "Code.h"
#include "FItem.h"
#include "varList.h"
#include "FuncDataBase.h"
#include "HeadRule.h"
#include "Object.h"
#include "Qhull.h"
#include "Surface.h"
#include "surfIndex.h"
#include "surfRegister.h"
#include "surfExpand.h"
#include "surfEqual.h"
#include "Wrapper.h"

namespace ModelSupport
{

Wrapper::Wrapper() : 
  originalCell(0),surfOffset(100),interiorFlag(0),
  Distance(0.0)
  /*!
    Constructor
   */
{}

Wrapper::Wrapper(const int OC,const int surO) : 
  originalCell(OC),surfOffset(surO),interiorFlag(0),
  Distance(0.0)
  /*!
    Constructor
    \param OC :: orignalCell 
    \param surO :: surface offset
   */
{}

Wrapper::Wrapper(const Wrapper& A) : 
  originalCell(A.originalCell),nonActive(A.nonActive),surfOffset(A.surfOffset),
  interiorFlag(A.interiorFlag),Distance(A.Distance),newSurf(A.newSurf),
  CellOut(A.CellOut)
  /*!
    Copy constructor
    \param A :: Wrapper to copy
  */
{}

Wrapper&
Wrapper::operator=(const Wrapper& A)
  /*!
    Assignment operator
    \param A :: Wrapper to copy
    \return *this
  */
{
  if (this!=&A)
    {
       originalCell=A.originalCell;
       nonActive=A.nonActive;
       surfOffset=A.surfOffset;
       interiorFlag=A.interiorFlag;
       Distance=A.Distance;
       CellOut=A.CellOut;
    }
  return *this;
}

Wrapper::~Wrapper()
  /*!
    Deletion operator
  */
{}
  
void
Wrapper::addNonActive(const int surN)
  /*!
    Adds a non-active surface number to the 
    system
    \param surN :: number to add [sign sensitive]
  */
{
  nonActive.insert(surN);
  return;
}

std::string
Wrapper::createSurfaces(const std::string& objStr,const double D)
  /*!
    Create the object and surfaces
    \param objStr :: Object string
    \param D :: New distance
    \return string of new object
  */
{
  ELog::RegMethod RegA("Wrapper","createSurfaces");
  ModelSupport::surfIndex& SurI=ModelSupport::surfIndex::Instance();
  Distance=D;
  
  std::string cellStr=objStr; //+" )";
  
  // Now need outer objects: MUST ensure that - is preserved 
  std::string Text="([^\\-&^\\d]*)([\\-|\\d|$]*)";
  boost::regex Re(Text,boost::regex::perl);

  // get cells
  std::vector<std::string> Out;
  StrFunc::StrFullSplit(cellStr,Re,Out);
  const double DFlag((interiorFlag) ? 1.0 : -1.0);

  std::ostringstream cx;
  for(size_t i=0;i<Out.size();i++)
    {
      int surfN;    // read name [with sign]
      if (StrFunc::convert(Out[i],surfN))
        {	  
	  const int surfNoSign=abs(surfN);                  
	  if ( nonActive.find(surfNoSign)==nonActive.end() ) // Surface to indent
	    {
	      std::map<int,int>::const_iterator mc=newSurf.find(surfN);
	      if (mc==newSurf.end())  // To be created
	        {

		  // find surface:
		  Geometry::Surface* SPtr=SurI.getSurf(surfNoSign);
		  // Make new surface: (forget old ptr) [Note: surfN/cn == +/-1]
		  // -- completely unregistered:
		  SPtr=ModelSupport::surfaceCreateExpand
		    (SPtr,Distance*DFlag*(surfN/surfNoSign));
		  //
		  // ONE : get unique name
		  //
		  int outSurfN=surfNoSign+surfOffset;
		  SPtr->setName(outSurfN);
		  SPtr=SurI.addSurface(SPtr);
		  outSurfN=SPtr->getName();
		  newSurf.insert(std::map<int,int>::value_type(surfN,outSurfN));
		  mc=newSurf.find(surfN);
		}
	      // Now have new surface :
	      cx<<" "<<mc->second*(surfN/surfNoSign);
	    }
	}
      else
	cx<<" "<<Out[i];
    }
  CellOut=cx.str();
  return CellOut;
}

}  /// NAMESPACE ModelSupport
