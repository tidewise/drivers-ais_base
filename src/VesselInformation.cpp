#include <ais_base/VesselInformation.hpp>

using namespace ais_base;

void VesselInformation::ensureEnumsValid() {
    if (ship_type < SHIP_TYPE_MIN || ship_type > SHIP_TYPE_MAX) {
        ship_type = SHIP_TYPE_NOT_AVAILABLE;
    }

    if (epfd_fix < EPFD_MIN || epfd_fix > EPFD_MAX) {
        epfd_fix = EPFD_UNDEFINED;
    }
}
