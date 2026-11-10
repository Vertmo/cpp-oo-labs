// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
// Adapted by Basile Pesin

#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include "controller/ClockedController.hpp"
#include <QWidget>

class AnalogClock : public QWidget, public ClockedController {
public:
  AnalogClock(QWidget *parent = nullptr);
  void update(std::chrono::seconds dt) override;

protected:
  void paintEvent(QPaintEvent *event) override;
  QSize sizeHint() const override;
};

#endif
