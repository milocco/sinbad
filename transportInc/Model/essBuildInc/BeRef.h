/********************************************************************* 
  CombLayer : MNCPX Input builder
 
 * File:   essBuildInc/BeRef.h
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
#ifndef essSystem_BeRef_h
#define essSystem_BeRef_h

class Simulation;

namespace essSystem
{
  class BeRefInnerStructure;

/*!
  \class BeRef
  \author S. Ansell
  \version 1.0
  \date February 2013
  \brief Reflector object 
*/

class BeRef : public attachSystem::ContainedComp,
  public attachSystem::FixedComp,
  public attachSystem::CellMap
{
 private:

  const int refIndex;             ///< Index of surface offset
  int cellIndex;                  ///< Cell index

  int engActive;                  ///< Engineering active flag
  std::shared_ptr<BeRefInnerStructure> InnerComp;   ///< Inner components inside Reflector (eng detail)

  double xStep;                   ///< X step
  double yStep;                   ///< Y step
  double zStep;                   ///< Z step
  double xyAngle;                 ///< XY Angle
  double zAngle;                  ///< Z Angle

  double radius;                  ///< Radius
  double height;                  ///< Height
  double wallThick;               ///< Wall thickness
  double wallThickLow;            ///< Wall thickness of the side near the target wheel. Separated from wallThick in order to optimise wrapping with CapMod

  double lowVoidThick;            ///< Low void segment
  double topVoidThick;            ///< Top void segment

  double targSepThick;            ///< Steel seperator at target level

  int refMat;                     ///< reflector material
  int wallMat;                    ///< wall Material
  int targSepMat;                 ///< Separator Mat

  // Functions:

  void populate(const FuncDataBase&,const double,const double,const double);
  void createUnitVector(const attachSystem::FixedComp&);

  void createSurfaces();
  void createObjects(Simulation&);
  void createLinks();

 public:

  BeRef(const std::string&);
  BeRef(const BeRef&);
  BeRef& operator=(const BeRef&);
  virtual ~BeRef();

  void globalPopulate(const FuncDataBase&);
  void createAll(Simulation&,const attachSystem::FixedComp&,
		 const double,const double,const double);

  /// Access to radius
  double getRadius() const { return radius+wallThick; }
};

}

#endif
 
