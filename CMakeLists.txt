cmake_minimum_required(VERSION 2.6)

project("step")

set(mcu "atmega8")
set(f_cpu "8000000UL")

set(CMAKE_CXX_COMPILER "avr-g++")
set(CMAKE_OBJCOPY "avr-objcopy")
set(CMAKE_SIZE "avr-size")
set(CMAKE_CXX_FLAGS "-mmcu=${mcu} -DF_CPU=${f_cpu} -Wall -std=gnu++98 -Os -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "")

set(PROJECT_HEX_DIRECTORY "${CMAKE_SOURCE_DIR}/..")
set(INTEL_HEX_FILE "${PROJECT_NAME}.hex")

set(CMAKE_VERBOSE_MAKEFILE "OFF")

set(project_SRCS
    "main_application.cpp"
    "main.cpp")
add_executable(${PROJECT_NAME} ${project_SRCS})

include_directories("AVR-Cpp-Library/include")
add_subdirectory ("AVR-Cpp-Library")
target_link_libraries(${PROJECT_NAME} 
                                        atmega8
                                        utils
                                        led
                                        button
                                        sensor_angle
                                        step_motor)

add_custom_command(
    TARGET  ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} 
    ARGS    -R.eeprom -O ihex ${CMAKE_BINARY_DIR}/${PROJECT_NAME} ${PROJECT_HEX_DIRECTORY}/${INTEL_HEX_FILE}
    COMMENT "Convert ELF to IntelHEX")

add_custom_command(
    TARGET  ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_SIZE}
    ARGS    -C --mcu=${mcu} ${CMAKE_BINARY_DIR}/${PROJECT_NAME}
    DEPENDS ${INTEL_HEX_FILE}
    COMMENT "Result project size")
