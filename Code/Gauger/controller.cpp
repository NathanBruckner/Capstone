#include "controller.h"
#include "debug.h"
#include <math.h>
Controller::Controller() {
  mode_ = AUTO;
  gaugeIndex_ = 0;
  lastValue_ = 0;
  currentValue_ = 0;
  direction_ = STABLE;
  triggered_ = false;
  timingActive_ = false;
  startTime_ = 0;
  movementAccum_ = 0;
  triggerFlag_ = false;
}

void Controller::setMode(Mode m) { mode_ = m; }
Controller::Mode Controller::getMode() { return mode_; }
void Controller::nextGauge() {
  DBG_PRINT("next gauge triggered");
  gaugeIndex_++;
  if (gaugeIndex_ >= NUM_GAUGES) {
    DBG_PRINT("gauge index exceeds limits");
    gaugeIndex_ = NUM_GAUGES - 1;
  }
}
void Controller::prevGauge() {
  DBG_PRINT("previous gauge triggered");
  gaugeIndex_--;
  if (gaugeIndex_ < 0) {
    gaugeIndex_ = 0;
    DBG_PRINT("gauge index is lower than limits");
  }
}
float Controller::getGauge() { return gauges_[gaugeIndex_]; }

float Controller::getDisplayValue() {
  if (direction_ == EXPANDING)
    return currentValue_ - offset_expand_;
  else if (direction_ == CONTRACTING)
    return currentValue_ - offset_contract_;
  else
    return currentValue_;
}

void Controller::updateDirection(float delta) {
  if (delta > directionEps_)
    direction_ = EXPANDING;
  else if (delta < -directionEps_)
    direction_ = CONTRACTING;
  // if direction doesn't change, the last direction will be kept
}

float Controller::computeTarget() {
  float base = gauges_[gaugeIndex_];
  if (direction_ == EXPANDING)
    return base + offset_expand_;
  else if (direction_ == CONTRACTING)
    return base + offset_contract_;
  else
    return base;
}

Controller::Direction Controller::getDirection() { return direction_; }

void Controller::update(float value) {
  triggerFlag_ = false;
  currentValue_ = value;
  history[index] = currentValue_;
  int oldIndex = (index + 1) % N;
  float delta = currentValue_ - history[oldIndex];
  index = (index + 1) % N;
  updateDirection(delta);

  DBG_PRINTLN(delta);
  float target = computeTarget();
  float error = currentValue_ - target;

  // this is where most of the trigger logic is found
  if (mode_ == AUTO) {
    if (!triggered_ && fabs(error) <= tolerance_) {
      triggerFlag_ = true;
      triggered_ = true;
    }

    // hysterisis reset
    if (triggered_ && fabs(error) > tolerance_ * releaseFactor_) {
      triggered_ = false;
    }

    // timer auto shutoff logic
    if (direction_ == EXPANDING && !timingActive_) {
      timingActive_ = true;
      startTime_ = millis();
      movementAccum_ = 0;
    }

    if (fabs(delta) > movementEps_) {
      movementAccum_ += fabs(delta);
    }

    if (timingActive_ && millis() - startTime_ >= waitTime_) {
      float avgRate = movementAccum_ / waitTime_;
      if (avgRate > movementEps_) {
        triggerFlag_ = true;
      }
      timingActive_ = false;
    }
  }
  lastValue_ = currentValue_;
}

bool Controller::shouldTrigger() {
  if (triggerFlag_) {
    triggerFlag_ = false;
    return true;
  }
  return false;
}

float Controller::getTarget() { return computeTarget(); }
