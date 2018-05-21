#include "obstacle_detection.hpp"
#include "wrap-hwlib.hpp"

ObstacleDetection::ObstacleDetection(hwlib::target::pin_in pressureSensorPin, hwlib::target::pin_in distanceSensorTrigPin,
                                     hwlib::target::pin_in distanceSensorEchoPin)
    : pressureSensorPin(pressureSensorPin), distanceSensorTrigPin(distanceSensorTrigPin),
      distanceSensorEchoPin(distanceSensorEchoPin) {
}

bool ObstacleDetection::getPressureState() {
    if (pressureSensorPin.get()) {
        pressureState = true;
    } else {
        pressureState = false;
    }
    return pressureState;
}

int ObstacleDetection::getDistanceState() {
    return distanceState;
}

void ObstacleDetection::setDistanceWarningValue(int distance) {
    distanceWarningValue = distance;
}

bool ObstacleDetection::getWarningState() {
    return warningState;
}