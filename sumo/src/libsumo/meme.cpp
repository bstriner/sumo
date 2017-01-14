#include "libsumo.h"

extern MSNet* libsumo_net;

LIBSUMO_DLL_EXPORTED static double
pysumo_meme_meanspeed(const char* id)
{
	MSE3Collector* e3 = 
		static_cast<MSE3Collector*>(libsumo_net->getDetectorControl()
		.getTypedDetectors(SUMO_TAG_ENTRY_EXIT_DETECTOR).get(id));
	if (e3 == 0) {
		throw ProcessError("Unknown meme detector");
	}
	return e3->getCurrentMeanSpeed();
}

LIBSUMO_DLL_EXPORTED static int
pysumo_meme_vehiclenumber(const char* id)
{
	MSE3Collector* e3 = 
		static_cast<MSE3Collector*>(libsumo_net->getDetectorControl()
		.getTypedDetectors(SUMO_TAG_ENTRY_EXIT_DETECTOR).get(id));
	if (e3 == 0) {
		throw ProcessError("Unknown meme detector");
	}
	return e3->getVehiclesWithin();
}
