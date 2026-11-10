#include <iostream>

#include "qcoreapplication.h"
#include "qgraphicsview.h"

#include "view/AirportView.hpp"
#include "view/IgnoreWheelScrollBar.hpp"

AirportView::AirportView(FloorScene *defaultScene, QWidget *parent)
    : QGraphicsView(defaultScene, parent) {
  setVerticalScrollBar(new IgnoreWheelScrollBar());
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setDragMode(QGraphicsView::ScrollHandDrag);
}

void AirportView::wheelEvent(QWheelEvent *event) {
  QGraphicsView::wheelEvent(event);
  if (!event->isAccepted()) {
    if (event->angleDelta().y() > 0)
      scale(1.25, 1.25);
    else
      scale(0.8, 0.8);
  }
}
