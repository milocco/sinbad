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

CSRC = ess.cxx fullBuild.cxx muBeam.cxx reactor.cxx sinbad.cxx \
            sns.cxx t1MarkII.cxx t1Real.cxx testMain.cxx 

FSRC = 

CINC = 

FINC = 

ODEP = ess.o fullBuild.o muBeam.o reactor.o sinbad.o sns.o \
            t1MarkII.o t1Real.o testMain.o 

MAINDEP=fullBuild.o ess.o muBeam.o sinbad.o t1Real.o sns.o \
            reactor.o t1MarkII.o testMain.o 

all: $(MAINDEP)

ess.o: $(SRCDIR)/ess.cxx                         \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRB)/ContainedGroup.h $(INCDIRe)/DefPhysics.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRq)/ImportControl.h $(INCDIRk)/InputControl.h  \
             $(INCDIRT)/inputParam.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRA)/mainJobs.h $(INCDIRe)/MainProcess.h  \
             $(INCDIRO)/makeESS.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRY)/MersenneTwister.h  \
             $(INCDIRW)/NameStack.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRa)/Qhull.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRe)/SimInput.h  \
             $(INCDIRA)/SimPHITS.h $(INCDIRe)/SimProcess.h  \
             $(INCDIRA)/Simulation.h $(INCDIRi)/SourceCreate.h  \
             $(INCDIRi)/SourceSelector.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRQ)/SurInter.h  \
             $(INCDIRl)/TallySelector.h $(INCDIRF)/variableSetup.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h  \
             $(INCDIRe)/Volumes.h $(INCDIRs)/World.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRT) -I$(INCDIRF) \
               -I$(INCDIRY) -I$(INCDIRA) -I$(INCDIRP) -I$(INCDIRQ) \
               -I$(INCDIRs) -I$(INCDIRO) -I$(INCDIRq) -I$(INCDIRl) \
               -I$(INCDIRa) -I$(INCDIRi) -I$(INCDIRB) -I$(INCDIRk) \
               -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) $(SRCDIR)/ess.cxx

fullBuild.o: $(SRCDIR)/fullBuild.cxx                         \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRF)/chipDataStore.h $(INCDIRP)/Code.h  \
             $(INCDIRe)/DefPhysics.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRq)/ImportControl.h $(INCDIRk)/InputControl.h  \
             $(INCDIRT)/inputParam.h $(INCDIRA)/KCode.h  \
             $(INCDIRA)/KGroup.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRc)/LSwitchCard.h $(INCDIRA)/mainJobs.h  \
             $(INCDIRe)/MainProcess.h $(INCDIRZ)/makeTS2.h  \
             $(INCDIRA)/masterRotate.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/MemStack.h  \
             $(INCDIRY)/MersenneTwister.h $(INCDIRc)/ModeCard.h  \
             $(INCDIRW)/NameStack.h $(INCDIRA)/NList.h  \
             $(INCDIRA)/NRange.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRc)/PhysCard.h $(INCDIRc)/PhysicsCards.h  \
             $(INCDIRc)/PhysImp.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRe)/SimInput.h $(INCDIRA)/SimPHITS.h  \
             $(INCDIRe)/SimProcess.h $(INCDIRA)/Simulation.h  \
             $(INCDIRA)/SimValid.h $(INCDIRA)/Source.h  \
             $(INCDIRi)/SourceCreate.h $(INCDIRi)/SourceSelector.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRl)/TallySelector.h $(INCDIRA)/Triple.h  \
             $(INCDIRF)/variableSetup.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h $(INCDIRA)/version.h  \
             $(INCDIRe)/Volumes.h $(INCDIRs)/World.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRT) -I$(INCDIRF) \
               -I$(INCDIRY) -I$(INCDIRP) -I$(INCDIRA) -I$(INCDIRQ) \
               -I$(INCDIRs) -I$(INCDIRc) -I$(INCDIRq) -I$(INCDIRZ) \
               -I$(INCDIRl) -I$(INCDIRa) -I$(INCDIRi) -I$(INCDIRk) \
               -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/fullBuild.cxx

