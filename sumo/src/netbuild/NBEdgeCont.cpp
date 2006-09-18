/***************************************************************************
                          NBEdgeCont.cpp
              A container for all of the nets edges
                             -------------------
    project              : SUMO
    subproject           : netbuilder / netconverter
    begin                : Tue, 20 Nov 2001
    copyright            : (C) 2001 by DLR http://ivf.dlr.de/
    author               : Daniel Krajzewicz
    email                : Daniel.Krajzewicz@dlr.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
namespace
{
    const char rcsid[] =
    "$Id$";
}
// $Log$
// Revision 1.50  2006/09/18 10:09:29  dkrajzew
// patching junction-internal state simulation
//
// Revision 1.49  2006/07/06 06:48:00  dkrajzew
// changed the retrieval of connections-API; some unneeded variables removed
//
// Revision 1.48  2006/04/18 08:05:44  dkrajzew
// beautifying: output consolidation
//
// Revision 1.47  2006/04/05 05:30:42  dkrajzew
// code beautifying: embedding string in strings removed
//
// Revision 1.46  2006/03/17 11:03:04  dkrajzew
// made access to positions in Position2DVector c++ compliant
//
// Revision 1.45  2006/03/08 13:14:15  dkrajzew
// debugging on/off-ramp geometries
//
// Revision 1.44  2006/02/13 07:17:35  dkrajzew
// code beautifying; added pois output of built tls
//
// Revision 1.43  2006/01/17 14:11:52  dkrajzew
// "split-geometry" - option added (unfinsihed, rename)
//
// Revision 1.42  2006/01/11 11:59:20  dkrajzew
// patched reassignment of explicite connections
//
// Revision 1.41  2005/12/01 07:38:13  dkrajzew
// debugging plain edge output
//
// Revision 1.40  2005/11/30 08:53:03  dkrajzew
// removed warning if no types are defined
//
// Revision 1.39  2005/11/09 06:40:49  dkrajzew
// complete geometry building rework (unfinished)
//
// Revision 1.38  2005/10/17 09:02:44  dkrajzew
// got rid of the old MSVC memory leak checker; memory leaks removed
//
// Revision 1.37  2005/10/07 11:38:18  dkrajzew
// THIRD LARGE CODE RECHECK: patched problems on Linux/Windows configs
//
// Revision 1.36  2005/09/23 06:01:05  dkrajzew
// SECOND LARGE CODE RECHECK: converted doubles and floats to SUMOReal
//
// Revision 1.35  2005/09/15 12:02:45  dkrajzew
// LARGE CODE RECHECK
//
// Revision 1.34  2005/07/12 12:32:47  dkrajzew
// code style adapted; guessing of ramps and unregulated near districts implemented; debugging
//
// Revision 1.33  2005/04/27 11:48:25  dkrajzew
// level3 warnings removed; made containers non-static
//
// Revision 1.32  2005/01/27 14:26:08  dkrajzew
// patched several problems on determination of the turning direction; code beautifying
//
// Revision 1.31  2004/12/16 13:59:17  dkrajzew
// debugging
//
// Revision 1.30  2004/12/16 12:16:30  dkrajzew
// a further network prune option added
//
// Revision 1.29  2004/11/23 10:21:41  dkrajzew
// debugging
//
// Revision 1.28  2004/08/02 13:11:39  dkrajzew
// made some deprovements or so
//
// Revision 1.27  2004/07/02 09:30:55  dkrajzew
// removal of edges with a too low speed added
//
// Revision 1.26  2004/03/19 13:06:09  dkrajzew
// some further work on vissim-import and geometry computation
//
// Revision 1.25  2004/01/28 12:40:23  dkrajzew
// added to possibility to give each lane a speed
//
// Revision 1.24  2004/01/12 15:25:09  dkrajzew
// node-building classes are now lying in an own folder
//
// Revision 1.23  2003/11/11 08:33:54  dkrajzew
// consequent position2D instead of two SUMOReals added
//
// Revision 1.22  2003/10/28 09:47:28  dkrajzew
// lane2lane connections are now kept when edges are joined
//
// Revision 1.21  2003/10/15 11:45:17  dkrajzew
// unneeded debug-ifs removed
//
// Revision 1.20  2003/10/06 07:46:12  dkrajzew
// further work on vissim import (unsignalised vs. signalised streams
//  modality cleared & lane2lane instead of edge2edge-prohibitions implemented
//
// Revision 1.19  2003/09/22 12:40:11  dkrajzew
// further work on vissim-import
//
// Revision 1.18  2003/09/05 15:16:57  dkrajzew
// umlaute conversion; node geometry computation; internal links computation
//
// Revision 1.17  2003/08/14 13:51:51  dkrajzew
// reshifting of networks added
//
// Revision 1.16  2003/07/22 15:09:11  dkrajzew
// removed warnings
//
// Revision 1.15  2003/07/07 08:22:42  dkrajzew
// some further refinements due to the new 1:N traffic lights and usage of
//  geometry information
//
// Revision 1.14  2003/06/18 11:13:13  dkrajzew
// new message and error processing: output to user may be a message,
//  warning or an error now; it is reported to a Singleton (MsgHandler);
//  this handler puts it further to output instances.
//  changes: no verbose-parameter needed; messages are exported to singleton
//
// Revision 1.13  2003/06/05 11:43:35  dkrajzew
// class templates applied; documentation added
//
// Revision 1.12  2003/05/21 15:18:19  dkrajzew
// yellow traffic lights implemented
//
// Revision 1.11  2003/05/20 09:33:47  dkrajzew
// false computation of yielding on lane ends debugged;
//  some debugging on tl-import; further work on vissim-import
//
// Revision 1.10  2003/04/14 08:34:57  dkrajzew
// some further bugs removed
//
// Revision 1.9  2003/04/01 15:15:51  dkrajzew
// further work on vissim-import
//
// Revision 1.8  2003/03/19 08:03:40  dkrajzew
// splitting of edges made a little bit more stable
//
// Revision 1.7  2003/03/17 14:22:33  dkrajzew
// further debug and windows eol removed
//
// Revision 1.6  2003/03/12 16:47:53  dkrajzew
// extension for artemis-import
//
// Revision 1.5  2003/03/06 17:18:33  dkrajzew
// debugging during vissim implementation
//
// Revision 1.4  2003/03/03 14:59:04  dkrajzew
// debugging; handling of imported traffic light definitions
//
// Revision 1.3  2003/02/13 15:51:04  dkrajzew
// functions for merging edges with the same origin and destination added
//
// Revision 1.2  2003/02/07 10:43:44  dkrajzew
// updated
//
// Revision 1.1  2002/10/16 15:48:13  dkrajzew
// initial commit for net building classes
//
// Revision 1.6  2002/07/25 08:31:42  dkrajzew
// Report methods transfered from loader to the containers
//
// Revision 1.5  2002/06/11 16:00:41  dkrajzew
// windows eol removed; template class definition inclusion depends now
//  on the EXTERNAL_TEMPLATE_DEFINITION-definition
//
// Revision 1.4  2002/06/07 14:58:45  dkrajzew
// Bugs on dead ends and junctions with too few outgoing roads fixed;
//  Comments improved
//
// Revision 1.3  2002/05/14 04:42:55  dkrajzew
// new computation flow
//
// Revision 1.2  2002/04/26 10:07:10  dkrajzew
// Windows eol removed; minor SUMOReal to int conversions removed;
//
// Revision 1.1.1.1  2002/04/09 14:18:27  dkrajzew
// new version-free project name (try2)
//
// Revision 1.1.1.1  2002/04/09 13:22:00  dkrajzew
// new version-free project name
//
// Revision 1.3  2002/04/09 12:21:24  dkrajzew
// Windows-Memoryleak detection changed
//
// Revision 1.2  2002/03/22 10:50:03  dkrajzew
// Memory leaks debugging added (MSVC++)
//
// Revision 1.1.1.1  2002/02/19 15:33:04  traffic
// Initial import as a separate application.
//
// Revision 1.1  2001/12/06 13:38:00  traffic
// files for the netbuilder
//
/* =========================================================================
 * compiler pragmas
 * ======================================================================= */
