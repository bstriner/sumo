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
