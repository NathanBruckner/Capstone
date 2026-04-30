#include <LiquidCrystal.h>

// Pin definitions based on your original code
const int rs = 10;
const int en = 8;
const int d0 = 7;
const int d1 = 6;
const int d2 = 5;
const int d3 = 4;
const int d4 = 3;
const int d5 = 2;
const int d6 = 22;
const int d7 = 23;

// Initialize the LCD with the 8-bit interface used in your snippet
LiquidCrystal lcd(rs, en, d0, d1, d2, d3, d4, d5, d6, d7);

void setup() {
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  // Clear any existing text and print "hello"
  lcd.clear();
  lcd.print("hello");
}

void loop() {
  // Nothing to do here!
}