#pragma warning(disable: 4786)


/* =========================================================================
 * included modules
 * ======================================================================= */
#ifdef HAVE_CONFIG_H
#ifdef WIN32
#include <windows_config.h>
#else
#include <config.h>
#endif
#endif // HAVE_CONFIG_H

#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <utils/geom/GeomHelper.h>
#include <utils/common/MsgHandler.h>
#include <utils/common/ToString.h>
#include <utils/options/OptionsSubSys.h>
#include <utils/options/OptionsCont.h>
#include "NBEdgeCont.h"
#include "nodes/NBNodeCont.h"
#include "NBHelpers.h"
#include "NBCont.h"
#include "NBTrafficLightLogicCont.h"
#include "NBDistrictCont.h"
#include <cmath>
#include "NBTypeCont.h"
#include <iostream>
#include <utils/common/StringTokenizer.h>
#include <utils/common/UtilExceptions.h>

#ifdef _DEBUG
#include <utils/dev/debug_new.h>
#endif // _DEBUG


/* =========================================================================
 * debug definitions
 * ======================================================================= */
#define DEBUG_OUT cout


/* =========================================================================
 * used namespaces
 * ======================================================================= */
using namespace std;


/* =========================================================================
 * some definitions (debugging only)
 * ======================================================================= */
