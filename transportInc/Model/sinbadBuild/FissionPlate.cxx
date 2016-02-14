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
#include <boost/shared_ptr.hpp>
#include <boost/multi_array.hpp>

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
#include "FissionPlate.h"

// #include "SourceSelector.h"
#include "Source.h"
#include "SrcData.h"
#include "SrcItem.h"
#include "DSTerm.h"

namespace sinbadSystem
{

FissionPlate::FissionPlate(const std::string& Key) : 
  LayerPlate(Key)
  /*!
    Constructor BUT ALL variable are left unpopulated.
    \param Key :: Name for item in search
  */
{}

FissionPlate::FissionPlate(const FissionPlate& A) : 
  LayerPlate(A),
  DIndex(A.DIndex),nDivide(A.nDivide),nXSpace(A.nXSpace),
  nZSpace(A.nZSpace),XPts(A.XPts),ZPts(A.ZPts),YPts(A.YPts),
  matIndex(A.matIndex),matTemp(A.matTemp),indexFPout(A.indexFPout)
  /*!
    Copy constructor
    \param A :: FissionPlate to copy
  */
{}

FissionPlate&
FissionPlate::operator=(const FissionPlate& A)
  /*!
    Assignment operator
    \param A :: FissionPlate to copy
    \return *this
  */
{
  if (this!=&A)
    {
      LayerPlate::operator=(A);
      DIndex=A.DIndex;
      nDivide=A.nDivide;
      nXSpace=A.nXSpace;
      nZSpace=A.nZSpace;
      XPts=A.XPts;
      ZPts=A.ZPts;
      YPts=A.YPts;
      matIndex=A.matIndex;
      matTemp=A.matTemp;
      indexFPout=A.indexFPout;
    }
  return *this;
}

FissionPlate*
FissionPlate::clone() const
  /*!
    Simple clone funciton
    \return new(this)
   */
{
  return new FissionPlate(*this);
}


FissionPlate::~FissionPlate() 
  /*!
    Destructor
  */
{}

std::string
FissionPlate::getXSurf(const long int Index) const
  /*!
    Calculate the side +/- surfaces
    \param Index :: Index array
    \return String
  */
{
  ELog::RegMethod RegA("FissionPlate","getXSurf");

  const int SI(slabIndex+1000+(static_cast<int>(Index)-1)*10);
  if (Index>0 && Index<static_cast<long int>(nXSpace))
    return ModelSupport::getComposite(SMap,SI," 3 -13 ");

  // not used
  if (Index==0)
    return ModelSupport::getComposite(SMap,slabIndex,SI," 3 -13M ");

  // fictitous flag to build the Al top/bottom cover of the fission plate 
  if (Index<0)
     return ModelSupport::getComposite(SMap,slabIndex+1000,
                                       slabIndex+1000+(static_cast<int>(nXSpace)-1)*10," 3 -3M ");

  // right hand edge:
  return ModelSupport::getComposite(SMap,slabIndex,SI," 3M -4 ");
}


std::string
FissionPlate::getZSurf(const long int Index) const
  /*!
    Calculate the top/bottom +/- surfaces
    \param Index :: Index array
    \return String
  */
{
  ELog::RegMethod RegA("FissionPlate","getZSurf");
  
  const int SI(slabIndex+1000+(static_cast<int>(Index)-1)*10);
  if (Index>0 && Index<static_cast<long int>(nZSpace))
    return ModelSupport::getComposite(SMap,SI," 5 -15 ");
  if (Index==0)
    return ModelSupport::getComposite(SMap,slabIndex,SI," 5 -15M ");
  //fictitious flag to buld left/right fission plate cover
  if (Index<0)
    return ModelSupport::getComposite(SMap,slabIndex,SI," 5 -6 ");

  // top edge:
  return ModelSupport::getComposite(SMap,slabIndex,SI," 5M -6 ");
}

template<typename T>
T
FissionPlate::getXZ(const FuncDataBase& Control,
		    const std::string& SubKey,const long int dLayer,
		    const long int I,const long int J) const
  /*!
    Get a database entry based on a key system:
    -  Naming for Individual : L3X12Z45
    -  Naming for Row : L3X12 
    -  Naming for Column : L3Z45 
    -  Naming for DEFAULT : L3           
    Note that layer has NO default
    \param Control :: DataBase of variables
    \param SubKey :: SubKey after master keyName
    \param I :: First index 
    \param J :: Second index 
    \return Database entry
   */
{
  ELog::RegMethod RegA("FissionPlate","getXZ");

  const std::string LN=StrFunc::makeString(std::string("L"),dLayer);
  const std::string XN=StrFunc::makeString(std::string("X"),I);
  const std::string ZN=StrFunc::makeString(std::string("Z"),J);
  const std::string PreName=keyName+SubKey+LN;
  if (Control.hasVariable(PreName+XN+ZN))
    return Control.EvalVar<T>(PreName+XN+ZN);
  if (Control.hasVariable(PreName+XN))
    return Control.EvalVar<T>(PreName+XN);
  if (Control.hasVariable(PreName+ZN))
    return Control.EvalVar<T>(PreName+ZN);

  // If this fails :: Exception thrown
  return Control.EvalVar<T>(PreName);
}
    
void
FissionPlate::populate(const FuncDataBase& Control)
  /*!
    Populate all the variables
    \param Control :: DataBase of variables
  */
{
  ELog::RegMethod RegA("FissionPlate","populate");

  LayerPlate::populate(Control);

  nDivide=0;

  // First determin if we have any index layers to process:
  const std::string KN=keyName+"DivIndex";
  for(size_t i=0;i<nSlab && 
	Control.hasVariable(KN+StrFunc::makeString(i));i++)
   DIndex.push_back(Control.EvalVar<size_t>(KN+StrFunc::makeString(i)));

  if (DIndex.empty() || 
      (*std::max_element(DIndex.begin(),DIndex.end())>=nSlab))
    {
      ELog::EM<<"Fission Plate not divided "<<ELog::endWarn;
      return;
    }

  // Division of layers :
  nXSpace=Control.EvalVar<size_t>(keyName+"NXSpace");  
  nZSpace=Control.EvalVar<size_t>(keyName+"NZSpace");  

  double xStepNC=Control.EvalVar<double>(keyName+"XNucCentre");

  double zStepNC=Control.EvalVar<double>(keyName+"ZNucCentre");


  // ELog::EM<<" XZSpace "<<nZSpace<<ELog::endWarn;
  
  if (nXSpace*nZSpace==0)
    {
      ELog::EM<<"Fission Plate not divided :"
	      <<nXSpace<<" "<<nZSpace<<ELog::endWarn;
      return;
    }
    
  // READ XPTS/ZPTS [sort -- but can check for uniq etc]
  XPts.clear();
  ZPts.clear();
  YPts.clear();

  double XV,ZV,YV;
  for(size_t i=0;i<nXSpace;i++)
    {
      XV=Control.EvalVar<double>(keyName+"XPt"+StrFunc::makeString(i))-xStepNC; 
      XPts.push_back(XV);
    }
  std::sort(XPts.begin(),XPts.end());
  
  for(size_t i=0;i<nZSpace;i++)
    {
      ZV=Control.EvalVar<double>(keyName+"ZPt"+StrFunc::makeString(i)) -zStepNC;
      ZPts.push_back(ZV);

    }
  std::sort(ZPts.begin(),ZPts.end());

  //read source distribution values
  // for(size_t ix=0;ix<nXSpace-1;ix++)
  //  {
  //   std::vector<double> YPtsRow;
  //   for(size_t iz=0;iz<nZSpace-1;iz++)
  //    {
  //     YV=Control.EvalVar<double>(keyName+"YPt"+StrFunc::makeString(ix+iz*(nZSpace-1)));
  //     YPtsRow.push_back(YV);
  //    }
  //    YPts.push_back(YPtsRow);
  //  }

  //new
  for(size_t ix=0;ix<nXSpace-1;ix++)
   {
    std::vector<double> YPtsRow;
    std::string SX=StrFunc::makeString(keyName+"SourceX",ix);

    for(size_t iz=0;iz<nZSpace-1;iz++)
     {
      std::string SXZ=StrFunc::makeString(SX+"Z",iz);
      YV=Control.EvalVar<double>(StrFunc::makeString(SX+"Z",iz));
      YPtsRow.push_back(YV);
     }
     YPts.push_back(YPtsRow);
   }






  //
  // MASTER Loop for Mat/Mat Temp:
  //
  nDivide=DIndex.size();
  //nSpace+1 because 0 ans nSpace+1 are reserved to the Al cover; 1-nSpace refer to fission plate itself 
  matIndex.resize(boost::extents
		  [static_cast<long int>(nDivide)]
		  [static_cast<long int>(nXSpace+1)]
		  [static_cast<long int>(nZSpace+1)]);
  matTemp.resize(boost::extents
		 [static_cast<long int>(nDivide)]
		 [static_cast<long int>(nXSpace+1)]
		 [static_cast<long int>(nZSpace+1)]);

  // std::string matName1;  

  for(long int dLayer=0;dLayer < static_cast<long int>(nDivide);dLayer++)
    {
      for(long int i=0;i<static_cast<long int>(nXSpace+1);i++)
	for(long int j=0;j<static_cast<long int>(nZSpace+1);j++)
	  {
	     long int ix(i-1);
	     long int iz(j-1);

	     if(i==0) ix=i;
	     if(j==0) iz=j;
 
	     if(i==nXSpace) ix=i-2;
	     if(j==nZSpace) iz=j-2;

	    if(YPts.at(ix).at(iz)!=0)
	       {
	        const std::string matName=
	        getXZ<std::string>(Control,"MatIn",dLayer,i,j);
	        matIndex[dLayer][i][j]=ModelSupport::EvalMatName(matName);
	       }
	    else
	       {
	        const std::string matName=
	        getXZ<std::string>(Control,"MatOut",dLayer,i,j);
 	        matIndex[dLayer][i][j]=ModelSupport::EvalMatName(matName);
	       }
	     // matIndex[dLayer][i][j]=ModelSupport::EvalMatName(matName);
	    //	    matTemp[dLayer][i][j]=getXZ<double>(Control,"MatTemp",dLayer,i,j);
	    //   std::string matFPout 
	    //  indexFPout=Control.EvalVar<size_t>(keyName+"MatOutL0");  
	     //    indexFPout=ModelSupport::EvalMatName(matFPout);
  indexFPout=ModelSupport::EvalMat<int>(Control,keyName+"MatOutL0"); 

	  }
	 

    }
  return;
}

void
FissionPlate::createSurfaces()
  /*!
    Create All the extra surfaces for the divided cell
  */
{
  ELog::RegMethod RegA("FissionPlate","createSurface");


  LayerPlate::createSurfaces();
  if (!nDivide) return;

  int SI(slabIndex+1000);  
  std::vector<double>::const_iterator vc;
  for(size_t i=0;i<XPts.size();i++)    
    {
      ModelSupport::buildPlane(SMap,SI+3,Origin+X*XPts[i],X);
      SI+=10;
    }
  SI=(slabIndex+1000);
  for(size_t i=0;i<ZPts.size();i++)
    {
      ModelSupport::buildPlane(SMap,SI+5,Origin+Z*ZPts[i],Z);
      SI+=10;
    }
  return;
}


void
FissionPlate::createObjects(Simulation& System,
		      const attachSystem::FixedComp& FC,
			    const long int sideIndex)
/*!
    Create all the objects
    \param System :: Simulation to create objects in
    \param FC :: FixedComp
    \param sideIndex :: SIGNED sideIndex offset by 1 [0 base origin]
  */
{
  ELog::RegMethod RegA("FissionPlate","createObjects");
  
  LayerPlate::createObjects(System,FC,sideIndex);
  // No work check
  if (nDivide==0)
    return;

  for(size_t dLayer=0;dLayer<nDivide;dLayer++)
    {
      const long int DI(static_cast<long int>(dLayer));
      //    ELog::EM<<" dLayer "<<dLayer<<" nDivide "<<nDivide<<ELog::endWarn;


      const int CIndex=getCellIndex(DIndex[dLayer]);
      System.removeCell(CIndex);


      // This should be to a virtual function:
      const std::string fbSurf=getFrontSurface(DIndex[dLayer],FC,sideIndex)+
	getBackSurface(DIndex[dLayer],FC,sideIndex);


      // Al Cover on the left of the fission plate
      const std::string OutLeft=fbSurf+getXSurf(0)+getZSurf(-1);
      System.addCell(MonteCarlo::Qhull
	  	    (cellIndex++,indexFPout,matTemp[DI][0][0],OutLeft));

      // Al Cover on the right of the fission plate
      const std::string OutRight=fbSurf+getXSurf(nXSpace)+getZSurf(-1);
      System.addCell(MonteCarlo::Qhull
	  	    (cellIndex++,indexFPout,matTemp[DI][nXSpace][nZSpace],OutRight));

      // Al Cover on the bottom of the fission plate
      const std::string OutBottom=fbSurf+getZSurf(0)+getXSurf(-1);
      System.addCell(MonteCarlo::Qhull
	            (cellIndex++,indexFPout,matTemp[DI][0][0],OutBottom));

      // Al Cover on the top of the fission plate
      const std::string OutTop=fbSurf+getZSurf(nZSpace)+getXSurf(-1);
      System.addCell(MonteCarlo::Qhull
	            (cellIndex++,indexFPout,matTemp[DI][nXSpace][nZSpace],OutTop));

      // Fission plate 'chessboard' (indexes between 1 and nSpace-1)
      for(long int i=1;i<static_cast<long int>(nXSpace);i++)
	{
	  const std::string sides=getXSurf(i);
	  for(long int j=1;j<static_cast<long int>(nZSpace);j++)
	    {
	      const std::string Out=fbSurf+sides+getZSurf(j);
	      System.addCell(MonteCarlo::Qhull
		            (cellIndex++,matIndex[DI][i][j],matTemp[DI][i][j],Out));
	    }
	}   
    }   

  return;
}


void
FissionPlate::createAll(Simulation& System,
			const attachSystem::FixedComp& FC,
			const long int sideIndex)
  /*!
    Generic function to create everything
    \param System :: Simulation item
    \param FC :: Fixed Component for origin
  */
    {
  ELog::RegMethod RegA("FissionPlate","createAll");

 populate(System.getDataBase());
  // populate(System);
 createUnitVector(FC,sideIndex);
 createSurfaces();
 createObjects(System,FC,sideIndex);
 insertObjects(System);

  return;
 }
  

 }
