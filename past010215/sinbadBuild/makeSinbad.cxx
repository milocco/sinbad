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
// #include "sinbadShield.h"
#include "LayerPlate.h"
#include "FissionPlate.h"
// #include "sbadDetector.h"
#include "sinbadSource.h"
#include "sinbadMaterial.h"
#include "makeSinbad.h"
#include "MainProcess.h"
#include "sinbadSource.h"
#include "Detectors.h"

  
namespace sinbadSystem 
{

makeSinbad::makeSinbad(const std::string& pKey) :
  preName(pKey),
  nestorSide(new LayerPlate(pKey+"NestorSide")),
  shield(new LayerPlate(pKey+"Shield")),
  fissionPlate(new FissionPlate(pKey+"FissionPlate"))
  // detArray(new Detectors(pKey+"Det",0))

  /*!
    Constructor
  */
{
  ModelSupport::objectRegister& OR=
    ModelSupport::objectRegister::Instance();
  OR.addObject(nestorSide);
  OR.addObject(fissionPlate);
  OR.addObject(shield);

  //  OR.addObject(detArray);

} 

makeSinbad::makeSinbad(const makeSinbad& A) : 
  preName(A.preName),room(A.room),shield(A.shield),
  nestorSide(A.nestorSide),fissionPlate(A.fissionPlate)
  //,detArray(A.detArray)
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
      room=A.room;
      shield=A.shield;
      nestorSide=A.nestorSide;
      fissionPlate=A.fissionPlate;
      //      detArray=A.detArray;
    }
  return *this;
}


makeSinbad::~makeSinbad()
  /*!
    Destructor
  */
{}


void
makeSinbad::buildDetectors(Simulation& System, const mainSystem::inputParam& IParam)

  /*!
    Build detector units
    \param System :: Simulation
  */
{
  ELog::RegMethod RegA("makeSinbad","buildDetectors");

  const FuncDataBase& Control=System.getDataBase();  
 
 const std::string preName=IParam.getValue<std::string>("preName");
  // support vectors for detector type, scan type and detector offset
  std::vector<std::string> DT;
  std::vector<std::string> DF;
  std::vector<double> DO;

  size_t t(0);
  while(t<10 && IParam.getValue<std::string>("axDet",t).size()!=0)
    {
     DT.push_back(IParam.getValue<std::string>("axDet",t));
     DF.push_back("Axial");
     t=t+1;
    }
  t=0;
  while(t<10 && IParam.getValue<std::string>("vertDet",t).size()!=0)
    {
     DT.push_back(IParam.getValue<std::string>("vertDet",t));
     DF.push_back("Vertical");
     t=t+1;
    }

  // support vector dor detector pile-up
  std::vector<double> CumOffset;  

  // insert a row/column of detectors
  for(size_t i=0;i<DT.size();i++)
    {
     // detector key (e.g. 49S)

     const std::string detKey=preName+DT[i];
     const std::string detFlag=DF[i];


     // number of axial/vertical detectors
     size_t detNY(0);
     size_t detNZ(0);
     if(detFlag=="Axial")
       {
        detNY=Control.EvalVar<size_t>(preName+"DetNY");
        detNZ=1;
       }
     if(detFlag=="Vertical")
       {
        detNY =Control.EvalVar<size_t>(detKey+"VscanNY");
        detNZ =Control.EvalVar<size_t>(preName+"DetNZ");
       }

     // detector thickness for pile up 
     DO.push_back(Control.EvalVar<double>(detKey+"Thick"));
     // detector offset
     double detOffset(0.0);
     double boralOffset(0.0);

 
     // loop along axial positions
     std::string YIndex("");
     std::string ZIndex("");
     for(size_t iy=0;iy<detNY;iy++)
       {
 	YIndex="Y";  
 	std::stringstream IS2("");
        IS2<< iy;
        std::string s2 = IS2.str();
 	YIndex+=s2;     
        // loop along vertical positions
        for(size_t iz=0;iz<detNZ;iz++)
          {
 	   ZIndex="Z";  
           std::stringstream IS1("");
           IS1<< iz;
           std::string s1 = IS1.str();
           ZIndex+=s1;

           size_t id(0); 
           if(detFlag=="Vertical")
             id=iz+iy*(detNY);
           if(detFlag=="Axial")
 	     id=iy;
 
          // create the detector array 
	   boost::shared_ptr<Detectors> detPtr
	   (new Detectors(detKey+YIndex+ZIndex,id));

	   detArray.push_back(detPtr);

	   // calculate offsets for axial pile-up and boral
           size_t dS(0);
           size_t dT(0);
           for(size_t i1=0;i1<10;i1++)
             {
              dS = IParam.getValue<std::string>("axDet",i1).size();
              if(dS!=0) dT=i1+1;
             }
            boralOffset=0.0;
            if(iy==1&&detFlag=="Axial") 
       	     {
              for(size_t n=0;n<dT;n++)
                {
                 boralOffset+=Control.EvalVar<double>(preName+DT[n]+"Thick");
                }
       	     }
            detOffset=0.0;
            if(i>0)
 	      {
 	       for(size_t m=0;m<i;m++)
 	          {
 	           if(detArray[detArray.size()-(i-m)*detNY-1]->isActiveY() )
 	              {
                       detOffset+=DO[m];
                      }
 		  }
 	      }
            else
             {
              detOffset+=0;
 	     }

            if(iy==1&&detFlag=="Axial") 
            detOffset=-boralOffset+detOffset; 


	    // makeSinbad Secondary;

	   detArray.back()->createAllAM(System,IParam,*shield,detOffset,detFlag);

            if (detArray.back()->isActiveY()==1||detArray.back()->isActiveZ()==1)
	      {
		ELog::EM<<detKey<<" Insert Detector: "<<DT[i]<<"   Axial Position: "<<YIndex<<"   Vertical Position "<<ZIndex<<"   Scan: "<<DF[i]<<"   Detector Index "<<id<<ELog::endBasic;
             attachSystem::addToInsertControl(System,*shield,*detPtr,*detPtr);
	      }
 	   }
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

  std::string ND=IParam.getValue<std::string>("xs");
  
  ModelSupport::addSinbadMaterial(ND);


  int voidCell(74123); 

  nestorSide->addInsertCell(voidCell) ;
  nestorSide->createAll(*SimPtr,World::masterOrigin(),0);


  fissionPlate->addInsertCell(voidCell);
  fissionPlate->createAll(*SimPtr,*nestorSide,2);

  shield->addInsertCell(voidCell);
  shield->createAllAM(*SimPtr,IParam,*fissionPlate,2);



    // const ModelSupport::objectRegister& OR=
    // 	  ModelSupport::objectRegister::Instance();
    //  int cellOff=OR.getCell("49FissionPlate");
     //   int cellOn=OR.cell("49FissionPlate");
          // const attachSystem::FixedComp* mainFC=
    //          OR.getObject<attachSystem::FixedComp>(shield);
    // int cellNum=OR.getRange("49FissionPlate");

    // ELog::EM<<" NNNNN "<<cellNum<<"  "<<"  "<<cellOff<<ELog::endBasic;


  // room->addInsertCell(voidCell) ;
  // room->createAllAM(*SimPtr,World::masterOrigin(),0);

  // build all detectors in one shot
  buildDetectors(*SimPtr,IParam);


   
  return;
}
  

}   // NAMESPACE sinbadSystem

