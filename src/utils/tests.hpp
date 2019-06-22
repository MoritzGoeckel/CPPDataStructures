#include "utils.hpp"

TEST(Utils, Swap) {
    int a = 10;
    int b = 30;

    mtl::swap(a, b);

    ASSERT_EQ(a, 30);
    ASSERT_EQ(b, 10);
}

//#define PRINT_HASH_RESULTS
TEST(Utils, Hash){
    using uint = unsigned int;

    uint a = 10;
    long b = 123456789123456789;
    double c = 1234.56789123456789;
    size_t d = 123456789123456789;
    size_t e = 123456799123456789;

    #ifdef PRINT_HASH_RESULTS
    uint x = mtl::hash<int, uint>(a);
    std::cout << a << " -> " << x << std::endl;

    x = mtl::hash<long, uint>(b);
    std::cout << b << " -> " << x << std::endl;

    x = mtl::hash<double, uint>(c);
    std::cout << c << " -> " << x << std::endl;

    x = mtl::hash<size_t, uint>(d);
    std::cout << d << " -> " << x << std::endl;

    x = mtl::hash<size_t, uint>(e);
    std::cout << e << " -> " << x << std::endl;
    #endif

    uint h = mtl::hash<uint, uint>(a);
    ASSERT_EQ(h, a);

    h = mtl::hash<long, uint>(b);
    ASSERT_NE(h, b);

    h = mtl::hash<double, uint>(c);
    ASSERT_NE(h, c);

    h = mtl::hash<size_t, uint>(d);
    ASSERT_NE(h, d);

    h = mtl::hash<size_t, uint>(e);
    uint h2 = mtl::hash<size_t, uint>(d);
    ASSERT_NE(h, h2);
}
