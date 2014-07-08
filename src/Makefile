#!-----------------------------------------------------------------------
SHELL=/bin/sh
#
#
# First where are we going to get the sources
SRCDIR=.
#
## Fortran compiler and compilation flags
#
FCOMPL=gfortran
FFLAG=-g  -fPIC -fno-automatic -C -ffixed-line-length-132 -fno-backslash \
         -Wall 
#CCOMPL=/usr/local/bin/g++
BCOMPL=clang
CCOMPL=clang
CFLAGC=-g -fPIC -Wconversion -W -Wall -Wextra -Wno-comment -fexceptions
CFLAGE=-g -fPIC -Wconversion -W -Wall -Wextra -Wno-comment -fexceptions
BCFLAGC=-g -fPIC -Wconversion -W -Wall -Wextra -Wno-comment -fexceptions
MCOMPL=
FLAGC=

AR= ar
RANLIB= ranlib

LIBOUTDIR= /home/alberto/mbin/mcnp/CombLayer/lib
INCBOOST = -I/opt/local/include
INCGSL=

INCDIRA=../include
INCDIRB=../attachCompInc
INCDIRC=../beamlineInc
INCDIRD=../bibBuildInc
INCDIRE=../bnctBuildInc
INCDIRF=../buildInc
INCDIRG=../chipInc
INCDIRH=../constructInc
INCDIRI=../crystalInc
INCDIRJ=../cuBlockInc
INCDIRK=../d4cModelInc
INCDIRL=../delftInc
INCDIRM=../endfInc
INCDIRN=../epbBuildInc
INCDIRO=../essBuildInc
INCDIRP=../funcBaseInc
INCDIRQ=../geomInc
INCDIRR=../globalInc
INCDIRS=../imatInc
INCDIRT=../inputInc
INCDIRU=../instrumentInc
INCDIRV=../lensModelInc
INCDIRW=../logInc
INCDIRX=../md5Inc
INCDIRY=../mersenneInc
INCDIRZ=../moderatorInc
INCDIRa=../monteInc
INCDIRb=../muonInc
INCDIRc=../physicsInc
INCDIRd=../polyInc
INCDIRe=../processInc
INCDIRf=../scatMatInc
INCDIRg=../sinbadBuildInc
INCDIRh=../snsBuildInc
INCDIRi=../sourceInc
INCDIRj=../specialInc
INCDIRk=../supportInc
INCDIRl=../tallyInc
INCDIRm=../t1BuildInc
INCDIRn=../t1UpgradeInc
INCDIRo=../transportInc
INCDIRp=../visitInc
INCDIRq=../weightsInc
INCDIRr=../workInc
INCDIRs=../worldInc
INCDIRt=../xmlInc
INCDIRu=../zoomInc
INCDIRv=../testInclude

LIBS=-L/usr/X11/lib -lX11 -L/usr/lib -lm
FORTLIBS=-lgfortranbegin -lgfortran 
OPENLIBS=-lglut -lGLU -lGL -L/usr/X11R6/lib -lXmu -lX11
MOTIF_LIBS=-L/usr/X11R6/lib -lXm -lXtst -lX11
BOOSTLIBS= -L/opt/local/lib -lboost_regex
GSLLIBS=-lgsl -lgslcblas -lm 

ASRC = $(CSRC) $(CINC) $(FSRC) 

CSRC = DSTerm.cxx KCode.cxx KGroup.cxx mainJobs.cxx \
            masterRotate.cxx NList.cxx NodeList.cxx NodePoint.cxx \
            NRange.cxx pairRange.cxx Radiation.cxx RadNodes.cxx \
            ReadFunctions.cxx RemoveCell.cxx SimMonte.cxx \
            SimPHITS.cxx SimTrack.cxx Simulation.cxx SimValid.cxx \
            Source.cxx SrcData.cxx SrcItem.cxx transComp.cxx \
            Triple.cxx version.cxx WeightModification.cxx 

FSRC = 

CINC = 

FINC = 

ODEP = DSTerm.o KCode.o KGroup.o mainJobs.o masterRotate.o \
            NList.o NodeList.o NodePoint.o NRange.o pairRange.o \
            Radiation.o RadNodes.o ReadFunctions.o RemoveCell.o \
            SimMonte.o SimPHITS.o SimTrack.o Simulation.o \
            SimValid.o Source.o SrcData.o SrcItem.o transComp.o \
            Triple.o version.o WeightModification.o 

