#include "libsumo.h"

extern MSNet* libsumo_net;

LIBSUMO_DLL_EXPORTED static const char*
pysumo_tls_getstate(PyObject *self, PyObject *args)
{
	char* cname;
	if (! PyArg_ParseTuple( args, "s", &cname)) return NULL;	
	if (!gNet->getTLSControl().knows(cname)) {
		PyErr_SetString(PyExc_RuntimeError, "Unknown traffic light");
		return NULL;
	}
    MSTLLogicControl::TLSLogicVariants& vars = 
		gNet->getTLSControl().get(cname);
	return vars.getActive()->getCurrentPhaseDef().getState();
}


LIBSUMO_DLL_EXPORTED static void
pysumo_tls_setstate(const char* id, const char* state)
{
	if (!gNet->getTLSControl().knows(id)) {
		throw new ProcessError("Unknown traffic light");
	}
    MSTLLogicControl::TLSLogicVariants& vars = 
		gNet->getTLSControl().get(id);
	vars.setStateInstantiatingOnline(gNet->getTLSControl(), state);
}
