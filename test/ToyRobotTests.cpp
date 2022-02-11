#ifndef _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#endif // !_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING

#include "ToyRobot.cpp"
#include <gtest/gtest.h>
class ToyRobotFixture : public ::testing::Test
{
public:
	ToyRobotFixture() {}
	~ToyRobotFixture() {}

	ToyRobot* sut = new ToyRobot();
};

TEST_F(ToyRobotFixture, n)
{
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}
