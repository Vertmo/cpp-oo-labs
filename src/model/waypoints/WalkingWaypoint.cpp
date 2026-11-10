#include <iostream>
#include <algorithm>

#include "model/waypoints/WalkingWaypoint.hpp"
#include "model/waypoints/Waypoint.hpp"
#include "model/waypoints/WaypointChangeObserver.hpp"

WalkingWaypoint::WalkingWaypoint(const Vector2 &position, int floor)
    : Waypoint(position), floor(floor) {}

WalkingWaypoint::WalkingWaypoint() : Waypoint(Vector2()) {}

std::vector<int> WalkingWaypoint::getFloors() const { return { floor }; }

void WalkingWaypoint::addSucc(Waypoint *neighbour) {
  neighbours.push_back(neighbour);
  // copy to avoid problems, since notifyEdgeAdded may modify the list of observers
  auto observers1 = observers;
  for (WaypointChangeObserver *obs : observers1) {
    obs->notifyOutgoingEdgeAdded(*neighbour);
  }
}

void WalkingWaypoint::addPred(Waypoint *neighbour) {
  neighbour->addSucc(this);
}

std::vector<Waypoint *> WalkingWaypoint::getSuccessors() const { return neighbours; }

void WalkingWaypoint::removeSuccessor(Waypoint *wp) {
  auto it = find(neighbours.begin(), neighbours.end(), wp);
  if(it != neighbours.end()) neighbours.erase(it);
}

QColor WalkingWaypoint::getDisplayColor() { return QColor(200, 200, 200, 100); }
