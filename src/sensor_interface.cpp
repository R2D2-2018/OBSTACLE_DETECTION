#include "sensor_interface.hpp"
#include "wrap-hwlib.hpp"

SensorInterface::SensorInterface(hwlib::pin_in &pressureSensorPin, hwlib::pin_out &distanceSensorTrigPin,
                                 hwlib::pin_in &distanceSensorEchoPin)
    : pressureSensorPin(pressureSensorPin), distanceSensorTrigPin(distanceSensorTrigPin),
      distanceSensorEchoPin(distanceSensorEchoPin) {
}

void SensorInterface::updatePressureState() {
    pressureState = pressureSensorPin.get();
}

void SensorInterface::updateDistanceState() {
    distanceState = 0;
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
    return warningState;
}