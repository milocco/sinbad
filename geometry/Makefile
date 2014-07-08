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

CSRC = ArbPoly.cxx Circle.cxx Cone.cxx Convex.cxx Convex2D.cxx \
            CylCan.cxx Cylinder.cxx DblLine.cxx Edge.cxx \
            Ellipse.cxx EllipticCyl.cxx Face.cxx General.cxx \
            Intersect.cxx Line.cxx localRotate.cxx MBrect.cxx \
            MeshGrid.cxx NullSurface.cxx Plane.cxx Pnt.cxx \
            PointOperation.cxx Quadratic.cxx Quadrilateral.cxx \
            Quaternion.cxx RecTriangle.cxx SglLine.cxx Sphere.cxx \
            Surface.cxx surfaceFactory.cxx surfFunctors.cxx \
            surfIndex.cxx SurfLine.cxx surfProg.cxx SurInter.cxx \
            Torus.cxx Transform.cxx Triangle.cxx Vec3D.cxx \
            Vert2D.cxx Vertex.cxx 

FSRC = 

CINC = 

FINC = 

ODEP = ArbPoly.o Circle.o Cone.o Convex.o Convex2D.o CylCan.o \
            Cylinder.o DblLine.o Edge.o Ellipse.o EllipticCyl.o \
            Face.o General.o Intersect.o Line.o localRotate.o \
            MBrect.o MeshGrid.o NullSurface.o Plane.o Pnt.o \
            PointOperation.o Quadratic.o Quadrilateral.o \
            Quaternion.o RecTriangle.o SglLine.o Sphere.o \
            Surface.o surfaceFactory.o surfFunctors.o surfIndex.o \
            SurfLine.o surfProg.o SurInter.o Torus.o Transform.o \
            Triangle.o Vec3D.o Vert2D.o Vertex.o 

all: $(LIBOUTDIR)/libGeometry.so 

$(LIBOUTDIR)/libGeometry.so : $(ODEP) 
	$(CCOMPL) -fPIC -shared -g  -o $(LIBOUTDIR)/libGeometry.so \
       $(ODEP) 

ArbPoly.o: $(SRCDIR)/ArbPoly.cxx $(INCDIRQ)/ArbPoly.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRQ)/Line.h  \
             $(INCDIRk)/mathSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/Transform.h $(INCDIRA)/Triple.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRk) \
               -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/ArbPoly.cxx

Circle.o: $(SRCDIR)/Circle.cxx $(INCDIRQ)/Circle.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRQ)/Intersect.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               -I$(INCDIRR) $(SRCDIR)/Circle.cxx

Cone.o: $(SRCDIR)/Cone.cxx $(INCDIRQ)/Cone.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRQ)/Line.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               -I$(INCDIRR) $(INCBOOST) $(SRCDIR)/Cone.cxx

Convex.o: $(SRCDIR)/Convex.cxx $(INCDIRQ)/Convex.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRQ)/Edge.h $(INCDIRk)/Exception.h  \
             $(INCDIRQ)/Face.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/Vec3D.h $(INCDIRQ)/Vertex.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               -I$(INCDIRR) $(INCBOOST) $(SRCDIR)/Convex.cxx

Convex2D.o: $(SRCDIR)/Convex2D.cxx $(INCDIRQ)/Convex2D.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/SVD.h $(INCDIRQ)/Vec3D.h  \
             $(INCDIRQ)/Vert2D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               $(INCBOOST) $(SRCDIR)/Convex2D.cxx

CylCan.o: $(SRCDIR)/CylCan.cxx $(INCDIRQ)/CylCan.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRQ)/Line.h $(INCDIRk)/mathSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               -I$(INCDIRR) $(INCBOOST) $(SRCDIR)/CylCan.cxx

Cylinder.o: $(SRCDIR)/Cylinder.cxx $(INCDIRQ)/Cylinder.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRW)/Debug.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRQ)/Line.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRk)/regexSupport.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               -I$(INCDIRR) $(INCBOOST) $(SRCDIR)/Cylinder.cxx

DblLine.o: $(SRCDIR)/DblLine.cxx $(INCDIRQ)/DblLine.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRQ)/Intersect.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               $(SRCDIR)/DblLine.cxx

