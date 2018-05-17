/**
 * @file
 * @brief     Obstacle Detection for pressure and distance sensors
 * @author    Joost van Lingen
 * @license   MIT
 */

#include "OBSTACLE_DETECTION_HPP.hpp"
#include "wrap-hwlib.hpp"

ObstacleDetection::ObstacleDetection(const hwlib::target::pin_in &pressureSensorPin,
                                     const hwlib::target::pin_in &distanceSensorTrigPin,
                                     const hwlib::target::pin_in &distanceSensorEchoPin)
    : pressureSensorPin(pressureSensorPin), distanceSensorTrigPin(distanceSensorTrigPin),
      distanceSensorEchoPin(distanceSensorEchoPin) {
}

bool ObstacleDetection::getPressureState() {
    return pressureState;
}

int ObstacleDetection::getDistanceState() {
    return distanceState;
}

void ObstacleDetection::setDestanceWarningValue(int distance) {
    distanceWarningValue = distance;
}

bool ObstacleDetection::getWarningState() {
    return warningState;
}