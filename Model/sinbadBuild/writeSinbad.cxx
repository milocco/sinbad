/********************************************************************* 
  CombLayer : MNCPX Input builder
 
 * File:   src/Simulation.cxx
 *
 * Copyright (c) 2004-2014 by Stuart Ansell
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. 
 *
 ****************************************************************************/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cmath>
#include <complex> 
#include <vector>
#include <list> 
#include <map> 
#include <set>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iterator>
#include <boost/functional.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/array.hpp>

#include "Exception.h"
#include "FileReport.h"
#include "GTKreport.h"
#include "NameStack.h"
#include "RegMethod.h"
#include "OutputLog.h"
#include "BaseVisit.h"
#include "BaseModVisit.h"
#include "mathSupport.h"
#include "support.h"
#include "version.h"
#include "Element.h"
#include "MapSupport.h"
#include "MXcards.h"
#include "Material.h"
#include "DBMaterial.h"
#include "MatrixBase.h"
#include "Matrix.h"
#include "Vec3D.h"
#include "Quaternion.h"
#include "localRotate.h"
#include "masterRotate.h"
#include "Triple.h"
#include "NList.h"
#include "NRange.h"
#include "Tally.h"
#include "cellFluxTally.h"
#include "pointTally.h"
#include "heatTally.h"
#include "tallyFactory.h"
#include "Transform.h"
#include "Surface.h"
#include "surfIndex.h"
#include "surfEqual.h"
#include "Quadratic.h"
#include "surfaceFactory.h"
#include "objectRegister.h"
#include "Rules.h"
#include "varList.h"
#include "Code.h"
#include "FItem.h"
#include "FuncDataBase.h"
#include "SurInter.h"
#include "BnId.h"
#include "Acomp.h"
#include "Algebra.h"
#include "HeadRule.h"
#include "Object.h"
#include "Qhull.h"
// #include "RemoveCell.h"
#include "WForm.h"
#include "weightManager.h"
#include "ModeCard.h"
#include "PhysCard.h"
#include "LSwitchCard.h"
#include "PhysImp.h"
// #include "KGroup.h"
#include "SrcData.h"
#include "SrcItem.h"
#include "Source.h"
#include "KCode.h"
#include "ObjSurfMap.h"
#include "PhysicsCards.h"
#include "ReadFunctions.h"
#include "SimTrack.h"
#include "Simulation.h"
#include "stringCombine.h"
// #include "simulateSinbad.h"
// #include "PhysicsCards.h"
#include "DefPhysics.h"
#include "BasicWWE.h"
#include "support.h"
#include "MainProcess.h"
#include "InputControl.h"
#include "inputParam.h"
#include "ImportControl.h"
#include "WItem.h"
#include "WCells.h"
#include "makeSinbad.h"
#include "writeSinbad.h"
// #include "LayerPlate.h"
#include <boost/lexical_cast.hpp>
// using namespace physicsSystem;


namespace mainSystem
{
 void 
 createSinbadInputs(inputParam& IParam)
  /*!
    Set the specialise inputs for sinbad
    \param IParam :: Input Parameters
  */
{
  //  createInputs(IParam);

  ELog::RegMethod RegA("MainProcess::","createSinbadInputs");


  std::vector<std::string> RItems(10,"");
  std::vector<std::string> DItems(10,"");

  IParam.regDefItem<int>("imp","importance",1,0);
  IParam.regDefItem<int>("n","nps",1,1000000);
  IParam.regDefItemList<std::string>("r","renum",10,RItems);
  IParam.regDefItem<std::string>("preName","preName",1,"35");
  IParam.regDefItemList<std::string>("axDet","detector type (axial scan)",10,DItems);
  IParam.regDefItemList<std::string>("vertDet","detector type (vertical scan)",10,DItems);
  IParam.regDefItem<std::string>("xs","nuclear data library",1,".80c");
  IParam.regDefItem<std::string>("sdefType","sdefType",1,"sinbad");
  IParam.regDefItem<double>("ec","Ecut",1,0.0);

  IParam.setDesc("Ecut","Cut energy");
  IParam.setDesc("n","Number of starting particles (default 1.e6).\n");
  IParam.setDesc("r","Renumber cells and surfaces (recommended).\n");
  IParam.setDesc("preName","Experiment number from SINBAD compilation.\n                    Choose between: \n                     34 == Winfrith Iron Benchmark Experiment (ASPIS), \n                     35 == Winfrith Iron 88 Benchmark(ASPIS), \n                     36 == Winfrith Graphite Benchmark Experiment (ASPIS), \n                     37 == Winfrith Water Benchmark Experiment (ASPIS), \n                     41 == JANUS Phase I (Neutron Transport Through Mild and Stainless Steel), \n                     42 == JANUS Phase VIII (Neutron Transport Through Sodium and Mild Steel), \n                     44 == NESDIP-2 Benchmark Experiment (ASPIS), \n                     45 == 18/20 NESDIP-3 Benchmark Experiment (ASPIS), \n                     49 == ASPIS Neutron/Gamma-Ray Transport Through Water/Steel Arrays, \n                     75 ==Winfrith Water/Iron Benchmark Experiment (PCA Replica). \n ");
  IParam.setDesc("xs","append standard extension in material cards.\n                    Possible choices are: \n                     ENDF/B-VII.1 == .80c, \n                     ENDF/B-VII.0 == .70c, \n                     JEFF3.2 == .31c, \n                     TENDL == . \n                     user extension == .XXc, \n No check on the availability of the elements in the xsdir file  \n");

  IParam.setDesc("axDet","Select detector type (for axial scan only).\n                    Possible choices are: \n                     S == Solphur (cast, except for the first one, the monitor, which is pressed), \n                     Rh == Rhodium, \n                     Mn == Manganese, \n                     Au == Gold, \n                     Tld == Thermoluminiscent detector, \n                     IC == Ionisation chamber. \n Combinations of them are possible just adding items (e.g. --detType Rh S Au). \n Please ascertain that measurements were performed with selected detector.\n");

  IParam.setDesc("vertDet","Define detectors used in vertical scans. \n                    Possibilities are: \n                     Mn == Manganese,\n                     Tld == Thermoluminiscent detector. \n");

  IParam.setDesc("imp","importance card.\n                    Choose between: \n                     0 == energy and cell weight windows (the default), \n                     1 == no action; importance 1 in any cell at any energy, \n                     2 == split and kill based on cell but not on energy. \n");

  IParam.setDesc("sdefType","source model.\n                    Choose between: \n                     0 == U-235 fission spectrum from ENDF/B-VII.0 and area-conservinfg interpolation (the default), \n                     1 == U-235 fission spectrum from MCNP + area-conserving interpolation, \n                     2 == not yet defined. \n");


  return;
}


}  // NAMESPACE mainSystem









