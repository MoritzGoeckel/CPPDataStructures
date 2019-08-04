#include <iostream>
#include "list.hpp"

TEST(List, Basic) {
    mtl::List<int> list;
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

TEST(List, Iter){
    mtl::List<int> list;
    list.push_back(10);
    list.push_back(11);
    list.push_back(12);
    list.push_back(13);

    auto it = list.begin();
    EXPECT_EQ(*it, 10);
    EXPECT_EQ(false, it == list.end());

    ++it;
    EXPECT_EQ(*it, 11);

    int i = 0;
    for(auto it = list.begin(); it != list.end(); ++it){
        EXPECT_EQ(*it, 10 + i);
        i++;
    }
}
