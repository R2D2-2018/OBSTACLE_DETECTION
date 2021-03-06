# Libraries:

link_libraries (gcc)

set (hwlib ${build_environment}/libraries/hwlib)
include_directories (${hwlib}/library)

set (catch ${build_environment}/libraries/Catch2)
include_directories (${catch}/single_include)

# Source Files:

set (sources
    src/wrap-hwlib.cpp
    src/libc-stub.cpp
    src/sensor_interface.cpp
    src/data_communication.cpp
    src/flex_sensor.cpp
    src/distance_sensor.cpp
    src/obstacle_detection.cpp
)
