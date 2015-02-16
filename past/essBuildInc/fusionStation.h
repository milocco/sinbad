#ifndef essSystem_fusionStation_h
#define essSystem_fusionStation_h

class Simulation;

namespace essSystem
{
/*!
  \class fusionStation
  \version 1.0
  \author S. Ansell
  \date January 2013
  \brief fusionStation (Rotating bit)

  Provides linkage to its outside on FixedComp[0]
*/

class fusionStation : public attachSystem::ContainedComp,
    public attachSystem::FixedComp
{
 private:
  
  const int TSTIndex;        ///< Index of surface offset

  int cellIndex;                ///< Cell index

  double OffsetX;               ///< Master offset distance 
  double OffsetY;               ///< Master offset distance 
  double OffsetZ;               ///< Master offset distance 

  double AngleXY;
  double AngleZ; 

  double SampleBlockLength;
  double SampleBlockWidth;
  double SampleBlockHeight;
  int SampleBlockColumns;
  int SampleBlockRows;
  int SampleBlockMaterial;
  double SampleBlockTemperature;


  int SampleCladdingMaterial;
  double SampleCladdingThickness;
  double SampleCladdingTemperature;

  int BaffleMaterial;
  double BaffleThickness;
  double BaffleTemperature;

  int BaffleCladdingMaterial;
  double BaffleCladdingThickness;
  double BaffleCladdingTemperature;

  int CoolingMaterial;
  double CoolingThickness;
  double CoolingTemperature;

  int CoolingCladdingMaterial;
  double CoolingCladdingThickness;
  double CoolingCladdingTemperature;

  int mainDetCell;                 ///< Main tungsten cylinder




  void populate(const Simulation&);
  void createUnitVector(const attachSystem::FixedComp&);
  
  void createSurfaces();
  void createObjects(Simulation&);
  void createLinks();

 public:

  fusionStation(const std::string&);
  fusionStation(const fusionStation&);
  fusionStation& operator=(const fusionStation&);
  virtual fusionStation* clone() const; 
  virtual ~fusionStation();



  std::string getComposite(const std::string&) const;
   virtual void addToInsertChain(attachSystem::ContainedComp&) const;  
  int getCell() const { return mainDetCell; }
  virtual void createAll(Simulation&,
			 const attachSystem::FixedComp&);
  
};

}

#endif
 
