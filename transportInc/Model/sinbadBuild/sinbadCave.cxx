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
#include "FileReport.h"
#include "GTKreport.h"
#include "NameStack.h"
#include "RegMethod.h"
#include "OutputLog.h"
#include "surfRegister.h"
#include "objectRegister.h"
#include "BaseVisit.h"
#include "BaseModVisit.h"
#include "MatrixBase.h"
#include "Matrix.h"
#include "Vec3D.h"
#include "Quaternion.h"
#include "Surface.h"
#include "surfIndex.h"
#include "Quadratic.h"
#include "Rules.h"
#include "varList.h"
#include "Code.h"
#include "FuncDataBase.h"
#include "HeadRule.h"
#include "Object.h"
#include "Qhull.h"
#include "Simulation.h"
#include "ModelSupport.h"
#include "generateSurf.h"
#include "support.h"
#include "stringCombine.h"
#include "LinkUnit.h"
#include "FixedComp.h"
#include "ContainedComp.h"

#include "sinbadCave.h"

namespace sinbadSystem
{

sinbadCave::sinbadCave(const std::string& Key) : 
  attachSystem::ContainedComp(),attachSystem::FixedComp(Key,6),
  caveIndex(ModelSupport::objectRegister::Instance().cell(Key)), cellIndex(caveIndex+1)
  /*!
    Constructor BUT ALL variable are left unpopulated.
    \param Key :: Name for item in search
  */
{}

sinbadCave::sinbadCave(const sinbadCave& A) :
  attachSystem::ContainedComp(A),attachSystem::FixedComp(A),
  caveIndex(A.caveIndex), cellIndex(A.cellIndex),offSetX(A.offSetX),
  offSetY(A.offSetY),offSetZ(A.offSetZ),LLC(A.LLC),LRC(A.LRC),HUC(A.HUC),
  HDC(A.HDC),WIC(A.WIC),WOC(A.WOC),MC(A.MC),TC(A.TC),nSlab(A.nSlab),
  WR(A.WR),lengthL(A.lengthL),lengthR(A.lengthR),heightU(A.heightU),
  heightD(A.heightD),widthI(A.widthI),widthO(A.widthO),mat(A.mat),mainCell(A.mainCell)
  /*!
    Constructor BUT ALL variable are left unpopulated.
  */
{}

sinbadCave&
sinbadCave::operator=(const sinbadCave& A) 
{
  if (&A!=this)
    {
     attachSystem::ContainedComp::operator=(A);
     attachSystem::FixedComp::operator=(A);
     cellIndex=A.cellIndex;
     offSetX=A.offSetX;
     offSetY=A.offSetY;
     offSetZ=A.offSetZ;
     LLC=A.LLC;
     LRC=A.LRC;
     HUC=A.HUC;
     HDC=A.HDC;
     WIC=A.WIC;
     WOC=A.WOC;
     MC=A.MC;
     nSlab=A.nSlab;
     WR=A.WR;
     lengthL=A.lengthL;
     lengthR=A.lengthR;
     heightU=A.heightU;
     heightD=A.heightD;
     widthI=A.widthI;
     widthO=A.widthO;
     mat=A.mat;
     mainCell=A.mainCell;

    }
  return *this;
}

sinbadCave*
sinbadCave::clone() const
  /*!
    Clone funciton
    \return new(this)
  */
{
  return new sinbadCave(*this);
}


sinbadCave::~sinbadCave() 
  /*!
    Destructor
  */
{}


void
sinbadCave::populate(const Simulation& System)
  /*!
    Populate all the variables
    \param System :: Simulation to use
  */
{
  ELog::RegMethod RegA("sinbadCave","populate");

  const FuncDataBase& Control=System.getDataBase();

  offSetX=Control.EvalVar<double>(keyName+"OffSetX");
  offSetY=Control.EvalVar<double>(keyName+"OffSetY");
  offSetZ=Control.EvalVar<double>(keyName+"OffSetZ");

  LLC=Control.EvalVar<double>(keyName+"LengthL");
  LRC=Control.EvalVar<double>(keyName+"LengthR");
     
  HUC=Control.EvalVar<double>(keyName+"HeightU");
  HDC=Control.EvalVar<double>(keyName+"HeightD");
     
  WIC=Control.EvalVar<double>(keyName+"WidthI");
  WOC=Control.EvalVar<double>(keyName+"WidthO");
     
  MC=Control.EvalVar<int>(keyName+"Material");
  TC=Control.EvalVar<double>(keyName+"Temperature");
     
  nSlab=Control.EvalVar<size_t>(keyName+"SlabN");
     
  WR=Control.EvalVar<double>(keyName+"AlWindowRadius");
 
  double LL;
  double LR;
  double HU;  
  double HD;
  double WI;
  double WO;
  int M;
  for(size_t i=0;i<nSlab;i++)
    {
    LL=Control.EvalVar<double>(StrFunc::makeString(keyName+"LengthLSlab",i));
      lengthL.push_back(LL);
    LR=Control.EvalVar<double>(StrFunc::makeString(keyName+"LengthRSlab",i));
      lengthR.push_back(LR);
    HU=Control.EvalVar<double>(StrFunc::makeString(keyName+"HeightUSlab",i));
      heightU.push_back(HU);
    HD=Control.EvalVar<double>(StrFunc::makeString(keyName+"HeightDSlab",i));
      heightD.push_back(HD);
    WI=Control.EvalVar<double>(StrFunc::makeString(keyName+"WidthISlab",i));
      widthI.push_back(WI);
    WO=Control.EvalVar<double>(StrFunc::makeString(keyName+"WidthOSlab",i));
      widthO.push_back(WO);
    M=Control.EvalVar<int>(StrFunc::makeString(keyName+"MaterialSlab",i));
      mat.push_back(M);   
    }


  return;
}


void
sinbadCave::createUnitVector(const attachSystem::FixedComp& FC)
  /*!
    Create the unit vectors
    \param FC :: FixedComponent for origin
  */
{
  ELog::RegMethod RegA("sinbadCave","createUnitVector");

  FixedComp::createUnitVector(FC);

  // setting origin at lower left vertex of the first slab
  Origin+=X*offSetX+Y*offSetY+Z*offSetZ;

 return;
}


void
sinbadCave::createSurfaces()
  /*!
    Create All the surfaces
   */
{
  ELog::RegMethod RegA("sinbadCave","createSurface");
  //  
  ModelSupport::buildPlane(SMap,caveIndex+1,Origin-X*(LLC),X);
  ModelSupport::buildPlane(SMap,caveIndex+2,Origin+X*(LRC),X);
  ModelSupport::buildPlane(SMap,caveIndex+3,Origin-Y*(WIC),Y);
  ModelSupport::buildPlane(SMap,caveIndex+4,Origin+Y*(WOC),Y);
  ModelSupport::buildPlane(SMap,caveIndex+5,Origin-Z*(HDC),Z);
  ModelSupport::buildPlane(SMap,caveIndex+6,Origin+Z*(HUC),Z);
  
  double cumLL(LLC);
  double cumLR(LRC);
  double cumWI(WIC);
  double cumWO(WOC);
  double cumHU(HUC);
  double cumHD(HDC);
  LM=0;
  int SI1(caveIndex+1000);
  for(size_t i=0;i<nSlab;i++)
   {
    cumLL+=lengthL[i];
    if(LM<cumLL)LM=cumLL; 
    cumLR+=lengthR[i];
    cumWI+=widthI[i];
    cumWO+=widthO[i];
    cumHU+=heightU[i];
    cumHD+=heightD[i];
    ModelSupport::buildPlane(SMap,SI1+1,Origin-X*cumLL,X);
    ModelSupport::buildPlane(SMap,SI1+2,Origin+X*cumLR,X);
    ModelSupport::buildPlane(SMap,SI1+3,Origin-Y*cumWI,Y);
    ModelSupport::buildPlane(SMap,SI1+4,Origin+Y*cumWO,Y);
    ModelSupport::buildPlane(SMap,SI1+5,Origin-Z*cumHD,Z);
    ModelSupport::buildPlane(SMap,SI1+6,Origin+Z*cumHU,Z);
    SI1+=10;
   }
    ModelSupport::buildCylinder(SMap,caveIndex+7,Origin,Y,WR);


   return;
}


void
sinbadCave::createObjects(Simulation& System)
  /*!
    Create all the objects
    \param System :: Simulation to create objects in
  */
{
  ELog::RegMethod RegA("sinbadCave","createObjects");
  std::string Out;
  std::string OutTot1;
  std::string OutTot2;
  int SI1(caveIndex+1000);
  int SI2(caveIndex+1000);

  Out=ModelSupport::getComposite(SMap,caveIndex,"1 -2 3 -4  5 -6");
  System.addCell(MonteCarlo::Qhull(cellIndex++,MC,TC,Out));
  mainCell=cellIndex-1; 
 

  for(size_t i=0;i<nSlab;i++)
   {
	// insert al window in first layer
     if(i==0)
      {
       Out=ModelSupport::getComposite(SMap,caveIndex,SI1,
                                      " 3M -4M -7  ( -1 : 2 : -3 : 4 : -5 : 6 ) ");
       System.addCell(MonteCarlo::Qhull(cellIndex++,2,TC,Out));
       Out=ModelSupport::getComposite(SMap,caveIndex,SI1,
                                     "  1M -2M 3M -4M 5M -6M 7 ( -1 : 2 : -3 : 4 : -5 : 6 ) ");
       System.addCell(MonteCarlo::Qhull(cellIndex++,mat[i],TC,Out));
       //    OutTot1=ModelSupport::getComposite(SMap,caveIndex,SI1," 1M -2M 3M -4M 5M -6M ");
	  // std::cout<<" O " <<Out<<std::endl;        
       }
     else
      {
       if(lengthL[i]>=0 && lengthL[i-1]>=0 && i<nSlab-1) 
         {
          Out=ModelSupport::getComposite(SMap,caveIndex,SI1,
                          " 11M -12M 13M -14M 15M -16M ( -1M : 2M : -3M : 4M : -5M : 6M ) ");
	  // std::cout<<" O1 " <<Out<<std::endl;  
         // OutTot1=ModelSupport::getComposite(SMap,caveIndex,SI1,
         //                                 " ( 11M -12M 13M -14M 15M -16M ) ");
         OutTot1=ModelSupport::getComposite(SMap,caveIndex,SI1,
                                         " ( -11M : 12M : -13M : 14M : -15M : 16M ) ");

          SI2=SI1;
          }
       else if(i==nSlab-1)
      {
        Out=ModelSupport::getComposite(SMap,caveIndex,SI1,
        " 11M -12M 13M -14M 15M -16M ");
        Out+=OutTot1+OutTot2;
	  // std::cout<<" O2 " <<Out<<std::endl;  
      }

	    // per tener conto delle due sezioni di nestor
         else
          {
           Out=ModelSupport::getComposite(SMap,caveIndex,SI1,
                                       "11M -12M 13M -14M 15M -16M -3M");
           // OutTot2=ModelSupport::getComposite(SMap,SI2,SI1,
           //                               ": ( 11M -12M 13M -13 15M -16M ) ");
          OutTot2=ModelSupport::getComposite(SMap,SI2,SI1,
                                         " ( -11M : 12M : -13M : 13 : -15M : 16M ) ");



           }
       System.addCell(MonteCarlo::Qhull(cellIndex++,mat[i],TC,Out));
     SI1+=10; 

        }

   }

  Out=ModelSupport::getComposite(SMap,caveIndex,SI1-10,
        " 11M -12M 13M -14M 15M -16M ");
   addOuterSurf(Out);

   // addOuterSurf(OutTot1+OutTot2);

    // std::cout<<" outt "<<OutTot1+OutTot2<<std::endl;

  return;
}



// void
// sinbadCave::addToInsertChain(attachSystem::ContainedComp& CC, const int n) const
//   /*!
//     Adds this object to the containedComp to be inserted.
//     \param CC :: ContainedComp object to add to this
//   */
// {

//   return;
// }




void
sinbadCave::createAll(Simulation& System,
			const attachSystem::FixedComp& FC)
  /*!
    Generic function to create everything
    \param System :: Simulation item
    \param FC :: Fixed Component for origin
  */
{
  ELog::RegMethod RegA("sinbadCave","createAll");

  populate(System);
  createUnitVector(FC);
  createSurfaces();
  createObjects(System);
  insertObjects(System);

  return;
}
  
} 