all: $(LIBOUTDIR)/libSrc.so 

$(LIBOUTDIR)/libSrc.so : $(ODEP) 
	$(CCOMPL) -fPIC -shared -g  -o $(LIBOUTDIR)/libSrc.so \
       $(ODEP) 

DSTerm.o: $(SRCDIR)/DSTerm.cxx $(INCDIRA)/DSTerm.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/mathSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRA)/SrcData.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRW) \
               -I$(INCDIRR) -I$(INCDIRA) $(INCBOOST) \
               $(SRCDIR)/DSTerm.cxx

KCode.o: $(SRCDIR)/KCode.cxx $(INCDIRA)/KCode.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRk)/MapSupport.h $(INCDIRA)/masterRotate.h  \
             $(INCDIRk)/mathSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/Transform.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRW) \
               -I$(INCDIRR) -I$(INCDIRA) $(INCBOOST) $(SRCDIR)/KCode.cxx

KGroup.o: $(SRCDIR)/KGroup.cxx $(INCDIRA)/KGroup.h \
             $(INCDIRk)/Exception.h $(INCDIRA)/NRange.h  \
             $(INCDIRk)/support.h $(INCDIRA)/Triple.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRk) -I$(INCDIRA) $(INCBOOST) \
               $(SRCDIR)/KGroup.cxx

NList.o: $(SRCDIR)/NList.cxx $(INCDIRA)/NList.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRA)/Triple.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRA) \
               $(SRCDIR)/NList.cxx

NRange.o: $(SRCDIR)/NRange.cxx $(INCDIRA)/NRange.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/mathSupport.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRk)/support.h  \
             $(INCDIRA)/Triple.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRA) \
               $(SRCDIR)/NRange.cxx

NodeList.o: $(SRCDIR)/NodeList.cxx $(INCDIRA)/NodeList.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRA)/NodePoint.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Transform.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRW) \
               -I$(INCDIRA) $(SRCDIR)/NodeList.cxx

NodePoint.o: $(SRCDIR)/NodePoint.cxx $(INCDIRA)/NodePoint.h \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Transform.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRA) \
               $(SRCDIR)/NodePoint.cxx

RadNodes.o: $(SRCDIR)/RadNodes.cxx $(INCDIRA)/RadNodes.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRa)/Element.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRP)/FItem.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRA)/KGroup.h $(INCDIRk)/MapSupport.h  \
             $(INCDIRa)/Material.h $(INCDIRk)/mathSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRY)/MersenneTwister.h $(INCDIRa)/MXcards.h  \
             $(INCDIRW)/NameStack.h $(INCDIRA)/NList.h  \
             $(INCDIRA)/NodeList.h $(INCDIRA)/NodePoint.h  \
             $(INCDIRA)/NRange.h $(INCDIRa)/Object.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRc)/PhysCard.h  \
             $(INCDIRc)/PhysImp.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRA)/Radiation.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRA)/RemoveCell.h  \
             $(INCDIRa)/Rules.h $(INCDIRA)/Simulation.h  \
             $(INCDIRA)/Source.h $(INCDIRA)/SrcData.h  \
             $(INCDIRA)/SrcItem.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRk)/Tensor.h  \
             $(INCDIRQ)/Transform.h $(INCDIRA)/Triple.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRa) -I$(INCDIRY) -I$(INCDIRP) \
               -I$(INCDIRA) -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRc) \
               -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/RadNodes.cxx

Radiation.o: $(SRCDIR)/Radiation.cxx $(INCDIRA)/Radiation.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRk)/Tensor.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRk) -I$(INCDIRQ) \
               -I$(INCDIRW) $(SRCDIR)/Radiation.cxx

