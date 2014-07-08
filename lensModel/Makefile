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

CSRC = candleStick.cxx FlightCluster.cxx layers.cxx lensFL.cxx \
            LensSource.cxx LensTally.cxx lensVariables.cxx \
            makeLens.cxx outerConstruct.cxx ProtonFlight.cxx \
            siModerator.cxx 

FSRC = 

CINC = 

FINC = 

ODEP = candleStick.o FlightCluster.o layers.o lensFL.o \
            LensSource.o LensTally.o lensVariables.o makeLens.o \
            outerConstruct.o ProtonFlight.o siModerator.o 

all: $(LIBOUTDIR)/libLensModel.so 

$(LIBOUTDIR)/libLensModel.so : $(ODEP) 
	$(CCOMPL) -fPIC -shared -g  -o $(LIBOUTDIR)/libLensModel.so \
       $(ODEP) 

FlightCluster.o: $(SRCDIR)/FlightCluster.cxx $(INCDIRV)/FlightCluster.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRB)/ContainedGroup.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRH)/FlightLine.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRe)/ModelSupport.h  \
             $(INCDIRW)/NameStack.h $(INCDIRa)/Object.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRA)/Simulation.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRA) -I$(INCDIRP) \
               -I$(INCDIRQ) -I$(INCDIRV) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRH) -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/FlightCluster.cxx

LensSource.o: $(SRCDIR)/LensSource.cxx $(INCDIRV)/LensSource.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRk)/doubleErr.h  \
             $(INCDIRA)/DSTerm.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRB)/LinearComp.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRe)/ModelSupport.h  \
             $(INCDIRW)/NameStack.h $(INCDIRA)/NList.h  \
             $(INCDIRA)/NRange.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRA)/Source.h  \
             $(INCDIRA)/SrcData.h $(INCDIRA)/SrcItem.h  \
             $(INCDIRk)/support.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRA)/Triple.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h $(INCDIRr)/WorkData.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRP) -I$(INCDIRA) \
               -I$(INCDIRQ) -I$(INCDIRV) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRk) -I$(INCDIRr) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/LensSource.cxx

LensTally.o: $(SRCDIR)/LensTally.cxx $(INCDIRV)/LensTally.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRl)/cellFluxTally.h $(INCDIRP)/Code.h  \
             $(INCDIRB)/ContainedComp.h $(INCDIRB)/ContainedGroup.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRV)/FlightCluster.h  \
             $(INCDIRH)/FlightLine.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRl)/heatTally.h $(INCDIRH)/insertPlate.h  \
             $(INCDIRA)/KGroup.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRA)/NList.h  \
             $(INCDIRA)/NRange.h $(INCDIRa)/Object.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRl)/pointTally.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRA)/Simulation.h $(INCDIRA)/Source.h  \
             $(INCDIRQ)/Surface.h $(INCDIRl)/surfaceTally.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRl)/Tally.h  \
             $(INCDIRl)/TallyCreate.h $(INCDIRQ)/Transform.h  \
             $(INCDIRA)/Triple.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRP) -I$(INCDIRA) \
               -I$(INCDIRQ) -I$(INCDIRV) -I$(INCDIRa) -I$(INCDIRl) \
               -I$(INCDIRB) -I$(INCDIRH) -I$(INCDIRk) -I$(INCDIRW) \
               -I$(INCDIRR) $(INCBOOST) $(SRCDIR)/LensTally.cxx

ProtonFlight.o: $(SRCDIR)/ProtonFlight.cxx $(INCDIRV)/ProtonFlight.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRB)/ContainedGroup.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRe)/generateSurf.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRA)/KGroup.h  \
             $(INCDIRB)/LinearComp.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRA)/NList.h $(INCDIRA)/NRange.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRA)/Simulation.h  \
             $(INCDIRA)/Source.h $(INCDIRA)/SrcData.h  \
             $(INCDIRA)/SrcItem.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRe)/surfDIter.h  \
             $(INCDIRe)/surfDivide.h $(INCDIRe)/surfEqual.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRA)/Triple.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRP) -I$(INCDIRA) \
               -I$(INCDIRQ) -I$(INCDIRV) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/ProtonFlight.cxx

candleStick.o: $(SRCDIR)/candleStick.cxx $(INCDIRV)/candleStick.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRQ)/Line.h $(INCDIRa)/LineIntersectVisit.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRV)/siModerator.h  \
             $(INCDIRe)/SimProcess.h $(INCDIRA)/Simulation.h  \
             $(INCDIRQ)/Sphere.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfEqual.h $(INCDIRe)/surfExpand.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h  \
             $(INCDIRe)/Wrapper.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRA) -I$(INCDIRP) \
               -I$(INCDIRQ) -I$(INCDIRV) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/candleStick.cxx

