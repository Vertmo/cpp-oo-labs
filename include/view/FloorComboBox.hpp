#ifndef FLOORCOMBOBOX_H_
#define FLOORCOMBOBOX_H_

#include <vector>
#include <QComboBox>
#include "view/FloorScene.hpp"

class FloorComboBox : public QComboBox {
private:
  QGraphicsView &controlledView;
  const std::vector<FloorScene *> &scenes;
  void currentIndexChanged(int idx);

public:
  FloorComboBox(QWidget *parent, QGraphicsView &controlledView,
                const std::vector<FloorScene *> &scenes);
  ~FloorComboBox();
};

#endif // FLOORCOMBOBOX_H_
