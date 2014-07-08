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

CSRC = PolyFunction.cxx PolyVar.cxx PolyVarOne.cxx \
            solveValues.cxx 

FSRC = 

CINC = 

FINC = 

ODEP = PolyFunction.o PolyVar.o PolyVarOne.o solveValues.o 

all: $(LIBOUTDIR)/libPoly.so 

$(LIBOUTDIR)/libPoly.so : $(ODEP) 
	$(CCOMPL) -fPIC -shared -g  -o $(LIBOUTDIR)/libPoly.so \
       $(ODEP) 

PolyFunction.o: $(SRCDIR)/PolyFunction.cxx $(INCDIRd)/PolyFunction.h \
             $(INCDIRk)/Exception.h $(INCDIRk)/support.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRk) -I$(INCDIRd) \
               $(SRCDIR)/PolyFunction.cxx

PolyVar.o: $(SRCDIR)/PolyVar.cxx $(INCDIRd)/PolyVar.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRk)/mathSupport.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRd)/PolyFunction.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRd) \
               $(INCBOOST) $(SRCDIR)/PolyVar.cxx

PolyVarOne.o: $(SRCDIR)/PolyVarOne.cxx                         \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRe)/masterWrite.h $(INCDIRk)/mathSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRd)/PolyFunction.h $(INCDIRd)/PolyVar.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRQ) -I$(INCDIRk) \
               -I$(INCDIRW) -I$(INCDIRd) $(INCBOOST) $(INCGSL) \
               $(SRCDIR)/PolyVarOne.cxx

solveValues.o: $(SRCDIR)/solveValues.cxx $(INCDIRd)/solveValues.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRk)/mathSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRd)/PolyFunction.h  \
             $(INCDIRd)/PolyVar.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Vec3D.h  \
             $(INCDIRQ)/vecOrder.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               -I$(INCDIRd) $(INCBOOST) $(SRCDIR)/solveValues.cxx

words: 
	grep -v -e '^[[:space:][:cntrl:]]*$$' $(ASRC) | wc 

loc: 
	sloccount $(ASRC) 

cccc: 
	cccc $(ASRC) 

clean:
	rm $(ODEP)

tar:
	tar -zcvf poly.tgz $(ASRC) Doxyfile Makefile getMk.pl getMake.pmtar:
	tar -zcvf poly_core.tgz $(CORESRC) getMk.pl getMake.pm
cost:
	sloccount $(ASRC) Doxyfile Makefile getMk.pl getMake.pm
doxygen:
	(cat Doxyfile; echo "INPUT= $(ASRC)" ) | doxygen -