#define DEBUG_OUT cout


/* =========================================================================
 * method definitions
 * ======================================================================= */
NBEdgeCont::NBEdgeCont()
    : EdgesSplit(0)
{
}


NBEdgeCont::~NBEdgeCont()
{
    clear();
}

bool
NBEdgeCont::insert(NBEdge *edge)
{
    EdgeCont::iterator i = _edges.find(edge->getID());
    if(i!=_edges.end()) {
        return false;
    }
    if(OptionsSubSys::getOptions().isSet("edges-min-speed")) {
        if(edge->getSpeed()<OptionsSubSys::getOptions().getFloat("edges-min-speed")) {
            edge->getFromNode()->removeOutgoing(edge);
            edge->getToNode()->removeIncoming(edge);
            delete edge;
            return true;
        }
    }
    // check whether the edge is a named edge to keep
    if( !OptionsSubSys::getOptions().getBool("keep-edges.postload")
        &&
        OptionsSubSys::getOptions().isSet("keep-edges")) {

        if(!OptionsSubSys::helper_CSVOptionMatches("keep-edges", edge->getID())) {
            edge->getFromNode()->removeOutgoing(edge);
            edge->getToNode()->removeIncoming(edge);
            delete edge;
            return true;
        }
    }
    // check whether the edge shall be removed due to a allow an unwished class
    if(OptionsSubSys::getOptions().isSet("remove-edges.by-type")) {
        int matching = 0;
        std::vector<SUMOVehicleClass> allowed = edge->getAllowedVehicleClasses();
        // !!! don't do this each time
        StringTokenizer st(OptionsSubSys::getOptions().getString("remove-edges.by-type"), ";");
        while(st.hasNext()) {
            SUMOVehicleClass vclass = getVehicleClassID(st.next());
            std::vector<SUMOVehicleClass>::iterator i =
                find(allowed.begin(), allowed.end(), vclass);
            if(i!=allowed.end()) {
                allowed.erase(i);
            }
        }
        // remove the edge if all allowed
        if(allowed.size()!=0) {
            edge->getFromNode()->removeOutgoing(edge);
            edge->getToNode()->removeIncoming(edge);
            delete edge;
            return true;
        }
    }
    _edges.insert(EdgeCont::value_type(edge->getID(), edge));
    return true;
}


NBEdge *
NBEdgeCont::retrieve(const string &id) const
{
    EdgeCont::const_iterator i = _edges.find(id);
    if(i==_edges.end()) return 0;
    return (*i).second;
}


bool
NBEdgeCont::computeTurningDirections()
{
    for(EdgeCont::iterator i=_edges.begin(); i!=_edges.end(); i++) {
        (*i).second->computeTurningDirections();
    }
    return true;
}


bool
NBEdgeCont::sortOutgoingLanesConnections()
{
    for(EdgeCont::iterator i=_edges.begin(); i!=_edges.end(); i++) {
        (*i).second->sortOutgoingLanesConnections();
    }
    return true;
}


bool
NBEdgeCont::computeEdge2Edges()
{
    for(EdgeCont::iterator i=_edges.begin(); i!=_edges.end(); i++) {
        (*i).second->computeEdge2Edges();
    }
    return true;
}



