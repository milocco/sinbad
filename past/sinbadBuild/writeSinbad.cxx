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
#include "RemoveCell.h"
#include "WForm.h"
#include "weightManager.h"
#include "ModeCard.h"
#include "PhysCard.h"
#include "LSwitchCard.h"
#include "PhysImp.h"
#include "KGroup.h"
#include "SrcData.h"
#include "SrcItem.h"
#include "Source.h"
#include "KCode.h"
#include "ObjSurfMap.h"
#include "PhysicsCards.h"
#include "ReadFunctions.h"
#include "SimTrack.h"
#include "Simulation.h"

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
  IParam.regDefItemList<std::string>("imp","importance",10,RItems);
  IParam.regDefItem<int>("n","nps",1,1000000);
  IParam.regDefItemList<std::string>("r","renum",10,RItems);
  IParam.regDefItem<std::string>("preName","preName",1,"33");
  std::vector<std::string> DItems(10,"");
  IParam.regDefItemList<std::string>("axDet","detector type (axial scan)",10,DItems);
  IParam.regDefItemList<std::string>("vertDet","detector type (vertical scan)",10,DItems);
  IParam.regDefItem<std::string>("xs","nuclear data library",1,".");

  IParam.regDefItem<std::string>("sdefType","sdefType",1,"");
  IParam.regFlag("sdefVoid","sdefVoid");
  IParam.regItem<std::string>("SF","sdefFile");


  IParam.setDesc("n","Number of starting particles (default 1.e6).\n");
  IParam.setDesc("r","Renumber cells and surfaces (recommended).\n");
  IParam.setDesc("preName","Experiment number from SINBAD compilation.\n                    Choose between: \n                     34 == Winfrith Iron Benchmark Experiment (ASPIS), \n                     35 == Winfrith Graphite Benchmark Experiment (ASPIS), \n                     36 == Winfrith Graphite Benchmark Experiment (ASPIS), \n                     37 == Winfrith Water Benchmark Experiment (ASPIS), \n                     41 == JANUS Phase I (Neutron Transport Through Mild and Stainless Steel), \n                     42 == JANUS Phase VIII (Neutron Transport Through Sodium and Mild Steel), \n                     44 == NESDIP-2 Benchmark Experiment (ASPIS), \n                     45 == 18/20 NESDIP-3 Benchmark Experiment (ASPIS), \n                     49 == ASPIS Neutron/Gamma-Ray Transport Through Water/Steel Arrays, \n                     75 ==Winfrith Water/Iron Benchmark Experiment (PCA Replica). \n ");
  IParam.setDesc("xs","append standard extension in material cards.\n                    Possible choices are: \n                     ENDF/B-VII.1 == .80c, \n                     ENDF/B-VII.0 == .70c, \n                     JEFF3.2 == .31c, \n                     TENDL == . \n                     user extension == .XXc, \n No check on the availability of the elements in the xsdir file  \n");

  IParam.setDesc("axDet","Select detector type (for axial scan only).\n                    Possible choices are: \n                     S == Solphur (cast, except for the first one, the monitor, which is pressed), \n                     Rh == Rhodium, \n                     Mn == Manganese, \n                     Au == Gold, \n                     Tld == Thermoluminiscent detector, \n                     IC == Ionisation chamber. \n Combinations of them are possible just adding items (e.g. --detType Rh S Au). \n Please ascertain that measurements were performed with selected detector.\n");

  IParam.setDesc("vertDet","Define detectors used in vertical scans. \n                    Possibilities are: \n                     Mn == Manganese,\n                     Tld == Thermoluminiscent detector. \n");

  return;
}


}  // NAMESPACE mainSystem









namespace sinbadSystem
{
  writeSinbad::writeSinbad(const std::string& Key): Simulation()
  // : 
    //cellS("")
  {}

  writeSinbad::writeSinbad(const writeSinbad& A):Simulation(A),cellS(A.cellS),
  DT1(A.DT1),DT2(A.DT2)
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
      cellS=A.cellS;
      DT1=A.DT1;
      DT2=A.DT2;

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
    //  writeVariables(OX);
    // writeSinbadCells(OX);
  writeCells(OX);
  writeSurfaces(OX);
  writeMaterial(OX);
  writeSinbadWeights(OX);
  writeSinbadTally(OX);
  writeSinbadPhysics(OX);
  OX.close();
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
  OX<<"c ++++++++++++++++++++++ END ++++++++++++++++++++++++++++"<<std::endl;
  OX<<std::endl;  // Empty line manditory for MCNPX
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
  OX<<"c -------------------------------------------------------"<<std::endl;
  OX<<"c --------------- WEIGHT CARDS --------------------------"<<std::endl;
  OX<<"c -------------------------------------------------------"<<std::endl;
  WM.write(OX);
  OX<<"c ++++++++++++++++++++++ END ++++++++++++++++++++++++++++"<<std::endl;
  return;
}





