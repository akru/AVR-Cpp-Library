set(INTEL_HEX_FILE "step.hex")

set(step_SRCS
    "main_application.cpp"
    "main.cpp")
add_executable(step ${step_SRCS})
target_link_libraries(step 
                                        atmega8
                                        utils
                                        led
                                        button
                                        sensor_angle
                                        step_motor)

add_custom_command(
    TARGET  step
    POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} 
    ARGS    -R.eeprom -O ihex ${CMAKE_BINARY_DIR}/examples/step_motor_driver/step ${PROJECT_HEX_DIRECTORY}/${INTEL_HEX_FILE}
    COMMENT "Convert ELF to IntelHEX")

add_custom_command(
    TARGET  step
    POST_BUILD
    COMMAND ${CMAKE_SIZE}
    ARGS    -C --mcu=${mcu} ${CMAKE_BINARY_DIR}/examples/step_motor_driver/step
    DEPENDS ${INTEL_HEX_FILE}
    COMMENT "Result project size")
