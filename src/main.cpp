#include "OBSTACLE_DETECTION_HPP.hpp"
#include "wrap-hwlib.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    namespace target = hwlib::target;

    target::pin_in pressurePin = target::pin_in(target::pins::d2);
    target::pin_in distanceTrigPin = target::pin_in(target::pins::d11);
    target::pin_in distanceEchoPin = target::pin_in(target::pins::d10);

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
