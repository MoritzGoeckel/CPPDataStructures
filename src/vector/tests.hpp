#include "vector.hpp"

TEST(Vector, Basic) {
    Vector<int> v;
    EXPECT_EQ(10u, v.capacity());
    EXPECT_EQ(0u, v.size());

    v.push_back(10);
    EXPECT_EQ(1u, v.size());
}

TEST(Vector, Grow) {
    const int nums = 100;

    Vector<int> v;

    for(int i = 0; i < nums; i++)
        v.push_back(i); 

    for(int i = 0; i < nums; i++)
        EXPECT_EQ(i, v[i]); 
}

TEST(Vector, Clear) {
    Vector<int> v;
    for(int i = 0; i < 100; i++)
       v.push_back(i); 

    ASSERT_EQ(100u, v.size());
    ASSERT_GT(v.capacity(), v.size());

    v.clear(); 
    ASSERT_EQ(0u, v.size());
    ASSERT_EQ(10u, v.capacity());
}

TEST(Vector, Insert) {
    Vector<int> v;

    for(int i = 0; i < 118; i++)
       v.push_back(i); 

    ASSERT_EQ(118u, v.size());
    ASSERT_EQ(118, v.capacity());

    v.insert(999, 40);

    ASSERT_EQ(999, v[40]);
    ASSERT_EQ(39, v[39]);
    ASSERT_EQ(40, v[41]);
    ASSERT_EQ(41, v[42]);

    EXPECT_EQ(119u, v.size());
}

TEST(Vector, FrontBack) {
    Vector<int> v;

    for(int i = 0; i < 100; i++)
       v.push_back(i); 

    ASSERT_EQ(0, v.front());
    ASSERT_EQ(99, v.back());
}
