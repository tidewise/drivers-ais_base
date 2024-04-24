#ifndef AIS_BASE_VESSELINFOACCUMULATOR_HPP
#define AIS_BASE_VESSELINFOACCUMULATOR_HPP

#include "VesselAggregatedInfo.hpp"
#include <map>

namespace ais_base {
    /**
     *
     */
    struct VesselInfoAccumulator {
        std::map<uint32_t, VesselAggregatedInfo> m_vessels_information;
        void addVesselInformation(ais_base::VesselInformation const& info);
        void updateVesselPosition(ais_base::Position const& position);
    };
}

#endif
