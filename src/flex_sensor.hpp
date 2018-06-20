#ifndef FLEX_SENSOR_HPP
#define FLEX_SENSOR_HPP
#include "wrap-hwlib.hpp"

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
    hwlib::adc &analog_pin; ///< Analog pin the sensor is hooked up to
    int calibrationValues;  ///< Integer that holds the values to calibrate the sensor
    int restingValue;       ///< Value from the sensor when it is not being bent
    bool calibrated;        ///< Has the sensor been calibrated?

  public:
    /**
     * @brief FlexSensor Constructor
     * @param analog_pin       Pin to read the voltage on
     */
    explicit FlexSensor(hwlib::adc &analog_pin);

    /**
     * @brief read() function
     *
     * This function reads returns a reading from the flex sensor.
     *
     * @return integer value from the flex sensor
     */
    int read();

    /**
     * @brief calibrate() functon
     *
     * This function performs a calibration of the sensor. It calls the `read()` function 10 times takes the average of those
     * values to determine the value the sensor returns in an "idle" state.
     *
     * @return void
     */
    void calibrate();

    /**
     * @brief reset() functon
     *
     * This function resets the flex sensors' internal variables incase the calibration needs to be performed again.
     *
     * @return void
     */
    void reset();
};

#endif // FLEX_SENSOR_HPP