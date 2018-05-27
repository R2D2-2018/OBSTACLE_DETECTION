#include "obstacle_detection.hpp"
#include "wrap-hwlib.hpp"

ObstacleDetection::ObstacleDetection(hwlib::pin_in &pressureSensorPin, hwlib::pin_out &distanceSensorTrigPin,
                                     hwlib::pin_in &distanceSensorEchoPin)
    : pressureSensorPin(pressureSensorPin), distanceSensorTrigPin(distanceSensorTrigPin),
      distanceSensorEchoPin(distanceSensorEchoPin) {
}

void ObstacleDetection::update() {
    pressureState = pressureSensorPin.get();
    uint_fast64_t counter[5];
    for (int i = 0; i < 5; i++) {
        distanceSensorTrigPin.set(0);
        hwlib::wait_us(2);
        distanceSensorTrigPin.set(1);
        hwlib::wait_us(10);
        distanceSensorTrigPin.set(0);
        while (!distanceSensorEchoPin.get()) {
        }
        counter[i] = hwlib::now_us();
        while (distanceSensorEchoPin.get()) {
        }
        counter[i] = (hwlib::now_us() - counter[i]) * 0.034 / 2;
    }
    for (int h = 0; h < 4; h++) {
        for (int i = 0; i < 4; i++) {
            if (counter[i] > counter[i + 1]) {
                int temp = counter[i];
                counter[i] = counter[i + 1];
                counter[i + 1] = temp;
            }
        }
    }
    distanceState = counter[2];
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