#include <ais_base/VesselInfoAccumulator.hpp>
#include <gtest/gtest.h>
#include <iostream>

using namespace ais_base;
using namespace std;

struct VesselInforAccumulatorTest : public ::testing::Test {};

TEST_F(VesselInforAccumulatorTest, it_updates_the_vessel_information)
{
    VesselInfoAccumulator accumulator;
    VesselInformation vessel_0_info;
    vessel_0_info.mmsi = 0;
    accumulator.addVesselInformation(vessel_0_info);
    ASSERT_EQ(accumulator.m_vessels_information[0].vessel_id, "0");
    accumulator.addVesselInformation(vessel_0_info);
    ASSERT_EQ(accumulator.m_vessels_information[0].vessel_id, "0");
    VesselInformation vessel_1_info;
    vessel_1_info.mmsi = 1;
    accumulator.addVesselInformation(vessel_1_info);
    ASSERT_EQ(accumulator.m_vessels_information[1].vessel_id, "1");
    ASSERT_EQ(accumulator.m_vessels_information.size(), 2);
}

TEST_F(VesselInforAccumulatorTest,
    it_updates_the_vessel_position_with_nan_yaw_and_nan_course)
{
    VesselInfoAccumulator accumulator;
    Position vessel_0_position;
    vessel_0_position.mmsi = 0;
    vessel_0_position.latitude = base::Angle::fromRad(0.1);
    vessel_0_position.longitude = base::Angle::fromRad(0.2);
    accumulator.updateVesselPosition(vessel_0_position);
    ASSERT_EQ(accumulator.m_vessels_information[0].vessel_id, "0");
    ASSERT_TRUE(std::isnan(accumulator.m_vessels_information[0].vessel_position.yaw.rad));
    ASSERT_EQ(accumulator.m_vessels_information[0].vessel_position.latitude.rad,
        vessel_0_position.latitude.rad);
    ASSERT_EQ(accumulator.m_vessels_information[0].vessel_position.longitude.rad,
        vessel_0_position.longitude.rad);
}

TEST_F(VesselInforAccumulatorTest,
    it_updates_the_vessel_position_with_nan_yaw_but_with_course)
{
    VesselInfoAccumulator accumulator;
    Position vessel_0_position;
    vessel_0_position.mmsi = 0;
    vessel_0_position.latitude = base::Angle::fromRad(0.1);
    vessel_0_position.longitude = base::Angle::fromRad(0.2);
    vessel_0_position.course_over_ground = base::Angle::fromRad(0.5);
    accumulator.updateVesselPosition(vessel_0_position);
    ASSERT_EQ(accumulator.m_vessels_information[0].vessel_id, "0");
    ASSERT_EQ(accumulator.m_vessels_information[0].vessel_position.yaw.rad,
        vessel_0_position.course_over_ground.rad);
    ASSERT_EQ(accumulator.m_vessels_information[0].vessel_position.latitude.rad,
        vessel_0_position.latitude.rad);
}

TEST_F(VesselInforAccumulatorTest, it_updates_the_vessel_position_with_yaw_and_course)
{
    VesselInfoAccumulator accumulator;
    Position vessel_0_position;
    vessel_0_position.mmsi = 0;
    vessel_0_position.latitude = base::Angle::fromRad(0.1);
    vessel_0_position.longitude = base::Angle::fromRad(0.2);
    vessel_0_position.course_over_ground = base::Angle::fromRad(0.5);
    vessel_0_position.yaw = base::Angle::fromRad(0.4);
    accumulator.updateVesselPosition(vessel_0_position);
    ASSERT_EQ(accumulator.m_vessels_information[0].vessel_id, "0");
    ASSERT_EQ(accumulator.m_vessels_information[0].vessel_position.yaw.rad,
        vessel_0_position.yaw.rad);
    ASSERT_EQ(accumulator.m_vessels_information[0].vessel_position.course_over_ground.rad,
        vessel_0_position.course_over_ground.rad);
    ASSERT_EQ(accumulator.m_vessels_information[0].vessel_position.latitude.rad,
        vessel_0_position.latitude.rad);
}
