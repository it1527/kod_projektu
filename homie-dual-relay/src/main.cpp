
#include <Homie.h>
#include <EEPROM.h>
#include <Bounce2.h>
// sonoff

//knihovna LCD 
#include <LiquidCrystal_I2C.h>
// Construct an LCD object and pass it the 
// I2C address, width (in characters) and
// height (in characters). Depending on the
// Actual device, the IC2 address may change.
LiquidCrystal_I2C lcd(0x3F, 16, 2);
HomieNode lightNode("light", "switch");


void setup()
{
 
Serial.begin(115200);
  Serial << endl << endl;
  lcd.init();                      // initialize the lcd 
  lcd.backlight();

  // The begin call takes the width and height. This
  // Should match the number provided to the constructor.
  lcd.begin(16,2);
  lcd.init();

  // Turn on the backlight.
  lcd.backlight();

  // Move the cursor characters to the right and
  // zero characters down (line 1).
  lcd.setCursor(5, 0);

  // Print HELLO to the screen, starting at 5,0.
  lcd.print("polib,");

  // Move the cursor to the next line and print
  // WORLD.
  lcd.setCursor(5, 1);      
  lcd.print("mi zadek");
  Homie_setFirmware("awesome-relay", "1.0.0"); 
   Homie.setup();
}

 void loop(void) {
    Homie.loop();
}