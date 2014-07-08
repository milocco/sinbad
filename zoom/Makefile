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

CSRC = makeZoom.cxx ZoomBend.cxx ZoomChopper.cxx \
            ZoomCollimator.cxx ZoomHutch.cxx zoomInsertBase.cxx \
            zoomInsertBlock.cxx zoomInsertCyl.cxx ZoomPrimary.cxx \
            ZoomRoof.cxx ZoomShutter.cxx ZoomStack.cxx \
            ZoomTank.cxx ZoomVariables.cxx 

FSRC = 

CINC = 

FINC = 

ODEP = makeZoom.o ZoomBend.o ZoomChopper.o ZoomCollimator.o \
            ZoomHutch.o zoomInsertBase.o zoomInsertBlock.o \
            zoomInsertCyl.o ZoomPrimary.o ZoomRoof.o \
            ZoomShutter.o ZoomStack.o ZoomTank.o ZoomVariables.o 

all: $(LIBOUTDIR)/libZoom.so 

$(LIBOUTDIR)/libZoom.so : $(ODEP) 
	$(CCOMPL) -fPIC -shared -g  -o $(LIBOUTDIR)/libZoom.so \
       $(ODEP) 

ZoomBend.o: $(SRCDIR)/ZoomBend.cxx $(INCDIRu)/ZoomBend.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRu)/bendSection.h $(INCDIRF)/BulkInsert.h  \
             $(INCDIRF)/BulkShield.h $(INCDIRF)/chipDataStore.h  \
             $(INCDIRP)/Code.h $(INCDIRF)/collInsertBase.h  \
             $(INCDIRF)/collInsertBlock.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRB)/ContainedGroup.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRF)/GeneralShutter.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRB)/InsertComp.h $(INCDIRB)/LinearComp.h  \
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
             $(INCDIRA)/Simulation.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfDIter.h $(INCDIRe)/surfDivide.h  \
             $(INCDIRe)/surfEqual.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRQ)/SurInter.h  \
             $(INCDIRB)/TwinComp.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h $(INCDIRu)/ZoomShutter.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRF) -I$(INCDIRP) \
               -I$(INCDIRA) -I$(INCDIRu) -I$(INCDIRQ) -I$(INCDIRa) \
               -I$(INCDIRB) -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/ZoomBend.cxx

ZoomChopper.o: $(SRCDIR)/ZoomChopper.cxx $(INCDIRu)/ZoomChopper.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRu)/bendSection.h $(INCDIRF)/BulkShield.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRB)/ContainedGroup.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRF)/GeneralShutter.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRB)/InsertComp.h $(INCDIRQ)/Line.h  \
             $(INCDIRB)/LinearComp.h $(INCDIRa)/LineIntersectVisit.h  \
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
             $(INCDIRQ)/surfFunctors.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRQ)/SurInter.h  \
             $(INCDIRB)/TwinComp.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h $(INCDIRu)/ZoomBend.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRF) -I$(INCDIRP) \
               -I$(INCDIRA) -I$(INCDIRu) -I$(INCDIRQ) -I$(INCDIRa) \
               -I$(INCDIRB) -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/ZoomChopper.cxx

ZoomCollimator.o: $(SRCDIR)/ZoomCollimator.cxx $(INCDIRu)/ZoomCollimator.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRB)/ContainedGroup.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRe)/generateSurf.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRQ)/Line.h  \
             $(INCDIRa)/LineIntersectVisit.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRQ)/localRotate.h $(INCDIRA)/masterRotate.h  \
             $(INCDIRe)/MaterialSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRe)/ModelSupport.h  \
             $(INCDIRW)/NameStack.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRB)/SecondTrack.h $(INCDIRe)/SimProcess.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRe)/surfDIter.h  \
             $(INCDIRe)/surfDivide.h $(INCDIRe)/surfEqual.h  \
             $(INCDIRQ)/surfFunctors.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRQ)/SurInter.h  \
             $(INCDIRB)/TwinComp.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h $(INCDIRu)/ZoomChopper.h  \
             $(INCDIRu)/ZoomStack.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRP) -I$(INCDIRA) \
               -I$(INCDIRu) -I$(INCDIRQ) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/ZoomCollimator.cxx

ZoomHutch.o: $(SRCDIR)/ZoomHutch.cxx $(INCDIRu)/ZoomHutch.h \
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
             $(INCDIRB)/SecondTrack.h $(INCDIRA)/Simulation.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfDIter.h $(INCDIRe)/surfDivide.h  \
             $(INCDIRe)/surfEqual.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRB)/TwinComp.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h  \
             $(INCDIRu)/ZoomTank.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRF) -I$(INCDIRP) \
               -I$(INCDIRA) -I$(INCDIRu) -I$(INCDIRQ) -I$(INCDIRa) \
               -I$(INCDIRB) -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/ZoomHutch.cxx