namespace sinbadSystem
{
  writeSinbad::writeSinbad(const std::string& Key): Simulation()
  {}

  writeSinbad::writeSinbad(const writeSinbad& A):Simulation(A),cellS(A.cellS),
						 cellI1(A.cellI1),cellI2(A.cellI2),WFlag(A.WFlag),
						 EC(A.EC),DN(A.DN),
                                                 DT1(A.DT1),DT2(A.DT2),NP(A.NP)
  /*!
    Copy constructor
    \param A :: writeSinbad to copy
  */
  {}

writeSinbad&
writeSinbad::operator=(const writeSinbad& A)
  /*!
    Assignment operator
    \param A :: writeSinbad to copy
    \return *this
  */
{
  if (this!=&A)
    {
      Simulation::operator=(A);
      //      PhysicsCards::operator=(A);
      cellS=A.cellS;
      cellI1=A.cellI1;
      cellI2=A.cellI2;
      WFlag=A.WFlag;
      EC=A.EC;
      DN=A.DN;
      DT1=A.DT1;
      DT2=A.DT2;
      NP=A.NP;
    }
  return *this;
}

writeSinbad*
writeSinbad::clone() const
  /*!
    Virtual copy constructor
    \return new(this)
  */
{
  return new writeSinbad(*this);
}

writeSinbad::~writeSinbad() 
  /*!
    Destructor
  */
{}




