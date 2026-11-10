#include "view/WaypointsCheckBox.hpp"

WaypointsCheckBox::WaypointsCheckBox(QWidget *parent,
                                     const std::vector<FloorScene *> &scenes)
    : QCheckBox("Show waypoints", parent), scenes(scenes) {
  connect((QCheckBox *)this, QOverload<int>::of(&QCheckBox::stateChanged),
          this, &WaypointsCheckBox::stateChanged);
}

WaypointsCheckBox::~WaypointsCheckBox() {
  // Nothing to do
}

void WaypointsCheckBox::stateChanged(int state) {
  if (state > 0) {
    for (FloorScene *scene : scenes)
      scene->showWaypoints();
  } else {
    for (FloorScene *scene : scenes)
      scene->hideWaypoints();
  }
}
