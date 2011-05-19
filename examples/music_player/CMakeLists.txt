set(INTEL_HEX_FILE "music.hex")

set(music_SRCS
    "music_player.cpp"
    "main.cpp")
add_executable(music ${music_SRCS})
target_link_libraries(music 
                                        atmega8
                                        utils
                                        speaker)

add_custom_command(
    TARGET  music
    POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} 
    ARGS    -R.eeprom -O ihex ${CMAKE_BINARY_DIR}/examples/music_player/music ${PROJECT_HEX_DIRECTORY}/${INTEL_HEX_FILE}
    COMMENT "Convert ELF to IntelHEX")

add_custom_command(
    TARGET  music
    POST_BUILD
    COMMAND ${CMAKE_SIZE}
    ARGS    -C --mcu=${mcu} ${CMAKE_BINARY_DIR}/examples/music_player/music
    DEPENDS ${INTEL_HEX_FILE}
    COMMENT "Result project size")
