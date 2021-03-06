/********************************************************************* 
  CombLayer : MNCPX Input builder
 
 * File:   include/simulateSinbad.h
 *
 * Copyright (c) 2004-2014 by Stuart Ansell
 * author A. Milocco
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
#ifndef writeSinbad_h
#define writeSinbad_h



class Simulation;

class PhysicsCards; 



namespace mainSystem
{
  class inputParam;
  void createSinbadInputs(inputParam&);
}


namespace tallySystem
{
  class Tally;
}


namespace ModelSupport
 {
 }

namespace sinbadSystem
{

  class writeSinbad: public Simulation
 {
  protected: 
  std::string preNameX;
  std::string cellS;
  std::string cellI1;
  std::string cellI2;
  int WFlag;
  double EC;
  int DN;
  std::vector<int> DT1; 
  std::vector<int> DT2;
  int NP;

  public:

  void setSinbadTally(Simulation&,const mainSystem::inputParam&); 
  void setSinbadPhysics(Simulation&,const mainSystem::inputParam&); 
  void writeSinbadPhysics(std::ostream&) const;
  void writeSinbadWeights(std::ostream& OX) const;
  void writeSinbadTally(std::ostream&) const;
  void writeSinbadMaterial(std::ostream&) const;
  void SinbadWrite(Simulation&,const std::string&);
  void writeSinbadCells(std::ostream&) const;
  void writeSinbadSurfaces(std::ostream&) const;
  void setSinbadWeights(Simulation&,const mainSystem::inputParam&);
 

  writeSinbad(const std::string&);
  writeSinbad(const writeSinbad&);
  writeSinbad& operator=(const writeSinbad&);
  virtual writeSinbad* clone() const;
  virtual ~writeSinbad();
  
 };



}



#endif
