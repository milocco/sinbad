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

CSRC = BeamWindow.cxx ConicInfo.cxx CylMod.cxx FlightLine.cxx \
            GroupOrigin.cxx hexUnit.cxx insertPlate.cxx \
            LinkWrapper.cxx LWInner.cxx LWOuter.cxx ModBase.cxx \
            ProtonVoid.cxx SupplyPipe.cxx targCoolant.cxx \
            TargetBase.cxx tubeUnit.cxx WedgeInsert.cxx \
            Window.cxx 

FSRC = 

CINC = 

FINC = 

ODEP = BeamWindow.o ConicInfo.o CylMod.o FlightLine.o \
            GroupOrigin.o hexUnit.o insertPlate.o LinkWrapper.o \
            LWInner.o LWOuter.o ModBase.o ProtonVoid.o \
            SupplyPipe.o targCoolant.o TargetBase.o tubeUnit.o \
            WedgeInsert.o Window.o 

all: $(LIBOUTDIR)/libConstruct.so 

$(LIBOUTDIR)/libConstruct.so : $(ODEP) 
	$(CCOMPL) -fPIC -shared -g  -o $(LIBOUTDIR)/libConstruct.so \
       $(ODEP) 

BeamWindow.o: $(SRCDIR)/BeamWindow.cxx $(INCDIRH)/BeamWindow.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRQ)/Line.h $(INCDIRB)/LinkUnit.h  \
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
               -I$(INCDIRH) -I$(INCDIRP) -I$(INCDIRA) -I$(INCDIRk) \
               -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/BeamWindow.cxx

ConicInfo.o: $(SRCDIR)/ConicInfo.cxx $(INCDIRH)/ConicInfo.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRH) -I$(INCDIRk) -I$(INCDIRQ) \
               -I$(INCDIRW) $(INCBOOST) $(SRCDIR)/ConicInfo.cxx

CylMod.o: $(SRCDIR)/CylMod.cxx $(INCDIRH)/CylMod.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRH)/ConicInfo.h  \
             $(INCDIRB)/ContainedComp.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRB)/LayerComp.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRe)/MaterialSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRH)/ModBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h  \
             $(INCDIRH)/WedgeInsert.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRH) -I$(INCDIRA) -I$(INCDIRP) -I$(INCDIRk) \
               -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/CylMod.cxx

FlightLine.o: $(SRCDIR)/FlightLine.cxx $(INCDIRH)/FlightLine.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRB)/ContainedGroup.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRe)/generateSurf.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRQ)/Line.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRA)/Simulation.h  \
             $(INCDIRk)/stringCombine.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRe)/surfDIter.h  \
             $(INCDIRe)/surfDivide.h $(INCDIRe)/surfEqual.h  \
             $(INCDIRe)/surfExpand.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRH) -I$(INCDIRA) -I$(INCDIRP) -I$(INCDIRk) \
               -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/FlightLine.cxx

GroupOrigin.o: $(SRCDIR)/GroupOrigin.cxx $(INCDIRH)/GroupOrigin.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRA)/KGroup.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRA)/masterRotate.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRA)/NList.h $(INCDIRA)/NRange.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRA)/Simulation.h $(INCDIRA)/Source.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfDIter.h $(INCDIRe)/surfDivide.h  \
             $(INCDIRe)/surfEqual.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRl)/Tally.h  \
             $(INCDIRA)/Triple.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRl) \
               -I$(INCDIRB) -I$(INCDIRH) -I$(INCDIRP) -I$(INCDIRA) \
               -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/GroupOrigin.cxx

LWInner.o: $(SRCDIR)/LWInner.cxx $(INCDIRH)/LWInner.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRk)/Exception.h  \
             $(INCDIRB)/ExcludedComp.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRe)/generateSurf.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRA)/KGroup.h  \
             $(INCDIRQ)/Line.h $(INCDIRB)/LinearComp.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRH)/LinkWrapper.h  \
             $(INCDIRQ)/localRotate.h $(INCDIRA)/masterRotate.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRA)/NList.h $(INCDIRA)/NRange.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRA)/Simulation.h  \
             $(INCDIRA)/Source.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfDIter.h $(INCDIRe)/surfDivide.h  \
             $(INCDIRe)/surfEqual.h $(INCDIRe)/surfExpand.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRl)/Tally.h $(INCDIRA)/Triple.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRl) \
               -I$(INCDIRB) -I$(INCDIRH) -I$(INCDIRP) -I$(INCDIRA) \
               -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/LWInner.cxx

