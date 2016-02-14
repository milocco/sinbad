#ifndef sinbadSystem_LayerPlate_h
#define sinbadSystem_LayerPlate_h

class Simulation;

namespace sinbadSystem
{
/*!
  \class LayerPlate
  \version 1.0
  \author A. Milocco (based on S. Ansell starter)
  \date Novenber 2013
  \brief Builds a layered stack object
\ build of shield array
*/

class LayerPlate  : public attachSystem::ContainedComp,
      public attachSystem::FixedComp
{
 protected:
  
  const int slabIndex;        ///< Index of surface offset

  int cellIndex;                ///< Cell index

  double xStep;               ///< X Step distance 
  double yStep;               ///< Y Step distance
  double zStep;               ///< Z Step distance 
  double xyAngle;             ///< xyAngle rotation
  double zAngle;              ///< z angle rotation

  bool frontShared;           ///< Front surface shared
  double width;               ///< Width of slab
  double height;              ///< Height of block
   std::vector<double> slotL;
   std::vector<double> slotT; 
   std::vector<double> slotA; 

   std::vector<int> slotN; 
   std::vector<double> slotX;
   std::vector<double> slotY;
   std::vector<double> slotZ;
   std::vector<int> slotM; 

  double radiusWindow;
  int matWindow;

  size_t nSlab;                ///< number of slabs

  std::vector<double> thick;       ///< slab thickness
  std::vector<int> mat;            ///< Material type
  std::vector<double> matTemp;     ///< Material temperature

  std::string pName; 

  /// Cut out size
  std::vector<double> cutX;
  std::vector<double> cutZ;
  std::vector<int> cutMat;
  std::vector<double> thickSlot;


  double cGap;

  std::string detT;


  // std::string keyName; 


  std::string getFrontSurface(const size_t,const attachSystem::FixedComp&,
			      const long int) const;
  std::string getBackSurface(const size_t,const attachSystem::FixedComp&,
			     const long int) const;
  int getCellIndex(const size_t) const;

  virtual void populate(const FuncDataBase&);
  virtual void createUnitVector(const attachSystem::FixedComp&,const long int);
  virtual void createSurfaces();
  virtual void createObjects(Simulation&,const attachSystem::FixedComp&,
			     const long int);
  virtual double boralGap(const FuncDataBase&, const mainSystem::inputParam&);

  virtual void createLinks();

  // private:


 public:

  LayerPlate(const std::string&);
  LayerPlate(const LayerPlate&);
  LayerPlate& operator=(const LayerPlate&);
  virtual LayerPlate* clone() const;
  virtual ~LayerPlate();

  virtual void createAll(Simulation&,
			 const attachSystem::FixedComp&,
			 const long int);
  virtual void createAllAM(Simulation&, const mainSystem::inputParam&, 
			 const attachSystem::FixedComp&,
			 const long int);


};

}

#endif
 
