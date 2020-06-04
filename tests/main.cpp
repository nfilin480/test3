#include <gtest/gtest.h>
#include "location_test.h"
#include "archer_test.h"
#include "update_test.h"

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
