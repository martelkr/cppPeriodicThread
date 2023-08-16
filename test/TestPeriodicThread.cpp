#include <gtest/gtest.h>

#include "CPeriodicThread.hpp"

#include <iostream>

static std::atomic<unsigned int> counter = 0;

static void myPeriodicThread(void)
{
    ++counter;
}

/**
 * @brief A simple 3 second periodic test
 * 
 */
TEST(Basic, SimpleTest)
{
    std::cout << "Start test" << std::endl;
    std::function<void()> f = myPeriodicThread;
    CPeriodicThread p(f, 1000);

    std::this_thread::sleep_for(std::chrono::seconds(3));

    // the 1/s periodic thread should be called 3 times during 3 second sleep
    ASSERT_GE(counter, 3);
    std::cout << "End test" << std::endl;
}

auto main(int argc, char* argv[]) -> int 
{
    std::cout << "Starting tests" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
