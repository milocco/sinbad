/********************************************************************* 
  CombLayer : MNCPX Input builder
 
 * File:   process/ModelSupport.cxx
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

#include "support.h"
#include "surfRegister.h"
#include "ModelSupport.h"

namespace ModelSupport
{

std::string
spcDelimString(const std::string& baseString)
  /*
    Space delimit the input string to remove : and ( without spaces
    \param baseString :: input string
  */
{
  std::ostringstream cx;
  
  int flag(0);
  char prevC('A');
  for(char c : baseString)
    {
      if (flag && c!=' ')
	cx<<' ';
      flag=0;
      if (c=='(' || c==')' || c==':')
	{
	  if (prevC!=' ')
	    cx<<' ';
	  flag=1;
	}
      // now write character
      cx<<c;
      prevC=c;

    }
  return cx.str();
}


std::string
getExclude(const int Offset)
  /*!
    Given a cell number construct the composite form
    for addition to getComposite
    \param Offset :: Cell value
    \return Cell exclude string
  */
{
  std::ostringstream cx;
  cx<<" #"<<Offset<<"T ";
  return cx.str();
}


std::string
getComposite(const int Offset,const std::string& BaseString)
  /*!
    Given a base string add an offset to the numbers
    \param Offset :: Offset nubmer  to add
    \param BaseString :: BaseString number
    \return String with offset components
   */ 
{
  std::ostringstream cx;
  std::string OutUnit;
  int cellN;
  std::string segment=spcDelimString(BaseString);
  
  cx<<" ";
  while(StrFunc::section(segment,OutUnit))
    {
      if (!OutUnit.empty())
        {
	  if (OutUnit[0]=='T')
	    {
	      OutUnit[0]=' ';
	      if (StrFunc::convert(OutUnit,cellN))
		cx<<cellN;
	      else
		cx<<OutUnit;
	    }
	  else if (StrFunc::convert(OutUnit,cellN))
	    cx<<((cellN>0) ? cellN+Offset : cellN-Offset)<<" ";
	  else
	    cx<<OutUnit<<" ";
	}
    }
  return cx.str();
}

std::string
getComposite(const surfRegister& SMap,const int offset,
	     const int minorOffset,const int secondOffset,
	     const std::string& baseString)
  /*!
    Given a base string add an offset to the numbers
    If a number is preceeded by T then it is a true number.
    Use T-4000 etc.
    \param SMap :: Surf register 
    \param Offset :: Offset nubmer to add
    \param minorOffset :: minor Offset nubmer to add [M]
    \param secondOffset :: second Offset nubmer to add [N]
    \param BaseString :: BaseString number
    \return String with offset components
   */
{
  std::ostringstream cx;
  
  int cellN;
  int TrueNum,MinorNum,SecondNum;
  std::string segment=spcDelimString(baseString);
  std::string OutUnit;
  cx<<" ";
  while(StrFunc::section(segment,OutUnit))
    {
      const size_t oL=OutUnit.length();
      if (oL)
	{
	  TrueNum=MinorNum=SecondNum=0;
	  if (OutUnit[oL-1]=='T')
	    {
	      OutUnit[oL-1]=' ';
	      TrueNum=1;
	    }
	  else if (OutUnit[oL-1]=='M')
	    {
	      OutUnit[oL-1]=' ';
	      MinorNum=1;
	    }
	  else if (OutUnit[oL-1]=='N')
	    {
	      OutUnit[oL-1]=' ';
	      SecondNum=1;
	    }
	  if (StrFunc::convert(OutUnit,cellN))
	    {
	      if (TrueNum)
		cx<<SMap.realSurf(cellN);
	      else if (MinorNum)
		cx<<((cellN>0) ? SMap.realSurf(cellN+minorOffset) 
		     : SMap.realSurf(cellN-minorOffset))<<" ";
	      else if (SecondNum)
		cx<<((cellN>0) ? SMap.realSurf(cellN+secondOffset) 
		     : SMap.realSurf(cellN-secondOffset))<<" ";
	      else
		cx<<((cellN>0) ? SMap.realSurf(cellN+offset) 
		     : SMap.realSurf(cellN-offset))<<" ";
	    }
	  else
	    cx<<OutUnit<<" ";
	}
    }
  return cx.str();
}

std::string
getComposite(const surfRegister& SMap,const int Offset,
	     const int MinorOffset,
	     const std::string& BaseString)
  /*!
    Given a base string add an offset to the numbers
    If a number is preceeded by T then it is a true number.
    Use T-4000 etc.
    \param SMap :: Surf register 
    \param Offset :: Offset nubmer to add
    \param minorOffset :: minor Offset nubmer to add [M]
    \param BaseString :: BaseString number
    \return String with offset components
   */
{
  std::ostringstream cx;
  
  int cellN;
  int TrueNum,MinorNum;
  std::string segment=spcDelimString(BaseString);
  std::string OutUnit;
  cx<<" ";
  while(StrFunc::section(segment,OutUnit))
    {
      const size_t oL=OutUnit.length();
      if (oL)
	{
	  TrueNum=MinorNum=0;
	  if (OutUnit[oL-1]=='T')
	    {
	      OutUnit[oL-1]=' ';
	      TrueNum=1;
	    }
	  else if (OutUnit[oL-1]=='M')
	    {
	      OutUnit[oL-1]=' ';
	      MinorNum=1;
	    }
	  if (StrFunc::convert(OutUnit,cellN))
	    {
	      if (TrueNum)
		cx<<SMap.realSurf(cellN);
	      else if (MinorNum)
		cx<<((cellN>0) ? SMap.realSurf(cellN+MinorOffset) 
		     : SMap.realSurf(cellN-MinorOffset))<<" ";
	      else
		cx<<((cellN>0) ? SMap.realSurf(cellN+Offset) 
		     : SMap.realSurf(cellN-Offset))<<" ";
	    }
	  else
	    cx<<OutUnit<<" ";
	}
    }
  return cx.str();
}