 void 
 writeSinbad::setSinbadPhysics(Simulation& System,
		  const mainSystem::inputParam& IParam)
{
  std::string WEC("");
  if(IParam.flag("vertDet")==1)
  WEC=IParam.getValue<std::string>("vertDet",0);
  else if(IParam.flag("axDet")==1)
  WEC=IParam.getValue<std::string>("axDet",0);



  if(WEC=="S" && IParam.getValue<std::string>("axDet",1)=="")
    {
     EC=0.01;
     DN=5.e+6;
    }
  else if(WEC=="In" && IParam.getValue<std::string>("axDet",1)=="")
    {
     EC=0.01;
     DN=1.e+7;
    }
  else if(WEC=="Rh" && IParam.getValue<std::string>("axDet",1)=="")
    {
     EC=0.01;
     DN=1.e+7;
    }
  else if(WEC=="Al" && IParam.getValue<std::string>("axDet",1)=="")
    {
     EC=1.0;
     DN=1.e+7;
    }
  else
    {
     EC=0.0;
     DN=1.e+7;
    }


  if(IParam.getValue<std::string>("axDet",1)=="Au")
    {
     EC=0.0;
     DN=1.e+8;
    }




 System.getPC().setMode("n");

 if(IParam.flag("n")==1) 
    DN= IParam.getValue<int>("nps");

 if(IParam.flag("ec")==1) 
    EC= IParam.getValue<double>("Ecut");

 // System.getPC().setNPS(12.e+6);
  System.getPC().setRND(3469871871985);	


  // physicsSystem::PhysCard& cpi=System.getPC().addPhysCard("cut","/");
  // cpi.setValues("j 0.0");

  // physicsSystem::PhysicsCards& PC=System.getPC();
  // physicsSystem::PhysCard& NCut=PC.addPhysCard("cut","n");
  // NCut.setValues(4,1e+8,0.0,0.4,-0.1);




//  System.processCellsImp();
//  System.getPC().setCells("imp",1,0);   
//  // System.getPC().setEnergyCut(98.0);
// System.getPC().addPhysImp("imp","n");


//  System.getPC().setPrintNum("-30 ");



  return; 
}



void
writeSinbad::setSinbadWeights(Simulation& System,
		 const mainSystem::inputParam& IParam)
  /*!
    Set individual weights based on cell as they are created in the makeFile
    \param System :: Simulation
    \param IParam :: input stream
    - first shield layers and associate weights

   */
{
  ELog::RegMethod RegA("BasicWWE","simulationWeights");

  System.populateCells();
  System.createObjSurfMap();

  std::string WType("neutral");

  if(IParam.flag("imp")==0)
    WFlag=0;
  if(IParam.flag("imp")==1)
    WFlag=IParam.getValue<int>("imp");

  if(IParam.flag("vertDet")==1)
  WType=IParam.getValue<std::string>("vertDet",0);
  else if(IParam.flag("axDet")==1)
  WType=IParam.getValue<std::string>("axDet",0);
  else
    ELog::EM<<"NO DETECTORS INCLUDED !!! "<<ELog::endDiag;

  // Manganese or gold between Cd covers
  if(IParam.getValue<std::string>("axDet",0)=="Cd"&&IParam.getValue<std::string>("axDet",1)=="Mn")
  WType=IParam.getValue<std::string>("axDet",1);

  if(IParam.getValue<std::string>("vertDet",0)=="Cd"&&IParam.getValue<std::string>("vertDet",1)=="Mn")
  WType=IParam.getValue<std::string>("vertDet",1);

  if(IParam.getValue<std::string>("axDet",0)=="Cd"&&IParam.getValue<std::string>("axDet",1)=="Au")
  WType=IParam.getValue<std::string>("axDet",1);

  if(IParam.getValue<std::string>("vertDet",0)=="Cd"&&IParam.getValue<std::string>("vertDet",1)=="Au")
  WType=IParam.getValue<std::string>("vertDet",1);

  // detector pile up
  if(IParam.flag("axDet")==1 && IParam.getValue<std::string>("axDet",1)!="" && WType!="Mn")
  WType="neutral";
  if(IParam.flag("vertDet")==1 && IParam.getValue<std::string>("vertDet",1)!="" && WType!="Mn")
  WType="neutral";


  if(IParam.flag("axDet")==1 && IParam.getValue<std::string>("axDet",1)!="" && WType!="Au")
  WType="neutral";
  if(IParam.flag("vertDet")==1 && IParam.getValue<std::string>("vertDet",1)!="" && WType!="Au")
  WType="neutral";
  
  // set the energy splitting ranges (reactor physics apps)

  std::vector<double> Eval(6);
  Eval[0]=1.e-9;
  Eval[1]=1.e-7;
  Eval[2]=1.e-5;
  Eval[3]=1.e-2;
  Eval[4]=1.0;
  Eval[5]=31.0;

  // set the weights based on detector type
  
  std::vector<double> WT(6);
  ELog::EM<<"Weight Type: "<<WType<<ELog::endDiag;

  if (WType=="Mn"||WType=="Au")
    {
  // no action
 WT[0]=0.5;WT[1]=0.5;WT[2]=0.5;
 WT[3]=0.5;WT[4]= 0.5;WT[5]= 0.5;
    }
  else if (WType=="S"||WType=="Al")
    {
  WT[0]=16;WT[1]=4;WT[2]=1;
  WT[3]=0.25;WT[4]= 0.05;WT[5]= 0.05;
    }
  else if (WType=="Rh"||WType=="In")
    {
    //( In good???)
     WT[0]=16;WT[1]=4;WT[2]=2;
     WT[3]=0.05;WT[4]= 0.05;WT[5]= 0.25;
    }
  else if (WType=="Ic")
    {
     WT[0]=8.0;WT[1]=4.0;WT[2]=2.0;
     WT[3]=0.5;WT[4]= 0.5;WT[5]= 1.0;
    }
  // in case of multiple detectors set neutral weight windows
  else if (WType=="neutral")
    {
     WT[0]=0.5;WT[1]=0.5;WT[2]=0.5;
     WT[3]=0.5;WT[4]= 0.5;WT[5]= 0.5;
    }
  else
    throw ColErr::InContainerError<std::string>(WType,"Unknown weight type");


  WeightSystem::weightManager& WM=
  WeightSystem::weightManager::Instance();  

  WM.addParticle<WeightSystem::WCells>('n');
  WeightSystem::WCells* WF=
    dynamic_cast<WeightSystem::WCells*>(WM.getParticle('n'));
  if (!WF)
    throw ColErr::InContainerError<std::string>("n","WCell - WM");

  WF->setEnergy(Eval);
  System.populateWCells();
  WF->balanceScale(WT);
  WF-> setWeights(WT);  //dropped log from this! 

  const FuncDataBase& Control=System.getDataBase();  
  const std::string preName=IParam.getValue<std::string>("preName");

  // starting number of cells is 3: outer world, outer room, the first void layer in front of the fission plate is teh 3rd cell 
  int cellOffset(3);

 std::vector<double> WT0(6);

 WT0[0]=-1;
 WT0[1]=-1;
 WT0[2]=-1;
 WT0[3]=-1;
 WT0[4]=-1;
 WT0[5]=-1;

 WF-> setWeights(1,WT0);  
  // std::stringstream IS2(" ");
  cellI1 = "imp:n 0 1 1 ";
  cellI2 = "imp:n 0 1 1 ";

  // set axial limits of imporance based on the presence of the detectors (problem specific)
  
  std::vector<double> distW(6);
  double cumThick(0.0);

  if(preName=="35")
   {
    distW[0]=10;
    distW[1]=30;
    distW[2]=50;
    distW[3]=80;
    distW[4]=100;
    distW[5]=140;
   }
  else if(preName=="36")
   {
     // this should not be changed, slab thicknesses are set already for wr
    distW[0]=1;
    distW[1]=30;
    distW[2]=60;
    distW[3]=90;
    distW[4]=170;
    distW[5]=200;
   }
  else if(preName=="41")
   {
     // this should not be changed, slab thicknesses are set already for wr
    distW[0]=15;
    distW[1]=30;
    distW[2]=60;
    distW[3]=75;
    distW[4]=90;
    distW[5]=200;
   }
  else if(preName=="49")
   {
    distW[0]=10;
    distW[1]=25;
    distW[2]=50;
    distW[3]=80;
    distW[4]=95;
    distW[5]=140;
   }
  else  if(preName=="75")
   {
    distW[0]=10;
    distW[1]=20;
    distW[2]=40;
    distW[3]=55.3;
    distW[4]=85;
    distW[5]=150;
   }
  else
   {
    distW[0]=10;
    distW[1]=30;
    distW[2]=60;
    distW[3]=90;
    distW[4]=120;
    distW[5]=150;
   }


  // S is number of slabs

 int S=Control.EvalVar<size_t>(preName+"ShieldNSlab");
 int SN(0);
 int SC(0);

 // associate to any slab (also voids) a weight factor
 for(int i=0;i<S;i++)
  {   
   const std::string NStr(StrFunc::makeString(i));
   cumThick+=Control.EvalVar<double>(preName+"ShieldThick"+NStr);
   double RF(0);

   if(cumThick<=distW[0])
      {
       if(preName=="36")
	{
         SN=Control.EvalVar<int>(preName+"Shield"+NStr+"SlotN");
         SC=Control.EvalVar<int>(preName+"ShieldCutN"+NStr);

         for (int n=0;n<SN;n++)
	  {
            RF=pow(2,0);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
            cellI1 += boost::lexical_cast<std::string>(1);
            cellI1 += " ";
            cellI2 += boost::lexical_cast<std::string>(RF);
            cellI2 += " ";
	  }
	 for(size_t m=0;m<SC;m++)
	   {
          RF=pow(2,0);
          cellOffset++;
          WF->rescale(cellOffset,cellOffset,RF);   
          cellI1 += boost::lexical_cast<std::string>(1);
          cellI1 += " ";
          cellI2 += boost::lexical_cast<std::string>(RF);
          cellI2 += " ";
	   }
	}
       else
	{
         RF=pow(2,0);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
         cellI1 += boost::lexical_cast<std::string>(1);
         cellI1 += " ";
         cellI2 += boost::lexical_cast<std::string>(RF);
         cellI2 += " ";
        }
      }
   else if(cumThick>distW[0] && cumThick<=distW[1])
      {
       if(preName=="75")
       // because of cuts
	{
         RF=pow(2,1);
         WF->rescale(cellOffset+2*i-1,cellOffset+2*i-1,RF);   
         cellI1 += boost::lexical_cast<std::string>(1);
         cellI1 += " ";
         cellI2 += boost::lexical_cast<std::string>(RF);
         cellI2 += " ";

         RF=pow(2,0);
         WF->rescale(cellOffset+2*i,cellOffset+2*i,RF);   
         cellI1 += boost::lexical_cast<std::string>(1);
         cellI1 += " ";
         cellI2 += boost::lexical_cast<std::string>(RF);
         cellI2 += " ";
	}
       else if(preName=="36")
	{
         SN=Control.EvalVar<int>(preName+"Shield"+NStr+"SlotN");
         SC=Control.EvalVar<int>(preName+"ShieldCutN"+NStr);
         RF=pow(2,1);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
         cellI1 += boost::lexical_cast<std::string>(1);
         cellI1 += " ";
         cellI2 += boost::lexical_cast<std::string>(RF);
         cellI2 += " ";
         for (int n=0;n<SN;n++)
	  {
            RF=pow(2,1);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
            cellI1 += boost::lexical_cast<std::string>(1);
            cellI1 += " ";
            cellI2 += boost::lexical_cast<std::string>(RF);
            cellI2 += " ";
	  }

          RF=pow(2,1);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
          cellI1 += boost::lexical_cast<std::string>(1);
          cellI1 += " ";
          cellI2 += boost::lexical_cast<std::string>(RF);
          cellI2 += " ";

          RF=pow(2,1);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
          cellI1 += boost::lexical_cast<std::string>(1);
          cellI1 += " ";
          cellI2 += boost::lexical_cast<std::string>(RF);
          cellI2 += " ";

          RF=pow(2,0);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
          cellI1 += boost::lexical_cast<std::string>(1);
          cellI1 += " ";
          cellI2 += boost::lexical_cast<std::string>(RF);
          cellI2 += " ";
	}
       else 
	{
         RF=pow(2,1);
         WF->rescale(cellOffset+i,cellOffset+i,RF);
         cellI1 += boost::lexical_cast<std::string>(1);
         cellI1 += " ";
         cellI2 += boost::lexical_cast<std::string>(RF);
         cellI2 += " ";
	}   
      }
   else if(cumThick>distW[1] && cumThick<=distW[2])
      {
       if(preName=="75")
       // because of cuts
	{
         RF=pow(2,2);
         WF->rescale(cellOffset+2*i-1,cellOffset+2*i-1,RF);   
         cellI1 += boost::lexical_cast<std::string>(1);
         cellI1 += " ";
         cellI2 += boost::lexical_cast<std::string>(RF);
         cellI2 += " ";

         RF=pow(2,1);
         WF->rescale(cellOffset+2*i,cellOffset+2*i,RF);   
         cellI1 += boost::lexical_cast<std::string>(1);
         cellI1 += " ";
         cellI2 += boost::lexical_cast<std::string>(RF);
         cellI2 += " ";
	}
       else if(preName=="36")
	{
         SN=Control.EvalVar<int>(preName+"Shield"+NStr+"SlotN");
         SC=Control.EvalVar<int>(preName+"ShieldCutN"+NStr);
         RF=pow(2,2);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
         cellI1 += boost::lexical_cast<std::string>(1);
         cellI1 += " ";
         cellI2 += boost::lexical_cast<std::string>(RF);
         cellI2 += " ";
         for (int n=0;n<SN;n++)
	  {
            RF=pow(2,2);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
            cellI1 += boost::lexical_cast<std::string>(1);
            cellI1 += " ";
            cellI2 += boost::lexical_cast<std::string>(RF);
            cellI2 += " ";
	  }

          RF=pow(2,2);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
          cellI1 += boost::lexical_cast<std::string>(1);
          cellI1 += " ";
          cellI2 += boost::lexical_cast<std::string>(RF);
          cellI2 += " ";

          RF=pow(2,1);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
          cellI1 += boost::lexical_cast<std::string>(1);
          cellI1 += " ";
          cellI2 += boost::lexical_cast<std::string>(RF);
          cellI2 += " ";

          RF=pow(2,0);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
          cellI1 += boost::lexical_cast<std::string>(1);
          cellI1 += " ";
          cellI2 += boost::lexical_cast<std::string>(RF);
          cellI2 += " ";
	}
       else
	{
         RF=pow(2,2);
         WF->rescale(cellOffset+i,cellOffset+i,RF);   
         cellI1 += boost::lexical_cast<std::string>(1);
         cellI1 += " ";
         cellI2 += boost::lexical_cast<std::string>(RF);
         cellI2 += " ";
        }
      }
   else if(cumThick>distW[2] && cumThick<=distW[3])
      {
       if(preName=="75")
       // because of cuts
	{
         RF=pow(2,3);
         WF->rescale(cellOffset+2*i-1,cellOffset+2*i-1,RF);   
         cellI1 += boost::lexical_cast<std::string>(1);
         cellI1 += " ";
         cellI2 += boost::lexical_cast<std::string>(RF);
         cellI2 += " ";
         RF=pow(2,2);
         WF->rescale(cellOffset+2*i,cellOffset+2*i,RF);   
         cellI1 += boost::lexical_cast<std::string>(1);
         cellI1 += " ";
         cellI2 += boost::lexical_cast<std::string>(RF);
         cellI2 += " "; 
	}
       else if(preName=="36")
	{
         SN=Control.EvalVar<int>(preName+"Shield"+NStr+"SlotN");
         SC=Control.EvalVar<int>(preName+"ShieldCutN"+NStr);
         RF=pow(2,3);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
         cellI1 += boost::lexical_cast<std::string>(1);
         cellI1 += " ";
         cellI2 += boost::lexical_cast<std::string>(RF);
         cellI2 += " ";
         for (int n=0;n<SN;n++)
	  {
            RF=pow(2,3);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
            cellI1 += boost::lexical_cast<std::string>(1);
            cellI1 += " ";
            cellI2 += boost::lexical_cast<std::string>(RF);
            cellI2 += " ";
	  }

          RF=pow(2,3);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);      
          cellI1 += boost::lexical_cast<std::string>(1);
          cellI1 += " ";
          cellI2 += boost::lexical_cast<std::string>(RF);
          cellI2 += " ";

          RF=pow(2,2);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
          cellI1 += boost::lexical_cast<std::string>(1);
          cellI1 += " ";
          cellI2 += boost::lexical_cast<std::string>(RF);
          cellI2 += " ";

          RF=pow(2,1);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
          cellI1 += boost::lexical_cast<std::string>(1);
          cellI1 += " ";
          cellI2 += boost::lexical_cast<std::string>(RF);
          cellI2 += " ";
	}   
       else
	{
         RF=pow(2,3);
         WF->rescale(cellOffset+i,cellOffset+i,RF);
         cellI1 += boost::lexical_cast<std::string>(1);
         cellI1 += " ";
         cellI2 += boost::lexical_cast<std::string>(RF);
         cellI2 += " ";
        }
     }
   else if(cumThick>distW[3] && cumThick<=distW[4])
      {
       if(preName=="75")
       // because of cuts
	{
         RF=pow(2,4);
         WF->rescale(cellOffset+2*i-1,cellOffset+2*i-1,RF);   
         cellI1 += boost::lexical_cast<std::string>(1);
         cellI1 += " ";
         cellI2 += boost::lexical_cast<std::string>(RF);
         cellI2 += " ";

	 RF=pow(2,3);
         WF->rescale(cellOffset+2*i,cellOffset+2*i,RF);   
         cellI1 += boost::lexical_cast<std::string>(1);
         cellI1 += " ";
         cellI2 += boost::lexical_cast<std::string>(RF);
         cellI2 += " "; 
	}
       else if(preName=="36")
	{
         SN=Control.EvalVar<int>(preName+"Shield"+NStr+"SlotN");
         SC=Control.EvalVar<int>(preName+"ShieldCutN"+NStr);
         RF=pow(2,1);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
         cellI1 += boost::lexical_cast<std::string>(1);
         cellI1 += " ";
         cellI2 += boost::lexical_cast<std::string>(RF);
         cellI2 += " ";
         for (int n=0;n<SN;n++)
	  {
            RF=pow(2,1);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
            cellI1 += boost::lexical_cast<std::string>(1);
            cellI1 += " ";
            cellI2 += boost::lexical_cast<std::string>(RF);
            cellI2 += " ";
	  }

          RF=pow(2,0);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
          cellI1 += boost::lexical_cast<std::string>(1);
          cellI1 += " ";
          cellI2 += boost::lexical_cast<std::string>(RF);
          cellI2 += " ";

          RF=pow(2,1);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
          cellI1 += boost::lexical_cast<std::string>(1);
          cellI1 += " ";
          cellI2 += boost::lexical_cast<std::string>(RF);
          cellI2 += " ";

          RF=pow(2,0);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
          cellI1 += boost::lexical_cast<std::string>(1);
          cellI1 += " ";
          cellI2 += boost::lexical_cast<std::string>(RF);
          cellI2 += " ";
	}
       else
	{
         RF=pow(2,2);
         WF->rescale(cellOffset+i,cellOffset+i,RF);
         cellI1 += boost::lexical_cast<std::string>(1);
         cellI1 += " ";
         cellI2 += boost::lexical_cast<std::string>(RF);
         cellI2 += " "; 
        }
    }
   else if(cumThick>distW[4] && cumThick<=distW[5])
      {
       if(preName=="75")
       // because of cuts
	{
         RF=pow(2,0);
         WF->rescale(cellOffset+2*i-1,cellOffset+2*i-1,RF);   
         cellI1 += boost::lexical_cast<std::string>(1);
         cellI1 += " ";
         cellI2 += boost::lexical_cast<std::string>(RF);
         cellI2 += " ";

         RF=pow(2,0);
         WF->rescale(cellOffset+2*i,cellOffset+2*i,RF);   
         cellI1 += boost::lexical_cast<std::string>(1);
         cellI1 += " ";
         cellI2 += boost::lexical_cast<std::string>(RF);
         cellI2 += " ";
	}
       else if(preName=="36")
	{
         SN=Control.EvalVar<int>(preName+"Shield"+NStr+"SlotN");
         SC=Control.EvalVar<int>(preName+"ShieldCutN"+NStr);
         RF=pow(2,0);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
         cellI1 += boost::lexical_cast<std::string>(1);
         cellI1 += " ";
         cellI2 += boost::lexical_cast<std::string>(RF);
         cellI2 += " ";
         for (int n=0;n<SN;n++)
	  {
            RF=pow(2,0);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
            cellI1 += boost::lexical_cast<std::string>(1);
            cellI1 += " ";
            cellI2 += boost::lexical_cast<std::string>(RF);
            cellI2 += " ";
	  }

          RF=pow(2,0);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
          cellI1 += boost::lexical_cast<std::string>(1);
          cellI1 += " ";
          cellI2 += boost::lexical_cast<std::string>(RF);
          cellI2 += " ";

          RF=pow(2,0);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
          cellI1 += boost::lexical_cast<std::string>(1);
          cellI1 += " ";
          cellI2 += boost::lexical_cast<std::string>(RF);
          cellI2 += " ";

          RF=pow(2,0);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
          cellI1 += boost::lexical_cast<std::string>(1);
          cellI1 += " ";
          cellI2 += boost::lexical_cast<std::string>(RF);
          cellI2 += " ";
	}
       else
        {
         RF=pow(2,1);
         WF->rescale(cellOffset+i,cellOffset+i,RF);
         cellI1 += boost::lexical_cast<std::string>(1);
         cellI1 += " ";
         cellI2 += boost::lexical_cast<std::string>(RF);
         cellI2 += " ";   
        }

     }
    else
      {
      if(preName=="75")
       // because of cuts
	{
         RF=pow(2,0);
         WF->rescale(cellOffset+2*i-1,cellOffset+2*i-1,RF);   
         cellI1 += boost::lexical_cast<std::string>(1);
         cellI1 += " ";
         cellI2 += boost::lexical_cast<std::string>(RF);
         cellI2 += " ";
         RF=pow(2,0);
         WF->rescale(cellOffset+2*i,cellOffset+2*i,RF);   
         cellI1 += boost::lexical_cast<std::string>(1);
         cellI1 += " ";
         cellI2 += boost::lexical_cast<std::string>(RF);
         cellI2 += " ";
	}
       else if(preName=="36")
	{
         SN=Control.EvalVar<int>(preName+"Shield"+NStr+"SlotN");
         SC=Control.EvalVar<int>(preName+"ShieldCutN"+NStr);
         RF=pow(2,0);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
         cellI1 += boost::lexical_cast<std::string>(1);
         cellI1 += " ";
         cellI2 += boost::lexical_cast<std::string>(RF);
         cellI2 += " ";
         for (int n=0;n<SN;n++)
	  {
            RF=pow(2,0);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
            cellI1 += boost::lexical_cast<std::string>(1);
            cellI1 += " ";
            cellI2 += boost::lexical_cast<std::string>(RF);
            cellI2 += " ";
	  }

          RF=pow(2,0);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
          cellI1 += boost::lexical_cast<std::string>(1);
          cellI1 += " ";
          cellI2 += boost::lexical_cast<std::string>(RF);
          cellI2 += " ";

          RF=pow(2,0);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
          cellI1 += boost::lexical_cast<std::string>(1);
          cellI1 += " ";
          cellI2 += boost::lexical_cast<std::string>(RF);
          cellI2 += " ";

          RF=pow(2,0);
            cellOffset++;
            WF->rescale(cellOffset,cellOffset,RF);   
          cellI1 += boost::lexical_cast<std::string>(1);
          cellI1 += " ";
          cellI2 += boost::lexical_cast<std::string>(RF);
          cellI2 += " ";
	}
      else
       {   
        RF=pow(2,0);
        WF->rescale(cellOffset+i,cellOffset+i,RF);   
        cellI1 += boost::lexical_cast<std::string>(1);
        cellI1 += " ";
        cellI2 += boost::lexical_cast<std::string>(RF);
        cellI2 += " "; 
	}
     }
  }

