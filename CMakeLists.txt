cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_COMPILER clang)
add_definitions(-fPIC -Wconversion -W -Wall -Wextra -Wno-comment -fexceptions -std=c++11)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ./lib)

include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/beamlineInc")
include_directories("${PROJECT_SOURCE_DIR}/globalInc")
include_directories("${PROJECT_SOURCE_DIR}/instrumentInc")
include_directories("${PROJECT_SOURCE_DIR}/scatMatInc")
include_directories("${PROJECT_SOURCE_DIR}/specialInc")
include_directories("${PROJECT_SOURCE_DIR}/transportInc")
include_directories("${PROJECT_SOURCE_DIR}/testInclude")
include_directories("${PROJECT_SOURCE_DIR}/System/attachCompInc")
include_directories("${PROJECT_SOURCE_DIR}/System/compWeightsInc")
include_directories("${PROJECT_SOURCE_DIR}/System/constructInc")
include_directories("${PROJECT_SOURCE_DIR}/System/crystalInc")
include_directories("${PROJECT_SOURCE_DIR}/System/endfInc")
include_directories("${PROJECT_SOURCE_DIR}/System/funcBaseInc")
include_directories("${PROJECT_SOURCE_DIR}/System/geomInc")
include_directories("${PROJECT_SOURCE_DIR}/System/inputInc")
include_directories("${PROJECT_SOURCE_DIR}/System/logInc")
include_directories("${PROJECT_SOURCE_DIR}/System/md5Inc")
include_directories("${PROJECT_SOURCE_DIR}/System/mersenneInc")
include_directories("${PROJECT_SOURCE_DIR}/System/monteInc")
include_directories("${PROJECT_SOURCE_DIR}/System/physicsInc")
include_directories("${PROJECT_SOURCE_DIR}/System/polyInc")
include_directories("${PROJECT_SOURCE_DIR}/System/processInc")
include_directories("${PROJECT_SOURCE_DIR}/System/simMCInc")
include_directories("${PROJECT_SOURCE_DIR}/System/sourceInc")
include_directories("${PROJECT_SOURCE_DIR}/System/supportInc")
include_directories("${PROJECT_SOURCE_DIR}/System/tallyInc")
include_directories("${PROJECT_SOURCE_DIR}/System/visitInc")
include_directories("${PROJECT_SOURCE_DIR}/System/weightsInc")
include_directories("${PROJECT_SOURCE_DIR}/System/workInc")
include_directories("${PROJECT_SOURCE_DIR}/System/worldInc")
include_directories("${PROJECT_SOURCE_DIR}/System/xmlInc")
include_directories("${PROJECT_SOURCE_DIR}/Model/bibBuildInc")
include_directories("${PROJECT_SOURCE_DIR}/Model/bnctBuildInc")
include_directories("${PROJECT_SOURCE_DIR}/Model/buildInc")
include_directories("${PROJECT_SOURCE_DIR}/Model/chipInc")
include_directories("${PROJECT_SOURCE_DIR}/Model/cuBlockInc")
include_directories("${PROJECT_SOURCE_DIR}/Model/d4cModelInc")
include_directories("${PROJECT_SOURCE_DIR}/Model/delftInc")
include_directories("${PROJECT_SOURCE_DIR}/Model/epbBuildInc")
include_directories("${PROJECT_SOURCE_DIR}/Model/essBuildInc")
include_directories("${PROJECT_SOURCE_DIR}/Model/gammaBuildInc")
include_directories("${PROJECT_SOURCE_DIR}/Model/imatInc")
include_directories("${PROJECT_SOURCE_DIR}/Model/lensModelInc")
include_directories("${PROJECT_SOURCE_DIR}/Model/moderatorInc")
include_directories("${PROJECT_SOURCE_DIR}/Model/muonInc")
include_directories("${PROJECT_SOURCE_DIR}/Model/photonInc")
include_directories("${PROJECT_SOURCE_DIR}/Model/pipeBuildInc")
include_directories("${PROJECT_SOURCE_DIR}/Model/sinbadBuildInc")
include_directories("${PROJECT_SOURCE_DIR}/Model/snsBuildInc")
include_directories("${PROJECT_SOURCE_DIR}/Model/t1BuildInc")
include_directories("${PROJECT_SOURCE_DIR}/Model/t1EngineerInc")
include_directories("${PROJECT_SOURCE_DIR}/Model/t1UpgradeInc")
include_directories("${PROJECT_SOURCE_DIR}/Model/t3ModelInc")
include_directories("${PROJECT_SOURCE_DIR}/Model/zoomInc")
include_directories("${PROJECT_SOURCE_DIR}/Model/ESSBeam/lokiInc")
include_directories("${PROJECT_SOURCE_DIR}/Model/ESSBeam/nmxInc")
include_directories("${PROJECT_SOURCE_DIR}/Model/ESSBeam/odinInc")
include_directories("${PROJECT_SOURCE_DIR}/Model/ESSBeam/vorInc")
## END INCLUDES 

