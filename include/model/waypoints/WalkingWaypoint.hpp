#ifndef WALKINGWAYPOINT_H_
#define WALKINGWAYPOINT_H_

#include <vector>

#include "model/waypoints/Waypoint.hpp"

class WalkingWaypoint : public Waypoint {
private:
  int floor;
  std::vector<Waypoint *> neighbours;

public:
  WalkingWaypoint(const Vector2 &position, int floor);
  WalkingWaypoint();

  std::vector<int> getFloors() const override;

  void removeSuccessor(Waypoint *wp) override;
  void addSucc(Waypoint *neighbour) override;
  void addPred(Waypoint *neighbour) override;
  std::vector<Waypoint *> getSuccessors() const override;
  QColor getDisplayColor() override;
};

#endif
