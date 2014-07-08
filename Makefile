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

all : libSrc libAttachComp libBeamline libBibBuild libBnctBuild \
            libBuild libChip libConstruct libCrystal libCuBlock \
            libD4cModel libDelft libEndf libEpbBuild libEssBuild \
            libFuncBase libGeometry libGlobal libImat libInput \
            libInstrument libLensModel libLog libMd5 libModerator \
            libMersenne libMonte libMuon libPhysics libPoly \
            libProcess libScatMat libSinbadBuild libSnsBuild \
            libSource libSupport libTally libT1Build libT1Upgrade \
            libTransport libVisit libWeights libWorld libWork \
            libXml libZoom libSpecial libTest mainProg fullBuild \
            ess muBeam sinbad t1Real sns reactor t1MarkII \
            testMain 

.PHONY : libSrc libAttachComp libBeamline libBibBuild \
            libBnctBuild libBuild libChip libConstruct libCrystal \
            libCuBlock libD4cModel libDelft libEndf libEpbBuild \
            libEssBuild libFuncBase libGeometry libGlobal libImat \
            libInput libInstrument libLensModel libLog libMd5 \
            libModerator libMersenne libMonte libMuon libPhysics \
            libPoly libProcess libScatMat libSinbadBuild \
            libSnsBuild libSource libSupport libTally libT1Build \
            libT1Upgrade libTransport libVisit libWeights \
            libWorld libWork libXml libZoom libSpecial libTest \
            mainProg 

fullBuild : mainProg Main/fullBuild.o libBuild libVisit libChip \
          libModerator libBuild libZoom libImat libSrc libPhysics \
          libConstruct libTransport libScatMat libCrystal libEndf \
          libInput libSource libMonte libFuncBase libLog \
          libProcess libTally libWorld libMonte libGeometry \
          libMersenne libSrc libWork libXml libPoly libSupport \
          libWeights libMd5 libGlobal libAttachComp libVisit 
	$(CCOMPL) $(CFLAGC) -o fullBuild Main/fullBuild.o -fPIC \
            -Wl,-rpath,$(LIBOUTDIR) $(LIBOUTDIR)/libBuild.so \
            $(LIBOUTDIR)/libVisit.so $(LIBOUTDIR)/libChip.so \
            $(LIBOUTDIR)/libModerator.so $(LIBOUTDIR)/libBuild.so \
            $(LIBOUTDIR)/libZoom.so $(LIBOUTDIR)/libImat.so \
            $(LIBOUTDIR)/libSrc.so $(LIBOUTDIR)/libPhysics.so \
            $(LIBOUTDIR)/libConstruct.so \
            $(LIBOUTDIR)/libTransport.so \
            $(LIBOUTDIR)/libScatMat.so $(LIBOUTDIR)/libCrystal.so \
            $(LIBOUTDIR)/libEndf.so $(LIBOUTDIR)/libInput.so \
            $(LIBOUTDIR)/libSource.so $(LIBOUTDIR)/libMonte.so \
            $(LIBOUTDIR)/libFuncBase.so $(LIBOUTDIR)/libLog.so \
            $(LIBOUTDIR)/libProcess.so $(LIBOUTDIR)/libTally.so \
            $(LIBOUTDIR)/libWorld.so $(LIBOUTDIR)/libMonte.so \
            $(LIBOUTDIR)/libGeometry.so \
            $(LIBOUTDIR)/libMersenne.so $(LIBOUTDIR)/libSrc.so \
            $(LIBOUTDIR)/libWork.so $(LIBOUTDIR)/libXml.so \
            $(LIBOUTDIR)/libPoly.so $(LIBOUTDIR)/libSupport.so \
            $(LIBOUTDIR)/libWeights.so $(LIBOUTDIR)/libMd5.so \
            $(LIBOUTDIR)/libGlobal.so \
            $(LIBOUTDIR)/libAttachComp.so \
            $(LIBOUTDIR)/libVisit.so -lstdc++ $(GSLLIBS) \
            $(BOOSTLIBS) 

ess : mainProg Main/ess.o libEssBuild libVisit libSrc libBeamline \
          libPhysics libInput libSource libMonte libFuncBase \
          libLog libTally libConstruct libCrystal libTransport \
          libScatMat libMd5 libEndf libProcess libWorld libWork \
          libMonte libGeometry libMersenne libSrc libXml libPoly \
          libSupport libWeights libGlobal libAttachComp libVisit 
	$(CCOMPL) $(CFLAGC) -o ess Main/ess.o -fPIC \
            -Wl,-rpath,$(LIBOUTDIR) $(LIBOUTDIR)/libEssBuild.so \
            $(LIBOUTDIR)/libVisit.so $(LIBOUTDIR)/libSrc.so \
            $(LIBOUTDIR)/libBeamline.so \
            $(LIBOUTDIR)/libPhysics.so $(LIBOUTDIR)/libInput.so \
            $(LIBOUTDIR)/libSource.so $(LIBOUTDIR)/libMonte.so \
            $(LIBOUTDIR)/libFuncBase.so $(LIBOUTDIR)/libLog.so \
            $(LIBOUTDIR)/libTally.so $(LIBOUTDIR)/libConstruct.so \
            $(LIBOUTDIR)/libCrystal.so \
            $(LIBOUTDIR)/libTransport.so \
            $(LIBOUTDIR)/libScatMat.so $(LIBOUTDIR)/libMd5.so \
            $(LIBOUTDIR)/libEndf.so $(LIBOUTDIR)/libProcess.so \
            $(LIBOUTDIR)/libWorld.so $(LIBOUTDIR)/libWork.so \
            $(LIBOUTDIR)/libMonte.so $(LIBOUTDIR)/libGeometry.so \
            $(LIBOUTDIR)/libMersenne.so $(LIBOUTDIR)/libSrc.so \
            $(LIBOUTDIR)/libXml.so $(LIBOUTDIR)/libPoly.so \
            $(LIBOUTDIR)/libSupport.so $(LIBOUTDIR)/libWeights.so \
            $(LIBOUTDIR)/libGlobal.so \
            $(LIBOUTDIR)/libAttachComp.so \
            $(LIBOUTDIR)/libVisit.so -lstdc++ $(GSLLIBS) \
            $(BOOSTLIBS) 