bool
NBEdgeCont::computeLanes2Edges()
{
    for(EdgeCont::iterator i=_edges.begin(); i!=_edges.end(); i++) {
        (*i).second->computeLanes2Edges();
    }
    return true;
}



bool
NBEdgeCont::recheckLanes()
{
    for(EdgeCont::iterator i=_edges.begin(); i!=_edges.end(); i++) {
        (*i).second->recheckLanes();
    }
    return true;
}


/*
bool
NBEdgeCont::computeLinkPriorities(bool verbose)
{
    for(EdgeCont::iterator i=_edges.begin(); i!=_edges.end(); i++) {
        (*i).second->computeLinkPriorities();
    }
    return true;
}
*/

bool
NBEdgeCont::appendTurnarounds()
{
    for(EdgeCont::iterator i=_edges.begin(); i!=_edges.end(); i++) {
        (*i).second->appendTurnaround();
    }
    return true;
}


void
NBEdgeCont::writeXMLEdgeList(ostream &into, std::vector<std::string> toAdd)
{
    into << "   <edges no=\"" << (_edges.size()+toAdd.size()) << "\">";
    for(vector<string>::iterator j=toAdd.begin(); j!=toAdd.end(); j++) {
        if(j!=toAdd.begin()) {
            into << ' ';
        }
        into << (*j);
    }
    if(toAdd.size()!=0) {
        into << ' ';
    }

    for(EdgeCont::iterator i=_edges.begin(); i!=_edges.end(); i++) {
        if(i!=_edges.begin()) {
            into << ' ';
        }
        into << (*i).first;
    }
    into << "</edges>" << endl;
}


void
NBEdgeCont::writeXMLStep1(std::ostream &into)
{
    for(EdgeCont::iterator i=_edges.begin(); i!=_edges.end(); i++) {
        (*i).second->writeXMLStep1(into);
    }
    into << endl;
}


void
NBEdgeCont::writeXMLStep2(std::ostream &into)
{
    for(EdgeCont::iterator i=_edges.begin(); i!=_edges.end(); i++) {
        (*i).second->writeXMLStep2(into);
    }
    into << endl;
}

int NBEdgeCont::size()
{
    return _edges.size();
}


int
NBEdgeCont::getNo()
{
    return _edges.size();
}


void
NBEdgeCont::clear()
{
    for(EdgeCont::iterator i=_edges.begin(); i!=_edges.end(); i++)
        delete((*i).second);
    _edges.clear();
}


void
NBEdgeCont::report()
{
    WRITE_MESSAGE("   " + toString<int>(getNo()) + " edges loaded.");
    if(EdgesSplit>0) {
        WRITE_WARNING("The split of edges was performed "+ toString<int>(EdgesSplit) + " times.");
    }
}


bool
NBEdgeCont::splitAt(NBDistrictCont &dc, NBEdge *edge, NBNode *node)
{
    return splitAt(dc, edge, node,
        edge->getID() + "[0]", edge->getID() + "[1]",
        edge->_nolanes, edge->_nolanes);
}


bool
NBEdgeCont::splitAt(NBDistrictCont &dc, NBEdge *edge, NBNode *node,
                    const std::string &firstEdgeName,
                    const std::string &secondEdgeName,
                    size_t noLanesFirstEdge, size_t noLanesSecondEdge)
{
    SUMOReal pos;
    pos = edge->getGeometry().nearest_position_on_line_to_point(node->getPosition());
    if(pos<=0) {
        pos = GeomHelper::nearest_position_on_line_to_point(
            edge->_from->getPosition(), edge->_to->getPosition(),
            node->getPosition());
    }
    if(pos<=0) {
        return false;
    }
    /*
    if(pos>edge->getGeometry().length()) {
        pos = edge->getGeometry().length()-10; // !!!! bla!!!
    }
    */
    return splitAt(dc, edge, pos, node, firstEdgeName, secondEdgeName,
        noLanesFirstEdge, noLanesSecondEdge);
        //!!! does not regard the real edge geometry
}

