#include "OBSTACLE_DETECTION_HPP.hpp"
#include "wrap-hwlib.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    namespace target = hwlib::target;

    const target::pin_in &pressurePin = target::pin_in(target::pins::d12);
    const target::pin_in &distanceTrigPin = target::pin_in(target::pins::d11);
    const target::pin_in &distanceEchoPin = target::pin_in(target::pins::d10);

    ObstacleDetection obstacleDetector(pressurePin, distanceTrigPin, distanceEchoPin);

    obstacleDetector.setDestanceWarningValue(50);

    hwlib::wait_ms(1000);
    hwlib::cout << "Pressure state:" << obstacleDetector.getPressureState() << '\n';
    hwlib::cout << "Distance state:" << obstacleDetector.getDistanceState() << '\n';
    hwlib::cout << "Warning state:" << obstacleDetector.getWarningState() << '\n';

    return 0;
}
