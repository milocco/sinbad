/********************************************************************* 
  CombLayer : MNCPX Input builder
 
 * File:   physics/LSwitchCard.cxx
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
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <complex>
#include <list>
#include <map>
#include <algorithm>
#include <iterator>
#include <boost/array.hpp>
#include <boost/format.hpp>

#include "Exception.h"
#include "FileReport.h"
#include "GTKreport.h"
#include "NameStack.h"
#include "RegMethod.h"
#include "OutputLog.h"
#include "support.h"
#include "LSwitchCard.h"
 
namespace physicsSystem
{ 

std::ostream&
operator<<(std::ostream& OX,const LSwitchCard& A)
  /*!
    Write out the cut to the stream
    \param OX :: Output Stream
    \param A :: LSwitchCard object
    \return Output stream
   */
{
  A.write(OX);
  return OX;
}

LSwitchCard::LSwitchCard() :
  lcaActive(0),lcbActive(0),lccActive(0),leaActive(0),lebActive(0),
  lcaVal(10,0),lcbVal(8,0),lccVal(2,0),leaVal(8,0),lebVal(4,0),
  lcaActiveJ(0),lcbActiveJ(0),lccActiveJ(0),leaActiveJ(0),lebActiveJ(0),
  lcaValJ(10),lcbValJ(8),lccValJ(2),leaValJ(8),lebValJ(4),
  lcaActiveF(0),lcbActiveF(0),lccActiveF(0),leaActiveF(0),lebActiveF(0),
  lcaValF(10,0),lcbValF(8,0),lccValF(2,0),leaValF(8,0),lebValF(4,0)

  /*!
    Constructor
  */
{}

LSwitchCard::LSwitchCard(const LSwitchCard& A) : 
  lcaActive(A.lcaActive),lcbActive(A.lcbActive),lccActive(A.lccActive),
  leaActive(A.leaActive),lebActive(A.lebActive),
  lcaVal(A.lcaVal),lcbVal(A.lcbVal),lccVal(A.lccVal),
  leaVal(A.leaVal),lebVal(A.lebVal),
  lcaActiveJ(A.lcaActiveJ),lcbActiveJ(A.lcbActiveJ),
  lccActiveJ(A.lccActiveJ),
  leaActiveJ(A.leaActiveJ),lebActiveJ(A.lebActiveJ),
  lcaValJ(A.lcaValJ),lcbValJ(A.lcbValJ),lccValJ(A.lccValJ),
  leaValJ(A.leaValJ),lebValJ(A.lebValJ),
  lcaActiveF(A.lcaActiveF),lcbActiveF(A.lcbActiveF),
  lccActiveF(A.lccActiveF),
  leaActiveF(A.leaActiveF),lebActiveF(A.lebActiveF),
  lcaValF(A.lcaValF),lcbValF(A.lcbValF),lccValF(A.lccValF),
  leaValF(A.leaValF),lebValF(A.lebValF)

  /*!
    Copy constructor
    \param A :: LSwitchCard to copy
  */
{}

LSwitchCard&
LSwitchCard::operator=(const LSwitchCard& A)
  /*!
    Assignment operator
    \param A :: LSwitchCard to copy
    \return *this
  */
{
  if (this!=&A)
    {
      lcaActive=A.lcaActive;
      lcbActive=A.lcbActive;
      lccActive=A.lccActive;
      leaActive=A.leaActive;
      lebActive=A.lebActive;
      lcaVal=A.lcaVal;
      lcbVal=A.lcbVal;
      lccVal=A.lccVal;
      leaVal=A.leaVal;
      lebVal=A.lebVal;
      lcaActiveJ=A.lcaActiveJ;
      lcbActiveJ=A.lcbActiveJ;
      lccActiveJ=A.lccActiveJ;
      leaActiveJ=A.leaActiveJ;
      lebActiveJ=A.lebActiveJ;
      lcaValJ=A.lcaValJ;
      lcbValJ=A.lcbValJ;
      lccValJ=A.lccValJ;
      leaValJ=A.leaValJ;
      lebValJ=A.lebValJ;
      lcaActiveF=A.lcaActiveF;
      lcbActiveF=A.lcbActiveF;
      lccActiveF=A.lccActiveF;
      leaActiveF=A.leaActiveF;
      lebActiveF=A.lebActiveF;
      lcaValF=A.lcaValF;
      lcbValF=A.lcbValF;
      lccValF=A.lccValF;
      leaValF=A.leaValF;
      lebValF=A.lebValF;

    }
  return *this;
}


