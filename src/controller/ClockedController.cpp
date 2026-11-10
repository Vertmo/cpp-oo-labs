#include "controller/ClockedController.hpp"

ClockedController::ClockedController() : time(0) {}

void ClockedController::update(std::chrono::seconds dt) { time = time + dt; }

std::chrono::minutes ClockedController::getMinutes() {
  return std::chrono::minutes(time.count() / 60);
}
