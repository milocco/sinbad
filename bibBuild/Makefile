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

CSRC = BeFilter.cxx bilbauVariables.cxx BilReflector.cxx \
            BWaterPipe.cxx ColdH2Mod.cxx ConcreteWall.cxx \
            FilterBox.cxx GuideBox.cxx GuideShield.cxx \
            makeBib.cxx NiGuide.cxx ProtonPipe.cxx RotorWheel.cxx \
            WaterMod.cxx 

FSRC = 

CINC = 

FINC = 

ODEP = BeFilter.o bilbauVariables.o BilReflector.o BWaterPipe.o \
            ColdH2Mod.o ConcreteWall.o FilterBox.o GuideBox.o \
            GuideShield.o makeBib.o NiGuide.o ProtonPipe.o \
            RotorWheel.o WaterMod.o 

all: $(LIBOUTDIR)/libBibBuild.so 

$(LIBOUTDIR)/libBibBuild.so : $(ODEP) 
	$(CCOMPL) -fPIC -shared -g  -o $(LIBOUTDIR)/libBibBuild.so \
       $(ODEP) 

BWaterPipe.o: $(SRCDIR)/BWaterPipe.cxx $(INCDIRD)/BWaterPipe.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRW)/Debug.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRe)/PipeLine.h  \
             $(INCDIRe)/pipeUnit.h $(INCDIRQ)/Plane.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRA)/Simulation.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRA) -I$(INCDIRP) -I$(INCDIRk) -I$(INCDIRQ) \
               -I$(INCDIRW) -I$(INCDIRR) -I$(INCDIRD) $(INCBOOST) \
               $(SRCDIR)/BWaterPipe.cxx

BeFilter.o: $(SRCDIR)/BeFilter.cxx $(INCDIRD)/BeFilter.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRB)/ContainedGroup.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRA) -I$(INCDIRP) -I$(INCDIRk) -I$(INCDIRQ) \
               -I$(INCDIRW) -I$(INCDIRR) -I$(INCDIRD) $(INCBOOST) \
               $(SRCDIR)/BeFilter.cxx

BilReflector.o: $(SRCDIR)/BilReflector.cxx $(INCDIRD)/BilReflector.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRB)/ContainedGroup.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRe)/generateSurf.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRT)/inputParam.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRA)/masterRotate.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRA)/ReadFunctions.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfDIter.h $(INCDIRe)/surfDivide.h  \
             $(INCDIRe)/surfEqual.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRT) -I$(INCDIRa) \
               -I$(INCDIRB) -I$(INCDIRP) -I$(INCDIRA) -I$(INCDIRk) \
               -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) -I$(INCDIRD) \
               $(INCBOOST) $(SRCDIR)/BilReflector.cxx

ColdH2Mod.o: $(SRCDIR)/ColdH2Mod.cxx $(INCDIRD)/ColdH2Mod.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRB)/ContainedGroup.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRA) -I$(INCDIRP) -I$(INCDIRk) -I$(INCDIRQ) \
               -I$(INCDIRW) -I$(INCDIRR) -I$(INCDIRD) $(INCBOOST) \
               $(SRCDIR)/ColdH2Mod.cxx

ConcreteWall.o: $(SRCDIR)/ConcreteWall.cxx $(INCDIRD)/ConcreteWall.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRB)/ContainedGroup.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRH)/FlightLine.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRT)/inputParam.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRQ)/localRotate.h $(INCDIRA)/masterRotate.h  \
             $(INCDIRe)/MaterialSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRe)/ModelSupport.h  \
             $(INCDIRW)/NameStack.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRA)/ReadFunctions.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRA)/Simulation.h  \
             $(INCDIRk)/stringCombine.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRZ)/VacVessel.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h  \
             $(INCDIRs)/World.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRZ) -I$(INCDIRe) -I$(INCDIRT) \
               -I$(INCDIRa) -I$(INCDIRB) -I$(INCDIRH) -I$(INCDIRP) \
               -I$(INCDIRA) -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRs) \
               -I$(INCDIRW) -I$(INCDIRR) -I$(INCDIRD) $(INCBOOST) \
               $(SRCDIR)/ConcreteWall.cxx

FilterBox.o: $(SRCDIR)/FilterBox.cxx $(INCDIRD)/FilterBox.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRB)/ContainedGroup.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRA) -I$(INCDIRP) -I$(INCDIRk) -I$(INCDIRQ) \
               -I$(INCDIRW) -I$(INCDIRR) -I$(INCDIRD) $(INCBOOST) \
               $(SRCDIR)/FilterBox.cxx

GuideBox.o: $(SRCDIR)/GuideBox.cxx $(INCDIRD)/GuideBox.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRB)/ContainedGroup.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRA) -I$(INCDIRP) -I$(INCDIRk) -I$(INCDIRQ) \
               -I$(INCDIRW) -I$(INCDIRR) -I$(INCDIRD) $(INCBOOST) \
               $(SRCDIR)/GuideBox.cxx