ReadFunctions.o: $(SRCDIR)/ReadFunctions.cxx $(INCDIRA)/ReadFunctions.h \
             $(INCDIRa)/Acomp.h $(INCDIRa)/Algebra.h  \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRa)/BnId.h $(INCDIRP)/Code.h  \
             $(INCDIRa)/DBMaterial.h $(INCDIRA)/DSTerm.h  \
             $(INCDIRa)/Element.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRP)/FItem.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRA)/KCode.h  \
             $(INCDIRA)/KGroup.h $(INCDIRc)/LSwitchCard.h  \
             $(INCDIRk)/MapSupport.h $(INCDIRa)/Material.h  \
             $(INCDIRk)/mathSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRc)/ModeCard.h  \
             $(INCDIRa)/MXcards.h $(INCDIRW)/NameStack.h  \
             $(INCDIRA)/NList.h $(INCDIRA)/NRange.h  \
             $(INCDIRa)/Object.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRc)/PhysCard.h $(INCDIRc)/PhysicsCards.h  \
             $(INCDIRc)/PhysImp.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRA)/Source.h  \
             $(INCDIRA)/SrcData.h $(INCDIRA)/SrcItem.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/surfaceFactory.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRQ)/SurInter.h $(INCDIRQ)/Transform.h  \
             $(INCDIRA)/Triple.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRa) -I$(INCDIRP) -I$(INCDIRA) \
               -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRc) -I$(INCDIRW) \
               -I$(INCDIRR) $(INCBOOST) $(SRCDIR)/ReadFunctions.cxx

RemoveCell.o: $(SRCDIR)/RemoveCell.cxx $(INCDIRA)/RemoveCell.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRa)/Object.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRa)/Qhull.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRa) -I$(INCDIRA) -I$(INCDIRP) \
               -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) \
               $(SRCDIR)/RemoveCell.cxx

SimMonte.o: $(SRCDIR)/SimMonte.cxx $(INCDIRA)/SimMonte.h \
             $(INCDIRQ)/ArbPoly.h $(INCDIRR)/BaseModVisit.h  \
             $(INCDIRR)/BaseVisit.h $(INCDIRo)/Beam.h  \
             $(INCDIRP)/Code.h $(INCDIRQ)/Cone.h  \
             $(INCDIRQ)/CylCan.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRo)/Detector.h $(INCDIRo)/DetGroup.h  \
             $(INCDIRa)/Element.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRP)/FItem.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRQ)/General.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRk)/ManagedPtr.h $(INCDIRk)/MapSupport.h  \
             $(INCDIRa)/Material.h $(INCDIRk)/mathSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRQ)/MBrect.h $(INCDIRY)/MersenneTwister.h  \
             $(INCDIRa)/MXcards.h $(INCDIRW)/NameStack.h  \
             $(INCDIRf)/neutMaterial.h $(INCDIRa)/neutron.h  \
             $(INCDIRA)/NRange.h $(INCDIRQ)/NullSurface.h  \
             $(INCDIRo)/ObjComponent.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/ObjSurfMap.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRA)/Simulation.h $(INCDIRQ)/Sphere.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/surfaceFactory.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRQ)/Torus.h $(INCDIRa)/Track.h  \
             $(INCDIRA)/Triple.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h $(INCDIRR)/XMLwriteVisitor.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRf) -I$(INCDIRe) -I$(INCDIRa) \
               -I$(INCDIRY) -I$(INCDIRP) -I$(INCDIRA) -I$(INCDIRo) \
               -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/SimMonte.cxx

SimPHITS.o: $(SRCDIR)/SimPHITS.cxx $(INCDIRA)/SimPHITS.h \
             $(INCDIRa)/Acomp.h $(INCDIRa)/Algebra.h  \
             $(INCDIRQ)/ArbPoly.h $(INCDIRR)/BaseModVisit.h  \
             $(INCDIRR)/BaseVisit.h $(INCDIRa)/BnId.h  \
             $(INCDIRl)/cellFluxTally.h $(INCDIRP)/Code.h  \
             $(INCDIRQ)/Cone.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRa)/DBMaterial.h $(INCDIRW)/Debug.h  \
             $(INCDIRa)/Element.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRP)/FItem.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRQ)/General.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRl)/heatTally.h $(INCDIRA)/KCode.h  \
             $(INCDIRA)/KGroup.h $(INCDIRc)/LSwitchCard.h  \
             $(INCDIRk)/MapSupport.h $(INCDIRa)/Material.h  \
             $(INCDIRk)/mathSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRQ)/MBrect.h  \
             $(INCDIRc)/ModeCard.h $(INCDIRa)/MXcards.h  \
             $(INCDIRW)/NameStack.h $(INCDIRA)/NList.h  \
             $(INCDIRA)/NRange.h $(INCDIRQ)/NullSurface.h  \
             $(INCDIRa)/Object.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRc)/PhysCard.h $(INCDIRc)/PhysicsCards.h  \
             $(INCDIRc)/PhysImp.h $(INCDIRQ)/Plane.h  \
             $(INCDIRl)/pointTally.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRA)/RemoveCell.h  \
             $(INCDIRa)/Rules.h $(INCDIRA)/Simulation.h  \
             $(INCDIRA)/Source.h $(INCDIRQ)/Sphere.h  \
             $(INCDIRA)/SrcData.h $(INCDIRA)/SrcItem.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/surfaceFactory.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRQ)/surfProg.h $(INCDIRQ)/SurInter.h  \
             $(INCDIRl)/Tally.h $(INCDIRl)/tallyFactory.h  \
             $(INCDIRQ)/Torus.h $(INCDIRQ)/Transform.h  \
             $(INCDIRA)/Triple.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h $(INCDIRA)/version.h  \
             $(INCDIRq)/weightManager.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRl) -I$(INCDIRa) -I$(INCDIRP) \
               -I$(INCDIRA) -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRc) \
               -I$(INCDIRW) -I$(INCDIRR) -I$(INCDIRq) $(INCBOOST) \
               $(SRCDIR)/SimPHITS.cxx

