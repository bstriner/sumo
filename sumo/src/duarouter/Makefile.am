if CHECK_MEMORY_LEAKS
MEM_LIBS  = ../foreign/nvwa/libnvwa.la
endif

bin_PROGRAMS = duarouter

duarouter_SOURCES = duarouter_main.cpp \
RODUAEdgeBuilder.cpp RODUAEdgeBuilder.h \
RODUAFrame.cpp RODUAFrame.h

duarouter_LDFLAGS = $(XERCES_LDFLAGS)

duarouter_LDADD   = ../router/librouter.la \
../utils/options/liboptions.la \
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
-l$(LIB_XERCES) $(FOX_LDFLAGS)
