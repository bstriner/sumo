lib_LTLIBRARIES = libsumo.la
libsumo_la_SOURCES = \
	libsumo.cpp \
	simulation.cpp \
	inductionloop.cpp \
	meme.cpp \
	vehicle.cpp \
	tls.cpp \
        lane.cpp
libsumo_la_LIBADD = \
	../netload/libnetload.la \
	../microsim/libmicrosim.la \
	../microsim/cfmodels/libmicrosimcfmodels.la \
	../microsim/lcmodels/libmicrosimlcmodels.la \
	../microsim/devices/libmicrosimdevs.la \
	../microsim/output/libmicrosimoutput.la \
	../microsim/trigger/libmicrosimtrigger.la \
	../microsim/actions/libmsactions.la \
	../microsim/traffic_lights/libmicrosimtls.la \
	../microsim/pedestrians/libmicrosimpeds.la \
	../mesosim/libmesosim.la \
	../router/librouter.la \
	../traci-server/libtraciserver.la \
	../foreign/tcpip/libtcpip.la \
	../foreign/PHEMlight/cpp/libphemlight.la \
	../utils/common/libcommon.la \
	../utils/distribution/libdistribution.la \
	../utils/importio/libimportio.la \
	../utils/geom/libgeom.la \
	../utils/vehicle/libvehicle.la \
	../utils/shapes/libshapes.la \
	../utils/emissions/libemissions.la \
	../utils/options/liboptions.la \
	../utils/iodevices/libiodevices.la \
	../utils/xml/libxml.la \
	-lFOX-1.6 \
	-lxerces-c-3.1 \
	-lproj
