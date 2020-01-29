#include <ais_base/Position.hpp>

using namespace ais_base;

void Position::ensureEnumsValid() {
    if (status < STATUS_MIN || status > STATUS_MAX) {
        status = STATUS_NOT_DEFINED;
    }

    if (maneuver_indicator < MANEUVER_MIN || maneuver_indicator > MANEUVER_MAX) {
        maneuver_indicator = MANEUVER_NOT_AVAILABLE;
    }
}