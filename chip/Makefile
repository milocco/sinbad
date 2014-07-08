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

CSRC = beamBlock.cxx BeamStop.cxx ChipIRFilter.cxx \
            ChipIRGuide.cxx ChipIRInsert.cxx \
            ChipIRShutterFlat.cxx ChipSample.cxx \
            ChipVariables.cxx ColBox.cxx Collimator.cxx \
            CylinderColl.cxx cylTrack.cxx FBBlock.cxx \
            FeedThrough.cxx HoleUnit.cxx Hutch.cxx InnerWall.cxx \
            insertBaseInfo.cxx LeadPlate.cxx makeChipIR.cxx \
            PreCollimator.cxx ScatterPlate.cxx Table.cxx 

FSRC = 

CINC = 

FINC = 

ODEP = beamBlock.o BeamStop.o ChipIRFilter.o ChipIRGuide.o \
            ChipIRInsert.o ChipIRShutterFlat.o ChipSample.o \
            ChipVariables.o ColBox.o Collimator.o CylinderColl.o \
            cylTrack.o FBBlock.o FeedThrough.o HoleUnit.o Hutch.o \
            InnerWall.o insertBaseInfo.o LeadPlate.o makeChipIR.o \
            PreCollimator.o ScatterPlate.o Table.o 

all: $(LIBOUTDIR)/libChip.so 

$(LIBOUTDIR)/libChip.so : $(ODEP) 
	$(CCOMPL) -fPIC -shared -g  -o $(LIBOUTDIR)/libChip.so \
       $(ODEP) 

BeamStop.o: $(SRCDIR)/BeamStop.cxx $(INCDIRG)/BeamStop.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRG)/beamBlock.h $(INCDIRF)/chipDataStore.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRA)/masterRotate.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRA)/ReadFunctions.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRe)/SimProcess.h $(INCDIRA)/Simulation.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfEqual.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRF) -I$(INCDIRP) -I$(INCDIRA) -I$(INCDIRG) \
               -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/BeamStop.cxx

ChipIRFilter.o: $(SRCDIR)/ChipIRFilter.cxx $(INCDIRG)/ChipIRFilter.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRF)/chipDataStore.h $(INCDIRP)/Code.h  \
             $(INCDIRB)/ContainedComp.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRe)/generateSurf.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRB)/LinearComp.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRA)/masterRotate.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRA)/Simulation.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfDIter.h $(INCDIRe)/surfDivide.h  \
             $(INCDIRe)/surfEqual.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRF) -I$(INCDIRP) -I$(INCDIRA) -I$(INCDIRG) \
               -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/ChipIRFilter.cxx

ChipIRGuide.o: $(SRCDIR)/ChipIRGuide.cxx $(INCDIRG)/ChipIRGuide.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRF)/BulkShield.h $(INCDIRF)/chipDataStore.h  \
             $(INCDIRG)/ChipIRFilter.h $(INCDIRP)/Code.h  \
             $(INCDIRB)/ContainedComp.h $(INCDIRB)/ContainedGroup.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRF)/GeneralShutter.h  \
             $(INCDIRe)/generateSurf.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRB)/InsertComp.h  \
             $(INCDIRB)/LinearComp.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRQ)/localRotate.h $(INCDIRA)/masterRotate.h  \
             $(INCDIRe)/MaterialSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRe)/ModelSupport.h  \
             $(INCDIRW)/NameStack.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRG)/ScatterPlate.h $(INCDIRB)/SecondTrack.h  \
             $(INCDIRF)/shutterBlock.h $(INCDIRA)/Simulation.h  \
             $(INCDIRk)/stringCombine.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRe)/surfDIter.h  \
             $(INCDIRe)/surfDivide.h $(INCDIRe)/surfEqual.h  \
             $(INCDIRQ)/surfFunctors.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRQ)/SurInter.h  \
             $(INCDIRB)/TwinComp.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRF) -I$(INCDIRP) -I$(INCDIRA) -I$(INCDIRG) \
               -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/ChipIRGuide.cxx

ChipIRInsert.o: $(SRCDIR)/ChipIRInsert.cxx $(INCDIRG)/ChipIRInsert.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRF)/BulkInsert.h $(INCDIRF)/chipDataStore.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRB)/ContainedGroup.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRG)/CylinderColl.h $(INCDIRG)/cylTrack.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRF)/GeneralShutter.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRB)/InsertComp.h $(INCDIRG)/LeadPlate.h  \
             $(INCDIRQ)/Line.h $(INCDIRa)/LineIntersectVisit.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRA)/masterRotate.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRB)/SecondTrack.h  \
             $(INCDIRF)/shutterBlock.h $(INCDIRe)/SimProcess.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRe)/surfDIter.h  \
             $(INCDIRe)/surfDivide.h $(INCDIRe)/surfEqual.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRQ)/SurInter.h $(INCDIRB)/TwinComp.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRF) -I$(INCDIRP) -I$(INCDIRA) -I$(INCDIRG) \
               -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/ChipIRInsert.cxx

