#include <chrono>
#include <iostream>
#include <cmath>

#include <QApplication>
#include <QMainWindow>
#include <QTimer>
#include <QBoxLayout>

#include "controller/FlightController.hpp"
#include "controller/WaypointController.hpp"
// #include "controller/WaypointEditionController.hpp"

#include "model/waypoints/WalkingWaypoint.hpp"

#include "view/AnalogClock.hpp"
#include "view/FloorComboBox.hpp"
#include "view/WaypointsCheckBox.hpp"
#include "view/AirportView.hpp"

#include "controller/AirportController.hpp"

void test_vector2() {
  // TODO  
}

void test_passenger() {
  // TODO  
}

int main(int argc, char *argv[]) {
  std::cout << "Vector2 tests" << std::endl;
  test_vector2();

  std::cout << "Passenger tests" << std::endl;
  test_passenger();

  std::cout << "Test application" << std::endl;

  QApplication app(argc, argv);

  QMainWindow window;

  WaypointController wpController(3);

  // Graphics View
  AirportView view(wpController.getScenes()[0], &window);

  // Menu
  QWidget menu(&window);
  QVBoxLayout layout(&menu);
  AnalogClock clock(&menu);
  layout.addWidget(&clock);
  QSlider speedSlider(Qt::Horizontal, &menu);
  speedSlider.setTickInterval(1);
  layout.addWidget(&speedSlider);
  FloorComboBox floorBox(&menu, view, wpController.getScenes());
  layout.addWidget(&floorBox);
  WaypointsCheckBox waypointsBox(&menu, wpController.getScenes());
  layout.addWidget(&waypointsBox);
  menu.adjustSize();

  // Test loop
  QTimer timer(&window);
  timer.start(10);
  AirportController aController(wpController);
  FlightController fController(wpController);
  timer.callOnTimeout([&aController, &fController, &clock, &speedSlider]() {
    std::chrono::seconds dt(speedSlider.value() ? int(std::pow(1.05, speedSlider.value())) : 0);
    clock.update(dt);
    aController.update(dt);
    fController.update(dt);
  });

  window.setCentralWidget(&view);
  window.show();

  // FIXME passenger test
  // std::string entranceName = "Door 1";
  // Waypoint *entrance = wpController.findEntrance(entranceName);
  // std::string exitName = "Departure Gate A37";
  // Waypoint *exit = wpController.findExit(exitName);
  // aController.addPassenger(*entrance, *exit);

  return app.exec();
}
