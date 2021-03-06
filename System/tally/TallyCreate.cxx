/********************************************************************* 
  CombLayer : MCNP(X) Input builder
 
 * File:   tally/TallyCreate.cxx
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
#include <cmath>
#include <complex> 
#include <vector>
#include <list> 
#include <map> 
#include <set>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iterator>
#include <memory>
#include <array>

#include "Exception.h"
#include "FileReport.h"
#include "GTKreport.h"
#include "NameStack.h"
#include "RegMethod.h"
#include "OutputLog.h"
#include "BaseVisit.h"
#include "BaseModVisit.h"
#include "MatrixBase.h"
#include "Matrix.h"
#include "Vec3D.h"
#include "localRotate.h"
#include "masterRotate.h"
#include "Triple.h"
#include "NList.h"
#include "NRange.h"
#include "pairRange.h"
#include "Tally.h"
#include "pointTally.h"
#include "meshTally.h"
#include "heatTally.h"
#include "cellFluxTally.h"
#include "fissionTally.h"
#include "surfaceTally.h"
#include "tallyFactory.h"
#include "Surface.h"
#include "surfIndex.h"
#include "SurInter.h"
#include "Rules.h"
#include "Code.h"
#include "FItem.h"
#include "varList.h"
#include "FuncDataBase.h"
#include "ModeCard.h"
#include "PhysCard.h"
#include "LSwitchCard.h"
#include "PhysImp.h"
#include "Source.h"
#include "KCode.h"
#include "PhysicsCards.h"
#include "Simulation.h"
#include "SpecialSurf.h"
#include "LineTrack.h"
#include "ObjectTrackAct.h"
#include "pointDetOpt.h"
#include "basicConstruct.h" 
#include "meshConstruct.h" 

#include "TallyCreate.h"

namespace tallySystem
{
  
void
addFullHeatBlock(Simulation& System)
  /*!
    Adds a f6 for everthing
    \param System :: Simuation object 
  */
{
  ELog::RegMethod RegA("tallySystem","addFullHeatBlock");

  const std::vector<int> Units=System.getNonVoidCellVector();
  const std::vector<int> CL=System.getCellVector();
  System.getPC().setVolume(CL,1.0);
  System.getPC().setVolume(1,0);
  tallySystem::heatTally TX(6);
  TX.setPlus(1);
  TX.setActive(1);                         /// Turn it on
  TX.addCells(Units);
  TX.addLine("e6 800");
  System.addTally(TX);

  std::string part[]={"n","p","h"};
  for(int i=0;i<3;i++)
    {
      TX.setKey(16+10*i);
      TX.setPlus(0);
      TX.setParticles(part[i]);
      System.addTally(TX);
    }
  return;
}

void
addHeatBlock(Simulation& System,const std::vector<int>& CellList)
  /*!
    Adds a f6 for designated cells
    \param System :: Simuation object 
    \param CellList :: Items to add unit for
  */
{
  ELog::RegMethod RegA("tallySystem","addHeatBlock");
  std::vector<int> Units=System.getNonVoidCellVector();
  const std::vector<int> CL=System.getCellVector();             /// All cells
  // check CellList:
  std::vector<int> Tvalues=Units;
  copy(CellList.begin(),CellList.end(),
       std::back_inserter(Tvalues));
  
  // 
  // Get Duplicates since only non-void cells are acceptable:
  // 
  sort(Tvalues.begin(),Tvalues.end());
  std::vector<int>::iterator vc=Tvalues.begin();
  std::vector<int> cellsActual;
  do
    {
      vc=adjacent_find(vc,Tvalues.end());
      if (vc!=Tvalues.end())
	{
	  cellsActual.push_back(*vc);
	  vc++;
	}
    }
  while(vc!=Tvalues.end());
  // Set volumes etx:
  System.getPC().setVolume(CL,1.0);
  System.getPC().setVolume(1,0);
  tallySystem::heatTally TX(6);
  TX.setPlus(1);
  TX.setActive(1);                         /// Turn it on
  TX.addCells(cellsActual);
  TX.addLine("e6 800");
  System.addTally(TX);

  const int partSize(4);
  std::string part[partSize]={"n","p","h","e"};
  for(int i=0;i<partSize;i++)
    {
      TX.setKey(16+10*i);
      TX.setPlus(0);
      TX.setParticles(part[i]);
      System.addTally(TX);
    }
  return;
}

void
addF1Tally(Simulation& System,const int tNum,
	   const int surfNum)
  /*!
    Addition of a tally to the mcnpx
    deck
    \param System :: Simulation class
    \param tNum :: tally number
    \param surfNum :: surface to tally
  */
{
  tallySystem::surfaceTally TX(tNum);
  TX.setParticles("n");                  /// F1 Tally on neutrons
  TX.addSurface(surfNum);
  TX.setEnergy("1.0e-11 251log 1e3");
  TX.setPrintField("f d u s m e t c");
  System.addTally(TX);

  return;
}

