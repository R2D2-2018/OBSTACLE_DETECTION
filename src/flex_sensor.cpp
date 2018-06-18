#include "flex_sensor.hpp"

/**
 * @file      flex_sensor.cpp
 * @brief     CPP file for the class flex_sensor which will contain functions to control the flex pressure sensor
 *            https://learn.sparkfun.com/tutorials/flex-sensor-hookup-guide
 * @author    Wouter Dijksta
 * @date      13-6-2018
 * @license   MIT
 */

FlexSensor::FlexSensor(hwlib::adc &analog_pin) : analog_pin(analog_pin) {
    restingValue = 0;
    calibrationValues = 0;
    calibrated = false;
}

int FlexSensor::read() {
    if (!this->calibrated) {
        this->calibrate();
    }

    return this->analog_pin.get();
}

void FlexSensor::calibrate() {
    this->reset();           // Reset all values to make sure we're not using values from the last calibration
    this->calibrated = true; // Calibrated is set to true here because in our calibration we use the function `read()` which will
                             // call `calibrate()` if we don't, causing an infinite loop
    read(); // The first value the sensor gives us is always inaccurate, so we dispose of it by calling the `read()` functon and not
            // storing its value

    for (int i = 0; i < 10; i++) {
        int val = read();
        this->calibrationValues += val;
    }
    this->restingValue = this->calibrationValues / 10;
}

void FlexSensor::reset() {
    this->calibrated = false;
    this->calibrationValues = 0;
    this->restingValue = 0;
}