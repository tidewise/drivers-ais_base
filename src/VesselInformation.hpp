#ifndef AIS_BASE_VESSELINFORMATION_HPP
#define AIS_BASE_VESSELINFORMATION_HPP

#include <string>

#include <base/Float.hpp>
#include <base/Time.hpp>

namespace ais_base {
    struct VesselInformation {
        base::Time time;

        int mmsi = 0;
        int imo = 0;
        std::string call_sign;
        std::string name;
        int ship_type = 0;
        int position_device_type = 0;
        float draft = base::unknown<float>();
        float length = base::unknown<float>();
        float width = base::unknown<float>();

        base::Vector3d reference_position;
    };
}

#endif

