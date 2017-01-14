#include <microsim/MSFrame.h>
#include <microsim/output/MSDetectorControl.h>
#include <ctime>
#include <string>
#include <iostream>
#include <microsim/MSGlobals.h>
#include <microsim/MSNet.h>
#include <microsim/MSRoute.h>
#include <microsim/MSVehicleControl.h>
#include <netload/NLBuilder.h>
#include <netload/NLHandler.h>
#include <netload/NLTriggerBuilder.h>
#include <netload/NLEdgeControlBuilder.h>
#include <netload/NLJunctionControlBuilder.h>
#include <netload/NLDetectorBuilder.h>
#include <utils/options/OptionsCont.h>
#include <utils/options/OptionsIO.h>
#include <utils/common/MsgHandler.h>
#include <utils/common/SystemFrame.h>
#include <utils/common/UtilExceptions.h>
#include <utils/common/FileHelpers.h>
#include <utils/common/StringTokenizer.h>
#include <utils/common/ToString.h>
#include <utils/xml/XMLSubSys.h>
#include <microsim/MSFrame.h>
#include <microsim/output/MSDetectorControl.h>
#include <utils/iodevices/OutputDevice.h>
#include <mesosim/MEVehicleControl.h>

//#define HAVE_INTERNAL_LANES
//#define NO_TRACI

#ifndef NO_TRACI
#include <traci-server/TraCIServer.h>
#endif

#ifdef CHECK_MEMORY_LEAKS
#include <foreign/nvwa/debug_new.h>
#endif

#if BUILDING_LIBSUMO && HAVE_VISIBILITY
#define LIBSUMO_DLL_EXPORTED __attribute__((__visibility__("default")))
#elif BUILDING_LIBSUMO && defined _MSC_VER
#define LIBSUMO_DLL_EXPORTED __declspec(dllexport)
#elif defined _MSC_VER
#define LIBSUMO_DLL_EXPORTED __declspec(dllimport)
#else
#define LIBSUMO_DLL_EXPORTED
#endif