muBeam.o: $(SRCDIR)/muBeam.cxx                         \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRe)/DefPhysics.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRq)/ImportControl.h  \
             $(INCDIRk)/InputControl.h $(INCDIRT)/inputParam.h  \
             $(INCDIRA)/mainJobs.h $(INCDIRe)/MainProcess.h  \
             $(INCDIRb)/makeMuon.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRY)/MersenneTwister.h  \
             $(INCDIRW)/NameStack.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRa)/Qhull.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRe)/SimInput.h  \
             $(INCDIRe)/SimProcess.h $(INCDIRA)/Simulation.h  \
             $(INCDIRi)/SourceCreate.h $(INCDIRi)/SourceSelector.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRl)/TallySelector.h $(INCDIRF)/variableSetup.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h  \
             $(INCDIRe)/Volumes.h $(INCDIRs)/World.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRT) -I$(INCDIRF) \
               -I$(INCDIRY) -I$(INCDIRA) -I$(INCDIRP) -I$(INCDIRQ) \
               -I$(INCDIRs) -I$(INCDIRb) -I$(INCDIRq) -I$(INCDIRl) \
               -I$(INCDIRa) -I$(INCDIRi) -I$(INCDIRk) -I$(INCDIRW) \
               -I$(INCDIRR) $(INCBOOST) $(SRCDIR)/muBeam.cxx

reactor.o: $(SRCDIR)/reactor.cxx                         \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRq)/BasicWWE.h $(INCDIRP)/Code.h  \
             $(INCDIRe)/DefPhysics.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRk)/InputControl.h $(INCDIRT)/inputParam.h  \
             $(INCDIRA)/mainJobs.h $(INCDIRe)/MainProcess.h  \
             $(INCDIRL)/makeDelft.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRY)/MersenneTwister.h  \
             $(INCDIRW)/NameStack.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRA)/SimPHITS.h $(INCDIRe)/SimProcess.h  \
             $(INCDIRA)/Simulation.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRQ)/SurInter.h  \
             $(INCDIRl)/TallyCreate.h $(INCDIRl)/TallySelector.h  \
             $(INCDIRQ)/Transform.h $(INCDIRF)/variableSetup.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h  \
             $(INCDIRe)/Volumes.h $(INCDIRs)/World.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRT) -I$(INCDIRF) \
               -I$(INCDIRY) -I$(INCDIRA) -I$(INCDIRP) -I$(INCDIRQ) \
               -I$(INCDIRs) -I$(INCDIRL) -I$(INCDIRq) -I$(INCDIRa) \
               -I$(INCDIRl) -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/reactor.cxx

sinbad.o: $(SRCDIR)/sinbad.cxx                         \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRe)/DefPhysics.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRq)/ImportControl.h $(INCDIRk)/InputControl.h  \
             $(INCDIRT)/inputParam.h $(INCDIRA)/mainJobs.h  \
             $(INCDIRe)/MainProcess.h $(INCDIRg)/makeSinbad.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRY)/MersenneTwister.h $(INCDIRW)/NameStack.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRe)/SimInput.h  \
             $(INCDIRA)/SimPHITS.h $(INCDIRe)/SimProcess.h  \
             $(INCDIRA)/Simulation.h $(INCDIRi)/SourceSelector.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRl)/TallySelector.h  \
             $(INCDIRF)/variableSetup.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h $(INCDIRe)/Volumes.h  \
             $(INCDIRs)/World.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRT) -I$(INCDIRF) \
               -I$(INCDIRY) -I$(INCDIRA) -I$(INCDIRP) -I$(INCDIRQ) \
               -I$(INCDIRs) -I$(INCDIRq) -I$(INCDIRl) -I$(INCDIRi) \
               -I$(INCDIRk) -I$(INCDIRg) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/sinbad.cxx