bool
NBEdgeCont::splitAt(NBDistrictCont &dc,
                    NBEdge *edge, SUMOReal pos, NBNode *node,
                    const std::string &firstEdgeName,
                    const std::string &secondEdgeName,
                    size_t noLanesFirstEdge, size_t noLanesSecondEdge)
{
    // build the new edges' geometries
    std::pair<Position2DVector, Position2DVector> geoms =
        edge->getGeometry().splitAt(pos);
    if(geoms.first[-1]!=node->getPosition()) {
        geoms.first.pop_back();
        geoms.first.push_back(node->getPosition());
    }

    if(geoms.second[0]!=node->getPosition()) {
        geoms.second.pop_front();
        geoms.second.push_front(node->getPosition());
    }
#ifdef _DEBUG
#ifdef CHECK_UNIQUE_POINTS_GEOMETRY
    if(!geoms.first.assertNonEqual()) {
        DEBUG_OUT << "first: " << edge->getID() << endl;
        DEBUG_OUT << geoms.first << endl;
        DEBUG_OUT << geoms.second << endl;
    }
    if(!geoms.second.assertNonEqual()) {
        DEBUG_OUT << "second: " << edge->getID() << endl;
        DEBUG_OUT << geoms.first << endl;
        DEBUG_OUT << geoms.second << endl;
    }
#endif
#endif
    // build and insert the edges
    NBEdge *one = new NBEdge(firstEdgeName, firstEdgeName,
        edge->_from, node, edge->_type, edge->_speed, noLanesFirstEdge,
        pos, edge->getPriority(), geoms.first, edge->myLaneSpreadFunction,
        edge->_basicType);
    size_t i;
    for(i=0; i<noLanesFirstEdge&&i<edge->getNoLanes(); i++) {
        one->setLaneSpeed(i, edge->getLaneSpeed(i));
    }
    NBEdge *two = new NBEdge(secondEdgeName, secondEdgeName,
        node, edge->_to, edge->_type, edge->_speed, noLanesSecondEdge,
        edge->_length-pos, edge->getPriority(), geoms.second,
        edge->myLaneSpreadFunction, edge->_basicType);
    for(i=0; i<noLanesSecondEdge&&i<edge->getNoLanes(); i++) {
        two->setLaneSpeed(i, edge->getLaneSpeed(i));
    }
    two->copyConnectionsFrom(edge);
    // replace information about this edge within the nodes
    edge->_from->replaceOutgoing(edge, one, 0);
    edge->_to->replaceIncoming(edge, two, 0);
    // the edge is now occuring twice in both nodes...
    //  clean up
    edge->_from->removeDoubleEdges();
    edge->_to->removeDoubleEdges();
    // add connections from the first to the second edge
    size_t noLanes = one->getNoLanes();
    for(i=0; i<one->getNoLanes()&&i<two->getNoLanes(); i++) {
        if(!one->addLane2LaneConnection(i, two, i, false)) {// !!! Bresenham, here!!!
            MsgHandler::getErrorInstance()->inform("Could not set connection!");
            throw ProcessError();
        }
    }
    // erase the splitted edge
    erase(dc, edge);
    insert(one);
    insert(two);
    EdgesSplit++;
    return true;
}






void
NBEdgeCont::erase(NBDistrictCont &dc, NBEdge *edge)
{
    _edges.erase(edge->getID());
    edge->_from->removeOutgoing(edge);
    edge->_to->removeIncoming(edge);
    dc.removeFromSinksAndSources(edge);
    delete edge;
}


NBEdge *
NBEdgeCont::retrievePossiblySplitted(const std::string &id,
                                     const std::string &hint,
                                     bool incoming) const
{
    // try to retrieve using the given name (iterative)
    NBEdge *edge = retrieve(id);
    if(edge!=0) {
        return edge;
    }
    // now, we did not find it; we have to look over all possibilities
    EdgeVector hints;
        // check whether at least the hint was not splitted
    NBEdge *hintedge = retrieve(hint);
    if(hintedge==0) {
        hints = getGeneratedFrom(hint);
    } else {
        hints.push_back(hintedge);
    }
    EdgeVector candidates = getGeneratedFrom(id);
    for(EdgeVector::iterator i=hints.begin(); i!=hints.end(); i++) {
        NBEdge *hintedge = (*i);
        for(EdgeVector::iterator j=candidates.begin(); j!=candidates.end(); j++) {
            NBEdge *poss_searched = (*j);
            NBNode *node = incoming
                ? poss_searched->_to : poss_searched->_from;
            const EdgeVector &cont = incoming
                ? node->getOutgoingEdges() : node->getIncomingEdges();
            if(find(cont.begin(), cont.end(), hintedge)!=cont.end()) {
                return poss_searched;
            }
        }
    }
    return 0;
}


