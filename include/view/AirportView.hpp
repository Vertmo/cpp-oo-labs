#ifndef AIRPORTVIEW_H_
#define AIRPORTVIEW_H_

#include <QGraphicsView>
#include <QWidget>
#include <QWheelEvent>

#include "view/FloorScene.hpp"

class AirportView : public QGraphicsView {
public:
  AirportView(FloorScene *defaultScene, QWidget *parent);
protected Q_SLOTS:
  void wheelEvent(QWheelEvent *event) override;
};

#endif // AIRPORTVIEW_H_
