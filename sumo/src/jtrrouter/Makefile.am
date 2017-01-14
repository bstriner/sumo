if CHECK_MEMORY_LEAKS
MEM_LIBS  = ../foreign/nvwa/libnvwa.la
endif

bin_PROGRAMS = jtrrouter

jtrrouter_SOURCES = jtrrouter_main.cpp \
ROJTREdge.cpp ROJTREdge.h \
ROJTREdgeBuilder.cpp ROJTREdgeBuilder.h \
ROJTRRouter.cpp ROJTRRouter.h ROJTRTurnDefLoader.cpp ROJTRTurnDefLoader.h \
ROJTRFrame.cpp ROJTRFrame.h


jtrrouter_LDFLAGS = $(XERCES_LDFLAGS)

jtrrouter_LDADD   = ../router/librouter.la \
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
