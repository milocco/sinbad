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
#include "MaterialSupport.h"
#include "generateSurf.h"
#include "support.h"
#include "stringCombine.h"
#include "LinkUnit.h"
#include "FixedComp.h"
#include "ContainedComp.h"
#include "inputParam.h"
#include "LayerPlate.h"

namespace sinbadSystem
{

LayerPlate::LayerPlate(const std::string& Key) : 
  attachSystem::ContainedComp(),attachSystem::FixedComp(Key,6),
  slabIndex(ModelSupport::objectRegister::Instance().cell(Key)), 
  cellIndex(slabIndex+1),frontShared(1)
  /*!
    Constructor BUT ALL variable are left unpopulated.
    \param Key :: Name for item in search
  */
{}

LayerPlate::LayerPlate(const LayerPlate& A) : 
  attachSystem::ContainedComp(A),attachSystem::FixedComp(A),
  slabIndex(A.slabIndex),cellIndex(A.cellIndex),
  xStep(A.xStep),yStep(A.yStep),zStep(A.zStep),
  xyAngle(A.xyAngle),zAngle(A.zAngle),frontShared(A.frontShared),
  width(A.width),height(A.height),nSlab(A.nSlab),
  thick(A.thick),mat(A.mat),matTemp(A.matTemp),
  radiusWindow(A.radiusWindow),matWindow(A.matWindow),pName(A.pName),
  cutX(A.cutX),cutZ(A.cutZ),cutMat(A.cutMat),cGap(A.cGap),thickSlot(A.thickSlot),slotL(A.slotL),slotT(A.slotT),slotA(A.slotA),slotN(A.slotN),slotX(A.slotX),slotY(A.slotY),slotZ(A.slotZ),slotM(A.slotM)
  
