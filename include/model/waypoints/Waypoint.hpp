#ifndef LOCATION_H_
#define LOCATION_H_

#include <vector>

#include "model/Vector2.hpp"

#include "model/waypoints/WaypointChangeObserver.hpp"
#include "qcolor.h"

/**
 * A waypoint in the terminal that passengers may go through.
 * Corresponds to a node in the graph.
 * May be extended to be a Point of Interest (POI) where an action occurs,
 **/
class Waypoint {
private:
  int id;
  static int id_cpt;
  Vector2 position;
  bool selected = false;

protected:
  std::vector<WaypointChangeObserver *> observers;

public:
  Waypoint(const Vector2 &position);
  virtual ~Waypoint();
  int getId() const;

  const Vector2 &getPosition() const;
  void setPosition(const Vector2 &pos);

  /**
   * Check if waypoint is on a given floor.
   * Most waypoints are on a singlefloor, except elevators for which this method
   * will be redefined.
   **/
  virtual std::vector<int> getFloors() const = 0;
  bool isOnFloor(int floor) const;

  bool isSelected() const;
  void select();
  void unselect();

  virtual std::vector<Waypoint *> getSuccessors() const = 0;
  bool hasSuccessor(Waypoint *wp);
  virtual void removeSuccessor(Waypoint *) = 0;
  virtual void addSucc(Waypoint *wp) = 0;
  virtual void addPred(Waypoint *wp) = 0;

  void subscribe(WaypointChangeObserver *observer);
  void unsubscribe(WaypointChangeObserver *observer);
};

#endif // LOCATION_H_
