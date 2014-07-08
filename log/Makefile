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

CSRC = Debug.cxx debugMethod.cxx EReport.cxx FileReport.cxx \
            MemStack.cxx NameStack.cxx OutputLog.cxx \
            RegMethod.cxx 

FSRC = 

CINC = 

FINC = 

ODEP = Debug.o debugMethod.o EReport.o FileReport.o MemStack.o \
            NameStack.o OutputLog.o RegMethod.o 

all: $(LIBOUTDIR)/libLog.so 

$(LIBOUTDIR)/libLog.so : $(ODEP) 
	$(CCOMPL) -fPIC -shared -g  -o $(LIBOUTDIR)/libLog.so \
       $(ODEP) 

Debug.o: $(SRCDIR)/Debug.cxx $(INCDIRW)/Debug.h
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRW) $(SRCDIR)/Debug.cxx

EReport.o: $(SRCDIR)/EReport.cxx                         \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRk) -I$(INCDIRW) $(SRCDIR)/EReport.cxx

FileReport.o: $(SRCDIR)/FileReport.cxx $(INCDIRW)/FileReport.h \
             $(INCDIRk)/Exception.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRk) -I$(INCDIRW) \
               $(SRCDIR)/FileReport.cxx

MemStack.o: $(SRCDIR)/MemStack.cxx $(INCDIRW)/MemStack.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               -I$(INCDIRR) $(SRCDIR)/MemStack.cxx

NameStack.o: $(SRCDIR)/NameStack.cxx $(INCDIRW)/NameStack.h
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRW) $(SRCDIR)/NameStack.cxx

OutputLog.o: $(SRCDIR)/OutputLog.cxx $(INCDIRW)/OutputLog.h \
             $(INCDIRW)/Debug.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRW)/NameStack.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRk) -I$(INCDIRW) $(INCBOOST) \
               $(SRCDIR)/OutputLog.cxx

RegMethod.o: $(SRCDIR)/RegMethod.cxx $(INCDIRW)/RegMethod.h \
             $(INCDIRW)/NameStack.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRW) $(SRCDIR)/RegMethod.cxx

debugMethod.o: $(SRCDIR)/debugMethod.cxx $(INCDIRW)/debugMethod.h \
             $(INCDIRW)/Debug.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRW) $(SRCDIR)/debugMethod.cxx

words: 
	grep -v -e '^[[:space:][:cntrl:]]*$$' $(ASRC) | wc 

loc: 
	sloccount $(ASRC) 

cccc: 
	cccc $(ASRC) 

clean:
	rm $(ODEP)

tar:
	tar -zcvf log.tgz $(ASRC) Doxyfile Makefile getMk.pl getMake.pmtar:
	tar -zcvf log_core.tgz $(CORESRC) getMk.pl getMake.pm
cost:
	sloccount $(ASRC) Doxyfile Makefile getMk.pl getMake.pm
doxygen:
	(cat Doxyfile; echo "INPUT= $(ASRC)" ) | doxygen -

