rock_library(ais_base
    HEADERS Position.hpp VesselInformation.hpp VoyageInformation.hpp
    SOURCES Position.cpp VesselInformation.cpp
    DEPS_PKGCONFIG base-types
)
