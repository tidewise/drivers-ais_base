#ifndef AIS_BASE_VESSELINFORMATION_HPP
#define AIS_BASE_VESSELINFORMATION_HPP

#include <string>

#include <base/Eigen.hpp>
#include <base/Float.hpp>
#include <base/Time.hpp>

namespace ais_base {
    enum EPFDFixType {
        EPFD_UNDEFINED = 0,
        EPFD_GPS = 1,
        EPFD_GLONASS = 2,
        EPFD_COMBINED_GPS_GLONASS = 3,
        EPFD_LORAN_C = 4,
        EPFD_CHAYKA = 5,
        EPFD_INTEGRATED_NAVIGATION_SYSTEM = 6,
        EPFD_SURVEYED = 7,
        EPFD_GALILEO = 8,
    };

    enum ShipType {
        SHIP_TYPE_NOT_AVAILABLE = 0,
        // 1..19 RESERVED FOR FUTURE USE
        SHIP_TYPE_WING_IN_GROUND = 20,
        SHIP_TYPE_WING_IN_GROUND_HAZARDOUS_CAT_A = 21,
        SHIP_TYPE_WING_IN_GROUND_HAZARDOUS_CAT_B = 22,
        SHIP_TYPE_WING_IN_GROUND_HAZARDOUS_CAT_C = 23,
        SHIP_TYPE_WING_IN_GROUND_HAZARDOUS_CAT_D = 24,
        // 25..29 WIG RESERVED FOR FUTURE USE
        SHIP_TYPE_FISHING = 30,
        SHIP_TYPE_TOWING = 31,
        SHIP_TYPE_TOWING_LARGE = 32, // EXCEEDS 200M LENGTH OR 25M BREADTH
        SHIP_TYPE_DREDGING_OR_UNDERWATER_OPS = 33,
        SHIP_TYPE_DIVING_OPS = 34,
        SHIP_TYPE_MILITARY_OPS = 35,
        SHIP_TYPE_SAILING = 36,
        SHIP_TYPE_PLEASURE_CRAFT = 37,
        // 38..39 RESERVED
        SHIP_TYPE_HIGH_SPEED_CRAFT = 40,
        SHIP_TYPE_HIGH_SPEED_CRAFT_HAZARDOUS_CAT_A = 41,
        SHIP_TYPE_HIGH_SPEED_CRAFT_HAZARDOUS_CAT_B = 42,
        SHIP_TYPE_HIGH_SPEED_CRAFT_HAZARDOUS_CAT_C = 43,
        SHIP_TYPE_HIGH_SPEED_CRAFT_HAZARDOUS_CAT_D = 44,
        // 45..48 HSC RESERVED FOR FUTURE USE
        SHIP_TYPE_HIGH_SPEED_CRAFT_NO_INFO = 49,
        SHIP_TYPE_PILOT_VESSEL = 50,
        SHIP_TYPE_SEARCH_AND_RESCUE_VESSEL = 51,
        SHIP_TYPE_TUG = 52,
        SHIP_TYPE_PORT_TENDER = 53,
        SHIP_TYPE_ANTI_POLLUTION_EQUIPMENT = 54,
        SHIP_TYPE_LAW_ENFORCEMENT = 55,
        // 56..57 SPARE, LOCAL VESSEL
        SHIP_TYPE_MEDICAL_TRANSPORT = 58,
        SHIP_TYPE_NONCOMBATANT = 59,
        SHIP_TYPE_PASSENGER = 60,
        SHIP_TYPE_PASSENGER_HAZARDOUS_CAT_A = 61,
        SHIP_TYPE_PASSENGER_HAZARDOUS_CAT_B = 62,
        SHIP_TYPE_PASSENGER_HAZARDOUS_CAT_C = 63,
        SHIP_TYPE_PASSENGER_HAZARDOUS_CAT_D = 64,
        // 65..68 PASSENGER RESERVED FOR FUTURE USE
        SHIP_TYPE_PASSENGER_NO_INFO = 69,
        SHIP_TYPE_CARGO = 70,
        SHIP_TYPE_CARGO_HAZARDOUS_CAT_A = 71,
        SHIP_TYPE_CARGO_HAZARDOUS_CAT_B = 72,
        SHIP_TYPE_CARGO_HAZARDOUS_CAT_C = 73,
        SHIP_TYPE_CARGO_HAZARDOUS_CAT_D = 74,
        // 75..78 CARGO RESERVED FOR FUTURE USE
        SHIP_TYPE_CARGO_NO_INFO = 79,
        SHIP_TYPE_TANKER = 80,
        SHIP_TYPE_TANKER_HAZARDOUS_CAT_A = 81,
        SHIP_TYPE_TANKER_HAZARDOUS_CAT_B = 82,
        SHIP_TYPE_TANKER_HAZARDOUS_CAT_C = 83,
        SHIP_TYPE_TANKER_HAZARDOUS_CAT_D = 84,
        // 85..88 TANKER RESERVED FOR FUTURE USE
        SHIP_TYPE_TANKER_NO_INFO = 89,
        SHIP_TYPE_OTHER = 90,
        SHIP_TYPE_OTHER_HAZARDOUS_CAT_A = 91,
        SHIP_TYPE_OTHER_HAZARDOUS_CAT_B = 92,
        SHIP_TYPE_OTHER_HAZARDOUS_CAT_C = 93,
        SHIP_TYPE_OTHER_HAZARDOUS_CAT_D = 94,
        // 95..98 OTHER TYPE RESERVED FOR FUTURE USE
        SHIP_TYPE_OTHER_NO_INFO = 99,
    };

    struct VesselInformation {
        base::Time time;

        int mmsi = 0;
        int imo = 0;
        std::string call_sign;
        std::string name;
        ShipType ship_type = SHIP_TYPE_NOT_AVAILABLE;
        EPFDFixType epfd_fix = EPFD_UNDEFINED;
        float draft = base::unknown<float>();
        float length = base::unknown<float>();
        float width = base::unknown<float>();

        base::Vector3d reference_position =
            base::Vector3d(base::unknown<float>(),
                           base::unknown<float>(),
                           base::unknown<float>());
    };
}

#endif

