#include "flex_sensor.hpp"
#include "wrap-hwlib.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);
    hwlib::cout << "Starting..." << hwlib::endl;

    auto ad_pin = hwlib::target::pin_adc(hwlib::target::ad_pins::a0);

    FlexSensor flexSensor(ad_pin);

    while (true) {
        hwlib::cout << flexSensor.read() << hwlib::endl;
        hwlib::wait_ms(500);
    }

    return 0;
}