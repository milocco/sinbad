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

CSRC = XMLattribute.cxx XMLcollect.cxx XMLcomment.cxx XMLcomp.cxx \
            XMLdatablock.cxx XMLgrid.cxx XMLgridSupport.cxx \
            XMLgroup.cxx XMLiterator.cxx XMLload.cxx XMLmap.cxx \
            XMLnamespace.cxx XMLobject.cxx XMLread.cxx \
            XMLvector.cxx 

FSRC = 

CINC = 

FINC = 

ODEP = XMLattribute.o XMLcollect.o XMLcomment.o XMLcomp.o \
            XMLdatablock.o XMLgrid.o XMLgridSupport.o XMLgroup.o \
            XMLiterator.o XMLload.o XMLmap.o XMLnamespace.o \
            XMLobject.o XMLread.o XMLvector.o 

all: $(LIBOUTDIR)/libXml.so 

$(LIBOUTDIR)/libXml.so : $(ODEP) 
	$(CCOMPL) -fPIC -shared -g  -o $(LIBOUTDIR)/libXml.so \
       $(ODEP) 

XMLattribute.o: $(SRCDIR)/XMLattribute.cxx $(INCDIRt)/XMLattribute.h \
             $(INCDIRk)/Exception.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRk)/support.h  \
             $(INCDIRt)/XMLload.h $(INCDIRt)/XMLnamespace.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRt) -I$(INCDIRk) \
               $(SRCDIR)/XMLattribute.cxx

XMLcollect.o: $(SRCDIR)/XMLcollect.cxx $(INCDIRt)/XMLcollect.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRk)/fileSupport.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRk)/support.h  \
             $(INCDIRt)/XMLattribute.h $(INCDIRt)/XMLcomment.h  \
             $(INCDIRt)/XMLcomp.h $(INCDIRt)/XMLgrid.h  \
             $(INCDIRt)/XMLgroup.h $(INCDIRt)/XMLload.h  \
             $(INCDIRt)/XMLnamespace.h $(INCDIRt)/XMLobject.h  \
             $(INCDIRt)/XMLread.h $(INCDIRt)/XMLvector.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRt) -I$(INCDIRk) -I$(INCDIRW) \
               $(INCBOOST) $(SRCDIR)/XMLcollect.cxx

XMLcomment.o: $(SRCDIR)/XMLcomment.cxx $(INCDIRt)/XMLcomment.h \
             $(INCDIRk)/Exception.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Vec3D.h $(INCDIRt)/XMLattribute.h  \
             $(INCDIRt)/XMLgroup.h $(INCDIRt)/XMLload.h  \
             $(INCDIRt)/XMLnamespace.h $(INCDIRt)/XMLobject.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRt) -I$(INCDIRk) \
               $(SRCDIR)/XMLcomment.cxx

XMLcomp.o: $(SRCDIR)/XMLcomp.cxx $(INCDIRt)/XMLcomp.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Vec3D.h $(INCDIRt)/XMLattribute.h  \
             $(INCDIRt)/XMLgroup.h $(INCDIRt)/XMLload.h  \
             $(INCDIRt)/XMLnamespace.h $(INCDIRt)/XMLobject.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRt) -I$(INCDIRk) \
               -I$(INCDIRW) $(SRCDIR)/XMLcomp.cxx

XMLdatablock.o: $(SRCDIR)/XMLdatablock.cxx $(INCDIRt)/XMLdatablock.h \
             $(INCDIRk)/doubleErr.h $(INCDIRk)/Exception.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Vec3D.h  \
             $(INCDIRt)/XMLattribute.h $(INCDIRt)/XMLgroup.h  \
             $(INCDIRt)/XMLload.h $(INCDIRt)/XMLnamespace.h  \
             $(INCDIRt)/XMLobject.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRt) -I$(INCDIRk) \
               $(INCBOOST) $(SRCDIR)/XMLdatablock.cxx

XMLgrid.o: $(SRCDIR)/XMLgrid.cxx $(INCDIRt)/XMLgrid.h \
             $(INCDIRk)/Exception.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Vec3D.h $(INCDIRt)/XMLattribute.h  \
             $(INCDIRt)/XMLgroup.h $(INCDIRt)/XMLload.h  \
             $(INCDIRt)/XMLnamespace.h $(INCDIRt)/XMLobject.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRt) -I$(INCDIRk) \
               $(SRCDIR)/XMLgrid.cxx

XMLgridSupport.o: $(SRCDIR)/XMLgridSupport.cxx                         \
             $(INCDIRk)/Exception.h $(INCDIRt)/XMLattribute.h  \
             $(INCDIRt)/XMLcollect.h $(INCDIRt)/XMLgrid.h  \
             $(INCDIRt)/XMLgroup.h $(INCDIRt)/XMLload.h  \
             $(INCDIRt)/XMLnamespace.h $(INCDIRt)/XMLobject.h  \
             $(INCDIRt)/XMLread.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRt) -I$(INCDIRk) $(INCBOOST) \
               $(SRCDIR)/XMLgridSupport.cxx

