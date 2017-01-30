#include "libsumo.h"

extern MSNet* libsumo_net;

LIBSUMO_DLL_EXPORTED void
libsumo_lane_list(std::basic_string<char>* list)
{
	std::vector<std::string> ids;
	MSLane::insertIDs(ids);
	int j = 0;
	for(std::vector<std::string>::iterator it = ids.begin(); it != ids.end(); ++it)
	{
		list[j]= *it;
		j++;
	}

}

LIBSUMO_DLL_EXPORTED int
libsumo_lane_count()
{
	std::vector<std::string> ids;
	MSLane::insertIDs(ids);
	return ids.size();
}

LIBSUMO_DLL_EXPORTED std::vector<std::string>
libsumo_lane_onLaneVehicles(const char* id)
{
	MSLane* lane = MSLane::dictionary(id);
	std::vector<std::string> vehIDs;
	const MSLane::VehCont& vehs = lane->getVehiclesSecure();
	for (MSLane::VehCont::const_iterator j = vehs.begin(); j != vehs.end(); ++j) {
                    vehIDs.push_back((*j)->getID());
                }
	lane->releaseVehicles();
	return vehIDs;
}