void
addF1Tally(Simulation& System,const int tNum,
	   const int surfNum,
	   const std::vector<int>& SDividers)
  /*!
    Addition of a tally to the mcnpx
    deck
    \param System :: Simulation class
    \param tNum :: tally number
    \param surfNum :: surface to tally
    \param SDividers :: Add surface dividers
  */
{
  tallySystem::surfaceTally TX(tNum);
  TX.setParticles("n");                  /// F1 Tally on neutrons
  TX.addSurface(surfNum);
  TX.setEnergy("1.0e-11 251log 1e3");
  TX.setPrintField("f d u s m e t c");
  TX.setSurfDivider(SDividers);
  System.addTally(TX);

  return;
}

void
addF4Tally(Simulation& System,const int tallyNum,
	   const std::string& pType,const std::vector<int>& Units)
  /*!
    Addition of a tally to the mcnpx deck
    \param System :: Simulation class
    \param tallyNum :: Cell number to tally 
    \param pType :: particle to tally over
    \param Units :: List of cells to add
  */
{
  tallySystem::cellFluxTally TX(tallyNum);
  TX.setParticles(pType);                  /// F4 tally on neutrons
  TX.setSD(1.0);                           /// Weight to 1.0
  TX.setActive(1);                         /// Turn it on
  TX.addCells(Units);
  TX.setCinderEnergy(pType);
  System.addTally(TX);

  System.getPC().addHistpCells(Units);

  return;
}

void
addF7Tally(Simulation& System,const int tallyNum,
	   const std::vector<int>& Units)
  /*!
    Addition of a tally to the mcnpx deck
    \param System :: Simulation class
    \param tallyNum :: Cell number to tally 
    \param pType :: particle to tally over
    \param Units :: List of cells to add
  */
{
  tallySystem::fissionTally TX(tallyNum);
  TX.setParticles("n");                  /// F4 tally on neutrons
  TX.setSD(1.0);                           /// Weight to 1.0
  TX.setActive(1);                         /// Turn it on
  TX.addCells(Units);
  System.addTally(TX);

  return;
}

void
addF5Tally(Simulation& System,const int tNumber)
  /*!
    Adds a point tally 
    \param System :: Simulation item
    \param tNumber :: Tally Number
  */
{
  ELog::RegMethod RegA("tallySystem","addF5Tally(int)");
  std::vector<Geometry::Vec3D> EmptyVec;
  addF5Tally(System,tNumber,Geometry::Vec3D(0,0,0),EmptyVec);
  return;
}

void
addF5Tally(Simulation& System,const int tNumber,
	   const Geometry::Vec3D& Point,
	   const std::vector<Geometry::Vec3D>& VList,
	   const double secondDistance)
  /*!
    Adds a point tally 
    \param System :: Simulation item
    \param tNumber :: Tally Number
    \param Point :: Centre point
    \param VList :: Window list
    \param secondDistance :: input step
  */
{
  ELog::RegMethod RegA("tallySystem","addF5Tally(4)");

  tallySystem::pointTally TX(tNumber);
  if (VList.size()>=4) 
    TX.setWindow(VList);
  TX.setCentre(Point);
  TX.setActive(1);
  TX.setParticles("n");                    /// F5 :: tally on neutrons
  TX.setEnergy("1.0e-11 251log 1e3");
  if (fabs(secondDistance)>1.0)
    {
      TX.setTime("1.0 350log 1e8");
      TX.setSecondDist(secondDistance);
    }
  else
    TX.setTime("1.0 179log 1e8");
  if (System.isMCNP6())
    TX.setMCNP6(1);
  System.addTally(TX);

  return;
}


std::vector<Geometry::Vec3D>
calcWindowIntercept(const int bPlane,const int A,
		    const int B,const int C,
		    const int D,const int extraPlane)
  /*!
    Calculate the window for the point tally
    \param System :: Simulation item
    \param bPlane :: back plane/ cylinder /sphere etc.
    \param A :: First part of pair [parallel to B]
    \param B :: Second part of opposite pair
    \param C :: First part of second opposite pair [parallel to D]
    \param D :: Second part of second opposite pair 
    \param extraPlane :: Extra test value
    \return Vector of Points
  */
{
  ELog::RegMethod RegA("tallySystem","calcWindowIntercept");

  std::vector<Geometry::Vec3D> VList;
  std::vector<Geometry::Vec3D> Out;
  // Get Methane plane intercepts:
  const int S[4]={A,B,C,D};

  ELog::EM<<"Extra == "<<extraPlane<<ELog::endDebug;
  for(int i=0;i<4;i++)
    {
      const int j((i%3) ? 3 : 2);
      ModelSupport::calcVertex(bPlane,S[i % 2],S[j],Out,extraPlane);
      if (Out.empty())
        {
	  ELog::EM<<"Unable to calculate intercept \n";
	  ELog::EM<<"Planes == "<<bPlane<<" "<<S[i%2]<<" "<<S[j]
		  <<" ("<<extraPlane<<")"<<ELog::endErr;
	  return VList;
	}
      VList.push_back(Out[0]);
    }
  return VList;
}

