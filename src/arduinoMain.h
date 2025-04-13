#ifndef ArduinoMain_h_
#define ArduinoMain_h_
//#include <Arduino.h>
#include "timer.h"
#include "vector"
#include <functional>


class ArduinoMain {

private:
    // beliebige Anzahl von Timer durch liste
    std::vector<Timer*> timers; // Vector to hold pointers to Timer objects


public:
    ArduinoMain(){    // Constructor to initialize the ArduinoMain object
    };

    void step();

    void Arduino_setup();
    void Arduino_loop();

    int registerTimer(int interval, std::function<void()> callback);
    void startTimer(int timerID);
    void stopTimer(int timerID);
    void removeTimer(int timerID);
};

#endif