ChipIRShutterFlat.o: $(SRCDIR)/ChipIRShutterFlat.cxx $(INCDIRG)/ChipIRShutterFlat.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRF)/chipDataStore.h $(INCDIRP)/Code.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRF)/GeneralShutter.h  \
             $(INCDIRe)/generateSurf.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRG)/insertBaseInfo.h  \
             $(INCDIRB)/InsertComp.h $(INCDIRF)/insertInfo.h  \
             $(INCDIRQ)/Line.h $(INCDIRa)/LineIntersectVisit.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRA)/masterRotate.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRQ)/PointOperation.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRB)/SecondTrack.h $(INCDIRF)/shutterBlock.h  \
             $(INCDIRe)/SimProcess.h $(INCDIRA)/Simulation.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRQ)/SurInter.h $(INCDIRB)/TwinComp.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRF) -I$(INCDIRP) -I$(INCDIRA) -I$(INCDIRG) \
               -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/ChipIRShutterFlat.cxx

ChipSample.o: $(SRCDIR)/ChipSample.cxx $(INCDIRG)/ChipSample.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRF)/chipDataStore.h $(INCDIRP)/Code.h  \
             $(INCDIRB)/ContainedComp.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRA)/Simulation.h  \
             $(INCDIRk)/stringCombine.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRe)/surfEqual.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRA)/Triple.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRF) -I$(INCDIRP) -I$(INCDIRA) -I$(INCDIRG) \
               -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/ChipSample.cxx

ChipVariables.o: $(SRCDIR)/ChipVariables.cxx                         \
             $(INCDIRP)/Code.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRF)/variableSetup.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRF) -I$(INCDIRP) -I$(INCDIRk) \
               -I$(INCDIRQ) -I$(INCDIRW) $(INCBOOST) \
               $(SRCDIR)/ChipVariables.cxx

ColBox.o: $(SRCDIR)/ColBox.cxx $(INCDIRG)/ColBox.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRB)/SecondTrack.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRe)/surfEqual.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRB)/TwinComp.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRA) -I$(INCDIRP) -I$(INCDIRG) -I$(INCDIRk) \
               -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/ColBox.cxx

Collimator.o: $(SRCDIR)/Collimator.cxx $(INCDIRG)/Collimator.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRA)/masterRotate.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRB)/SecondTrack.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRe)/surfDIter.h  \
             $(INCDIRe)/surfDivide.h $(INCDIRe)/surfEqual.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRB)/TwinComp.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRP) -I$(INCDIRA) -I$(INCDIRG) -I$(INCDIRk) \
               -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/Collimator.cxx

CylinderColl.o: $(SRCDIR)/CylinderColl.cxx $(INCDIRG)/CylinderColl.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRQ)/Convex.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRG)/cylTrack.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRG)/insertBaseInfo.h $(INCDIRF)/insertInfo.h  \
             $(INCDIRA)/KGroup.h $(INCDIRQ)/Line.h  \
             $(INCDIRa)/LineIntersectVisit.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRQ)/localRotate.h $(INCDIRA)/masterRotate.h  \
             $(INCDIRe)/MaterialSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRe)/ModelSupport.h  \
             $(INCDIRW)/NameStack.h $(INCDIRA)/NList.h  \
             $(INCDIRA)/NRange.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRQ)/PointOperation.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRB)/SecondTrack.h  \
             $(INCDIRF)/shutterBlock.h $(INCDIRe)/SimProcess.h  \
             $(INCDIRA)/Simulation.h $(INCDIRA)/Source.h  \
             $(INCDIRk)/stringCombine.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRe)/surfDIter.h  \
             $(INCDIRe)/surfDivide.h $(INCDIRe)/surfEqual.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRQ)/SurInter.h $(INCDIRk)/Tensor.h  \
             $(INCDIRA)/Triple.h $(INCDIRB)/TwinComp.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRF) -I$(INCDIRP) -I$(INCDIRA) -I$(INCDIRG) \
               -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/CylinderColl.cxx

