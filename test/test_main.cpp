#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

// cppcheck-suppress unusedFunction
TEST_CASE("Example Test Case") {
    // cppcheck-suppress knownConditionTrueFalse
    // cppcheck-suppress duplicateExpression
    REQUIRE(10 == 10);
}
