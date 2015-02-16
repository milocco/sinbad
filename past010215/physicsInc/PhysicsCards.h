/********************************************************************* 
  CombLayer : MNCPX Input builder
 
 * File:   physicsInc/PhysicsCards.h
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
#ifndef PhysicsCards_h
#define PhysicsCards_h

namespace physicsSystem
{

/*!
  \class PhysicsCards
  \version 1.0
  \date November 2005
  \author S.Ansell
  \brief Processes the physics cards in the MCNPX .i file

  Reads/Writes the physics cards. At the moment does
  not process the special cards. 
  It holds all types of "all cell" cards (imp,vol,fcl etc.)
  in ImpCards.
  
*/

class PhysicsCards 
{
 private:
  
  long int rndSeed;                       ///< Random number seed
  int nps;                                ///< number of particles to run
  int histp;                              ///< Add a histp line
  tallySystem::NList<int> histpCells;     ///< cells for the histp list

  std::vector<std::string> Basic;         ///< Basic cards (stripped of Variables)

  ModeCard mode;                          ///< Mode card
  bool voidCard;                          ///< Void card
  std::list<int> printNum;                ///< print numbers
  std::string prdmp;                      ///< prdmp string
  std::vector<PhysImp> ImpCards;          ///< Importance cards
  std::vector<PhysCard> PhysCards;        ///< Physics cards
  LSwitchCard LEA;                        ///< LEA/LCA Card

  SDef::Source sdefCard;                  ///< Source term
  SDef::KCode kcodeCard;                  ///< KCode term [if used]
  PhysImp Volume;                         ///< Volume stack
  
 public:
   
  PhysicsCards();
  PhysicsCards(const PhysicsCards&);
  PhysicsCards& operator=(const PhysicsCards&);
  virtual ~PhysicsCards();

  void clearAll();
  void setHist(const int H) { histp=H; }     ///< Set history flag
  void addHistpCells(const std::vector<int>&);
  void clearHistpCells(); 

  // ALL systems setup
  void setCellNumbers(const std::vector<int>&,const std::vector<double>&);

  // General [All particles] :
  void setCells(const std::string&,const std::vector<int>&,const double =1.0);
  void setCells(const std::string&,const int,const double);
  // Particle+Type
  void setCells(const std::string&,const std::string&,
		const int, const double);
  double getValue(const std::string&,const std::string&,const int) const;

  /// Get Mode card
  ModeCard& getMode() { return mode; }
  /// Get LEA card
  LSwitchCard& getLEA() { return LEA; } 

  const PhysImp& getPhysImp(const std::string&,const std::string&) const;
  PhysImp& getPhysImp(const std::string&,const std::string&);

  PhysImp& addPhysImp(const std::string&,const std::string&);
  PhysCard& addPhysCard(const std::string&,const std::string&);
  /// Access source card
  SDef::Source& getSDefCard() { return sdefCard; }
  /// Access kcode card
  SDef::KCode& getKCodeCard() { return kcodeCard; }

  // ALL Particle/Type
  int processCard(const std::string&);
  void removeCell(const int);

  // Special for type: vol
  void setVolume(const std::vector<int>&,const double =1.0);
  void setVolume(const int,const double);
  void setNPS(const int N) { nps=N; }      ///< Set the Number of particles
  void setRND(const long int N) { rndSeed=N; }  ///< Set the seed number
  void setEnergyCut(const double);  
  void setMode(std::string);
  void setVoidCard(const bool V) { voidCard=V; }   ///< Set the void card
  void setPrintNum(std::string);
  /// Set the prdmp card
  void setPrdmp(const std::string& P) 
    { prdmp = P; } 
  
  long int getRND() const { return rndSeed; }   ///< Get Random number seed

  void substituteCell(const int,const int);
  void substituteSurface(const int,const int); 

  void write(std::ostream&,const std::vector<int>&) const;   

  //ALB
  void sinbadPhysicsCards(std::ostream&,const std::vector<int>&) const;   
  //ALB

};

}

#endif
