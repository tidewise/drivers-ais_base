rock_library(ais_base
    SOURCES Dummy.cpp
    HEADERS Dummy.hpp)

rock_executable(ais_base_bin Main.cpp
    DEPS ais_base)