ZoomPrimary.o: $(SRCDIR)/ZoomPrimary.cxx $(INCDIRu)/ZoomPrimary.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRF)/BulkShield.h $(INCDIRG)/ChipIRFilter.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRB)/InsertComp.h $(INCDIRQ)/Line.h  \
             $(INCDIRB)/LinearComp.h $(INCDIRa)/LineIntersectVisit.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRA)/masterRotate.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRB)/SecondTrack.h  \
             $(INCDIRe)/SimProcess.h $(INCDIRA)/Simulation.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfDIter.h $(INCDIRe)/surfDivide.h  \
             $(INCDIRe)/surfEqual.h $(INCDIRQ)/surfFunctors.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRQ)/SurInter.h $(INCDIRB)/TwinComp.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRF) -I$(INCDIRP) \
               -I$(INCDIRA) -I$(INCDIRu) -I$(INCDIRQ) -I$(INCDIRa) \
               -I$(INCDIRB) -I$(INCDIRG) -I$(INCDIRk) -I$(INCDIRW) \
               -I$(INCDIRR) $(INCBOOST) $(SRCDIR)/ZoomPrimary.cxx

ZoomRoof.o: $(SRCDIR)/ZoomRoof.cxx $(INCDIRu)/ZoomRoof.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRu)/bendSection.h $(INCDIRF)/BulkShield.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRB)/ContainedGroup.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRF)/GeneralShutter.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRB)/InsertComp.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRe)/MaterialSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRe)/ModelSupport.h  \
             $(INCDIRW)/NameStack.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRB)/SecondTrack.h $(INCDIRF)/shutterBlock.h  \
             $(INCDIRe)/SimProcess.h $(INCDIRA)/Simulation.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfDIter.h $(INCDIRe)/surfDivide.h  \
             $(INCDIRe)/surfEqual.h $(INCDIRQ)/surfFunctors.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRQ)/SurInter.h $(INCDIRB)/TwinComp.h  \
             $(INCDIRP)/varBlock.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h $(INCDIRu)/ZoomBend.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRF) -I$(INCDIRA) \
               -I$(INCDIRP) -I$(INCDIRu) -I$(INCDIRQ) -I$(INCDIRa) \
               -I$(INCDIRB) -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/ZoomRoof.cxx

ZoomShutter.o: $(SRCDIR)/ZoomShutter.cxx $(INCDIRu)/ZoomShutter.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRF)/collInsertBase.h  \
             $(INCDIRF)/collInsertBlock.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRF)/GeneralShutter.h  \
             $(INCDIRe)/generateSurf.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRB)/InsertComp.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRA)/masterRotate.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRB)/SecondTrack.h  \
             $(INCDIRF)/shutterBlock.h $(INCDIRA)/Simulation.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfDIter.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRB)/TwinComp.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRF) -I$(INCDIRP) \
               -I$(INCDIRA) -I$(INCDIRu) -I$(INCDIRQ) -I$(INCDIRa) \
               -I$(INCDIRB) -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/ZoomShutter.cxx

ZoomStack.o: $(SRCDIR)/ZoomStack.cxx $(INCDIRu)/ZoomStack.h \
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
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRB)/SecondTrack.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfDIter.h $(INCDIRe)/surfDivide.h  \
             $(INCDIRe)/surfEqual.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRB)/TwinComp.h  \
             $(INCDIRP)/varBlock.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRF) -I$(INCDIRP) \
               -I$(INCDIRA) -I$(INCDIRu) -I$(INCDIRQ) -I$(INCDIRa) \
               -I$(INCDIRB) -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/ZoomStack.cxx

ZoomTank.o: $(SRCDIR)/ZoomTank.cxx $(INCDIRu)/ZoomTank.h \
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
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRP) -I$(INCDIRA) \
               -I$(INCDIRu) -I$(INCDIRQ) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/ZoomTank.cxx

ZoomVariables.o: $(SRCDIR)/ZoomVariables.cxx                         \
             $(INCDIRP)/Code.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRT)/inputParam.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRF)/variableSetup.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRT) -I$(INCDIRF) -I$(INCDIRP) \
               -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) $(INCBOOST) \
               $(SRCDIR)/ZoomVariables.cxx

