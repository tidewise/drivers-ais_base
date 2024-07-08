#ifndef AIS_BASE_POSITION_HPP
#define AIS_BASE_POSITION_HPP

#include <base/Angle.hpp>
#include <base/Float.hpp>
#include <base/Time.hpp>

namespace ais_base {
    enum NavigationalStatus {
        STATUS_UNDER_WAY_USING_ENGINE = 0,
        STATUS_AT_ANCHOR = 1,
        STATUS_NOT_UNDER_COMMAND = 2,
        STATUS_RESTRICTED_MANOEUVERABILITY = 3,
        STATUS_RESTRICTED_BY_DRAUGHT = 4,
        STATUS_MOORED = 5,
        STATUS_AGROUND = 6,
        STATUS_ENGAGED_IN_FISHING = 7,
        STATUS_UNDER_WAY_SAILING = 8,
        STATUS_RESERVED0 = 9,
        STATUS_RESERVED1 = 10,
        STATUS_RESERVED2 = 11,
        STATUS_RESERVED3 = 12,
        STATUS_RESERVED4 = 13,
        STATUS_AIS_SART_ACTIVE = 14,
        STATUS_NOT_DEFINED = 15
    };

    static const int STATUS_MIN = 0;
    static const int STATUS_MAX = 15;

    enum ManeuverIndicator {
        MANEUVER_NOT_AVAILABLE = 0,
        MANEUVER_NORMAL = 1,
        MANEUVER_SPECIAL = 2,
    };

    static const int MANEUVER_MIN = 0;
    static const int MANEUVER_MAX = 2;

    /** Representation of the data stored in AIS Message 1 to 3 */
    struct Position {
    public:
        base::Time time;
        /** The vessel MMSI number */
        int mmsi = 0;
        /** The vessel IMO number if available
         *
         * This should be filled by the software if the vessel information has
         * been received already
         */
        int imo = 0;
        /** Vessel course over ground */
        base::Angle course_over_ground;
        base::Angle latitude;
        base::Angle longitude;
        NavigationalStatus status = STATUS_NOT_DEFINED;
        /** Whether the GPS position is using differential (< 10m resolution) or
         * not
         */
        bool high_accuracy_position = false;
        /** Vessel heading */
        base::Angle yaw;
        /** Velocity in yaw, in rad/s */
        float yaw_velocity = base::unknown<float>();
        /** Speed over ground, in m/s */
        float speed_over_ground = base::unknown<float>();
        ManeuverIndicator maneuver_indicator = MANEUVER_NOT_AVAILABLE;
        bool raim = false;
        uint32_t radio_status = 0;

        Position() = default;
        Position(base::Time const& time,
            int mmsi,
            int imo,
            base::Angle const& course_over_ground,
            base::Angle const& latitude,
            base::Angle const& longitude,
            NavigationalStatus status,
            bool high_accuracy_position,
            base::Angle const& yaw,
            float yaw_velocity,
            float speed_over_ground,
            ManeuverIndicator maneuver_indicator,
            bool raim,
            uint32_t radio_status)
            : time(time)
            , mmsi(mmsi)
            , imo(imo)
            , course_over_ground(course_over_ground)
            , latitude(latitude)
            , longitude(longitude)
            , status(status)
            , high_accuracy_position(high_accuracy_position)
            , yaw(yaw)
            , yaw_velocity(yaw_velocity)
            , speed_over_ground(speed_over_ground)
            , maneuver_indicator(maneuver_indicator)
            , raim(raim)
            , radio_status(radio_status){};

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
