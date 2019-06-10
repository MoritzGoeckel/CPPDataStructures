#include "gtest/gtest.h"
#include <iostream>

#include "list/tests.hpp"

TEST(General, Print) {
	std::cout << "Thats a print" << std::endl;
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
