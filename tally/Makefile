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

CSRC = basicConstruct.cxx cellFluxTally.cxx fissionConstruct.cxx \
            fissionTally.cxx fluxConstruct.cxx heatConstruct.cxx \
            heatTally.cxx itemConstruct.cxx meshConstruct.cxx \
            meshTally.cxx pointConstruct.cxx pointTally.cxx \
            surfaceConstruct.cxx surfaceTally.cxx Tally.cxx \
            tallyConstruct.cxx tallyConstructFactory.cxx \
            TallyCreate.cxx tallyFactory.cxx TallySelector.cxx \
            textTally.cxx 

FSRC = 

CINC = 

FINC = 

ODEP = basicConstruct.o cellFluxTally.o fissionConstruct.o \
            fissionTally.o fluxConstruct.o heatConstruct.o \
            heatTally.o itemConstruct.o meshConstruct.o \
            meshTally.o pointConstruct.o pointTally.o \
            surfaceConstruct.o surfaceTally.o Tally.o \
            tallyConstruct.o tallyConstructFactory.o \
            TallyCreate.o tallyFactory.o TallySelector.o \
            textTally.o 

all: $(LIBOUTDIR)/libTally.so 

$(LIBOUTDIR)/libTally.so : $(ODEP) 
	$(CCOMPL) -fPIC -shared -g  -o $(LIBOUTDIR)/libTally.so \
       $(ODEP) 

Tally.o: $(SRCDIR)/Tally.cxx $(INCDIRl)/Tally.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/mathSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRA)/NList.h  \
             $(INCDIRA)/NRange.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRk)/support.h  \
             $(INCDIRA)/Triple.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRl) \
               -I$(INCDIRk) -I$(INCDIRW) $(SRCDIR)/Tally.cxx

TallyCreate.o: $(SRCDIR)/TallyCreate.cxx $(INCDIRl)/TallyCreate.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRl)/cellFluxTally.h $(INCDIRP)/Code.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRl)/fissionTally.h $(INCDIRP)/FItem.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRl)/heatTally.h $(INCDIRA)/KCode.h  \
             $(INCDIRA)/KGroup.h $(INCDIRe)/LineTrack.h  \
             $(INCDIRQ)/localRotate.h $(INCDIRc)/LSwitchCard.h  \
             $(INCDIRA)/masterRotate.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRl)/meshTally.h  \
             $(INCDIRc)/ModeCard.h $(INCDIRW)/NameStack.h  \
             $(INCDIRA)/NList.h $(INCDIRA)/NRange.h  \
             $(INCDIRe)/ObjectTrackAct.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRA)/pairRange.h $(INCDIRc)/PhysCard.h  \
             $(INCDIRc)/PhysicsCards.h $(INCDIRc)/PhysImp.h  \
             $(INCDIRe)/pointDetOpt.h $(INCDIRl)/pointTally.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRA)/Simulation.h $(INCDIRA)/Source.h  \
             $(INCDIRe)/SpecialSurf.h $(INCDIRQ)/Surface.h  \
             $(INCDIRl)/surfaceTally.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRQ)/SurInter.h $(INCDIRl)/Tally.h  \
             $(INCDIRl)/tallyFactory.h $(INCDIRA)/Triple.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRP) -I$(INCDIRA) \
               -I$(INCDIRQ) -I$(INCDIRc) -I$(INCDIRa) -I$(INCDIRl) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/TallyCreate.cxx

TallySelector.o: $(SRCDIR)/TallySelector.cxx $(INCDIRl)/TallySelector.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRl)/basicConstruct.h $(INCDIRP)/Code.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRl)/fluxConstruct.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRl)/heatConstruct.h  \
             $(INCDIRT)/inputParam.h $(INCDIRl)/itemConstruct.h  \
             $(INCDIRe)/MainProcess.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRl)/meshConstruct.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRl)/pointConstruct.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRl)/surfaceConstruct.h  \
             $(INCDIRl)/tallyConstruct.h $(INCDIRl)/tallyConstructFactory.h  \
             $(INCDIRl)/TallyCreate.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRT) -I$(INCDIRP) \
               -I$(INCDIRQ) -I$(INCDIRl) -I$(INCDIRk) -I$(INCDIRW) \
               -I$(INCDIRR) $(INCBOOST) $(SRCDIR)/TallySelector.cxx

