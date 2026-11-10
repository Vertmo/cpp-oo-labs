#ifndef WAYPOINT_CONTROLLER_H_
#define WAYPOINT_CONTROLLER_H_

#include "model/Terminal.hpp"
#include "model/waypoints/ArrivalGate.hpp"
#include "model/waypoints/DepartureGate.hpp"
#include "model/waypoints/Waypoint.hpp"
#include "view/FloorScene.hpp"

class WaypointController {
protected:
  std::vector<Waypoint *> waypoints;
  std::vector<DepartureGate *> departureGates;
  std::vector<ArrivalGate *> arrivalGates;
  std::vector<FloorScene *> scenes;
  const std::string filename = "data/waypoints.txt";

public:
  WaypointController(int nbfloors);
  const std::vector<FloorScene *> &getScenes();

  /* Return the first free departure/arrival gate for the given terminal
   * May return NULL if there is none */
  // DepartureGate *findFreeDepartureGate(Terminal term);
  // ArrivalGate *findFreeArrivalGate(Terminal term);

  void addDepartureGate(DepartureGate *wp);
  void addArrivalGate(ArrivalGate *wp);
  void addWaypoint(Waypoint *wp);

  void addEdge(WaypointView *wp);
  void load();
  void save();

  /* Find an entrance with given name. May return NULL if not found */
  Waypoint *findEntrance(std::string &name);
  /* Find an exit with given name. May return NULL if not found */
  Waypoint *findExit(std::string &name);

protected:
   WaypointController();
};

#endif