Edge.o: $(SRCDIR)/Edge.cxx $(INCDIRQ)/Edge.h \
             $(INCDIRk)/Exception.h $(INCDIRQ)/Face.h  \
             $(INCDIRW)/FileReport.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRQ)/Vec3D.h  \
             $(INCDIRQ)/Vertex.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               $(SRCDIR)/Edge.cxx

Ellipse.o: $(SRCDIR)/Ellipse.cxx $(INCDIRQ)/Ellipse.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRQ)/Intersect.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               $(SRCDIR)/Ellipse.cxx

EllipticCyl.o: $(SRCDIR)/EllipticCyl.cxx $(INCDIRQ)/EllipticCyl.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRW)/Debug.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRQ)/Line.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRk)/regexSupport.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               -I$(INCDIRR) $(INCBOOST) $(SRCDIR)/EllipticCyl.cxx

Face.o: $(SRCDIR)/Face.cxx $(INCDIRQ)/Face.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Binary.h $(INCDIRQ)/Edge.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/Vec3D.h  \
             $(INCDIRQ)/Vertex.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               -I$(INCDIRR) $(SRCDIR)/Face.cxx

General.o: $(SRCDIR)/General.cxx $(INCDIRQ)/General.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRk)/regexSupport.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               -I$(INCDIRR) $(INCBOOST) $(SRCDIR)/General.cxx

Intersect.o: $(SRCDIR)/Intersect.cxx $(INCDIRQ)/Intersect.h \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) \
               $(SRCDIR)/Intersect.cxx

Line.o: $(SRCDIR)/Line.cxx $(INCDIRQ)/Line.h \
             $(INCDIRQ)/ArbPoly.h $(INCDIRR)/BaseModVisit.h  \
             $(INCDIRR)/BaseVisit.h $(INCDIRQ)/Cone.h  \
             $(INCDIRQ)/CylCan.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRQ)/EllipticCyl.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRa)/LineIntersectVisit.h $(INCDIRk)/mathSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRQ)/MBrect.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRk)/polySupport.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRQ)/Sphere.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/Torus.h  \
             $(INCDIRQ)/Transform.h $(INCDIRA)/Triple.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRa) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/Line.cxx

MBrect.o: $(SRCDIR)/MBrect.cxx $(INCDIRQ)/MBrect.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRQ)/Line.h  \
             $(INCDIRk)/mathSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRA)/Triple.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRk) \
               -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/MBrect.cxx

MeshGrid.o: $(SRCDIR)/MeshGrid.cxx $(INCDIRQ)/MeshGrid.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               $(SRCDIR)/MeshGrid.cxx

NullSurface.o: $(SRCDIR)/NullSurface.cxx $(INCDIRQ)/NullSurface.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/mathSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/Transform.h  \
             $(INCDIRA)/Triple.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRk) \
               -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/NullSurface.cxx

Plane.o: $(SRCDIR)/Plane.cxx $(INCDIRQ)/Plane.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRe)/masterWrite.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/MemStack.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRQ) -I$(INCDIRk) \
               -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) $(SRCDIR)/Plane.cxx

Pnt.o: $(SRCDIR)/Pnt.cxx $(INCDIRQ)/Pnt.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRQ)/Intersect.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               $(SRCDIR)/Pnt.cxx

PointOperation.o: $(SRCDIR)/PointOperation.cxx                         \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/surfProg.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) \
               $(SRCDIR)/PointOperation.cxx

Quadratic.o: $(SRCDIR)/Quadratic.cxx $(INCDIRQ)/Quadratic.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/mathSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRd)/PolyFunction.h  \
             $(INCDIRd)/PolyVar.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               -I$(INCDIRR) -I$(INCDIRd) $(INCBOOST) \
               $(SRCDIR)/Quadratic.cxx

Quadrilateral.o: $(SRCDIR)/Quadrilateral.cxx $(INCDIRQ)/Quadrilateral.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               $(SRCDIR)/Quadrilateral.cxx

Quaternion.o: $(SRCDIR)/Quaternion.cxx $(INCDIRQ)/Quaternion.h \
             $(INCDIRk)/Exception.h $(INCDIRk)/mathSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) $(INCBOOST) \
               $(SRCDIR)/Quaternion.cxx

