#ifndef AIRPORT_H_
#define AIRPORT_H_

#include <QObject>

#include "controller/ClockedController.hpp"
// #include "model/Passenger.hpp"
#include "view/PassengerView.hpp"
#include "controller/WaypointController.hpp"

// Main controller class
class AirportController : public ClockedController {
private:
  // Model
  // std::vector<Passenger> passengers;
  // Views
  // TODO Lab 4
  // Controller
  WaypointController &wpController;

public:
  AirportController(WaypointController &wpController);
  ~AirportController();

  const std::vector<FloorScene *> &getScenes();

  void addPassenger(Waypoint &origin, Waypoint &destination);

  void update(std::chrono::seconds dt) override;

  void unselectAllPassengers();
};

#endif // AIRPORT_H_
