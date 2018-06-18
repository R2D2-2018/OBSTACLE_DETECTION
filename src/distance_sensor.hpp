#ifndef DISTANCE_SENSOR_HPP
#define DISTANCE_SENSOR_HPP
#include "wrap-hwlib.hpp"

/**
 * @file      distance_sensor.hpp
 * @brief     Hpp file for the class DistanceSensor which will contain functions to control a distance sensor
 * @author    Wouter Dijksta
 * @date      17-6-2018
 * @license   MIT
 */

/**
 * @class DistanceSensor
 * @brief Class for a distance sensor
 */
class DistanceSensor {
  private:
    hwlib::pin_in &echo_pin;     ///< Echo pin the distance sensor listens for a pulse on
    hwlib::pin_out &trigger_pin; ///< Trigger pin the distance sensor sends a pulse from

  public:
    /**
     * @brief DistanceSensor Constructor
     * @param echo_pin Echo pin the distance sensor listens for a pulse on
     * @param trigger_pin Trigger pin the distance sensor sends a pulse from
     */
    DistanceSensor(hwlib::pin_in &echo_pin, hwlib::pin_out &trigger_pin);

    /**
     * @brief getDistance() function
     *
     * This function takes a distance measurement with a distance sensor.
     *
     * @return integer value from the distance sensor
     */
    int getDistance();
};

#endif // DISTANCE_SENSOR_HPP