FBBlock.o: $(SRCDIR)/FBBlock.cxx $(INCDIRG)/FBBlock.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRG)/beamBlock.h $(INCDIRG)/BeamStop.h  \
             $(INCDIRe)/BoxLine.h $(INCDIRe)/boxUnit.h  \
             $(INCDIRe)/boxValues.h $(INCDIRF)/chipDataStore.h  \
             $(INCDIRP)/Code.h $(INCDIRG)/ColBox.h  \
             $(INCDIRG)/Collimator.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRW)/Debug.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRG)/HoleUnit.h $(INCDIRG)/Hutch.h  \
             $(INCDIRG)/InnerWall.h $(INCDIRA)/KGroup.h  \
             $(INCDIRQ)/Line.h $(INCDIRB)/LinearComp.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRA)/masterRotate.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRA)/NList.h $(INCDIRA)/NRange.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRG)/PreCollimator.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRB)/SecondTrack.h $(INCDIRe)/SimProcess.h  \
             $(INCDIRA)/Simulation.h $(INCDIRA)/Source.h  \
             $(INCDIRk)/stringCombine.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRe)/surfDIter.h  \
             $(INCDIRe)/surfDivide.h $(INCDIRe)/surfEqual.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRG)/Table.h $(INCDIRl)/Tally.h  \
             $(INCDIRA)/Triple.h $(INCDIRB)/TwinComp.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRl) \
               -I$(INCDIRB) -I$(INCDIRF) -I$(INCDIRP) -I$(INCDIRA) \
               -I$(INCDIRG) -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRW) \
               -I$(INCDIRR) $(INCBOOST) $(SRCDIR)/FBBlock.cxx

FeedThrough.o: $(SRCDIR)/FeedThrough.cxx $(INCDIRG)/FeedThrough.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRG)/beamBlock.h $(INCDIRG)/BeamStop.h  \
             $(INCDIRe)/BoxLine.h $(INCDIRe)/boxUnit.h  \
             $(INCDIRe)/boxValues.h $(INCDIRF)/chipDataStore.h  \
             $(INCDIRP)/Code.h $(INCDIRG)/ColBox.h  \
             $(INCDIRG)/Collimator.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRW)/debugMethod.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRG)/HoleUnit.h $(INCDIRG)/Hutch.h  \
             $(INCDIRG)/InnerWall.h $(INCDIRA)/KGroup.h  \
             $(INCDIRQ)/Line.h $(INCDIRB)/LinearComp.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRA)/masterRotate.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRe)/ModelSupport.h  \
             $(INCDIRW)/NameStack.h $(INCDIRA)/NList.h  \
             $(INCDIRA)/NRange.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRG)/PreCollimator.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRB)/SecondTrack.h  \
             $(INCDIRe)/SimProcess.h $(INCDIRA)/Simulation.h  \
             $(INCDIRA)/Source.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfDIter.h $(INCDIRe)/surfDivide.h  \
             $(INCDIRe)/surfEqual.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRG)/Table.h  \
             $(INCDIRl)/Tally.h $(INCDIRA)/Triple.h  \
             $(INCDIRB)/TwinComp.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRl) \
               -I$(INCDIRB) -I$(INCDIRF) -I$(INCDIRP) -I$(INCDIRA) \
               -I$(INCDIRG) -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRW) \
               -I$(INCDIRR) $(INCBOOST) $(SRCDIR)/FeedThrough.cxx

HoleUnit.o: $(SRCDIR)/HoleUnit.cxx $(INCDIRG)/HoleUnit.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRF)/chipDataStore.h $(INCDIRP)/Code.h  \
             $(INCDIRB)/ContainedComp.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRQ)/Line.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRQ)/localRotate.h $(INCDIRA)/masterRotate.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRA)/NList.h $(INCDIRA)/NRange.h  \
             $(INCDIRa)/Object.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRB)/SecondTrack.h $(INCDIRA)/Simulation.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfDIter.h $(INCDIRe)/surfDivide.h  \
             $(INCDIRe)/surfEqual.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRl)/Tally.h  \
             $(INCDIRA)/Triple.h $(INCDIRB)/TwinComp.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRl) \
               -I$(INCDIRB) -I$(INCDIRF) -I$(INCDIRP) -I$(INCDIRA) \
               -I$(INCDIRG) -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRW) \
               -I$(INCDIRR) $(INCBOOST) $(SRCDIR)/HoleUnit.cxx

