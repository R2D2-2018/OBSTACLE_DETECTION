#include "obstacle_detection.hpp"
#include "wrap-hwlib.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    auto pressurePin = hwlib::target::pin_in(hwlib::target::pins::d12);
    auto distanceTrigPin = hwlib::target::pin_out(hwlib::target::pins::d11);
    auto distanceEchoPin = hwlib::target::pin_in(hwlib::target::pins::d10);

    ObstacleDetection obstacleDetector(pressurePin, distanceTrigPin, distanceEchoPin);

    obstacleDetector.setDistanceWarningValue(50);

    while (1) {
        hwlib::wait_ms(1000);
        hwlib::cout << "Pressure state:" << obstacleDetector.getPressureState();
        hwlib::cout << " - Distance state:" << obstacleDetector.getDistanceState();
        hwlib::cout << " - Warning state:" << obstacleDetector.getWarningState();
        hwlib::cout << '\n';
    }

    return 0;
}