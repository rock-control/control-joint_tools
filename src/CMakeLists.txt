rock_library(joint_tools
    SOURCES Dummy.cpp
    HEADERS Dummy.hpp)

rock_executable(joint_tools_bin Main.cpp
    DEPS joint_tools)