Hutch.o: $(SRCDIR)/Hutch.cxx $(INCDIRG)/Hutch.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRG)/beamBlock.h $(INCDIRG)/BeamStop.h  \
             $(INCDIRF)/chipDataStore.h $(INCDIRG)/ChipSample.h  \
             $(INCDIRP)/Code.h $(INCDIRG)/ColBox.h  \
             $(INCDIRG)/Collimator.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRe)/createDivide.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRF)/GeneralShutter.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRG)/HoleUnit.h $(INCDIRG)/InnerWall.h  \
             $(INCDIRB)/InsertComp.h $(INCDIRQ)/Line.h  \
             $(INCDIRB)/LinearComp.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRQ)/localRotate.h $(INCDIRA)/masterRotate.h  \
             $(INCDIRe)/MaterialSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRe)/ModelSupport.h  \
             $(INCDIRW)/NameStack.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRG)/PreCollimator.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRB)/SecondTrack.h  \
             $(INCDIRF)/shutterBlock.h $(INCDIRe)/SimProcess.h  \
             $(INCDIRA)/Simulation.h $(INCDIRe)/SpecialSurf.h  \
             $(INCDIRk)/stringCombine.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRe)/surfDIter.h  \
             $(INCDIRe)/surfDivide.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRQ)/SurInter.h  \
             $(INCDIRG)/Table.h $(INCDIRB)/TwinComp.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRF) -I$(INCDIRP) -I$(INCDIRA) -I$(INCDIRG) \
               -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/Hutch.cxx

InnerWall.o: $(SRCDIR)/InnerWall.cxx $(INCDIRG)/InnerWall.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRF)/chipDataStore.h $(INCDIRP)/Code.h  \
             $(INCDIRB)/ContainedComp.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRe)/generateSurf.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRQ)/Line.h  \
             $(INCDIRB)/LinearComp.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRQ)/localRotate.h $(INCDIRA)/masterRotate.h  \
             $(INCDIRe)/MaterialSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRe)/ModelSupport.h  \
             $(INCDIRW)/NameStack.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRe)/surfDIter.h  \
             $(INCDIRe)/surfDivide.h $(INCDIRe)/surfEqual.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRF) -I$(INCDIRP) -I$(INCDIRA) -I$(INCDIRG) \
               -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/InnerWall.cxx

LeadPlate.o: $(SRCDIR)/LeadPlate.cxx $(INCDIRG)/LeadPlate.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRQ)/Line.h $(INCDIRa)/LineIntersectVisit.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRA)/masterRotate.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRA)/NList.h $(INCDIRA)/NRange.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRB)/SecondTrack.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRe)/surfDIter.h  \
             $(INCDIRe)/surfDivide.h $(INCDIRe)/surfEqual.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRQ)/SurInter.h $(INCDIRl)/Tally.h  \
             $(INCDIRA)/Triple.h $(INCDIRH)/tubeUnit.h  \
             $(INCDIRB)/TwinComp.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRl) \
               -I$(INCDIRB) -I$(INCDIRH) -I$(INCDIRP) -I$(INCDIRA) \
               -I$(INCDIRG) -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRW) \
               -I$(INCDIRR) $(INCBOOST) $(SRCDIR)/LeadPlate.cxx

PreCollimator.o: $(SRCDIR)/PreCollimator.cxx $(INCDIRG)/PreCollimator.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRF)/chipDataStore.h $(INCDIRP)/Code.h  \
             $(INCDIRB)/ContainedComp.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRe)/generateSurf.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRG)/HoleUnit.h  \
             $(INCDIRQ)/Line.h $(INCDIRB)/LinearComp.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRA)/masterRotate.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRB)/SecondTrack.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRe)/surfDIter.h  \
             $(INCDIRe)/surfDivide.h $(INCDIRe)/surfEqual.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRB)/TwinComp.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRF) -I$(INCDIRP) -I$(INCDIRA) -I$(INCDIRG) \
               -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/PreCollimator.cxx

ScatterPlate.o: $(SRCDIR)/ScatterPlate.cxx $(INCDIRG)/ScatterPlate.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRF)/chipDataStore.h $(INCDIRP)/Code.h  \
             $(INCDIRB)/ContainedComp.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRe)/generateSurf.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRQ)/Line.h  \
             $(INCDIRB)/LinearComp.h $(INCDIRa)/LineIntersectVisit.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRA)/masterRotate.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRA)/NList.h $(INCDIRA)/NRange.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRA)/Simulation.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfDIter.h $(INCDIRe)/surfDivide.h  \
             $(INCDIRe)/surfEqual.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRl)/Tally.h  \
             $(INCDIRA)/Triple.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRl) \
               -I$(INCDIRB) -I$(INCDIRF) -I$(INCDIRP) -I$(INCDIRA) \
               -I$(INCDIRG) -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRW) \
               -I$(INCDIRR) $(INCBOOST) $(SRCDIR)/ScatterPlate.cxx