void
writeSinbad::setSinbadWeights(Simulation& System,
		 const mainSystem::inputParam& IParam)
  /*!
    Set individual weights based on temperature/cell
    \param System :: Simulation
    \param IParam :: input stream
   */
{
  ELog::RegMethod RegA("BasicWWE","simulationWeights");

  System.populateCells();
  System.createObjSurfMap();

 
  const std::string WType=IParam.getValue<std::string>("axDet",0);

  std::vector<double> Eval(6);
  // Eval[0]=1.e-11;
  // Eval[1]=1.e-9;
  // Eval[2]=1.e-6;
  // Eval[3]=1.e-3;
  // Eval[4]=1.0;
  // Eval[5]=31.0;

  Eval[0]=1.e-9;
  Eval[1]=1.e-7;
  Eval[2]=1.e-5;
  Eval[3]=1.e-2;
  Eval[4]=1.e+1;
  Eval[5]=31.0;

 std::vector<double> WT(6);

  if (WType=="Mn")
    {
  // no action
 WT[0]=0.5;WT[1]=0.5;WT[2]=0.5;
 WT[3]=0.5;WT[4]= 0.5;WT[5]= 0.5;
    }
  else if (WType=="S")
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
  else
    throw ColErr::InContainerError<std::string>(WType,"Unknown weight type");

  // WeightSystem::weightManager& WM=
  // WeightSystem::weightManager::Instance();  

 std::set<std::string> EmptySet;
 // setWeights(System,Eval,WT,EmptySet);

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
  WF-> setWeights(WT);
 
  const FuncDataBase& Control=System.getDataBase();  
  const std::string preName=IParam.getValue<std::string>("preName");
  size_t cellOffset(3);

 size_t S=Control.EvalVar<size_t>(preName+"ShieldNSlab");
 for(size_t i=0;i<S;i+=4)
  {   
   int SF=pow(4,i/4-4);
   int RF=pow(2,i/4); 
   if(i>16) RF=pow(2,i/4)/pow(4,i/4-4);
   WF->rescale(cellOffset+i,cellOffset+i+3,RF);   
  }

  cellOffset=3+S+1;


  size_t NS=Control.EvalVar<size_t>(preName+"NestorSideNSlab");
  for(size_t i=0;i<NS-1;i+=2)
   {   
    double SF=(NS/2+1);
    double RF=i/SF/2; 
    if(i==0) RF=1/SF/2;
    WF->rescale(cellOffset+i,cellOffset+i+1,RF);  
    //  ELog::EM<<" RRRFF "<<RF<<"  "<<SF<<" "<<cellOffset+i<<ELog::endDiag; 
   }

 size_t FPL=Control.EvalVar<size_t>(preName+"FissionPlateNSlab");
 size_t FPX=Control.EvalVar<size_t>(preName+"FissionPlateNXSpace");
 size_t FPZ=Control.EvalVar<size_t>(preName+"FissionPlateNZSpace");
 size_t FPN=FPL+(FPZ-1)*(FPX-1)+3;
 size_t D=Control.EvalVar<size_t>(preName+"DetNY");
 std::string DT=IParam.getValue<std::string>("axDet",0);
 cellOffset=3+NS+S+1+FPN;

 for(size_t i=0;i<9;i+=2)
   {   
    int RF=pow(2,i/2); 
    WF->rescale(cellOffset+i,cellOffset+i+1,RF);   
   }

   cellOffset=3+NS+S+1+FPN+9;
   const std::vector<int> CL=getCellVector();
    int RF=pow(2,4); 

   WF->rescale(cellOffset,CL.size(),RF);   

  //  const ModelSupport::objectRegister& OR=
  // 	  ModelSupport::objectRegister::Instance();
  //    int cellOff1=OR.getCell("49FissionPlate");
  //    int cellNum1=OR.getRange("49FissionPlate");
  //    int cellOff2=OR.getCell("49Shield");
  //    int cellNum2=OR.getRange("49Shield");

  //    int cellOff3=OR.getCell("49NestorSide");
  //    int cellNum3=OR.getRange("49NestorSide");
  // OTYPE::const_iterator vc;  
  // for(vc=OList.begin();vc!=OList.end();vc++)
  //   {
  //     const int cNum=vc->second->getName();
  //     //      const std::vector<const Geometry::Surface*>& cPt=vc->second->getSurList();
  // const int cMat=vc->second->getMat();
  // const int cImp=vc->second->getImp();
  //     ELog::EM<<" NNNNN "<<cellOff1<<"  "<<cellOff2<<"  "<<cellOff3<<"  "<<cMat<<"  "<<cImp<<" "<<cNum<<ELog::endBasic;


  //   }



  return;
}







  // std::string
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
    IS2<<" ";
    IS2<< i;
    DT1.push_back(i);
    DT2.push_back(System.getCellMaterial(i));
   }
 std::string s2 = IS2.str();
 cellS=s2;

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
  OX<<"c -------------------------------------------------------------------"<<std::endl;
  OX<<"c ------------------- TALLY CARDSXXX ---------------------------"<<std::endl;
  OX<<"c -----------------------------------------------------------"<<std::endl;
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

  std::string cellS1("");
  std::string cellS2("");
  std::string cellS3("");
 
 if(cellS.size()<65)
   OX<<" f4:n ("<<cellS<<")"<<std::endl;
 else if(cellS.size()>=65&&cellS.size()<130)
   {
   for(size_t i1=0;i1<65;i1++)
     cellS1+=cellS[i1];
   OX<<" f4:n ("<<cellS1<<std::endl;
 
   for(size_t i2=60;i2<cellS.size();i2++)
     cellS2+=cellS[i2];
   OX<<"       "<<cellS2<<" )"<<std::endl;
   }
 else 
   {
   for(size_t i1=0;i1<65;i1++)
     cellS1+=cellS[i1];
   OX<<" f4:n ("<<cellS1<<std::endl;
 
   for(size_t i2=60;i2<124;i2++)
     cellS2+=cellS[i2];
   OX<<"       "<<cellS2<<std::endl;

   for(size_t i3=124;i3<cellS.size();i3++)
     cellS3+=cellS[i3];
   OX<<"       "<<cellS3<<" )"<<std::endl;
  ELog::EM<<" lots of tally 4 cells. Check if all are present! Only 3 f4 lines allowed"<<ELog::endDiag; 

   }

 ELog::EM<<" MTTT "<<DT1.size()<<ELog::endDiag; 

     std::stringstream is101(" ");
     std::stringstream is103(" ");
     std::stringstream is104(" ");
     std::stringstream is105(" ");
     std::stringstream is107(" ");

     std::string s101(" ");
     std::string s101a(" ");
     std::string s101b(" ");
     std::string s103(" ");     
     std::string s103a(" ");     
     std::string s103b(" ");     
     std::string s104(" ");     
     std::string s104a(" ");     
     std::string s104b(" ");     
     std::string s105(" ");
     std::string s105a(" ");
     std::string s105b(" ");
     std::string s107(" ");

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
    if(DT2[i]==107)
     {
      is107<<" ";
      is107<< DT1[i];
      s107 = is107.str();
     }
   }

 int LL(0);

  if(s101!=" ")
   {
    LL=s101.size(); 
    if(LL<65)
      OX<<" f104:n ("<<s101<<" )"<<std::endl;
    else
      {
	for(size_t i=0;i<65;i++)
	  s101a+=s101[i];
	for(size_t i=65;i<LL;i++)
	  s101b+=s101[i];
      OX<<"f104:n ("<<s101a<<std::endl;
      OX<<"          "<<s101b<<" )"<<std::endl;
      }
    OX<<" m201  16032. 1 "<<std::endl;
    OX<<" fm104:n ( 1 "<<201<<" "<<103<<" )"<<std::endl;
   }

  if(s103!=" ")
   {
    LL=s103.size(); 
    if(LL<65)
      OX<<" f114:n ("<<s103<<" )"<<std::endl;
    else
      {
	for(size_t i=0;i<65;i++)
	  s103a+=s103[i];
	for(size_t i=65;i<LL;i++)
	  s103b+=s103[i];
      OX<<"f114:n ("<<s103a<<std::endl;
      OX<<"          "<<s103b<<" )"<<std::endl;
      }
    OX<<" m203  45103. 1 "<<std::endl;
    OX<<" fm114:n ( 1 "<<203<<" "<<10004<<" )"<<std::endl;
   }

  if(s104!=" ")
   {
    LL=s104.size(); 
    if(LL<65)
      OX<<" f124:n ("<<s104<<" )"<<std::endl;
    else
      {
	for(size_t i=0;i<65;i++)
	  s104a+=s104[i];
	for(size_t i=65;i<LL;i++)
	  s104b+=s104[i];
      OX<<"f124:n ("<<s104a<<std::endl;
      OX<<"          "<<s104b<<" )"<<std::endl;
      }
    OX<<" m204  25055. 1 "<<std::endl;
    OX<<" fm124:n ( 1 "<<204<<" "<<102<<" )"<<std::endl;
   }

  if(s105!=" ")
   {
    LL=s105.size(); 
    if(LL<65)
      OX<<" f134:n ("<<s105<<" )"<<std::endl;
    else
      {
	for(size_t i=0;i<65;i++)
	  s105a+=s105[i];
	for(size_t i=65;i<LL;i++)
	  s105b+=s105[i];
      OX<<"f134:n ("<<s105a<<std::endl;
      OX<<"          "<<s105b<<" )"<<std::endl;
      }
    OX<<" m205  79197. 1 "<<std::endl;
    OX<<" fm134:n ( 1 "<<105<<" "<<102<<" )"<<std::endl;
   }

  if(s107!=" ")
   {
    OX<<" f144:n ("<<s107<<" )"<<std::endl;
    //  OX<<" fm144:n ( 1 "<<107<<" "<<"???)"<<std::endl;
   }



 //   const ModelSupport::objectRegister& OR=
 //	  ModelSupport::objectRegister::Instance();
  //    int cellOff1=OR.getCell("49FissionPlate");
  //    int cellNum1=OR.getRange("49FissionPlate");
  //    int cellOff2=OR.getCell("49Shield");
  //    int cellNum2=OR.getRange("49Shield");

  //    int cellOff3=OR.getCell("49NestorSide");
  //    int cellNum3=OR.getRange("49NestorSide");
  // OTYPE::const_iterator vc;  
  // for(vc=OList.begin();vc!=OList.end();vc++)
  //   {
  //     const int cNum=vc->second->getName();
  //     //      const std::vector<const Geometry::Surface*>& cPt=vc->second->getSurList();
  // const int cMat=vc->second->getMat();
  // const int cImp=vc->second->getImp();
  //     ELog::EM<<" NNNNN "<<cellOff1<<"  "<<cellOff2<<"  "<<cellOff3<<"  "<<cMat<<"  "<<cImp<<" "<<cNum<<ELog::endBasic;



 // OX<<" fm4:n ( 1 "<<201<<" "<<103<<")"<<std::endl;



  return;
}






} //end namespace sinbad