sns.o: $(SRCDIR)/sns.cxx                         \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRq)/BasicWWE.h $(INCDIRP)/Code.h  \
             $(INCDIRB)/ContainedComp.h $(INCDIRB)/ContainedGroup.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRe)/DefPhysics.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRq)/ImportControl.h $(INCDIRk)/InputControl.h  \
             $(INCDIRT)/inputParam.h $(INCDIRA)/KCode.h  \
             $(INCDIRA)/KGroup.h $(INCDIRQ)/Line.h  \
             $(INCDIRB)/LinearComp.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRQ)/localRotate.h $(INCDIRc)/LSwitchCard.h  \
             $(INCDIRA)/mainJobs.h $(INCDIRe)/MainProcess.h  \
             $(INCDIRh)/makeSNS.h $(INCDIRA)/masterRotate.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRY)/MersenneTwister.h $(INCDIRc)/ModeCard.h  \
             $(INCDIRW)/NameStack.h $(INCDIRA)/NList.h  \
             $(INCDIRA)/NRange.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRc)/PhysCard.h $(INCDIRc)/PhysicsCards.h  \
             $(INCDIRc)/PhysImp.h $(INCDIRQ)/Plane.h  \
             $(INCDIRq)/PointWeights.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRe)/SimInput.h $(INCDIRA)/SimPHITS.h  \
             $(INCDIRe)/SimProcess.h $(INCDIRA)/Simulation.h  \
             $(INCDIRA)/Source.h $(INCDIRi)/SourceCreate.h  \
             $(INCDIRi)/SourceSelector.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRQ)/SurInter.h $(INCDIRl)/Tally.h  \
             $(INCDIRl)/TallyCreate.h $(INCDIRl)/TallySelector.h  \
             $(INCDIRk)/Tensor.h $(INCDIRQ)/Transform.h  \
             $(INCDIRA)/Triple.h $(INCDIRF)/variableSetup.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h  \
             $(INCDIRe)/Volumes.h $(INCDIRs)/World.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRh) -I$(INCDIRe) -I$(INCDIRT) \
               -I$(INCDIRF) -I$(INCDIRY) -I$(INCDIRP) -I$(INCDIRA) \
               -I$(INCDIRQ) -I$(INCDIRs) -I$(INCDIRc) -I$(INCDIRq) \
               -I$(INCDIRa) -I$(INCDIRl) -I$(INCDIRi) -I$(INCDIRB) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/sns.cxx

t1MarkII.o: $(SRCDIR)/t1MarkII.cxx                         \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRe)/DefPhysics.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRq)/ImportControl.h  \
             $(INCDIRk)/InputControl.h $(INCDIRT)/inputParam.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRA)/mainJobs.h $(INCDIRe)/MainProcess.h  \
             $(INCDIRn)/makeT1Upgrade.h $(INCDIRA)/masterRotate.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRY)/MersenneTwister.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRe)/SimInput.h $(INCDIRA)/SimPHITS.h  \
             $(INCDIRe)/SimProcess.h $(INCDIRA)/Simulation.h  \
             $(INCDIRi)/SourceCreate.h $(INCDIRi)/SourceSelector.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRl)/tallyConstructFactory.h  \
             $(INCDIRl)/TallySelector.h $(INCDIRQ)/Transform.h  \
             $(INCDIRF)/variableSetup.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h $(INCDIRe)/Volumes.h  \
             $(INCDIRs)/World.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRT) -I$(INCDIRF) \
               -I$(INCDIRY) -I$(INCDIRP) -I$(INCDIRA) -I$(INCDIRQ) \
               -I$(INCDIRs) -I$(INCDIRq) -I$(INCDIRl) -I$(INCDIRa) \
               -I$(INCDIRi) -I$(INCDIRB) -I$(INCDIRn) -I$(INCDIRk) \
               -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/t1MarkII.cxx

