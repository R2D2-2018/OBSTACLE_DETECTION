#include "obstacle_detection.hpp"
#include "wrap-hwlib.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    auto pressurePin = hwlib::target::pin_in(hwlib::target::pins::d12);
    auto distanceTrigPin = hwlib::target::pin_out(hwlib::target::pins::d11);
    auto distanceEchoPin = hwlib::target::pin_in(hwlib::target::pins::d10);

    ObstacleDetection obstacleDetector(pressurePin, distanceTrigPin, distanceEchoPin);

    // Demo code - the important variables of the obstacle detection class are printed out on the serial bus
    while (1) {
        hwlib::wait_ms(500);
        hwlib::cout << "Pressure:" << obstacleDetector.getPressureState() << '\r' << '\n';
        hwlib::cout << "Distance: " << obstacleDetector.getDistanceState() << '\r' << '\n';
        hwlib::cout << "Warning: " << obstacleDetector.getWarningState() << '\r' << '\n';
        hwlib::cout << '\n';
    }
    return 0;
}