EdgeVector
NBEdgeCont::getGeneratedFrom(const std::string &id) const
{
    size_t len = id.length();
    EdgeVector ret;
    for(EdgeCont::const_iterator i=_edges.begin(); i!=_edges.end(); i++) {
        string curr = (*i).first;
        // the next check makes it possibly faster - we don not have
        //  to compare the names
        if(curr.length()<=len) {
            continue;
        }
        // the name must be the same as the given id but something
        //  beginning with a '[' must be appended to it
        if(curr.substr(0, len)==id&&curr[len]=='[') {
            ret.push_back((*i).second);
            continue;
        }
        // ok, maybe the edge is a compound made during joining of edges
        size_t pos = curr.find(id);
            // surely not
        if(pos==string::npos) {
            continue;
        }
            // check leading char
        if(pos>0) {
            if(curr[pos-1]!=']'&&curr[pos-1]!='+') {
                // actually, this is another id
                continue;
            }
        }
        if(pos+id.length()<curr.length()) {
            if(curr[pos+id.length()]!='['&&curr[pos+id.length()]!='+') {
                // actually, this is another id
                continue;
            }
        }
        ret.push_back((*i).second);
    }
    return ret;
}

std::vector<std::string>
NBEdgeCont::buildPossibilities(const std::vector<std::string> &s)
{
    std::vector<std::string> ret;
    for(std::vector<std::string>::const_iterator i=s.begin(); i!=s.end(); i++) {
        ret.push_back((*i) + "[0]");
        ret.push_back((*i) + "[1]");
    }
    return ret;
}



void
NBEdgeCont::joinSameNodeConnectingEdges(NBDistrictCont &dc,
                                        NBTrafficLightLogicCont &tlc,
                                        EdgeVector edges)
{
    // !!! Attention!
    //  No merging of the geometry to come is being done
    //  The connections are moved from one edge to another within
    //   the replacement where the edge is a node's incoming edge.

    // count the number of lanes, the speed and the id
    size_t nolanes = 0;
    SUMOReal speed = 0;
    int priority = 0;
    string id;
    NBEdge::EdgeBasicFunction function = NBEdge::EDGEFUNCTION_UNKNOWN;
    sort(edges.begin(), edges.end(), NBContHelper::same_connection_edge_sorter());
    // retrieve the connected nodes
    NBEdge *tpledge = *(edges.begin());
    NBNode *from = tpledge->getFromNode();
    NBNode *to = tpledge->getToNode();
    EdgeVector::const_iterator i;
    for(i=edges.begin(); i!=edges.end(); i++) {
        // some assertions
        assert((*i)->getFromNode()==from);
        assert((*i)->getToNode()==to);
        // ad the number of lanes the current edge has
        nolanes += (*i)->getNoLanes();
        // build the id
        if(i!=edges.begin()) {
            id += "+";
        }
        id += (*i)->getID();
        // build the edge type
        if(function==NBEdge::EDGEFUNCTION_UNKNOWN) {
            function = (*i)->getBasicType();
        } else {
            if(function!=NBEdge::EDGEFUNCTION_NORMAL) {
                if(function!=(*i)->getBasicType()) {
                    function = NBEdge::EDGEFUNCTION_NORMAL;
                }
            }
        }
        // compute the speed
        speed += (*i)->getSpeed();
        // build the priority
        if(priority<(*i)->getPriority()) {
            priority = (*i)->getPriority();
        }
        // remove all connections to the joined edges
/*
        for(EdgeVector::const_iterator j=edges.begin(); j!=edges.end(); j++) {
            (*i)->removeFromConnections(*j);
        }
        */
    }
    speed /= edges.size();
    // build the new edge
    NBEdge *newEdge = new NBEdge(id, id, from, to, "", speed,
        nolanes, -1, priority, tpledge->myLaneSpreadFunction, function);
    insert(newEdge);
/*    // sort edges as lanes
    sort(edges.begin(), edges.end(),
        NBContHelper::edge_to_lane_sorter(from, to));*/
    // replace old edge by current within the nodes
    //  and delete the old
    from->replaceOutgoing(edges, newEdge);
    to->replaceIncoming(edges, newEdge);
    // patch connections
    //  add edge2edge-information
    for(i=edges.begin(); i!=edges.end(); i++) {
        EdgeVector ev = (*i)->getConnected();
        for(EdgeVector::iterator j=ev.begin(); j!=ev.end(); j++) {
            newEdge->addEdge2EdgeConnection(*j);
        }
    }
    //  move lane2lane-connections
    size_t currLane = 0;
    for(i=edges.begin(); i!=edges.end(); i++) {
        newEdge->moveOutgoingConnectionsFrom(*i, currLane, false);
        currLane += (*i)->getNoLanes();
    }
    // patch tl-information
    currLane = 0;
    for(i=edges.begin(); i!=edges.end(); i++) {
        size_t noLanes = (*i)->getNoLanes();
        for(size_t j=0; j<noLanes; j++, currLane++) {
            // replace in traffic lights
            tlc.replaceRemoved(*i, j, newEdge, currLane);
        }
    }
    // delete joined edges
    for(i=edges.begin(); i!=edges.end(); i++) {
        erase(dc, *i);
    }
}