namespace physicsSystem
{


void 
PhysicsCards::sinbadPhysicsCards(std::ostream& OX,
		    const std::vector<int>& cellOutOrder) const 
  /*!
    Write out each of the cards
    \param OX :: Output stream
    \param cellOutOrder :: Cell List
    \todo Check that histp does not need a line cut.
  */
{
  ELog::RegMethod RegA("PhyiscsCards","write");
  mode.write(OX);


 OX<<"c  +++ source cards +++"<<std::endl;

 sdefCard.write(OX);
 // sourceCard.write(OX);

 OX<<"c  +++ peripheral cards +++"<<std::endl;

  OX<<"nps "<<nps<<std::endl;
  OX<<"dbcn "<<rndSeed<<std::endl;

  // Volume.write(OX,cellOutOrder);
  
  // for_each(ImpCards.begin(),ImpCards.end(),
  // 	   boost::bind<void>(&PhysImp::write,_1,boost::ref(OX),
  // 			     boost::ref(cellOutOrder)));

  // for_each(PhysCards.begin(),PhysCards.end(),
  // 	   boost::bind<void>(&PhysCard::write,_1,boost::ref(OX)));
  
  // for_each(Basic.begin(),Basic.end(),
  // 	   boost::bind2nd(&StrFunc::writeMCNPX,OX));


  std::string prdmp(" j j j j j ");
   StrFunc::writeMCNPX("prdmp "+prdmp,OX);
  
  if (!printNum.empty())
    {
      std::ostringstream cx;
      cx<<"print ";
      copy(printNum.begin(),printNum.end(),
	   std::ostream_iterator<int>(cx," "));
      StrFunc::writeMCNPX(cx.str(),OX);
    }


  


  return;
}


} // NAMESPACE PhysicsCards	
      


