/**
 * @file sensor_interface.cpp
 * @brief    Sensor Interface functionality
 * @author   Joost van Lingen
 * @license  See LICENSE
 */

#include "sensor_interface.hpp"
#include "wrap-hwlib.hpp"

SensorInterface::SensorInterface(hwlib::pin_in &pressureSensorPin, hwlib::pin_out &distanceSensorTrigPin,
                                 hwlib::pin_in &distanceSensorEchoPin)
    : pressureSensorPin(pressureSensorPin), distanceSensorTrigPin(distanceSensorTrigPin),
      distanceSensorEchoPin(distanceSensorEchoPin) {
}

int SensorInterface::filterSensorData(int data[5]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    return data[2];
}

void SensorInterface::updatePressureState() {
    pressureState = pressureSensorPin.get();
}

void SensorInterface::updateDistanceState() {
    int data[5];
    uint16_t timeout = 30000;
    for (int i = 0; i < 5; i++) {
        distanceSensorTrigPin.set(0);
        hwlib::wait_us(2);
        distanceSensorTrigPin.set(1);
        hwlib::wait_us(10);
        distanceSensorTrigPin.set(0);
        data[i] = hwlib::now_us();
        while (!distanceSensorEchoPin.get() && (hwlib::now_us() - data[i]) < timeout) {
        }
        data[i] = hwlib::now_us();
        while (distanceSensorEchoPin.get() && (hwlib::now_us() - data[i]) < timeout) {
        }
        data[i] = (hwlib::now_us() - data[i]) * 0.034 / 2;
    }
    distanceState = filterSensorData(data);
}

void SensorInterface::updateWarningState() {
    updatePressureState();
    updateDistanceState();
    warningState = pressureState || (distanceState <= distanceWarningValue && distanceState != 0);
}

bool SensorInterface::getPressureState() {
    updatePressureState();
    return pressureState;
}

int SensorInterface::getDistanceState() {
    updateDistanceState();
    return distanceState;
}

void SensorInterface::setDistanceWarningValue(const int &distance) {
    distanceWarningValue = distance;
}

bool SensorInterface::getWarningState() {
    updateWarningState();
    return warningState;
}