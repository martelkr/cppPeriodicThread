#include <gtest/gtest.h>

#include "CPeriodicThread.hpp"

#include <iostream>

static void myPeriodicThread(void)
{
    std::cout << "My peeriodic thread" << std::endl;
}

TEST(Basic, SimpleTest)
{
    CPeriodicThread p(myPeriodicThread, 1000);

    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Ending test" << std::endl;

    ASSERT_EQ(true, true);
}

auto main(int argc, char* argv[]) -> int 
{
    std::cout << "Starting tests" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
