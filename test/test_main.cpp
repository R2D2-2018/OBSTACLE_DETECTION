#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

class ObstacleDetection {
  public:
    bool pressureState = 0;
    int distanceState = 0;
    bool warningState = 0;
    int distanceWarningValue = 0;
    int pin;

  public:
    explicit ObstacleDetection(int pin);
    bool getPressureState();
    int getDistanceState();
    void setDistanceWarningValue(int distance);
    bool getWarningState();
};

ObstacleDetection::ObstacleDetection(int pin) : pin(pin){};

bool ObstacleDetection::getPressureState() {
    return pressureState;
}

int ObstacleDetection::getDistanceState() {
    return distanceState;
}

void ObstacleDetection::setDistanceWarningValue(int distance) {
    distanceWarningValue = distance;
}

bool ObstacleDetection::getWarningState() {
    return warningState;
}

ObstacleDetection obstacleDetector(2);

TEST_CASE("Set Distance Warning Value") {
    obstacleDetector.setDistanceWarningValue(50);
    REQUIRE(obstacleDetector.distanceWarningValue == 50);
}

TEST_CASE("Read pressure state") {
    REQUIRE(obstacleDetector.getPressureState() == false);
}

TEST_CASE("Read distance state") {
    REQUIRE(obstacleDetector.getDistanceState() == 0);
}

TEST_CASE("Read warning state") {
    REQUIRE(obstacleDetector.getWarningState() == false);
}