LWOuter.o: $(SRCDIR)/LWOuter.cxx $(INCDIRH)/LWOuter.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRk)/Exception.h  \
             $(INCDIRB)/ExcludedComp.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRe)/generateSurf.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRA)/KGroup.h  \
             $(INCDIRQ)/Line.h $(INCDIRB)/LinearComp.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRH)/LinkWrapper.h  \
             $(INCDIRQ)/localRotate.h $(INCDIRA)/masterRotate.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRA)/NList.h $(INCDIRA)/NRange.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRA)/Simulation.h  \
             $(INCDIRA)/Source.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfDIter.h $(INCDIRe)/surfDivide.h  \
             $(INCDIRe)/surfEqual.h $(INCDIRe)/surfExpand.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRl)/Tally.h $(INCDIRA)/Triple.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRl) \
               -I$(INCDIRB) -I$(INCDIRH) -I$(INCDIRP) -I$(INCDIRA) \
               -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/LWOuter.cxx

LinkWrapper.o: $(SRCDIR)/LinkWrapper.cxx $(INCDIRH)/LinkWrapper.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRk)/Exception.h  \
             $(INCDIRB)/ExcludedComp.h $(INCDIRW)/FileReport.h  \
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
             $(INCDIRA)/Simulation.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfDIter.h $(INCDIRe)/surfDivide.h  \
             $(INCDIRe)/surfEqual.h $(INCDIRe)/surfExpand.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRH) -I$(INCDIRP) -I$(INCDIRA) -I$(INCDIRk) \
               -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/LinkWrapper.cxx

ModBase.o: $(SRCDIR)/ModBase.cxx $(INCDIRH)/ModBase.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRB)/LayerComp.h  \
             $(INCDIRQ)/Line.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRA)/Simulation.h  \
             $(INCDIRk)/stringCombine.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRH) -I$(INCDIRA) -I$(INCDIRP) -I$(INCDIRk) \
               -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/ModBase.cxx

ProtonVoid.o: $(SRCDIR)/ProtonVoid.cxx $(INCDIRH)/ProtonVoid.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRe)/BoxLine.h $(INCDIRe)/boxUnit.h  \
             $(INCDIRe)/boxValues.h $(INCDIRm)/channel.h  \
             $(INCDIRF)/chipDataStore.h $(INCDIRP)/Code.h  \
             $(INCDIRB)/ContainedComp.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRe)/generateSurf.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRQ)/Line.h  \
             $(INCDIRB)/LinearComp.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRQ)/localRotate.h $(INCDIRA)/masterRotate.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRe)/SimProcess.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfDIter.h $(INCDIRe)/surfDivide.h  \
             $(INCDIRe)/surfEqual.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRm) \
               -I$(INCDIRB) -I$(INCDIRF) -I$(INCDIRH) -I$(INCDIRP) \
               -I$(INCDIRA) -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRW) \
               -I$(INCDIRR) $(INCBOOST) $(SRCDIR)/ProtonVoid.cxx

SupplyPipe.o: $(SRCDIR)/SupplyPipe.cxx $(INCDIRH)/SupplyPipe.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRB)/LayerComp.h  \
             $(INCDIRQ)/Line.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRQ)/localRotate.h $(INCDIRA)/masterRotate.h  \
             $(INCDIRe)/MaterialSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRe)/ModelSupport.h  \
             $(INCDIRW)/NameStack.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRe)/PipeLine.h $(INCDIRe)/pipeUnit.h  \
             $(INCDIRQ)/Plane.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfDIter.h $(INCDIRe)/surfEqual.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRH) -I$(INCDIRP) -I$(INCDIRA) -I$(INCDIRk) \
               -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/SupplyPipe.cxx

