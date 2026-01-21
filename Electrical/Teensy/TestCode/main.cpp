#include "gauge_type.h"
#include "potentiometer.h"
#include <chrono>
#include <conio.h>
#include <thread>

struct Gauges {
  double g1 = 56.5;
  double g2 = 60.25;
  double g3 = 62.75;
};

double getPosition(potentiometer pot);

//
void printMenu();

int main() {
  bool pow = 0;
  gaugeType gauge;
  potentiometer pot;
  double length;
  double travel = 7; // travel length in inches
  double batVoltage; // will be a ADC signal
  char mute = 'n';
  double position;

  int mode = 0;

  while (pow != 0) {
    incrementPosition();
    position = getPosition(pot);
    printMenu();

    if (_kbhit()) {
      char key = _getch();
      if (key == 'm' || key == 'M')
        muted = !muted;
      else if (key == 72)
        targetGauge++;
      else if (key == 80)
        targetGauge--;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}

double getPosition(potentiometer p) {
  double position = travel * (p.readVoltage() / p.inputVoltage());
  return position;
}

void printMenu() {
  std::cout << std::setw(18) << gauge.getName() << std::setw(3) << "M:" << mute
            << std::endl;
  std::cout << "Position: " << std::fixed << std::setprecision(2) << position;
}
