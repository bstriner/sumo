if CHECK_MEMORY_LEAKS
MEM_LIBS  = ../foreign/nvwa/libnvwa.la
endif

bin_PROGRAMS = marouter

marouter_SOURCES = marouter_main.cpp \
ROMAAssignments.cpp ROMAAssignments.h \
ROMAEdge.cpp ROMAEdge.h \
ROMAEdgeBuilder.cpp ROMAEdgeBuilder.h \
ROMAFrame.cpp ROMAFrame.h \
ROMARouteHandler.cpp ROMARouteHandler.h

marouter_LDFLAGS = $(XERCES_LDFLAGS)

marouter_LDADD   = ../router/librouter.la \
../od/libod.la \
../utils/distribution/libdistribution.la \
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
