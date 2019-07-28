#include "gtest/gtest.h"

#include "list/tests.hpp"
#include "array/tests.hpp"
#include "vector/tests.hpp"
#include "map/tests.hpp"
#include "utils/tests.hpp"
#include "stack/tests.hpp"
#include "queue/tests.cpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
