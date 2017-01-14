#include "libsumo.h"

extern MSNet* libsumo_net;

LIBSUMO_DLL_EXPORTED double
libsumo_inductionloop_meanspeed(const char* id)
{
	MSInductLoop* il = 
		dynamic_cast<MSInductLoop*>(libsumo_net->getDetectorControl()
		.getTypedDetectors(SUMO_TAG_INDUCTION_LOOP).get(id));
	if (il == 0) {
		throw ProcessError("Unknown induction loop");
	}
	return il->getCurrentSpeed();
}

LIBSUMO_DLL_EXPORTED int
libsumo_inductionloop_vehiclenumber(const char* id)
{
	MSInductLoop* il = 
		dynamic_cast<MSInductLoop*>(libsumo_net->getDetectorControl()
		.getTypedDetectors(SUMO_TAG_INDUCTION_LOOP).get(id));
	if (il == 0) {
		throw ProcessError("Unknown induction loop");
	}
	return il->getCurrentPassedNumber();
}