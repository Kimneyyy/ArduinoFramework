#include <Arduino.h>
#include "arduinoMain.h"

ArduinoMain* arduinoMain;

static HardwareTimer timer = HardwareTimer(TIM1);

void clk();


void setup() {
    Serial.begin(9600);
    delay(1000); // Wait for serial to initialize
    Serial.println("Starting Arduino Framework...");

    arduinoMain = new ArduinoMain(); // Create an instance of ArduinoMain

    timer.setOverflow(1000, MICROSEC_FORMAT); // Set timer to overflow every 100 microseconds
    timer.attachInterrupt(clk);
    timer.resume(); // Start the timer

    arduinoMain->Arduino_setup(); // Call the setup method of ArduinoMain
    Serial.println("Arduino setup complete.");
}

void loop() {
    // Main loop does nothing, all work is done in the timer interrupt
    // delay(1000); // Just to avoid flooding the serial outputt
}




void clk() {
    arduinoMain->step(); // Call the step method of ArduinoMain
    arduinoMain->Arduino_loop(); // Call the loop method of ArduinoMain
}