## GLOBS 
file(GLOB transport "${PROJECT_SOURCE_DIR}/transport/*.cxx")
add_library(libtransport SHARED ${transport})
file(GLOB src "${PROJECT_SOURCE_DIR}/src/*.cxx")
add_library(libsrc SHARED ${src})
file(GLOB endf "${PROJECT_SOURCE_DIR}/System/endf/*.cxx")
add_library(libendf SHARED ${endf})
file(GLOB funcBase "${PROJECT_SOURCE_DIR}/System/funcBase/*.cxx")
add_library(libfuncBase SHARED ${funcBase})
file(GLOB simMC "${PROJECT_SOURCE_DIR}/System/simMC/*.cxx")
add_library(libsimMC SHARED ${simMC})
file(GLOB monte "${PROJECT_SOURCE_DIR}/System/monte/*.cxx")
add_library(libmonte SHARED ${monte})
file(GLOB support "${PROJECT_SOURCE_DIR}/System/support/*.cxx")
add_library(libsupport SHARED ${support})
file(GLOB geometry "${PROJECT_SOURCE_DIR}/System/geometry/*.cxx")
add_library(libgeometry SHARED ${geometry})
file(GLOB t1Upgrade "${PROJECT_SOURCE_DIR}/Model/t1Upgrade/*.cxx")
add_library(libt1Upgrade SHARED ${t1Upgrade})
file(GLOB imat "${PROJECT_SOURCE_DIR}/Model/imat/*.cxx")
add_library(libimat SHARED ${imat})
file(GLOB nmx "${PROJECT_SOURCE_DIR}/Model/ESSBeam/nmx/*.cxx")
add_library(libnmx SHARED ${nmx})
file(GLOB process "${PROJECT_SOURCE_DIR}/System/process/*.cxx")
add_library(libprocess SHARED ${process})
file(GLOB d4cModel "${PROJECT_SOURCE_DIR}/Model/d4cModel/*.cxx")
add_library(libd4cModel SHARED ${d4cModel})
file(GLOB test "${PROJECT_SOURCE_DIR}/test/*.cxx")
add_library(libtest SHARED ${test})
file(GLOB CMakeFiles "${PROJECT_SOURCE_DIR}/CMakeFiles/*.cxx")
add_library(libCMakeFiles SHARED ${CMakeFiles})
file(GLOB build "${PROJECT_SOURCE_DIR}/Model/build/*.cxx")
add_library(libbuild SHARED ${build})
file(GLOB tally "${PROJECT_SOURCE_DIR}/System/tally/*.cxx")
add_library(libtally SHARED ${tally})
file(GLOB scatMat "${PROJECT_SOURCE_DIR}/scatMat/*.cxx")
add_library(libscatMat SHARED ${scatMat})
file(GLOB t3Model "${PROJECT_SOURCE_DIR}/Model/t3Model/*.cxx")
add_library(libt3Model SHARED ${t3Model})
file(GLOB source "${PROJECT_SOURCE_DIR}/System/source/*.cxx")
add_library(libsource SHARED ${source})
file(GLOB pipeBuild "${PROJECT_SOURCE_DIR}/Model/pipeBuild/*.cxx")
add_library(libpipeBuild SHARED ${pipeBuild})
file(GLOB md5 "${PROJECT_SOURCE_DIR}/System/md5/*.cxx")
add_library(libmd5 SHARED ${md5})
file(GLOB compWeights "${PROJECT_SOURCE_DIR}/System/compWeights/*.cxx")
add_library(libcompWeights SHARED ${compWeights})
file(GLOB special "${PROJECT_SOURCE_DIR}/special/*.cxx")
add_library(libspecial SHARED ${special})
file(GLOB zoom "${PROJECT_SOURCE_DIR}/Model/zoom/*.cxx")
add_library(libzoom SHARED ${zoom})
file(GLOB mersenne "${PROJECT_SOURCE_DIR}/System/mersenne/*.cxx")
add_library(libmersenne SHARED ${mersenne})
file(GLOB delft "${PROJECT_SOURCE_DIR}/Model/delft/*.cxx")
add_library(libdelft SHARED ${delft})
file(GLOB visit "${PROJECT_SOURCE_DIR}/System/visit/*.cxx")
add_library(libvisit SHARED ${visit})
file(GLOB sinbadBuild "${PROJECT_SOURCE_DIR}/Model/sinbadBuild/*.cxx")
add_library(libsinbadBuild SHARED ${sinbadBuild})
file(GLOB attachComp "${PROJECT_SOURCE_DIR}/System/attachComp/*.cxx")
add_library(libattachComp SHARED ${attachComp})
file(GLOB bibBuild "${PROJECT_SOURCE_DIR}/Model/bibBuild/*.cxx")
add_library(libbibBuild SHARED ${bibBuild})
file(GLOB loki "${PROJECT_SOURCE_DIR}/Model/ESSBeam/loki/*.cxx")
add_library(libloki SHARED ${loki})
file(GLOB xml "${PROJECT_SOURCE_DIR}/System/xml/*.cxx")
add_library(libxml SHARED ${xml})
file(GLOB essBuild "${PROJECT_SOURCE_DIR}/Model/essBuild/*.cxx")
add_library(libessBuild SHARED ${essBuild})
file(GLOB poly "${PROJECT_SOURCE_DIR}/System/poly/*.cxx")
add_library(libpoly SHARED ${poly})
file(GLOB world "${PROJECT_SOURCE_DIR}/System/world/*.cxx")
add_library(libworld SHARED ${world})
file(GLOB gammaBuild "${PROJECT_SOURCE_DIR}/Model/gammaBuild/*.cxx")
add_library(libgammaBuild SHARED ${gammaBuild})
file(GLOB t1Engineer "${PROJECT_SOURCE_DIR}/Model/t1Engineer/*.cxx")
add_library(libt1Engineer SHARED ${t1Engineer})
file(GLOB t1Build "${PROJECT_SOURCE_DIR}/Model/t1Build/*.cxx")
add_library(libt1Build SHARED ${t1Build})
file(GLOB weights "${PROJECT_SOURCE_DIR}/System/weights/*.cxx")
add_library(libweights SHARED ${weights})
file(GLOB odin "${PROJECT_SOURCE_DIR}/Model/ESSBeam/odin/*.cxx")
add_library(libodin SHARED ${odin})
file(GLOB input "${PROJECT_SOURCE_DIR}/System/input/*.cxx")
add_library(libinput SHARED ${input})
file(GLOB muon "${PROJECT_SOURCE_DIR}/Model/muon/*.cxx")
add_library(libmuon SHARED ${muon})
file(GLOB instrument "${PROJECT_SOURCE_DIR}/instrument/*.cxx")
add_library(libinstrument SHARED ${instrument})
file(GLOB construct "${PROJECT_SOURCE_DIR}/System/construct/*.cxx")
add_library(libconstruct SHARED ${construct})
file(GLOB physics "${PROJECT_SOURCE_DIR}/System/physics/*.cxx")
add_library(libphysics SHARED ${physics})
file(GLOB cuBlock "${PROJECT_SOURCE_DIR}/Model/cuBlock/*.cxx")
add_library(libcuBlock SHARED ${cuBlock})
file(GLOB beamline "${PROJECT_SOURCE_DIR}/beamline/*.cxx")
add_library(libbeamline SHARED ${beamline})
file(GLOB moderator "${PROJECT_SOURCE_DIR}/Model/moderator/*.cxx")
add_library(libmoderator SHARED ${moderator})
file(GLOB lensModel "${PROJECT_SOURCE_DIR}/Model/lensModel/*.cxx")
add_library(liblensModel SHARED ${lensModel})
file(GLOB vor "${PROJECT_SOURCE_DIR}/Model/ESSBeam/vor/*.cxx")
add_library(libvor SHARED ${vor})
file(GLOB crystal "${PROJECT_SOURCE_DIR}/System/crystal/*.cxx")
add_library(libcrystal SHARED ${crystal})
file(GLOB chip "${PROJECT_SOURCE_DIR}/Model/chip/*.cxx")
add_library(libchip SHARED ${chip})
file(GLOB photon "${PROJECT_SOURCE_DIR}/Model/photon/*.cxx")
add_library(libphoton SHARED ${photon})
file(GLOB epbBuild "${PROJECT_SOURCE_DIR}/Model/epbBuild/*.cxx")
add_library(libepbBuild SHARED ${epbBuild})
file(GLOB work "${PROJECT_SOURCE_DIR}/System/work/*.cxx")
add_library(libwork SHARED ${work})
file(GLOB global "${PROJECT_SOURCE_DIR}/global/*.cxx")
add_library(libglobal SHARED ${global})
file(GLOB log "${PROJECT_SOURCE_DIR}/System/log/*.cxx")
add_library(liblog SHARED ${log})
file(GLOB bnctBuild "${PROJECT_SOURCE_DIR}/Model/bnctBuild/*.cxx")
add_library(libbnctBuild SHARED ${bnctBuild})
file(GLOB snsBuild "${PROJECT_SOURCE_DIR}/Model/snsBuild/*.cxx")
add_library(libsnsBuild SHARED ${snsBuild})
## END GLOBS 

