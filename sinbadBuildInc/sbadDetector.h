#ifndef sinbadSystem_sbadDetector_h
#define sinbadSystem_sbadDetector_h

class Simulation;

namespace sinbadSystem
{
/*!
  \class sbadDetector
  \version 1.0
  \author A. Milocco
  \date February 2014
  \brief Rod detector
*/

class sbadDetector : public attachSystem::ContainedComp,
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


  void populate(const FuncDataBase&);
  void createUnitVector(const attachSystem::FixedComp&);  
  void createUnitVectorAM(const attachSystem::FixedComp&,const double& );  

  void createSurfaces();
  void createObjects(Simulation&);
  void createLinks();
  std::string detT;
 
 public:

  sbadDetector(const std::string&,const size_t);
  sbadDetector(const sbadDetector&);
  sbadDetector& operator=(const sbadDetector&);
  virtual sbadDetector* clone() const; 
  virtual ~sbadDetector();

  virtual void createAll(Simulation&,
  			 const attachSystem::FixedComp&);
  virtual void createAllAM(Simulation&, const mainSystem::inputParam&,
			   const attachSystem::FixedComp&, const double& offSet);

  
  int isActiveY() const { return activeY; }
  int isActiveZ() const { return activeZ; }

  std::string getDet(const mainSystem::inputParam&) const;
 
};

}

#endif
 