  /*!
    Copy constructor
    \param A :: LayerPlate to copy
  */
{}

LayerPlate&
LayerPlate::operator=(const LayerPlate& A)
  /*!
    Assignment operator
    \param A :: LayerPlate to copy
    \return *this
  */
{
  if (this!=&A)
    {
      attachSystem::ContainedComp::operator=(A);
      attachSystem::FixedComp::operator=(A);
      cellIndex=A.cellIndex;
      xStep=A.xStep;
      yStep=A.yStep;
      zStep=A.zStep;
      xyAngle=A.xyAngle;
      zAngle=A.zAngle;
      frontShared=A.frontShared;
      width=A.width;
      height=A.height;
      nSlab=A.nSlab;
      thick=A.thick;
      mat=A.mat;
      matTemp=A.matTemp;
      radiusWindow=A.radiusWindow;
      matWindow=A.matWindow;
      pName=A.pName;
      cutX=A.cutX;
      cutZ=A.cutZ;
      cutMat=A.cutMat;
      cGap=A.cGap;
      thickSlot=A.thickSlot;
      slotL=A.slotL;
      slotT=A.slotT;
      slotA=A.slotA;
      slotN=A.slotN;
      slotX=A.slotX;
      slotY=A.slotY;
      slotZ=A.slotZ;
      slotM=A.slotM;

    }
  return *this;
}


LayerPlate*
LayerPlate::clone() const
  /*!
    Virtual copy constructor
    \return new(this)
  */
{
  return new LayerPlate(*this);
}

LayerPlate::~LayerPlate() 
  /*!
    Destructor
  */
{}

int
LayerPlate::getCellIndex(const size_t lNumber) const
  /*!
    Determine the cell index based on lNumber
    \param lNumber :: Layer number
    \return cellNumber
  */
{
  ELog::RegMethod RegA("LayerPlate","getCellIndex");

  if (lNumber >= nSlab)
    throw ColErr::IndexError<size_t>
      (lNumber,nSlab,"lNumber");
  //  ELog::EM<<"INDEX "<<slabIndex+1+static_cast<int>(lNumber)<<ELog::endDiag;  
  return slabIndex+1+static_cast<int>(lNumber);
}

std::string
LayerPlate::getFrontSurface(const size_t layerIndex,
			const attachSystem::FixedComp& FC,
			const long int sideIndex) const
  /*!
    Get the front/back surfaces based on the link object 
    \param layerIndex :: Layer Number
    \param FC :: Link object
    \param sideIndex :: Connection point [signed for direction/ zero = centre]
    \return surface string 
   */
{
  ELog::RegMethod RegA("LayerPlate","getFrontSurface");

  if (layerIndex>0 || !sideIndex || !frontShared)
    {
      const int SI(slabIndex+static_cast<int>(layerIndex)*10);
      return ModelSupport::getComposite(SMap,SI," 1 ");
    }
  // FC Object
  if (sideIndex>0) 
    return FC.getLinkString(static_cast<size_t>(sideIndex-1));

  // Negetive surface
  return FC.getLinkComplement(static_cast<size_t>((-sideIndex)-1));
}

std::string
LayerPlate::getBackSurface(const size_t layerIndex,
		       const attachSystem::FixedComp&,
		       const long int ) const
  /*!
    Get the front/back surfaces based on the link object 
    \param layerIndex :: Layer Number
    \param FC :: Link object
    \param sideIndex :: Connection point [signed for direction/ zero = centre]
    \return surface string 
   */
{
  ELog::RegMethod RegA("LayerPlate","getBackSurface");

  const int SI(slabIndex+static_cast<int>(layerIndex)*10);
  return ModelSupport::getComposite(SMap,SI," -11 ");  
}

double
LayerPlate::boralGap(const FuncDataBase& Control,
                     const mainSystem::inputParam& IParam)
{

  double bGap(0.0);
  cGap=0.0;

 int t(0);
  while(t<10 && IParam.getValue<std::string>("axDet",t).size()!=0)
    {
     const std::string detT=IParam.getValue<std::string>("axDet",t);
     const std::string pName=IParam.getValue<std::string>("preName");
     const std::string detKey=pName+detT;
     bGap=Control.EvalVar<double>(detKey+"Thick");
     if(Control.EvalVar<int>(detKey+"Active"+"Y1")!=0)
     cGap+=bGap;
     t=t+1;
    }
 

  return cGap;
}





void
LayerPlate::populate(const FuncDataBase& Control)
  /*!
    Populate all the variables
    \param Control :: Function data base to use
  */
{
  ELog::RegMethod RegA("LayerPlate","populate");



  nSlab=Control.EvalVar<size_t>(keyName+"NSlab");
  xStep=Control.EvalVar<double>(keyName+"XStep");
  yStep=Control.EvalVar<double>(keyName+"YStep");
  zStep=Control.EvalVar<double>(keyName+"ZStep");
  xyAngle=Control.EvalVar<double>(keyName+"XYAngle");
  zAngle=Control.EvalVar<double>(keyName+"ZAngle");
  height=Control.EvalVar<double>(keyName+"Height");
  width=Control.EvalVar<double>(keyName+"Width");
  radiusWindow=Control.EvalDefVar<double>(keyName+"WindowRadius",0.0);
  //   if(keyName=="49NestorSide"||keyName=="35NestorSide"||keyName=="75NestorSide"||keyName=="36NestorSide")
     matWindow=ModelSupport::EvalDefMat<int>(Control,keyName+"WindowMat",0);


  double Len,Tmp;
  int M,cutN,SN,SM;
  //cuts
  double CX,CZ,SL,ST,SA,SX,SY,SZ;
  double R0,CX1,CX2,CX3,CZ1,CZ2,CZ3;

  int CM;
  // boralGap;
  double BG=0.0;


  for(size_t i=0;i<nSlab;i++)
    {
      const std::string NStr(StrFunc::makeString(i));
      Len=Control.EvalVar<double>(keyName+"Thick"+NStr);
      Tmp=Control.EvalDefVar<double>(keyName+"Temp"+NStr,0.0);
      thick.push_back(Len);   
      matTemp.push_back(Tmp);   

      if(keyName!="36Shield")
       {
        M=ModelSupport::EvalMat<int>(Control,keyName+"Mat"+NStr);
        mat.push_back(M);   
       }


      if(keyName=="36Shield")
       {
        R0=Control.EvalVar<double>(keyName+"CylDiam"+NStr);
        M=ModelSupport::EvalMat<int>(Control,keyName+"CylMat"+NStr);
        cutX.push_back(R0/2);   
        cutZ.push_back(R0/2);   

        mat.push_back(M);   
        CX1=Control.EvalVar<double>(keyName+"InnerWidth"+NStr);
        CZ1=Control.EvalVar<double>(keyName+"InnerHeight"+NStr);
        M=ModelSupport::EvalMat<int>(Control,keyName+"InnerMat"+NStr);
        cutX.push_back(CX1);   
        cutZ.push_back(CZ1);   
        mat.push_back(M);   
        CX2=Control.EvalVar<double>(keyName+"MidWidth"+NStr);
        CZ2=Control.EvalVar<double>(keyName+"MidHeight"+NStr);
        M=ModelSupport::EvalMat<int>(Control,keyName+"MidMat"+NStr);
        cutX.push_back(CX2);   
        cutZ.push_back(CZ2);   
        mat.push_back(M);   
        CX3=Control.EvalVar<double>(keyName+"OuterWidth"+NStr);
        CZ3=Control.EvalVar<double>(keyName+"OuterHeight"+NStr);
        M=ModelSupport::EvalMat<int>(Control,keyName+"OuterMat"+NStr);
        cutX.push_back(CX3);   
        cutZ.push_back(CZ3);   
        mat.push_back(M);   

        SN=Control.EvalVar<int>(keyName+NStr+"SlotN");
        SL=Control.EvalVar<double>(keyName+NStr+"SlotSide");
        ST=Control.EvalVar<double>(keyName+NStr+"SlotThick");
        SA=Control.EvalDefVar<double>(keyName+NStr+"SlotAngle",0.0);

        slotL.push_back(SL);
        slotN.push_back(SN);
        slotT.push_back(ST);
        slotA.push_back(SA);

        for(size_t n=0;n<SN;n++)
         {
          const std::string SString(StrFunc::makeString(n));
          int TF(0); 
          SX=Control.EvalVar<double>(keyName+NStr+"SlotX"+SString);
          TF=n%2;
          if(TF==0)
          SY+=Control.EvalVar<double>(keyName+NStr+"SlotY"+SString);
          SZ=Control.EvalVar<double>(keyName+NStr+"SlotZ"+SString);
          SM=ModelSupport::EvalMat<int>(Control,keyName+NStr+"SlotMat"+SString);
          slotX.push_back(SX);
          slotY.push_back(SY);
          slotZ.push_back(SZ);
          slotM.push_back(SM);

         }//end for
       }//end if


      if(keyName=="75Shield")
       {
        CX=Control.EvalVar<double>(keyName+"CutX"+NStr);
        CZ=Control.EvalVar<double>(keyName+"CutZ"+NStr);
        CM=ModelSupport::EvalMat<int>(Control,keyName+"CutOutMat"+NStr);

        cutX.push_back(CX);   
        cutZ.push_back(CZ);   
        cutMat.push_back(CM);   
       }

      // if ( keyName=="49Shield" && ModelSupport::EvalMat<std::string>(Control,"49ShieldMat"+NStr)=="49Boral")
      //  {
      // 	thick[i-1]=thick[i-1]-cGap;
      //   thick[i-2]=cGap;
      //  }

       if(i>0 && mat[i]==0 && mat[i-1]==6 && keyName=="49Shield")
       	 {
       	   // temp fix; assume boral is mat 6 and void is 0
       	   thick[i-2]=thick[i-2]-cGap;
           thick[i]=cGap;
       	 }

    }

  return;
}


void
LayerPlate::createUnitVector(const attachSystem::FixedComp& FC,
			 const long int sideIndex)
  /*!
    Create the unit vectors
    \param FC :: FixedComponent for origin
    \param sideIndex :: Connection point [signed for direction/ zero = centre]
  */
{
  ELog::RegMethod RegA("LayerPlate","createUnitVector");

  FixedComp::createUnitVector(FC,sideIndex);

  applyShift(xStep,yStep,zStep);
   applyAngleRotate(xyAngle,zAngle);
  if (fabs(yStep)>Geometry::zeroTol || 
      fabs(xyAngle)>Geometry::zeroTol ||
      fabs(zAngle)>Geometry::zeroTol)
    frontShared=0;
      
      
  return;
}


void
LayerPlate::createSurfaces()
  /*!
    Create All the surfaces
   */
{
  ELog::RegMethod RegA("LayerPlate","createSurface");

  ModelSupport::buildPlane(SMap,slabIndex+3,Origin-X*(width/2.0),X);
  ModelSupport::buildPlane(SMap,slabIndex+4,Origin+X*(width/2.0),X);
  ModelSupport::buildPlane(SMap,slabIndex+5,Origin-Z*(height/2.0),Z);
  ModelSupport::buildPlane(SMap,slabIndex+6,Origin+Z*(height/2.0),Z);

  if (radiusWindow>Geometry::zeroTol)
    ModelSupport::buildCylinder(SMap,slabIndex+7,Origin,Y,radiusWindow);
  

   if(keyName=="36Shield")
    {
     int SM(slabIndex);
     int SP(slabIndex);
     int m (0);
     for(size_t i=0;i<nSlab;i++)
      {
       ModelSupport::buildCylinder(SMap,SM+507,Origin,Y,cutX[i*4]);
       ModelSupport::buildPlane(SMap,SM+503,Origin-X*(cutX[i*4+1]/2.0),X);
       ModelSupport::buildPlane(SMap,SM+504,Origin+X*(cutX[i*4+1]/2.0),X);
       ModelSupport::buildPlane(SMap,SM+505,Origin-Z*(cutZ[i*4+1]/2.0),Z);
       ModelSupport::buildPlane(SMap,SM+506,Origin+Z*(cutZ[i*4+1]/2.0),Z);

       ModelSupport::buildPlane(SMap,SM+603,Origin-X*(cutX[i*4+2]/2.0),X);
       ModelSupport::buildPlane(SMap,SM+604,Origin+X*(cutX[i*4+2]/2.0),X);
       ModelSupport::buildPlane(SMap,SM+605,Origin-Z*(cutZ[i*4+2]/2.0),Z);
       ModelSupport::buildPlane(SMap,SM+606,Origin+Z*(cutZ[i*4+2]/2.0),Z);

       ModelSupport::buildPlane(SMap,SM+703,Origin-X*(cutX[i*4+3]/2.0),X);
       ModelSupport::buildPlane(SMap,SM+704,Origin+X*(cutX[i*4+3]/2.0),X);
       ModelSupport::buildPlane(SMap,SM+705,Origin-Z*(cutZ[i*4+3]/2.0),Z);
       ModelSupport::buildPlane(SMap,SM+706,Origin+Z*(cutZ[i*4+3]/2.0),Z);

       SP=SM;
       for(size_t n=0;n<slotN[i];n++)
        {
	 ModelSupport::buildPlane(SMap,SP+8001,Origin+Y*(slotY[m]-slotT[i]/2.0),Y);
         ModelSupport::buildPlane(SMap,SP+8002,Origin+Y*(slotY[m]+slotT[i]/2.0),Y);
         if(slotA[i]==0.0)
	   {
         ModelSupport::buildPlane(SMap,SP+8003,Origin+X*(slotX[m]-slotL[i]/2.0),X);
         ModelSupport::buildPlane(SMap,SP+8004,Origin+X*(slotX[m]+slotL[i]/2.0),X);
         ModelSupport::buildPlane(SMap,SP+8005,Origin+Z*(slotZ[m]-slotL[i]/2.0),Z);
         ModelSupport::buildPlane(SMap,SP+8006,Origin+Z*(slotZ[m]+slotL[i]/2.0),Z);
	   }
	 else
	   {
         ModelSupport::buildPlane(SMap,SP+8003,Origin+Z*(slotX[m]-slotL[i]/2.0),Z);
         ModelSupport::buildPlane(SMap,SP+8004,Origin+Z*(slotX[m]+slotL[i]/2.0),Z);
         ModelSupport::buildPlane(SMap,SP+8005,Origin+X*(slotZ[m]-slotL[i]/2.0),X);
         ModelSupport::buildPlane(SMap,SP+8006,Origin+X*(slotZ[m]+slotL[i]/2.0),X);
	   }
         SP+=100;
	  m+=1;

  	}//end for
      SM+=10; 
    }

  } //end if


  int SI(slabIndex);
  double totalThick(0.0);
  for(size_t i=0;i<=nSlab;i++)
   {
     ModelSupport::buildPlane(SMap,SI+1,Origin+Y*totalThick,Y);
   if(keyName=="75Shield")
       {
          ModelSupport::buildPlane(SMap,SI+503,Origin-X*(cutX[i]/2.0),X);
          ModelSupport::buildPlane(SMap,SI+504,Origin+X*(cutX[i]/2.0),X);
          ModelSupport::buildPlane(SMap,SI+505,Origin-Z*(cutZ[i]/2.0),Z);
          ModelSupport::buildPlane(SMap,SI+506,Origin+Z*(cutZ[i]/2.0),Z);
        }
     if (i!=nSlab)
       {
	 totalThick+=thick[i];
	 SI+=10;
       }
   }

  FixedComp::setConnect(1,Origin+Y*totalThick,Y);
  FixedComp::setLinkSurf(1,SMap.realSurf(SI+1));

  return;
}


void
LayerPlate::createObjects(Simulation& System,
		      const attachSystem::FixedComp& FC,
		      const long int sideIndex)
  /*!
    Create all the objects
    \param System :: Simulation to create objects in
    \param FC :: FixedComp
    \param sideIndex :: SIGNED sideIndex offset by 1 [0 base origin]
  */
{
  ELog::RegMethod RegA("LayerPlate","createObjects");

  if (mat.empty()) return;

  const std::string FSurf=getFrontSurface(0,FC,sideIndex);
  std::string Out;
  std::string Out1;

   if(keyName=="49NestorSide"||keyName=="35NestorSide"||keyName=="75NestorSide"||keyName=="36NestorSide")
     {
	// al window-outside
      Out=FSurf+ModelSupport::getComposite(SMap,slabIndex," -11 3 -4 5 -6 7");
      System.addCell(MonteCarlo::Qhull(cellIndex++,mat[0],matTemp[0],Out)); 
	// al window-inside
      Out=FSurf+ModelSupport::getComposite(SMap,slabIndex," -11  -7");
      System.addCell(MonteCarlo::Qhull(cellIndex++,matWindow,matTemp[0],Out));
     } 
   else if(keyName=="36Shield")
     {
      std::string slotOut0("");
      int SP(slabIndex);
      for(size_t n=0;n<slotN[0];n++)
       {
        Out=ModelSupport::getComposite(SMap,slabIndex,SP,
                                       "8001M -8002M 8003M -8004M 8005M -8006M -507");
        System.addCell(MonteCarlo::Qhull(cellIndex++,0,0,Out));
        slotOut0+=ModelSupport::getComposite(SMap,slabIndex,SP,
                                           "(-8001M : 8002M : -8003M : 8004M : -8005M : 8006M) ");
        SP+=100;
       }
      Out=FSurf+ModelSupport::getComposite(SMap,slabIndex," -11 -507 ");
      Out=Out+slotOut0;
      System.addCell(MonteCarlo::Qhull(cellIndex++,mat[0],0,Out)); 
      Out=FSurf+ModelSupport::getComposite(SMap,slabIndex,
                                   "-11 507 503 -504  505 -506");
      System.addCell(MonteCarlo::Qhull(cellIndex++,mat[1],matTemp[0],Out)); 
      Out=FSurf+ModelSupport::getComposite(SMap,slabIndex,
                                   "-11 603 -604 605 -606 (-503 : 504 : -505 : 506)");
      System.addCell(MonteCarlo::Qhull(cellIndex++,mat[2],matTemp[0],Out)); 
      Out=FSurf+ModelSupport::getComposite(SMap,slabIndex,
                                   "-11 703 -704 705 -706 (-603M : 604M : -605M : 606M)");
      System.addCell(MonteCarlo::Qhull(cellIndex++,mat[3],matTemp[0],Out)); 
      Out1=FSurf+ModelSupport::getComposite(SMap,slabIndex,
                                   "-11 703 -704 705 -706");
    //  addOuterSurf(Out1);

     }
    else
     {
      Out=FSurf+ModelSupport::getComposite(SMap,slabIndex," -11 3 -4 5 -6");
      System.addCell(MonteCarlo::Qhull(cellIndex++,mat[0],matTemp[0],Out)); 
     }

  std::string slotOut;
  int SI(slabIndex);
  int SP(slabIndex);
  int SC(slabIndex+10);

  for(size_t i=1;i<nSlab;i++)
   {
    if(keyName=="36Shield")
      {
       // ugly part to insert slots, cuts and sections of shield 36

       // slots
       SP=SI+10;             	  

       for(size_t n=0;n<slotN[i];n++)
        {
         Out=ModelSupport::getComposite(SMap,SI,SP,
                                         "8001M -8002M 8003M -8004M 8005M -8006M -507 ");
         System.addCell(MonteCarlo::Qhull(cellIndex++,slotM[i],matTemp[i],Out));
         slotOut+=ModelSupport::getComposite(SMap,slabIndex,SP,
                                             "(-8001M : 8002M : -8003M : 8004M : -8005M : 8006M) ");
         SP+=100;
        }
        //inner cut
       Out=ModelSupport::getComposite(SMap,SC,SI," 1 -11  -507M ");
       Out=Out+slotOut;
       System.addCell(MonteCarlo::Qhull(cellIndex++,mat[4*i],0,Out)); 
       Out=ModelSupport::getComposite(SMap,SC,SI,
                                     "1 -11 507M 503M -504M 505M -506M");
       System.addCell(MonteCarlo::Qhull(cellIndex++,mat[4*i+1],matTemp[0],Out)); 
       Out=ModelSupport::getComposite(SMap,SC,SI,
                                     "1 -11 603M -604M 605M -606M (-503M : 504M : -505M : 506M)");
       System.addCell(MonteCarlo::Qhull(cellIndex++,mat[4*i+2],matTemp[0],Out)); 
       Out=ModelSupport::getComposite(SMap,SC,SI,
                                     "1 -11 703M -704M 705M -706M (-603M : 604M : -605M : 606M)");
       System.addCell(MonteCarlo::Qhull(cellIndex++,mat[4*i+3],matTemp[0],Out)); 
       Out1=FSurf+ModelSupport::getComposite(SMap,SC,SI,
                                     " -11 703M -704M 705M -706M");
       SI+=10;
       SC+=10;
      }
     // other special case is the Shield of exp 75 because of the cuts (water outside layer)  
     else if(keyName=="75Shield")
      {
       SI+=10;
       Out=ModelSupport::getComposite(SMap,slabIndex,SI,"1M -11M 503M -504M 505M -506M");
       System.addCell(MonteCarlo::Qhull(cellIndex++,mat[i],matTemp[i],Out)); 
       Out=ModelSupport::getComposite(SMap,slabIndex,SI,"1M -11M 3 -4 5 -6 (-503M : 504M : -505M : 506M)");
       System.addCell(MonteCarlo::Qhull(cellIndex++,cutMat[i],matTemp[i],Out)); 
      }
     else
      {
       SI+=10;
       Out=ModelSupport::getComposite(SMap,slabIndex,SI,"1M -11M 3 -4 5 -6");
       System.addCell(MonteCarlo::Qhull(cellIndex++,mat[i],matTemp[i],Out)); 
      }
    }
  
   Out=ModelSupport::getComposite(SMap,slabIndex,SI," -11M 3 -4 5 -6");

   if(keyName=="36Shield")
    addOuterSurf(Out1);
   else
    addOuterSurf(FSurf+Out);

  return;
 }

void
LayerPlate::createLinks()
  /*!
    Create all the links
  */
{
  ELog::RegMethod RegA("LayerPlate","createLinks");

  FixedComp::setConnect(0,Origin,-Y);
  FixedComp::setLinkSurf(0,SMap.realSurf(slabIndex+1));
  // Attacth 1 : provided by createSurfaces

  FixedComp::setConnect(2,Origin-X*(width/2.0),-X);
  FixedComp::setLinkSurf(2,-SMap.realSurf(slabIndex+3));
  FixedComp::setConnect(3,Origin+X*(width/2.0),-X);
  FixedComp::setLinkSurf(3,SMap.realSurf(slabIndex+4));
  FixedComp::setConnect(4,Origin-Z*(height/2.0),-Z);
  FixedComp::setLinkSurf(4,-SMap.realSurf(slabIndex+5));
  FixedComp::setConnect(5,Origin+Z*(height/2.0),Z);
  FixedComp::setLinkSurf(5,SMap.realSurf(slabIndex+6));

  return;
}

void
LayerPlate::createAll(Simulation& System,
		  const attachSystem::FixedComp& FC,
		  const long int sideIndex)
  /*!
    Generic function to create everything
    \param System :: Simulation item
    \param FC :: Fixed Component for origin
    \param sideIndex :: Direction/type of side index [0 central origin]
  */
{
  ELog::RegMethod RegA("LayerPlate","createAll");
 
  populate(System.getDataBase());
  createUnitVector(FC,sideIndex);
  createSurfaces();
  createObjects(System,FC,sideIndex);
  createLinks();
  insertObjects(System);

  return;
}


void
LayerPlate::createAllAM(Simulation& System, 
			const mainSystem::inputParam& IParam,
		        const attachSystem::FixedComp& FC,
		        const long int sideIndex)
  /*!
    Generic function to create everything
    \param System :: Simulation item
    \param FC :: Fixed Component for origin
    \param sideIndex :: Direction/type of side index [0 central origin]
  */
{
  ELog::RegMethod RegA("LayerPlate","createAll");

  boralGap(System.getDataBase(),IParam);
  populate(System.getDataBase());
  createUnitVector(FC,sideIndex);
  createSurfaces();
  createObjects(System,FC,sideIndex);
  createLinks();
  insertObjects(System);

  return;
}


  
} 