LSwitchCard::~LSwitchCard()
  /*!
    Destructor
  */
{}

 std::vector<int>&
 LSwitchCard::getVec(const std::string& Key) 
  /*!
    Get a reference to the value vector
    \param Key :: Key Name
    \return Reference
   */
{
  if (Key=="lca")
    return lcaVal;
  if (Key=="lcb")
    return lcbVal;
  if (Key=="lcc")
    return lccVal;
  if (Key=="lea")
    return leaVal;
  if (Key=="leb")
    return lebVal;
  
  throw ColErr::InContainerError<std::string>(Key,ELog::RegMethod::getFull());
}

  //ALB+++

  std::vector<std::string>&
  LSwitchCard::getVecJ(const std::string& Key) 
  /*!
    Get a reference to the value vector
    \param Key :: Key Name
    \return Reference
   */
{
  if (Key=="lca")
    return lcaValJ;
  if (Key=="lcb")
    return lcbValJ;
  if (Key=="lcc")
    return lccValJ;
  if (Key=="lea")
    return leaValJ;
  if (Key=="leb")
    return lebValJ;
  
  throw ColErr::InContainerError<std::string>(Key,ELog::RegMethod::getFull());
}

  std::vector<float>&
  LSwitchCard::getVecF(const std::string& Key) 
  /*!
    Get a reference to the value vector
    \param Key :: Key Name
    \return Reference
   */
{
  if (Key=="lca")
    return lcaValF;
  if (Key=="lcb")
    return lcbValF;
  if (Key=="lcc")
    return lccValF;
  if (Key=="lea")
    return leaValF;
  if (Key=="leb")
    return lebValF;
  
  throw ColErr::InContainerError<std::string>(Key,ELog::RegMethod::getFull());
}


  //ALB+++



size_t&
LSwitchCard::getActive(const std::string& Key) 
  /*!
    Get a reference to the active value
    \param Key :: Key Name
    \return Reference
   */
{
  if (Key=="lca")
    return lcaActive;
  if (Key=="lcb")
    return lcbActive;
  if (Key=="lcc")
    return lccActive;
  if (Key=="lea")
    return leaActive;
  if (Key=="leb")
    return lebActive;
  
  throw ColErr::InContainerError<std::string>(Key,"getActive");
}


  //ALB+++

size_t&
LSwitchCard::getActiveJ(const std::string& Key) 
  /*!
    Get a reference to the active value
    \param Key :: Key Name
    \return Reference
   */
{
  if (Key=="lca")
    return lcaActiveJ;
  if (Key=="lcb")
    return lcbActiveJ;
  if (Key=="lcc")
    return lccActiveJ;
  if (Key=="lea")
    return leaActiveJ;
  if (Key=="leb")
    return lebActiveJ;
  
  throw ColErr::InContainerError<std::string>(Key,"getActive");
}


size_t&
LSwitchCard::getActiveF(const std::string& Key) 
  /*!
    Get a reference to the active value
    \param Key :: Key Name
    \return Reference
   */
{
  if (Key=="lca")
    return lcaActiveF;
  if (Key=="lcb")
    return lcbActiveF;
  if (Key=="lcc")
    return lccActiveF;
  if (Key=="lea")
    return leaActiveF;
  if (Key=="leb")
    return lebActiveF;
  
  throw ColErr::InContainerError<std::string>(Key,"getActive");
}


  //ALB+++


