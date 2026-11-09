#ifndef PASSENGERVIEW_H_
#define PASSENGERVIEW_H_

#include <QGraphicsEllipseItem>
#include <QGraphicsSvgItem>
#include <QGraphicsColorizeEffect>

#include "model/Passenger.hpp"

#include "qsvgrenderer.h"
#include "view/FloorScene.hpp"

class AirportController;

class PassengerView : public QGraphicsSvgItem {
private:
  Passenger &pass;
  AirportController &controller;
  FloorScene *currScene = NULL;

  static QSvgRenderer sharedPassengerRenderer;
  QGraphicsColorizeEffect colorizeEffect;

public:
  PassengerView(Passenger &pass, AirportController &controller);

  void highlight();
  void unhighlight();

private:
  void setPosition(const Vector2 &pos);
  void setFloor(int floor);

protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // PASSENGERVIEW_H_
