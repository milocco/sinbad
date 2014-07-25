#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <utility>
#include <cmath>
#include <complex>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iterator>
#include <boost/array.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/multi_array.hpp>

#include "Exception.h"
#include "FileReport.h"
#include "NameStack.h"
#include "RegMethod.h"
#include "GTKreport.h"
#include "OutputLog.h"
#include "BaseVisit.h"
#include "BaseModVisit.h"
#include "MatrixBase.h"
#include "Matrix.h"
#include "Vec3D.h"
#include "support.h"
#include "stringCombine.h"
#include "inputParam.h"
#include "Surface.h"
#include "surfIndex.h"
#include "surfRegister.h"
#include "objectRegister.h"
#include "Rules.h"
#include "Code.h"
#include "varList.h"
#include "FuncDataBase.h"
#include "HeadRule.h"
#include "Object.h"
#include "Qhull.h"
#include "InsertComp.h"
#include "Simulation.h"
#include "LinkUnit.h"
#include "FixedComp.h"
#include "ContainedComp.h"
#include "ContainedGroup.h"
#include "LayerComp.h"
#include "World.h"
#include "FlightLine.h"
#include "AttachSupport.h"

#include "Cave.h"
#include "sinbadShield.h"
#include "LayerPlate.h"
#include "FissionPlate.h"
#include "sbadDetector.h"
#include "sinbadSource.h"
#include "sinbadMaterial.h"
#include "makeSinbad.h"

  
namespace sinbadSystem 
{

makeSinbad::makeSinbad(const std::string& pKey) :
  preName(pKey),
  Primary(new LayerPlate(pKey+"NestorSide")),
  Secondary(new LayerPlate(pKey+"Shield")),
  fPlate(new FissionPlate(pKey+"FissionPlate"))
  /*!
    Constructor
  */
{
  ModelSupport::objectRegister& OR=
    ModelSupport::objectRegister::Instance();
  OR.addObject(Primary);
  OR.addObject(Secondary);
  OR.addObject(fPlate);
} 

makeSinbad::makeSinbad(const makeSinbad& A) : 
  preName(A.preName),Surround(A.Surround),Primary(A.Primary),
  Secondary(A.Secondary),fPlate(A.fPlate),detArray(A.detArray)
  /*!
    Copy constructor
    \param A :: makeSinbad to copy
  */
{}

makeSinbad&
makeSinbad::operator=(const makeSinbad& A)
  /*!
    Assignment operator
    \param A :: makeSinbad to copy
    \return *this
  */
{
  if (this!=&A)
    {
      Surround=A.Surround;
      Primary=A.Primary;
      Secondary=A.Secondary;
      fPlate=A.fPlate;
      detArray=A.detArray;
    }
  return *this;
}


makeSinbad::~makeSinbad()
  /*!
    Destructor
  */
{}

void
makeSinbad::buildDetectors(Simulation& System)
  /*!
    Build detector units
    \param System :: Simulation
  */
{
  ELog::RegMethod RegA("makeSinbad","buildDetectors");

  const FuncDataBase& Control=System.getDataBase();
  
  const std::string detKey=preName+"Detector";
  const size_t detN=Control.EvalVar<size_t>(detKey+"PositionN");
  for(size_t i=0;i<detN;i++)
    { 
      boost::shared_ptr<sbadDetector> detPtr
	(new sbadDetector(preName+"Detector",i));
      
      detArray.push_back(detPtr);   
      detArray.back()->createAll(System,*Secondary);
      if (detArray.back()->isActive())
	{
	  ELog::EM<<"Active"<<ELog::endDiag;
	  attachSystem::addToInsertControl(System,*Secondary,*detPtr,*detPtr);
	}
    }
  return;
}

void 
makeSinbad::build(Simulation* SimPtr,
		  const mainSystem::inputParam& IParam)
  /*!
    Carry out the full build
    \param SimPtr :: Simulation system
    \param IParam :: Input parameters
  */
{
  // For output stream
  ELog::RegMethod RControl("makeSinbad","build");

  ModelSupport::addSinbadMaterial();
  int voidCell(74123);
  
  Primary->addInsertCell(voidCell) ;
  Primary->createAll(*SimPtr,World::masterOrigin(),0);

  fPlate->addInsertCell(voidCell);
  fPlate->createAll(*SimPtr,*Primary,2);

  Secondary->addInsertCell(voidCell) ;
  Secondary->createAll(*SimPtr,*fPlate,2);

  buildDetectors(*SimPtr);

  //  ShieldArray->addInsertCell(voidCell) ;
  //  ShieldArray->createAll(*SimPtr,World::masterOrigin());

  ELog::EM<<"WARNING EARLY RETURN"<<ELog::endCrit;
   
  return;
}
  

}   // NAMESPACE sinbadSystem

