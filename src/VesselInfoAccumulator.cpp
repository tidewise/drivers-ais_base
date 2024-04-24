#include "VesselInfoAccumulator.hpp"

using namespace ais_base;
using namespace std;

void VesselInfoAccumulator::addVesselInformation(
    ais_base::VesselInformation const& vessel_info)
{
    int mmsi = vessel_info.mmsi;
    auto& info = m_vessels_information[mmsi];
    info.vessel_info = vessel_info;
    if (info.vessel_id.empty()) {
        info.vessel_id = to_string(mmsi);
    }
    if (info.vessel_position.time.isNull()) {
        std::cout << "received vessel information for " << mmsi
                  << " but no position information received yet" << std::endl;
        return;
    }
}

void VesselInfoAccumulator::updateVesselPosition(ais_base::Position const& position)
{
    int mmsi = position.mmsi;
    auto& info = m_vessels_information[mmsi];
    if (info.vessel_id.empty()) {
        info.vessel_id = to_string(mmsi);
    }
    info.vessel_position = position;

    // For our purposes ... if the angle is unknown, use the course. If there's no
    // course, just ignore
    auto yaw = position.yaw;
    if (base::isUnknown(yaw)) {
        yaw = position.course_over_ground;
        if (base::isUnknown(yaw)) {
            // should it be LOG_ERROR_S?
            std::cout << "ignoring position for " << mmsi
                      << " as it has no heading or course information" << std::endl;
            return;
        }
    }
    info.vessel_position.yaw = yaw;

    if (info.vessel_info.time.isNull()) {
        std::cout << "received position for " << mmsi
                  << " but no vessel information received yet" << std::endl;
        return;
    }

}