muBeam : mainProg Main/muBeam.o libMuon libT1Build libImat \
          libChip libBuild libVisit libModerator libZoom libSrc \
          libConstruct libCrystal libTransport libScatMat libEndf \
          libPhysics libInput libProcess libSource libMonte \
          libFuncBase libLog libMonte libTally libGeometry \
          libMersenne libSrc libWorld libWork libXml libPoly \
          libSupport libWeights libMd5 libGlobal libAttachComp \
          libVisit libPoly 
	$(CCOMPL) $(CFLAGC) -o muBeam Main/muBeam.o -fPIC \
            -Wl,-rpath,$(LIBOUTDIR) $(LIBOUTDIR)/libMuon.so \
            $(LIBOUTDIR)/libT1Build.so $(LIBOUTDIR)/libImat.so \
            $(LIBOUTDIR)/libChip.so $(LIBOUTDIR)/libBuild.so \
            $(LIBOUTDIR)/libVisit.so $(LIBOUTDIR)/libModerator.so \
            $(LIBOUTDIR)/libZoom.so $(LIBOUTDIR)/libSrc.so \
            $(LIBOUTDIR)/libConstruct.so \
            $(LIBOUTDIR)/libCrystal.so \
            $(LIBOUTDIR)/libTransport.so \
            $(LIBOUTDIR)/libScatMat.so $(LIBOUTDIR)/libEndf.so \
            $(LIBOUTDIR)/libPhysics.so $(LIBOUTDIR)/libInput.so \
            $(LIBOUTDIR)/libProcess.so $(LIBOUTDIR)/libSource.so \
            $(LIBOUTDIR)/libMonte.so $(LIBOUTDIR)/libFuncBase.so \
            $(LIBOUTDIR)/libLog.so $(LIBOUTDIR)/libMonte.so \
            $(LIBOUTDIR)/libTally.so $(LIBOUTDIR)/libGeometry.so \
            $(LIBOUTDIR)/libMersenne.so $(LIBOUTDIR)/libSrc.so \
            $(LIBOUTDIR)/libWorld.so $(LIBOUTDIR)/libWork.so \
            $(LIBOUTDIR)/libXml.so $(LIBOUTDIR)/libPoly.so \
            $(LIBOUTDIR)/libSupport.so $(LIBOUTDIR)/libWeights.so \
            $(LIBOUTDIR)/libMd5.so $(LIBOUTDIR)/libGlobal.so \
            $(LIBOUTDIR)/libAttachComp.so \
            $(LIBOUTDIR)/libVisit.so $(LIBOUTDIR)/libPoly.so \
            -lstdc++ $(GSLLIBS) $(BOOSTLIBS) 

sinbad : mainProg Main/sinbad.o libSinbadBuild libVisit libSrc \
          libPhysics libInput libSource libMonte libFuncBase \
          libLog libTally libConstruct libCrystal libTransport \
          libScatMat libMd5 libEndf libProcess libWorld libWork \
          libMonte libGeometry libMersenne libSrc libXml libPoly \
          libSupport libWeights libGlobal libAttachComp libVisit 
	$(CCOMPL) $(CFLAGC) -o sinbad Main/sinbad.o -fPIC \
            -Wl,-rpath,$(LIBOUTDIR) \
            $(LIBOUTDIR)/libSinbadBuild.so \
            $(LIBOUTDIR)/libVisit.so $(LIBOUTDIR)/libSrc.so \
            $(LIBOUTDIR)/libPhysics.so $(LIBOUTDIR)/libInput.so \
            $(LIBOUTDIR)/libSource.so $(LIBOUTDIR)/libMonte.so \
            $(LIBOUTDIR)/libFuncBase.so $(LIBOUTDIR)/libLog.so \
            $(LIBOUTDIR)/libTally.so $(LIBOUTDIR)/libConstruct.so \
            $(LIBOUTDIR)/libCrystal.so \
            $(LIBOUTDIR)/libTransport.so \
            $(LIBOUTDIR)/libScatMat.so $(LIBOUTDIR)/libMd5.so \
            $(LIBOUTDIR)/libEndf.so $(LIBOUTDIR)/libProcess.so \
            $(LIBOUTDIR)/libWorld.so $(LIBOUTDIR)/libWork.so \
            $(LIBOUTDIR)/libMonte.so $(LIBOUTDIR)/libGeometry.so \
            $(LIBOUTDIR)/libMersenne.so $(LIBOUTDIR)/libSrc.so \
            $(LIBOUTDIR)/libXml.so $(LIBOUTDIR)/libPoly.so \
            $(LIBOUTDIR)/libSupport.so $(LIBOUTDIR)/libWeights.so \
            $(LIBOUTDIR)/libGlobal.so \
            $(LIBOUTDIR)/libAttachComp.so \
            $(LIBOUTDIR)/libVisit.so -lstdc++ $(GSLLIBS) \
            $(BOOSTLIBS) 

t1Real : mainProg Main/t1Real.o libT1Build libImat libChip \
          libBuild libVisit libModerator libZoom libSrc \
          libConstruct libCrystal libTransport libScatMat libEndf \
          libPhysics libInput libProcess libSource libMonte \
          libFuncBase libLog libMonte libTally libGeometry \
          libMersenne libSrc libWorld libWork libXml libPoly \
          libSupport libWeights libMd5 libGlobal libAttachComp \
          libVisit libPoly 
	$(CCOMPL) $(CFLAGC) -o t1Real Main/t1Real.o -fPIC \
            -Wl,-rpath,$(LIBOUTDIR) $(LIBOUTDIR)/libT1Build.so \
            $(LIBOUTDIR)/libImat.so $(LIBOUTDIR)/libChip.so \
            $(LIBOUTDIR)/libBuild.so $(LIBOUTDIR)/libVisit.so \
            $(LIBOUTDIR)/libModerator.so $(LIBOUTDIR)/libZoom.so \
            $(LIBOUTDIR)/libSrc.so $(LIBOUTDIR)/libConstruct.so \
            $(LIBOUTDIR)/libCrystal.so \
            $(LIBOUTDIR)/libTransport.so \
            $(LIBOUTDIR)/libScatMat.so $(LIBOUTDIR)/libEndf.so \
            $(LIBOUTDIR)/libPhysics.so $(LIBOUTDIR)/libInput.so \
            $(LIBOUTDIR)/libProcess.so $(LIBOUTDIR)/libSource.so \
            $(LIBOUTDIR)/libMonte.so $(LIBOUTDIR)/libFuncBase.so \
            $(LIBOUTDIR)/libLog.so $(LIBOUTDIR)/libMonte.so \
            $(LIBOUTDIR)/libTally.so $(LIBOUTDIR)/libGeometry.so \
            $(LIBOUTDIR)/libMersenne.so $(LIBOUTDIR)/libSrc.so \
            $(LIBOUTDIR)/libWorld.so $(LIBOUTDIR)/libWork.so \
            $(LIBOUTDIR)/libXml.so $(LIBOUTDIR)/libPoly.so \
            $(LIBOUTDIR)/libSupport.so $(LIBOUTDIR)/libWeights.so \
            $(LIBOUTDIR)/libMd5.so $(LIBOUTDIR)/libGlobal.so \
            $(LIBOUTDIR)/libAttachComp.so \
            $(LIBOUTDIR)/libVisit.so $(LIBOUTDIR)/libPoly.so \
            -lstdc++ $(GSLLIBS) $(BOOSTLIBS) 

