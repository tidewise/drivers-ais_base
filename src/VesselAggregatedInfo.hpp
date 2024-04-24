#ifndef AIS_BASE_VESSELAGGREGATEDINFO_HPP
#define AIS_BASE_VESSELAGGREGATEDINFO_HPP

#include "Position.hpp"
#include "VesselInformation.hpp"

namespace ais_base {
    /**
     *
     */
    struct VesselAggregatedInfo {
        VesselInformation vessel_info;
        ais_base::Position vessel_position;
        std::string vessel_id;
    };
}

#endif
