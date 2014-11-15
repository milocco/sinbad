#ifndef essSystem_BasementRooms_h
#define essSystem_BasementRooms_h

class Simulation;

namespace essSystem
{

/*!
  \class essBasementRooms
  \author S. Ansell
  \version 1.0
  \date February 2013
  \brief Reflector object 
*/

class essBasementRooms : public attachSystem::ContainedComp,
    public attachSystem::FixedComp
{
 private:

  const int roomIndex;             ///< Index of surface offset
  int cellIndex;                  ///< Cell index

  double xStep;                   ///< X step
  double yStep;                   ///< Y step
  double zStep;                   ///< Z step
  double xyAngle;                 ///< XY Angle
  double zAngle;                  ///< Z Angle

  double width;                  ///< Radius
  double heightY;                  ///< Height dump and forward
  double heightX1;                  ///< Height right back room
  double heightX2;                  ///< Height left room
  double heightX3;                  ///< Height right front room
  double length;               ///< Wall thickness
  double innerRadius;
  double outerRadius;
  double wallThickTop;
  double wallThickTopMax;
  double wallThickDown;
  double wallThickSide;
  double wallThickInner;
  double wallAngleInner;


  int wallMat;                     ///< reflector material
  int MainCell;
  //  int wallMat;                    ///< wall Material
  Geometry::Vec3D Origin1; 
  Geometry::Vec3D X1; 
  Geometry::Vec3D Y1; 
  Geometry::Vec3D Z1; 

  // alberto


  //  double ycut;
  //  double zcut;



  // Functions:

  void populate(const FuncDataBase&);
  void createUnitVector(const attachSystem::FixedComp&);

  void createSurfaces();
  void createObjects(Simulation&);
  void createLinks();

 public:

  essBasementRooms(const std::string&);
  essBasementRooms(const essBasementRooms&);
  essBasementRooms& operator=(const essBasementRooms&);
  virtual ~essBasementRooms();

    int getCell() const { return MainCell; }
  virtual void addToInsertChain(attachSystem::ContainedComp&) const; 
  void createAll(Simulation&,const attachSystem::FixedComp&);
  

};

}

#endif
 