## EXECUTABLES 
add_executable(fullBuild ${PROJECT_SOURCE_DIR}/Main/fullBuild)
target_link_libraries(fullBuild  libbuild)
target_link_libraries(fullBuild  libvisit)
target_link_libraries(fullBuild  libchip)
target_link_libraries(fullBuild  libmoderator)
target_link_libraries(fullBuild  libbuild)
target_link_libraries(fullBuild  libzoom)
target_link_libraries(fullBuild  libimat)
target_link_libraries(fullBuild  libsrc)
target_link_libraries(fullBuild  libsimMC)
target_link_libraries(fullBuild  libphysics)
target_link_libraries(fullBuild  libconstruct)
target_link_libraries(fullBuild  libtransport)
target_link_libraries(fullBuild  libscatMat)
target_link_libraries(fullBuild  libcrystal)
target_link_libraries(fullBuild  libendf)
target_link_libraries(fullBuild  libinput)
target_link_libraries(fullBuild  libsource)
target_link_libraries(fullBuild  libmonte)
target_link_libraries(fullBuild  libfuncBase)
target_link_libraries(fullBuild  liblog)
target_link_libraries(fullBuild  libprocess)
target_link_libraries(fullBuild  libtally)
target_link_libraries(fullBuild  libworld)
target_link_libraries(fullBuild  libmonte)
target_link_libraries(fullBuild  libgeometry)
target_link_libraries(fullBuild  libmersenne)
target_link_libraries(fullBuild  libsrc)
target_link_libraries(fullBuild  libwork)
target_link_libraries(fullBuild  libxml)
target_link_libraries(fullBuild  libpoly)
target_link_libraries(fullBuild  libsupport)
target_link_libraries(fullBuild  libweights)
target_link_libraries(fullBuild  libmd5)
target_link_libraries(fullBuild  libglobal)
target_link_libraries(fullBuild  libattachComp)
target_link_libraries(fullBuild  libvisit)
target_link_libraries(fullBuild boost_regex)
target_link_libraries(fullBuild stdc++)
 target_link_libraries(fullBuild gsl)
