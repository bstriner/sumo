if CHECK_MEMORY_LEAKS
MEM_LIBS  = ../foreign/nvwa/libnvwa.la
endif

bin_PROGRAMS = dfrouter

dfrouter_SOURCES = dfrouter_main.cpp RODFDetFlowLoader.cpp RODFDetFlowLoader.h \
RODFDetector.cpp RODFDetector.h RODFDetectorFlow.cpp RODFDetectorFlow.h \
RODFDetectorHandler.cpp RODFDetectorHandler.h \
RODFNet.cpp RODFNet.h RODFRouteCont.cpp RODFRouteCont.h \
RODFRouteDesc.h RODFEdgeBuilder.cpp RODFEdgeBuilder.h \
RODFEdge.cpp RODFEdge.h \
RODFFrame.cpp RODFFrame.h

dfrouter_LDFLAGS = $(XERCES_LDFLAGS)

dfrouter_LDADD   = ../router/librouter.la \
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
