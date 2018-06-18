#ifndef OBSTACLE_DETECTION_HPP
#define OBSTACLE_DETECTION_HPP
#include "distance_sensor.hpp"
#include "flex_sensor.hpp"
#include "wrap-hwlib.hpp"

/**
 * @file      obstacle_detection.hpp
 * @brief     Hpp file for the class ObstacleDetection
 * @author    Wouter Dijksta
 * @date      17-6-2018
 * @license   MIT
 */

/**
 * @class ObstacleDetection
 * @brief Class for the ObstacleDetection interface
 */
class ObstacleDetection {
  private:
    FlexSensor &flexSensor;         ///< Flex sensor object
    DistanceSensor &distanceSensor; ///< Distance sensor object

    int distanceThreshold; ///< Threshold for the distance sensor
    int pressureThreshold; ///< Threshold for the pressure sensor

  public:
    /**
     * @brief ObstacleDetection Constructor
     */
    ObstacleDetection(FlexSensor &flexSensor, DistanceSensor &distanceSensor);

    /**
     * @brief getState() function
     *
     * This function returns either true or false based on if the module detects an obstacle nearby. Either because the pressure
     * sensor is touching an object, or because the distance sensor notices an object nearby.
     *
     * @return boolean
     */
    bool getState();

    /**
     * @brief getDistanceThreshold() function
     *
     * This function returns the value the distanceThreshold variable contains
     *
     * @return int
     */
    int getDistanceThreshold();
    /**
     * @brief getPressureThreshold() function
     *
     * This function returns the value the pressureThreshold variable contains
     *
     * @return int
     */
    int getPressureThreshold();
    /**
     * @brief setDistanceThreshold() function
     *
     * This function sets the distanceThreshold variable to a given value
     *
     * @return void
     */
    void setDistanceThreshold(int distanceThreshold);
    /**
     * @brief setPressureThreshold() function
     *
     * This function sets the pressureThreshold variable to a given value
     *
     * @return void
     */
    void setPressureThreshold(int pressureThreshold);
};

#endif // OBSTACLE_DETECTION_HPP