sns : mainProg Main/sns.o libSnsBuild libVisit libSrc libPhysics \
          libInput libSource libMonte libFuncBase libLog libTally \
          libConstruct libCrystal libTransport libScatMat libMd5 \
          libEndf libProcess libWorld libWork libMonte \
          libGeometry libMersenne libSrc libXml libPoly \
          libSupport libWeights libGlobal libAttachComp libVisit 
	$(CCOMPL) $(CFLAGC) -o sns Main/sns.o -fPIC \
            -Wl,-rpath,$(LIBOUTDIR) $(LIBOUTDIR)/libSnsBuild.so \
            $(LIBOUTDIR)/libVisit.so $(LIBOUTDIR)/libSrc.so \
            $(LIBOUTDIR)/libPhysics.so $(LIBOUTDIR)/libInput.so \
            $(LIBOUTDIR)/libSource.so $(LIBOUTDIR)/libMonte.so \
            $(LIBOUTDIR)/libFuncBase.so $(LIBOUTDIR)/libLog.so \
            $(LIBOUTDIR)/libTally.so $(LIBOUTDIR)/libConstruct.so \
            $(LIBOUTDIR)/libCrystal.so \
            $(LIBOUTDIR)/libTransport.so \
            $(LIBOUTDIR)/libScatMat.so $(LIBOUTDIR)/libMd5.so \
            $(LIBOUTDIR)/libEndf.so $(LIBOUTDIR)/libProcess.so \
            $(LIBOUTDIR)/libWorld.so $(LIBOUTDIR)/libWork.so \
            $(LIBOUTDIR)/libMonte.so $(LIBOUTDIR)/libGeometry.so \
            $(LIBOUTDIR)/libMersenne.so $(LIBOUTDIR)/libSrc.so \
            $(LIBOUTDIR)/libXml.so $(LIBOUTDIR)/libPoly.so \
            $(LIBOUTDIR)/libSupport.so $(LIBOUTDIR)/libWeights.so \
            $(LIBOUTDIR)/libGlobal.so \
            $(LIBOUTDIR)/libAttachComp.so \
            $(LIBOUTDIR)/libVisit.so -lstdc++ $(GSLLIBS) \
            $(BOOSTLIBS) 

reactor : mainProg Main/reactor.o libDelft libVisit libSrc \
          libPhysics libInput libSource libMonte libFuncBase \
          libLog libConstruct libTransport libScatMat libCrystal \
          libEndf libProcess libTally libWorld libMonte \
          libGeometry libMersenne libSrc libXml libPoly \
          libSupport libWeights libMd5 libWork libGlobal \
          libAttachComp libVisit 
	$(CCOMPL) $(CFLAGC) -o reactor Main/reactor.o -fPIC \
            -Wl,-rpath,$(LIBOUTDIR) $(LIBOUTDIR)/libDelft.so \
            $(LIBOUTDIR)/libVisit.so $(LIBOUTDIR)/libSrc.so \
            $(LIBOUTDIR)/libPhysics.so $(LIBOUTDIR)/libInput.so \
            $(LIBOUTDIR)/libSource.so $(LIBOUTDIR)/libMonte.so \
            $(LIBOUTDIR)/libFuncBase.so $(LIBOUTDIR)/libLog.so \
            $(LIBOUTDIR)/libConstruct.so \
            $(LIBOUTDIR)/libTransport.so \
            $(LIBOUTDIR)/libScatMat.so $(LIBOUTDIR)/libCrystal.so \
            $(LIBOUTDIR)/libEndf.so $(LIBOUTDIR)/libProcess.so \
            $(LIBOUTDIR)/libTally.so $(LIBOUTDIR)/libWorld.so \
            $(LIBOUTDIR)/libMonte.so $(LIBOUTDIR)/libGeometry.so \
            $(LIBOUTDIR)/libMersenne.so $(LIBOUTDIR)/libSrc.so \
            $(LIBOUTDIR)/libXml.so $(LIBOUTDIR)/libPoly.so \
            $(LIBOUTDIR)/libSupport.so $(LIBOUTDIR)/libWeights.so \
            $(LIBOUTDIR)/libMd5.so $(LIBOUTDIR)/libWork.so \
            $(LIBOUTDIR)/libGlobal.so \
            $(LIBOUTDIR)/libAttachComp.so \
            $(LIBOUTDIR)/libVisit.so -lstdc++ $(GSLLIBS) \
            $(BOOSTLIBS) 

