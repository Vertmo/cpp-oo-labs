#include <iostream>

#include "view/FloorScene.hpp"

#include "controller/AirportController.hpp"

AirportController::AirportController(WaypointController &wpController)
    : wpController(wpController) {}

void AirportController::addPassenger(Waypoint &origin, Waypoint &destination) {
  Passenger pass(origin, destination);
  passengers.push_back(pass);

  // TODO Lab 4
}

const std::vector<FloorScene *> &AirportController::getScenes() {
  return wpController.getScenes();
}

void AirportController::update(std::chrono::seconds dt) {
  ClockedController::update(dt);
  // FIXME After Lab 6
  // for (Passenger &p : passengers)
  //   p.update(dt);
}

void AirportController::unselectAllPassengers() {
  // FIXME After Lab 6
  // for (Passenger &p : passengers)
  //   p.unselect();
}

AirportController::~AirportController() {
    // TODO Lab 4
}
