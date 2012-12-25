set(INTEL_HEX_FILE "tc.hex")

set(tc_SRCS
    "thermo_controller.cpp"
    "main.cpp")
add_executable(tc ${tc_SRCS})
target_link_libraries(tc 
                                        atmega8
                                        utils
                                        button
                                        seven_segment
                                        led)

add_custom_command(
    TARGET  tc
    POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} 
    ARGS    -R.eeprom -O ihex ${CMAKE_BINARY_DIR}/examples/thermo_controller/tc ${PROJECT_HEX_DIRECTORY}/${INTEL_HEX_FILE}
    COMMENT "Convert ELF to IntelHEX")

add_custom_command(
    TARGET  tc
    POST_BUILD
    COMMAND ${CMAKE_SIZE}
    ARGS    -C --mcu=${mcu} ${CMAKE_BINARY_DIR}/examples/thermo_controller/tc
    DEPENDS ${INTEL_HEX_FILE}
    COMMENT "Result project size")