t1MarkII : mainProg Main/t1MarkII.o libT1Upgrade libT1Build \
          libImat libChip libBuild libVisit libModerator libZoom \
          libSrc libConstruct libCrystal libTransport libScatMat \
          libEndf libPhysics libInput libProcess libSource \
          libMonte libFuncBase libLog libMonte libTally \
          libGeometry libMersenne libSrc libWorld libWork libXml \
          libPoly libSupport libWeights libMd5 libGlobal \
          libAttachComp libVisit libPoly 
	$(CCOMPL) $(CFLAGC) -o t1MarkII Main/t1MarkII.o -fPIC \
            -Wl,-rpath,$(LIBOUTDIR) $(LIBOUTDIR)/libT1Upgrade.so \
            $(LIBOUTDIR)/libT1Build.so $(LIBOUTDIR)/libImat.so \
            $(LIBOUTDIR)/libChip.so $(LIBOUTDIR)/libBuild.so \
            $(LIBOUTDIR)/libVisit.so $(LIBOUTDIR)/libModerator.so \
            $(LIBOUTDIR)/libZoom.so $(LIBOUTDIR)/libSrc.so \
            $(LIBOUTDIR)/libConstruct.so \
            $(LIBOUTDIR)/libCrystal.so \
            $(LIBOUTDIR)/libTransport.so \
            $(LIBOUTDIR)/libScatMat.so $(LIBOUTDIR)/libEndf.so \
            $(LIBOUTDIR)/libPhysics.so $(LIBOUTDIR)/libInput.so \
            $(LIBOUTDIR)/libProcess.so $(LIBOUTDIR)/libSource.so \
            $(LIBOUTDIR)/libMonte.so $(LIBOUTDIR)/libFuncBase.so \
            $(LIBOUTDIR)/libLog.so $(LIBOUTDIR)/libMonte.so \
            $(LIBOUTDIR)/libTally.so $(LIBOUTDIR)/libGeometry.so \
            $(LIBOUTDIR)/libMersenne.so $(LIBOUTDIR)/libSrc.so \
            $(LIBOUTDIR)/libWorld.so $(LIBOUTDIR)/libWork.so \
            $(LIBOUTDIR)/libXml.so $(LIBOUTDIR)/libPoly.so \
            $(LIBOUTDIR)/libSupport.so $(LIBOUTDIR)/libWeights.so \
            $(LIBOUTDIR)/libMd5.so $(LIBOUTDIR)/libGlobal.so \
            $(LIBOUTDIR)/libAttachComp.so \
            $(LIBOUTDIR)/libVisit.so $(LIBOUTDIR)/libPoly.so \
            -lstdc++ $(GSLLIBS) $(BOOSTLIBS) 

testMain : mainProg Main/testMain.o libTest libBuild libVisit \
          libChip libT1Upgrade libImat libModerator libBuild \
          libZoom libConstruct libCrystal libTransport libScatMat \
          libEndf libT1Build libSrc libPhysics libInput \
          libProcess libSource libMonte libFuncBase libLog \
          libGeometry libTally libMersenne libSrc libWork libXml \
          libPoly libSupport libWorld libWeights libMd5 libGlobal \
          libAttachComp libVisit libPoly 
	$(CCOMPL) $(CFLAGC) -o testMain Main/testMain.o -fPIC \
            -Wl,-rpath,$(LIBOUTDIR) $(LIBOUTDIR)/libTest.so \
            $(LIBOUTDIR)/libBuild.so $(LIBOUTDIR)/libVisit.so \
            $(LIBOUTDIR)/libChip.so $(LIBOUTDIR)/libT1Upgrade.so \
            $(LIBOUTDIR)/libImat.so $(LIBOUTDIR)/libModerator.so \
            $(LIBOUTDIR)/libBuild.so $(LIBOUTDIR)/libZoom.so \
            $(LIBOUTDIR)/libConstruct.so \
            $(LIBOUTDIR)/libCrystal.so \
            $(LIBOUTDIR)/libTransport.so \
            $(LIBOUTDIR)/libScatMat.so $(LIBOUTDIR)/libEndf.so \
            $(LIBOUTDIR)/libT1Build.so $(LIBOUTDIR)/libSrc.so \
            $(LIBOUTDIR)/libPhysics.so $(LIBOUTDIR)/libInput.so \
            $(LIBOUTDIR)/libProcess.so $(LIBOUTDIR)/libSource.so \
            $(LIBOUTDIR)/libMonte.so $(LIBOUTDIR)/libFuncBase.so \
            $(LIBOUTDIR)/libLog.so $(LIBOUTDIR)/libGeometry.so \
            $(LIBOUTDIR)/libTally.so $(LIBOUTDIR)/libMersenne.so \
            $(LIBOUTDIR)/libSrc.so $(LIBOUTDIR)/libWork.so \
            $(LIBOUTDIR)/libXml.so $(LIBOUTDIR)/libPoly.so \
            $(LIBOUTDIR)/libSupport.so $(LIBOUTDIR)/libWorld.so \
            $(LIBOUTDIR)/libWeights.so $(LIBOUTDIR)/libMd5.so \
            $(LIBOUTDIR)/libGlobal.so \
            $(LIBOUTDIR)/libAttachComp.so \
            $(LIBOUTDIR)/libVisit.so $(LIBOUTDIR)/libPoly.so \
            -lstdc++ $(GSLLIBS) $(BOOSTLIBS) 

libSrc : 
	@${MAKE} -C ./src all

libAttachComp : 
	@${MAKE} -C ./attachComp all

libBeamline : 
	@${MAKE} -C ./beamline all

libBibBuild : 
	@${MAKE} -C ./bibBuild all

libBnctBuild : 
	@${MAKE} -C ./bnctBuild all

libBuild : 
	@${MAKE} -C ./build all

libChip : 
	@${MAKE} -C ./chip all

libConstruct : 
	@${MAKE} -C ./construct all

libCrystal : 
	@${MAKE} -C ./crystal all

libCuBlock : 
	@${MAKE} -C ./cuBlock all

libD4cModel : 
	@${MAKE} -C ./d4cModel all

libDelft : 
	@${MAKE} -C ./delft all

libEndf : 
	@${MAKE} -C ./endf all

libEpbBuild : 
	@${MAKE} -C ./epbBuild all

libEssBuild : 
	@${MAKE} -C ./essBuild all

libFuncBase : 
	@${MAKE} -C ./funcBase all

libGeometry : 
	@${MAKE} -C ./geometry all

libGlobal : 
	@${MAKE} -C ./global all

libImat : 
	@${MAKE} -C ./imat all

libInput : 
	@${MAKE} -C ./input all

libInstrument : 
	@${MAKE} -C ./instrument all

libLensModel : 
	@${MAKE} -C ./lensModel all

libLog : 
	@${MAKE} -C ./log all

libMd5 : 
	@${MAKE} -C ./md5 all

libModerator : 
	@${MAKE} -C ./moderator all

