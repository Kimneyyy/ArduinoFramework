#include <Arduino.h>
#include "arduinoMain.h"

void ArduinoMain::step()
{
    // hier koennen Timer registered werden
    for(int i = 0; i < timers.size(); i++) {
        timers[i]->step(); // Call the step method of each timer
    }
}

int ArduinoMain::registerTimer(int interval, std::function<void()> callback)
{
    int numberOfTimers = timers.size(); // Get the current number of timers


    Timer* timer = new Timer(numberOfTimers, interval, callback); // Create a new Timer object
    timers.push_back(timer); // Add the new timer to the vector

    // hier koennen Timer registered werden
    return numberOfTimers; // Dummy return value for now
}

void ArduinoMain::startTimer(int timerID)
{
    if (timerID < timers.size()) {
        timers[timerID]->start(); // Start the specified timer
    }
}
void ArduinoMain::stopTimer(int timerID)
{
    if (timerID < timers.size()) {
        timers[timerID]->stop(); // Stop the specified timer
    }
}
void ArduinoMain::removeTimer(int timerID)
{
    if (timerID < timers.size()) {
        delete timers[timerID]; // Delete the timer object
        timers.erase(timers.begin() + timerID); // Remove the timer from the vector
    }
}