basicConstruct.o: $(SRCDIR)/basicConstruct.cxx $(INCDIRl)/basicConstruct.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRT)/inputParam.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRl)/TallySelector.h  \
             $(INCDIRk)/Tensor.h $(INCDIRA)/Triple.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRT) -I$(INCDIRP) \
               -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRl) -I$(INCDIRa) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/basicConstruct.cxx

cellFluxTally.o: $(SRCDIR)/cellFluxTally.cxx $(INCDIRl)/cellFluxTally.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRA)/NList.h $(INCDIRA)/NRange.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRl)/Tally.h  \
             $(INCDIRA)/Triple.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRl) \
               -I$(INCDIRk) -I$(INCDIRW) $(INCBOOST) \
               $(SRCDIR)/cellFluxTally.cxx

fissionConstruct.o: $(SRCDIR)/fissionConstruct.cxx $(INCDIRl)/fissionConstruct.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRl)/basicConstruct.h $(INCDIRP)/Code.h  \
             $(INCDIRa)/DBMaterial.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRT)/inputParam.h $(INCDIRa)/Material.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRa)/MXcards.h $(INCDIRW)/NameStack.h  \
             $(INCDIRA)/NList.h $(INCDIRA)/NRange.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRA)/Simulation.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRl)/Tally.h $(INCDIRl)/TallyCreate.h  \
             $(INCDIRl)/TallySelector.h $(INCDIRA)/Triple.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h  \
             $(INCDIRa)/Zaid.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRT) -I$(INCDIRP) \
               -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRa) -I$(INCDIRl) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/fissionConstruct.cxx

fissionTally.o: $(SRCDIR)/fissionTally.cxx $(INCDIRl)/fissionTally.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRA)/NList.h $(INCDIRA)/NRange.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRl)/Tally.h  \
             $(INCDIRA)/Triple.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRl) \
               -I$(INCDIRk) -I$(INCDIRW) $(INCBOOST) \
               $(SRCDIR)/fissionTally.cxx

fluxConstruct.o: $(SRCDIR)/fluxConstruct.cxx $(INCDIRl)/fluxConstruct.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRl)/basicConstruct.h $(INCDIRP)/Code.h  \
             $(INCDIRa)/DBMaterial.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRT)/inputParam.h $(INCDIRa)/Material.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRa)/MXcards.h $(INCDIRW)/NameStack.h  \
             $(INCDIRA)/NList.h $(INCDIRA)/NRange.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRA)/Simulation.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRl)/Tally.h $(INCDIRl)/TallyCreate.h  \
             $(INCDIRl)/TallySelector.h $(INCDIRA)/Triple.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h  \
             $(INCDIRa)/Zaid.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRT) -I$(INCDIRP) \
               -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRa) -I$(INCDIRl) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/fluxConstruct.cxx

heatConstruct.o: $(SRCDIR)/heatConstruct.cxx $(INCDIRl)/heatConstruct.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRl)/basicConstruct.h $(INCDIRP)/Code.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRT)/inputParam.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRA)/NRange.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRl)/Tally.h  \
             $(INCDIRl)/TallyCreate.h $(INCDIRl)/TallySelector.h  \
             $(INCDIRk)/Tensor.h $(INCDIRA)/Triple.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRT) -I$(INCDIRP) \
               -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRl) -I$(INCDIRa) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/heatConstruct.cxx

heatTally.o: $(SRCDIR)/heatTally.cxx $(INCDIRl)/heatTally.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRA)/NList.h  \
             $(INCDIRA)/NRange.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRk)/support.h  \
             $(INCDIRl)/Tally.h $(INCDIRA)/Triple.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRl) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) \
               $(SRCDIR)/heatTally.cxx

itemConstruct.o: $(SRCDIR)/itemConstruct.cxx $(INCDIRl)/itemConstruct.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRl)/basicConstruct.h $(INCDIRP)/Code.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRT)/inputParam.h $(INCDIRQ)/Line.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRe)/MainProcess.h $(INCDIRA)/masterRotate.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRA)/NList.h  \
             $(INCDIRA)/NRange.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRl)/pointConstruct.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRB)/SecondTrack.h  \
             $(INCDIRA)/Simulation.h $(INCDIRe)/SpecialSurf.h  \
             $(INCDIRk)/stringCombine.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRl)/Tally.h $(INCDIRl)/TallyCreate.h  \
             $(INCDIRl)/TallySelector.h $(INCDIRk)/Tensor.h  \
             $(INCDIRQ)/Transform.h $(INCDIRA)/Triple.h  \
             $(INCDIRB)/TwinComp.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRT) -I$(INCDIRP) \
               -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRa) -I$(INCDIRl) \
               -I$(INCDIRB) -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/itemConstruct.cxx

