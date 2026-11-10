#include <iostream>

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QGraphicsSceneMouseEvent>

#include "utils.hpp"
#include "view/FloorScene.hpp"
#include "view/WaypointView.hpp"

FloorScene::FloorScene(int floorNb) : floorNb(floorNb) {
  loadBuildings(loadJson("data/buildings.json"));
  loadZones(loadJson("data/floor" + std::to_string(floorNb) + "/zonePOI.json"));
  loadStructures(loadJson("data/floor" + std::to_string(floorNb) + "/structurePOI.json"));
  waypointsShown = false;
}

QPointF toScreenPoint(const QJsonValue & point) {
  double worldX = point[0].toDouble();
  double worldY = point[1].toDouble();

  double screenX = worldX - WORLD_LEFT;
  double screenY = WORLD_TOP - worldY;

  return QPointF(screenX, screenY);
}

void FloorScene::loadBuildings(const QJsonDocument & doc) {
  QPen pen;
  QBrush brush(Qt::darkGray, Qt::SolidPattern);

  const QJsonArray & features = doc.object()["features"].toArray();

  for(const QJsonValue & o : features) {
    const QString & mapName = o["attributes"]["MAPNAME"].toString();
    if(mapName == "2ABCD" || mapName == "2EFG") {
      const QJsonArray & rings = o["geometry"]["rings"].toArray();
      for(const QJsonValue & ring : rings) {
        QPolygonF polygon;
        for(const QJsonValue & point : ring.toArray()) {
          polygon << toScreenPoint(point);
        }
        addPolygon(polygon, pen, brush);
      }
    }
  }
}

void FloorScene::loadZones(const QJsonDocument & doc) {
  QPen pen;
  QBrush brush(Qt::white, Qt::SolidPattern);

  const QJsonArray & features = doc.object()["features"].toArray();

  for(const QJsonValue & o : features) {
    const QJsonArray & rings = o["geometry"]["rings"].toArray();
    for(const QJsonValue & ring : rings) {
      QPolygonF polygon;
      for(const QJsonValue & point : ring.toArray()) {
        polygon << toScreenPoint(point);
      }
      addPolygon(polygon, pen, brush);
    }
  }
}

void FloorScene::loadStructures(const QJsonDocument & doc) {
  QPen pen;

  const QJsonArray & features = doc.object()["features"].toArray();

  for(const QJsonValue & o : features) {
    QBrush brush(Qt::lightGray, Qt::SolidPattern);

    QString color = o["attributes"]["BGCOLOR"].toString();

    if (color == "16428745") { // Shop
      brush.setColor(Qt::red);
    } else if (color == "15626538") { // Service
      brush.setColor(Qt::blue);
    } else if (color == "15132160") { // Elevator
      brush.setColor(Qt::yellow);
    } else if (color == "8046915") { // Restaurant
      brush.setColor(Qt::green);
    }

    const QJsonArray & rings = o["geometry"]["rings"].toArray();
    for(const QJsonValue & ring : rings) {
      QPolygonF polygon;
      
      for(const QJsonValue & point : ring.toArray()) {
        polygon << toScreenPoint(point);
      }
      addPolygon(polygon, pen, brush);
    }
  }
}

int FloorScene::getFloorNb() const { return floorNb; }

void FloorScene::addWaypoint(Waypoint &wp) {
  WaypointView *el = new WaypointView(wp, *this);
  waypoints.push_back(el);
  addItem(el);
  if (!waypointsShown)
    el->hide();
}

void FloorScene::showWaypoints() {
  waypointsShown = true;
  for (WaypointView *wp : waypoints)
    wp->show();
}

void FloorScene::hideWaypoints() {
  waypointsShown = false;
  for (WaypointView *wp : waypoints)
    wp->hide();
}

void FloorScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  QGraphicsScene::mousePressEvent(event);
}
