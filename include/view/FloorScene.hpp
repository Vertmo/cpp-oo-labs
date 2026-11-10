#ifndef FLOORSCENE_H_
#define FLOORSCENE_H_

#include <QGraphicsScene>
#include <QGraphicsItemGroup>

#include "model/waypoints/Waypoint.hpp"

#include "view/WaypointView.hpp"

#define WORLD_LEFT 286000
// #define WORLD_RIGHT 289000
#define WORLD_TOP 6277000
// #define WORLD_BOTTOM 6274000

class FloorScene : public QGraphicsScene {
protected:
  int floorNb;
  std::vector<WaypointView *> waypoints;
  bool waypointsShown;

public:
  FloorScene(int floorNb);
  int getFloorNb() const;
  virtual void addWaypoint(Waypoint &wp);
  void showWaypoints();
  void hideWaypoints();

private:
  void loadBuildings(const QJsonDocument & doc);
  void loadZones(const QJsonDocument & doc);
  void loadStructures(const QJsonDocument & doc);

protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // FLOORSCENE_H_