meshConstruct.o: $(SRCDIR)/meshConstruct.cxx $(INCDIRl)/meshConstruct.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRl)/basicConstruct.h $(INCDIRP)/Code.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRT)/inputParam.h  \
             $(INCDIRQ)/localRotate.h $(INCDIRA)/masterRotate.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRl)/meshTally.h $(INCDIRW)/NameStack.h  \
             $(INCDIRA)/NRange.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRA)/pairRange.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRl)/Tally.h  \
             $(INCDIRl)/TallyCreate.h $(INCDIRl)/TallySelector.h  \
             $(INCDIRk)/Tensor.h $(INCDIRA)/Triple.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRT) -I$(INCDIRP) \
               -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRl) -I$(INCDIRa) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/meshConstruct.cxx

meshTally.o: $(SRCDIR)/meshTally.cxx $(INCDIRl)/meshTally.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRQ)/localRotate.h $(INCDIRA)/masterRotate.h  \
             $(INCDIRe)/masterWrite.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRA)/NList.h $(INCDIRA)/NRange.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRA)/pairRange.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRl)/Tally.h  \
             $(INCDIRA)/Triple.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRA) -I$(INCDIRQ) \
               -I$(INCDIRl) -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/meshTally.cxx

pointConstruct.o: $(SRCDIR)/pointConstruct.cxx $(INCDIRl)/pointConstruct.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRl)/basicConstruct.h $(INCDIRF)/BlockShutter.h  \
             $(INCDIRP)/Code.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRF)/GeneralShutter.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRT)/inputParam.h $(INCDIRB)/InsertComp.h  \
             $(INCDIRQ)/Line.h $(INCDIRa)/LineIntersectVisit.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRe)/MainProcess.h $(INCDIRA)/masterRotate.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRA)/NList.h  \
             $(INCDIRA)/NRange.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRB)/PositionSupport.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRB)/SecondTrack.h  \
             $(INCDIRF)/shutterBlock.h $(INCDIRA)/Simulation.h  \
             $(INCDIRe)/SpecialSurf.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/SurfLine.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRl)/Tally.h $(INCDIRl)/TallyCreate.h  \
             $(INCDIRl)/TallySelector.h $(INCDIRk)/Tensor.h  \
             $(INCDIRQ)/Transform.h $(INCDIRA)/Triple.h  \
             $(INCDIRB)/TwinComp.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRT) -I$(INCDIRF) \
               -I$(INCDIRP) -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRa) \
               -I$(INCDIRl) -I$(INCDIRB) -I$(INCDIRk) -I$(INCDIRW) \
               -I$(INCDIRR) $(INCBOOST) $(SRCDIR)/pointConstruct.cxx

pointTally.o: $(SRCDIR)/pointTally.cxx $(INCDIRl)/pointTally.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRQ)/Line.h $(INCDIRa)/LineIntersectVisit.h  \
             $(INCDIRQ)/localRotate.h $(INCDIRA)/masterRotate.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRA)/NList.h  \
             $(INCDIRA)/NRange.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/stringCombine.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRl)/Tally.h  \
             $(INCDIRQ)/Transform.h $(INCDIRA)/Triple.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRa) \
               -I$(INCDIRl) -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/pointTally.cxx

surfaceConstruct.o: $(SRCDIR)/surfaceConstruct.cxx $(INCDIRl)/surfaceConstruct.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRl)/basicConstruct.h $(INCDIRP)/Code.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRT)/inputParam.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRA)/NRange.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRl)/Tally.h $(INCDIRl)/TallyCreate.h  \
             $(INCDIRl)/TallySelector.h $(INCDIRk)/Tensor.h  \
             $(INCDIRA)/Triple.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRT) -I$(INCDIRP) \
               -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRl) -I$(INCDIRa) \
               -I$(INCDIRB) -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/surfaceConstruct.cxx

