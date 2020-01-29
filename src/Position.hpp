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
        STATUS_NOT_DEFINED = 15,

        STATUS_MIN = 0,
        STATUS_MAX = 15
    };

    enum ManeuverIndicator {
        MANEUVER_NOT_AVAILABLE = 0,
        MANEUVER_NORMAL = 1,
        MANEUVER_SPECIAL = 2,

        MANEUVER_MIN = 0,
        MANEUVER_MAX = 2
    };

    /** Representation of the data stored in AIS Message 1 to 3 */
    struct Position {
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
