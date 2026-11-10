#include "model/flights/ArrivalFlight.hpp"
#include "model/waypoints/ArrivalGate.hpp"

ArrivalFlight::ArrivalFlight(int flightNumber, Terminal terminal, std::chrono::minutes arrivalTime)
    : Flight(flightNumber, terminal), arrivalTime(arrivalTime) {}

void ArrivalFlight::enterTerminal(ArrivalGate *gate) {
  this->gate = gate;
  // gate->setFlightAtGate(*this);
}
bool ArrivalFlight::isInTerminal() { return gate != NULL; }

void ArrivalFlight::leaveTerminal() {
  // gate->unsetFlightAtGate();
}
