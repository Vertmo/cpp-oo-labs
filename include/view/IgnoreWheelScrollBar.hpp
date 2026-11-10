#ifndef IGNOREWHEELSCROLLBAR_H_H
#define IGNOREWHEELSCROLLBAR_H_H

#include <QScrollBar>

class IgnoreWheelScrollBar : public QScrollBar {
protected:
  void wheelEvent(QWheelEvent *event) override;
};

#endif