makeZoom.o: $(SRCDIR)/makeZoom.cxx $(INCDIRu)/makeZoom.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRu)/bendSection.h $(INCDIRF)/BulkInsert.h  \
             $(INCDIRF)/BulkShield.h $(INCDIRP)/Code.h  \
             $(INCDIRF)/collInsertBase.h $(INCDIRF)/collInsertBlock.h  \
             $(INCDIRB)/ContainedComp.h $(INCDIRB)/ContainedGroup.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRF)/GeneralShutter.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRT)/inputParam.h  \
             $(INCDIRG)/insertBaseInfo.h $(INCDIRB)/InsertComp.h  \
             $(INCDIRF)/insertInfo.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRa)/Qhull.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRB)/SecondTrack.h  \
             $(INCDIRF)/shutterBlock.h $(INCDIRA)/Simulation.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRB)/TwinComp.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h  \
             $(INCDIRu)/ZoomBend.h $(INCDIRu)/ZoomChopper.h  \
             $(INCDIRu)/ZoomCollimator.h $(INCDIRu)/ZoomHutch.h  \
             $(INCDIRu)/ZoomPrimary.h $(INCDIRu)/ZoomRoof.h  \
             $(INCDIRu)/ZoomShutter.h $(INCDIRu)/ZoomStack.h  \
             $(INCDIRu)/ZoomTank.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRT) -I$(INCDIRF) \
               -I$(INCDIRA) -I$(INCDIRP) -I$(INCDIRu) -I$(INCDIRQ) \
               -I$(INCDIRa) -I$(INCDIRB) -I$(INCDIRG) -I$(INCDIRk) \
               -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/makeZoom.cxx

zoomInsertBase.o: $(SRCDIR)/zoomInsertBase.cxx $(INCDIRu)/zoomInsertBase.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRA)/KGroup.h $(INCDIRB)/LinearComp.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRA)/masterRotate.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRe)/ModelSupport.h  \
             $(INCDIRW)/NameStack.h $(INCDIRA)/NList.h  \
             $(INCDIRA)/NRange.h $(INCDIRa)/Object.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRF)/shutterBlock.h  \
             $(INCDIRA)/Simulation.h $(INCDIRA)/Source.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfDIter.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRA)/Triple.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRF) -I$(INCDIRP) \
               -I$(INCDIRA) -I$(INCDIRu) -I$(INCDIRQ) -I$(INCDIRa) \
               -I$(INCDIRB) -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/zoomInsertBase.cxx

zoomInsertBlock.o: $(SRCDIR)/zoomInsertBlock.cxx $(INCDIRu)/zoomInsertBlock.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRA)/KGroup.h $(INCDIRB)/LinearComp.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRA)/masterRotate.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRe)/ModelSupport.h  \
             $(INCDIRW)/NameStack.h $(INCDIRA)/NList.h  \
             $(INCDIRA)/NRange.h $(INCDIRa)/Object.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRF)/shutterBlock.h  \
             $(INCDIRA)/Simulation.h $(INCDIRA)/Source.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfDIter.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRA)/Triple.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h  \
             $(INCDIRu)/zoomInsertBase.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRF) -I$(INCDIRP) \
               -I$(INCDIRA) -I$(INCDIRu) -I$(INCDIRQ) -I$(INCDIRa) \
               -I$(INCDIRB) -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/zoomInsertBlock.cxx

zoomInsertCyl.o: $(SRCDIR)/zoomInsertCyl.cxx $(INCDIRu)/zoomInsertCyl.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRA)/KGroup.h $(INCDIRB)/LinearComp.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRA)/masterRotate.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRe)/ModelSupport.h  \
             $(INCDIRW)/NameStack.h $(INCDIRA)/NList.h  \
             $(INCDIRA)/NRange.h $(INCDIRa)/Object.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRF)/shutterBlock.h  \
             $(INCDIRA)/Simulation.h $(INCDIRA)/Source.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfDIter.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRA)/Triple.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h  \
             $(INCDIRu)/zoomInsertBase.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRF) -I$(INCDIRP) \
               -I$(INCDIRA) -I$(INCDIRu) -I$(INCDIRQ) -I$(INCDIRa) \
               -I$(INCDIRB) -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/zoomInsertCyl.cxx

words: 
	grep -v -e '^[[:space:][:cntrl:]]*$$' $(ASRC) | wc 

loc: 
	sloccount $(ASRC) 

cccc: 
	cccc $(ASRC) 

clean:
	rm $(ODEP)

tar:
	tar -zcvf zoom.tgz $(ASRC) Doxyfile Makefile getMk.pl getMake.pmtar:
	tar -zcvf zoom_core.tgz $(CORESRC) getMk.pl getMake.pm
cost:
	sloccount $(ASRC) Doxyfile Makefile getMk.pl getMake.pm
doxygen:
	(cat Doxyfile; echo "INPUT= $(ASRC)" ) | doxygen -

