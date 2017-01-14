#include "libsumo.h"

extern MSNet* libsumo_net;

static PyObject *
pysumo_vehicle_list(PyObject *self, PyObject *args)
{
	PyObject* ids;
	ids = PyList_New(0);
	MSVehicleControl& c = gNet->getVehicleControl();
	for (MSVehicleControl::constVehIt i = c.loadedVehBegin();
		i != c.loadedVehEnd(); ++i) {
		if (i->second->isOnRoad() || i->second->isParking()) {
			PyList_Append(ids, PyString_FromString(i->first.c_str()));
		}
	}
	return ids;
}

static PyObject *
pysumo_vehicle_position(PyObject *self, PyObject *args)
{
	char* cname;
	double x,y,z;
	if (! PyArg_ParseTuple( args, "s", &cname)) return NULL;
	
	SUMOVehicle* sumoVehicle = MSNet::getInstance()->getVehicleControl().getVehicle(cname);
	if (sumoVehicle == 0) {
		PyErr_SetString(PyExc_RuntimeError, "Unknown vehicle");
		return NULL;
	}
	MSVehicle* v = dynamic_cast<MSVehicle*>(sumoVehicle);
	if (v == 0) {
		PyErr_SetString(PyExc_RuntimeError, "Vehicle is not a micro-simulation vehicle");
		return NULL;
	}
	bool onRoad = v->isOnRoad();
	bool visible = onRoad || v->isParking();
	
	x=visible ? v->getPosition().x() : INVALID_DOUBLE_VALUE;
	y=visible ? v->getPosition().y() : INVALID_DOUBLE_VALUE;
	z= visible ? v->getPosition().z() : INVALID_DOUBLE_VALUE;
	return Py_BuildValue("ddd",x,y,z);
}

static PyObject *
pysumo_vehicle_speed(PyObject *self, PyObject *args)
{
	char* cname;
	double speed;
	if (! PyArg_ParseTuple( args, "s", &cname)) return NULL;
	
	SUMOVehicle* sumoVehicle = MSNet::getInstance()->getVehicleControl().getVehicle(cname);
	if (sumoVehicle == 0) {
		PyErr_SetString(PyExc_RuntimeError, "Unknown vehicle");
		return NULL;
	}
	MSVehicle* v = dynamic_cast<MSVehicle*>(sumoVehicle);
	if (v == 0) {
		PyErr_SetString(PyExc_RuntimeError, "Vehicle is not a micro-simulation vehicle");
		return NULL;
	}
	bool onRoad = v->isOnRoad();
	bool visible = onRoad || v->isParking();
	speed = visible ? v->getSpeed() : INVALID_DOUBLE_VALUE;
	return Py_BuildValue("d",speed);
}

static PyObject *
pysumo_vehicle_positions(PyObject *self, PyObject *args)
{
	PyObject* positions;
	positions = PyList_New(0);
	MSVehicleControl& c = gNet->getVehicleControl();
	for (MSVehicleControl::constVehIt i = c.loadedVehBegin();
		i != c.loadedVehEnd(); ++i) {
		if (i->second->isOnRoad() || i->second->isParking()) {
			SUMOVehicle* sumoVehicle = c.getVehicle(i->first.c_str());
			if (sumoVehicle == 0) {
				PyErr_SetString(PyExc_RuntimeError, "Unknown vehicle");
				return NULL;
			}
			MSVehicle* v = dynamic_cast<MSVehicle*>(sumoVehicle);
			if (v == 0) {
				PyErr_SetString(PyExc_RuntimeError, "Vehicle is not a micro-simulation vehicle");
				return NULL;
			}
			bool onRoad = v->isOnRoad();
			bool visible = onRoad || v->isParking();
			double x=visible ? v->getPosition().x() : INVALID_DOUBLE_VALUE;
			double y=visible ? v->getPosition().y() : INVALID_DOUBLE_VALUE;
			double z= visible ? v->getPosition().z() : INVALID_DOUBLE_VALUE;
			PyList_Append(positions, Py_BuildValue("ddd",x,y,z));
		}
	}
	return positions;
}
static PyObject *
pysumo_vehicle_speeds(PyObject *self, PyObject *args)
{
	PyObject* speeds;
	speeds = PyList_New(0);
	MSVehicleControl& c = gNet->getVehicleControl();
	for (MSVehicleControl::constVehIt i = c.loadedVehBegin();
		i != c.loadedVehEnd(); ++i) {
		if (i->second->isOnRoad() || i->second->isParking()) {
			SUMOVehicle* sumoVehicle = c.getVehicle(i->first.c_str());
			if (sumoVehicle == 0) {
				PyErr_SetString(PyExc_RuntimeError, "Unknown vehicle");
				return NULL;
			}
			MSVehicle* v = dynamic_cast<MSVehicle*>(sumoVehicle);
			if (v == 0) {
				PyErr_SetString(PyExc_RuntimeError, "Vehicle is not a micro-simulation vehicle");
				return NULL;
			}
			bool onRoad = v->isOnRoad();
			bool visible = onRoad || v->isParking();
			double speed = visible ? v->getSpeed() : INVALID_DOUBLE_VALUE;
			PyList_Append(speeds, Py_BuildValue("d",speed));
		}
	}
	return speeds;
}
