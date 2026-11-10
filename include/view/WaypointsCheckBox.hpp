#ifndef WAYPOINTSCHECKBOX_H_
#define WAYPOINTSCHECKBOX_H_

#include <vector>
#include <QCheckBox>
#include "view/FloorScene.hpp"

class WaypointsCheckBox : public QCheckBox {
private:
  const std::vector<FloorScene *> &scenes;
  void stateChanged(int state);

public:
  WaypointsCheckBox(QWidget *parent, const std::vector<FloorScene *> &scenes);
  ~WaypointsCheckBox();
};

#endif // WAYPOINTSCHECKBOX_H_
