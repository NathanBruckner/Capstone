#ifndef __POT__
#define __POT__
class potentiometer {
public:
  potentiometer();
  ~potentiometer();

  double readVoltage();
  double inputVoltage();

  void setReadVoltage(double read);
  void setInputVoltage(double in);

private:
  double readVoltage_;
  double inputVoltage_;
};

#endif
