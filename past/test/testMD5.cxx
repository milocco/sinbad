/********************************************************************* 
  CombLayer : MNCPX Input builder
 
 * File:   test/testMD5.cxx
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
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <boost/tuple/tuple.hpp>

#include "Exception.h"
#include "FileReport.h"
#include "NameStack.h"
#include "RegMethod.h"
#include "GTKreport.h"
#include "OutputLog.h"
#include "Binary.h"
#include "MD5hash.h"

#include "testFunc.h"
#include "testMD5.h"

testMD5::testMD5()  
  /*!
    Constructor 
  */
{}

testMD5::~testMD5() 
  /*!
    Destructor
   */
{}

int 
testMD5::applyTest(const int extra)
  /*!
    Applies all the tests and returns 
    the error number
    \param extra :: control variable
    \returns -ve on error 0 on success.
  */
{
  ELog::RegMethod RegA("testMD5","applyTest");

  typedef int (testMD5::*testPtr)();
  testPtr TPtr[]=
    {
      &testMD5::testNext
    };
  const std::string TestName[]=
    {
      "Next"
    };
  
  const int TSize(sizeof(TPtr)/sizeof(testPtr));
  if (!extra)
    {
      std::ios::fmtflags flagIO=std::cout.setf(std::ios::left);
      for(int i=0;i<TSize;i++)
        {
	  std::cout<<std::setw(30)<<TestName[i]<<"("<<i+1<<")"<<std::endl;
	}
      std::cout.flags(flagIO);
      return 0;
    }
  for(int i=0;i<TSize;i++)
    {
      if (extra<0 || extra==i+1)
        {
	  TestFunc::bracketTest(TestName[i],std::cout);
	  const int retValue= (this->*TPtr[i])();
	  if (retValue || extra>0)
	    return retValue;
	}
    }
  return 0;
}


int
testMD5::testNext()
  /*!
    Test of the getNext function
    \returns -ve on error 0 on success.
   */
{
  ELog::RegMethod("testMD5","testNext");

  typedef boost::tuple<std::string,std::string> TTYPE;
  std::vector<TTYPE> Tests;
  Tests.push_back(TTYPE(
		  "The quick brown fox jumps over the lazy dog.",
		  "e4d909c290d0fb1ca068ffaddf22cbd0"));
  Tests.push_back(TTYPE(
		  "The quick brown fox jumps over the lazy dog",
		  "9e107d9d372bb6826bd81d3542a419d6"));
  Tests.push_back(TTYPE("",
			"d41d8cd98f00b204e9800998ecf8427e"));
  
  
  MD5hash sum;
  std::vector<TTYPE>::const_iterator tc;
  for(tc=Tests.begin();tc!=Tests.end();tc++)
    {
      const std::string Hash=sum.processMessage(tc->get<0>());
      if (Hash!=tc->get<1>())
	{
	  ELog::EM<<"Failed on string :"<<
	    tc->get<0>()<<":"<<ELog::endTrace;
	  ELog::EM<<"Obtained HASH :"<<Hash<<":"<<ELog::endTrace;
	  ELog::EM<<"Expected HASH :"<<tc->get<1>()<<":"<<ELog::endTrace;
	  return -1;
	}
    }
  return 0;
}
