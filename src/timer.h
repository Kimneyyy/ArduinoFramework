#ifndef Timer_h_
#define Timer_h_

class Timer {
private:
    int timerID; // Unique identifier for the timer
    int interval; // Timer interval in milliseconds
    std::function<void()> callback; // Callback function to be executed when the timer expires

    bool isRunning; // Flag to indicate if the timer is running

    // startZeit in Millis
    unsigned long startTime; // Start time in milliseconds

public:
    Timer(int timerID, int interval, std::function<void()> callback);
    void step(); // Method to execute the timer step
    void start(); // Method to start the timer
    void stop(); // Method to stop the timer
};

#endif