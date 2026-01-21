#include "gauge_type.h"

gaugeType::gaugeType(double length, std::string name) {
  gaugeLength_ = length;
  gaugeName_ = name;
}

gaugeType::~gaugeType() {};

void gaugeType::setLength(double length) { gaugeLength_ = length; }
void gaugeType::setName(std::string name) { gaugeName_ = name; }

std::string gaugeType::getName() { return gaugeName_; }
double gaugeType::getLength() { return gaugeLength_; }
