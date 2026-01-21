<center>**Example Code -> LCD**</center>

1.  Using Liquid Crystal

'#include <Wire.h>'
'#include <LiquidCrystal_I2C.h>'
'LiquidCrystal_I2C lcd(0x27, 8, 2);'

'void setup() {'
'lcd.init();'
lcd.backlight();'
'//lcd.setCursor(0, 0);'
' //lcd.print("setup");'
'}'

'void loop() {'
'lcd.setCursor(0, 0);'
'lcd.print("setup");'

'}'

1.