Table.o: $(SRCDIR)/Table.cxx $(INCDIRG)/Table.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRF)/chipDataStore.h $(INCDIRP)/Code.h  \
             $(INCDIRB)/ContainedComp.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRe)/generateSurf.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRQ)/Line.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRA)/masterRotate.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRA)/NList.h $(INCDIRA)/NRange.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRB)/SecondTrack.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRe)/surfDIter.h  \
             $(INCDIRe)/surfDivide.h $(INCDIRe)/surfEqual.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRl)/Tally.h $(INCDIRA)/Triple.h  \
             $(INCDIRB)/TwinComp.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRl) \
               -I$(INCDIRB) -I$(INCDIRF) -I$(INCDIRP) -I$(INCDIRA) \
               -I$(INCDIRG) -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRW) \
               -I$(INCDIRR) $(INCBOOST) $(SRCDIR)/Table.cxx

beamBlock.o: $(SRCDIR)/beamBlock.cxx $(INCDIRG)/beamBlock.h \
             $(INCDIRP)/Code.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRP)/FItem.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRk)/stringCombine.h $(INCDIRk)/support.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRP) \
               -I$(INCDIRG) -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRW) \
               $(SRCDIR)/beamBlock.cxx

cylTrack.o: $(SRCDIR)/cylTrack.cxx $(INCDIRG)/cylTrack.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRk)/Tensor.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRG) -I$(INCDIRk) -I$(INCDIRQ) \
               -I$(INCDIRW) -I$(INCDIRR) $(SRCDIR)/cylTrack.cxx

insertBaseInfo.o: $(SRCDIR)/insertBaseInfo.cxx $(INCDIRG)/insertBaseInfo.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRF)/insertInfo.h  \
             $(INCDIRQ)/Line.h $(INCDIRa)/LineIntersectVisit.h  \
             $(INCDIRe)/MaterialSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRe)/SimProcess.h $(INCDIRA)/Simulation.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/surfFunctors.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRQ)/SurInter.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRF) \
               -I$(INCDIRA) -I$(INCDIRP) -I$(INCDIRG) -I$(INCDIRk) \
               -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/insertBaseInfo.cxx

makeChipIR.o: $(SRCDIR)/makeChipIR.cxx $(INCDIRG)/makeChipIR.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRG)/beamBlock.h $(INCDIRG)/BeamStop.h  \
             $(INCDIRe)/BoxLine.h $(INCDIRe)/boxUnit.h  \
             $(INCDIRe)/boxValues.h $(INCDIRF)/BulkShield.h  \
             $(INCDIRG)/ChipIRFilter.h $(INCDIRG)/ChipIRGuide.h  \
             $(INCDIRP)/Code.h $(INCDIRG)/ColBox.h  \
             $(INCDIRG)/Collimator.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRB)/ContainedGroup.h $(INCDIRW)/debugMethod.h  \
             $(INCDIRk)/Exception.h $(INCDIRG)/FBBlock.h  \
             $(INCDIRG)/FeedThrough.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRG)/HoleUnit.h $(INCDIRG)/Hutch.h  \
             $(INCDIRG)/InnerWall.h $(INCDIRT)/inputParam.h  \
             $(INCDIRG)/insertBaseInfo.h $(INCDIRB)/InsertComp.h  \
             $(INCDIRF)/insertInfo.h $(INCDIRB)/LinearComp.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRG)/PreCollimator.h  \
             $(INCDIRa)/Qhull.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRB)/SecondTrack.h  \
             $(INCDIRA)/Simulation.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRG)/Table.h $(INCDIRB)/TwinComp.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRT) \
               -I$(INCDIRB) -I$(INCDIRF) -I$(INCDIRA) -I$(INCDIRP) \
               -I$(INCDIRG) -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRW) \
               -I$(INCDIRR) $(INCBOOST) $(SRCDIR)/makeChipIR.cxx

words: 
	grep -v -e '^[[:space:][:cntrl:]]*$$' $(ASRC) | wc 

loc: 
	sloccount $(ASRC) 

cccc: 
	cccc $(ASRC) 

clean:
	rm $(ODEP)

tar:
	tar -zcvf chip.tgz $(ASRC) Doxyfile Makefile getMk.pl getMake.pmtar:
	tar -zcvf chip_core.tgz $(CORESRC) getMk.pl getMake.pm
cost:
	sloccount $(ASRC) Doxyfile Makefile getMk.pl getMake.pm
doxygen:
	(cat Doxyfile; echo "INPUT= $(ASRC)" ) | doxygen -