const std::vector<int>&
LSwitchCard::getVec(const std::string& Key) const
  /*!
    Get a reference to the value vector
    \param Key :: Key Name
    \return Reference
   */
{
  if (Key=="lca")
    return lcaVal;
  if (Key=="lcb")
    return lcbVal;
  if (Key=="lcc")
    return lccVal;
  if (Key=="lea")
    return leaVal;
  if (Key=="leb")
    return lebVal;
  
  throw ColErr::InContainerError<std::string>(Key,"LSwitchCar::getVec");
}

  //ALB+++

  const std::vector<std::string>&
LSwitchCard::getVecJ(const std::string& Key) const
  /*!
    Get a reference to the value vector
    \param Key :: Key Name
    \return Reference
   */
{
  if (Key=="lca")
    return lcaValJ;
  if (Key=="lcb")
    return lcbValJ;
  if (Key=="lcc")
    return lccValJ;
  if (Key=="lea")
    return leaValJ;
  if (Key=="leb")
    return lebValJ;
  
  throw ColErr::InContainerError<std::string>(Key,"LSwitchCar::getVec");
}


  const std::vector<float>&
LSwitchCard::getVecF(const std::string& Key) const
  /*!
    Get a reference to the value vector
    \param Key :: Key Name
    \return Reference
   */
{
  if (Key=="lca")
    return lcaValF;
  if (Key=="lcb")
    return lcbValF;
  if (Key=="lcc")
    return lccValF;
  if (Key=="lea")
    return leaValF;
  if (Key=="leb")
    return lebValF;
  
  throw ColErr::InContainerError<std::string>(Key,"LSwitchCar::getVec");
}


  //ALB+++


size_t
LSwitchCard::getActive(const std::string& Key) const
  /*!
    Get a reference to the active value
    \param Key :: Key Name
    \return Reference
   */
{
  if (Key=="lca")
    return lcaVal.size();
  if (Key=="lcb")
    return lcbVal.size();
  if (Key=="lcc")
    return lccVal.size();
  if (Key=="lea")
    return leaVal.size();
  if (Key=="leb")
    return lebVal.size();
  
  throw ColErr::InContainerError<std::string>
    (Key,"LSwitchCard::getActive");
}

  //ALB+++

size_t
LSwitchCard::getActiveJ(const std::string& Key) const
  /*!
    Get a reference to the active value
    \param Key :: Key Name
    \return Reference
   */
{
  if (Key=="lca")
    return lcaValJ.size();
  if (Key=="lcb")
    return lcbValJ.size();
  if (Key=="lcc")
    return lccValJ.size();
  if (Key=="lea")
    return leaValJ.size();
  if (Key=="leb")
    return lebValJ.size();
  
  throw ColErr::InContainerError<std::string>
    (Key,"LSwitchCard::getActive");
}


size_t
LSwitchCard::getActiveF(const std::string& Key) const
  /*!
    Get a reference to the active value
    \param Key :: Key Name
    \return Reference
   */
{
  if (Key=="lca")
    return lcaValF.size();
  if (Key=="lcb")
    return lcbValF.size();
  if (Key=="lcc")
    return lccValF.size();
  if (Key=="lea")
    return leaValF.size();
  if (Key=="leb")
    return lebValF.size();
  
  throw ColErr::InContainerError<std::string>
    (Key,"LSwitchCard::getActive");
}


  //ALB+++


void
LSwitchCard::setValues(const std::string& Key,const std::string& Line) 
  /*!
    Set the values from a card
    \param Key :: Line to set
    \param Line :: Line to process	       
  */
{
  ELog::RegMethod RegA("LSwitchCard","setValues(string)");

  std::vector<int>& KV=getVec(Key);
  size_t& active=getActive(Key);
  const size_t maxSize=KV.size();

  std::string LX=Line;
  int Item;

  active=0;
  while(active<maxSize && StrFunc::section(LX,Item))
    {
      KV[active]=Item;
      active++;
    }
  if (active!=maxSize || !StrFunc::isEmpty(LX))
    ELog::EM<<"Failed to fully process :"<<Line<<ELog::endErr;

  return;
}

  //ALB+++

