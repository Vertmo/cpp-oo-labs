#ifndef CLOCKED_CONTROLLER_H_
#define CLOCKED_CONTROLLER_H_

#include "model/SimUpdateable.hpp"
#include <chrono>

// Controller that stores the time ellapsed in the simulation
class ClockedController : public SimUpdateable {
private:
  std::chrono::seconds time;

public:
  ClockedController();
  void update(std::chrono::seconds dt) override;

  // Number of minutes ellapsed since start of simulation
  std::chrono::minutes getMinutes();
};

#endif