NBEdge *
NBEdgeCont::retrievePossiblySplitted(const std::string &id, SUMOReal pos) const
{
    // check whether the edge was not split, yet
    NBEdge *edge = retrieve(id);
    if(edge!=0) {
        return edge;
    }
    // find the part of the edge which matches the position
    SUMOReal seen = 0;
    std::vector<string> names;
    names.push_back(id + "[1]");
    names.push_back(id + "[0]");
    while(true) {
        // retrieve the first subelement (to follow)
        string cid = names[names.size()-1];
        names.pop_back();
        edge = retrieve(cid);
        // The edge was splitted; check its subparts within the
        //  next step
        if(edge==0) {
            names.push_back(cid + "[1]");
            names.push_back(cid + "[0]");
        }
        // an edge with the name was found,
        //  check whether the position lies within it
        else {
            seen += edge->getLength();
            if(seen>=pos) {
                return edge;
            }
        }
    }
    return 0; //!!!
}


void
NBEdgeCont::search(NBEdge *e)
{
    for(EdgeCont::iterator i=_edges.begin(); i!=_edges.end(); i++) {
        DEBUG_OUT << (*i).second << ", " << (*i).second->getID() << endl;
        if((*i).second==e) {
            int checkdummy = 0;
            checkdummy += 2;
        }
    }
    DEBUG_OUT << "--------------------------------" << endl;
}


bool
NBEdgeCont::normaliseEdgePositions(const NBNodeCont &nc)
{
    for(EdgeCont::iterator i=_edges.begin(); i!=_edges.end(); i++) {
        (*i).second->normalisePosition(nc);
    }
    return true;
}


bool
NBEdgeCont::reshiftEdgePositions(SUMOReal xoff, SUMOReal yoff, SUMOReal rot)
{
    for(EdgeCont::iterator i=_edges.begin(); i!=_edges.end(); i++) {
        (*i).second->reshiftPosition(xoff, yoff, rot);
    }
    return true;
}


bool
NBEdgeCont::computeEdgeShapes()
{
    for(EdgeCont::iterator i=_edges.begin(); i!=_edges.end(); i++) {
        (*i).second->computeEdgeShape();
    }
    return true;
}


std::vector<std::string>
NBEdgeCont::getAllNames()
{
    std::vector<std::string> ret;
    for(EdgeCont::iterator i=_edges.begin(); i!=_edges.end(); ++i) {
        ret.push_back((*i).first);
    }
    return ret;
}