std::vector<Geometry::Vec3D>
calcWindowIntercept(const int bPlane,const int A,
		    const int B,const int C,
		    const int D,const Geometry::Vec3D& closePt)
  /*!
    Calculate the window for the point tally
    \param System :: Simulation item
    \param bPlane :: back plane/ cylinder /sphere etc.
    \param A :: First part of pair [parallel to B]
    \param B :: Second part of opposite pair
    \param C :: First part of second opposite pair [parallel to D]
    \param D :: Second part of second opposite pair 
    \param closePt :: Closest point to test
    \return Vector of Points
  */
{
  ELog::RegMethod RegA("tallySystem","calcWindowIntercept");

  std::vector<Geometry::Vec3D> VList;
  std::vector<Geometry::Vec3D> Out;
  // Get Methane plane intercepts:
  const int S[4]={A,B,C,D};

  for(int i=0;i<4;i++)
    {
      const int j((i%3) ? 3 : 2);
      ModelSupport::calcVertex(bPlane,S[i % 2],S[j],Out,closePt);
      if (Out.empty())
        {
	  ELog::EM<<"Unable to calculate intercept \n";
	  ELog::EM<<"Planes == "<<bPlane<<" "<<S[i%2]<<" "<<S[j]
		  <<" ("<<closePt<<")"<<ELog::endErr;
	  return VList;
	}
      VList.push_back(Out[0]);
    }
  return VList;
}

void
addF5Tally(Simulation& System,const int tNumber,
	   const Geometry::Vec3D& TP,const int bPlane,
	   const int A,const int B,const int C,
	   const int D,const int extraPlane)
  /*!
    Adds a point tally . Forms agroup of pairs (A-B) and (C-D)
    \param System :: Simulation item
    \param tNumber :: Tally Number
    \param TP :: Tally Point
    \param A :: First part of pair [parallel to B]
    \param B :: Second part of opposite pair
    \param C :: First part of second opposite pair [parallel to D]
    \param D :: Second part of second opposite pair 
  */
{
  ELog::RegMethod RegA("tallySystem","addF5Tally(int[8])");

  tallySystem::pointTally TX(tNumber);
  std::vector<Geometry::Vec3D> VList;
  if (extraPlane)
    VList=calcWindowIntercept(bPlane,A,B,C,D,extraPlane);
  else
    VList=calcWindowIntercept(bPlane,A,B,C,D,TP);
  TX.setWindow(VList);
  TX.setCentre(TP);
  if (extraPlane && ModelSupport::checkSurface(extraPlane,TX.getCentre())<0)
    {
      ELog::EM<<"Centre on wrong side of extraPlane for tally "
	      <<tNumber<<ELog::endWarn;
      ELog::EM<<"Point == "<<TX.getCentre()<<ELog::endWarn; 
    }

  TX.setActive(1);
  TX.setParticles("n");                    /// F5 :: tally on neutrons
  TX.setEnergy("1.0e-11 251log 1e3");
  TX.setTime("1.0 179log 1e8");
  if (System.isMCNP6())
    TX.setMCNP6(1);

  System.addTally(TX);
  return;
}

