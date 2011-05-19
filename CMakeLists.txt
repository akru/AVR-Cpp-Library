cmake_minimum_required(VERSION 2.6)

project("AVR-Cpp-Library")

set(mcu "atmega8")
set(f_cpu "8000000UL")

set(CMAKE_CXX_COMPILER "avr-g++")
set(CMAKE_OBJCOPY "avr-objcopy")
set(CMAKE_SIZE "avr-size")
set(CMAKE_CXX_FLAGS "-mmcu=${mcu} -DF_CPU=${f_cpu} -Wall -std=gnu++98 -Os -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "")

set(PROJECT_HEX_DIRECTORY "${CMAKE_SOURCE_DIR}/..")

set(CMAKE_VERBOSE_MAKEFILE "OFF")

include_directories("AVR-Cpp-Library/include")
add_subdirectory ("AVR-Cpp-Library")
add_subdirectory ("examples")
