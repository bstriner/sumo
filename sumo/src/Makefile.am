XERCES_LIBS = -l$(LIB_XERCES)

if WITH_GUI
GUI_APPS = sumo-gui
GUI_DIRS = gui guinetload guisim netedit mesogui osgview
endif

if CHECK_MEMORY_LEAKS
MEM_LIBS  = ./foreign/nvwa/libnvwa.la
endif

if TRACI
TRACI_LIBS = ./traci-server/libtraciserver.la ./utils/traci/libtraci.la
TRACI_DIRS = traci-server traci_testclient
endif

bin_PROGRAMS = od2trips sumo netconvert $(GUI_APPS)

COMMON_LIBS = ./utils/options/liboptions.la \
./utils/xml/libxml.la \
./utils/common/libcommon.la \
./utils/importio/libimportio.la \
./utils/iodevices/libiodevices.la \
./foreign/PHEMlight/cpp/libphemlight.la \
./foreign/tcpip/libtcpip.la \
$(MEM_LIBS) \
$(XERCES_LIBS)


od2trips_SOURCES = od2trips_main.cpp

od2trips_LDADD   = ./od/libod.la \
./utils/options/liboptions.la \
./utils/distribution/libdistribution.la \
./utils/vehicle/libvehicle.la \
./utils/common/libcommon.la \
./utils/geom/libgeom.la \
$(COMMON_LIBS) $(XERCES_LDFLAGS)


sumo_SOURCES = sumo_main.cpp

sumo_LDADD   = ./netload/libnetload.la \
./microsim/libmicrosim.la \
./microsim/cfmodels/libmicrosimcfmodels.la \
./microsim/lcmodels/libmicrosimlcmodels.la \
./microsim/devices/libmicrosimdevs.la \
./microsim/output/libmicrosimoutput.la \
./microsim/MSMoveReminder.o \
./microsim/trigger/libmicrosimtrigger.la \
./microsim/actions/libmsactions.la \
./microsim/traffic_lights/libmicrosimtls.la \
./microsim/pedestrians/libmicrosimpeds.la \
./mesosim/libmesosim.la \
./utils/geom/libgeom.la \
./utils/vehicle/libvehicle.la \
./utils/shapes/libshapes.la \
./utils/emissions/libemissions.la \
$(TRACI_LIBS) \
$(COMMON_LIBS) \
$(PYTHON_LIBS) \
$(FOX_LDFLAGS) $(XERCES_LDFLAGS) $(PROJ_LDFLAGS)


netconvert_SOURCES = netconvert_main.cpp

netconvert_LDADD   = ./netimport/libnetimport.la \
./netimport/vissim/libvissimimport.la \
./netimport/vissim/typeloader/libvissimtypeload.la \
./netimport/vissim/tempstructs/libvissimtmpstr.la \
./netbuild/libnetbuild.la \
./netwrite/libnetwrite.la \
./utils/distribution/libdistribution.la \
./utils/geom/libgeom.la \
./foreign/eulerspiral/libeulerspiral.la \
$(COMMON_LIBS) \
$(XERCES_LDFLAGS) $(GDAL_LDFLAGS) $(PROJ_LDFLAGS)


if WITH_GUI
sumo_gui_SOURCES = guisim_main.cpp

sumo_gui_LDADD =  ./gui/libgui.la \
./guinetload/libguinetload.la \
./guisim/libguisim.la \
./gui/dialogs/libguidialogs.la \
./utils/gui/windows/libguiutilsWindows.la \
./utils/gui/globjects/libguiutilsglobjects.la \
./utils/gui/div/libguiutilsdiv.la \
./utils/gui/settings/libguiutilssettings.la \
./utils/gui/images/libguiutilsimages.la \
./utils/gui/tracker/libguiutilstracker.la \
./utils/foxtools/libfoxtools.la \
./mesogui/libmesogui.la \
./osgview/libosgview.la \
$(sumo_LDADD) \
./foreign/gl2ps/libgl2ps.la \
./foreign/polyfonts/libpolyfonts.la \
./gui/GUIManipulator.o \
./gui/GUITLLogicPhasesTrackerWindow.o \
$(OSG_LIBS) $(FFMPEG_LIBS) \
$(sumo_LDFLAGS) $(GDAL_LDFLAGS) $(X_LDFLAGS)
endif


SUBDIRS = foreign utils microsim router od marouter mesosim \
netbuild netwrite netgen netimport netload \
polyconvert dfrouter duarouter jtrrouter activitygen tools \
$(TRACI_DIRS) $(GUI_DIRS)
if WITH_LIBSUMO
	SUBDIRS = $(SUBDIRS) libsumo
endif

if WITH_VERSION_H
VERSION_H = version.h
all: $(VERSION_H)
$(VERSION_H): ../.svn
	../tools/build/version.py $(CURDIR)
endif

EXTRA_DIST = config.h config.h.in \
$(VERSION_H) guisim.rc \
windows_config.h
