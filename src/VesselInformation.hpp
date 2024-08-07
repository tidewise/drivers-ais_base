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

    static const int EPFD_MIN = 0;
    static const int EPFD_MAX = 8;

    enum ShipType {
        SHIP_TYPE_NOT_AVAILABLE = 0,
        SHIP_TYPE_RESERVED1 = 1,
        SHIP_TYPE_RESERVED2 = 2,
        SHIP_TYPE_RESERVED3 = 3,
        SHIP_TYPE_RESERVED4 = 4,
        SHIP_TYPE_RESERVED5 = 5,
        SHIP_TYPE_RESERVED6 = 6,
        SHIP_TYPE_RESERVED7 = 7,
        SHIP_TYPE_RESERVED8 = 8,
        SHIP_TYPE_RESERVED9 = 9,

        SHIP_TYPE_RESERVED10 = 10,
        SHIP_TYPE_RESERVED11 = 11,
        SHIP_TYPE_RESERVED12 = 12,
        SHIP_TYPE_RESERVED13 = 13,
        SHIP_TYPE_RESERVED14 = 14,
        SHIP_TYPE_RESERVED15 = 15,
        SHIP_TYPE_RESERVED16 = 16,
        SHIP_TYPE_RESERVED17 = 17,
        SHIP_TYPE_RESERVED18 = 18,
        SHIP_TYPE_RESERVED19 = 19,

        SHIP_TYPE_WING_IN_GROUND = 20,
        SHIP_TYPE_WING_IN_GROUND_HAZARDOUS_CAT_A = 21,
        SHIP_TYPE_WING_IN_GROUND_HAZARDOUS_CAT_B = 22,
        SHIP_TYPE_WING_IN_GROUND_HAZARDOUS_CAT_C = 23,
        SHIP_TYPE_WING_IN_GROUND_HAZARDOUS_CAT_D = 24,
        SHIP_TYPE_RESERVED25 = 25,
        SHIP_TYPE_RESERVED26 = 26,
        SHIP_TYPE_RESERVED27 = 27,
        SHIP_TYPE_RESERVED28 = 28,
        SHIP_TYPE_RESERVED29 = 29,

        SHIP_TYPE_FISHING = 30,
        SHIP_TYPE_TOWING = 31,
        SHIP_TYPE_TOWING_LARGE = 32, // EXCEEDS 200M LENGTH OR 25M BREADTH
        SHIP_TYPE_DREDGING_OR_UNDERWATER_OPS = 33,
        SHIP_TYPE_DIVING_OPS = 34,
        SHIP_TYPE_MILITARY_OPS = 35,
        SHIP_TYPE_SAILING = 36,
        SHIP_TYPE_PLEASURE_CRAFT = 37,
        SHIP_TYPE_RESERVED38 = 38,
        SHIP_TYPE_RESERVED39 = 39,

        SHIP_TYPE_HIGH_SPEED_CRAFT = 40,
        SHIP_TYPE_HIGH_SPEED_CRAFT_HAZARDOUS_CAT_A = 41,
        SHIP_TYPE_HIGH_SPEED_CRAFT_HAZARDOUS_CAT_B = 42,
        SHIP_TYPE_HIGH_SPEED_CRAFT_HAZARDOUS_CAT_C = 43,
        SHIP_TYPE_HIGH_SPEED_CRAFT_HAZARDOUS_CAT_D = 44,
        SHIP_TYPE_RESERVED45 = 45,
        SHIP_TYPE_RESERVED46 = 46,
        SHIP_TYPE_RESERVED47 = 47,
        SHIP_TYPE_RESERVED48 = 48,
        SHIP_TYPE_HIGH_SPEED_CRAFT_NO_INFO = 49,

        SHIP_TYPE_PILOT_VESSEL = 50,
        SHIP_TYPE_SEARCH_AND_RESCUE_VESSEL = 51,
        SHIP_TYPE_TUG = 52,
        SHIP_TYPE_PORT_TENDER = 53,
        SHIP_TYPE_ANTI_POLLUTION_EQUIPMENT = 54,
        SHIP_TYPE_LAW_ENFORCEMENT = 55,
        SHIP_TYPE_RESERVED56 = 56,
        SHIP_TYPE_RESERVED57 = 57,
        SHIP_TYPE_MEDICAL_TRANSPORT = 58,
        SHIP_TYPE_NONCOMBATANT = 59,

        SHIP_TYPE_PASSENGER = 60,
        SHIP_TYPE_PASSENGER_HAZARDOUS_CAT_A = 61,
        SHIP_TYPE_PASSENGER_HAZARDOUS_CAT_B = 62,
        SHIP_TYPE_PASSENGER_HAZARDOUS_CAT_C = 63,
        SHIP_TYPE_PASSENGER_HAZARDOUS_CAT_D = 64,
        SHIP_TYPE_RESERVED65 = 65,
        SHIP_TYPE_RESERVED66 = 66,
        SHIP_TYPE_RESERVED67 = 67,
        SHIP_TYPE_RESERVED68 = 68,
        SHIP_TYPE_PASSENGER_NO_INFO = 69,

        SHIP_TYPE_CARGO = 70,
        SHIP_TYPE_CARGO_HAZARDOUS_CAT_A = 71,
        SHIP_TYPE_CARGO_HAZARDOUS_CAT_B = 72,
        SHIP_TYPE_CARGO_HAZARDOUS_CAT_C = 73,
        SHIP_TYPE_CARGO_HAZARDOUS_CAT_D = 74,
        SHIP_TYPE_RESERVED75 = 75,
        SHIP_TYPE_RESERVED76 = 76,
        SHIP_TYPE_RESERVED77 = 77,
        SHIP_TYPE_RESERVED78 = 78,
        SHIP_TYPE_CARGO_NO_INFO = 79,

        SHIP_TYPE_TANKER = 80,
        SHIP_TYPE_TANKER_HAZARDOUS_CAT_A = 81,
        SHIP_TYPE_TANKER_HAZARDOUS_CAT_B = 82,
        SHIP_TYPE_TANKER_HAZARDOUS_CAT_C = 83,
        SHIP_TYPE_TANKER_HAZARDOUS_CAT_D = 84,
        SHIP_TYPE_RESERVED85 = 85,
        SHIP_TYPE_RESERVED86 = 86,
        SHIP_TYPE_RESERVED87 = 87,
        SHIP_TYPE_RESERVED88 = 88,
        SHIP_TYPE_TANKER_NO_INFO = 89,

        SHIP_TYPE_OTHER = 90,
        SHIP_TYPE_OTHER_HAZARDOUS_CAT_A = 91,
        SHIP_TYPE_OTHER_HAZARDOUS_CAT_B = 92,
        SHIP_TYPE_OTHER_HAZARDOUS_CAT_C = 93,
        SHIP_TYPE_OTHER_HAZARDOUS_CAT_D = 94,
        SHIP_TYPE_RESERVED95 = 95,
        SHIP_TYPE_RESERVED96 = 96,
        SHIP_TYPE_RESERVED97 = 97,
        SHIP_TYPE_RESERVED98 = 98,
        SHIP_TYPE_OTHER_NO_INFO = 99,
    };

    static const int SHIP_TYPE_MIN = 0;
    static const int SHIP_TYPE_MAX = 99;

    struct VesselInformation {
    public:
        base::Time time;
        int mmsi = 0;
        int imo = 0;
        std::string name;
        std::string call_sign;
        float length = base::unknown<float>();
        float width = base::unknown<float>();
        ShipType ship_type = SHIP_TYPE_NOT_AVAILABLE;
        EPFDFixType epfd_fix = EPFD_UNDEFINED;
        float draft = base::unknown<float>();
        base::Vector3d reference_position =
            base::Vector3d(base::unknown<float>(),
                           base::unknown<float>(),
                           base::unknown<float>());

        VesselInformation() = default;
        VesselInformation(base::Time const& time,
            int mmsi,
            int imo,
            std::string name,
            std::string call_sign,
            float length = base::unknown<float>(),
            float width = base::unknown<float>(),
            ShipType ship_type = SHIP_TYPE_NOT_AVAILABLE,
            EPFDFixType epfd_fix = EPFD_UNDEFINED,
            float draft = base::unknown<float>(),
            base::Vector3d const& reference_position = base::Vector3d(base::unknown<float>(),
                base::unknown<float>(),
                base::unknown<float>()))
            : time(time)
            , mmsi(mmsi)
            , imo(imo)
            , name(name)
            , call_sign(call_sign)
            , length(length)
            , width(width)
            , ship_type(ship_type)
            , epfd_fix(epfd_fix)
            , draft(draft)
            , reference_position(reference_position){};

        /** Convert invalid enum values to the corresponding 'unknown' enum
         * entry
         *
         * This is to be used as input validation for packages that do
         * conversion from e.g. NMEA
         */
        void ensureEnumsValid();
    };
}

#endif
