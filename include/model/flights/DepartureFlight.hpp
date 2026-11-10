#ifndef DEPARTURE_FLIGHT_H_
#define DEPARTURE_FLIGHT_H_

#include <chrono>

#include "model/flights/Flight.hpp"

#include "model/waypoints/DepartureGate.hpp"

class DepartureFlight : public Flight {
private:
  DepartureGate *gate = NULL;

public:
  // Number of minutes after start of simulation
  const std::chrono::minutes boardingTime;
  const std::chrono::minutes departureTime;

public:
  DepartureFlight(int flightNumber, Terminal terminal,
                  std::chrono::minutes departureTime);
  bool isInTerminal() override;
  void enterTerminal(DepartureGate *gate);
  void leaveTerminal() override;
};

#endif
