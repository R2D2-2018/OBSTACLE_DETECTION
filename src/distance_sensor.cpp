#include "distance_sensor.hpp"

/**
 * @file      distance_sensor.cpp
 * @brief     CPP file for the class DistanceSensor which will contain functions to control a distance sensor sensor
 * @author    Wouter Dijksta
 * @date      26-6-2018
 * @license   MIT
 */

DistanceSensor::DistanceSensor(hwlib::pin_in &echo_pin, hwlib::pin_out &trigger_pin)
    : echo_pin(echo_pin), trigger_pin(trigger_pin) {
}

// Note: This should eventually use the `Distance` module instead of having it's own implementation.
int DistanceSensor::getDistance() {
    trigger_pin.set(0);
    hwlib::wait_ms(2);
    trigger_pin.set(1);
    hwlib::wait_ms(10);
    trigger_pin.set(0);

    // Receive pulse
    bool received = echo_pin.get();

    // Get current time
    int duration = (int)hwlib::now_us();

    while (!received) {
        received = echo_pin.get();
    }
    while (received) {
        received = echo_pin.get();
    }

    // Calculate distance
    duration = (int)((hwlib::now_us() - duration) - 400);
    int distance = (int)((duration / 2) / 29.1);

    // Return distance, when it exceeds it's maximum range; it returns 400.
    return distance < 400 ? distance : 400;
}