SimTrack.o: $(SRCDIR)/SimTrack.cxx $(INCDIRA)/SimTrack.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRk) -I$(INCDIRW) \
               $(SRCDIR)/SimTrack.cxx

SimValid.o: $(SRCDIR)/SimValid.cxx $(INCDIRA)/SimValid.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRA)/masterRotate.h $(INCDIRk)/mathSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRY)/MersenneTwister.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/neutron.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/ObjSurfMap.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRe)/SimProcess.h $(INCDIRA)/Simulation.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/SurInter.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRY) \
               -I$(INCDIRP) -I$(INCDIRA) -I$(INCDIRk) -I$(INCDIRQ) \
               -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/SimValid.cxx

Simulation.o: $(SRCDIR)/Simulation.cxx $(INCDIRA)/Simulation.h \
             $(INCDIRa)/Acomp.h $(INCDIRa)/Algebra.h  \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRa)/BnId.h $(INCDIRl)/cellFluxTally.h  \
             $(INCDIRP)/Code.h $(INCDIRa)/DBMaterial.h  \
             $(INCDIRa)/Element.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRP)/FItem.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRl)/heatTally.h  \
             $(INCDIRA)/KCode.h $(INCDIRA)/KGroup.h  \
             $(INCDIRQ)/localRotate.h $(INCDIRc)/LSwitchCard.h  \
             $(INCDIRk)/MapSupport.h $(INCDIRA)/masterRotate.h  \
             $(INCDIRa)/Material.h $(INCDIRk)/mathSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRc)/ModeCard.h $(INCDIRa)/MXcards.h  \
             $(INCDIRW)/NameStack.h $(INCDIRA)/NList.h  \
             $(INCDIRA)/NRange.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRe)/ObjSurfMap.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRc)/PhysCard.h  \
             $(INCDIRc)/PhysicsCards.h $(INCDIRc)/PhysImp.h  \
             $(INCDIRl)/pointTally.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRA)/ReadFunctions.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRA)/RemoveCell.h $(INCDIRa)/Rules.h  \
             $(INCDIRA)/SimTrack.h $(INCDIRA)/Source.h  \
             $(INCDIRA)/SrcData.h $(INCDIRA)/SrcItem.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/surfaceFactory.h $(INCDIRe)/surfEqual.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRQ)/SurInter.h  \
             $(INCDIRl)/Tally.h $(INCDIRl)/tallyFactory.h  \
             $(INCDIRQ)/Transform.h $(INCDIRA)/Triple.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h  \
             $(INCDIRA)/version.h $(INCDIRq)/weightManager.h  \
             $(INCDIRq)/WForm.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRl) -I$(INCDIRa) \
               -I$(INCDIRP) -I$(INCDIRA) -I$(INCDIRk) -I$(INCDIRQ) \
               -I$(INCDIRc) -I$(INCDIRW) -I$(INCDIRR) -I$(INCDIRq) \
               $(INCBOOST) $(SRCDIR)/Simulation.cxx

Source.o: $(SRCDIR)/Source.cxx $(INCDIRA)/Source.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRk)/MapSupport.h $(INCDIRA)/masterRotate.h  \
             $(INCDIRk)/mathSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRA)/SrcData.h  \
             $(INCDIRA)/SrcItem.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/Transform.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRk) -I$(INCDIRQ) \
               -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/Source.cxx