  if(preName=="36")
   cellOffset=cellOffset;
  else if(preName=="75")
   cellOffset=cellOffset+2*S-1;
  else
  cellOffset=3+S+1;

  int NS=Control.EvalVar<size_t>(preName+"NestorSideNSlab");
  for(int i=0;i<NS-1;i+=2)
   {   
    double SF=(NS/2+1);
    double RF=i/SF/2; 
    if(i==0) RF=1/SF/2;
    WF->rescale(cellOffset+i,cellOffset+i+1,RF);  
   }

  for(int i=0;i<NS-1;i++)
   {   
    cellI1 += boost::lexical_cast<std::string>(1);
    cellI1 += " ";
    // no n-killing with imp option 2 (there is source bias anyway)
    cellI2 += boost::lexical_cast<std::string>(1);
    cellI2 += " ";   
   }


 size_t FPL1=Control.EvalVar<size_t>(preName+"FissionPlateNSlab");
 size_t FPX1=Control.EvalVar<size_t>(preName+"FissionPlateNXSpace");
 size_t FPZ1=Control.EvalVar<size_t>(preName+"FissionPlateNZSpace");
 size_t FPN1=FPL1+(FPZ1-1)*(FPX1-1)+3;

 std::string DTV=IParam.getValue<std::string>("axDet",0);
 int FPN=static_cast<int>(FPN1);

