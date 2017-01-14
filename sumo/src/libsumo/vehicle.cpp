#include "libsumo.h"

extern MSNet* libsumo_net;

LIBSUMO_DLL_EXPORTED std::vector<string>
libsumo_vehicle_list()
{
	std::vector<string> v = {}
	MSVehicleControl& c = libsumo_net->getVehicleControl();
	for (MSVehicleControl::constVehIt i = c.loadedVehBegin();
		i != c.loadedVehEnd(); ++i) {
		if (i->second->isOnRoad() || i->second->isParking()) {
			v.push_back(i->first);
		}
	}
	return ids;
}

LIBSUMO_DLL_EXPORTED std::tuple<double,double,double>
libsumo_vehicle_position(const char* id)
{
	double x,y,z;	
	SUMOVehicle* sumoVehicle = libsumo_net->getVehicleControl().getVehicle(id);
	if (sumoVehicle == 0) {
		throw PRocessError("Unknown vehicle");
	}
	MSVehicle* v = dynamic_cast<MSVehicle*>(sumoVehicle);
	if (v == 0) {
		throw ProcessError("Vehicle is not a micro-simulation vehicle");
	}
	bool onRoad = v->isOnRoad();
	bool visible = onRoad || v->isParking();
	
	x=visible ? v->getPosition().x() : INVALID_DOUBLE_VALUE;
	y=visible ? v->getPosition().y() : INVALID_DOUBLE_VALUE;
	z=visible ? v->getPosition().z() : INVALID_DOUBLE_VALUE;
	return std::make_tuple(x,y,z);
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

LIBSUMO_DLL_EXPORTED std::vector<std::tuple<double, double, double>>
libsumo_vehicle_positions()
{
	std::vector<std::tuple<double, double, double>> v = {}
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
			double x=visible ? v->getPosition().x() : INVALID_DOUBLE_VALUE;
			double y=visible ? v->getPosition().y() : INVALID_DOUBLE_VALUE;
			double z= visible ? v->getPosition().z() : INVALID_DOUBLE_VALUE;
			v.push_back(std::make_tuple(x,y,z))
		}
	}
	return v;
}

LIBSUMO_DLL_EXPORTED std::vector<double>
libsumo_vehicle_speeds()
{
	std::vector<double> v = {}
	MSVehicleControl& c = libsumo_net->getVehicleControl();
	for (MSVehicleControl::constVehIt i = c.loadedVehBegin();
		i != c.loadedVehEnd(); ++i) {
		if (i->second->isOnRoad() || i->second->isParking()) {
			SUMOVehicle* sumoVehicle = c.getVehicle(i->first.c_str());
			if (sumoVehicle == 0) {
				throw ProcessError(PyExc_RuntimeError, "Unknown vehicle");
			}
			MSVehicle* v = dynamic_cast<MSVehicle*>(sumoVehicle);
			if (v == 0) {
				throw ProcessError(PyExc_RuntimeError, "Vehicle is not a micro-simulation vehicle");
			}
			bool onRoad = v->isOnRoad();
			bool visible = onRoad || v->isParking();
			double speed = visible ? v->getSpeed() : INVALID_DOUBLE_VALUE;
			v.push_back(speed);
		}
	}
	return v;
}
