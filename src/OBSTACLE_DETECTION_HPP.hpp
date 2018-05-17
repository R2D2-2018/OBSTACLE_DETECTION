#ifndef OBSTACLE_DETECTION_HPP
#define OBSTACLE_DETECTION_HPP
#include "wrap-hwlib.hpp"

class ObstacleDetection {
  private:
    bool pressureState = 0;
    int distanceState = 0;
    bool warningState = 0;
    int distanceWarningValue = 0;
    const hwlib::target::pin_in &pressureSensorPin;
    const hwlib::target::pin_in &distanceSensorTrigPin;
    const hwlib::target::pin_in &distanceSensorEchoPin;

  public:
    ObstacleDetection(const hwlib::target::pin_in &pressureSensorPin, const hwlib::target::pin_in &distanceSensorTrigPin,
                      const hwlib::target::pin_in &distanceSensorEchoPin);
    bool getPressureState();
    int getDistanceState();
    void setDestanceWarningValue(int distance);
    bool getWarningState();
};

#endif // OBSTACLE_DETECTION_HPP