#include "distance_sensor.hpp"
#include "flex_sensor.hpp"
#include "obstacle_detection.hpp"
#include "wrap-hwlib.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);
    hwlib::cout << "Starting..." << hwlib::endl;

    auto ad_pin = hwlib::target::pin_adc(hwlib::target::ad_pins::a0);
    FlexSensor flexSensor(ad_pin);

    auto echo_pin = hwlib::target::pin_in(hwlib::target::pins::d6);
    auto trigger_pin = hwlib::target::pin_out(hwlib::target::pins::d7);

    DistanceSensor distanceSensor(echo_pin, trigger_pin);

    ObstacleDetection obstacleDetection(flexSensor, distanceSensor);

    while (true) {
        if (obstacleDetection.getState()) {
            hwlib::cout << "Obstacle detected!" << hwlib::endl;
        } else {
            hwlib::cout << "Scanning.." << hwlib::endl;
            hwlib::wait_ms(250);
        }
    }

    return 0;
}