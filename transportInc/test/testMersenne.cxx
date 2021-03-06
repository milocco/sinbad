/********************************************************************* 
  CombLayer : MNCPX Input builder
 
 * File:   test/testMersenne.cxx
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
#include <math.h>
#include <list>
#include <vector>
#include <map>
#include <string>
#include <algorithm>


#include "Exception.h"
#include "FileReport.h"
#include "NameStack.h"
#include "RegMethod.h"
#include "GTKreport.h"
#include "OutputLog.h"
#include "BaseVisit.h"
#include "BaseModVisit.h"
#include "MersenneTwister.h"

#include "testFunc.h"
#include "testMersenne.h"

testMersenne::testMersenne()  :
  Rand(123456L)
  /*!
    Constructor
  */
{}

testMersenne::~testMersenne() 
  /*!
    Destructor
  */
{}

int 
testMersenne::applyTest(const int extra)
  /*!
    Applies all the tests and returns 
    the error number
    \param extra :: index of test
    \retval -1 Distance failed
    \retval 0 All succeeded
  */
{
  ELog::RegMethod RegA("testMersenne","applyTest");
  TestFunc::regSector("testMersenne");

  typedef int (testMersenne::*testPtr)();
  testPtr TPtr[]=
    {
      &testMersenne::testRand,
      &testMersenne::testRandom
    };

  const std::string TestName[]=
    {
      "Rand",
      "Random"
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
	  TestFunc::regTest(TestName[i]);
	  const int retValue= (this->*TPtr[i])();
	  if (retValue || extra>0)
	    return retValue;
	}
    }
  return 0;
}

int
testMersenne::testRandom()
  /*!
    Test the random number generator
    \retval -1 :: failed to get correct numbers
    \retval 0 :: All passed
  */
{
  std::stringstream TX;
  Rand.write(TX);
  std::cout<<"List == ";
  for(int i=0;i<10;i++)
    std::cout<<Rand.randInt(10)<<" ";
  std::cout<<std::endl;

  Rand.read(TX);
  for(int i=0;i<10;i++)
    std::cout<<Rand.randInt(10)<<" ";
  std::cout<<std::endl;

  return 0;
}

int
testMersenne::testRand()
  /*!
    Test the random number generator
    \retval -1 :: failed to get correct numbers
    \retval 0 :: All passed
  */
{
  double sum(0.0);
  for(int i=0;i<50000;i++)
    {
      double x=Rand.rand();
      if (x<0.0 || x>=1.0)
	{
	  ELog::EM<<"Failed on point "<<i<<" "<<x<<ELog::endDebug;
	  return -1;
	}
      sum+=x;
    }
  ELog::EM<<"Sum == "<<sum/50000.0<<ELog::endDebug;
  
  return 0;
}
  
  
