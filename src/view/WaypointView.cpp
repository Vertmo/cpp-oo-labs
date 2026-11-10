#include <iostream>

#include "qnamespace.h"

#include "view/WaypointView.hpp"
#include "view/FloorScene.hpp"
#include "view/WaypointEdgeView.hpp"

WaypointView::WaypointView(Waypoint &wp, FloorScene &scene)
    : QGraphicsEllipseItem(), wp(wp), floorNb(scene.getFloorNb()) {
  wp.subscribe(this);
  updatePositions();

  // FIXME After Lab 5
  // setBrush((wp.getDisplayColor()));
  setPen(QColor(0, 0, 0, 100));

  // Arrows
  for (Waypoint *wp2 : wp.getSuccessors()) {
      if(wp2->isOnFloor(floorNb)) {
        WaypointEdgeView *wpe = new WaypointEdgeView(&wp, wp2, this);
        wpe->updatePositions();
      }
  }
}

WaypointView::~WaypointView() { wp.unsubscribe(this); }

Waypoint &WaypointView::getWaypoint() const { return wp; };

void WaypointView::updatePositions() {
  const Vector2 &pos1 = wp.getPosition();
  double rad1 = WP_RADIUS;

  prepareGeometryChange();

  // FIXME After Lab 1
  // Vector2 wp1(pos1.x - WORLD_LEFT, WORLD_TOP - pos1.y);
  // setRect(wp1.x - rad1, wp1.y - rad1, WP_RADIUS * 2, WP_RADIUS * 2);
}

void WaypointView::highlight() {
    setPen(QColor(255, 255, 0, 255));
}

void WaypointView::unhighlight() {
    setPen(QColor(0, 0, 0, 100));
}

void WaypointView::notifyPositionChanged(const Vector2 &) { updatePositions(); }
void WaypointView::notifyRadiusChanged(double) { updatePositions(); }

void WaypointView::notifyOutgoingEdgeAdded(Waypoint &other) {
    if(other.isOnFloor(floorNb)) {
      WaypointEdgeView *wpe =
          new WaypointEdgeView(&getWaypoint(), &other, this);
      wpe->updatePositions();
    }      
}

void WaypointView::notifyDeleted() {
    scene()->removeItem(this);
}

void WaypointView::notifySelected() { highlight(); }
void WaypointView::notifyUnselected() { unhighlight(); }