SrcData.o: $(SRCDIR)/SrcData.cxx $(INCDIRA)/SrcData.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRA)/DSTerm.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRk)/mathSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRk) -I$(INCDIRQ) \
               -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/SrcData.cxx

SrcItem.o: $(SRCDIR)/SrcItem.cxx $(INCDIRA)/SrcItem.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRe)/masterWrite.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRA) -I$(INCDIRk) \
               -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/SrcItem.cxx

Triple.o: $(SRCDIR)/Triple.cxx $(INCDIRA)/Triple.h \
             $(INCDIRk)/Exception.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRk) -I$(INCDIRQ) \
               $(SRCDIR)/Triple.cxx

WeightModification.o: $(SRCDIR)/WeightModification.cxx $(INCDIRA)/WeightModification.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRA)/KCode.h $(INCDIRA)/KGroup.h  \
             $(INCDIRc)/LSwitchCard.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRc)/ModeCard.h  \
             $(INCDIRW)/NameStack.h $(INCDIRA)/NList.h  \
             $(INCDIRA)/NRange.h $(INCDIRa)/Object.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRc)/PhysCard.h  \
             $(INCDIRc)/PhysicsCards.h $(INCDIRc)/PhysImp.h  \
             $(INCDIRa)/Qhull.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRA)/Simulation.h  \
             $(INCDIRA)/Source.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRk)/Tensor.h  \
             $(INCDIRQ)/Transform.h $(INCDIRA)/Triple.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h  \
             $(INCDIRq)/weightManager.h $(INCDIRq)/WForm.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRa) -I$(INCDIRP) -I$(INCDIRA) \
               -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRc) -I$(INCDIRW) \
               -I$(INCDIRR) -I$(INCDIRq) $(INCBOOST) \
               $(SRCDIR)/WeightModification.cxx

mainJobs.o: $(SRCDIR)/mainJobs.cxx $(INCDIRA)/mainJobs.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRT)/inputParam.h  \
             $(INCDIRA)/KGroup.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRA)/masterRotate.h $(INCDIRp)/MatMD5.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRp)/MD5sum.h $(INCDIRe)/MeshCreate.h  \
             $(INCDIRW)/NameStack.h $(INCDIRA)/NList.h  \
             $(INCDIRA)/NRange.h $(INCDIRa)/Object.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRe)/SimProcess.h  \
             $(INCDIRA)/Simulation.h $(INCDIRA)/Source.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/SurInter.h  \
             $(INCDIRl)/TallyCreate.h $(INCDIRA)/Triple.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h  \
             $(INCDIRp)/Visit.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRl) -I$(INCDIRa) \
               -I$(INCDIRT) -I$(INCDIRP) -I$(INCDIRA) -I$(INCDIRk) \
               -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRp) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/mainJobs.cxx

masterRotate.o: $(SRCDIR)/masterRotate.cxx $(INCDIRA)/masterRotate.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRk)/mathSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRA)/transComp.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRk) -I$(INCDIRQ) \
               -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/masterRotate.cxx

pairRange.o: $(SRCDIR)/pairRange.cxx $(INCDIRA)/pairRange.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRA)/NRange.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRk)/support.h  \
             $(INCDIRA)/Triple.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRk) -I$(INCDIRW) \
               $(SRCDIR)/pairRange.cxx

transComp.o: $(SRCDIR)/transComp.cxx $(INCDIRA)/transComp.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRk)/mathSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRa) -I$(INCDIRA) -I$(INCDIRk) \
               -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/transComp.cxx

version.o: $(SRCDIR)/version.cxx $(INCDIRA)/version.h \
             $(INCDIRk)/Exception.h $(INCDIRk)/support.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRk) $(SRCDIR)/version.cxx

words: 
	grep -v -e '^[[:space:][:cntrl:]]*$$' $(ASRC) | wc 

loc: 
	sloccount $(ASRC) 

cccc: 
	cccc $(ASRC) 

clean:
	rm $(ODEP)

tar:
	tar -zcvf src.tgz $(ASRC) Doxyfile Makefile getMk.pl getMake.pmtar:
	tar -zcvf src_core.tgz $(CORESRC) getMk.pl getMake.pm
cost:
	sloccount $(ASRC) Doxyfile Makefile getMk.pl getMake.pm
doxygen:
	(cat Doxyfile; echo "INPUT= $(ASRC)" ) | doxygen -