void
addF5Tally(Simulation& System,const int tNumber,
	   const int bPlane,const int A,const int B,
	   const int C, const int D,const double Distance,
	   const int extraPlane)
  /*!
    Adds a point tally . Forms agroup of pairs (A-B) and (C-D)
    \param System :: Simulation item
    \param tNumber :: Tally Number
    \param bPlane :: back plane/ cylinder /sphere etc.
    \param A :: First part of pair [parallel to B]
    \param B :: Second part of opposite pair
    \param C :: First part of second opposite pair [parallel to D]
    \param D :: Second part of second opposite pair 
    \param Distance :: distance from the surface to the tally point
    \param extraPlane :: Extra test value
  */
{
  ELog::RegMethod RegA("tallySystem","addF5Tally(int[8])");

  tallySystem::pointTally TX(tNumber);
  std::vector<Geometry::Vec3D> VList;
  std::vector<Geometry::Vec3D> Out;
  // Get Methane plane intercepts:
  const int S[4]={A,B,C,D};

  for(int i=0;i<4;i++)
    {
      const int j((i%3) ? 3 : 2);
      ModelSupport::calcVertex(bPlane,S[i % 2],S[j],Out,extraPlane);
      if (Out.empty())
        {
	  ELog::EM<<"Unable to calculate intercept with Tally:"
		  <<tNumber<<"\n";
	  ELog::EM<<"Planes == "<<bPlane<<" "<<S[i%2]<<" "<<S[j]
		  <<" ("<<extraPlane<<")"<<ELog::endErr;
	  return;
	}
      VList.push_back(Out[0]);
    }

  TX.setWindow(VList);
  TX.setCentre(Distance);
  if (extraPlane && ModelSupport::checkSurface(extraPlane,TX.getCentre())<0)
    {
      ELog::EM<<"Centre on wrong side of extraPlane for tally "
	      <<tNumber<<ELog::endWarn;
      ELog::EM<<"Point == "<<TX.getCentre()<<ELog::endWarn; 
    }

  TX.setActive(1);
  TX.setParticles("n");                    /// F5 :: tally on neutrons
  TX.setEnergy("1.0e-11 251log 1e3");
  TX.setTime("1.0 179log 1e8");
  if (System.isMCNP6())
    TX.setMCNP6(1);

  System.addTally(TX);
  return;
}

void
addF5Tally(Simulation& System,const int tNumber,
	   const int bPlane,const int A,const int B,
	   const int C, const int D,const double Distance,
	   const Geometry::Vec3D& nearPoint)
  /*!
    Adds a point tally . Forms agroup of pairs (A-B) and (C-D)
    \param System :: Simulation item
    \param tNumber :: Tally Number
    \param bPlane :: back plane/ cylinder /sphere etc.
    \param A :: First part of pair [parallel to B]
    \param B :: Second part of opposite pair
    \param C :: First part of second opposite pair [parallel to D]
    \param D :: Second part of second opposite pair 
    \param Distance :: distance from the surface to the tally point
    \param nearPtoin :: Closest extra point
  */
{
  ELog::RegMethod RegA("tallySystem","addF5Tally(int,nearPt)");

  ModelSupport::surfIndex& SurI= ModelSupport::surfIndex::Instance();

  tallySystem::pointTally TX(tNumber);
  std::vector<Geometry::Vec3D> VList;
  std::vector<Geometry::Vec3D> Out;
  // Get Methane plane intercepts:
  const Geometry::Surface* BSurf=SurI.getSurf(bPlane);
  const Geometry::Surface* S[4];
  S[0]=SurI.getSurf(A);
  S[1]=SurI.getSurf(B);
  S[2]=SurI.getSurf(C);
  S[3]=SurI.getSurf(D);
  
  for(int i=0;i<4;i++)
    {
      const int j((i%3) ? 3 : 2);
      VList.push_back(SurInter::getPoint(BSurf,S[i % 2],S[j],nearPoint));
    }

  TX.setWindow(VList);
  TX.setCentre(Distance);

  TX.setActive(1);
  TX.setParticles("n");                    /// F5 :: tally on neutrons
  TX.setEnergy("1.0e-11 251log 1e3");
  TX.setTime("1.0 179log 1e8");
  if (System.isMCNP6())
    TX.setMCNP6(1);

  System.addTally(TX);
  return;
}

void 
addSimpleF5Tally(Simulation& System,const int TNum,
		 const Geometry::Vec3D& Pt,const std::string& Particle,
		 const std::string& Energy,const std::string& Time)
  /*!
    Add a basic point tally at a position
    \param System :: Simulation system
    \param Pt :: Point for tally
    \param TNum :: Tally number
    \param Particle :: Particle(s) string
    \param Energy :: Energy string
    \param Time :: Time string
  */
{
  ELog::RegMethod RegA("TallyCreate[F]","addSimpleF5Tally");
  tallySystem::pointTally TX(TNum);
  TX.setActive(1);
  TX.setCentre(Pt);
  TX.setParticles(Particle);
  TX.setEnergy(Energy);
  TX.setTime(Time);
  if (System.isMCNP6())
    TX.setMCNP6(1);

  System.addTally(TX);
  return;
} 

void
setComment(Simulation& System,const int tNumber,const std::string& Comment)
  /*!
    Set the comment on a tally
    \param System :: Simulation to run
    \param tNumber :: tally number
    \param Comment :: Comment string
  */
{
  ELog::RegMethod RegA("TallyCreate","setComment");

  tallySystem::pointTally* TX=
    dynamic_cast<tallySystem::pointTally*>(System.getTally(tNumber)); 
  if (!TX)
    ELog::EM<<"Error finding tally number "<<tNumber<<ELog::endErr;
  else
    TX->setComment(Comment);
  return;
}

