#include "gtest/gtest.h"

//empty for now
class WorldTest : public ::testing::Test {};

int main(int argc, char**argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}