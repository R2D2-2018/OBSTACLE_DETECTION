#include "obstacle_detection.hpp"
#include "wrap-hwlib.hpp"

ObstacleDetection::ObstacleDetection(hwlib::pin_in &pressureSensorPin, hwlib::pin_out &distanceSensorTrigPin,
                                     hwlib::pin_in &distanceSensorEchoPin)
    : pressureSensorPin(pressureSensorPin), distanceSensorTrigPin(distanceSensorTrigPin),
      distanceSensorEchoPin(distanceSensorEchoPin) {
}

void ObstacleDetection::update() {
    pressureState = pressureSensorPin.get();
    distanceSensorTrigPin.set(0);
    hwlib::wait_ms(10);
    distanceSensorTrigPin.set(1);
    hwlib::wait_us(15);
    distanceSensorTrigPin.set(0);
    timePassed = hwlib::now_us();
    hwlib::wait_us(10);
    while (hwlib::now_us() < timePassed + 20000) {
        if (distanceSensorEchoPin.get()) {
            break;
        }
    }
    timePassed = hwlib::now_us() - timePassed;
    hwlib::cout << (int)timePassed << hwlib::endl;
    distanceState = timePassed * 0.034 / 2;
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