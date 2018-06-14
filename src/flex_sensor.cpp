#include "flex_sensor.hpp"

/**
 * @file      flex_sensor.cpp
 * @brief     CPP file for the class flex_sensor which will contain functions to control the flex pressure sensor
 * @author    Wouter Dijksta
 * @date      13-6-2018
 * @license   MIT
 */

FlexSensor::FlexSensor(hwlib::target::pin_in &analog_pin) : analog_pin(analog_pin) {
    threshold = 0;
    resting_value = 0;
    calibrationValues = 0;
    calibrated = false;
}

int FlexSensor::read() {
    if (!calibrated) {
        this->calibrate();
    }
    return 1;
}

void FlexSensor::calibrate() {
    calibrated = true;
    hwlib::cout << "Calibrating";

    for (int i = 0; i < 10; i++) {
        calibrationValues += read(); // Add val
        hwlib::wait_ms(100);
        hwlib::cout << ".";
    }

    hwlib::cout << hwlib::endl;

    resting_value = calibrationValues / 10;
}

void FlexSensor::reset() {
    this->calibrated = false;
    this->calibrationValues = 0;
    this->resting_value = 0;
}