#include <gtest/gtest.h>
#include <ais_base/VesselInformation.hpp>

using namespace ais_base;

struct VesselInformationTest : public ::testing::Test {
    VesselInformation info;
};

TEST_F(VesselInformationTest, it_sets_SHIP_TYPE_NOT_AVAILABLE_for_ship_types_lower_than_MIN) {
    info.ship_type = static_cast<ShipType>(SHIP_TYPE_MIN - 1);
    info.ensureEnumsValid();
    ASSERT_EQ(SHIP_TYPE_NOT_AVAILABLE, info.ship_type);
}

TEST_F(VesselInformationTest, it_sets_SHIP_TYPE_NOT_AVAILABLE_for_ship_types_higher_than_MAX) {
    info.ship_type = static_cast<ShipType>(SHIP_TYPE_MAX + 1);
    info.ensureEnumsValid();
    ASSERT_EQ(SHIP_TYPE_NOT_AVAILABLE, info.ship_type);
}

TEST_F(VesselInformationTest, it_sets_EPFD_UNDEFINED_for_epfd_fix_lower_than_MIN) {
    info.epfd_fix = static_cast<EPFDFixType>(EPFD_MIN - 1);
    info.ensureEnumsValid();
    ASSERT_EQ(EPFD_UNDEFINED, info.epfd_fix);
}

TEST_F(VesselInformationTest, it_sets_EPFD_UNDEFINED_for_epfd_fix_higher_than_MAX) {
    info.epfd_fix = static_cast<EPFDFixType>(EPFD_MAX + 1);
    info.ensureEnumsValid();
    ASSERT_EQ(EPFD_UNDEFINED, info.epfd_fix);
}