GuideShield.o: $(SRCDIR)/GuideShield.cxx $(INCDIRD)/GuideShield.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRF)/chipDataStore.h $(INCDIRP)/Code.h  \
             $(INCDIRB)/ContainedComp.h $(INCDIRB)/ContainedGroup.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRT)/inputParam.h $(INCDIRQ)/Line.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRA)/masterRotate.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRA)/ReadFunctions.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfDIter.h $(INCDIRe)/surfDivide.h  \
             $(INCDIRe)/surfEqual.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h $(INCDIRs)/World.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRT) -I$(INCDIRa) \
               -I$(INCDIRB) -I$(INCDIRF) -I$(INCDIRP) -I$(INCDIRA) \
               -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRs) -I$(INCDIRW) \
               -I$(INCDIRR) -I$(INCDIRD) $(INCBOOST) \
               $(SRCDIR)/GuideShield.cxx

NiGuide.o: $(SRCDIR)/NiGuide.cxx $(INCDIRD)/NiGuide.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRB)/ContainedGroup.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRA) -I$(INCDIRP) -I$(INCDIRk) -I$(INCDIRQ) \
               -I$(INCDIRW) -I$(INCDIRR) -I$(INCDIRD) $(INCBOOST) \
               $(SRCDIR)/NiGuide.cxx

ProtonPipe.o: $(SRCDIR)/ProtonPipe.cxx $(INCDIRD)/ProtonPipe.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRB)/ContainedGroup.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRA) -I$(INCDIRP) -I$(INCDIRk) -I$(INCDIRQ) \
               -I$(INCDIRW) -I$(INCDIRR) -I$(INCDIRD) $(INCBOOST) \
               $(SRCDIR)/ProtonPipe.cxx

RotorWheel.o: $(SRCDIR)/RotorWheel.cxx $(INCDIRD)/RotorWheel.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRB)/ContainedGroup.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRA) -I$(INCDIRP) -I$(INCDIRk) -I$(INCDIRQ) \
               -I$(INCDIRW) -I$(INCDIRR) -I$(INCDIRD) $(INCBOOST) \
               $(SRCDIR)/RotorWheel.cxx

WaterMod.o: $(SRCDIR)/WaterMod.cxx $(INCDIRD)/WaterMod.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRB)/ContainedGroup.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRA) -I$(INCDIRP) -I$(INCDIRk) -I$(INCDIRQ) \
               -I$(INCDIRW) -I$(INCDIRR) -I$(INCDIRD) $(INCBOOST) \
               $(SRCDIR)/WaterMod.cxx

bilbauVariables.o: $(SRCDIR)/bilbauVariables.cxx                         \
             $(INCDIRP)/Code.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRF)/variableSetup.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRF) -I$(INCDIRP) -I$(INCDIRk) \
               -I$(INCDIRQ) -I$(INCDIRW) $(INCBOOST) \
               $(SRCDIR)/bilbauVariables.cxx

makeBib.o: $(SRCDIR)/makeBib.cxx $(INCDIRD)/makeBib.h \
             $(INCDIRB)/AttachSupport.h $(INCDIRR)/BaseModVisit.h  \
             $(INCDIRR)/BaseVisit.h $(INCDIRD)/BilReflector.h  \
             $(INCDIRP)/Code.h $(INCDIRD)/ColdH2Mod.h  \
             $(INCDIRD)/ConcreteWall.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRB)/ContainedGroup.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRD)/FilterBox.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRH)/FlightLine.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRD)/GuideBox.h $(INCDIRD)/GuideShield.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRT)/inputParam.h  \
             $(INCDIRG)/insertBaseInfo.h $(INCDIRB)/InsertComp.h  \
             $(INCDIRF)/insertInfo.h $(INCDIRB)/LayerComp.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRD)/NiGuide.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRD)/ProtonPipe.h $(INCDIRa)/Qhull.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRD)/RotorWheel.h  \
             $(INCDIRa)/Rules.h $(INCDIRA)/Simulation.h  \
             $(INCDIRk)/stringCombine.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h $(INCDIRD)/WaterMod.h  \
             $(INCDIRs)/World.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRT) \
               -I$(INCDIRB) -I$(INCDIRF) -I$(INCDIRH) -I$(INCDIRA) \
               -I$(INCDIRP) -I$(INCDIRG) -I$(INCDIRk) -I$(INCDIRQ) \
               -I$(INCDIRs) -I$(INCDIRW) -I$(INCDIRR) -I$(INCDIRD) \
               $(INCBOOST) $(SRCDIR)/makeBib.cxx

words: 
	grep -v -e '^[[:space:][:cntrl:]]*$$' $(ASRC) | wc 

loc: 
	sloccount $(ASRC) 

cccc: 
	cccc $(ASRC) 

clean:
	rm $(ODEP)

tar:
	tar -zcvf bibBuild.tgz $(ASRC) Doxyfile Makefile getMk.pl getMake.pmtar:
	tar -zcvf bibBuild_core.tgz $(CORESRC) getMk.pl getMake.pm
cost:
	sloccount $(ASRC) Doxyfile Makefile getMk.pl getMake.pm
doxygen:
	(cat Doxyfile; echo "INPUT= $(ASRC)" ) | doxygen -

