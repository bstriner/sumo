XERCES_LIBS = -l$(LIB_XERCES)

if CHECK_MEMORY_LEAKS
MEM_LIBS  = ../foreign/nvwa/libnvwa.la
endif

COMMON_LIBS = ../utils/options/liboptions.la \
../utils/xml/libxml.la \
../utils/common/libcommon.la \
../utils/importio/libimportio.la \
../utils/iodevices/libiodevices.la \
../foreign/tcpip/libtcpip.la \
$(MEM_LIBS) \
$(XERCES_LIBS)

bin_PROGRAMS = polyconvert

polyconvert_SOURCES = polyconvert_main.cpp PCLoaderArcView.cpp PCLoaderArcView.h \
PCLoaderDlrNavteq.cpp PCLoaderDlrNavteq.h \
PCLoaderVisum.cpp PCLoaderVisum.h \
PCLoaderOSM.cpp PCLoaderOSM.h \
PCLoaderXML.cpp PCLoaderXML.h \
PCNetProjectionLoader.cpp PCNetProjectionLoader.h \
PCPolyContainer.cpp PCPolyContainer.h \
PCTypeDefHandler.cpp PCTypeDefHandler.h \
PCTypeMap.cpp PCTypeMap.h

polyconvert_LDADD   = ../utils/options/liboptions.la \
../utils/geom/libgeom.la \
../utils/shapes/libshapes.la \
$(COMMON_LIBS) \
$(XERCES_LDFLAGS) $(GDAL_LDFLAGS) $(PROJ_LDFLAGS)

BUILT_SOURCES = pc_typemap.h
EXTRA_DIST = pc_typemap.h
pc_typemap.h:
	../../tools/build/typemap.py poly
