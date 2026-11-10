#ifndef WAYPOINT_VIEW_
#define WAYPOINT_VIEW_

#include <QGraphicsItem>

#include "model/waypoints/Waypoint.hpp"
#include "model/waypoints/WaypointChangeObserver.hpp"
#include "qgraphicsitem.h"
#include "view/WaypointEdgeView.hpp"

#define WP_RADIUS 5

class FloorScene;

class WaypointView : public QGraphicsEllipseItem, public WaypointChangeObserver {
protected:
  Waypoint &wp;
  int floorNb;

public:
  WaypointView(Waypoint &wp, FloorScene &scene);
  ~WaypointView();
  Waypoint &getWaypoint() const;

private:
  void updatePositions();

  void highlight();
  void unhighlight();

  void notifyPositionChanged(const Vector2 &newPosition) override;
  void notifyRadiusChanged(double newRadius) override;
  void notifyOutgoingEdgeAdded(Waypoint &other) override;
  void notifyDeleted() override;
  void notifySelected() override;
  void notifyUnselected() override;
};

#endif
