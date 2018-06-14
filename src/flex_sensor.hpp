#ifndef FLEX_SENSOR_HPP
#define FLEX_SENSOR_HPP
#include "wrap-hwlib.hpp"

#include <array>

/**
 * @file      flex_sensor.hpp
 * @brief     Hpp file for the class FlexSensor which will contain functions to control the FlexSensor pressure sensor
 * @author    Wouter Dijksta
 * @date      12-6-2018
 * @license   MIT
 */

/**
 * @class FlexSensor
 * @brief Class for the FlexSensor pressure sensor
 */
class FlexSensor {
  private:
    hwlib::target::pin_in analog_pin; // Analog pin the sensor is hooked up to
    int calibrationValues;            // Integer that holds the values to calibrate the sensor
    int threshold;                    // Threshold value
    int resting_value;                // Value from the sensor when it is not being bent
    bool calibrated;                  // Has the sensor been calibrated?

  public:
    /**
     * @brief FlexSensor Constructor
     * @param analog_pin       Pin to read the voltage on
     */
    explicit FlexSensor(hwlib::target::pin_in &analog_pin);

    int read();       // Gets a value from the sensor
    void calibrate(); // Calibrates the sensor
    void reset();     // Resets `calibrated` value
};

#endif // FLEX_SENSOR_HPP