  for(int i=0;i<FPN+1;i++)
   {   
    cellI1 += boost::lexical_cast<std::string>(1);
    cellI1 += " ";
    cellI2 += boost::lexical_cast<std::string>(1);
    cellI2 += " ";   
   }

  cellOffset=3+NS+S+FPN;
  if(preName=="36")
   cellOffset=cellOffset+NS+FPN;
  // temp fix 1 cell more?!/
  // if(preName=="41")
  // cellOffset=cellOffset-1;
 
 
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
        detNZ=Control.EvalPair<int>(detKey,preName,"DetNZ");
	//  detNZ =Control.EvalVar<size_t>(preName+"DetNZ");
       }

     double detOffset(0.0);
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

	    // makeSinbad Secondary;
	   if(Control.EvalVar<double>(detKey+"Active"+YIndex)==1)
	    {
	     detOffset=Control.EvalVar<double>(preName+"Step"+YIndex);
	     cellOffset=cellOffset+1;
	     double RD(0.0);

             if(detFlag=="Axial" && detOffset<=distW[0])
              {
               RD=pow(2,0);
               WF->rescale(cellOffset,cellOffset,RD);
               cellI1 += boost::lexical_cast<std::string>(1);
               cellI1 += " ";
               cellI2 += boost::lexical_cast<std::string>(RD);
               cellI2 += " ";   
              }

             else if(detFlag=="Axial" && detOffset>distW[0] && detOffset<=distW[1])
              {
               RD=pow(2,1);
               WF->rescale(cellOffset,cellOffset,RD);   
               cellI1 += boost::lexical_cast<std::string>(1);
               cellI1 += " ";
               cellI2 += boost::lexical_cast<std::string>(RD);
               cellI2 += " ";   
              }

             else if(detFlag=="Axial" && detOffset>distW[1] && detOffset<=distW[2])
              {
               RD=pow(2,2);
               WF->rescale(cellOffset,cellOffset,RD);   
               cellI1 += boost::lexical_cast<std::string>(1);
               cellI1 += " ";
               cellI2 += boost::lexical_cast<std::string>(RD);
               cellI2 += " ";   
              }

           else if(detFlag=="Axial" && detOffset>distW[2] && detOffset<distW[3])
              {
               RD=pow(2,3);
               WF->rescale(cellOffset,cellOffset,RD);   
               cellI1 += boost::lexical_cast<std::string>(1);
               cellI1 += " ";
               cellI2 += boost::lexical_cast<std::string>(RD);
               cellI2 += " ";   
              }

           else if(detFlag=="Axial" && detOffset>distW[3] && detOffset<=distW[4])
              {
               RD=pow(2,2);
               WF->rescale(cellOffset,cellOffset,RD);   
               cellI1 += boost::lexical_cast<std::string>(1);
               cellI1 += " ";
               cellI2 += boost::lexical_cast<std::string>(RD);
               cellI2 += " ";   
              }
           else if(detFlag=="Axial" && detOffset>distW[4] && detOffset<=distW[5])
              {
               RD=pow(2,1);
               WF->rescale(cellOffset,cellOffset,RD);   
               cellI1 += boost::lexical_cast<std::string>(1);
               cellI1 += " ";
               cellI2 += boost::lexical_cast<std::string>(RD);
               cellI2 += " ";   
              }
            else
              {
	       if(detFlag=="Axial") 
		{ 
                 RD=pow(2,0);
                 WF->rescale(cellOffset,cellOffset,RD);
                 cellI1 += boost::lexical_cast<std::string>(1);
                 cellI1 += " ";
                 cellI2 += boost::lexical_cast<std::string>(RD);
                 cellI2 += " ";   
		}
		if(detFlag=="Vertical") 
		 {
		 if(preName=="49")
                 RD=pow(2,2);
		 if(preName=="75")
                 RD=pow(2,2);
		 if(preName=="41")
                 RD=pow(2,2);
		 
                 WF->rescale(cellOffset,cellOffset,RD);
		 
               cellI1 += boost::lexical_cast<std::string>(1);
               cellI1 += " ";
               cellI2 += boost::lexical_cast<std::string>(RD);
               cellI2 += " ";   
		 }
              }
 
	    }

 	   }
 	 }
    }

  // temp fix: assume remaing detector cells (for some reason not parsed above)
  // are vertical detectors (like TLD) and rescale to 4
 const std::vector<int> CD=System.getCellVector();
 int RST(0);
 RST=CD.size()-cellOffset;
 ELog::EM<<"HERE==== !!! "<<RST<<" "<<CD.size()<<"  "<<cellOffset<<ELog::endDiag;

 if (RST<0) RST=-RST;
 
