
#ifndef sinbadSystem_makeSinbad_h
#define sinbadSystem_makeSinbad_h


/*!
  \namespace sinbadSystem
  \brief General Sinbad stuff
  \version 1.0
  \date November 2013
  \author A. Milocco
*/

namespace sinbadSystem
{
  class Cave;
  class LayerPlate;
  class FissionPlate;
  class Detectors;

/*!
  \class makeSinbad
  \version 1.0
  \author A. Milocco
  \date Novenber 2013
  \brief General building manifest for Sinbad
*/

class makeSinbad
{
 private:

  const std::string preName;          ///< Initializtion ta

  
  std::shared_ptr<LayerPlate> shield;     ///< Initial beam control
  std::shared_ptr<LayerPlate> nestorSide;   ///< Stopping volume

  std::shared_ptr<FissionPlate> fissionPlate;   ///< Fission Plate object
  std::shared_ptr<LayerPlate> room; 
  std::vector<boost::shared_ptr<Detectors> > detArray;

  void buildDetectors(Simulation&, const mainSystem::inputParam&);


 public:
  
  makeSinbad(const std::string&);
  makeSinbad(const makeSinbad&);
  makeSinbad& operator=(const makeSinbad&);
  ~makeSinbad();
  
  void build(Simulation*,const mainSystem::inputParam&);

};

}

#endif