TargetBase.o: $(SRCDIR)/TargetBase.cxx $(INCDIRH)/TargetBase.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRH)/BeamWindow.h $(INCDIRF)/chipDataStore.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRA)/KGroup.h $(INCDIRQ)/Line.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRA)/masterRotate.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRe)/ModelSupport.h  \
             $(INCDIRW)/NameStack.h $(INCDIRA)/NList.h  \
             $(INCDIRA)/NRange.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRH)/ProtonVoid.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRe)/SimProcess.h  \
             $(INCDIRA)/Simulation.h $(INCDIRA)/Source.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfDIter.h $(INCDIRe)/surfDivide.h  \
             $(INCDIRe)/surfEqual.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRl)/Tally.h  \
             $(INCDIRA)/Triple.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h $(INCDIRs)/World.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRl) \
               -I$(INCDIRB) -I$(INCDIRF) -I$(INCDIRH) -I$(INCDIRP) \
               -I$(INCDIRA) -I$(INCDIRk) -I$(INCDIRQ) -I$(INCDIRs) \
               -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/TargetBase.cxx

WedgeInsert.o: $(SRCDIR)/WedgeInsert.cxx $(INCDIRH)/WedgeInsert.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRe)/generateSurf.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRB)/LayerComp.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRe)/MaterialSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRa)/RuleSupport.h $(INCDIRA)/Simulation.h  \
             $(INCDIRk)/stringCombine.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRH) -I$(INCDIRA) -I$(INCDIRP) -I$(INCDIRk) \
               -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/WedgeInsert.cxx

Window.o: $(SRCDIR)/Window.cxx $(INCDIRH)/Window.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRQ)/Line.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRQ)/localRotate.h $(INCDIRA)/masterRotate.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRe)/ModelSupport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRe)/pairBase.h  \
             $(INCDIRe)/pairFactory.h $(INCDIRe)/pairItem.h  \
             $(INCDIRQ)/Plane.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfDIter.h $(INCDIRe)/surfDivide.h  \
             $(INCDIRe)/surfEqual.h $(INCDIRe)/surfExpand.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRH) -I$(INCDIRP) -I$(INCDIRA) -I$(INCDIRk) \
               -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/Window.cxx

hexUnit.o: $(SRCDIR)/hexUnit.cxx $(INCDIRH)/hexUnit.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRH) -I$(INCDIRk) -I$(INCDIRQ) \
               -I$(INCDIRW) $(INCBOOST) $(SRCDIR)/hexUnit.cxx

insertPlate.o: $(SRCDIR)/insertPlate.cxx $(INCDIRH)/insertPlate.h \
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
               -I$(INCDIRH) -I$(INCDIRP) -I$(INCDIRA) -I$(INCDIRk) \
               -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/insertPlate.cxx

targCoolant.o: $(SRCDIR)/targCoolant.cxx $(INCDIRH)/targCoolant.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRQ)/Cone.h  \
             $(INCDIRB)/ContainedComp.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRe)/generateSurf.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRQ)/localRotate.h $(INCDIRA)/masterRotate.h  \
             $(INCDIRe)/MaterialSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRe)/ModelSupport.h  \
             $(INCDIRW)/NameStack.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRA)/Simulation.h $(INCDIRQ)/Sphere.h  \
             $(INCDIRk)/stringCombine.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRe)/surfDIter.h  \
             $(INCDIRe)/surfEqual.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRH)/TargetBase.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRH) -I$(INCDIRP) -I$(INCDIRA) -I$(INCDIRk) \
               -I$(INCDIRQ) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/targCoolant.cxx

tubeUnit.o: $(SRCDIR)/tubeUnit.cxx $(INCDIRH)/tubeUnit.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRH) -I$(INCDIRk) \
               -I$(INCDIRQ) -I$(INCDIRW) $(INCBOOST) \
               $(SRCDIR)/tubeUnit.cxx

words: 
	grep -v -e '^[[:space:][:cntrl:]]*$$' $(ASRC) | wc 

loc: 
	sloccount $(ASRC) 

cccc: 
	cccc $(ASRC) 

clean:
	rm $(ODEP)

tar:
	tar -zcvf construct.tgz $(ASRC) Doxyfile Makefile getMk.pl getMake.pmtar:
	tar -zcvf construct_core.tgz $(CORESRC) getMk.pl getMake.pm
cost:
	sloccount $(ASRC) Doxyfile Makefile getMk.pl getMake.pm
doxygen:
	(cat Doxyfile; echo "INPUT= $(ASRC)" ) | doxygen -