void
cutTallyEnergy(Simulation& System,const double energyCut)
  /*!
    Cut all tallies to a particular energy cut
    \param System :: Simulation object to add component
    \param energyCut :: Energy to cut [MeV]
  */
{
  Simulation::TallyTYPE& TMap=System.getTallyMap();
  Simulation::TallyTYPE::iterator mc;
  for(mc=TMap.begin();mc!=TMap.end();mc++)
    mc->second->cutEnergy(energyCut);

  return;
}

void 
setF5Position(Simulation& System,const int tNumber,
	      const Geometry::Vec3D& CPoint,const Geometry::Vec3D& Axis,
	      const double DBplane,const double WStep)
  /*!
    Set the angular offset on a system
    \param System :: Simulation to run
    \param tNumber :: tally number
    \param CPoint :: Centre point of line
    \param Axis :: Axis of centre line
    \param DBplane :: Distance from Back plane of tally
    \param WStep :: Window step
  */
{
  ELog::RegMethod RegA("TallyCreate","setF5Position");
  const masterRotate& MR=masterRotate::Instance();
  tallySystem::pointTally* TX=
    dynamic_cast<tallySystem::pointTally*>(System.getTally(tNumber)); 
  if (!TX)
    {
      ELog::EM<<"setF5Position:: Error finding tally number "
	      <<tNumber<<ELog::endErr;;
      return;
    }

  TX->setProjectionCentre(CPoint,Axis,DBplane);
  TX->shiftWindow(WStep);
  TX->printWindow();
  ELog::EM<<"Tally "<<tNumber<<" Centre == "
	  <<MR.calcRotate(TX->getCentre())<<ELog::endDiag;
  return;
}

void 
setF5Position(Simulation& System,const int tNumber,
	      const Geometry::Vec3D& TPoint)
  /*!
    Set the F5 centre point of a tally
    \param System :: Simulation to run
    \param tNumber :: tally number
    \param TPoint :: Centre point of tally
  */
{
  ELog::RegMethod RegA("TallyCreate","setF5Position(point)");

  tallySystem::pointTally* TX=
    dynamic_cast<tallySystem::pointTally*>(System.getTally(tNumber)); 
  if (!TX)
    {
      ELog::EM<<"Error finding tally number "<<tNumber<<ELog::endErr;
      return;
    }
  TX->setCentre(TPoint);
  return;
}

void 
moveF5Tally(Simulation& System,const int tNumber,
	    const Geometry::Vec3D& moveVec)
  /*!
    Move the F5 point of a tally
    \param System :: Simulation to run
    \param tNumber :: tally number
    \param moveVec :: Displacement value
  */
{
  ELog::RegMethod RegA("TallyCreate","moveF5Position");

  tallySystem::pointTally* TX=
    dynamic_cast<tallySystem::pointTally*>(System.getTally(tNumber)); 
  if (!TX)
    {
      ELog::EM<<"Error finding tally number "<<tNumber<<ELog::endErr;
      return;
    }
  TX->setCentre(TX->getCentre()+moveVec);
  return;
}

void 
setTallyTime(Simulation& System,const int tNumber,
	     const std::string& timeStr)
  /*!
    Set the angular offset on a system
    \param System :: Simulation to run
    \param tNumber :: tally number
    \param timeStr :: String the defines the time
  */
{
  ELog::RegMethod RegA("TallyCreate","setTallyTime");

  tallySystem::Tally* TX=System.getTally(tNumber); 
  if (!TX)
      ELog::EM<<"Error finding tally number "<<tNumber<<ELog::endErr;
  else
    TX->setTime(timeStr);
  return;
}

void
setF5Angle(Simulation& System,const int tNumber,
	   const Geometry::Vec3D& PN,const double D,
	   const double A)
  /*!
    Set the angular offset on a system
    \param System :: Simulation to run
    \param tNumber :: tally number
    \param PN :: Normal vector to the plane of rotation
    \param D :: Distance from the centre (1000cm normally)
    \param A :: Angle [degrees]
  */
{
  ELog::RegMethod RegA("TallyCreate","setF5Angle");

  tallySystem::pointTally* TX=
    dynamic_cast<tallySystem::pointTally*>(System.getTally(tNumber)); 
  if (!TX)
    {
      ELog::EM<<"setF5Angle:: Error finding tally number "
	      <<tNumber<<ELog::endErr;
      return;
    }
  TX->setCentreAngle(PN,D,A*M_PI/180.0);
  return;
}

