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
#include "MainProcess.h"

  
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

// void
// makeSinbad::buildDetectors(Simulation& System)
//   /*!
//     Build detector units
//     \param System :: Simulation
//   */
// {
//   ELog::RegMethod RegA("makeSinbad","buildDetectors");

//   const FuncDataBase& Control=System.getDataBase();
  
//   const std::string detKey=preName+"Detector";


//   const size_t detN=Control.EvalVar<size_t>(detKey+"PositionN");

//   for(size_t i=0;i<detN;i++)
//     { 
//       boost::shared_ptr<sbadDetector> detPtr
// 	(new sbadDetector(preName+"Detector",i));
      
//       detArray.push_back(detPtr);   
//       detArray.back()->createAll(System,*Secondary);
//       if (detArray.back()->isActive())
// 	{

// 	  ELog::EM<<"Active "<<i<<ELog::endDiag;
// 	  attachSystem::addToInsertControl(System,*Secondary,*detPtr,*detPtr);

// 	}
//     }
//   return;
// }

    std::vector<double> Off(10);  
  //  offSet1=0.0;


void
makeSinbad::buildDetectorsAM(Simulation& System, const mainSystem::inputParam& IParam, 
                             const std::string& detType, const int& T)
  /*!
    Build detector units
    \param System :: Simulation
  */
{
  ELog::RegMethod RegA("makeSinbad","buildDetectors");

  const FuncDataBase& Control=System.getDataBase();  
  const std::string detKey=preName+detType;
  const size_t detN=Control.EvalVar<size_t>(preName+"DetN");

  ELog::EM<<"detKey== "<<detKey<<ELog::endDiag;

  int dS(0);
  int dT(0);
  double offSet=Control.EvalVar<double>(detKey+"Thick");
  double offSet2(0.0);
  double offSet3(0.0);

  Off[T]=offSet;
  detT=detType;

  for(size_t i=0;i<detN;i++)
    { 
      boost::shared_ptr<sbadDetector> detPtr
	(new sbadDetector(preName+detType,i));
      detArray.push_back(detPtr);

      offSet1=0.0;   



      if (T>0)
	{
	  for(size_t m=0;m<T;m++)
	   { 
	     if(detArray[detArray.size()-(T-m)*detN-1]->isActive())
	       {   
                offSet1+=Off[m];
               }
             else
               {
                offSet1+=0;
	       }
           }
	}


      for(size_t i=0;i<10;i++)
       {
        dS = IParam.getValue<std::string>("detType",i).size(); 
        if(dS!=0) dT=i+1;
       }

     //       offSet3=0.0;
      if(i==1) 
      	{
         for(size_t n=0;n<dT;n++)
          {
           const std::string TT=IParam.getValue<std::string>("detType",n);
           const std::string detKey1=preName+TT;
           offSet3+=Control.EvalVar<double>(detKey1+"Thick");
	   ELog::EM<<" off3  "<<offSet3<<ELog::endDiag;
          }
      	  offSet2=-offSet3+offSet1; 
          detArray.back()->createAllAM(System,IParam,*Secondary,offSet2);
      	}
       else
	 {
          detArray.back()->createAllAM(System,IParam, *Secondary,offSet1);
	 }

    // ELog::EM<<"Active?? "<<preName+detType<<"  "<<i<<" "<<detArray.size()<<ELog::endDiag;

      if (detArray.back()->isActive())
	{
	  ELog::EM<<" DET "<< preName+detType  <<" OFF "<<offSet1<<"  Active "<<i<<"  "<<detArray.back()->isActive() <<ELog::endDiag;

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
  int TT(0);
 
  Primary->addInsertCell(voidCell) ;
  Primary->createAll(*SimPtr,World::masterOrigin(),0);

  fPlate->addInsertCell(voidCell);
  fPlate->createAll(*SimPtr,*Primary,2);

  Secondary->addInsertCell(voidCell) ;
  // Secondary->createAll(*SimPtr,*fPlate,2);


  Secondary->createAllAM(*SimPtr,IParam,*fPlate,2);


  int t(0);
  int  detI(0);

  while(t<10 && IParam.getValue<std::string>("detType",t).size()!=0)
    {
     const std::string detT=IParam.getValue<std::string>("detType",t);
     detI=t;
     buildDetectorsAM(*SimPtr,IParam,detT,detI);
     t=t+1;
    }


  //  buildDetectors(*SimPtr);  && IParam.getValue<std::string>("detType",t)!=""

  //  ShieldArray->addInsertCell(voidCell) ;
  //  ShieldArray->createAll(*SimPtr,World::masterOrigin());

  ELog::EM<<"WARNING EARLY RETURN"<<ELog::endCrit;
   
  return;
}
  

}   // NAMESPACE sinbadSystem