RecTriangle.o: $(SRCDIR)/RecTriangle.cxx $(INCDIRQ)/RecTriangle.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Quadrilateral.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRQ)/Triangle.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               $(SRCDIR)/RecTriangle.cxx

SglLine.o: $(SRCDIR)/SglLine.cxx $(INCDIRQ)/SglLine.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRQ)/Intersect.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               $(SRCDIR)/SglLine.cxx

Sphere.o: $(SRCDIR)/Sphere.cxx $(INCDIRQ)/Sphere.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRk)/regexSupport.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               -I$(INCDIRR) $(INCBOOST) $(SRCDIR)/Sphere.cxx

SurInter.o: $(SRCDIR)/SurInter.cxx $(INCDIRQ)/SurInter.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRQ)/Circle.h $(INCDIRQ)/Cone.h  \
             $(INCDIRQ)/Cylinder.h $(INCDIRQ)/DblLine.h  \
             $(INCDIRW)/Debug.h $(INCDIRQ)/Ellipse.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRQ)/General.h $(INCDIRQ)/Intersect.h  \
             $(INCDIRQ)/Line.h $(INCDIRk)/mathSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRQ)/Pnt.h  \
             $(INCDIRd)/PolyFunction.h $(INCDIRd)/PolyVar.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRQ)/SglLine.h $(INCDIRd)/solveValues.h  \
             $(INCDIRQ)/Sphere.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/Transform.h  \
             $(INCDIRQ)/Vec3D.h $(INCDIRQ)/vecOrder.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               -I$(INCDIRR) -I$(INCDIRd) $(INCBOOST) \
               $(SRCDIR)/SurInter.cxx

SurfLine.o: $(SRCDIR)/SurfLine.cxx                         \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRQ)/Line.h $(INCDIRa)/LineIntersectVisit.h  \
             $(INCDIRk)/mathSupport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRd)/PolyFunction.h  \
             $(INCDIRd)/PolyVar.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRd)/solveValues.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/surfIndex.h $(INCDIRQ)/Transform.h  \
             $(INCDIRQ)/Vec3D.h $(INCDIRQ)/vecOrder.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRa) -I$(INCDIRk) \
               -I$(INCDIRW) -I$(INCDIRR) -I$(INCDIRd) $(INCBOOST) \
               $(SRCDIR)/SurfLine.cxx

Surface.o: $(SRCDIR)/Surface.cxx $(INCDIRQ)/Surface.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRQ)/Line.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Transform.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               -I$(INCDIRR) $(SRCDIR)/Surface.cxx

Torus.o: $(SRCDIR)/Torus.cxx $(INCDIRQ)/Torus.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               -I$(INCDIRR) $(INCBOOST) $(SRCDIR)/Torus.cxx

Transform.o: $(SRCDIR)/Transform.cxx $(INCDIRQ)/Transform.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRe)/masterWrite.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRk)/regexSupport.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRQ) -I$(INCDIRk) \
               -I$(INCDIRW) $(INCBOOST) $(SRCDIR)/Transform.cxx

Triangle.o: $(SRCDIR)/Triangle.cxx $(INCDIRQ)/Triangle.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               -I$(INCDIRR) $(SRCDIR)/Triangle.cxx

Vec3D.o: $(SRCDIR)/Vec3D.cxx $(INCDIRQ)/Vec3D.h \
             $(INCDIRk)/Exception.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) $(SRCDIR)/Vec3D.cxx

Vert2D.o: $(SRCDIR)/Vert2D.cxx $(INCDIRQ)/Vert2D.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               $(SRCDIR)/Vert2D.cxx

Vertex.o: $(SRCDIR)/Vertex.cxx $(INCDIRQ)/Vertex.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               $(SRCDIR)/Vertex.cxx

localRotate.o: $(SRCDIR)/localRotate.cxx $(INCDIRQ)/localRotate.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/mathSupport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/NameStack.h $(INCDIRW)/OutputLog.h  \
             $(INCDIRQ)/Plane.h $(INCDIRQ)/Quadratic.h  \
             $(INCDIRQ)/Quaternion.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRA)/transComp.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRk) \
               -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/localRotate.cxx

