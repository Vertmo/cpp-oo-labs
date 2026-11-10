#include <iostream>
#include <fstream>

#include "model/waypoints/ArrivalGate.hpp"
#include "model/waypoints/DepartureGate.hpp"
// #include "model/waypoints/EntranceExit.hpp"
#include "model/waypoints/WalkingWaypoint.hpp"
// #include "model/waypoints/Elevator.hpp"
#include "controller/WaypointController.hpp"

WaypointController::WaypointController() {}

WaypointController::WaypointController(int nbfloors) {
  for (int i = 0; i < nbfloors; i++) {
    FloorScene *floor = new FloorScene(i);
    scenes.push_back(floor);
  }

  // FIXME After Lab 8
  // load();
}

const std::vector<FloorScene *> &WaypointController::getScenes() {
  return scenes;
}

void WaypointController::addWaypoint(Waypoint *wp) {
  waypoints.push_back(wp);
  for (size_t i = 0; i < scenes.size(); i++) {
    if (wp->isOnFloor(i))
      scenes[i]->addWaypoint(*wp);
  }
}

void WaypointController::addArrivalGate(ArrivalGate *wp) {
  // addWaypoint(wp);
  arrivalGates.push_back(wp);
}

void WaypointController::addDepartureGate(DepartureGate *wp) {
  // addWaypoint(wp);
  departureGates.push_back(wp);
}

void WaypointController::load() {
  std::cout << "Loading waypoints from " + filename << std::endl;
  std::ifstream ifs;
  ifs.open(filename, std::ofstream::in);
  char c;
  while (ifs.get(c)) {
    switch (c) {
    // FIXME After Lab 8
    // case 'W': {
    //   WalkingWaypoint *wp = new WalkingWaypoint();
    //   ifs >> *wp;
    //   addWaypoint(wp);
    //   continue;
    // }
    // case 'A': {
    //   ArrivalGate *wp = new ArrivalGate();
    //   ifs >> *wp;
    //   addArrivalGate(wp);
    //   continue;
    // }
    // case 'D': {
    //   DepartureGate *wp = new DepartureGate();
    //   ifs >> *wp;
    //   addDepartureGate(wp);
    //   continue;
    // }
    // case 'E': {
    //   EntranceExit *wp = new EntranceExit();
    //   ifs >> *wp;
    //   addWaypoint(wp);
    //   continue;
    // }
    // case 'V': {
    //   Elevator *wp = new Elevator();
    //   ifs >> *wp;
    //   addWaypoint(wp);
    //   continue;
    // }
    case '>': {
      int src, dest;
      ifs >> src >> dest;
      Waypoint *wpSrc = NULL, *wpDest = NULL;
      for (Waypoint *wp : waypoints) {
        if (wp->getId() == src)
          wpSrc = wp;
        if (wp->getId() == dest)
          wpDest = wp;
      }
      if (!wpSrc || !wpDest)
          std::cout << "Could not find waypoint " << wpSrc << " or " << wpDest;
      else
        wpSrc->addSucc(wpDest);
      continue;
    }
    case ' ':
    case '\n':
      continue;
    default:
      std::cout << "Could not read " << c << " (" << (int)c << ")" << std::endl;
    }
  }
  ifs.close();
}

Waypoint *WaypointController::findEntrance(std::string &name) {
  for (Waypoint *wp : waypoints) {
    if (wp->isEntrance(name))
      return wp;
  }
  return NULL;  
}

Waypoint *WaypointController::findExit(std::string &name) {
   for (Waypoint *wp : waypoints) {
    if (wp->isExit(name))
      return wp;
  }
  return NULL;  
}

// DepartureGate *WaypointController::findFreeDepartureGate(Terminal term) {
//   for (DepartureGate *gate : departureGates) {
//     if (gate->getTerminal() == term && gate->isFree())
//       return gate;
//   }
//   return NULL;
// }

// ArrivalGate *WaypointController::findFreeArrivalGate(Terminal term) {
//   for (ArrivalGate *gate : arrivalGates) {
//     if (gate->getTerminal() == term && gate->isFree())
//       return gate;
//   }
//   return NULL;
// }
