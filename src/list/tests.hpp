#include <iostream>
#include "list.hpp"

TEST(List, Basic) {
	List<int> list;
	list.push_front(10);
	list.push_front(12);
	list.push_front(14);
	list.push_front(15);

    ASSERT_EQ(14, list.at(1));
    ASSERT_EQ(10, list.back());

    ASSERT_EQ(15, list.at(0));
    ASSERT_EQ(15, list.front());
    
    list.remove(0);
    ASSERT_EQ(14, list.front());

    list.remove(1);
    ASSERT_EQ(14, list.front());

    list.push_back(18);
    ASSERT_EQ(14, list.front());
    ASSERT_EQ(18, list.back());
}
