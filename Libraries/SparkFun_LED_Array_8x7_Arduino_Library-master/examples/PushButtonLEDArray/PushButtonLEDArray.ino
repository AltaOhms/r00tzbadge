/*
 Input Pullup Serial
 Modified for r00tz badge by Pamela Cortez
 This example demonstrates the use of pinMode(INPUT_PULLUP). It reads a
 digital input on pin A4 and prints the results to the serial monitor.

 The circuit:
 * Momentary switch attached from pin A4 to ground
 * LED Array on r00tz badge

 Unlike pinMode(INPUT), there is no pull-down resistor necessary. An internal
 20K-ohm resistor is pulled to 5V. This configuration causes the input to
 read HIGH when the switch is open, and LOW when it is closed.

 created 14 March 2012
 by Scott Fitzgerald

 http://www.arduino.cc/en/Tutorial/InputPullupSerial

 This example code is in the public domain

 */

 #include <SparkFun_LED_8x7.h>
#include <Chaplex.h>

byte led_pins[] = {9, 8, 7, 6, 5, 4, 3, 2}; // Pins for LEDs
byte i;
byte x;
byte y;
byte radius;
const byte sparkfun_logo[] = { 0,0,0,0,1,0,0,0,
                               0,0,0,0,1,0,1,0,
                               0,0,1,0,1,1,1,0,
                               0,0,1,1,1,1,1,0,
                               0,0,1,1,1,1,0,0,
                               0,0,1,1,0,0,0,0,
                               0,0,1,0,0,0,0,0 };

void setup() {
  //start serial connection
  Serial.begin(9600);
    Serial.println(F("-----------------------"));
  Serial.println(F("SparkFun LED 8x7 - Demo"));
  Serial.println(F("-----------------------"));
  //configure pin2 as an input and enable the internal pull-up resistor
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(13, OUTPUT);
    // Initialize and clear display
  Plex.init(led_pins);
  Plex.clear();
  Plex.display();

}

void loop() {
  //read the pushbutton value into a variable
  int sensorVal = digitalRead(18);
  int sensorVel = digitalRead(19);
  //print out the value of the pushbutton
  Serial.println(sensorVal);
  Serial.println(sensorVel);
  // Keep in mind the pullup means the pushbutton's
  // logic is inverted. It goes HIGH when it's open,
  // and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  if (sensorVal == HIGH) {
    digitalWrite(13, LOW);
    
  } else {
      Serial.println(F("Scroll some text"));
  Plex.scrollText("rootz", 1);
  }


    if (sensorVel == HIGH) {
    digitalWrite(13, LOW);
    
  } else {
      Serial.println(F("Scroll some text"));
  Plex.scrollText("rootz", 1);
  }
}