namespace WeightSystem
{ 

// void
// sinbadWeights(Simulation& System,
// 		 const mainSystem::inputParam& IParam)
//   /*!
//     Set individual weights based on temperature/cell
//     \param System :: Simulation
//     \param IParam :: input stream
//    */
// {
//   ELog::RegMethod RegA("BasicWWE","simulationWeights");

//   System.populateCells();
//   System.createObjSurfMap();

//   // WEIGHTS:
//   if (IParam.flag("weight") || IParam.flag("tallyWeight"))
//     System.calcAllVertex();

//   //  const std::string WType=IParam.getValue<std::string>("weightType");
//   const std::string WType=IParam.getValue<std::string>("detType",0);
//   //  setWeights(System,WType);

//   // ELog::RegMethod RegA("SBasicWWE","setSinbadWeights");

//   std::vector<double> Eval(6);
//   // Eval[0]=1.e-11;
//   // Eval[1]=1.e-9;
//   // Eval[2]=1.e-6;
//   // Eval[3]=1.e-3;
//   // Eval[4]=1.0;
//   // Eval[5]=31.0;

//   Eval[0]=1.e-9;
//   Eval[1]=1.e-7;
//   Eval[2]=1.e-5;
//   Eval[3]=1.e-2;
//   Eval[4]=1.e+1;
//   Eval[5]=31.0;

//  std::vector<double> WT(6);

//   if (WType=="Mn")
//     {
//   // no action
//  WT[0]=0.5;WT[1]=0.5;WT[2]=0.5;
//  WT[3]=0.5;WT[4]= 0.5;WT[5]= 0.5;
//       //    setWeightsBasic(System);
//     }
//   else if (WType=="S")
//     {
//   // S 
//   WT[0]=16;WT[1]=4;WT[2]=1;
//   WT[3]=0.25;WT[4]= 0.05;WT[5]= 0.05;
//   //  setWeightsHighE(System);

//     }
//   else if (WType=="mid")
//     {
//   // Rh (and In good???)
//    WT[0]=16;WT[1]=4;WT[2]=2;
//    WT[3]=0.05;WT[4]= 0.05;WT[5]= 0.25;

//       //    setWeightsMidE(System);
//     }
//   else if (WType=="help")
//     {
//       ELog::EM<<"Basic weight energy types == \n"
// 	"High -- High energy\n"
// 	"Mid -- Mid/old point energy\n"
// 	"Basic -- Cold spectrum energy"<<ELog::endBasic;
//       throw ColErr::ExitAbort("End Help");
//     }
//   else
//     throw ColErr::InContainerError<std::string>(WType,"Unknown weight type");

//   // spectra
//   // WT[0]=8.0;WT[1]=4.0;WT[2]=2.0;
//   // WT[3]=0.5;WT[4]= 0.5;WT[5]= 1.0;

//  std::set<std::string> EmptySet;
// //  setWeights(System,Eval,WT,EmptySet);

//   WeightSystem::weightManager& WM=
//     WeightSystem::weightManager::Instance();  

//   WM.addParticle<WeightSystem::WCells>('n');
//   WeightSystem::WCells* WF=
//     dynamic_cast<WeightSystem::WCells*>(WM.getParticle('n'));
//   if (!WF)
//     throw ColErr::InContainerError<std::string>("n","WCell - WM");

//   WF->setEnergy(Eval);
//   System.populateWCells();
//  WF->balanceScale(WT);

 
//  WF-> setWeights(WT);

//   const FuncDataBase& Control=System.getDataBase();  
//   const std::string preName=IParam.getValue<std::string>("preName");

//  size_t NS=Control.EvalVar<size_t>(preName+"NestorSideNSlab");
//  size_t cellOffset(3);
// // double RF(0.0);
//  for(size_t i=0;i<NS-1;i+=2)
//    {   
//     double SF=(NS/2+1);
//     double RF=i/SF; 
//     if(i==0) RF=1/SF;
//     WF->rescale(cellOffset+i,cellOffset+i+1,RF);   
//    }

//  size_t S=Control.EvalVar<size_t>(preName+"ShieldNSlab");
//  cellOffset=3+NS+1;
//  for(size_t i=0;i<S;i+=4)
//   {   
//    int SF=pow(4,i/4-4);
//    int RF=pow(2,i/4); 
//    if(i>16) RF=pow(2,i/4)/pow(4,i/4-4);

//    WF->rescale(cellOffset+i,cellOffset+i+3,RF);   
//   }

//  size_t FPL=Control.EvalVar<size_t>(preName+"FissionPlateNSlab");
//  size_t FPX=Control.EvalVar<size_t>(preName+"FissionPlateNXSpace");
//  size_t FPZ=Control.EvalVar<size_t>(preName+"FissionPlateNZSpace");


//  size_t FPN=FPL+(FPZ-1)*(FPX-1)+3;

//  size_t D=Control.EvalVar<size_t>(preName+"DetNY");
//   std::string DT=IParam.getValue<std::string>("detType",0);

//  cellOffset=3+NS+S+1+FPN;

//  for(size_t i=0;i<9;i+=2)
//    {   
//    int RF=pow(2,i/2); 

//    WF->rescale(cellOffset+i,cellOffset+i+1,RF);   
// ELog::EM<<"i "<<i<<" cellOffset+i "<<cellOffset+i<<" RF "<<RF<<ELog::endDiag;

//    }


//   const Simulation::OTYPE& Cells=System.getCells();
//   Simulation::OTYPE::const_iterator oc;
//   for(oc=Cells.begin();oc!=Cells.end();oc++)
//     {
//       if(!oc->second->getImp())
//   	WF->maskCell(oc->first);      
//     }
//   WF->maskCell(1);


//   return;
// }


}



