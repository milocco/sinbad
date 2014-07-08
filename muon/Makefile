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

CSRC = coneColl.cxx cShieldLayer.cxx makeMuon.cxx \
            muBeamWindow.cxx muonCarbonTarget.cxx muonQ1.cxx \
            muonTube.cxx muVariables.cxx profileMon.cxx \
            targetVesselBox.cxx targSimpleShield.cxx 

FSRC = 

CINC = 

FINC = 

ODEP = coneColl.o cShieldLayer.o makeMuon.o muBeamWindow.o \
            muonCarbonTarget.o muonQ1.o muonTube.o muVariables.o \
            profileMon.o targetVesselBox.o targSimpleShield.o 

all: $(LIBOUTDIR)/libMuon.so 

$(LIBOUTDIR)/libMuon.so : $(ODEP) 
	$(CCOMPL) -fPIC -shared -g  -o $(LIBOUTDIR)/libMuon.so \
       $(ODEP) 

cShieldLayer.o: $(SRCDIR)/cShieldLayer.cxx $(INCDIRb)/cShieldLayer.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRe)/generateSurf.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRe)/MaterialSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRe)/ModelSupport.h  \
             $(INCDIRW)/NameStack.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRA)/Simulation.h  \
             $(INCDIRk)/stringCombine.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRA) -I$(INCDIRP) \
               -I$(INCDIRQ) -I$(INCDIRb) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/cShieldLayer.cxx

coneColl.o: $(SRCDIR)/coneColl.cxx $(INCDIRb)/coneColl.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRe)/generateSurf.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRQ)/Line.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRe)/MaterialSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRe)/ModelSupport.h  \
             $(INCDIRW)/NameStack.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRe)/SimProcess.h $(INCDIRA)/Simulation.h  \
             $(INCDIRk)/stringCombine.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRe)/surfEqual.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRQ)/SurInter.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRA) -I$(INCDIRP) \
               -I$(INCDIRQ) -I$(INCDIRb) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/coneColl.cxx

makeMuon.o: $(SRCDIR)/makeMuon.cxx $(INCDIRb)/makeMuon.h \
             $(INCDIRB)/AttachSupport.h $(INCDIRR)/BaseModVisit.h  \
             $(INCDIRR)/BaseVisit.h $(INCDIRP)/Code.h  \
             $(INCDIRb)/coneColl.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRB)/ContainedGroup.h $(INCDIRb)/cShieldLayer.h  \
             $(INCDIRW)/Debug.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRB)/FixedComp.h  \
             $(INCDIRP)/FuncDataBase.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRT)/inputParam.h  \
             $(INCDIRG)/insertBaseInfo.h $(INCDIRB)/InsertComp.h  \
             $(INCDIRF)/insertInfo.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRb)/muBeamWindow.h $(INCDIRb)/muonCarbonTarget.h  \
             $(INCDIRb)/muonQ1.h $(INCDIRb)/muonTube.h  \
             $(INCDIRW)/NameStack.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRb)/profileMon.h $(INCDIRa)/Qhull.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRA)/Simulation.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRb)/targetVesselBox.h $(INCDIRb)/targSimpleShield.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h  \
             $(INCDIRs)/World.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRT) -I$(INCDIRF) \
               -I$(INCDIRA) -I$(INCDIRP) -I$(INCDIRQ) -I$(INCDIRs) \
               -I$(INCDIRb) -I$(INCDIRa) -I$(INCDIRB) -I$(INCDIRG) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/makeMuon.cxx

muBeamWindow.o: $(SRCDIR)/muBeamWindow.cxx $(INCDIRb)/muBeamWindow.h \
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
             $(INCDIRQ)/PointOperation.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfDivide.h $(INCDIRe)/surfEqual.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRA) -I$(INCDIRP) \
               -I$(INCDIRQ) -I$(INCDIRb) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/muBeamWindow.cxx

muVariables.o: $(SRCDIR)/muVariables.cxx                         \
             $(INCDIRP)/Code.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRF)/variableSetup.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRF) -I$(INCDIRP) -I$(INCDIRQ) \
               -I$(INCDIRk) -I$(INCDIRW) $(INCBOOST) \
               $(SRCDIR)/muVariables.cxx

