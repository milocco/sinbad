/********************************************************************* 
  CombLayer : MNCPX Input builder
 
 * File:   attachCompInc/AttachSupport.h
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
#ifndef attachSystem_AttachSupport_h
#define attachSystem_AttachSupport_h

class Rule;
class Simulation;
class HeadRule;

namespace attachSystem
{

class FixedComp;
class ContainedComp;

void addUnion(const MonteCarlo::Object&,Rule*&);
void addUnion(const int,const Geometry::Surface*,Rule*&);

void addIntersection(const MonteCarlo::Object&,Rule*&);
void addIntersection(const int,const Geometry::Surface*,Rule*&);

void createAddition(const int,Rule*,Rule*&);

// On FC link points
void addToInsertLineCtrl(Simulation&,const FixedComp&,
			 const FixedComp&);

void addToInsertControl(Simulation&,const FixedComp&,
			 const FixedComp&);
void addToInsertControl(Simulation&,const FixedComp&,
			const FixedComp&,const std::string&);
void addToInsertControl(Simulation&,const std::string&,
			 const FixedComp&,ContainedComp&);
void addToInsertControl(Simulation&,const int,const int,
			 const FixedComp&,const ContainedComp&);
// +++ALB+++
void addToInsertControl(Simulation&,const FixedComp&,
			 const FixedComp&,ContainedComp&);
// +++ALB+++ 

 
// On surface intersects
void addToInsertSurfCtrl(Simulation&,const FixedComp&,
			ContainedComp&);
void addToInsertSurfCtrl(Simulation&,const int,const int,
			ContainedComp&);
void addToInsertOuterSurfCtrl(Simulation&,const FixedComp&,
			ContainedComp&);
void addToInsertOuterSurfCtrl(Simulation&,
			      const int,const int,
			      const ContainedComp&,ContainedComp&);

// Brutal forced option!!
void addToInsertForced(Simulation&,const FixedComp&,
			ContainedComp&);
void addToInsertForced(Simulation&,const int,const int,
		       ContainedComp&);

// External check system
bool checkIntersect(const ContainedComp&,const MonteCarlo::Object&,
		    const std::vector<const Geometry::Surface*>&);

bool checkPlaneIntersect(const Geometry::Plane&,
			 const MonteCarlo::Object&,
			 const MonteCarlo::Object&);

bool findPlaneIntersect(const Geometry::Plane&,
			const MonteCarlo::Object&,
			const MonteCarlo::Object&,
			std::vector<int>&,
			std::vector<int>&);

double calcLinkDistance(const FixedComp&,
			const long int,const long int);


HeadRule unionLink(const FixedComp&,
		   const std::vector<long int>&);
HeadRule intersectionLink(const FixedComp&,
			  const std::vector<long int>&);
 
}

#endif
 