void
widenF5Tally(Simulation& System,const int tNumber,
	     const int dirIndex,const double scale)
  /*!
    Widens the tally in the window direction by scale cm in 
    each direction
    \param System :: Simulation to deal with
    \param tNumber :: tally number
    \param dirIndex :: direction index [0/1]
    \param scale :: distance to move (-ve to reduce)
   */
{
  ELog::RegMethod RegA("TallyCreate","widenF5Tally");

  tallySystem::pointTally* TX=
    dynamic_cast<tallySystem::pointTally*>(System.getTally(tNumber)); 
  if (!TX)
    ELog::EM<<"Error finding tally nubmer "<<tNumber
	    <<ELog::endErr;
  else
    TX->widenWindow(dirIndex,scale);
  return;
}

void
slideF5Tally(Simulation& System,const int tNumber,
	     const int dirIndex,const double scale)
  /*!
    Widens the tally in the window direction by scale cm in 
    each direction
    \param System :: Simulation to deal with
    \param tNumber :: tally number
    \param dirIndex :: direction index [0/1]
    \param scale :: distance to move (-ve to reduce)
   */
{
  ELog::RegMethod RegA("TallyCreate","slideF5Tally");

  tallySystem::pointTally* TX=
    dynamic_cast<tallySystem::pointTally*>(System.getTally(tNumber)); 
  if (!TX)
    ELog::EM<<"Error finding tally nubmer "<<tNumber
	    <<ELog::endErr;
  else
    TX->slideWindow(dirIndex,scale);
  return;
}

void
shiftF5Tally(Simulation& System,const int tNumber,
	     const double scale)
  /*!
    Shift the tally window forward
    \param System :: Simulation to deal with
    \param tNumber :: tally number
    \param scale :: distance to move (-ve to reduce)
   */
{
  ELog::RegMethod RegA("TallyCreate","shiftF5Tally");

  tallySystem::pointTally* TX=
    dynamic_cast<tallySystem::pointTally*>(System.getTally(tNumber)); 
  if (!TX)
    {
      ELog::EM<<"Error finding tally nubmer "
	      <<tNumber<<ELog::endErr;
      throw ColErr::ExitAbort(RegA.getFull());
    }
  TX->shiftWindow(scale);
  return;
}

void
divideF5Tally(Simulation& System,const int tNumber,
	      const int xPts,const int yPts)
  /*!
    Modification to the FU card to add a user bin divide
    Note this depends on an MCNPX modification to tallyx
    \param System :: Simulation
    \param tNumber :: tally number
    \param xPts :: Number of x points
    \param xPts :: Number of y points
  */
{
  ELog::RegMethod RegA("TallyCreate","divideF5Tally");

  if (tNumber)
    {
      tallySystem::pointTally* TX=
	dynamic_cast<tallySystem::pointTally*>(System.getTally(tNumber)); 
      if (!TX)
	{
	  ELog::EM<<"Error finding tally nubmer "
		  <<tNumber<<ELog::endErr;
	  throw ColErr::ExitAbort(RegA.getFull());
	}
      TX->divideWindow(xPts,yPts);
    }
  else
    {
      Simulation::TallyTYPE& TM=System.getTallyMap();
      Simulation::TallyTYPE::iterator mc;
      for(mc=TM.begin() ;mc!=TM.end(); mc++)
	{
	  tallySystem::pointTally* TX=
	    dynamic_cast<tallySystem::pointTally*>(mc->second); 
	  if (TX)
	    TX->divideWindow(xPts,yPts);
	}
    }
  return;
}

void
removeF5Window(Simulation& System,const int tNumber)
  /*!
    Removes all/some of the windows for an f5 tally.
    \param System :: Simulation item
    \param tNumber :: Tally number [0 for all]
  */
{
  ELog::RegMethod RegA("TallyCreate","removeF5Window");

  Simulation::TallyTYPE& TM=System.getTallyMap();
  Simulation::TallyTYPE::iterator mc;
  // ugly way to trip in/out of the loop
  mc=(tNumber) ? TM.find(tNumber) : TM.begin();
  for( ;mc!=TM.end(); mc++)
    {
      tallySystem::pointTally* TX=
	dynamic_cast<tallySystem::pointTally*>(mc->second); 
      if (TX)
	{
	  // delete window if present
	  TX->removeWindow();
	}
      if (tNumber) return;
    }
  return;
}

void
modF5TallyCells(Simulation& System,const int tNumber,
	   const std::vector<int>& cells)
  /*!
    Sets the cells for a particular F5 tally [using icd]
    \param System :: Simulation item
    \param tNumber :: Tally Number
    \param cells :: List of cells to used
  */
{
  ELog::RegMethod RegA("TallyCreate","modF5TallyCells");

  tallySystem::pointTally* TX=
    dynamic_cast<tallySystem::pointTally*>(System.getTally(tNumber)); 
  if (!TX)
    ELog::EM<<"Error finding tally nubmer "<<tNumber<<ELog::endErr;
  else
    {
      TX->setActive(1);
      TX->setParticles("n");                    /// F5 :: tally on neutrons
      TX->setEnergy("5.0e-10 148log 1e3");
      TX->setTime("1e-1 10log 1e6");
      TX->setSpecial("icd");                 // Special to add cell view
      TX->setCells(cells);
    }
  return;
}

