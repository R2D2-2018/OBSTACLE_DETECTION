#include "obstacle_detection.hpp"
#include "wrap-hwlib.hpp"

ObstacleDetection::ObstacleDetection(hwlib::pin_in &pressureSensorPin, hwlib::pin_out &distanceSensorTrigPin,
                                     hwlib::pin_in &distanceSensorEchoPin)
    : pressureSensorPin(pressureSensorPin), distanceSensorTrigPin(distanceSensorTrigPin),
      distanceSensorEchoPin(distanceSensorEchoPin) {
}

void ObstacleDetection::update() {
    pressureState = pressureSensorPin.get();
}

bool ObstacleDetection::getPressureState() {
    update();
    return pressureState;
}

int ObstacleDetection::getDistanceState() {
    update();
    return distanceState;
}

void ObstacleDetection::setDistanceWarningValue(int distance) {
    distanceWarningValue = distance;
}

bool ObstacleDetection::getWarningState() {
    return warningState;
}