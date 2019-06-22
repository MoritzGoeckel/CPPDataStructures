#include "array.hpp"

TEST(Array, Basic) {
    mtl::Array<int> a(10);
    ASSERT_EQ(10u, a.size());

    a[3] = 99;
    ASSERT_EQ(99, a[3]);
}

TEST(Array, Fill) {
    mtl::Array<int> a(30);
    for(int i = 0; i < 30; i++) a[i] = i;

    mtl::Array<int> b(40);
    b.fill(a);

    for(size_t i = 0u; i < 30; i++)
        ASSERT_EQ(static_cast<int>(i), b[i]);
}