add_executable(ess ${PROJECT_SOURCE_DIR}/Main/ess)
target_link_libraries(ess  libessBuild)
target_link_libraries(ess  libvisit)
target_link_libraries(ess  libsrc)
target_link_libraries(ess  libsimMC)
target_link_libraries(ess  libbeamline)
target_link_libraries(ess  libphysics)
target_link_libraries(ess  libsupport)
target_link_libraries(ess  libinput)
target_link_libraries(ess  libinstrument)
target_link_libraries(ess  libsource)
target_link_libraries(ess  libmonte)
target_link_libraries(ess  libfuncBase)
target_link_libraries(ess  liblog)
target_link_libraries(ess  libtally)
target_link_libraries(ess  libconstruct)
target_link_libraries(ess  libcrystal)
target_link_libraries(ess  libtransport)
target_link_libraries(ess  libscatMat)
target_link_libraries(ess  libmd5)
target_link_libraries(ess  libendf)
target_link_libraries(ess  libprocess)
target_link_libraries(ess  libworld)
target_link_libraries(ess  libwork)
target_link_libraries(ess  libmonte)
target_link_libraries(ess  libgeometry)
target_link_libraries(ess  libmersenne)
target_link_libraries(ess  libsrc)
target_link_libraries(ess  libxml)
target_link_libraries(ess  libpoly)
target_link_libraries(ess  libweights)
target_link_libraries(ess  libglobal)
target_link_libraries(ess  libattachComp)
target_link_libraries(ess  libvisit)
target_link_libraries(ess  libodin)
target_link_libraries(ess  libloki)
target_link_libraries(ess  libnmx)
target_link_libraries(ess  libvor)
target_link_libraries(ess boost_regex)
target_link_libraries(ess stdc++)
 target_link_libraries(ess gsl)
add_executable(pipe ${PROJECT_SOURCE_DIR}/Main/pipe)
target_link_libraries(pipe  libpipeBuild)
target_link_libraries(pipe  libvisit)
target_link_libraries(pipe  libsrc)
target_link_libraries(pipe  libsimMC)
target_link_libraries(pipe  libconstruct)
target_link_libraries(pipe  libphysics)
target_link_libraries(pipe  libinput)
target_link_libraries(pipe  libprocess)
target_link_libraries(pipe  libtransport)
target_link_libraries(pipe  libscatMat)
target_link_libraries(pipe  libendf)
target_link_libraries(pipe  libcrystal)
target_link_libraries(pipe  libsource)
target_link_libraries(pipe  libmonte)
target_link_libraries(pipe  libfuncBase)
target_link_libraries(pipe  liblog)
target_link_libraries(pipe  libmonte)
target_link_libraries(pipe  libtally)
target_link_libraries(pipe  libgeometry)
target_link_libraries(pipe  libmersenne)
target_link_libraries(pipe  libsrc)
target_link_libraries(pipe  libworld)
target_link_libraries(pipe  libwork)
target_link_libraries(pipe  libxml)
target_link_libraries(pipe  libpoly)
target_link_libraries(pipe  libsupport)
target_link_libraries(pipe  libweights)
target_link_libraries(pipe  libmd5)
target_link_libraries(pipe  libglobal)
target_link_libraries(pipe  libattachComp)
target_link_libraries(pipe  libvisit)
target_link_libraries(pipe  libpoly)
target_link_libraries(pipe boost_regex)
target_link_libraries(pipe stdc++)
 target_link_libraries(pipe gsl)
add_executable(sinbad ${PROJECT_SOURCE_DIR}/Main/sinbad)
target_link_libraries(sinbad  libsource)
target_link_libraries(sinbad  libvisit)
target_link_libraries(sinbad  libsrc)
target_link_libraries(sinbad  libsimMC)
target_link_libraries(sinbad  libphysics)
target_link_libraries(sinbad  libinput)
target_link_libraries(sinbad  libmonte)
target_link_libraries(sinbad  libfuncBase)
target_link_libraries(sinbad  liblog)
target_link_libraries(sinbad  libtally)
target_link_libraries(sinbad  libconstruct)
target_link_libraries(sinbad  libcrystal)
target_link_libraries(sinbad  libtransport)
target_link_libraries(sinbad  libscatMat)
target_link_libraries(sinbad  libmd5)
target_link_libraries(sinbad  libendf)
target_link_libraries(sinbad  libprocess)
target_link_libraries(sinbad  libworld)
target_link_libraries(sinbad  libwork)
target_link_libraries(sinbad  libmonte)
target_link_libraries(sinbad  libgeometry)
target_link_libraries(sinbad  libmersenne)
target_link_libraries(sinbad  libsrc)
target_link_libraries(sinbad  libxml)
target_link_libraries(sinbad  libpoly)
target_link_libraries(sinbad  libsupport)
target_link_libraries(sinbad  libweights)
target_link_libraries(sinbad  libglobal)
target_link_libraries(sinbad  libattachComp)
target_link_libraries(sinbad  libsinbadBuild)
target_link_libraries(sinbad boost_regex)
target_link_libraries(sinbad stdc++)
 target_link_libraries(sinbad gsl)
