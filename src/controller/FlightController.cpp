#include <iostream>
#include <sstream>

#include <QJsonArray>
#include <QJsonValue>

#include "controller/WaypointController.hpp"
#include "model/Terminal.hpp"
#include "model/flights/ArrivalFlight.hpp"
#include "model/flights/DepartureFlight.hpp"
// #include "model/waypoints/ArrivalGate.hpp"
// #include "model/waypoints/DepartureGate.hpp"
#include "utils.hpp"
#include "controller/FlightController.hpp"

std::chrono::minutes readTime(std::string s) {
  std::istringstream ss(s);
  int hours, minutes;
  char sep;
  ss >> hours >> sep >> minutes;
  return std::chrono::hours(hours) + std::chrono::minutes(minutes);
}

FlightController::FlightController(WaypointController &wpController)
    : wpController(wpController) {
  QJsonDocument arrivalsDoc = loadJson("data/arrivals.json");
  for (const QJsonValue &flight : arrivalsDoc.array()) {
    int flightNumber = flight["flightNumber"].toString().toInt();
    std::string sTerminal = flight["arrivalTerminal"].toString().toStdString();
    Terminal terminal = parseTerminal(sTerminal);
    std::chrono::minutes time =
        readTime(flight["arrivalScheduledTime"].toString().toStdString());
    if (terminal) {
      arrivals.push_back(ArrivalFlight(flightNumber, terminal, time));
    }
  }
  QJsonDocument departuresDoc = loadJson("data/departures.json");
  for (const QJsonValue &flight : departuresDoc.array()) {
    int flightNumber = flight["flightNumber"].toString().toInt();
    std::string sTerminal = flight["departureTerminal"].toString().toStdString();
    Terminal terminal = parseTerminal(sTerminal);
    std::chrono::minutes time =
        readTime(flight["departureScheduledTime"].toString().toStdString());
    if (terminal) {
      departures.push_back(DepartureFlight(flightNumber, terminal, time));
    }
  }
};

void FlightController::update(std::chrono::seconds dt) {
  ClockedController::update(dt);
  // TODO update flights
  for (ArrivalFlight &fl : arrivals) {
    if (!fl.isInTerminal() && getMinutes() >= fl.arrivalTime) {
      // ArrivalGate *g = wpController.findFreeArrivalGate(fl.terminal);
      // if (g) {
      //   std::cout << "Assigning " << " to " << g->getName() << std::endl;
      //   fl.enterTerminal(g);
      // } else {
      //   std::cerr << "Warning: could not assign arrival gate to "
      //             << " in terminal " << printTerminal(fl.terminal) << std::endl;
      // }
    } else if (fl.isInTerminal() && getMinutes() >= fl.arrivalTime + std::chrono::minutes(30)) {
        fl.leaveTerminal();
    }
  }

  for (DepartureFlight &fl : departures) {
    if (!fl.isInTerminal() && getMinutes() >= fl.boardingTime) {
      // DepartureGate *g = wpController.findFreeDepartureGate(fl.terminal);
      // if (g) {
      //   std::cout << "Assigning " << " to " << g->getName() << std::endl;
      //   fl.enterTerminal(g);
      // } else {
      //   std::cerr << "Warning: could not assign departure gate to " << " in terminal "
      //             << printTerminal(fl.terminal) << std::endl;
      // }
    } else if (fl.isInTerminal() && getMinutes() >= fl.departureTime) {
      fl.leaveTerminal();
    }
  }
}
