set(atmega8_SRCS
    "src/atmega8/analog_digital_converter.cpp"
    "src/atmega8/external_interrupt.cpp"
    "src/atmega8/timer.cpp"
    "src/atmega8/atmega8.cpp"
)
set(sensor_angle_SRCS
    "src/device/sensor_angle.cpp")
set(button_SRCS
    "src/device/button.cpp")
set(step_motor_SRCS
    "src/device/step_motor.cpp")
set(led_SRCS
    "src/device/led.cpp")
set(seven_segment_SRCS
    "src/device/seven_segment.cpp")
set(speaker_RSCS
    "src/device/speaker.cpp")
set(pid_controller_RSCS
    "src/controller/pid.cpp")
set(utils_SRCS
    "src/utils.cpp")
    
add_library(atmega8 ${atmega8_SRCS})
add_library(sensor_angle ${sensor_angle_SRCS})
add_library(button ${button_SRCS})
add_library(step_motor ${step_motor_SRCS})
add_library(led ${led_SRCS})
add_library(seven_segment ${seven_segment_SRCS})
add_library(speaker ${speaker_RSCS})
add_library(pid_controller ${pid_controller_RSCS})
add_library(utils ${utils_SRCS})