add_executable(t1Real ${PROJECT_SOURCE_DIR}/Main/t1Real)
target_link_libraries(t1Real  libt1Build)
target_link_libraries(t1Real  libimat)
target_link_libraries(t1Real  libchip)
target_link_libraries(t1Real  libbuild)
target_link_libraries(t1Real  libvisit)
target_link_libraries(t1Real  libmoderator)
target_link_libraries(t1Real  libzoom)
target_link_libraries(t1Real  libsrc)
target_link_libraries(t1Real  libsimMC)
target_link_libraries(t1Real  libconstruct)
target_link_libraries(t1Real  libcrystal)
target_link_libraries(t1Real  libtransport)
target_link_libraries(t1Real  libscatMat)
target_link_libraries(t1Real  libendf)
target_link_libraries(t1Real  libphysics)
target_link_libraries(t1Real  libinput)
target_link_libraries(t1Real  libprocess)
target_link_libraries(t1Real  libsource)
target_link_libraries(t1Real  libmonte)
target_link_libraries(t1Real  libfuncBase)
target_link_libraries(t1Real  liblog)
target_link_libraries(t1Real  libmonte)
target_link_libraries(t1Real  libtally)
target_link_libraries(t1Real  libgeometry)
target_link_libraries(t1Real  libmersenne)
target_link_libraries(t1Real  libsrc)
target_link_libraries(t1Real  libworld)
target_link_libraries(t1Real  libwork)
target_link_libraries(t1Real  libxml)
target_link_libraries(t1Real  libpoly)
target_link_libraries(t1Real  libsupport)
target_link_libraries(t1Real  libweights)
target_link_libraries(t1Real  libmd5)
target_link_libraries(t1Real  libglobal)
target_link_libraries(t1Real  libattachComp)
target_link_libraries(t1Real  libvisit)
target_link_libraries(t1Real  libpoly)
target_link_libraries(t1Real boost_regex)
target_link_libraries(t1Real stdc++)
 target_link_libraries(t1Real gsl)
add_executable(sns ${PROJECT_SOURCE_DIR}/Main/sns)
target_link_libraries(sns  libsnsBuild)
target_link_libraries(sns  libvisit)
target_link_libraries(sns  libsrc)
target_link_libraries(sns  libsimMC)
target_link_libraries(sns  libphysics)
target_link_libraries(sns  libinput)
target_link_libraries(sns  libsource)
target_link_libraries(sns  libmonte)
target_link_libraries(sns  libfuncBase)
target_link_libraries(sns  liblog)
target_link_libraries(sns  libtally)
target_link_libraries(sns  libconstruct)
target_link_libraries(sns  libcrystal)
target_link_libraries(sns  libtransport)
target_link_libraries(sns  libscatMat)
target_link_libraries(sns  libmd5)
target_link_libraries(sns  libendf)
target_link_libraries(sns  libprocess)
target_link_libraries(sns  libworld)
target_link_libraries(sns  libwork)
target_link_libraries(sns  libmonte)
target_link_libraries(sns  libgeometry)
target_link_libraries(sns  libmersenne)
target_link_libraries(sns  libsrc)
target_link_libraries(sns  libxml)
target_link_libraries(sns  libpoly)
target_link_libraries(sns  libsupport)
target_link_libraries(sns  libweights)
target_link_libraries(sns  libglobal)
target_link_libraries(sns  libattachComp)
target_link_libraries(sns  libvisit)
target_link_libraries(sns boost_regex)
target_link_libraries(sns stdc++)
 target_link_libraries(sns gsl)
add_executable(reactor ${PROJECT_SOURCE_DIR}/Main/reactor)
target_link_libraries(reactor  libdelft)
target_link_libraries(reactor  libvisit)
target_link_libraries(reactor  libsrc)
target_link_libraries(reactor  libsimMC)
target_link_libraries(reactor  libphysics)
target_link_libraries(reactor  libinput)
target_link_libraries(reactor  libsource)
target_link_libraries(reactor  libmonte)
target_link_libraries(reactor  libfuncBase)
target_link_libraries(reactor  liblog)
target_link_libraries(reactor  libconstruct)
target_link_libraries(reactor  libtransport)
target_link_libraries(reactor  libscatMat)
target_link_libraries(reactor  libcrystal)
target_link_libraries(reactor  libendf)
target_link_libraries(reactor  libprocess)
target_link_libraries(reactor  libtally)
target_link_libraries(reactor  libworld)
target_link_libraries(reactor  libmonte)
target_link_libraries(reactor  libgeometry)
target_link_libraries(reactor  libmersenne)
target_link_libraries(reactor  libsrc)
target_link_libraries(reactor  libxml)
target_link_libraries(reactor  libpoly)
target_link_libraries(reactor  libsupport)
target_link_libraries(reactor  libweights)
target_link_libraries(reactor  libmd5)
target_link_libraries(reactor  libwork)
target_link_libraries(reactor  libglobal)
target_link_libraries(reactor  libattachComp)
target_link_libraries(reactor  libvisit)
target_link_libraries(reactor boost_regex)
target_link_libraries(reactor stdc++)
 target_link_libraries(reactor gsl)