bool
NBEdgeCont::savePlain(const std::string &file)
{
    // try to build the output file
    ofstream res(file.c_str());
    if(!res.good()) {
        MsgHandler::getErrorInstance()->inform("Plain edge file '" + file + "' could not be opened.");
        return false;
    }
    std::fixed(res);
    res << "<edges>" << endl;
    for(EdgeCont::iterator i=_edges.begin(); i!=_edges.end(); i++) {
        NBEdge *e = (*i).second;
        res << std::setprecision( 2 );
        res << "   <edge id=\"" << e->getID()
            << "\" fromnode=\"" << e->getFromNode()->getID()
            << "\" tonode=\"" << e->getToNode()->getID()
            << "\" nolanes=\"" << e->getNoLanes()
            << "\" speed=\"" << e->getSpeed() << "\"";
        // write the geometry only if larger than just the from/to positions
        if(e->getGeometry().size()>2) {
            res << std::setprecision( 10 );
            res << " shape=\"" << e->getGeometry() << "\"";
        }
        // write the spread type if not default ("right")
        if(e->getLaneSpreadFunction()!=NBEdge::LANESPREAD_RIGHT) {
            res << " spread_type=\"center\"";
        }
        // write the function if not "normal"
        if(e->getBasicType()!=NBEdge::EDGEFUNCTION_NORMAL) {
            switch(e->getBasicType()) {
            case NBEdge::EDGEFUNCTION_SOURCE:
                res << " function=\"source\"";
                break;
            case NBEdge::EDGEFUNCTION_SINK:
                res << " function=\"sink\"";
                break;
            default:
                // hmmm - do nothing? seems to be invalid anyhow
                break;
            }
        }
        // write the vehicles class if restrictions exist
        if(!e->hasRestrictions()) {
            res << "/>" << endl;
        } else {
            res << ">" << endl;
            e->writeLanesPlain(res);
            res << "   </edge>" << endl;
        }
    }
    res << "</edges>" << endl;
    return res.good();
}


bool
NBEdgeCont::removeUnwishedEdges(NBDistrictCont &dc, OptionsCont &oc)
{
    //
    std::vector<NBEdge*> toRemove;
    for(EdgeCont::iterator i=_edges.begin(); i!=_edges.end(); ) {
        NBEdge *edge = (*i).second;
        if(!OptionsSubSys::helper_CSVOptionMatches("keep-edges", edge->getID())) {
            edge->getFromNode()->removeOutgoing(edge);
            edge->getToNode()->removeIncoming(edge);
	        toRemove.push_back(edge);
        }
        ++i;
    }
    for(std::vector<NBEdge*>::iterator j=toRemove.begin(); j!=toRemove.end(); ++j) {
        erase(dc, *j);
    }
    return true;
}


bool
NBEdgeCont::recomputeLaneShapes()
{
    for(EdgeCont::iterator i=_edges.begin(); i!=_edges.end(); ++i) {
        (*i).second->computeLaneShapes();
    }
    return true;
}


bool
NBEdgeCont::splitGeometry(NBNodeCont &nc)
{
    for(EdgeCont::iterator i=_edges.begin(); i!=_edges.end(); ++i) {
        if((*i).second->getGeometry().size()<3) {
            continue;
        }
        (*i).second->splitGeometry(*this, nc);
    }
    return true;
}


void
NBEdgeCont::recheckLaneSpread()
{
    for(EdgeCont::iterator i=_edges.begin(); i!=_edges.end(); ++i) {
        string oppositeID;
        if((*i).first[0]=='-') {
            oppositeID = (*i).first.substr(1);
        } else {
            oppositeID = "-" + (*i).first;
        }
        if(_edges.find(oppositeID)!=_edges.end()) {
            (*i).second->setLaneSpreadFunction(NBEdge::LANESPREAD_RIGHT);
            _edges.find(oppositeID)->second->setLaneSpreadFunction(NBEdge::LANESPREAD_RIGHT);
        } else {
            (*i).second->setLaneSpreadFunction(NBEdge::LANESPREAD_CENTER);
        }
    }
}


void
NBEdgeCont::recheckEdgeGeomsForDoublePositions()
{
    for(EdgeCont::iterator i=_edges.begin(); i!=_edges.end(); ++i) {
        (*i).second->recheckEdgeGeomForDoublePositions();
    }
}

/**************** DO NOT DEFINE ANYTHING AFTER THE INCLUDE *****************/

// Local Variables:
// mode:C++
// End:



