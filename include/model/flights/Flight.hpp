#ifndef FLIGHT_H_
#define FLIGHT_H_

#include "model/Terminal.hpp"

class Flight {
public:  
  const int flightNumber;
  const Terminal terminal;

public:
  Flight(int flightNumber, Terminal terminal);

  /**
   * Determines whether or not the plane is currently in terminal.
   * Methods that make the plane enter the terminal should first assign
   * a gate (DepartureGate or ArrivalGate) to the plane
   **/
  virtual bool isInTerminal() = 0;
  virtual void leaveTerminal() = 0;
};

#endif