add_executable(t1MarkII ${PROJECT_SOURCE_DIR}/Main/t1MarkII)
target_link_libraries(t1MarkII  libt1Upgrade)
target_link_libraries(t1MarkII  libt1Build)
target_link_libraries(t1MarkII  libimat)
target_link_libraries(t1MarkII  libchip)
target_link_libraries(t1MarkII  libbuild)
target_link_libraries(t1MarkII  libvisit)
target_link_libraries(t1MarkII  libmoderator)
target_link_libraries(t1MarkII  libzoom)
target_link_libraries(t1MarkII  libsrc)
target_link_libraries(t1MarkII  libsimMC)
target_link_libraries(t1MarkII  libconstruct)
target_link_libraries(t1MarkII  libcrystal)
target_link_libraries(t1MarkII  libtransport)
target_link_libraries(t1MarkII  libscatMat)
target_link_libraries(t1MarkII  libendf)
target_link_libraries(t1MarkII  libphysics)
target_link_libraries(t1MarkII  libinput)
target_link_libraries(t1MarkII  libprocess)
target_link_libraries(t1MarkII  libsource)
target_link_libraries(t1MarkII  libmonte)
target_link_libraries(t1MarkII  libfuncBase)
target_link_libraries(t1MarkII  liblog)
target_link_libraries(t1MarkII  libmonte)
target_link_libraries(t1MarkII  libtally)
target_link_libraries(t1MarkII  libgeometry)
target_link_libraries(t1MarkII  libmersenne)
target_link_libraries(t1MarkII  libsrc)
target_link_libraries(t1MarkII  libworld)
target_link_libraries(t1MarkII  libwork)
target_link_libraries(t1MarkII  libxml)
target_link_libraries(t1MarkII  libpoly)
target_link_libraries(t1MarkII  libsupport)
target_link_libraries(t1MarkII  libweights)
target_link_libraries(t1MarkII  libmd5)
target_link_libraries(t1MarkII  libglobal)
target_link_libraries(t1MarkII  libattachComp)
target_link_libraries(t1MarkII  libvisit)
target_link_libraries(t1MarkII  libpoly)
target_link_libraries(t1MarkII boost_regex)
target_link_libraries(t1MarkII stdc++)
 target_link_libraries(t1MarkII gsl)
add_executable(t1Eng ${PROJECT_SOURCE_DIR}/Main/t1Eng)
target_link_libraries(t1Eng  libt1Engineer)
target_link_libraries(t1Eng  libt1Upgrade)
target_link_libraries(t1Eng  libt1Build)
target_link_libraries(t1Eng  libimat)
target_link_libraries(t1Eng  libchip)
target_link_libraries(t1Eng  libbuild)
target_link_libraries(t1Eng  libvisit)
target_link_libraries(t1Eng  libmoderator)
target_link_libraries(t1Eng  libzoom)
target_link_libraries(t1Eng  libsrc)
target_link_libraries(t1Eng  libsimMC)
target_link_libraries(t1Eng  libconstruct)
target_link_libraries(t1Eng  libcrystal)
target_link_libraries(t1Eng  libtransport)
target_link_libraries(t1Eng  libscatMat)
target_link_libraries(t1Eng  libendf)
target_link_libraries(t1Eng  libphysics)
target_link_libraries(t1Eng  libinput)
target_link_libraries(t1Eng  libprocess)
target_link_libraries(t1Eng  libsource)
target_link_libraries(t1Eng  libmonte)
target_link_libraries(t1Eng  libfuncBase)
target_link_libraries(t1Eng  liblog)
target_link_libraries(t1Eng  libmonte)
target_link_libraries(t1Eng  libtally)
target_link_libraries(t1Eng  libgeometry)
target_link_libraries(t1Eng  libmersenne)
target_link_libraries(t1Eng  libsrc)
target_link_libraries(t1Eng  libworld)
target_link_libraries(t1Eng  libwork)
target_link_libraries(t1Eng  libxml)
target_link_libraries(t1Eng  libpoly)
target_link_libraries(t1Eng  libsupport)
target_link_libraries(t1Eng  libweights)
target_link_libraries(t1Eng  libmd5)
target_link_libraries(t1Eng  libglobal)
target_link_libraries(t1Eng  libattachComp)
target_link_libraries(t1Eng  libvisit)
target_link_libraries(t1Eng  libpoly)
target_link_libraries(t1Eng boost_regex)
target_link_libraries(t1Eng stdc++)
 target_link_libraries(t1Eng gsl)