XMLgroup.o: $(SRCDIR)/XMLgroup.cxx $(INCDIRt)/XMLgroup.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Vec3D.h $(INCDIRt)/XMLattribute.h  \
             $(INCDIRt)/XMLcomp.h $(INCDIRt)/XMLgrid.h  \
             $(INCDIRt)/XMLload.h $(INCDIRt)/XMLnamespace.h  \
             $(INCDIRt)/XMLobject.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRt) -I$(INCDIRk) \
               -I$(INCDIRW) $(INCBOOST) $(SRCDIR)/XMLgroup.cxx

XMLiterator.o: $(SRCDIR)/XMLiterator.cxx $(INCDIRt)/XMLiterator.h \
             $(INCDIRk)/Exception.h $(INCDIRt)/XMLattribute.h  \
             $(INCDIRt)/XMLcollect.h $(INCDIRt)/XMLcomp.h  \
             $(INCDIRt)/XMLgrid.h $(INCDIRt)/XMLgroup.h  \
             $(INCDIRt)/XMLload.h $(INCDIRt)/XMLnamespace.h  \
             $(INCDIRt)/XMLobject.h $(INCDIRt)/XMLvector.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRt) -I$(INCDIRk) \
               $(SRCDIR)/XMLiterator.cxx

XMLload.o: $(SRCDIR)/XMLload.cxx $(INCDIRt)/XMLload.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRt) -I$(INCDIRk) \
               -I$(INCDIRW) $(SRCDIR)/XMLload.cxx

XMLmap.o: $(SRCDIR)/XMLmap.cxx $(INCDIRt)/XMLmap.h \
             $(INCDIRk)/Exception.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Vec3D.h $(INCDIRt)/XMLattribute.h  \
             $(INCDIRt)/XMLgroup.h $(INCDIRt)/XMLload.h  \
             $(INCDIRt)/XMLnamespace.h $(INCDIRt)/XMLobject.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRt) -I$(INCDIRk) \
               $(SRCDIR)/XMLmap.cxx

XMLnamespace.o: $(SRCDIR)/XMLnamespace.cxx $(INCDIRt)/XMLnamespace.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRk)/regexSupport.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Vec3D.h $(INCDIRt)/XMLattribute.h  \
             $(INCDIRt)/XMLcollect.h $(INCDIRt)/XMLcomp.h  \
             $(INCDIRt)/XMLgroup.h $(INCDIRt)/XMLiterator.h  \
             $(INCDIRt)/XMLload.h $(INCDIRt)/XMLobject.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRt) -I$(INCDIRk) \
               -I$(INCDIRW) $(INCBOOST) $(SRCDIR)/XMLnamespace.cxx

XMLobject.o: $(SRCDIR)/XMLobject.cxx $(INCDIRt)/XMLobject.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Vec3D.h  \
             $(INCDIRt)/XMLattribute.h $(INCDIRt)/XMLcomp.h  \
             $(INCDIRt)/XMLgroup.h $(INCDIRt)/XMLread.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRt) -I$(INCDIRk) \
               -I$(INCDIRW) $(INCBOOST) $(SRCDIR)/XMLobject.cxx

XMLread.o: $(SRCDIR)/XMLread.cxx $(INCDIRt)/XMLread.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRA)/RefControl.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Vec3D.h $(INCDIRt)/XMLattribute.h  \
             $(INCDIRt)/XMLgroup.h $(INCDIRt)/XMLload.h  \
             $(INCDIRt)/XMLnamespace.h $(INCDIRt)/XMLobject.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRt) \
               -I$(INCDIRk) -I$(INCDIRW) $(INCBOOST) \
               $(SRCDIR)/XMLread.cxx

XMLvector.o: $(SRCDIR)/XMLvector.cxx $(INCDIRt)/XMLvector.h \
             $(INCDIRk)/Exception.h $(INCDIRk)/support.h  \
             $(INCDIRt)/XMLattribute.h $(INCDIRt)/XMLgroup.h  \
             $(INCDIRt)/XMLload.h $(INCDIRt)/XMLnamespace.h  \
             $(INCDIRt)/XMLobject.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRt) -I$(INCDIRk) \
               $(SRCDIR)/XMLvector.cxx

words: 
	grep -v -e '^[[:space:][:cntrl:]]*$$' $(ASRC) | wc 

loc: 
	sloccount $(ASRC) 

cccc: 
	cccc $(ASRC) 

clean:
	rm $(ODEP)

tar:
	tar -zcvf xml.tgz $(ASRC) Doxyfile Makefile getMk.pl getMake.pmtar:
	tar -zcvf xml_core.tgz $(CORESRC) getMk.pl getMake.pm
cost:
	sloccount $(ASRC) Doxyfile Makefile getMk.pl getMake.pm
doxygen:
	(cat Doxyfile; echo "INPUT= $(ASRC)" ) | doxygen -

