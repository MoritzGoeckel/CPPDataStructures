#include "array.hpp"

TEST(Array, Basic) {
    Array<int> a(10);
    ASSERT_EQ(10u, a.size());
   
    a[3] = 99; 
    ASSERT_EQ(99, a[3]);
}
