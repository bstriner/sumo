SUBDIRS = activities city

XERCES_LIBS = -l$(LIB_XERCES)

if CHECK_MEMORY_LEAKS
MEM_LIBS  = ../foreign/nvwa/libnvwa.la
endif

COMMON_LIBS = ../utils/options/liboptions.la \
../utils/xml/libxml.la \
../utils/vehicle/libvehicle.la \
../utils/common/libcommon.la \
../utils/importio/libimportio.la \
../utils/iodevices/libiodevices.la \
../utils/geom/libgeom.la \
../utils/emissions/libemissions.la \
../foreign/PHEMlight/cpp/libphemlight.la \
../foreign/tcpip/libtcpip.la \
$(MEM_LIBS) \
$(XERCES_LIBS)

bin_PROGRAMS = activitygen

activitygen_SOURCES = activitygen_main.cpp \
AGActivityGen.cpp AGActivityGen.h \
AGActivityGenHandler.cpp AGActivityGenHandler.h \
AGActivityTripWriter.cpp AGActivityTripWriter.h \
AGFrame.cpp AGFrame.h

activitygen_LDFLAGS = $(XERCES_LDFLAGS)
activitygen_LDADD = ./activities/libagactivities.la \
./city/libagcity.la \
../duarouter/RODUAEdgeBuilder.o \
../duarouter/RODUAFrame.o \
../router/librouter.la \
$(COMMON_LIBS) $(FOX_LDFLAGS)
