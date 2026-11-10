#ifndef WAYPOINTEDGEVIEW_H_
#define WAYPOINTEDGEVIEW_H_

#include <QGraphicsItem>

#include "model/waypoints/Waypoint.hpp"
#include "model/waypoints/WaypointChangeObserver.hpp"
#include "qgraphicsitem.h"

class WaypointEdgeView : public QGraphicsItemGroup, public WaypointChangeObserver {
private:
  Waypoint *wp1, *wp2;
  QGraphicsLineItem main, tipL, tipR;

public:
  WaypointEdgeView(Waypoint *wp1, Waypoint *wp2,
                   QGraphicsItem *parent);
  ~WaypointEdgeView();
  void updatePositions();

private:
  void highlight();
  void unhighlight();

protected:
  void notifyPositionChanged(const Vector2 &) override;
  void notifyRadiusChanged(double) override;
  void notifyOutgoingEdgeAdded(Waypoint &other) override;
  void notifyDeleted() override;
  void notifySelected() override;
  void notifyUnselected() override;
};

#endif
