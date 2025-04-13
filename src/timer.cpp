#include <Arduino.h>
#include "timer.h"
#include <functional>

Timer::Timer(int timerID, int interval, std::function<void()> callback)
{
    this->timerID = timerID; // Set the timer ID
    this->interval = interval; // Set the timer interval
    this->callback = callback; // Set the callback function
    this->isRunning = false; // Initialize the timer as not running
}

void Timer::step()
{
    // Check if the timer is running and if the interval has elapsed
    if (isRunning) {
        // Call the callback function
        unsigned long currentTime = millis(); // Get the current time in milliseconds
        if (currentTime - startTime >= interval) {
            callback(); // Execute the callback function
            startTime = currentTime; // Reset the start time
        }
    }
}


void Timer::start()
{
    startTime = millis(); // Set the start time to the current time
    isRunning = true; // Set the timer to running state
}

void Timer::stop()
{
    isRunning = false; // Set the timer to not running state
}