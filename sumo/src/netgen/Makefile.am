if CHECK_MEMORY_LEAKS
MEM_LIBS  = ../foreign/nvwa/libnvwa.la
endif

bin_PROGRAMS = netgenerate

netgenerate_SOURCES = netgen_main.cpp NGEdge.cpp NGEdge.h NGFrame.cpp NGFrame.h \
NGNet.h NGNet.cpp NGNode.cpp NGNode.h \
NGRandomNetBuilder.h NGRandomNetBuilder.cpp

netgenerate_LDADD   = ../netbuild/libnetbuild.la \
../netwrite/libnetwrite.la \
../utils/geom/libgeom.la \
../utils/options/liboptions.la \
../utils/xml/libxml.la \
../utils/common/libcommon.la \
../utils/importio/libimportio.la \
../utils/iodevices/libiodevices.la \
../foreign/tcpip/libtcpip.la \
$(MEM_LIBS) \
-l$(LIB_XERCES) \
$(XERCES_LDFLAGS) $(GDAL_LDFLAGS) $(PROJ_LDFLAGS)