libMersenne : 
	@${MAKE} -C ./mersenne all

libMonte : 
	@${MAKE} -C ./monte all

libMuon : 
	@${MAKE} -C ./muon all

libPhysics : 
	@${MAKE} -C ./physics all

libPoly : 
	@${MAKE} -C ./poly all

libProcess : 
	@${MAKE} -C ./process all

libScatMat : 
	@${MAKE} -C ./scatMat all

libSinbadBuild : 
	@${MAKE} -C ./sinbadBuild all

libSnsBuild : 
	@${MAKE} -C ./snsBuild all

libSource : 
	@${MAKE} -C ./source all

libSupport : 
	@${MAKE} -C ./support all

libTally : 
	@${MAKE} -C ./tally all

libT1Build : 
	@${MAKE} -C ./t1Build all

libT1Upgrade : 
	@${MAKE} -C ./t1Upgrade all

libTransport : 
	@${MAKE} -C ./transport all

libVisit : 
	@${MAKE} -C ./visit all

libWeights : 
	@${MAKE} -C ./weights all

libWorld : 
	@${MAKE} -C ./world all

libWork : 
	@${MAKE} -C ./work all

libXml : 
	@${MAKE} -C ./xml all

libZoom : 
	@${MAKE} -C ./zoom all

libSpecial : 
	@${MAKE} -C ./special all

libTest : 
	@${MAKE} -C ./test all

mainProg : 
	@${MAKE} -C ./Main all

