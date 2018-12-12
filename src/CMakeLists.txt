rock_library(joint_tools
    SOURCES PWM.cpp PWMJointPositioner.cpp
    HEADERS PWM.hpp PWMJointPositioner.hpp PWMSettings.hpp PWMError.hpp
    DEPS_PKGCONFIG base-types)