muonCarbonTarget.o: $(SRCDIR)/muonCarbonTarget.cxx $(INCDIRb)/muonCarbonTarget.h \
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
             $(INCDIRa)/Rules.h $(INCDIRe)/SimProcess.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfEqual.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h $(INCDIRs)/World.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRA) -I$(INCDIRP) \
               -I$(INCDIRQ) -I$(INCDIRs) -I$(INCDIRb) -I$(INCDIRa) \
               -I$(INCDIRB) -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) \
               $(INCBOOST) $(SRCDIR)/muonCarbonTarget.cxx

muonQ1.o: $(SRCDIR)/muonQ1.cxx $(INCDIRb)/muonQ1.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRe)/generateSurf.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRe)/MaterialSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRe)/ModelSupport.h  \
             $(INCDIRW)/NameStack.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRa)/Qhull.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRA) -I$(INCDIRP) \
               -I$(INCDIRQ) -I$(INCDIRb) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/muonQ1.cxx

muonTube.o: $(SRCDIR)/muonTube.cxx $(INCDIRb)/muonTube.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRe)/generateSurf.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRe)/MaterialSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRe)/ModelSupport.h  \
             $(INCDIRW)/NameStack.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRa)/Qhull.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRA)/Simulation.h  \
             $(INCDIRk)/support.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRA) -I$(INCDIRP) \
               -I$(INCDIRQ) -I$(INCDIRb) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/muonTube.cxx

profileMon.o: $(SRCDIR)/profileMon.cxx $(INCDIRb)/profileMon.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRQ)/Convex.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRe)/generateSurf.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRe)/MaterialSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRe)/ModelSupport.h  \
             $(INCDIRW)/NameStack.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRe)/SimProcess.h $(INCDIRA)/Simulation.h  \
             $(INCDIRk)/stringCombine.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRP)/varList.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRA) -I$(INCDIRP) \
               -I$(INCDIRQ) -I$(INCDIRb) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/profileMon.cxx

targSimpleShield.o: $(SRCDIR)/targSimpleShield.cxx $(INCDIRb)/targSimpleShield.h \
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
             $(INCDIRa)/Rules.h $(INCDIRe)/SimProcess.h  \
             $(INCDIRA)/Simulation.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRe)/surfEqual.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRQ)/SurInter.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRA) -I$(INCDIRP) \
               -I$(INCDIRQ) -I$(INCDIRb) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/targSimpleShield.cxx

targetVesselBox.o: $(SRCDIR)/targetVesselBox.cxx $(INCDIRb)/targetVesselBox.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRP)/Code.h $(INCDIRB)/ContainedComp.h  \
             $(INCDIRQ)/Convex.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRB)/FixedComp.h $(INCDIRP)/FuncDataBase.h  \
             $(INCDIRe)/generateSurf.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRB)/LinkUnit.h  \
             $(INCDIRe)/MaterialSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRe)/ModelSupport.h  \
             $(INCDIRW)/NameStack.h $(INCDIRa)/Object.h  \
             $(INCDIRe)/objectRegister.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRa)/Qhull.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRe)/SimProcess.h $(INCDIRA)/Simulation.h  \
             $(INCDIRk)/stringCombine.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRe)/surfDivide.h  \
             $(INCDIRe)/surfEqual.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRe)/surfRegister.h $(INCDIRQ)/SurInter.h  \
             $(INCDIRP)/varList.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRA) -I$(INCDIRP) \
               -I$(INCDIRQ) -I$(INCDIRb) -I$(INCDIRa) -I$(INCDIRB) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/targetVesselBox.cxx

words: 
	grep -v -e '^[[:space:][:cntrl:]]*$$' $(ASRC) | wc 

loc: 
	sloccount $(ASRC) 

cccc: 
	cccc $(ASRC) 

clean:
	rm $(ODEP)

tar:
	tar -zcvf muon.tgz $(ASRC) Doxyfile Makefile getMk.pl getMake.pmtar:
	tar -zcvf muon_core.tgz $(CORESRC) getMk.pl getMake.pm
cost:
	sloccount $(ASRC) Doxyfile Makefile getMk.pl getMake.pm
doxygen:
	(cat Doxyfile; echo "INPUT= $(ASRC)" ) | doxygen -

