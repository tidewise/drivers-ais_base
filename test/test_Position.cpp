#include <gtest/gtest.h>
#include <ais_base/Position.hpp>

using namespace ais_base;

struct PositionTest : public ::testing::Test {
    Position position;
};

TEST_F(PositionTest, it_sets_SHIP_TYPE_NOT_AVAILABLE_for_ship_types_lower_than_MIN) {
    position.status = static_cast<NavigationalStatus>(STATUS_MIN - 1);
    position.ensureEnumsValid();
    ASSERT_EQ(STATUS_NOT_DEFINED, position.status);
}

TEST_F(PositionTest, it_sets_SHIP_TYPE_NOT_AVAILABLE_for_ship_types_higher_than_MAX) {
    position.status = static_cast<NavigationalStatus>(STATUS_MAX + 1);
    position.ensureEnumsValid();
    ASSERT_EQ(STATUS_NOT_DEFINED, position.status);
}

TEST_F(PositionTest, it_sets_EPFD_UNDEFINED_for_epfd_fix_lower_than_MIN) {
    position.maneuver_indicator = static_cast<ManeuverIndicator>(MANEUVER_MIN - 1);
    position.ensureEnumsValid();
    ASSERT_EQ(MANEUVER_NOT_AVAILABLE, position.maneuver_indicator);
}

TEST_F(PositionTest, it_sets_EPFD_UNDEFINED_for_epfd_fix_higher_than_MAX) {
    position.maneuver_indicator = static_cast<ManeuverIndicator>(MANEUVER_MAX + 1);
    position.ensureEnumsValid();
    ASSERT_EQ(MANEUVER_NOT_AVAILABLE, position.maneuver_indicator);
}
