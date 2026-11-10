#include "model/flights/DepartureFlight.hpp"

DepartureFlight::DepartureFlight(int flightNumber, Terminal terminal,
                                 std::chrono::minutes departureTime)
    : Flight(flightNumber, terminal),
      boardingTime(departureTime - std::chrono::minutes(30)),
      departureTime(departureTime) {}

void DepartureFlight::enterTerminal(DepartureGate *gate) {
  this->gate = gate;
  // gate->setFlightAtGate(*this);
}

bool DepartureFlight::isInTerminal() { return gate != NULL; }

void DepartureFlight::leaveTerminal() {
  // gate->unsetFlightAtGate(); 
}
