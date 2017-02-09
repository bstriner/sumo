#include "libsumo.h"

extern MSNet* libsumo_net;

LIBSUMO_DLL_EXPORTED int
libsumo_vehicle_count()
{
	int count = 0;
	MSVehicleControl& c = libsumo_net->getVehicleControl();
	for (MSVehicleControl::constVehIt i = c.loadedVehBegin();
		i != c.loadedVehEnd(); ++i) {
		if (i->second->isOnRoad() || i->second->isParking()) {
			count++;
		}
	}
	return count;
	
}


LIBSUMO_DLL_EXPORTED void
libsumo_vehicle_list(std::basic_string<char>* list)
{
	int j = 0;
	MSVehicleControl& c = libsumo_net->getVehicleControl();
	for (MSVehicleControl::constVehIt i = c.loadedVehBegin();
		i != c.loadedVehEnd(); ++i) {
		if (i->second->isOnRoad() || i->second->isParking()) {
			list[j] = i->first;
			j++;
		}
	}
}

LIBSUMO_DLL_EXPORTED void
libsumo_vehicle_position(const char* id, double* pos)
{
	SUMOVehicle* sumoVehicle = libsumo_net->getVehicleControl().getVehicle(id);
	if (sumoVehicle == 0) {
		throw ProcessError("Unknown vehicle");
	}
	MSVehicle* v = dynamic_cast<MSVehicle*>(sumoVehicle);
	if (v == 0) {
		throw ProcessError("Vehicle is not a micro-simulation vehicle");
	}
	bool onRoad = v->isOnRoad();
	bool visible = onRoad || v->isParking();
	
	pos[0]=visible ? v->getPosition().x() : INVALID_DOUBLE_VALUE;
	pos[1]=visible ? v->getPosition().y() : INVALID_DOUBLE_VALUE;
	pos[2]=visible ? v->getPosition().z() : INVALID_DOUBLE_VALUE;
}

LIBSUMO_DLL_EXPORTED double
libsumo_vehicle_lane_position(const char* id)
{
	SUMOVehicle* sumoVehicle = libsumo_net -> getVehicleControl().getVehicle(id);
	if(sumoVehicle == 0){
		throw ProcessError("Unknown vehicle");
	}
	MSVehicle* v = dynamic_cast<MSVehicle*>(sumoVehicle);
	if (v == 0) {
                throw ProcessError("Vehicle is not a micro-simulation vehicle");
        }
	bool onRoad = v->isOnRoad();
	bool visible = onRoad || v->isParking();
	return visible ? v->getPositionOnLane() : INVALID_DOUBLE_VALUE;
}
LIBSUMO_DLL_EXPORTED double
libsumo_vehicle_speed(const char* id)
{
	SUMOVehicle* sumoVehicle = libsumo_net->getVehicleControl().getVehicle(id);
	if (sumoVehicle == 0) {
		throw ProcessError("Unknown vehicle");
	}
	MSVehicle* v = dynamic_cast<MSVehicle*>(sumoVehicle);
	if (v == 0) {
		throw ProcessError( "Vehicle is not a micro-simulation vehicle");
	}
	bool onRoad = v->isOnRoad();
	bool visible = onRoad || v->isParking();
	return visible ? v->getSpeed() : INVALID_DOUBLE_VALUE;
}

LIBSUMO_DLL_EXPORTED double
libsumo_vehicle_waitingtime(const char* id)
{
	SUMOVehicle* sumoVehicle = libsumo_net->getVehicleControl().getVehicle(id);
	if (sumoVehicle == 0) {
		throw ProcessError("Unknown vehicle");
	}
	MSVehicle* v = dynamic_cast<MSVehicle*>(sumoVehicle);
	if (v == 0) {
		throw ProcessError( "Vehicle is not a micro-simulation vehicle");
	}

	return v->getWaitingSeconds();
}

LIBSUMO_DLL_EXPORTED void
libsumo_vehicle_positions(double* positions)
{
	MSVehicleControl& c = libsumo_net->getVehicleControl();
	int j = 0;
	for (MSVehicleControl::constVehIt i = c.loadedVehBegin();
		i != c.loadedVehEnd(); ++i) {
		if (i->second->isOnRoad() || i->second->isParking()) {
			SUMOVehicle* sumoVehicle = c.getVehicle(i->first.c_str());
			if (sumoVehicle == 0) {
				throw ProcessError("Unknown vehicle");
			}
			MSVehicle* v = dynamic_cast<MSVehicle*>(sumoVehicle);
			if (v == 0) {
				throw ProcessError("Vehicle is not a micro-simulation vehicle");
			}
			bool onRoad = v->isOnRoad();
			bool visible = onRoad || v->isParking();
			positions[j*3+0]=visible ? v->getPosition().x() : INVALID_DOUBLE_VALUE;
			positions[j*3+1]=visible ? v->getPosition().y() : INVALID_DOUBLE_VALUE;
			positions[j*3+2]=visible ? v->getPosition().z() : INVALID_DOUBLE_VALUE;
			j++;
		}
	}
}

LIBSUMO_DLL_EXPORTED void
libsumo_vehicle_speeds(double* speeds)
{
	int j=0;
	MSVehicleControl& c = libsumo_net->getVehicleControl();
	for (MSVehicleControl::constVehIt i = c.loadedVehBegin();
		i != c.loadedVehEnd(); ++i) {
		if (i->second->isOnRoad() || i->second->isParking()) {
			SUMOVehicle* sumoVehicle = c.getVehicle(i->first.c_str());
			if (sumoVehicle == 0) {
				throw ProcessError("Unknown vehicle");
			}
			MSVehicle* v = dynamic_cast<MSVehicle*>(sumoVehicle);
			if (v == 0) {
				throw ProcessError("Vehicle is not a micro-simulation vehicle");
			}
			bool onRoad = v->isOnRoad();
			bool visible = onRoad || v->isParking();
			speeds[j]= visible ? v->getSpeed() : INVALID_DOUBLE_VALUE;
			j++;
		}
	}
}