if (RST>0)
  {
   for(size_t i=0;i<RST;i++)
    {
     cellOffset+=1;                 
     WF->rescale(cellOffset,cellOffset,4);
     cellI1 += boost::lexical_cast<std::string>(1);
     cellI1 += " ";
     cellI2 += boost::lexical_cast<std::string>(4);
     cellI2 += " ";   
    }
  }



  return;
}




void
writeSinbad::setSinbadTally(Simulation& System,
			       const mainSystem::inputParam& IParam)
{

 const FuncDataBase& Control=System.getDataBase();  
 const std::string preName=IParam.getValue<std::string>("preName");

 size_t NS=Control.EvalVar<size_t>(preName+"NestorSideNSlab");
 size_t cellOffset(3);
 size_t S=Control.EvalVar<size_t>(preName+"ShieldNSlab");
 cellOffset=3+NS+1;
 size_t FPL=Control.EvalVar<size_t>(preName+"FissionPlateNSlab");
 size_t FPX=Control.EvalVar<size_t>(preName+"FissionPlateNXSpace");
 size_t FPZ=Control.EvalVar<size_t>(preName+"FissionPlateNZSpace");
 size_t FPN=FPL+(FPZ-1)*(FPX-1)+3;
 cellOffset=3+NS+S+1+FPN;
 const std::vector<int> CL=System.getCellVector();

 std::stringstream IS2(" ");

 for(size_t i=cellOffset;i<CL.size()+1;i++)
   {
    DT2.push_back(System.getCellMaterial(i));
    DT1.push_back(i);

    // exclude cells of cadmium (always mat 106),
    if(DT2[i-cellOffset]!=106)
      {
       IS2<<" ";
       IS2<< i;
      }
   }
 std::string s2 = IS2.str();
 cellS=s2;

 return; 
}




  /////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////



