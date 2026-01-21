#include "potentiometer.h"

potentiometer::potentiometer() {};
potentiometer::~potentiometer() {};

double potentiometer::readVoltage() { return readVoltage_; }
double potentiometer::inputVoltage() { return inputVoltage_; }

void potentiometer::setReadVoltage(double read) { readVoltage_ = read; }
void potentiometer::setInputVoltage(double in) { inputVoltage_ = in; }
