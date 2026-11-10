#include <iostream>

#include <QGraphicsView>
#include <QEvent>

#include "view/FloorComboBox.hpp"

FloorComboBox::FloorComboBox(QWidget *parent, QGraphicsView &controlledView,
                             const std::vector<FloorScene *> &scenes)
    : QComboBox(parent), controlledView(controlledView), scenes(scenes) {
  for (long unsigned int i = 0; i < scenes.size(); i++) {
    addItem("Floor " + QString::number(i));
  }
  // Connect parent signal to child signal
  connect((QComboBox*)this, QOverload<int>::of(&QComboBox::currentIndexChanged),
          this, &FloorComboBox::currentIndexChanged);
};

FloorComboBox::~FloorComboBox() {
  // Nothing to do
}

void FloorComboBox::currentIndexChanged(int idx) {
  controlledView.setScene(scenes[idx]);
}