tar:
	tar zcvf CombLayer.tgz ./src/*.cxx ./attachComp/*.cxx \
            ./beamline/*.cxx ./bibBuild/*.cxx \
            ./bnctBuild/*.cxx ./build/*.cxx ./chip/*.cxx \
            ./construct/*.cxx ./crystal/*.cxx \
            ./cuBlock/*.cxx ./d4cModel/*.cxx ./delft/*.cxx \
            ./endf/*.cxx ./epbBuild/*.cxx ./essBuild/*.cxx \
            ./funcBase/*.cxx ./geometry/*.cxx \
            ./global/*.cxx ./imat/*.cxx ./input/*.cxx \
            ./instrument/*.cxx ./lensModel/*.cxx \
            ./log/*.cxx ./md5/*.cxx ./moderator/*.cxx \
            ./mersenne/*.cxx ./monte/*.cxx ./muon/*.cxx \
            ./physics/*.cxx ./poly/*.cxx ./process/*.cxx \
            ./scatMat/*.cxx ./sinbadBuild/*.cxx \
            ./snsBuild/*.cxx ./source/*.cxx ./support/*.cxx \
            ./tally/*.cxx ./t1Build/*.cxx ./t1Upgrade/*.cxx \
            ./transport/*.cxx ./visit/*.cxx ./weights/*.cxx \
            ./world/*.cxx ./work/*.cxx ./xml/*.cxx \
            ./zoom/*.cxx ./special/*.cxx ./test/*.cxx \
            ./Main/*.cxx Doxyfile ./include/*.h \
            ./attachCompInc/*.h ./beamlineInc/*.h \
            ./bibBuildInc/*.h ./bnctBuildInc/*.h \
            ./buildInc/*.h ./chipInc/*.h ./constructInc/*.h \
            ./crystalInc/*.h ./cuBlockInc/*.h \
            ./d4cModelInc/*.h ./delftInc/*.h ./endfInc/*.h \
            ./epbBuildInc/*.h ./essBuildInc/*.h \
            ./funcBaseInc/*.h ./geomInc/*.h ./globalInc/*.h \
            ./imatInc/*.h ./inputInc/*.h \
            ./instrumentInc/*.h ./lensModelInc/*.h \
            ./logInc/*.h ./md5Inc/*.h ./mersenneInc/*.h \
            ./moderatorInc/*.h ./monteInc/*.h ./muonInc/*.h \
            ./physicsInc/*.h ./polyInc/*.h ./processInc/*.h \
            ./scatMatInc/*.h ./sinbadBuildInc/*.h \
            ./snsBuildInc/*.h ./sourceInc/*.h \
            ./specialInc/*.h ./supportInc/*.h \
            ./tallyInc/*.h ./t1BuildInc/*.h \
            ./t1UpgradeInc/*.h ./transportInc/*.h \
            ./visitInc/*.h ./weightsInc/*.h ./workInc/*.h \
            ./worldInc/*.h ./xmlInc/*.h ./zoomInc/*.h \
            ./testInclude/*.h getMake.pm getMk.pl 

tarcore:
	tar zcvf CombLayer_core.tgz src/*.cxx attachComp/*.cxx \
            beamline/*.cxx construct/*.cxx crystal/*.cxx \
            endf/*.cxx funcBase/*.cxx geometry/*.cxx \
            global/*.cxx input/*.cxx instrument/*.cxx \
            log/*.cxx md5/*.cxx mersenne/*.cxx monte/*.cxx \
            physics/*.cxx poly/*.cxx process/*.cxx \
            scatMat/*.cxx source/*.cxx support/*.cxx \
            tally/*.cxx transport/*.cxx visit/*.cxx \
            weights/*.cxx world/*.cxx work/*.cxx xml/*.cxx \
            special/*.cxx test/*.cxx include/*.h \
            attachCompInc/*.h beamlineInc/*.h \
            constructInc/*.h crystalInc/*.h endfInc/*.h \
            funcBaseInc/*.h geomInc/*.h globalInc/*.h \
            inputInc/*.h instrumentInc/*.h logInc/*.h \
            md5Inc/*.h mersenneInc/*.h monteInc/*.h \
            muonInc/*.h physicsInc/*.h polyInc/*.h \
            processInc/*.h scatMatInc/*.h sourceInc/*.h \
            specialInc/*.h supportInc/*.h tallyInc/*.h \
            transportInc/*.h visitInc/*.h weightsInc/*.h \
            workInc/*.h worldInc/*.h xmlInc/*.h \
            testInclude/*.h getMake.pm getMk.pl 

doxygen:
	(cat Doxyfile; echo "INPUT = " `ls ./src/*.cxx \
            ./attachComp/*.cxx ./beamline/*.cxx \
            ./bibBuild/*.cxx ./bnctBuild/*.cxx \
            ./build/*.cxx ./chip/*.cxx ./construct/*.cxx \
            ./crystal/*.cxx ./cuBlock/*.cxx \
            ./d4cModel/*.cxx ./delft/*.cxx ./endf/*.cxx \
            ./epbBuild/*.cxx ./essBuild/*.cxx \
            ./funcBase/*.cxx ./geometry/*.cxx \
            ./global/*.cxx ./imat/*.cxx ./input/*.cxx \
            ./instrument/*.cxx ./lensModel/*.cxx \
            ./log/*.cxx ./md5/*.cxx ./moderator/*.cxx \
            ./mersenne/*.cxx ./monte/*.cxx ./muon/*.cxx \
            ./physics/*.cxx ./poly/*.cxx ./process/*.cxx \
            ./scatMat/*.cxx ./sinbadBuild/*.cxx \
            ./snsBuild/*.cxx ./source/*.cxx ./support/*.cxx \
            ./tally/*.cxx ./t1Build/*.cxx ./t1Upgrade/*.cxx \
            ./transport/*.cxx ./visit/*.cxx ./weights/*.cxx \
            ./world/*.cxx ./work/*.cxx ./xml/*.cxx \
            ./zoom/*.cxx ./special/*.cxx ./test/*.cxx \
            ./Main/*.cxx ./include/*.h ./attachCompInc/*.h \
            ./beamlineInc/*.h ./bibBuildInc/*.h \
            ./bnctBuildInc/*.h ./buildInc/*.h ./chipInc/*.h \
            ./constructInc/*.h ./crystalInc/*.h \
            ./cuBlockInc/*.h ./d4cModelInc/*.h \
            ./delftInc/*.h ./endfInc/*.h ./epbBuildInc/*.h \
            ./essBuildInc/*.h ./funcBaseInc/*.h \
            ./geomInc/*.h ./globalInc/*.h ./imatInc/*.h \
            ./inputInc/*.h ./instrumentInc/*.h \
            ./lensModelInc/*.h ./logInc/*.h ./md5Inc/*.h \
            ./mersenneInc/*.h ./moderatorInc/*.h \
            ./monteInc/*.h ./muonInc/*.h ./physicsInc/*.h \
            ./polyInc/*.h ./processInc/*.h ./scatMatInc/*.h \
            ./sinbadBuildInc/*.h ./snsBuildInc/*.h \
            ./sourceInc/*.h ./specialInc/*.h \
            ./supportInc/*.h ./tallyInc/*.h \
            ./t1BuildInc/*.h ./t1UpgradeInc/*.h \
            ./transportInc/*.h ./visitInc/*.h \
            ./weightsInc/*.h ./workInc/*.h ./worldInc/*.h \
            ./xmlInc/*.h ./zoomInc/*.h ./testInclude/*.h ` \
            ) | doxygen -

cccc:
	cccc ./src/*.cxx ./attachComp/*.cxx ./beamline/*.cxx \
            ./bibBuild/*.cxx ./bnctBuild/*.cxx \
            ./build/*.cxx ./chip/*.cxx ./construct/*.cxx \
            ./crystal/*.cxx ./cuBlock/*.cxx \
            ./d4cModel/*.cxx ./delft/*.cxx ./endf/*.cxx \
            ./epbBuild/*.cxx ./essBuild/*.cxx \
            ./funcBase/*.cxx ./geometry/*.cxx \
            ./global/*.cxx ./imat/*.cxx ./input/*.cxx \
            ./instrument/*.cxx ./lensModel/*.cxx \
            ./log/*.cxx ./md5/*.cxx ./moderator/*.cxx \
            ./mersenne/*.cxx ./monte/*.cxx ./muon/*.cxx \
            ./physics/*.cxx ./poly/*.cxx ./process/*.cxx \
            ./scatMat/*.cxx ./sinbadBuild/*.cxx \
            ./snsBuild/*.cxx ./source/*.cxx ./support/*.cxx \
            ./tally/*.cxx ./t1Build/*.cxx ./t1Upgrade/*.cxx \
            ./transport/*.cxx ./visit/*.cxx ./weights/*.cxx \
            ./world/*.cxx ./work/*.cxx ./xml/*.cxx \
            ./zoom/*.cxx ./special/*.cxx ./test/*.cxx \
            ./Main/*.cxx ./include/*.h ./attachCompInc/*.h \
            ./beamlineInc/*.h ./bibBuildInc/*.h \
            ./bnctBuildInc/*.h ./buildInc/*.h ./chipInc/*.h \
            ./constructInc/*.h ./crystalInc/*.h \
            ./cuBlockInc/*.h ./d4cModelInc/*.h \
            ./delftInc/*.h ./endfInc/*.h ./epbBuildInc/*.h \
            ./essBuildInc/*.h ./funcBaseInc/*.h \
            ./geomInc/*.h ./globalInc/*.h ./imatInc/*.h \
            ./inputInc/*.h ./instrumentInc/*.h \
            ./lensModelInc/*.h ./logInc/*.h ./md5Inc/*.h \
            ./mersenneInc/*.h ./moderatorInc/*.h \
            ./monteInc/*.h ./muonInc/*.h ./physicsInc/*.h \
            ./polyInc/*.h ./processInc/*.h ./scatMatInc/*.h \
            ./sinbadBuildInc/*.h ./snsBuildInc/*.h \
            ./sourceInc/*.h ./specialInc/*.h \
            ./supportInc/*.h ./tallyInc/*.h \
            ./t1BuildInc/*.h ./t1UpgradeInc/*.h \
            ./transportInc/*.h ./visitInc/*.h \
            ./weightsInc/*.h ./workInc/*.h ./worldInc/*.h \
            ./xmlInc/*.h ./zoomInc/*.h ./testInclude/*.h 

words:
	grep -v -e '^[[:space:][:cntrl:]]*$$' ./src/*.cxx \
            ./attachComp/*.cxx ./beamline/*.cxx \
            ./bibBuild/*.cxx ./bnctBuild/*.cxx \
            ./build/*.cxx ./chip/*.cxx ./construct/*.cxx \
            ./crystal/*.cxx ./cuBlock/*.cxx \
            ./d4cModel/*.cxx ./delft/*.cxx ./endf/*.cxx \
            ./epbBuild/*.cxx ./essBuild/*.cxx \
            ./funcBase/*.cxx ./geometry/*.cxx \
            ./global/*.cxx ./imat/*.cxx ./input/*.cxx \
            ./instrument/*.cxx ./lensModel/*.cxx \
            ./log/*.cxx ./md5/*.cxx ./moderator/*.cxx \
            ./mersenne/*.cxx ./monte/*.cxx ./muon/*.cxx \
            ./physics/*.cxx ./poly/*.cxx ./process/*.cxx \
            ./scatMat/*.cxx ./sinbadBuild/*.cxx \
            ./snsBuild/*.cxx ./source/*.cxx ./support/*.cxx \
            ./tally/*.cxx ./t1Build/*.cxx ./t1Upgrade/*.cxx \
            ./transport/*.cxx ./visit/*.cxx ./weights/*.cxx \
            ./world/*.cxx ./work/*.cxx ./xml/*.cxx \
            ./zoom/*.cxx ./special/*.cxx ./test/*.cxx \
            ./Main/*.cxx ./include/*.h ./attachCompInc/*.h \
            ./beamlineInc/*.h ./bibBuildInc/*.h \
            ./bnctBuildInc/*.h ./buildInc/*.h ./chipInc/*.h \
            ./constructInc/*.h ./crystalInc/*.h \
            ./cuBlockInc/*.h ./d4cModelInc/*.h \
            ./delftInc/*.h ./endfInc/*.h ./epbBuildInc/*.h \
            ./essBuildInc/*.h ./funcBaseInc/*.h \
            ./geomInc/*.h ./globalInc/*.h ./imatInc/*.h \
            ./inputInc/*.h ./instrumentInc/*.h \
            ./lensModelInc/*.h ./logInc/*.h ./md5Inc/*.h \
            ./mersenneInc/*.h ./moderatorInc/*.h \
            ./monteInc/*.h ./muonInc/*.h ./physicsInc/*.h \
            ./polyInc/*.h ./processInc/*.h ./scatMatInc/*.h \
            ./sinbadBuildInc/*.h ./snsBuildInc/*.h \
            ./sourceInc/*.h ./specialInc/*.h \
            ./supportInc/*.h ./tallyInc/*.h \
            ./t1BuildInc/*.h ./t1UpgradeInc/*.h \
            ./transportInc/*.h ./visitInc/*.h \
            ./weightsInc/*.h ./workInc/*.h ./worldInc/*.h \
            ./xmlInc/*.h ./zoomInc/*.h ./testInclude/*.h  | \
            wc
sloc:
	sloccount ./src/*.cxx ./attachComp/*.cxx ./beamline/*.cxx \
            ./bibBuild/*.cxx ./bnctBuild/*.cxx \
            ./build/*.cxx ./chip/*.cxx ./construct/*.cxx \
            ./crystal/*.cxx ./cuBlock/*.cxx \
            ./d4cModel/*.cxx ./delft/*.cxx ./endf/*.cxx \
            ./epbBuild/*.cxx ./essBuild/*.cxx \
            ./funcBase/*.cxx ./geometry/*.cxx \
            ./global/*.cxx ./imat/*.cxx ./input/*.cxx \
            ./instrument/*.cxx ./lensModel/*.cxx \
            ./log/*.cxx ./md5/*.cxx ./moderator/*.cxx \
            ./mersenne/*.cxx ./monte/*.cxx ./muon/*.cxx \
            ./physics/*.cxx ./poly/*.cxx ./process/*.cxx \
            ./scatMat/*.cxx ./sinbadBuild/*.cxx \
            ./snsBuild/*.cxx ./source/*.cxx ./support/*.cxx \
            ./tally/*.cxx ./t1Build/*.cxx ./t1Upgrade/*.cxx \
            ./transport/*.cxx ./visit/*.cxx ./weights/*.cxx \
            ./world/*.cxx ./work/*.cxx ./xml/*.cxx \
            ./zoom/*.cxx ./special/*.cxx ./test/*.cxx \
            ./Main/*.cxx ./include/*.h ./attachCompInc/*.h \
            ./beamlineInc/*.h ./bibBuildInc/*.h \
            ./bnctBuildInc/*.h ./buildInc/*.h ./chipInc/*.h \
            ./constructInc/*.h ./crystalInc/*.h \
            ./cuBlockInc/*.h ./d4cModelInc/*.h \
            ./delftInc/*.h ./endfInc/*.h ./epbBuildInc/*.h \
            ./essBuildInc/*.h ./funcBaseInc/*.h \
            ./geomInc/*.h ./globalInc/*.h ./imatInc/*.h \
            ./inputInc/*.h ./instrumentInc/*.h \
            ./lensModelInc/*.h ./logInc/*.h ./md5Inc/*.h \
            ./mersenneInc/*.h ./moderatorInc/*.h \
            ./monteInc/*.h ./muonInc/*.h ./physicsInc/*.h \
            ./polyInc/*.h ./processInc/*.h ./scatMatInc/*.h \
            ./sinbadBuildInc/*.h ./snsBuildInc/*.h \
            ./sourceInc/*.h ./specialInc/*.h \
            ./supportInc/*.h ./tallyInc/*.h \
            ./t1BuildInc/*.h ./t1UpgradeInc/*.h \
            ./transportInc/*.h ./visitInc/*.h \
            ./weightsInc/*.h ./workInc/*.h ./worldInc/*.h \
            ./xmlInc/*.h ./zoomInc/*.h ./testInclude/*.h 
unique:
	/home/ansell/exe/C++/uniqLines.pl > AllLines.txt \
            ./src/*.cxx ./attachComp/*.cxx ./beamline/*.cxx \
            ./bibBuild/*.cxx ./bnctBuild/*.cxx \
            ./build/*.cxx ./chip/*.cxx ./construct/*.cxx \
            ./crystal/*.cxx ./cuBlock/*.cxx \
            ./d4cModel/*.cxx ./delft/*.cxx ./endf/*.cxx \
            ./epbBuild/*.cxx ./essBuild/*.cxx \
            ./funcBase/*.cxx ./geometry/*.cxx \
            ./global/*.cxx ./imat/*.cxx ./input/*.cxx \
            ./instrument/*.cxx ./lensModel/*.cxx \
            ./log/*.cxx ./md5/*.cxx ./moderator/*.cxx \
            ./mersenne/*.cxx ./monte/*.cxx ./muon/*.cxx \
            ./physics/*.cxx ./poly/*.cxx ./process/*.cxx \
            ./scatMat/*.cxx ./sinbadBuild/*.cxx \
            ./snsBuild/*.cxx ./source/*.cxx ./support/*.cxx \
            ./tally/*.cxx ./t1Build/*.cxx ./t1Upgrade/*.cxx \
            ./transport/*.cxx ./visit/*.cxx ./weights/*.cxx \
            ./world/*.cxx ./work/*.cxx ./xml/*.cxx \
            ./zoom/*.cxx ./special/*.cxx ./test/*.cxx \
            ./Main/*.cxx ./include/*.h ./attachCompInc/*.h \
            ./beamlineInc/*.h ./bibBuildInc/*.h \
            ./bnctBuildInc/*.h ./buildInc/*.h ./chipInc/*.h \
            ./constructInc/*.h ./crystalInc/*.h \
            ./cuBlockInc/*.h ./d4cModelInc/*.h \
            ./delftInc/*.h ./endfInc/*.h ./epbBuildInc/*.h \
            ./essBuildInc/*.h ./funcBaseInc/*.h \
            ./geomInc/*.h ./globalInc/*.h ./imatInc/*.h \
            ./inputInc/*.h ./instrumentInc/*.h \
            ./lensModelInc/*.h ./logInc/*.h ./md5Inc/*.h \
            ./mersenneInc/*.h ./moderatorInc/*.h \
            ./monteInc/*.h ./muonInc/*.h ./physicsInc/*.h \
            ./polyInc/*.h ./processInc/*.h ./scatMatInc/*.h \
            ./sinbadBuildInc/*.h ./snsBuildInc/*.h \
            ./sourceInc/*.h ./specialInc/*.h \
            ./supportInc/*.h ./tallyInc/*.h \
            ./t1BuildInc/*.h ./t1UpgradeInc/*.h \
            ./transportInc/*.h ./visitInc/*.h \
            ./weightsInc/*.h ./workInc/*.h ./worldInc/*.h \
            ./xmlInc/*.h ./zoomInc/*.h ./testInclude/*.h 

tags:
	etags ./src/*.cxx ./attachComp/*.cxx ./beamline/*.cxx \
            ./bibBuild/*.cxx ./bnctBuild/*.cxx \
            ./build/*.cxx ./chip/*.cxx ./construct/*.cxx \
            ./crystal/*.cxx ./cuBlock/*.cxx \
            ./d4cModel/*.cxx ./delft/*.cxx ./endf/*.cxx \
            ./epbBuild/*.cxx ./essBuild/*.cxx \
            ./funcBase/*.cxx ./geometry/*.cxx \
            ./global/*.cxx ./imat/*.cxx ./input/*.cxx \
            ./instrument/*.cxx ./lensModel/*.cxx \
            ./log/*.cxx ./md5/*.cxx ./moderator/*.cxx \
            ./mersenne/*.cxx ./monte/*.cxx ./muon/*.cxx \
            ./physics/*.cxx ./poly/*.cxx ./process/*.cxx \
            ./scatMat/*.cxx ./sinbadBuild/*.cxx \
            ./snsBuild/*.cxx ./source/*.cxx ./support/*.cxx \
            ./tally/*.cxx ./t1Build/*.cxx ./t1Upgrade/*.cxx \
            ./transport/*.cxx ./visit/*.cxx ./weights/*.cxx \
            ./world/*.cxx ./work/*.cxx ./xml/*.cxx \
            ./zoom/*.cxx ./special/*.cxx ./test/*.cxx \
            ./Main/*.cxx ./include/*.h ./attachCompInc/*.h \
            ./beamlineInc/*.h ./bibBuildInc/*.h \
            ./bnctBuildInc/*.h ./buildInc/*.h ./chipInc/*.h \
            ./constructInc/*.h ./crystalInc/*.h \
            ./cuBlockInc/*.h ./d4cModelInc/*.h \
            ./delftInc/*.h ./endfInc/*.h ./epbBuildInc/*.h \
            ./essBuildInc/*.h ./funcBaseInc/*.h \
            ./geomInc/*.h ./globalInc/*.h ./imatInc/*.h \
            ./inputInc/*.h ./instrumentInc/*.h \
            ./lensModelInc/*.h ./logInc/*.h ./md5Inc/*.h \
            ./mersenneInc/*.h ./moderatorInc/*.h \
            ./monteInc/*.h ./muonInc/*.h ./physicsInc/*.h \
            ./polyInc/*.h ./processInc/*.h ./scatMatInc/*.h \
            ./sinbadBuildInc/*.h ./snsBuildInc/*.h \
            ./sourceInc/*.h ./specialInc/*.h \
            ./supportInc/*.h ./tallyInc/*.h \
            ./t1BuildInc/*.h ./t1UpgradeInc/*.h \
            ./transportInc/*.h ./visitInc/*.h \
            ./weightsInc/*.h ./workInc/*.h ./worldInc/*.h \
            ./xmlInc/*.h ./zoomInc/*.h ./testInclude/*.h 

clean:
	rm -f ./src/*.o ./attachComp/*.o ./beamline/*.o \
            ./bibBuild/*.o ./bnctBuild/*.o ./build/*.o \
            ./chip/*.o ./construct/*.o ./crystal/*.o \
            ./cuBlock/*.o ./d4cModel/*.o ./delft/*.o \
            ./endf/*.o ./epbBuild/*.o ./essBuild/*.o \
            ./funcBase/*.o ./geometry/*.o ./global/*.o \
            ./imat/*.o ./input/*.o ./instrument/*.o \
            ./lensModel/*.o ./log/*.o ./md5/*.o \
            ./moderator/*.o ./mersenne/*.o ./monte/*.o \
            ./muon/*.o ./physics/*.o ./poly/*.o \
            ./process/*.o ./scatMat/*.o ./sinbadBuild/*.o \
            ./snsBuild/*.o ./source/*.o ./support/*.o \
            ./tally/*.o ./t1Build/*.o ./t1Upgrade/*.o \
            ./transport/*.o ./visit/*.o ./weights/*.o \
            ./world/*.o ./work/*.o ./xml/*.o ./zoom/*.o \
            ./special/*.o ./test/*.o ./Main/*.o ./lib/*.so 