namespace SimProcess
{


}



   
namespace ModelSupport
{
 void 
setSinbadPhysics(Simulation& System,
		  const mainSystem::inputParam& IParam)
{

 System.getPC().setMode("n");
  // System.getPC().setNPS(IParam.getValue<int>("nps"));
  // System.getPC().setRND(IParam.getValue<long int>("random"));	

  System.getPC().setNPS(12.e+6);
  System.getPC().setRND(3469871871985);	
  physicsSystem::PhysCard& cpi=System.getPC().addPhysCard("cut","/");
  cpi.setValues("j 0.0");
 System.processCellsImp();
   System.getPC().setCells("imp",1,0);   
 System.getPC().setEnergyCut(98.0);

 System.getPC().setPrintNum("-30 ");



  return; 
}



} //endNamespace ModelSupport



namespace StrFunc
{


void
writeMCNPXsinbad(const std::string& Line,std::ostream& OX)
/*!
  Write out the line in the limited form for MCNPX
  ie initial line from 0::72 after that 8 to 72
  (split on a space or comma)
  \param Line :: full MCNPX line
  \param OX :: ostream to write to
*/
{
  writeControl(Line,OX,72,8);
  return;
}

}



//////////////////////////////////////////////////////


// void
// Simulation::writeSinbadWeights(std::ostream& OX) const
//   /*!
//     Write all the used Weight in standard MCNPX output 
//     type.
//     \param OX :: Output stream
//   */