void
writeSinbad::writeSinbadPhysics(std::ostream& OX) const
  /*!
    Write all the used Weight in standard MCNPX output 
    type. Note that it also has to add the rdum cards
    to the physics
    \param OX :: Output stream
  */
{
  ELog::RegMethod RegA("Simulation","writePhysics");

  OX<<"c --------------- PHYSICS CARDS --------------------------"<<std::endl;

    PhysPtr->getMode().write(OX);
    OX<<"cut:n  j "<<EC<<std::endl;

  OX<<"c --------------- SOURCE CARDS --------------------------"<<std::endl;

    PhysPtr-> getSDefCard().write(OX);

  OX<<"c --------------- PERIPHERAL CARDS --------------------------"<<std::endl;

 // OX<<"c  +++ peripheral cards +++"<<std::endl;


 OX<<"nps "<<DN<<std::endl;
 OX<<"dbcn "<<3469871871985<<std::endl;
 OX<<"prdmp "<<std::endl;
   //<<DN/2<<" "<<DN/2<<std::endl;

 OX<<"print -10 -20 -30 -70 -98 -120 -126 -130 -140 -170 "<<std::endl;



  // Remaining Physics cards
      //  PhysPtr->sinbadPhysicsCards(OX,cellOutOrder);
  OX<<std::endl;  // MCNPX requires a blank line to terminate
  return;
}




void
writeSinbad::writeSinbadTally(std::ostream& OX) const
  /*!
    Writes out the tallies using a nice boost binding
    construction.
    \param OX :: Output stream
   */
{
  OX<<"c ------------------- TALLY CARDS ---------------------------"<<std::endl;
  // The totally insane line below does the following
  // It iterats over the Titems and since they are a map
  // uses the mathSupport:::PSecond
  // _1 refers back to the TItem pair<int,tally*>
  // for_each(TItem.begin(),TItem.end(),
  // 	   boost::bind(&tallySystem::Tally::write,
  // 		       boost::bind(MapSupport::PSecond<TallyTYPE>(),_1),
  // 		       boost::ref(OX)));

  OX<<"e0      1.0000E-10  3i  1.2000E-10  3i  1.5000E-10  8i  2.4000E-10  1i "<<std::endl;
  OX<<"        2.7000E-10  2.8000E-10  5i  4.0000E-10  7i  6.0000E-10  3i     "<<std::endl;
  OX<<"        7.2000E-10  6i  1.0000E-09  3i  1.2000E-09  3i  1.5000E-09  8i "<<std::endl;
  OX<<"        2.4000E-09  1i  2.7000E-09  2.8000E-09  5i  4.0000E-09  7i     "<<std::endl;
  OX<<"        6.0000E-09  3i  7.2000E-09  6i  1.0000E-08  3i  1.2000E-08  3i "<<std::endl;
  OX<<"        1.5000E-08  8i  2.4000E-08  1i  2.7000E-08  2.8000E-08  5i     "<<std::endl;
  OX<<"        4.0000E-08  7i  6.0000E-08  3i  7.2000E-08  6i  1.0000E-07  3i "<<std::endl;
  OX<<"        1.2000E-07  3i  1.5000E-07  8i  2.4000E-07  1i  2.7000E-07     "<<std::endl;
  OX<<"        2.8000E-07  5i  4.0000E-07  7i  6.0000E-07  3i  7.2000E-07  6i "<<std::endl;
  OX<<"        1.0000E-06  3i  1.2000E-06  3i  1.5000E-06  8i  2.4000E-06  1i "<<std::endl;
  OX<<"        2.7000E-06  2.8000E-06  5i  4.0000E-06  7i  6.0000E-06  3i     "<<std::endl;
  OX<<"        7.2000E-06  6i  1.0000E-05  3i  1.2000E-05  3i  1.5000E-05  8i "<<std::endl;
  OX<<"        2.4000E-05  1i  2.7000E-05  2.8000E-05  5i  4.0000E-05  7i     "<<std::endl;
  OX<<"        6.0000E-05  3i  7.2000E-05  6i  1.0000E-04  3i  1.2000E-04  3i "<<std::endl;
  OX<<"        1.5000E-04  8i  2.4000E-04  1i  2.7000E-04  2.8000E-04  5i     "<<std::endl;
  OX<<"        4.0000E-04  7i  6.0000E-04  3i  7.2000E-04  6i  1.0000E-03  3i "<<std::endl;
  OX<<"        1.2000E-03  3i  1.5000E-03  8i  2.4000E-03  1i  2.7000E-03     "<<std::endl;
  OX<<"        2.8000E-03  5i  4.0000E-03  7i  6.0000E-03  3i  7.2000E-03  6i "<<std::endl;
  OX<<"        1.0000E-02  3i  1.2000E-02  3i  1.5000E-02  8i  2.4000E-02  1i "<<std::endl;
  OX<<"        2.7000E-02  2.8000E-02  5i  4.0000E-02  7i  6.0000E-02  3i     "<<std::endl;
  OX<<"        7.2000E-02  6i  1.0000E-01  3i  1.2000E-01  3i  1.5000E-01  8i "<<std::endl;
  OX<<"        2.4000E-01  1i  2.7000E-01  2.8000E-01  5i  4.0000E-01  7i     "<<std::endl;
  OX<<"        6.0000E-01  3i  7.2000E-01  6i  1.0000E-00  189i  20.0         "<<std::endl;


  std::string cellS4(" f4:n  ");
  StrFunc::writeMCNPX(cellS4+cellS,OX);
     OX<<" fq4 e f "<<std::endl;

     // mat 101: S
     // mat 103: Rh
     // mat 104: Mn 
     // mat 105: Au
     // mat 107: In
     // mat 109: Al

     std::stringstream is101(" ");
     std::stringstream is103(" ");
     std::stringstream is104(" ");
     std::stringstream is105(" ");
     std::stringstream is107(" ");
     std::stringstream is109(" ");

     std::string s101(" ");
     std::string s103(" ");     
     std::string s104(" ");     
     std::string s105(" ");
     std::string s107(" ");
     std::string s109(" ");

 for(size_t i=0;i<DT1.size();i++)
   {
    if(DT2[i]==101)
     {
      is101<<" ";
      is101<< DT1[i];
      s101 = is101.str();
     }
    if(DT2[i]==103)
     {
      is103<<" ";
      is103<< DT1[i];
      s103 = is103.str();
     }
    if(DT2[i]==104)
     {
      is104<<" ";
      is104<< DT1[i];
      s104 = is104.str();
     }
    if(DT2[i]==105)
     {
      is105<<" ";
      is105<< DT1[i];
      s105 = is105.str();
     }
    //In
    if(DT2[i]==107)
     {
      is107<<" ";
      is107<< DT1[i];
      s107 = is107.str();
     }
    if(DT2[i]==109)
     {
      is109<<" ";
      is109<< DT1[i];
      s109 = is109.str();
     }
   }

 int LL(0);

  if(s101!=" ")
   {
    StrFunc::writeMCNPX(" f114:n "+s101+" ",OX);
    OX<<" fq114 e f "<<std::endl;
    OX<<" m201  16032.10y 1 "<<std::endl;
    OX<<" fm114:n ( 1 "<<201<<" "<<103<<" )"<<std::endl;
   }

  if(s103!=" ")
   {
    StrFunc::writeMCNPX(" f134:n "+s103+" ",OX);
    OX<<" fq134 e f "<<std::endl;
    OX<<" m203  45103.10y 1 "<<std::endl;
    OX<<" fm134:n ( 1 "<<203<<" "<<11004<<" )"<<std::endl;
   }

  if(s104!=" ")
   {
    StrFunc::writeMCNPX(" f144:n "+s104+" ",OX);
    OX<<" fq144 e f "<<std::endl;
    OX<<" m204  25055.10y 1 "<<std::endl;
    OX<<" fm144:n ( 1 "<<204<<" "<<102<<" )"<<std::endl;
   }

  if(s105!=" ")
   {
    StrFunc::writeMCNPX(" f154:n "+s105+" ",OX);
    OX<<" fq154 e f "<<std::endl;
    OX<<" m205  79197.10y  1 "<<std::endl;
    OX<<" fm154:n ( 1 "<<205<<" "<<102<<" )"<<std::endl;
   }

  if(s107!=" ")
   {
    StrFunc::writeMCNPX(" f174:n "+s107+" ",OX);
    OX<<" fq174 e f "<<std::endl;
    OX<<" m207  49115.10y 1. "<<std::endl;
    OX<<" fm174:n ( 1 "<<207<<" "<<11004<<" )"<<std::endl;
   }

 if(s109!=" ")
  {
   StrFunc::writeMCNPX(" f194:n "+s109+" ",OX);
   OX<<" fq194 e f "<<std::endl;
   OX<<" m209  13027.10y 1. "<<std::endl;
   OX<<" fm194:n ( 1 "<<209<<" "<<107<<" )"<<std::endl;
  }


  return;
}