void
LSwitchCard::setValuesJ(const std::string& Key,const std::string& Line) 
  /*!
    Alberto: extension for J flags
    Set the values from a card
    \param Key :: Line to set
    \param Line :: Line to process	       
  */
{
  ELog::RegMethod RegA("LSwitchCard","setValues(string)");

  std::vector<std::string>& KV=getVecJ(Key);
  size_t& active=getActiveJ(Key);
  const size_t maxSize=KV.size();

  std::string LX=Line;
  std::string Item;
  active=0;
  while(active<maxSize )
// && StrFunc::section(LX,Item))
    {
      if(!StrFunc::isEmpty(LX))
	{
	 StrFunc::section(LX,Item);
         KV[active]=Item;
	 // ELog::EM<<" LXXX "<<LX<<" maxSize "<<maxSize<<" Item "<<Item<<" active "<<active<<" StrFunc::isEmpty(LX) "<<StrFunc::isEmpty(LX)<<ELog::endTrace;
         active++;
	}
      else
	{
      // ELog::EM<<" LLLX "<<LX<<" maxSize "<<maxSize<<" Item "<<" active "<<active<<" StrFunc::isEmpty(LX) "<<StrFunc::isEmpty(LX)<<ELog::endTrace;

         Item=" ";
         KV[active]=Item;
         active++;
	}
    }
  if (active!=maxSize)
 // || !StrFunc::isEmpty(LX))
    ELog::EM<<"Failed to fully process :"<<Line<<ELog::endErr;

  return;
}


void
LSwitchCard::setValuesF(const std::string& Key,const std::string& Line) 
  /*!
    Alberto: extension for F flags
    Set the values from a card
    \param Key :: Line to set
    \param Line :: Line to process	       
  */
{
  ELog::RegMethod RegA("LSwitchCard","setValues(string)");

  std::vector<float>& KV=getVecF(Key);
  size_t& active=getActiveF(Key);
  const size_t maxSize=KV.size();
  std::string LX=Line;
  float Item;

  active=0;
  while(active<maxSize && StrFunc::section(LX,Item))
    {
      KV[active]=Item;
      active++;
    }
  if (active!=maxSize || !StrFunc::isEmpty(LX))
    ELog::EM<<"Failed to fully process :"<<Line<<ELog::endErr;

  return;
}


  //ALB+++


void
LSwitchCard::setValue(const std::string& Key,
		      const size_t ID,
		      const int value)
  /*!
    Set a special interest in a cell ID
    The existance of the cell is only 
    checked at the write out stage.
    \param Key :: Key name of object
    \param ID :: Cell number
    \param value :: new value
  */
{
  ELog::RegMethod RegA("LSwitchCard","setValue");

  std::vector<int>& KV=getVec(Key);
  // std::vector<std::string>& KV=getVec(Key);

  size_t& active=getActive(Key);
  const size_t maxSize=KV.size();
  if (ID>=maxSize) 
    throw ColErr::IndexError<size_t>(ID,maxSize,"ID");
  if (active<ID)
    active=ID;

  KV[ID]=value;
  return;
}

int
LSwitchCard::getValue(const std::string& Key,
		      const size_t ID) const
  /*!
    Get the Value  for a given cell.
    \param Key :: Card item to use
    \param ID :: Physics value to index
    \return Phys card value
  */
{
  ELog::RegMethod RegA("LSwitchCard","getValue");
  
  const std::vector<int>& KV=getVec(Key);
  const size_t aSize=getActive(Key);
  if (ID>=aSize)
    throw ColErr::IndexError<size_t>(ID,aSize,"ID");

  return KV[ID];
}

