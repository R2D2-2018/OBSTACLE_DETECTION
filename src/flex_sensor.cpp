#include "flex_sensor.hpp"

/**
 * @file      flex_sensor.cpp
 * @brief     CPP file for the class flex_sensor which will contain functions to control the flex pressure sensor
 * @author    Wouter Dijksta
 * @date      13-6-2018
 * @license   MIT
 */

FlexSensor::FlexSensor(hwlib::target::pin_adc &analog_pin) : analog_pin(analog_pin) {
    threshold = 0;
    resting_value = 0;
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
    this->reset();
    this->calibrated = true;
    hwlib::cout << "[Calibrating....]" << hwlib::endl;

    for (int i = 0; i < 10; i++) {
        int val = read();
        this->calibrationValues += val;
        hwlib::cout << "............" << val << hwlib::endl;
        hwlib::wait_ms(100);
    }
    hwlib::cout << "Average....." << (this->calibrationValues / 10) << hwlib::endl;
    hwlib::cout << hwlib::endl;

    this->resting_value = this->calibrationValues / 10;
}

void FlexSensor::reset() {
    this->calibrated = false;
    this->calibrationValues = 0;
    this->resting_value = 0;
}