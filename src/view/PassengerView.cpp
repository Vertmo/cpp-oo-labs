#include <iostream>

#include <QSvgRenderer>
#include "qhashfunctions.h"

#include "view/PassengerView.hpp"
#include "controller/AirportController.hpp"

#define PASSENGER_SVG_SIZE 10

QSvgRenderer PassengerView::sharedPassengerRenderer = QSvgRenderer(QLatin1String("res/passenger.svg"));

PassengerView::PassengerView(Passenger &pass, AirportController &controller)
    : pass(pass), controller(controller) {
  setSharedRenderer(&sharedPassengerRenderer);
  setScale(.01);
  colorizeEffect.setStrength(1);
  colorizeEffect.setColor(Qt::black);
  setGraphicsEffect(&colorizeEffect);
  // TODO Lab 6
}

void PassengerView::setPosition(const Vector2 &pos) {
  setPos(pos.x - WORLD_LEFT - PASSENGER_SVG_SIZE / 2,
         WORLD_TOP - pos.y - PASSENGER_SVG_SIZE / 2);
}

void PassengerView::setFloor(int floor) {
  // Change floor, if necessary
  if (currScene != controller.getScenes()[floor]) {
    if (currScene)
      currScene->removeItem(this);
    if (floor >= 0 && (unsigned int)floor < controller.getScenes().size()) {
      currScene = controller.getScenes()[floor];
      currScene->addItem(this);
    }
  }
}

void PassengerView::highlight() {
  colorizeEffect.setColor(Qt::yellow);
}

void PassengerView::unhighlight() {
  colorizeEffect.setColor(Qt::black);
}

void PassengerView::mousePressEvent(QGraphicsSceneMouseEvent *) {
  controller.unselectAllPassengers();
  // TODO Lab 6
}