surfaceTally.o: $(SRCDIR)/surfaceTally.cxx $(INCDIRl)/surfaceTally.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/NameStack.h $(INCDIRA)/NList.h  \
             $(INCDIRA)/NRange.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRk)/support.h  \
             $(INCDIRl)/Tally.h $(INCDIRA)/Triple.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRl) -I$(INCDIRk) \
               -I$(INCDIRW) $(SRCDIR)/surfaceTally.cxx

tallyConstruct.o: $(SRCDIR)/tallyConstruct.cxx $(INCDIRl)/tallyConstruct.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRl)/basicConstruct.h $(INCDIRP)/Code.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRl)/fissionConstruct.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRl)/fluxConstruct.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRl)/heatConstruct.h $(INCDIRT)/inputParam.h  \
             $(INCDIRl)/itemConstruct.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRQ)/localRotate.h $(INCDIRA)/masterRotate.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRl)/meshConstruct.h $(INCDIRQ)/MeshGrid.h  \
             $(INCDIRl)/meshTally.h $(INCDIRW)/NameStack.h  \
             $(INCDIRA)/NRange.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRA)/pairRange.h  \
             $(INCDIRl)/pointConstruct.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRB)/SecondTrack.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRl)/surfaceConstruct.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRl)/Tally.h  \
             $(INCDIRl)/tallyConstructFactory.h $(INCDIRl)/TallyCreate.h  \
             $(INCDIRl)/TallySelector.h $(INCDIRA)/Triple.h  \
             $(INCDIRB)/TwinComp.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRT) -I$(INCDIRP) \
               -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRl) -I$(INCDIRa) \
               -I$(INCDIRB) -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/tallyConstruct.cxx

tallyConstructFactory.o: $(SRCDIR)/tallyConstructFactory.cxx $(INCDIRl)/tallyConstructFactory.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRl)/basicConstruct.h $(INCDIRl)/cellFluxTally.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRl)/fissionConstruct.h $(INCDIRl)/fluxConstruct.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRl)/heatConstruct.h  \
             $(INCDIRl)/heatTally.h $(INCDIRl)/itemConstruct.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRl)/meshConstruct.h $(INCDIRW)/NameStack.h  \
             $(INCDIRA)/NList.h $(INCDIRA)/NRange.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRl)/pointConstruct.h $(INCDIRl)/pointTally.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRQ)/Surface.h $(INCDIRl)/surfaceConstruct.h  \
             $(INCDIRl)/surfaceTally.h $(INCDIRl)/Tally.h  \
             $(INCDIRl)/tallyFactory.h $(INCDIRQ)/Transform.h  \
             $(INCDIRA)/Triple.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRl) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) \
               $(SRCDIR)/tallyConstructFactory.cxx

tallyFactory.o: $(SRCDIR)/tallyFactory.cxx $(INCDIRl)/tallyFactory.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRl)/cellFluxTally.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRl)/heatTally.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRA)/NList.h $(INCDIRA)/NRange.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRl)/pointTally.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRQ)/Surface.h  \
             $(INCDIRl)/surfaceTally.h $(INCDIRl)/Tally.h  \
             $(INCDIRQ)/Transform.h $(INCDIRA)/Triple.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRl) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) \
               $(SRCDIR)/tallyFactory.cxx

textTally.o: $(SRCDIR)/textTally.cxx $(INCDIRl)/textTally.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/NameStack.h $(INCDIRA)/NList.h  \
             $(INCDIRA)/NRange.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRk)/support.h  \
             $(INCDIRl)/Tally.h $(INCDIRA)/Triple.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRl) -I$(INCDIRk) \
               -I$(INCDIRW) $(SRCDIR)/textTally.cxx

words: 
	grep -v -e '^[[:space:][:cntrl:]]*$$' $(ASRC) | wc 

loc: 
	sloccount $(ASRC) 

cccc: 
	cccc $(ASRC) 

clean:
	rm $(ODEP)

tar:
	tar -zcvf tally.tgz $(ASRC) Doxyfile Makefile getMk.pl getMake.pmtar:
	tar -zcvf tally_core.tgz $(CORESRC) getMk.pl getMake.pm
cost:
	sloccount $(ASRC) Doxyfile Makefile getMk.pl getMake.pm
doxygen:
	(cat Doxyfile; echo "INPUT= $(ASRC)" ) | doxygen -