t1Real.o: $(SRCDIR)/t1Real.cxx                         \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRq)/BasicWWE.h $(INCDIRP)/Code.h  \
             $(INCDIRB)/ContainedComp.h $(INCDIRB)/ContainedGroup.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRe)/DefPhysics.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRq)/ImportControl.h $(INCDIRk)/InputControl.h  \
             $(INCDIRT)/inputParam.h $(INCDIRA)/KCode.h  \
             $(INCDIRA)/KGroup.h $(INCDIRQ)/Line.h  \
             $(INCDIRB)/LinearComp.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRQ)/localRotate.h $(INCDIRc)/LSwitchCard.h  \
             $(INCDIRA)/mainJobs.h $(INCDIRe)/MainProcess.h  \
             $(INCDIRm)/makeT1Real.h $(INCDIRA)/masterRotate.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRY)/MersenneTwister.h $(INCDIRc)/ModeCard.h  \
             $(INCDIRW)/NameStack.h $(INCDIRA)/NList.h  \
             $(INCDIRA)/NRange.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRc)/PhysCard.h $(INCDIRc)/PhysicsCards.h  \
             $(INCDIRc)/PhysImp.h $(INCDIRQ)/Plane.h  \
             $(INCDIRq)/PointWeights.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRe)/SimInput.h $(INCDIRA)/SimPHITS.h  \
             $(INCDIRe)/SimProcess.h $(INCDIRA)/Simulation.h  \
             $(INCDIRA)/SimValid.h $(INCDIRA)/Source.h  \
             $(INCDIRi)/SourceCreate.h $(INCDIRi)/SourceSelector.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRQ)/SurInter.h  \
             $(INCDIRl)/Tally.h $(INCDIRl)/TallyCreate.h  \
             $(INCDIRl)/TallySelector.h $(INCDIRk)/Tensor.h  \
             $(INCDIRQ)/Transform.h $(INCDIRA)/Triple.h  \
             $(INCDIRF)/variableSetup.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h $(INCDIRe)/Volumes.h  \
             $(INCDIRs)/World.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRT) -I$(INCDIRF) \
               -I$(INCDIRY) -I$(INCDIRP) -I$(INCDIRA) -I$(INCDIRQ) \
               -I$(INCDIRs) -I$(INCDIRc) -I$(INCDIRq) -I$(INCDIRa) \
               -I$(INCDIRl) -I$(INCDIRm) -I$(INCDIRi) -I$(INCDIRB) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/t1Real.cxx

