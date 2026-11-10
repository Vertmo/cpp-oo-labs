#ifndef WAYPOINTCHANGEOBSERVER_H_
#define WAYPOINTCHANGEOBSERVER_H_

// #include "model/Vector2.hpp"

class Vector2;
class Waypoint;

class WaypointChangeObserver {
public:
  virtual void notifyPositionChanged(const Vector2 & newPosition) = 0;
  virtual void notifyRadiusChanged(double newRadius) = 0;
  virtual void notifyOutgoingEdgeAdded(Waypoint &other) = 0;
  virtual void notifyDeleted() = 0;
  virtual void notifySelected() = 0;
  virtual void notifyUnselected() = 0;
};

#endif // WAYPOINTCHANGEOBSERVER_H_
