/****************************************************************************/
/// @file    MSCFModel.cpp
/// @author  Tobias Mayer
/// @author  Daniel Krajzewicz
/// @author  Jakob Erdmann
/// @author  Michael Behrisch
/// @author  Laura Bieker
/// @date    Mon, 27 Jul 2009
/// @version $Id$
///
// The car-following model abstraction
/****************************************************************************/
// SUMO, Simulation of Urban MObility; see http://sumo-sim.org/
// Copyright (C) 2001-2014 DLR (http://www.dlr.de/) and contributors
/****************************************************************************/
//
//   This file is part of SUMO.
//   SUMO is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
/****************************************************************************/


// ===========================================================================
// included modules
// ===========================================================================
#ifdef _MSC_VER
#include <windows_config.h>
#else
#include <config.h>
#endif

#include <math.h>
#include <microsim/MSVehicleType.h>
#include <microsim/MSVehicle.h>
#include <microsim/MSLane.h>
#include <microsim/MSAbstractLaneChangeModel.h>
#include "MSCFModel.h"


// ===========================================================================
// method definitions
// ===========================================================================
MSCFModel::MSCFModel(const MSVehicleType* vtype, const SUMOReal accel,
                     const SUMOReal decel, const SUMOReal headwayTime)
    : myType(vtype), myAccel(accel), myDecel(decel), myHeadwayTime(headwayTime) {
}


MSCFModel::~MSCFModel() {}


SUMOReal
MSCFModel::moveHelper(MSVehicle* const veh, SUMOReal vPos) const {
    const SUMOReal oldV = veh->getSpeed(); // save old v for optional acceleration computation
    const SUMOReal vSafe = MIN2(vPos, veh->processNextStop(vPos)); // process stops
    // we need the acceleration for emission computation;
    //  in this case, we neglect dawdling, nonetheless, using
    //  vSafe does not incorporate speed reduction due to interaction
    //  on lane changing
    const SUMOReal vMin = getSpeedAfterMaxDecel(oldV);
    const SUMOReal vMax = MIN3(veh->getLane()->getVehicleMaxSpeed(veh), maxNextSpeed(oldV, veh), vSafe);
    assert(vMin <= vMax);
    return veh->getLaneChangeModel().patchSpeed(vMin, vMax, vMax, *this);
}


SUMOReal
MSCFModel::interactionGap(const MSVehicle* const veh, SUMOReal vL) const {
    // Resolve the vsafe equation to gap. Assume predecessor has
    // speed != 0 and that vsafe will be the current speed plus acceleration,
    // i.e that with this gap there will be no interaction.
    const SUMOReal vNext = MIN2(maxNextSpeed(veh->getSpeed(), veh), veh->getLane()->getVehicleMaxSpeed(veh));
    const SUMOReal gap = (vNext - vL) *
                         ((veh->getSpeed() + vL) / (2.*myDecel) + myHeadwayTime) +
                         vL * myHeadwayTime;

    // Don't allow timeHeadWay < deltaT situations.
    return MAX2(gap, SPEED2DIST(vNext));
}


SUMOReal
MSCFModel::maxNextSpeed(SUMOReal speed, const MSVehicle* const /*veh*/) const {
    return MIN2(speed + (SUMOReal) ACCEL2SPEED(getMaxAccel()), myType->getMaxSpeed());
}


SUMOReal
MSCFModel::freeSpeed(const MSVehicle* const /* veh */, SUMOReal /* speed */, SUMOReal seen, SUMOReal maxSpeed) const {
    return freeSpeed(myDecel, seen, maxSpeed);
}

/****************************************************************************/