add_executable(t3Expt ${PROJECT_SOURCE_DIR}/Main/t3Expt)
target_link_libraries(t3Expt  libt3Model)
target_link_libraries(t3Expt  libvisit)
target_link_libraries(t3Expt  libsrc)
target_link_libraries(t3Expt  libphysics)
target_link_libraries(t3Expt  libinput)
target_link_libraries(t3Expt  libinstrument)
target_link_libraries(t3Expt  libsource)
target_link_libraries(t3Expt  libsimMC)
target_link_libraries(t3Expt  libmonte)
target_link_libraries(t3Expt  libfuncBase)
target_link_libraries(t3Expt  liblog)
target_link_libraries(t3Expt  libconstruct)
target_link_libraries(t3Expt  libcrystal)
target_link_libraries(t3Expt  libtransport)
target_link_libraries(t3Expt  libscatMat)
target_link_libraries(t3Expt  libendf)
target_link_libraries(t3Expt  libtransport)
target_link_libraries(t3Expt  libscatMat)
target_link_libraries(t3Expt  libtally)
target_link_libraries(t3Expt  libprocess)
target_link_libraries(t3Expt  libtally)
target_link_libraries(t3Expt  libworld)
target_link_libraries(t3Expt  libconstruct)
target_link_libraries(t3Expt  libmonte)
target_link_libraries(t3Expt  libgeometry)
target_link_libraries(t3Expt  libmersenne)
target_link_libraries(t3Expt  libsrc)
target_link_libraries(t3Expt  libxml)
target_link_libraries(t3Expt  libpoly)
target_link_libraries(t3Expt  libsupport)
target_link_libraries(t3Expt  libweights)
target_link_libraries(t3Expt  libwork)
target_link_libraries(t3Expt  libmd5)
target_link_libraries(t3Expt  libglobal)
target_link_libraries(t3Expt  libattachComp)
target_link_libraries(t3Expt  libvisit)
target_link_libraries(t3Expt boost_regex)
target_link_libraries(t3Expt stdc++)
 target_link_libraries(t3Expt gsl)
add_executable(testMain ${PROJECT_SOURCE_DIR}/Main/testMain)
target_link_libraries(testMain  libtest)
target_link_libraries(testMain  libbuild)
target_link_libraries(testMain  libvisit)
target_link_libraries(testMain  libchip)
target_link_libraries(testMain  libt1Upgrade)
target_link_libraries(testMain  libimat)
target_link_libraries(testMain  libmoderator)
target_link_libraries(testMain  libbuild)
target_link_libraries(testMain  libzoom)
target_link_libraries(testMain  libconstruct)
target_link_libraries(testMain  libcrystal)
target_link_libraries(testMain  libtransport)
target_link_libraries(testMain  libscatMat)
target_link_libraries(testMain  libendf)
target_link_libraries(testMain  libt1Build)
target_link_libraries(testMain  libsrc)
target_link_libraries(testMain  libsimMC)
target_link_libraries(testMain  libphysics)
target_link_libraries(testMain  libinput)
target_link_libraries(testMain  libprocess)
target_link_libraries(testMain  libsource)
target_link_libraries(testMain  libmonte)
target_link_libraries(testMain  libfuncBase)
target_link_libraries(testMain  liblog)
target_link_libraries(testMain  libgeometry)
target_link_libraries(testMain  libtally)
target_link_libraries(testMain  libmersenne)
target_link_libraries(testMain  libsrc)
target_link_libraries(testMain  libwork)
target_link_libraries(testMain  libxml)
target_link_libraries(testMain  libpoly)
target_link_libraries(testMain  libsupport)
target_link_libraries(testMain  libworld)
target_link_libraries(testMain  libweights)
target_link_libraries(testMain  libmd5)
target_link_libraries(testMain  libglobal)
target_link_libraries(testMain  libattachComp)
target_link_libraries(testMain  libvisit)
target_link_libraries(testMain  libpoly)
target_link_libraries(testMain boost_regex)
target_link_libraries(testMain stdc++)
 target_link_libraries(testMain gsl)
## END EXECUTABLE 

