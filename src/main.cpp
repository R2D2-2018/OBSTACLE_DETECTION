#include "flex_sensor.hpp"
#include "wrap-hwlib.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);
    hwlib::cout << "Starting..." << hwlib::endl;

    auto analog_pin = hwlib::target::pin_in(hwlib::target::pins::d7);

    FlexSensor flexSensor(analog_pin);
    while (true) {
        hwlib::cout << flexSensor.read() << hwlib::endl;
        hwlib::wait_ms(500);
    }

    return 0;
}