// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
// Adapted by Basile Pesin

#include "view/AnalogClock.hpp"

#include <QtWidgets>
#include <iostream>

#include "view/AnalogClock.hpp"

AnalogClock::AnalogClock(QWidget *parent) : QWidget(parent) {
  resize(150, 150);
}

QSize AnalogClock::sizeHint() const { return QSize(151, 151); }

void AnalogClock::update(std::chrono::seconds dt) {  ClockedController::update(dt); QWidget::update(); }

void AnalogClock::paintEvent(QPaintEvent *) {
  static const QPoint hourHand[3] = {QPoint(7, 8), QPoint(-7, 8),
                                     QPoint(0, -40)};
  static const QPoint minuteHand[3] = {QPoint(7, 8), QPoint(-7, 8),
                                       QPoint(0, -70)};

  QColor hourColor(127, 0, 127);
  QColor minuteColor(0, 127, 127, 191);

  int side = qMin(width(), height());
  int hours = getMinutes().count() / 60;
  int minutes = getMinutes().count() % 60;

  QPainter painter(this);
  painter.setBrush(Qt::white);
  painter.drawEllipse(QRectF(0, 0, 150, 150));

  painter.setRenderHint(QPainter::Antialiasing);
  painter.translate(width() / 2, height() / 2);
  painter.scale(side / 200.0, side / 200.0);

  painter.setPen(Qt::NoPen);
  painter.setBrush(hourColor);

  painter.save();
  painter.rotate(30.0 * ((hours + minutes / 60.0)));
  painter.drawConvexPolygon(hourHand, 3);
  painter.restore();

  painter.setPen(hourColor);

  for (int i = 0; i < 12; ++i) {
    painter.drawLine(88, 0, 96, 0);
    painter.rotate(30.0);
  }

  painter.setPen(Qt::NoPen);
  painter.setBrush(minuteColor);

  painter.save();
  painter.rotate(6.0 * minutes);
  painter.drawConvexPolygon(minuteHand, 3);
  painter.restore();

  painter.setPen(minuteColor);

  for (int j = 0; j < 60; ++j) {
    if ((j % 5) != 0)
      painter.drawLine(92, 0, 96, 0);
    painter.rotate(6.0);
  }
}
