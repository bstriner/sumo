#include <microsim/MSFrame.h>
#include <microsim/output/MSDetectorControl.h>
#include <ctime>
#include <string>
#include <iostream>
#include <microsim/MSGlobals.h>
#include <microsim/MSNet.h>
#include <microsim/MSRoute.h>
#include <microsim/MSVehicleControl.h>
#include <microsim/MSInsertionControl.h>
#include <microsim/MSLane.h>
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
#include <microsim/devices/MSDevice_Tripinfo.h>

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



LIBSUMO_DLL_EXPORTED void 
	libsumo_simulation_start(int sumo_argc, char** sumo_argv);
LIBSUMO_DLL_EXPORTED void 
	libsumo_simulation_stop();
LIBSUMO_DLL_EXPORTED void 
	libsumo_simulation_step();
LIBSUMO_DLL_EXPORTED int
	libsumo_simulation_minexpectednumber();
LIBSUMO_DLL_EXPORTED std::string
	libsumo_simulation_tripstatistics();
LIBSUMO_DLL_EXPORTED const char* 
	libsumo_tls_getstate(const char* id);
LIBSUMO_DLL_EXPORTED void 
	libsumo_tls_setstate(const char* id, const char* state);
LIBSUMO_DLL_EXPORTED int
	libsumo_vehicle_count();
LIBSUMO_DLL_EXPORTED void
	libsumo_vehicle_list(std::basic_string<char>* list);
LIBSUMO_DLL_EXPORTED void
	libsumo_vehicle_position(const char* id, double* pos);
LIBSUMO_DLL_EXPORTED double 
	libsumo_vehicle_speed(const char* id);
LIBSUMO_DLL_EXPORTED double
	libsumo_vehicle_waitingtime(const char* id);
LIBSUMO_DLL_EXPORTED void
	libsumo_vehicle_positions(double* positions);
LIBSUMO_DLL_EXPORTED double
	libsumo_vehicle_lane_position(const char* id);
LIBSUMO_DLL_EXPORTED void
	libsumo_vehicle_speeds(double* speeds);
LIBSUMO_DLL_EXPORTED double 
	libsumo_meme_meanspeed(const char* id);
LIBSUMO_DLL_EXPORTED int 
	libsumo_meme_vehiclenumber(const char* id);
LIBSUMO_DLL_EXPORTED int
	libsumo_meme_vehiclehaltingnumber(const char* id);
LIBSUMO_DLL_EXPORTED std::vector<std::string>
	libsumo_meme_vehicleids(const char* id);
LIBSUMO_DLL_EXPORTED double 
	libsumo_inductionloop_meanspeed(const char* id);
LIBSUMO_DLL_EXPORTED int 
	libsumo_inductionloop_vehiclenumber(const char* id);
LIBSUMO_DLL_EXPORTED int
	libsumo_tls_controlledLanes_count(const char* id);
LIBSUMO_DLL_EXPORTED void
	libsumo_tls_controlledLanes(const char* id, std::basic_string<char>* list);
LIBSUMO_DLL_EXPORTED void
	libsumo_lane_list(std::basic_string<char>* list);
LIBSUMO_DLL_EXPORTED int
	libsumo_lane_count();
LIBSUMO_DLL_EXPORTED std::vector<std::string>
	libsumo_lane_onLaneVehicles(const char* id);
