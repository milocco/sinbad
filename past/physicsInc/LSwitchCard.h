/********************************************************************* 
  CombLayer : MNCPX Input builder
 
 * File:   physicsInc/LSwitchCard.h
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
#ifndef physicsSystem_LSwitchCard_h
#define physicsSystem_LSwitchCard_h

namespace physicsSystem
{

/*!
  \class LSwitchCard 
  \version 1.0
  \date July 2010
  \version 1.0
  \author S. Ansell
  \brief Holds cut cards
  
  Holds any card which indexes.
  Has a particle list ie imp:n,h nad
  a cell mapping to number. The map is ordered
  prior to being written.
  \date July 2014
  \version 1.0
  \author A. Milocco
  insert lca,lcb,lcc,lea and leb cards. 
  Values are integers in the original version.
  possibility to use a string as "j" with functions/variables ending with J
  possibility to use any number as "1.1" with functions/variables ending with F (Float)
  
*/

class LSwitchCard
{
 private:

  size_t lcaActive;         ///< Number active for lca
  size_t lcbActive;         ///< Number active for lcb
  size_t lccActive;         ///< Number active for lcc
  size_t leaActive;         ///< Number active for lea
  size_t lebActive;         ///< Number active for leb

  std::vector<int> lcaVal;      ///< Values for lca
  std::vector<int> lcbVal;      ///< Values for lcb
  std::vector<int> lccVal;      ///< Values for lcc
  std::vector<int> leaVal;      ///< Values for lea
  std::vector<int> lebVal;      ///< Values for leb

  size_t lcaActiveJ;         ///< Number active for lca
  size_t lcbActiveJ;         ///< Number active for lcb
  size_t lccActiveJ;         ///< Number active for lcc
  size_t leaActiveJ;         ///< Number active for lea
  size_t lebActiveJ;         ///< Number active for leb

  std::vector<std::string> lcaValJ;      ///< Values for lca
  std::vector<std::string> lcbValJ;      ///< Values for lcb
  std::vector<std::string> lccValJ;      ///< Values for lcc
  std::vector<std::string> leaValJ;      ///< Values for lea
  std::vector<std::string> lebValJ;      ///< Values for leb

  size_t lcaActiveF;         ///< Number active for lca
  size_t lcbActiveF;         ///< Number active for lcb
  size_t lccActiveF;         ///< Number active for lcc
  size_t leaActiveF;         ///< Number active for lea
  size_t lebActiveF;         ///< Number active for leb

  std::vector<float> lcaValF;      ///< Values for lca
  std::vector<float> lcbValF;      ///< Values for lcb
  std::vector<float> lccValF;      ///< Values for lcc
  std::vector<float> leaValF;      ///< Values for lea
  std::vector<float> lebValF;      ///< Values for leb

  size_t& getActive(const std::string&);
  size_t& getActiveJ(const std::string&);
  size_t& getActiveF(const std::string&);

  std::vector<int>& getVec(const std::string&);
  std::vector<std::string>& getVecJ(const std::string&);
  std::vector<float>& getVecF(const std::string&);

  size_t getActive(const std::string&) const;
  size_t getActiveJ(const std::string&) const;
  size_t getActiveF(const std::string&) const;

  const std::vector<int>& getVec(const std::string&) const;
  const std::vector<std::string>& getVecJ(const std::string&) const;
  const std::vector<float>& getVecF(const std::string&) const;

 public:

  LSwitchCard();
  LSwitchCard(const LSwitchCard&);
  LSwitchCard& operator=(const LSwitchCard&);
  ~LSwitchCard();

  /// Access key

  int getValue(const std::string&,const size_t) const;
  void setValue(const std::string&,const size_t,const int);

  void setValues(const std::string&,const std::string&);
  void setValuesJ(const std::string&,const std::string&);
  void setValuesF(const std::string&,const std::string&);

  void write(std::ostream&) const;
  
};

std::ostream&
operator<<(std::ostream&,const LSwitchCard&);

}

#endif
