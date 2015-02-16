#ifndef sinbadSystem_Detectors_h
#define sinbadSystem_Detectors_h

class Simulation;

namespace sinbadSystem
{
/*!
  \class Detectors
  \version 1.0
  \author A. Milocco
  \date Novenber 2013
  \brief Builds a layered stack object
\ build of shield array
*/

class Detectors  : public attachSystem::ContainedComp,
      public attachSystem::FixedComp
{
 private:
  
  const std::string baseName;     ///< Base name
  const size_t detID;             ///< Index of Detector
  const int detIndex;             ///< Index of surface offset
  int cellIndex;                  ///< Cell index

  int activeY;                     ///< active flag axial det
  int activeZ;                     ///< active flag vertical det

  double xStep;                   ///< X step
  double yStep;                   ///< Y step
  double zStep;                   ///< Z step
  double xyAngle;                 ///< XY Angle
  double zAngle;                  ///< Z Angle
  double xOffset;                   ///< X step
  double yOffset;                   ///< Y step
  double zOffset;                   ///< Z step

  double diameter;                  ///< Radis of rod 
  double length;                  ///< Length of rod
  int mat;                        ///< Material 
  //  std::string detT;
  int VscanNY;
  double VscanY;
  int VscanNZ;
  double VscanZ;


  void populate(const FuncDataBase&,const std::string& );
  void createUnitVector(const attachSystem::FixedComp&);  
  void createUnitVectorAM(const attachSystem::FixedComp&,const double& );  

  void createSurfaces();
  void createObjects(Simulation&);
  void createLinks();
  std::string detT;
 
 public:

  Detectors(const std::string&,const size_t);
  /* Detectors(const std::string&); */

  Detectors(const Detectors&);
  Detectors& operator=(const Detectors&);
  virtual Detectors* clone() const; 
  virtual ~Detectors();

  virtual void createAll(Simulation&,
  			 const attachSystem::FixedComp&);
  virtual void createAllAM(Simulation&, const mainSystem::inputParam&,
			   const attachSystem::FixedComp&, const double& offSet, const std::string& detFlag);

  
  int isActiveY() const { return activeY; }
  int isActiveZ() const { return activeZ; }

  std::string getDet(const mainSystem::inputParam&) const;
  /* void buildDetectors(Simulation&, const mainSystem::inputParam&,const attachSystem::FixedComp&); */
  /*   std::vector<boost::shared_ptr<Detectors> > detArray; */
  /*   std::vector<int> detActive; */
};

}

#endif
 
