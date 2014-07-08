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

CSRC = Binary.cxx ClebschGordan.cxx cycIterator.cxx doubleErr.cxx \
            Exception.cxx fileSupport.cxx InputControl.cxx \
            mathSupport.cxx Matrix.cxx MatrixBase.cxx \
            polySupport.cxx regexSupport.cxx stringCombine.cxx \
            support.cxx SVD.cxx Tensor.cxx 

FSRC = 

CINC = 

FINC = 

ODEP = Binary.o ClebschGordan.o cycIterator.o doubleErr.o \
            Exception.o fileSupport.o InputControl.o \
            mathSupport.o Matrix.o MatrixBase.o polySupport.o \
            regexSupport.o stringCombine.o support.o SVD.o \
            Tensor.o 

all: $(LIBOUTDIR)/libSupport.so 

$(LIBOUTDIR)/libSupport.so : $(ODEP) 
	$(CCOMPL) -fPIC -shared -g  -o $(LIBOUTDIR)/libSupport.so \
       $(ODEP) 

Binary.o: $(SRCDIR)/Binary.cxx $(INCDIRk)/Binary.h
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRk) $(SRCDIR)/Binary.cxx

ClebschGordan.o: $(SRCDIR)/ClebschGordan.cxx $(INCDIRk)/ClebschGordan.h \
             $(INCDIRk)/Exception.h $(INCDIRk)/mathSupport.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRk) $(SRCDIR)/ClebschGordan.cxx

Exception.o: $(SRCDIR)/Exception.cxx $(INCDIRk)/Exception.h \
             $(INCDIRW)/FileReport.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               $(SRCDIR)/Exception.cxx

InputControl.o: $(SRCDIR)/InputControl.cxx $(INCDIRk)/InputControl.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               $(SRCDIR)/InputControl.cxx

Matrix.o: $(SRCDIR)/Matrix.cxx $(INCDIRk)/Matrix.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/mathSupport.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               $(SRCDIR)/Matrix.cxx

MatrixBase.o: $(SRCDIR)/MatrixBase.cxx $(INCDIRk)/MatrixBase.h \
             $(INCDIRk)/Exception.h $(INCDIRk)/mathSupport.h  \
             $(INCDIRd)/PolyFunction.h $(INCDIRd)/PolyVar.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRk) -I$(INCDIRd) $(INCBOOST) \
               $(SRCDIR)/MatrixBase.cxx

SVD.o: $(SRCDIR)/SVD.cxx $(INCDIRk)/SVD.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRk) -I$(INCDIRW) $(INCGSL) \
               $(SRCDIR)/SVD.cxx

Tensor.o: $(SRCDIR)/Tensor.cxx $(INCDIRk)/Tensor.h
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRk) $(SRCDIR)/Tensor.cxx

cycIterator.o: $(SRCDIR)/cycIterator.cxx $(INCDIRk)/cycIterator.h \
             $(INCDIRk)/Exception.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRk) $(SRCDIR)/cycIterator.cxx

doubleErr.o: $(SRCDIR)/doubleErr.cxx $(INCDIRk)/doubleErr.h \
             $(INCDIRk)/support.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRk) $(SRCDIR)/doubleErr.cxx

fileSupport.o: $(SRCDIR)/fileSupport.cxx $(INCDIRk)/fileSupport.h \
             $(INCDIRk)/doubleErr.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRk)/mathSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               $(SRCDIR)/fileSupport.cxx

mathSupport.o: $(SRCDIR)/mathSupport.cxx $(INCDIRk)/mathSupport.h \
             $(INCDIRk)/doubleErr.h $(INCDIRk)/Exception.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRk) $(SRCDIR)/mathSupport.cxx

polySupport.o: $(SRCDIR)/polySupport.cxx $(INCDIRk)/polySupport.h \
             $(INCDIRk)/Exception.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRk) $(SRCDIR)/polySupport.cxx

regexSupport.o: $(SRCDIR)/regexSupport.cxx $(INCDIRk)/regexSupport.h \
             $(INCDIRk)/support.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRk) $(INCBOOST) \
               $(SRCDIR)/regexSupport.cxx

stringCombine.o: $(SRCDIR)/stringCombine.cxx                         \
             $(INCDIRk)/doubleErr.h $(INCDIRk)/Exception.h  \
             $(INCDIRk)/mathSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) \
               $(SRCDIR)/stringCombine.cxx

support.o: $(SRCDIR)/support.cxx $(INCDIRk)/support.h \
             $(INCDIRk)/doubleErr.h $(INCDIRk)/Exception.h  \
             $(INCDIRk)/mathSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) $(SRCDIR)/support.cxx

words: 
	grep -v -e '^[[:space:][:cntrl:]]*$$' $(ASRC) | wc 

loc: 
	sloccount $(ASRC) 

cccc: 
	cccc $(ASRC) 

clean:
	rm $(ODEP)

tar:
	tar -zcvf support.tgz $(ASRC) Doxyfile Makefile getMk.pl getMake.pmtar:
	tar -zcvf support_core.tgz $(CORESRC) getMk.pl getMake.pm
cost:
	sloccount $(ASRC) Doxyfile Makefile getMk.pl getMake.pm
doxygen:
	(cat Doxyfile; echo "INPUT= $(ASRC)" ) | doxygen -