layers.o: $(SRCDIR)/layers.cxx $(INCDIRV)/layers.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRe)/boxValues.h $(INCDIRV)/candleStick.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRB)/ContainedGroup.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRV)/FlightCluster.h  \
             $(INCDIRH)/FlightLine.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRe)/generateSurf.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRQ)/Line.h  \
             $(INCDIRB)/LinearComp.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRe)/MaterialSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRe)/ModelSupport.h  \
             $(INCDIRW)/NameStack.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRV)/ProtonFlight.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRV)/siModerator.h  \
             $(INCDIRe)/SimProcess.h $(INCDIRA)/Simulation.h  \
             $(INCDIRQ)/Sphere.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfDIter.h $(INCDIRe)/surfEqual.h  \
             $(INCDIRe)/surfExpand.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRQ)/SurInter.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h  \
             $(INCDIRe)/Wrapper.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRA) -I$(INCDIRP) \
               -I$(INCDIRQ) -I$(INCDIRV) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRH) -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/layers.cxx

lensFL.o: $(SRCDIR)/lensFL.cxx $(INCDIRV)/lensFL.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRB)/ContainedComp.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRQ)/Line.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRQ)/SurInter.h  \
             $(INCDIRk)/Tensor.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRQ) -I$(INCDIRV) \
               -I$(INCDIRa) -I$(INCDIRB) -I$(INCDIRk) -I$(INCDIRW) \
               -I$(INCDIRR) $(INCBOOST) $(SRCDIR)/lensFL.cxx

lensVariables.o: $(SRCDIR)/lensVariables.cxx                         \
             $(INCDIRP)/Code.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRF)/variableSetup.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRF) -I$(INCDIRP) -I$(INCDIRQ) \
               -I$(INCDIRk) -I$(INCDIRW) $(INCBOOST) \
               $(SRCDIR)/lensVariables.cxx

makeLens.o: $(SRCDIR)/makeLens.cxx $(INCDIRV)/makeLens.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRV)/candleStick.h $(INCDIRP)/Code.h  \
             $(INCDIRB)/ContainedComp.h $(INCDIRB)/ContainedGroup.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRV)/FlightCluster.h  \
             $(INCDIRH)/FlightLine.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRT)/inputParam.h $(INCDIRG)/insertBaseInfo.h  \
             $(INCDIRB)/InsertComp.h $(INCDIRF)/insertInfo.h  \
             $(INCDIRA)/KCode.h $(INCDIRA)/KGroup.h  \
             $(INCDIRV)/layers.h $(INCDIRV)/LensSource.h  \
             $(INCDIRV)/LensTally.h $(INCDIRB)/LinearComp.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRc)/LSwitchCard.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRc)/ModeCard.h $(INCDIRW)/NameStack.h  \
             $(INCDIRA)/NList.h $(INCDIRA)/NRange.h  \
             $(INCDIRa)/Object.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRc)/PhysCard.h $(INCDIRc)/PhysicsCards.h  \
             $(INCDIRc)/PhysImp.h $(INCDIRV)/ProtonFlight.h  \
             $(INCDIRa)/Qhull.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRV)/siModerator.h  \
             $(INCDIRA)/Simulation.h $(INCDIRA)/Source.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRA)/Triple.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRT) -I$(INCDIRF) \
               -I$(INCDIRP) -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRc) \
               -I$(INCDIRV) -I$(INCDIRa) -I$(INCDIRB) -I$(INCDIRH) \
               -I$(INCDIRG) -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/makeLens.cxx

outerConstruct.o: $(SRCDIR)/outerConstruct.cxx $(INCDIRV)/outerConstruct.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRP)/FItem.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRA)/KGroup.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRA)/NList.h  \
             $(INCDIRA)/NRange.h $(INCDIRa)/Object.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRa)/Qhull.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRe)/SimProcess.h $(INCDIRA)/Simulation.h  \
             $(INCDIRA)/Source.h $(INCDIRA)/Triple.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRP) -I$(INCDIRA) \
               -I$(INCDIRQ) -I$(INCDIRV) -I$(INCDIRa) -I$(INCDIRk) \
               -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/outerConstruct.cxx

siModerator.o: $(SRCDIR)/siModerator.cxx $(INCDIRV)/siModerator.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRA)/KGroup.h $(INCDIRQ)/Line.h  \
             $(INCDIRa)/LineIntersectVisit.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRA)/NList.h $(INCDIRA)/NRange.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRA)/Simulation.h  \
             $(INCDIRA)/Source.h $(INCDIRQ)/Sphere.h  \
             $(INCDIRQ)/Surface.h $(INCDIRe)/surfEqual.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRA)/Triple.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRP) -I$(INCDIRA) \
               -I$(INCDIRQ) -I$(INCDIRV) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/siModerator.cxx

words: 
	grep -v -e '^[[:space:][:cntrl:]]*$$' $(ASRC) | wc 

loc: 
	sloccount $(ASRC) 

cccc: 
	cccc $(ASRC) 

clean:
	rm $(ODEP)

tar:
	tar -zcvf lensModel.tgz $(ASRC) Doxyfile Makefile getMk.pl getMake.pmtar:
	tar -zcvf lensModel_core.tgz $(CORESRC) getMk.pl getMake.pm
cost:
	sloccount $(ASRC) Doxyfile Makefile getMk.pl getMake.pm
doxygen:
	(cat Doxyfile; echo "INPUT= $(ASRC)" ) | doxygen -

