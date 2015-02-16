/********************************************************************* 
  CombLayer : MNCPX Input builder
 
 * File:   physicsInc/PhysCard.h
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
#ifndef PhysCard_h
#define PhysCard_h

namespace physicsSystem
{

/*!
  \class PhysCard 
  \version 1.0
  \date Jully 2010
  \version 1.0
  \author S. Ansell
  \brief Holds cut cards
  
  Holds any card which indexes.
  Has a particle list ie imp:n,h nad
  a cell mapping to number. The map is ordered
  prior to being written.
*/

class PhysCard
{
 private:

  std::string KeyName;                 ///< NameType e.g. cut/phys
  std::list<std::string> particles;    ///< Particle list (if any)
  boost::array<int,5> defFlag;         ///< Default values
  boost::array<double,5> vals;         ///< Values

 public:

  PhysCard(const std::string&);
  PhysCard(const PhysCard&);
  PhysCard& operator=(const PhysCard&);
  ~PhysCard();

  void clear();

  /// Access key
  const std::string& getKey() const { return KeyName; }
  int hasElm(const std::string&) const;
  /// Get particle count
  size_t particleCount() const { return particles.size(); } 
  int removeParticle(const std::string&);

  double getValue(const size_t) const;
  void setValue(const size_t,const double);
  void setValues(const size_t,const double =0,const double =0,
		 const double =0,const double =0,const double =0);
  void setValues(const std::string&);
  void setDef(const size_t);
  void setEnergyCut(const double);

  void addElm(const std::string&);
  void addElmList(const std::string&);

  void write(std::ostream&) const;
  
};

std::ostream&
operator<<(std::ostream&,const PhysCard&);

}

#endif
