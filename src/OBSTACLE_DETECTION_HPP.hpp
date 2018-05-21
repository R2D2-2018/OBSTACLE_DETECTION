/**
 * @file OBSTACLE_DETECTION_HPP.hpp
 * @brief    Obstacle Detection class
 * @author   Joost van Lingen
 * @license  See LICENSE
 */

#ifndef OBSTACLE_DETECTION_HPP
#define OBSTACLE_DETECTION_HPP
#include "wrap-hwlib.hpp"

class ObstacleDetection {
  private:
    bool pressureState = 0;       ///< Stores boolean state of the Pressure sensor
    int distanceState = 0;        ///< Stores integer state of the Distance sensor
    bool warningState = 0;        ///< Stores boolean state of the warning funciton
    int distanceWarningValue = 0; ///< Stores integer edge value for warning funciton

    hwlib::target::pin_in pressureSensorPin;
    hwlib::target::pin_in distanceSensorTrigPin;
    hwlib::target::pin_in distanceSensorEchoPin;

  public:
    ObstacleDetection(hwlib::target::pin_in pressureSensorPin, hwlib::target::pin_in distanceSensorTrigPin,
                      hwlib::target::pin_in distanceSensorEchoPin);
    /**
     * @brief returns state of pressure sensor
     *
     * Returns the state of the pressure sensor. Returns true when sensing pressure, false when not sensing pressure.
     *
     * @param none
     * @return the state of the pressure sensor as a boolean
     */
    bool getPressureState();
    /**
     * @brief returns state of distance sensor
     *
     * Returns the state of the distance sensor as centimeters to most nearby obstacle in an integer variable.
     *
     * @param none
     * @return the state of the distance sensor as an integer
     */
    int getDistanceState();
    /**
     * @brief sets warning edge value
     *
     * Sets the edge value in centimeters for when the warning state must be set to TRUE.
     *
     * @param dinstance in centimeters, as an integer variable
     * @return none
     */
    void setDistanceWarningValue(int distance);
    /**
     * @brief returns state of warning function
     *
     * Returns the state of the warning function.
     * When the distance sensor measures and obstacle whithin the distance set as edge value, the warning state will be set to TRUE.
     *
     * @param none
     * @return the state of the warning function as a boolean
     */
    bool getWarningState();
};

#endif // OBSTACLE_DETECTION_HPP