std::string
getComposite(const surfRegister& SMap,
	     const int Offset,
	     const std::string& BaseString)
  /*!
    Given a base string add an offset to the numbers.
    If a number is preceeded by T then it is a true number.
    Use T-4000 etc.
    \param SMap :: Surf register 
    \param Offset :: Offset nubmer to add
    \param BaseString :: BaseString number
    \return String with offset components
   */
{
  return getComposite(SMap,Offset,Offset,BaseString);
}



std::string
getSetComposite(const surfRegister& SMap,const int Offset,
		const int MinorOffset,
		const std::string& BaseString)
  /*!
    Given a base string add an offset to the numbers
    If a cell does not exist ignore [no error]
    If a number is preceeded by T then it is a true number.
    Use T-4000 etc.
    \param SMap :: Surf register 
    \param Offset :: Offset nubmer to add
    \param minorOffset :: minor Offset nubmer to add [M]
    \param BaseString :: BaseString number
    \return String with offset components
   */
{
  std::ostringstream cx;
  
  int cellN;
  int TrueNum,MinorNum;
  std::string segment=spcDelimString(BaseString);
  std::string OutUnit;
  cx<<" ";
  while(StrFunc::section(segment,OutUnit))
    {
      const size_t oL=OutUnit.length();
      if (oL)
	{
	  TrueNum=MinorNum=0;
	  if (OutUnit[oL-1]=='T')
	    {
	      OutUnit[oL-1]=' ';
	      TrueNum=1;
	    }
	  else if (OutUnit[oL-1]=='M')
	    {
	      OutUnit[oL-1]=' ';
	      MinorNum=1;
	    }
	  if (StrFunc::convert(OutUnit,cellN))
	    {
	      int CN(cellN);
	      if (!TrueNum)
		{
		  if (MinorNum)
		    CN+=(cellN>0) ? MinorOffset : -MinorOffset;
		  else
		    CN+=(cellN>0) ? Offset : -Offset;
		  if (SMap.hasSurf(CN))
		    cx<<SMap.realSurf(CN)<<" ";
		}
	    }
	  else
	    cx<<OutUnit<<" ";
	}
    }
  return cx.str();
}


  
std::string
getSetComposite(const surfRegister& SMap,
	     const int Offset,const std::string& BaseString)
  /*!
    Given a base string add an offset to the numbers
    If a number is preceeded by T then it is a true number.
    Use T-4000 etc. However, if a number is missing then 
    leave its component blank.
    \param SMap :: Surf register 
    \param Offset :: Offset nubmer to add
    \param BaseString :: BaseString number
    \return String with offset components
   */
{
  std::ostringstream cx;
  std::string OutUnit;
  int cellN;
  int TrueNum=0;

  std::string segment=spcDelimString(BaseString);
 
  cx<<" ";
  while(StrFunc::section(segment,OutUnit))
    {
      const size_t oL=OutUnit.length();
      if (oL)
	{
	  TrueNum=0;
	  if (OutUnit[oL-1]=='T')
	    {
	      OutUnit[oL-1]=' ';
	      TrueNum=1;
	    }
	  if (StrFunc::convert(OutUnit,cellN))
	    {
	      int CN(cellN);
	      if (!TrueNum)
		CN+=(cellN>0) ? Offset : -Offset;
	      if (SMap.hasSurf(CN))
		cx<<SMap.realSurf(CN)<<" ";
	    }
	  else
	    cx<<OutUnit<<" ";
	}
    }
  return cx.str();
}

std::string
getComposite(const surfRegister& SMap,
	     const int Offset,const int surfN)
  /*!
    Given a base string add an offset to the numbers
    If a number is trailed byT then it is a true number.
    \param SMap :: Surf register 
    \param Offset :: Offset nubmer  to add
    \param surfN :: Index item to add
    \return String with offset components
   */
{
  std::ostringstream cx;
  cx<<" "<<((surfN>0) ? SMap.realSurf(surfN+Offset) 
       : SMap.realSurf(surfN-Offset));
  return cx.str();
}

std::string
getComposite(const surfRegister& SMap,
	     const int Offset,const int surfNA,
	     const int surfNB)
  /*!
    Given a base string add an offset to the numbers
    If a number is trailed byT then it is a true number.
    \param SMap :: Surf register 
    \param Offset :: Offset nubmer  to add
    \param surfNA :: Index item to add
    \param surfNB :: Index item to add
    \return String with offset components
   */
{
  return getComposite(SMap,Offset,surfNA)+
    getComposite(SMap,Offset,surfNB);
}

std::string
getComposite(const surfRegister& SMap,
	     const int Offset,const int surfNA,
	     const int surfNB,const int surfNC)
  /*!
    Given a base string add an offset to the numbers
    If a number is trailed byT then it is a true number.
    \param SMap :: Surf register 
    \param Offset :: Offset nubmer  to add
    \param surfNA :: Index item to add
    \param surfNB :: Index item to add
    \param surfNC :: Index item to add
    \return String with offset components
   */
{
  return getComposite(SMap,Offset,surfNA)+
    getComposite(SMap,Offset,surfNB)+
    getComposite(SMap,Offset,surfNC);
}

}  // NAMESPACE ModelSupport
