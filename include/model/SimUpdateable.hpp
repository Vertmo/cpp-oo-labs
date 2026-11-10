#ifndef SIMUPDATEABLE_H_
#define SIMUPDATEABLE_H_

#include <chrono>

/** This is an interface */
class SimUpdateable {
public:
  /** Apply simulation update with a dt step (in ms) */
  virtual void update(std::chrono::seconds dt) = 0;
};

#endif
