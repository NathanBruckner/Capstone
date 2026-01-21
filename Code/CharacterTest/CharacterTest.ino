#include <VL53L4CD.h>
#include <LiquidCrystal.h>
#include <Time.h>
#include <Wire.h>
#include <vector>
#include <numeric>

const int rs = 10;
const int rw = -1;
const int en = 8;
const int d0= 7;
const int d1= 6;
const int d2= 5;
const int d3= 4;
const int d4= 3;
const int d5= 2;
const int d6= 22;
const int d7= 23;

VL53L4CD sensor;

const int sampleCount = 100;

LiquidCrystal lcd(rs, en, d0, d1, d2, d3, d4, d5, d6, d7);

std::vector<int> samples(sampleCount);
int count = 0;

void setup() {

  lcd.begin(16, 2);
  lcd.print("Init...");

  Wire.begin();

  if (!sensor.init()) {
    lcd.clear();
    lcd.print("VL53 init fail");
    while (1);
  }

  // timing budget and interval
  sensor.setRangeTiming(50, 200); // 50ms timing budget, 200ms between measurements
  sensor.startContinuous();
}

void loop() {
  if (sensor.dataReady()) {
    uint16_t dist = sensor.readRangeContinuousMillimeters(true);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Dist: ");
    

    sensor.clearInterrupt();
    samples[count]=dist;
    lcd.print(std::accumulate(samples.begin(),samples.end(),0)/sampleCount);
    lcd.print(" mm");
    count++;
    if (count==sampleCount-1)
    {
    count = 0;
    }    
  }
}
