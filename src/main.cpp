#include "sensor_interface.hpp"
#include "wrap-hwlib.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;
    auto pressurePin = hwlib::target::pin_in(hwlib::target::pins::d7);
    auto distanceTrigPin = hwlib::target::pin_out(hwlib::target::pins::d6);
    auto distanceEchoPin = hwlib::target::pin_in(hwlib::target::pins::d5);

    SensorInterface obstacleDetector(pressurePin, distanceTrigPin, distanceEchoPin);

    obstacleDetector.setDistanceWarningValue(20);

    while (true) {
        hwlib::cout << obstacleDetector.getWarningState();
    }

    return 0;
}