void
LSwitchCard::write(std::ostream& OX) const
  /*!
    Writes out the imp list including
    those files that are required.
    \param OX :: output stream
  */
{
  boost::format FMT("%04d ");
  std::ostringstream cx;

  if (lcaActive)
    {
      cx<<"lca ";
      for(size_t i=0;i<lcaActive;i++)
	{
	  if (i!=3)
	    cx<<lcaVal[i]<<" ";
	  else
	    cx<<(FMT % lcaVal[i]);
	}
      StrFunc::writeMCNPX(cx.str(),OX);      
    }
 if (lcaActiveJ)
    {
      cx.str("");
      cx<<"lca ";
      for(size_t i=0;i<lcaActiveJ;i++)
	{
	    cx<<lcaValJ[i]<<" ";
	}
      StrFunc::writeMCNPX(cx.str(),OX);      
    }
 if (lcaActiveF)
    {
      cx.str("");
      cx<<"lca ";
      for(size_t i=0;i<lcaActiveF;i++)
	{
	  if (i!=3)
	    cx<<lcaValF[i]<<" ";
	  else
	    cx<<(FMT % lcaValF[i]);
	}
      StrFunc::writeMCNPX(cx.str(),OX);      
    }
   
 if (lcbActive)
    {
      cx.str("");
      cx<<"lcb ";
      for(size_t i=0;i<lcbActive;i++)
	cx<<lcbVal[i]<<" ";
      StrFunc::writeMCNPX(cx.str(),OX);      
    }
 if (lcbActiveJ)
    {
      cx.str("");
      cx<<"lcb ";
      for(size_t i=0;i<lcbActiveJ;i++)
	cx<<lcbValJ[i]<<" ";
      StrFunc::writeMCNPX(cx.str(),OX);      
    }
 if (lcbActiveF)
    {
      cx.str("");
      cx<<"lcb ";
      for(size_t i=0;i<lcbActiveF;i++)
	cx<<lcbValF[i]<<" ";
      StrFunc::writeMCNPX(cx.str(),OX);      
    }

  if (lccActive)
    {
      cx.str("");
      cx<<"lcc ";
      for(size_t i=0;i<lccActive;i++)
	cx<<lccVal[i]<<" ";
      StrFunc::writeMCNPX(cx.str(),OX);      
    }
  if (lccActiveJ)
    {
      cx.str("");
      cx<<"lcc ";
      for(size_t i=0;i<lccActiveJ;i++)
	cx<<lccValJ[i]<<" ";
      StrFunc::writeMCNPX(cx.str(),OX);      
    }
  if (lccActiveF)
    {
      cx.str("");
      cx<<"lcc ";
      for(size_t i=0;i<lccActiveF;i++)
	cx<<lccValF[i]<<" ";
      StrFunc::writeMCNPX(cx.str(),OX);      
    }

  if (leaActive)
    {
      cx.str("");
      cx<<"lea ";
      for(size_t i=0;i<leaActive;i++)
	cx<<leaVal[i]<<" ";
      StrFunc::writeMCNPX(cx.str(),OX);      
    }
  if (leaActiveJ)
    {
      cx.str("");
      cx<<"lea ";
      for(size_t i=0;i<leaActiveJ;i++)
	cx<<leaValJ[i]<<" ";
      StrFunc::writeMCNPX(cx.str(),OX);      
    }
  if (leaActiveF)
    {
      cx.str("");
      cx<<"lea ";
      for(size_t i=0;i<leaActiveF;i++)
	cx<<leaValF[i]<<" ";
      StrFunc::writeMCNPX(cx.str(),OX);      
    }

  if (lebActive)
    {
      cx.str("");
      cx<<"leb ";
      for(size_t i=0;i<lebActive;i++)
	cx<<lebVal[i]<<" ";
      StrFunc::writeMCNPX(cx.str(),OX);      
    }
  if (lebActiveJ)
    {
      cx.str("");
      cx<<"leb ";
      for(size_t i=0;i<lebActiveJ;i++)
	cx<<lebValJ[i]<<" ";
      StrFunc::writeMCNPX(cx.str(),OX);      
    }
  if (lebActiveF)
    {
      cx.str("");
      cx<<"leb ";
      for(size_t i=0;i<lebActiveF;i++)
	cx<<lebValF[i]<<" ";
      StrFunc::writeMCNPX(cx.str(),OX);      
    }

  return;
}



}  // NAMESPACE physicsSystem
