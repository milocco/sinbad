#ifndef sinbadSystem_sinbadCave_h
#define sinbadSystem_sinbadCave_h

class Simulation;

namespace sinbadSystem
{
/*!
  \class sinbadCave
  \version 1.0
  \author A. Milocco
  \date Novenber 2013
  \brief sinbadCave
\ build of shield array
*/

class sinbadCave  : public attachSystem::ContainedComp,
      public attachSystem::FixedComp
{
 private:
  
  const int caveIndex;        ///< Index of surface offset

  int cellIndex;                ///< Cell index

  double offSetX;               ///< Master offset distance 
  double offSetY;               ///< Master offset distance 
  double offSetZ;
  double LLC;
  double LRC;    
  double HUC;
  double HDC;    
  double WIC;
  double WOC;
  int MC;
  double TC;    
  size_t nSlab;    
  double WR;
  std::vector<double> lengthL;
  std::vector<double> lengthR;
  std::vector<double> heightU;
  std::vector<double> heightD;
  std::vector<double> widthI;
  std::vector<double> widthO;    ///< slab thickness
  std::vector<int> mat;      ///< Material type
  int mainCell;
  double LM;

  void populate(const Simulation&);
  void createUnitVector(const attachSystem::FixedComp&);
  void createSurfaces();
  void createObjects(Simulation&);
  void createLinks();

 public:

  sinbadCave(const std::string&);
  sinbadCave(const sinbadCave&);
  sinbadCave& operator=(const sinbadCave&);
  virtual sinbadCave* clone() const; 
  virtual ~sinbadCave();

  std::string getComposite(const std::string&) const;
  /* virtual void addToInsertChain(attachSystem::ContainedComp&,const int) const;     */
  int getCell() const { return mainCell; }


  virtual void createAll(Simulation&,
                         const attachSystem::FixedComp&);
/* , */
/*   			 const attachSystem::ContainedComp&);   */
};

}

#endif
 