void
addF6Tally(Simulation& System,const int tNumber,
	   const std::string& particleType,
	   const std::vector<int>& cellList)
  /*!
    Creates a +f6 type tally
    \param System :: Simulation to add
    \param pType :: particle type
    \param tNumber :: tally number 
    \param cellList :: Cells to add
   */
{
  tallySystem::heatTally TX(tNumber);
  TX.addCells(cellList);
  TX.setActive(1);
  if (particleType.empty() || particleType[0]=='+')
    TX.setPlus(1);
  else
    {
      TX.setPlus(0);
      TX.setParticles(particleType);
    }
  System.addTally(TX);
  return;
}

void
writePlanes(const int Index,const int MP,
	    const std::vector<int>& Planes)
  /*!
    Diagnostic to write plane info from a point tally (ugly)
    \param Index :: Index of tally
    \param MP :: Master Plane 
    \param Planes :: List of planes 
  */
{
  ELog::EM<<"Beamline ==== "<<Index<<ELog::endDiag;
  ELog::EM<<"Master == "<<MP<<ELog::endDiag;
  ELog::EM<<"Plane == ";
  copy(Planes.begin(),Planes.end(),
       std::ostream_iterator<int>(ELog::EM.Estream(),":"));
  ELog::EM.diagnostic();
  ELog::EM<<"-----------------------"<<ELog::endDiag;
  return;
}

void
deleteTallyType(Simulation& Sim,const int TType)
  /*!
    Delete a tally based on the number-type
    \param Sim :: Simulation system to remove tallies from
    \param TType :: Type number to delete  [0 for all]
  */
{
  ELog::RegMethod RegA("TallyCreate","deleteTallyType");

  Simulation::TallyTYPE& TM=Sim.getTallyMap();
  Simulation::TallyTYPE::iterator mc;
  for(mc=TM.begin();mc!=TM.end();)
    {
      if (!TType || (mc->second->getKey() % 10) == TType )
	{
	  ELog::EM<<"Deleting Tally "<<mc->second->getKey()<<ELog::endDiag;
	  delete mc->second;
	  TM.erase(mc++);
	}
      else
	mc++;
    }
  return;
}

void
deleteTally(Simulation& Sim,const int ID)
  /*!
    Delete a tally based on the number-type
    \param Sim :: Simulation system to remove tallies from
    \param ID :: Type number to delete 
  */
{
  ELog::RegMethod RegA("TallyCreate","deleteTally");

  Simulation::TallyTYPE& TM=Sim.getTallyMap();
  Simulation::TallyTYPE::iterator mc;
  for(mc=TM.begin();mc!=TM.end();mc++)
    {
      if (mc->second->getKey()==ID)
	{
	  ELog::EM<<"Deleting Tally "<<mc->second->getKey()<<ELog::endDiag;
	  delete mc->second;
	  TM.erase(mc++);
	  return;
	}
    }
  return;
}

int
getFarPoint(const Simulation& Sim,Geometry::Vec3D& Pt) 
  /*!
    Get the last tally point based on the tallynumber
    Can use the mesh centre if no point tallies exist
    \param Sim :: System to access tally tables
    \param Pt :: Point 
    \return tally number [0 on fail]
  */
{
  ELog::RegMethod RegA("TallyCreate","getFarPoint");

  const Simulation::TallyTYPE& tmap=Sim.getTallyMap();
  int tnum(0);
  Simulation::TallyTYPE::const_iterator mc;
  for(mc=tmap.begin();mc!=tmap.end();mc++)
    {
      const pointTally* PTptr=
	dynamic_cast<const pointTally*>(mc->second);
      if (PTptr && PTptr->getKey()>tnum)
	{
	  tnum=PTptr->getKey();
	  Pt=PTptr->getCentre();
	}
      else 
	{
	  const meshTally* Mptr=
	    dynamic_cast<const meshTally*>(mc->second);
	  if (Mptr)
	    {
	      tnum=Mptr->getKey();
	      Pt=Mptr->getCentre();
	    }
	}
    }
  ELog::EM<<"Aim Point == "<<Pt<<ELog::endDiag;
  if (Pt.abs()<10.0 && tnum)                  // Too close to target Reflector
    ELog::EM<<"Aim unexpectedly close  "<<ELog::endErr;

  return tnum;
}

