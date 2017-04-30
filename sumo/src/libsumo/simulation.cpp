#include "libsumo.h"

extern MSNet* libsumo_net;
/**
 * loads the net, additional routes and the detectors
 */
MSNet*
load(OptionsCont& oc) {
    MSFrame::setMSGlobals(oc);
    MSVehicleControl* vc = 0;
    if (MSGlobals::gUseMesoSim) {
        vc = new MEVehicleControl();
    } else {
        vc = new MSVehicleControl();
    }
    MSNet* net = new MSNet(vc, new MSEventControl(),
                           new MSEventControl(), new MSEventControl());
    NLEdgeControlBuilder eb;
    NLDetectorBuilder db(*net);
    NLJunctionControlBuilder jb(*net, db);
    NLTriggerBuilder tb;
    NLHandler handler("", *net, db, tb, eb, jb);
    tb.setHandler(&handler);
    NLBuilder builder(oc, *net, eb, jb, db, handler);
    if (!builder.build()) {
        delete net;
        throw ProcessError();
    }
    return net;
}

LIBSUMO_DLL_EXPORTED void 
libsumo_simulation_start(int sumo_argc, char** sumo_argv)
{
	OptionsCont& oc = OptionsCont::getOptions();
    oc.setApplicationDescription("A microscopic road traffic simulation.");
    oc.setApplicationName("sumo", "SUMO Version pysumo");
	XMLSubSys::init();
    MSFrame::fillOptions();
	OptionsIO::setArgs(sumo_argc, sumo_argv);
    OptionsIO::getOptions();
    if (oc.processMetaOptions(sumo_argc < 2)) {
		throw ProcessError();
	}
	XMLSubSys::setValidation(
		oc.getString("xml-validation"), 
		oc.getString("xml-validation.net"));
	if (!MSFrame::checkOptions()) {
		throw ProcessError();
	}
	MsgHandler::initOutputOptions();
	RandHelper::initRandGlobal();
	RandHelper::initRandGlobal(MSRouteHandler::getParsingRNG());
	libsumo_net = load(oc);
    libsumo_net->loadRoutes();
}

LIBSUMO_DLL_EXPORTED void
libsumo_simulation_stop()
{
	libsumo_net->closeSimulation(0);
    delete libsumo_net;
    SystemFrame::close();
}

LIBSUMO_DLL_EXPORTED void
libsumo_simulation_step()
{
	libsumo_net->simulationStep();
}

LIBSUMO_DLL_EXPORTED int
libsumo_simulation_minexpectednumber()
{
	return libsumo_net->getVehicleControl().getActiveVehicleCount() +libsumo_net->getInsertionControl().getPendingFlowCount();
}

LIBSUMO_DLL_EXPORTED std::string
libsumo_simulation_tripstatistics()
{
	return MSDevice_Tripinfo::printStatistics();
}
