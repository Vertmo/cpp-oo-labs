#ifndef ARRIVAL_FLIGHT_H_
#define ARRIVAL_FLIGHT_H_

#include <chrono>

#include "model/flights/Flight.hpp"

#include "model/waypoints/ArrivalGate.hpp"

class ArrivalFlight : public Flight {
private:
  ArrivalGate *gate = NULL;

public:  
  // Number of minutes after start of simulation
  const std::chrono::minutes arrivalTime;

public:
  ArrivalFlight(int flightNumber, Terminal terminal,
                std::chrono::minutes arrivalTime);
  bool isInTerminal() override;
  void enterTerminal(ArrivalGate *gate);
  void leaveTerminal() override;
};

#endif
