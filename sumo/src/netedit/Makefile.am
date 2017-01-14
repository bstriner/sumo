EXTRA_DIST = netedit64.ico netedit.rc

XERCES_LIBS = -l$(LIB_XERCES)

if WITH_GUI
GUI_APPS = netedit
endif

if CHECK_MEMORY_LEAKS
MEM_LIBS  = ../foreign/nvwa/libnvwa.la
endif

if TRACI
TRACI_LIBS = ../traci-server/libtraciserver.la
endif

bin_PROGRAMS = $(GUI_APPS)

if WITH_GUI
netedit_SOURCES = netedit_main.cpp \
GNEApplicationWindow.h GNEApplicationWindow.cpp \
GNELoadThread.h GNELoadThread.cpp \
GNENet.h GNENet.cpp \
GNENetElement.h GNENetElement.cpp \
GNEEdge.h GNEEdge.cpp \
GNELane.h GNELane.cpp \
GNEInternalLane.h GNEInternalLane.cpp \
GNEConnection.h GNEConnection.cpp \
GNECrossing.h GNECrossing.cpp \
GNEJunction.h GNEJunction.cpp \
GNEPOI.h GNEPOI.cpp \
GNEPoly.h GNEPoly.cpp \
GNEProhibition.h GNEProhibition.cpp \
GNEViewNet.h GNEViewNet.cpp \
GNEViewParent.h GNEViewParent.cpp \
GNEDialog_About.h GNEDialog_About.cpp \
GNEDialog_Wizard.h GNEDialog_Wizard.cpp \
GNEAdditionalDialog.h GNEAdditionalDialog.cpp \
GNEChange.h GNEChange.cpp \
GNEChange_Junction.h GNEChange_Junction.cpp \
GNEChange_Edge.h GNEChange_Edge.cpp \
GNEChange_Crossing.h GNEChange_Crossing.cpp \
GNEChange_Lane.h GNEChange_Lane.cpp \
GNEChange_Connection.h GNEChange_Connection.cpp \
GNEChange_Attribute.h GNEChange_Attribute.cpp \
GNEChange_TLS.h GNEChange_TLS.cpp \
GNEChange_Selection.h GNEChange_Selection.cpp \
GNEChange_Additional.h GNEChange_Additional.cpp \
GNEUndoList.h GNEUndoList.cpp \
GNEAttributeCarrier.h GNEAttributeCarrier.cpp \
GNEFrame.h GNEFrame.cpp \
GNEInspectorFrame.h GNEInspectorFrame.cpp \
GNESelectorFrame.h GNESelectorFrame.cpp \
GNEConnectorFrame.h GNEConnectorFrame.cpp \
GNETLSEditorFrame.h GNETLSEditorFrame.cpp \
GNEAdditionalFrame.h GNEAdditionalFrame.cpp \
GNECrossingFrame.h GNECrossingFrame.cpp \
GNEDeleteFrame.h GNEDeleteFrame.cpp \
GNEAdditionalHandler.h GNEAdditionalHandler.cpp \
GNEAdditional.h GNEAdditional.cpp \
GNEAdditionalSet.h GNEAdditionalSet.cpp \
GNEChargingStation.h GNEChargingStation.cpp \
GNEStoppingPlace.h GNEStoppingPlace.cpp \
GNEBusStop.h GNEBusStop.cpp \
GNEContainerStop.h GNEContainerStop.cpp \
GNEDetector.h GNEDetector.cpp \
GNEDetectorE1.h GNEDetectorE1.cpp \
GNEDetectorE2.h GNEDetectorE2.cpp \
GNEDetectorE3.h GNEDetectorE3.cpp \
GNEDetectorEntry.h GNEDetectorEntry.cpp \
GNEDetectorExit.h GNEDetectorExit.cpp \
GNERerouter.h GNERerouter.cpp \
GNERerouterDialog.h GNERerouterDialog.cpp \
GNERouteProbe.h GNERouteProbe.cpp \
GNEVaporizer.h GNEVaporizer.cpp \
GNECalibrator.h GNECalibrator.cpp \
GNECalibratorDialog.h GNECalibratorDialog.cpp \
GNEVariableSpeedSignal.h GNEVariableSpeedSignal.cpp \
GNEVariableSpeedSignalDialog.h GNEVariableSpeedSignalDialog.cpp \
GNEReferenceCounter.h GNEEvent_NetworkLoaded.h



netedit_LDADD = ../netimport/libnetimport.la \
../netimport/vissim/libvissimimport.la \
../netimport/vissim/typeloader/libvissimtypeload.la \
../netimport/vissim/tempstructs/libvissimtmpstr.la \
../netbuild/libnetbuild.la \
../netwrite/libnetwrite.la \
../utils/distribution/libdistribution.la \
../foreign/eulerspiral/libeulerspiral.la \
../utils/gui/windows/libguiutilsWindows.la \
../utils/gui/globjects/libguiutilsglobjects.la \
../utils/gui/div/libguiutilsdiv.la \
../utils/gui/settings/libguiutilssettings.la \
../utils/gui/images/libguiutilsimages.la \
../utils/gui/tracker/libguiutilstracker.la \
../utils/foxtools/libfoxtools.la \
../utils/distribution/libdistribution.la \
../foreign/gl2ps/libgl2ps.la \
../foreign/polyfonts/libpolyfonts.la \
../foreign/eulerspiral/libeulerspiral.la \
../utils/geom/libgeom.la \
../utils/shapes/libshapes.la \
../utils/options/liboptions.la \
../utils/common/libcommon.la \
../utils/emissions/libemissions.la \
../utils/xml/libxml.la \
../utils/importio/libimportio.la \
../utils/iodevices/libiodevices.la \
../foreign/tcpip/libtcpip.la \
$(MEM_LIBS) \
$(XERCES_LIBS) $(FFMPEG_LIBS) \
$(FOX_LDFLAGS) $(XERCES_LDFLAGS) $(PROJ_LDFLAGS) $(GDAL_LDFLAGS) $(X_LDFLAGS)
endif
