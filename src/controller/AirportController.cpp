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
  for (Passenger &p : passengers)
    p.move(Vector2((float)(rand()%3-1)/10*dt.count(), (float)(rand()%3-1)/10*dt.count()));
}

void AirportController::unselectAllPassengers() {
  for (Passenger &p : passengers)
    p.unselect();
}

AirportController::~AirportController() {
    // TODO Lab 4
}