int
setEnergy(Simulation& Sim,const int tNumber,
	  const std::string& ePart)
  /*!
    Set the energy of a tally
    \param Sim :: Simulation
    \param tNumber :: tally nubmer
    \param ePart :: string
   */
{
  ELog::RegMethod RegA("TallyCreate","setEnergy");

  Simulation::TallyTYPE& tmap=Sim.getTallyMap();
  int fnum(0);
  Simulation::TallyTYPE::iterator mc;
  for(mc=tmap.begin();mc!=tmap.end();mc++)
    {
      if (tNumber==0 || mc->first==tNumber)
	{
	  if (mc->second->setEnergy(ePart))
	    fnum++;
	}
    }

  return fnum;
}

int
setSingle(Simulation& Sim,const int tNumber)
  /*!
    Split all the tallies into single cells
    \param Sim :: Simulation
    \param tNumber :: tally nubmer
    \return number of tallies split
   */
{
  ELog::RegMethod RegA("TallyCreate","setSingle");

  Simulation::TallyTYPE& tmap=Sim.getTallyMap();
  int fnum(0);
  Simulation::TallyTYPE::iterator mc;
  for(mc=tmap.begin();mc!=tmap.end();mc++)
    {
      if ( ((mc->first % 10)==4  || (mc->first % 10)==2) &&
	   (tNumber==0 || mc->first==tNumber))
	{
	  if (mc->second->makeSingle())
	    fnum++;
	}
    }
  return fnum;  
}

int
setTime(Simulation& Sim,const int tNumber,
	     const std::string& tPart)
  /*!
    Set the energy of a tally
    \param Sim :: Simulation
    \param tNumber :: tally nubmer
    \param tPart :: time segment string [MCNPX format]
    \return number of tallies split
   */
{
  ELog::RegMethod RegA("TallyCreate","setTime");

  Simulation::TallyTYPE& tmap=Sim.getTallyMap();
  int fnum(0);
  Simulation::TallyTYPE::iterator mc;
  for(mc=tmap.begin();mc!=tmap.end();mc++)
    {
      if (tNumber==0 || mc->first==tNumber)
	{
	  if (mc->second->setTime(tPart))
	    fnum++;
	}
    }

  return fnum;
}


int
changeParticleType(Simulation& Sim,const int tNumber,
		   const std::string& oPart,
		   const std::string& nPart) 
  /*!
    Get the last tally point based on the tallynumber
    Can use the mesh centre if no point tallies exist
    \param Sim :: System to access tally tables
    \param tNumber :: Tally number [0 for all]
    \param oPart :: Old Particle
    \param nPart :: New Particle
    \return tally number [0 on fail]
  */
{
  ELog::RegMethod RegA("TallyCreate","changeParticleType");

  Simulation::TallyTYPE& tmap=Sim.getTallyMap();
  int fnum(0);
  Simulation::TallyTYPE::iterator mc;
  for(mc=tmap.begin();mc!=tmap.end();mc++)
    {
      if (tNumber==0 || mc->first==tNumber)
	{
	  std::string PStr=mc->second->getParticles();
	  std::string::size_type pos=PStr.find(oPart);
	  if (pos!=std::string::npos)
	    {
	      PStr.replace(pos,oPart.size(),nPart);
	      mc->second->setParticles(PStr);
	      fnum++;
	    }
	}
    }

  return fnum;
}

void
addPointPD(Simulation& ASim)
  /*!
    Add point detector PD option to the tally
    Assumed that calcAllVertex has been run on ASim
    \param ASim :: Simulation value
  */
{
  ELog::RegMethod RegA("TallyCreate","addPointPD");


  const Simulation::TallyTYPE& tmap=ASim.getTallyMap();
  Simulation::TallyTYPE::const_iterator mc;
  for(mc=tmap.begin();mc!=tmap.end();mc++)
    {
      const pointTally* PTptr=
	dynamic_cast<const pointTally*>(mc->second);
      if (PTptr)
	{
	  const masterRotate& MR=masterRotate::Instance();
	  ModelSupport::pointDetOpt 
	    PD(MR.reverseRotate(PTptr->getCentre()));
	  PD.createObjAct(ASim);
	  PD.addTallyOpt(PTptr->getKey(),ASim);
	}
    }
  
  return;
}

int 
getLastTallyNumber(const Simulation& ASim,const int type)
  /*!
    Get the last tally nubmer
    \param ASim :: Simulation
   */
{
  const Simulation::TallyTYPE& tmap=ASim.getTallyMap();
  int outN(0);
  Simulation::TallyTYPE::const_iterator mc;
  for(mc=tmap.begin();mc!=tmap.end();mc++)
    {
      if (mc->first>outN && 
	  (!type || (mc->first % 10)==type))
	outN=mc->first;
    }
  return outN;
}


}  // NAMESPACE tallySystem
