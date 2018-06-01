/**
 * @file sensor_interface.hpp
 * @brief    Obstacle Detection sensors Interface class
 * @author   Joost van Lingen
 * @license  See LICENSE
 */

#ifndef SENSOR_INTERFACE_HPP
#define SENSOR_INTERFACE_HPP
#include "wrap-hwlib.hpp"

class SensorInterface {
  private:
    bool pressureState = 0;       ///< Stores boolean state of the Pressure sensor
    int distanceState = 0;        ///< Stores integer state of the Distance sensor
    bool warningState = 0;        ///< Stores boolean state of the warning funciton
    int distanceWarningValue = 0; ///< Stores integer edge value for warning funciton

    hwlib::pin_in &pressureSensorPin;      ///< Stores the address of the pin connected to the pressure sensor
    hwlib::pin_out &distanceSensorTrigPin; ///< Stores the address of the trigger pin connected to the distance sensor
    hwlib::pin_in &distanceSensorEchoPin;  ///< Stores the address of the echo pin connected to the distance sensor

    /**
     * @brief updatePressureState function
     *
     * The pressure state is determined by reading out the pin where the pressure sensor is connected, this is a simple true or
     * false. The distance state is determined by sending an echo pulse of 10 us to the trig pin of the distance sensor, waiting for
     * the echo pin to return a pulse. The length of this pulse represents the time it took the ultrasonic pulse to reach an
     * obstacle and get back to the sensor. This is multiplied by 0.034 (speed of sound devided by 100 to get cm/us) and devided by
     * 2 (the sound traveled forth and back, we only need to know the distance to the object).
     *
     * @param none
     * @return none
     */
    void updatePressureState();
    /**
     * @brief updateDistanceState function
     *
     * The distance state is determined by sending an echo pulse of 10 us to the trig pin of the distance sensor, waiting for
     * the echo pin to return a pulse. The length of this pulse represents the time it took the ultrasonic pulse to reach an
     * obstacle and get back to the sensor. This is multiplied by 0.034 (speed of sound devided by 100 to get cm/us) and devided by
     * 2 (the sound traveled forth and back, we only need to know the distance to the object).
     *
     * @param none
     * @return none
     */
    void updateDistanceState();

  public:
    /**
     * @brief constructor of SensorInterface
     *
     * Constructor for the SensorInterface class.
     *
     * @param The pins used for the sensors are given to the SensorInterface constructor
     * @return none
     */
    SensorInterface(hwlib::pin_in &pressureSensorPin, hwlib::pin_out &distanceSensorTrigPin, hwlib::pin_in &distanceSensorEchoPin);
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
    void setDistanceWarningValue(const int &distance);
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

#endif // SENSOR_INTERFACE_HPP
