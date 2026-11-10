#ifndef FLIGHT_CONTROLLER_H_
#define FLIGHT_CONTROLLER_H_

#include "controller/ClockedController.hpp"
#include "controller/WaypointController.hpp"
#include "model/flights/ArrivalFlight.hpp"
#include "model/flights/DepartureFlight.hpp"
#include <vector>

class FlightController : public ClockedController {
private:
  std::vector<DepartureFlight> departures;
  std::vector<ArrivalFlight> arrivals;
  WaypointController &wpController;

public:
  FlightController(WaypointController &wpController);

  void update(std::chrono::seconds dt) override;
};

#endif