void
writeSinbad::writeSinbadWeights(std::ostream& OX) const
  /*!
    Write all the used Weight in standard MCNPX output 
    type.
    \param OX :: Output stream
  */

{
 
  WeightSystem::weightManager& WM=
  WeightSystem::weightManager::Instance();  
  OX<<"c --------------- WEIGHT CARDS --------------------------"<<std::endl;
  if(WFlag==0)
  WM.write(OX);
  if(WFlag==1)
  StrFunc::writeMCNPX(cellI1,OX);
  if(WFlag==2)
  StrFunc::writeMCNPX(cellI2,OX);



  return;
}

  


void
writeSinbad::writeSinbadMaterial(std::ostream& OX) const
  /*!
    Write all the used Materials in standard MCNPX output 
    type.
    \param OX :: Output stream
  */

{
  OX<<"c -------------------------------------------------------"<<std::endl;
  ModelSupport::DBMaterial& DB=ModelSupport::DBMaterial::Instance();  
  DB.resetActive();

  OTYPE::const_iterator mp;
  for(mp=OList.begin();mp!=OList.end();mp++)
    DB.setActive(mp->second->getMat());

  DB.writeMCNPX(OX);




  //  OX<<"c ++++++++++++++++++++++ END ++++++++++++++++++++++++++++"<<std::endl;
  return;
}






void
writeSinbad::writeSinbadSurfaces(std::ostream& OX) const
  /*!
    Write all the surfaces in standard MCNPX output 
    type.
    \param OX :: Output stream
  */

{
  OX<<"c --------------- SURFACE CARDS -------------------------"<<std::endl;

  const ModelSupport::surfIndex::STYPE& SurMap =
    ModelSupport::surfIndex::Instance().surMap();

  std::map<int,Geometry::Surface*>::const_iterator mp;
  for(mp=SurMap.begin();mp!=SurMap.end();mp++)
    {
      (mp->second)->write(OX);
    }
  //  OX<<"c ++++++++++++++++++++++ END ++++++++++++++++++++++++++++"<<std::endl;
  OX<<std::endl;
  return;
}




void
writeSinbad::writeSinbadCells(std::ostream& OX) const
  /*!
    Write all the cells in standard MCNPX output 
    type.
    \param OX :: Output stream
  */

{
  //  OX<<"c -------------------------------------------------------"<<std::endl;
  OX<<"c --------------- CELL CARDS --------------------------"<<std::endl;
  //  OX<<"c -------------------------------------------------------"<<std::endl;

   OTYPE::const_iterator mp;
   for(mp=OList.begin();mp!=OList.end();mp++)
     {
       mp->second->write(OX);
     }
   //  OX<<"c ++++++++++++++++++++++ END ++++++++++++++++++++++++++++"<<std::endl;
  OX<<std::endl;  // Empty line manditory for MCNPX
  return;
}


    

void
writeSinbad::SinbadWrite(Simulation& System,const std::string& Fname)
// const
  /*!
    Write out all the system (in MCNPX output format)
    \param Fname :: Output file 
  */
{
  System.prepareWrite();

  std::ofstream OX(Fname.c_str());
  OX<<"Input File:"<<inputFile<<std::endl;
  StrFunc::writeMCNPXcomment("RunCmd:"+cmdLine,OX);

  writeSinbadCells(OX);
  writeSinbadSurfaces(OX);
  writeSinbadMaterial(OX);
  writeSinbadWeights(OX);
  writeSinbadTally(OX);
  writeSinbadPhysics(OX);
  OX.close();
  return;
}


}










