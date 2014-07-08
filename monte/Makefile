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

CSRC = Acomp.cxx Algebra.cxx BnId.cxx DBMaterial.cxx Element.cxx \
            HeadRule.cxx IsoTable.cxx LineIntersectVisit.cxx \
            mapIterator.cxx Material.cxx MXcards.cxx neutron.cxx \
            Object.cxx Qhull.cxx RotCounter.cxx RuleBinary.cxx \
            RuleCheck.cxx RuleItems.cxx Rules.cxx RuleSupport.cxx \
            SurfVertex.cxx Token.cxx Track.cxx Zaid.cxx 

FSRC = 

CINC = 

FINC = 

ODEP = Acomp.o Algebra.o BnId.o DBMaterial.o Element.o HeadRule.o \
            IsoTable.o LineIntersectVisit.o mapIterator.o \
            Material.o MXcards.o neutron.o Object.o Qhull.o \
            RotCounter.o RuleBinary.o RuleCheck.o RuleItems.o \
            Rules.o RuleSupport.o SurfVertex.o Token.o Track.o \
            Zaid.o 

all: $(LIBOUTDIR)/libMonte.so 

$(LIBOUTDIR)/libMonte.so : $(ODEP) 
	$(CCOMPL) -fPIC -shared -g  -o $(LIBOUTDIR)/libMonte.so \
       $(ODEP) 

Acomp.o: $(SRCDIR)/Acomp.cxx $(INCDIRa)/Acomp.h \
             $(INCDIRa)/BnId.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRk)/regexSupport.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/RotCounter.h $(INCDIRk)/support.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRa) -I$(INCDIRk) -I$(INCDIRW) \
               $(INCBOOST) $(SRCDIR)/Acomp.cxx

Algebra.o: $(SRCDIR)/Algebra.cxx $(INCDIRa)/Algebra.h \
             $(INCDIRa)/Acomp.h $(INCDIRR)/BaseModVisit.h  \
             $(INCDIRR)/BaseVisit.h $(INCDIRa)/BnId.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/MapSupport.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRk)/support.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRa) -I$(INCDIRk) -I$(INCDIRW) \
               -I$(INCDIRR) $(SRCDIR)/Algebra.cxx

BnId.o: $(SRCDIR)/BnId.cxx $(INCDIRa)/BnId.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRa) -I$(INCDIRk) -I$(INCDIRW) \
               $(SRCDIR)/BnId.cxx

DBMaterial.o: $(SRCDIR)/DBMaterial.cxx $(INCDIRa)/DBMaterial.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRa)/Element.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/Material.h $(INCDIRa)/MXcards.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRa)/Zaid.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRa) -I$(INCDIRk) -I$(INCDIRW) \
               -I$(INCDIRR) $(INCBOOST) $(SRCDIR)/DBMaterial.cxx

Element.o: $(SRCDIR)/Element.cxx $(INCDIRa)/Element.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/IsoTable.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRk)/support.h  \
             $(INCDIRA)/Triple.h $(INCDIRa)/Zaid.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRa) -I$(INCDIRk) \
               -I$(INCDIRW) $(SRCDIR)/Element.cxx

HeadRule.o: $(SRCDIR)/HeadRule.cxx $(INCDIRa)/HeadRule.h \
             $(INCDIRa)/Acomp.h $(INCDIRa)/Algebra.h  \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRa)/BnId.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRQ)/Line.h $(INCDIRa)/LineIntersectVisit.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/MemStack.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/RuleCheck.h $(INCDIRa)/Rules.h  \
             $(INCDIRk)/stringCombine.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRa) -I$(INCDIRk) \
               -I$(INCDIRW) -I$(INCDIRR) $(SRCDIR)/HeadRule.cxx

IsoTable.o: $(SRCDIR)/IsoTable.cxx $(INCDIRa)/IsoTable.h \
             $(INCDIRk)/Exception.h $(INCDIRA)/Triple.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRa) -I$(INCDIRk) \
               $(SRCDIR)/IsoTable.cxx

LineIntersectVisit.o: $(SRCDIR)/LineIntersectVisit.cxx $(INCDIRa)/LineIntersectVisit.h \
             $(INCDIRQ)/ArbPoly.h $(INCDIRR)/BaseModVisit.h  \
             $(INCDIRR)/BaseVisit.h $(INCDIRQ)/Cone.h  \
             $(INCDIRQ)/CylCan.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRQ)/EllipticCyl.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRQ)/General.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRQ)/Line.h  \
             $(INCDIRk)/mathSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRQ)/MBrect.h  \
             $(INCDIRW)/NameStack.h $(INCDIRa)/neutron.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRQ)/Sphere.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/surfFunctors.h $(INCDIRQ)/SurInter.h  \
             $(INCDIRQ)/Torus.h $(INCDIRA)/Triple.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRa) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/LineIntersectVisit.cxx

MXcards.o: $(SRCDIR)/MXcards.cxx $(INCDIRa)/MXcards.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRa)/Element.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRk)/regexSupport.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRa)/Zaid.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRa) -I$(INCDIRk) -I$(INCDIRW) \
               -I$(INCDIRR) $(INCBOOST) $(SRCDIR)/MXcards.cxx

Material.o: $(SRCDIR)/Material.cxx $(INCDIRa)/Material.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRa)/Element.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/MXcards.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRa)/RefCon.h  \
             $(INCDIRk)/regexSupport.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRa)/Zaid.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRa) -I$(INCDIRk) -I$(INCDIRW) \
               -I$(INCDIRR) $(INCBOOST) $(SRCDIR)/Material.cxx

