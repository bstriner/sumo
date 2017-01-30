#include "libsumo.h"

extern MSNet* libsumo_net;

LIBSUMO_DLL_EXPORTED const char*
libsumo_tls_getstate(const char* id)
{
	if (!libsumo_net->getTLSControl().knows(id)) {
		throw ProcessError("Unknown traffic light");
	}
    MSTLLogicControl::TLSLogicVariants& vars = 
		libsumo_net->getTLSControl().get(id);
	return vars.getActive()->getCurrentPhaseDef().getState().c_str();
}


LIBSUMO_DLL_EXPORTED void
libsumo_tls_setstate(const char* id, const char* state)
{
	if (!libsumo_net->getTLSControl().knows(id)) {
		throw ProcessError("Unknown traffic light");
	}
    MSTLLogicControl::TLSLogicVariants& vars = 
		libsumo_net->getTLSControl().get(id);
	vars.setStateInstantiatingOnline(libsumo_net->getTLSControl(), state);
}

LIBSUMO_DLL_EXPORTED int
libsumo_tls_controlledLanes_count(const char* id)
{
	int count = 0;
	MSTLLogicControl::TLSLogicVariants& vars = libsumo_net->getTLSControl().get(id);
	const MSTrafficLightLogic::LaneVectorVector& lanes = vars.getActive()->getLaneVectors();
	for (MSTrafficLightLogic::LaneVectorVector::const_iterator i = lanes.begin(); i != lanes.end(); ++i) {
		const MSTrafficLightLogic::LaneVector& llanes = (*i);	
		for (MSTrafficLightLogic::LaneVector::const_iterator j = llanes.begin(); j != llanes.end(); ++j) {
			count++;
		}
	}
	return count;
}

LIBSUMO_DLL_EXPORTED void
libsumo_tls_controlledLanes(const char* id, std::basic_string<char>* list)
{
	int k = 0;
	MSTLLogicControl::TLSLogicVariants& vars = libsumo_net->getTLSControl().get(id);
	const MSTrafficLightLogic::LaneVectorVector& lanes = vars.getActive()->getLaneVectors();
	for (MSTrafficLightLogic::LaneVectorVector::const_iterator i = lanes.begin(); i != lanes.end(); ++i) {
		const MSTrafficLightLogic::LaneVector& llanes = (*i);	
		for (MSTrafficLightLogic::LaneVector::const_iterator j = llanes.begin(); j != llanes.end(); ++j) {
			list[k]=(*j)->getID();
			k++;
		}
	}
}