add_custom_target(tar  COMMAND tar zcvf ${PROJECT_SOURCE_DIR}/cl.tgz 
     ${PROJECT_SOURCE_DIR}/transport/*.cxx 
     ${PROJECT_SOURCE_DIR}/src/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/endf/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/funcBase/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/simMC/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/monte/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/support/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/geometry/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/t1Upgrade/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/imat/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/ESSBeam/nmx/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/process/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/d4cModel/*.cxx 
     ${PROJECT_SOURCE_DIR}/test/*.cxx 
     ${PROJECT_SOURCE_DIR}/CMakeFiles/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/build/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/tally/*.cxx 
     ${PROJECT_SOURCE_DIR}/scatMat/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/t3Model/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/source/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/pipeBuild/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/md5/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/compWeights/*.cxx 
     ${PROJECT_SOURCE_DIR}/special/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/zoom/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/mersenne/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/delft/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/visit/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/sinbadBuild/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/attachComp/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/bibBuild/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/ESSBeam/loki/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/xml/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/essBuild/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/poly/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/world/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/gammaBuild/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/t1Engineer/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/t1Build/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/weights/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/ESSBeam/odin/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/input/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/muon/*.cxx 
     ${PROJECT_SOURCE_DIR}/instrument/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/construct/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/physics/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/cuBlock/*.cxx 
     ${PROJECT_SOURCE_DIR}/beamline/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/moderator/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/lensModel/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/ESSBeam/vor/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/crystal/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/chip/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/photon/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/epbBuild/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/work/*.cxx 
     ${PROJECT_SOURCE_DIR}/global/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/log/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/bnctBuild/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/snsBuild/*.cxx 
     ${PROJECT_SOURCE_DIR}/include/*.h 
     ${PROJECT_SOURCE_DIR}/beamlineInc/*.h 
     ${PROJECT_SOURCE_DIR}/globalInc/*.h 
     ${PROJECT_SOURCE_DIR}/instrumentInc/*.h 
     ${PROJECT_SOURCE_DIR}/scatMatInc/*.h 
     ${PROJECT_SOURCE_DIR}/specialInc/*.h 
     ${PROJECT_SOURCE_DIR}/transportInc/*.h 
     ${PROJECT_SOURCE_DIR}/testInclude/*.h 
     ${PROJECT_SOURCE_DIR}/System/attachCompInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/compWeightsInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/constructInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/crystalInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/endfInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/funcBaseInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/geomInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/inputInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/logInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/md5Inc/*.h 
     ${PROJECT_SOURCE_DIR}/System/mersenneInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/monteInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/physicsInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/polyInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/processInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/simMCInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/sourceInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/supportInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/tallyInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/visitInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/weightsInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/workInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/worldInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/xmlInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/bibBuildInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/bnctBuildInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/buildInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/chipInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/cuBlockInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/d4cModelInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/delftInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/epbBuildInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/essBuildInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/gammaBuildInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/imatInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/lensModelInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/moderatorInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/muonInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/photonInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/pipeBuildInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/sinbadBuildInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/snsBuildInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/t1BuildInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/t1EngineerInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/t1UpgradeInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/t3ModelInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/zoomInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/ESSBeam/lokiInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/ESSBeam/nmxInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/ESSBeam/odinInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/ESSBeam/vorInc/*.h 
     ${PROJECT_SOURCE_DIR}/CMake.pl  
     ${PROJECT_SOURCE_DIR}/CMakeList.pm 
 )

add_custom_target(tags  COMMAND etags  
     ${PROJECT_SOURCE_DIR}/transport/*.cxx 
     ${PROJECT_SOURCE_DIR}/src/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/endf/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/funcBase/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/simMC/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/monte/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/support/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/geometry/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/t1Upgrade/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/imat/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/ESSBeam/nmx/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/process/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/d4cModel/*.cxx 
     ${PROJECT_SOURCE_DIR}/test/*.cxx 
     ${PROJECT_SOURCE_DIR}/CMakeFiles/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/build/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/tally/*.cxx 
     ${PROJECT_SOURCE_DIR}/scatMat/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/t3Model/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/source/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/pipeBuild/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/md5/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/compWeights/*.cxx 
     ${PROJECT_SOURCE_DIR}/special/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/zoom/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/mersenne/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/delft/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/visit/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/sinbadBuild/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/attachComp/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/bibBuild/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/ESSBeam/loki/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/xml/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/essBuild/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/poly/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/world/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/gammaBuild/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/t1Engineer/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/t1Build/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/weights/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/ESSBeam/odin/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/input/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/muon/*.cxx 
     ${PROJECT_SOURCE_DIR}/instrument/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/construct/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/physics/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/cuBlock/*.cxx 
     ${PROJECT_SOURCE_DIR}/beamline/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/moderator/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/lensModel/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/ESSBeam/vor/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/crystal/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/chip/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/photon/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/epbBuild/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/work/*.cxx 
     ${PROJECT_SOURCE_DIR}/global/*.cxx 
     ${PROJECT_SOURCE_DIR}/System/log/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/bnctBuild/*.cxx 
     ${PROJECT_SOURCE_DIR}/Model/snsBuild/*.cxx 
     ${PROJECT_SOURCE_DIR}/include/*.h 
     ${PROJECT_SOURCE_DIR}/beamlineInc/*.h 
     ${PROJECT_SOURCE_DIR}/globalInc/*.h 
     ${PROJECT_SOURCE_DIR}/instrumentInc/*.h 
     ${PROJECT_SOURCE_DIR}/scatMatInc/*.h 
     ${PROJECT_SOURCE_DIR}/specialInc/*.h 
     ${PROJECT_SOURCE_DIR}/transportInc/*.h 
     ${PROJECT_SOURCE_DIR}/testInclude/*.h 
     ${PROJECT_SOURCE_DIR}/System/attachCompInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/compWeightsInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/constructInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/crystalInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/endfInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/funcBaseInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/geomInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/inputInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/logInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/md5Inc/*.h 
     ${PROJECT_SOURCE_DIR}/System/mersenneInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/monteInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/physicsInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/polyInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/processInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/simMCInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/sourceInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/supportInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/tallyInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/visitInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/weightsInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/workInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/worldInc/*.h 
     ${PROJECT_SOURCE_DIR}/System/xmlInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/bibBuildInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/bnctBuildInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/buildInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/chipInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/cuBlockInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/d4cModelInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/delftInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/epbBuildInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/essBuildInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/gammaBuildInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/imatInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/lensModelInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/moderatorInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/muonInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/photonInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/pipeBuildInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/sinbadBuildInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/snsBuildInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/t1BuildInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/t1EngineerInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/t1UpgradeInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/t3ModelInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/zoomInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/ESSBeam/lokiInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/ESSBeam/nmxInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/ESSBeam/odinInc/*.h 
     ${PROJECT_SOURCE_DIR}/Model/ESSBeam/vorInc/*.h 
 )

