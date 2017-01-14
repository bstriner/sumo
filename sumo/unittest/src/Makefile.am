XERCES_LIBS = -l$(LIB_XERCES)

MESO_LIBS = ../../src/mesosim/libmesosim.la

if CHECK_MEMORY_LEAKS
MEM_LIBS = ../../src/foreign/nvwa/libnvwa.la
endif

if WITH_GUI
GUI_TESTS = ./utils/foxtools/FXWorkerThreadTest.o
endif


if WITH_GTEST
bin_PROGRAMS = sumo-unittest

sumo_unittest_SOURCES = unittest_main.cpp

sumo_unittest_LDFLAGS = $(GTEST_LDFLAGS) $(GDAL_LDFLAGS) $(PROJ_LDFLAGS)

sumo_unittest_LDADD   = \
./utils/common/StringUtilsTest.o \
./utils/common/StringTokenizerTest.o \
./utils/common/RGBColorTest.o \
./utils/common/TplConvertTest.o \
./utils/common/ValueTimeLineTest.o \
./utils/geom/BoundaryTest.o \
./utils/geom/PositionVectorTest.o \
./utils/geom/GeomHelperTest.o \
./utils/geom/GeoConvHelperTest.o \
./netbuild/NBHeightMapperTest.o \
./netbuild/NBTrafficLightLogicTest.o \
./microsim/MSCFModelTest.o \
./microsim/MSEventControlTest.o \
$(GUI_TESTS) \
../../src/netbuild/libnetbuild.la \
../../src/traci-server/libtraciserver.la \
../../src/microsim/libmicrosim.la \
../../src/traci-server/TraCIServer.o \
../../src/microsim/devices/libmicrosimdevs.la \
../../src/microsim/trigger/libmicrosimtrigger.la \
../../src/microsim/cfmodels/libmicrosimcfmodels.la \
../../src/microsim/lcmodels/libmicrosimlcmodels.la \
../../src/microsim/pedestrians/libmicrosimpeds.la \
../../src/microsim/output/libmicrosimoutput.la \
../../src/microsim/MSMoveReminder.o \
../../src/microsim/MSRouteHandler.o \
../../src/microsim/actions/libmsactions.la \
../../src/microsim/traffic_lights/libmicrosimtls.la \
$(MESO_LIBS) \
../../src/utils/geom/libgeom.la \
../../src/utils/shapes/libshapes.la \
../../src/utils/emissions/libemissions.la \
../../src/utils/xml/libxml.la \
../../src/utils/vehicle/libvehicle.la \
../../src/utils/common/libcommon.la \
../../src/utils/options/liboptions.la \
../../src/utils/iodevices/libiodevices.la \
../../src/utils/common/FileHelpers.o \
../../src/foreign/PHEMlight/cpp/libphemlight.la \
../../src/foreign/tcpip/libtcpip.la \
$(MEM_LIBS) \
$(PYTHON_LIBS) \
$(XERCES_LIBS) \
$(FOX_LDFLAGS)

SUBDIRS = utils microsim netbuild
endif
