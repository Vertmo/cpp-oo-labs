#include <iostream>

#include <QPen>

#include "qgraphicsitem.h"
#include "view/FloorScene.hpp"
#include "view/WaypointEdgeView.hpp"
#include "view/WaypointView.hpp"

WaypointEdgeView::WaypointEdgeView(Waypoint *wp1, Waypoint *wp2,
                                   QGraphicsItem *parent)
    : QGraphicsItemGroup(parent), wp1(wp1), wp2(wp2) {
  wp1->subscribe(this);
  wp2->subscribe(this);

  QPen pen(QColor(0, 0, 0, 100));
  main.setPen(pen);
  tipL.setPen(pen);
  tipR.setPen(pen);

  addToGroup(&main);
  addToGroup(&tipL);
  addToGroup(&tipR);

  updatePositions();
}

WaypointEdgeView::~WaypointEdgeView() {
  wp1->unsubscribe(this);
  wp2->unsubscribe(this);
}

void WaypointEdgeView::updatePositions() {
  // FIXME After Lab 1
  // Vector2 c1(wp1->getPosition().x - WORLD_LEFT,
  //            WORLD_TOP - wp1->getPosition().y);
  // Vector2 c2(wp2->getPosition().x - WORLD_LEFT,
  //            WORLD_TOP - wp2->getPosition().y);
  // Vector2 v(c2.x - c1.x, c2.y - c1.y);
  // v.normalize();
  // Vector2 e1(c1.x + v.x * WP_RADIUS, c1.y + v.y * WP_RADIUS);
  // Vector2 e2(c2.x - v.x * WP_RADIUS, c2.y - v.y * WP_RADIUS);
  // main.setLine(e1.x, e1.y, e2.x, e2.y);
  // Vector2 t1l(e2.x - v.y - v.x, e2.y + v.x + v.y);
  // tipL.setLine(e2.x, e2.y, t1l.x, t1l.y);
  // Vector2 t1r(e2.x + v.y - v.x, e2.y - v.x - v.y);
  // tipR.setLine(e2.x, e2.y, t1r.x, t1r.y);
}

void WaypointEdgeView::highlight() {
    main.setPen(QColor(255, 255, 0, 255));
    tipL.setPen(QColor(255, 255, 0, 255));
    tipR.setPen(QColor(255, 255, 0, 255));
}

void WaypointEdgeView::unhighlight() {
    main.setPen(QColor(0, 0, 0, 100));
    tipL.setPen(QColor(0, 0, 0, 100));
    tipR.setPen(QColor(0, 0, 0, 100));
}

void WaypointEdgeView::notifyPositionChanged(const Vector2 &) { updatePositions(); }
void WaypointEdgeView::notifyRadiusChanged(double) { updatePositions(); }
void WaypointEdgeView::notifyOutgoingEdgeAdded(Waypoint &) {};

void WaypointEdgeView::notifyDeleted() {
  delete this;
}

void WaypointEdgeView::notifySelected() {
  if (wp1->isSelected() && wp2->isSelected())
    highlight();
}

void WaypointEdgeView::notifyUnselected() { unhighlight(); }