surfFunctors.o: $(SRCDIR)/surfFunctors.cxx $(INCDIRQ)/surfFunctors.h \
             $(INCDIRR)/BaseModVisit.h $(INCDIRR)/BaseVisit.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRQ)/Line.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/Transform.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               -I$(INCDIRR) $(SRCDIR)/surfFunctors.cxx

surfIndex.o: $(SRCDIR)/surfIndex.cxx $(INCDIRQ)/surfIndex.h \
             $(INCDIRQ)/ArbPoly.h $(INCDIRR)/BaseModVisit.h  \
             $(INCDIRR)/BaseVisit.h $(INCDIRQ)/Cone.h  \
             $(INCDIRQ)/CylCan.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRW)/Debug.h $(INCDIRQ)/EllipticCyl.h  \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRQ)/General.h $(INCDIRW)/GTKreport.h  \
             $(INCDIRk)/Matrix.h $(INCDIRk)/MatrixBase.h  \
             $(INCDIRQ)/MBrect.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRk)/regexSupport.h $(INCDIRW)/RegMethod.h  \
             $(INCDIRQ)/Sphere.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Surface.h $(INCDIRQ)/surfaceFactory.h  \
             $(INCDIRe)/surfEqual.h $(INCDIRe)/surfRegister.h  \
             $(INCDIRQ)/Torus.h $(INCDIRA)/Triple.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRe) -I$(INCDIRA) -I$(INCDIRQ) \
               -I$(INCDIRk) -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/surfIndex.cxx

surfProg.o: $(SRCDIR)/surfProg.cxx $(INCDIRQ)/surfProg.h \
             $(INCDIRk)/Exception.h $(INCDIRW)/FileReport.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRW)/NameStack.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRk)/regexSupport.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRk)/support.h  \
             $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRQ) -I$(INCDIRk) -I$(INCDIRW) \
               $(INCBOOST) $(SRCDIR)/surfProg.cxx

surfaceFactory.o: $(SRCDIR)/surfaceFactory.cxx $(INCDIRQ)/surfaceFactory.h \
             $(INCDIRQ)/ArbPoly.h $(INCDIRR)/BaseModVisit.h  \
             $(INCDIRR)/BaseVisit.h $(INCDIRQ)/Cone.h  \
             $(INCDIRQ)/CylCan.h $(INCDIRQ)/Cylinder.h  \
             $(INCDIRQ)/EllipticCyl.h $(INCDIRk)/Exception.h  \
             $(INCDIRW)/FileReport.h $(INCDIRQ)/General.h  \
             $(INCDIRW)/GTKreport.h $(INCDIRk)/Matrix.h  \
             $(INCDIRk)/MatrixBase.h $(INCDIRQ)/MBrect.h  \
             $(INCDIRW)/NameStack.h $(INCDIRQ)/NullSurface.h  \
             $(INCDIRW)/OutputLog.h $(INCDIRQ)/Plane.h  \
             $(INCDIRQ)/Quadratic.h $(INCDIRQ)/Quaternion.h  \
             $(INCDIRW)/RegMethod.h $(INCDIRQ)/Sphere.h  \
             $(INCDIRk)/support.h $(INCDIRQ)/Surface.h  \
             $(INCDIRQ)/surfVector.h $(INCDIRQ)/Torus.h  \
             $(INCDIRA)/Triple.h $(INCDIRQ)/Vec3D.h 
	$(CCOMPL) -c $(CFLAGC) -I$(INCDIRA) -I$(INCDIRQ) -I$(INCDIRk) \
               -I$(INCDIRW) -I$(INCDIRR) $(INCBOOST) \
               $(SRCDIR)/surfaceFactory.cxx

words: 
	grep -v -e '^[[:space:][:cntrl:]]*$$' $(ASRC) | wc 

loc: 
	sloccount $(ASRC) 

cccc: 
	cccc $(ASRC) 

clean:
	rm $(ODEP)

tar:
	tar -zcvf geometry.tgz $(ASRC) Doxyfile Makefile getMk.pl getMake.pmtar:
	tar -zcvf geometry_core.tgz $(CORESRC) getMk.pl getMake.pm
cost:
	sloccount $(ASRC) Doxyfile Makefile getMk.pl getMake.pm
doxygen:
	(cat Doxyfile; echo "INPUT= $(ASRC)" ) | doxygen -

