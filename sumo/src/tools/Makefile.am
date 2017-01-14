if CHECK_MEMORY_LEAKS
MEM_LIBS  = ../foreign/nvwa/libnvwa.la
endif

bin_PROGRAMS = emissionsDrivingCycle emissionsMap

emissionsDrivingCycle_SOURCES = emissionsDrivingCycle_main.cpp \
TrajectoriesHandler.cpp TrajectoriesHandler.h

emissionsDrivingCycle_LDFLAGS = $(XERCES_LDFLAGS)

emissionsDrivingCycle_LDADD   = ../utils/options/liboptions.la \
../utils/xml/libxml.la \
../utils/geom/libgeom.la \
../utils/emissions/libemissions.la \
../utils/common/libcommon.la \
../utils/importio/libimportio.la \
../utils/iodevices/libiodevices.la \
../foreign/PHEMlight/cpp/libphemlight.la \
../foreign/tcpip/libtcpip.la \
$(MEM_LIBS) \
-l$(LIB_XERCES)


emissionsMap_SOURCES = emissionsMap_main.cpp 

emissionsMap_LDFLAGS = $(XERCES_LDFLAGS)

emissionsMap_LDADD   = $(emissionsDrivingCycle_LDADD)
