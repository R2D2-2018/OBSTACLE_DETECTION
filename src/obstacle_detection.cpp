#include "obstacle_detection.hpp"

/**
 * @file      obstacle_detection.cpp
 * @brief     CPP file for the class ObstacleDection
 * @author    Wouter Dijksta
 * @date      17-6-2018
 * @license   MIT
 */
ObstacleDetection::ObstacleDetection(FlexSensor &flexSensor, DistanceSensor &distanceSensor)
    : flexSensor(flexSensor), distanceSensor(distanceSensor) {
    distanceThreshold = 40;
    pressureThreshold = 2400;
}

bool ObstacleDetection::getState() {
    return flexSensor.read() < pressureThreshold || distanceSensor.getDistance() < distanceThreshold;
}

void ObstacleDetection::setDistanceThreshold(int distanceThreshold) {
    this->distanceThreshold = distanceThreshold;
}

void ObstacleDetection::setPressureThreshold(int pressureThreshold) {
    this->pressureThreshold = pressureThreshold;
}

int ObstacleDetection::getDistanceThreshold() {
    return distanceThreshold;
}

int ObstacleDetection::getPressureThreshold() {
    return pressureThreshold;
}