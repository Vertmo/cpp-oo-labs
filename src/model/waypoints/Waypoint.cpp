#include <algorithm>
#include <iostream>

#include "model/waypoints/Waypoint.hpp"
#include "model/waypoints/WaypointChangeObserver.hpp"

int Waypoint::id_cpt = 0;

Waypoint::Waypoint(const Vector2 &position)
    : position(position) {
  id = id_cpt++;
}

Waypoint::~Waypoint() {
  auto it = observers;
  for (WaypointChangeObserver *obs : it)
    obs->notifyDeleted();
}

int Waypoint::getId() const { return id; }

const Vector2 &Waypoint::getPosition() const { return position; }

void Waypoint::setPosition(const Vector2 &pos) {
  position = pos;
  // FIXME After Lab 6
  // for (WaypointChangeObserver *wp : observers)
  //   wp->notifyPositionChanged(Vector2(position.x, position.y));
};

bool Waypoint::isOnFloor(int floor) const {
    std::vector<int> floors = getFloors();
    return find(floors.begin(), floors.end(), floor) != floors.end();
}

bool Waypoint::isSelected() const { return selected; }

void Waypoint::select() {
  selected = true;
  for (WaypointChangeObserver *wpc : observers)
    wpc->notifySelected();
}

void Waypoint::unselect() {
  selected = false;
  for (WaypointChangeObserver *wpc : observers)
    wpc->notifyUnselected();
}

void Waypoint::subscribe(WaypointChangeObserver *observer) {
  observers.push_back(observer);
}

void Waypoint::unsubscribe(WaypointChangeObserver *obs) {
  auto it = find(observers.begin(), observers.end(), obs);
  if (it != observers.end())
    observers.erase(it);
}

bool Waypoint::hasSuccessor(Waypoint *wp) {
  for (Waypoint *wp2 : getSuccessors()) {
    if (wp2 == wp)
      return true;
  }
  return false;
}