Object.o: $(SRCDIR)/Object.cxx $(INCDIRa)/Object.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRW)/Debug.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRQ)/Line.h  \
             $(INCDIRa)/LineIntersectVisit.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/neutron.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRk)/regexSupport.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/RuleCheck.h $(INCDIRa)/Rules.h  \
             $(INCDIRk)/stringCombine.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/surfIndex.h  \
             $(INCDIRa)/Token.h $(INCDIRa)/Track.h  \
             $(INCDIRQ)/Transform.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRa) -I$(INCDIRk) \
               -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/Object.cxx

Qhull.o: $(SRCDIR)/Qhull.cxx $(INCDIRa)/Qhull.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRQ)/Line.h $(INCDIRQ)/localRotate.h  \
             $(INCDIRA)/masterRotate.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRa)/Object.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRa)/SurfVertex.h  \
             $(INCDIRQ)/SurInter.h $(INCDIRQ)/Transform.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRa) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/Qhull.cxx

RotCounter.o: $(SRCDIR)/RotCounter.cxx $(INCDIRa)/RotCounter.h
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRa) $(SRCDIR)/RotCounter.cxx

RuleBinary.o: $(SRCDIR)/RuleBinary.cxx $(INCDIRa)/RuleBinary.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRa)/BnId.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRk)/mathSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/RotCounter.h $(INCDIRa)/Rules.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/Transform.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRa) -I$(INCDIRk) \
               -I$(INCDIRW) -I$(INCDIRR) $(SRCDIR)/RuleBinary.cxx

RuleCheck.o: $(SRCDIR)/RuleCheck.cxx $(INCDIRa)/RuleCheck.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/mapIterator.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/Rules.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRa) -I$(INCDIRk) \
               -I$(INCDIRW) -I$(INCDIRR) $(SRCDIR)/RuleCheck.cxx

RuleItems.o: $(SRCDIR)/RuleItems.cxx                         \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRa)/Object.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRQ)/Surface.h  \
             $(INCDIRa)/Token.h $(INCDIRa)/Track.h  \
             $(INCDIRQ)/Transform.h $(INCDIRA)/Triple.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRa) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) \
               $(SRCDIR)/RuleItems.cxx

RuleSupport.o: $(SRCDIR)/RuleSupport.cxx $(INCDIRa)/RuleSupport.h \
             $(INCDIRa)/Acomp.h $(INCDIRa)/Algebra.h  \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRa)/BnId.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/HeadRule.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/MemStack.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRa)/RuleCheck.h  \
             $(INCDIRa)/Rules.h $(INCDIRk)/stringCombine.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRQ)/Transform.h  \
             $(INCDIRA)/Triple.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRa) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) \
               $(SRCDIR)/RuleSupport.cxx

Rules.o: $(SRCDIR)/Rules.cxx $(INCDIRa)/Rules.h \
             $(INCDIRa)/Acomp.h $(INCDIRa)/Algebra.h  \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRa)/BnId.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/MemStack.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRQ)/Transform.h  \
             $(INCDIRA)/Triple.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRa) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) \
               $(SRCDIR)/Rules.cxx

SurfVertex.o: $(SRCDIR)/SurfVertex.cxx $(INCDIRa)/SurfVertex.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/Transform.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRa) -I$(INCDIRk) \
               -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/SurfVertex.cxx

Token.o: $(SRCDIR)/Token.cxx $(INCDIRa)/Token.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRa) -I$(INCDIRk) -I$(INCDIRW) \
               $(SRCDIR)/Token.cxx

Track.o: $(SRCDIR)/Track.cxx $(INCDIRa)/Track.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRa)/HeadRule.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRa)/Object.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRa)/Rules.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/Transform.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRa) -I$(INCDIRk) \
               -I$(INCDIRW) -I$(INCDIRR) $(SRCDIR)/Track.cxx

Zaid.o: $(SRCDIR)/Zaid.cxx $(INCDIRa)/Zaid.h \
             $(INCDIRa)/Element.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/IsoTable.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRk)/regexSupport.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRk)/support.h  \
             $(INCDIRA)/Triple.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRa) -I$(INCDIRk) \
               -I$(INCDIRW) $(INCBOOST) $(SRCDIR)/Zaid.cxx

mapIterator.o: $(SRCDIR)/mapIterator.cxx $(INCDIRa)/mapIterator.h
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRa) $(SRCDIR)/mapIterator.cxx

neutron.o: $(SRCDIR)/neutron.cxx $(INCDIRa)/neutron.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRa)/RefCon.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRa) -I$(INCDIRk) \
               -I$(INCDIRW) $(SRCDIR)/neutron.cxx

words: 
	grep -v -e '^[[:space:][:cntrl:]]*$$' $(ASRC) | wc 

loc: 
	sloccount $(ASRC) 

cccc: 
	cccc $(ASRC) 

clean:
	rm $(ODEP)

tar:
	tar -zcvf monte.tgz $(ASRC) Doxyfile Makefile getMk.pl getMake.pmtar:
	tar -zcvf monte_core.tgz $(CORESRC) getMk.pl getMake.pm
cost:
	sloccount $(ASRC) Doxyfile Makefile getMk.pl getMake.pm
doxygen:
	(cat Doxyfile; echo "INPUT= $(ASRC)" ) | doxygen -