// {
//   WeightSystem::weightManager& WM=
//     WeightSystem::weightManager::Instance();  
//   OX<<"c -------------------------------------------------------"<<std::endl;
//   OX<<"c --------------- WEIGHT CARDS --------------------------"<<std::endl;
//   OX<<"c -------------------------------------------------------"<<std::endl;
//   WM.write(OX);
//   OX<<"c ++++++++++++++++++++++ END ++++++++++++++++++++++++++++"<<std::endl;
//   return;
// }




void
Simulation::writeSinbadPhysics(std::ostream& OX) const
  /*!
    Write all the used Weight in standard MCNPX output 
    type. Note that it also has to add the rdum cards
    to the physics
    \param OX :: Output stream
  */
{
  ELog::RegMethod RegA("Simulation","writePhysics");

  OX<<"c -------------------------------------------------------"<<std::endl;
  OX<<"c --------------- PHYSICS CARDS --------------------------"<<std::endl;
  OX<<"c -------------------------------------------------------"<<std::endl;


  // physicsSystem::PhysicsCards& PC=System.getPC();  
  // PC.setNPS(IParam.getValue<int>("nps"));
  // PC.setRND(IParam.getValue<long int>("random"));	
  // PC.setVoidCard(IParam.flag("void"));

  // OX<<"dbcnCCC "<<std::endl;
  // OX<<"npsCCC "<<std::endl;

  // if (mcnpType!=1)
  //   {
      // Processing for point tallies
      std::map<int,tallySystem::Tally*>::const_iterator mc;
      std::vector<int> Idum;
      std::vector<Geometry::Vec3D> Rdum;


  // Remaining Physics cards
     PhysPtr->sinbadPhysicsCards(OX,cellOutOrder);
  OX<<"c ++++++++++++++++++++++ END ++++++++++++++++++++++++++++"<<std::endl;
  OX<<std::endl;  // MCNPX requires a blank line to terminate
  return;
}





