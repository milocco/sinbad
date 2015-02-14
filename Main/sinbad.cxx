#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cmath>
#include <complex>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <boost/array.hpp>
#include <boost/shared_ptr.hpp>

#include "Exception.h"
#include "MersenneTwister.h"
#include "FileReport.h"
#include "NameStack.h"
#include "RegMethod.h"
#include "GTKreport.h"
#include "OutputLog.h"
#include "BaseVisit.h"
#include "BaseModVisit.h"
#include "objectRegister.h"
#include "InputControl.h"
#include "MatrixBase.h"
#include "Matrix.h"
#include "Vec3D.h"
#include "inputParam.h"
#include "surfIndex.h"
#include "Code.h"
#include "varList.h"
#include "FuncDataBase.h"
#include "MainProcess.h"
#include "SimProcess.h"
#include "SimInput.h"
#include "Simulation.h"
#include "SimPHITS.h"
#include "mainJobs.h"
#include "Volumes.h"
#include "DefPhysics.h"
#include "variableSetup.h"
#include "ImportControl.h"
#include "SourceSelector.h"
// #include "PhysicsCards.h"
#include "Source.h"
#include "TallySelector.h"
#include "World.h"

#include "makeSinbad.h"
#include "writeSinbad.h"
#include "sinbadSource.h"



MTRand RNG(12345UL);

///\cond STATIC
namespace ELog 
{
  ELog::OutputLog<EReport> EM;
  ELog::OutputLog<FileReport> FM("Spectrum.log");
  ELog::OutputLog<FileReport> RN("Renumber.txt");   ///< Renumber
  ELog::OutputLog<StreamReport> CellM;
}
///\endcond STATIC

int 
main(int argc,char* argv[])
 {
  int exitFlag(0);                // Value on exit
  ELog::RegMethod RControl("","main");
  mainSystem::activateLogging(RControl);

  std::string Oname;
  std::vector<std::string> Names;  
  std::map<std::string,std::string> Values;  
  std::map<std::string,std::string> AddValues;  
  std::map<std::string,double> IterVal;           // Variable to iterate 

  // process input:
  InputControl::mainVector(argc,argv,Names);
  std::stringstream cmdLine;
  copy(Names.begin(),Names.end(),
  std::ostream_iterator<std::string>(cmdLine," "));
  Oname=InputControl::getFileName(Names);
  mainSystem::inputParam IParam;
  createSinbadInputs(IParam);

  if (Oname[0]=='-')
   {
    IParam.writeDescription(ELog::EM.Estream());
    ELog::EM<<ELog::endBasic; 
    return 0;
   }  
  IParam.processMainInput(Names);
   sinbadSystem::writeSinbad* SimPtr;
   SimPtr=new sinbadSystem::writeSinbad("");
   SimPtr->setCmdLine(cmdLine.str());        // set full command line
   if (!SimPtr) return -1;

   // The big variable setting
   setVariable::SinbadVariables(SimPtr->getDataBase());


   try
    {

    // Definitions section  
    SimPtr->resetAll();

    // logs
    // ELog::EM.setActive(4);
    // ELog::FM.setActive(4);    
    // ELog::RN.setActive(0); 
  ELog::EM<<"pKeyYYYY "<<ELog::endDiag;

    const std::string expN=IParam.getValue<std::string>("preName");
    std::string expS;
    if(expN=="34") expS="Winfrith Iron Benchmark Experiment (ASPIS)";
    if(expN=="35") expS="Winfrith Iron 88 Benchmark (ASPIS)";
    if(expN=="36") expS="Winfrith Graphite Benchmark Experiment (ASPIS)";
    if(expN=="37") expS="Winfrith Water Benchmark Experiment";
    if(expN=="41") expS="JANUS Phase I (Neutron Transport Through Mild and Stainless Steel)";
    if(expN=="42") expS="JANUS Phase VIII (Neutron Transport Through Sodium and Mild Steel)";
    if(expN=="44") expS="NESDIP-2 Benchmark Experiment (ASPIS)";
    if(expN=="45") expS="18/20 NESDIP-3 Benchmark Experiment (ASPIS)";
    if(expN=="49") expS="ASPIS Neutron/Gamma-Ray Transport Through Water/Steel Arrays";
    if(expN=="75") expS="Winfrith Water/Iron Benchmark Experiment (PCA Replica)";

    ELog::EM<<" Experiment Number: "<<expN<<"\n Experiment Name:  "<<expS<<ELog::endBasic;




    sinbadSystem::makeSinbad SinbadObj(expN);
    World::createOuterObjects(*SimPtr);
    SinbadObj.build(SimPtr,IParam);

    SimPtr->removeDeadSurfaces(0);         

    mainSystem::renumberCells(*SimPtr,IParam);   

    SDef::setSinbadSource(*SimPtr,IParam);

    SimPtr->setSinbadWeights(*SimPtr,IParam);
    SimPtr->setSinbadTally(*SimPtr,IParam);
    SimPtr->setSinbadPhysics(*SimPtr,IParam);

    std::ostringstream cx;
    int MCIndex(0);
    cx<<Oname<<MCIndex+1<<".x";

    SimPtr->prepareWrite();
    SimPtr->SinbadWrite(*SimPtr,cx.str());

    ModelSupport::objectRegister::Instance().write("ObjectRegister.txt");
   }
  catch (ColErr::ExitAbort& EA)
   {
    if (!EA.pathFlag())
     ELog::EM<<"Exiting from "<<EA.what()<<ELog::endCrit;
     exitFlag=-2;
   }
  catch (ColErr::ExBase& A)
   {
    ELog::EM<<"EXCEPTION FAILURE :: "
    <<A.what()<<ELog::endCrit;
    exitFlag= -1;
   }
  delete SimPtr;
  ModelSupport::objectRegister::Instance().reset();
  ModelSupport::surfIndex::Instance().reset();
  return exitFlag;
}



	  // if (renumCellWork)
	  //   tallyRenumberWork(*SimPtr,IParam);
	  // tallyModification(*SimPtr,IParam);

	  // ModelSupport::setSinbadPhysics(*SimPtr,IParam);

	  // Ensure we done loop
	//   do
	//     {
	//       // SimProcess::writeIndexSim(*SimPtr,Oname,MCIndex);

        //       std::ostringstream cx;
        //       cx<<Oname<<MCIndex+1<<".x";

        //       SimPtr->prepareWrite();
	//       //   SimPtr->writeCells(cx.str());
	//       sinbadSystem::simulateSinbad* SimPtrS;
	//       //=createSinbadSimulation(IParam,Names,Oname);
	//       // SimPtr->SinbadWrite(cx.str());
        //       SimPtr->SinbadWrite(*SimPtr,cx.str());
	//      //  ST.SinbadWrite(*SimPtr,cx.str());
	//       //  ST.write(cx.str());
	//       //  SimPtr->SinbadWriteX(cx.str());

	//       //  ST.writeSinbadTally(*SimPtr,IParam);
	//       MCIndex++;
	//     }
	//   while(!iteractive && MCIndex<multi);
	// }