testMain.o: $(SRCDIR)/testMain.cxx                         \
             $(INCDIRa)/Acomp.h $(INCDIRa)/Algebra.h  \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRa)/BnId.h $(INCDIRP)/Code.h  \
             $(INCDIRQ)/Cone.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRQ)/Convex.h $(INCDIRQ)/Convex2D.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRW)/Debug.h  \
             $(INCDIRQ)/EllipticCyl.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRP)/funcList.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRA)/KCode.h $(INCDIRA)/KGroup.h  \
             $(INCDIRB)/LinkUnit.h $(INCDIRc)/LSwitchCard.h  \
             $(INCDIRe)/MainProcess.h $(INCDIRk)/MapSupport.h  \
             $(INCDIRk)/mathSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRY)/MersenneTwister.h  \
             $(INCDIRc)/ModeCard.h $(INCDIRW)/NameStack.h  \
             $(INCDIRA)/NList.h $(INCDIRA)/NRange.h  \
             $(INCDIRa)/Object.h $(INCDIRe)/objectRegister.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRc)/PhysCard.h  \
             $(INCDIRc)/PhysicsCards.h $(INCDIRc)/PhysImp.h  \
             $(INCDIRQ)/Plane.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRA)/RefControl.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/RotCounter.h  \
             $(INCDIRa)/RuleBinary.h $(INCDIRa)/Rules.h  \
             $(INCDIRv)/simpleObj.h $(INCDIRA)/Simulation.h  \
             $(INCDIRA)/Source.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRk)/SVD.h  \
             $(INCDIRv)/testAlgebra.h $(INCDIRv)/testAttachSupport.h  \
             $(INCDIRv)/testBinData.h $(INCDIRv)/testBnId.h  \
             $(INCDIRv)/testBoost.h $(INCDIRv)/testBoundary.h  \
             $(INCDIRv)/testBoxLine.h $(INCDIRv)/testCone.h  \
             $(INCDIRv)/testContained.h $(INCDIRv)/testConvex.h  \
             $(INCDIRv)/testConvex2D.h $(INCDIRv)/testCylinder.h  \
             $(INCDIRv)/testDBMaterial.h $(INCDIRv)/testDoubleErr.h  \
             $(INCDIRv)/testElement.h $(INCDIRv)/testEllipticCyl.h  \
             $(INCDIRv)/testFace.h $(INCDIRv)/testFunc.h  \
             $(INCDIRv)/testFunction.h $(INCDIRv)/testInputParam.h  \
             $(INCDIRv)/testInsertComp.h $(INCDIRv)/testLine.h  \
             $(INCDIRv)/testLineTrack.h $(INCDIRv)/testLog.h  \
             $(INCDIRv)/testMapSupport.h $(INCDIRv)/testMasterRotate.h  \
             $(INCDIRv)/testMaterial.h $(INCDIRv)/testMathSupport.h  \
             $(INCDIRv)/testMatrix.h $(INCDIRv)/testMD5.h  \
             $(INCDIRv)/testMergeRule.h $(INCDIRv)/testMersenne.h  \
             $(INCDIRv)/testNeutron.h $(INCDIRv)/testNList.h  \
             $(INCDIRv)/testNRange.h $(INCDIRv)/testObject.h  \
             $(INCDIRv)/testObjectRegister.h $(INCDIRv)/testObjectTrackAct.h  \
             $(INCDIRv)/testObjSurfMap.h $(INCDIRv)/testObjTrackItem.h  \
             $(INCDIRv)/testPairFactory.h $(INCDIRv)/testPairItem.h  \
             $(INCDIRv)/testPipeLine.h $(INCDIRv)/testPipeUnit.h  \
             $(INCDIRv)/testPlane.h $(INCDIRv)/testPoly.h  \
             $(INCDIRv)/testQuaternion.h $(INCDIRv)/testRecTriangle.h  \
             $(INCDIRv)/testRefPlate.h $(INCDIRv)/testRotCounter.h  \
             $(INCDIRv)/testRules.h $(INCDIRv)/testSimpleObj.h  \
             $(INCDIRv)/testSimpson.h $(INCDIRv)/testSimulation.h  \
             $(INCDIRv)/testSingleObject.h $(INCDIRv)/testSolveValues.h  \
             $(INCDIRv)/testSource.h $(INCDIRv)/testSupport.h  \
             $(INCDIRv)/testSurfDivide.h $(INCDIRv)/testSurfEqual.h  \
             $(INCDIRv)/testSurfExpand.h $(INCDIRv)/testSurfRegister.h  \
             $(INCDIRv)/testSurIntersect.h $(INCDIRv)/testSVD.h  \
             $(INCDIRv)/testTally.h $(INCDIRv)/testVarNameOrder.h  \
             $(INCDIRv)/testVec3D.h $(INCDIRv)/testVolumes.h  \
             $(INCDIRv)/testWorkData.h $(INCDIRv)/testWrapper.h  \
             $(INCDIRv)/testXML.h $(INCDIRQ)/Transform.h  \
             $(INCDIRA)/Triple.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h $(INCDIRQ)/Vert2D.h  \
             $(INCDIRt)/XMLattribute.h $(INCDIRt)/XMLcollect.h  \
             $(INCDIRt)/XMLgroup.h $(INCDIRt)/XMLload.h  \
             $(INCDIRt)/XMLobject.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRY) -I$(INCDIRP) \
               -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRc) -I$(INCDIRa) \
               -I$(INCDIRB) -I$(INCDIRt) -I$(INCDIRk) -I$(INCDIRv) \
               -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/testMain.cxx

words: 
	grep -v -e '^[[:space:][:cntrl:]]*$$' $(ASRC) | wc 

loc: 
	sloccount $(ASRC) 

cccc: 
	cccc $(ASRC) 

clean:
	rm $(ODEP)

tar:
	tar -zcvf Main.tgz $(ASRC) Doxyfile Makefile getMk.pl getMake.pmtar:
	tar -zcvf Main_core.tgz $(CORESRC) getMk.pl getMake.pm
cost:
	sloccount $(ASRC) Doxyfile Makefile getMk.pl getMake.pm
doxygen:
	(cat Doxyfile; echo "INPUT= $(ASRC)" ) | doxygen -

