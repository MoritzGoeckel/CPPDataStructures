#include "bitset.hpp"

TEST(Bitset, Basic) {
    mtl::Bitset b;
    EXPECT_EQ(0u, b.size());

    b.resize(4);
    EXPECT_EQ(4u, b.size());

    b[0] = true;

    EXPECT_EQ(4u, b.size());
    EXPECT_EQ(true, b[0]);
    EXPECT_EQ(false, b[1]);
    EXPECT_EQ(false, b[2]);
    EXPECT_EQ(false, b[3]);

    b[2] = true;

    EXPECT_EQ(true, b[0]);
    EXPECT_EQ(false, b[1]);
    EXPECT_EQ(true, b[2]);
    EXPECT_EQ(false, b[3]);

    bool bl = b[1];
    EXPECT_EQ(false, bl);

    bl = b[2];
    EXPECT_EQ(true, bl);

    EXPECT_EQ(b[1], b[3]);
    EXPECT_EQ(b[0], b[2]);

    EXPECT_EQ(false, b[1]);
    b.flip(1);

    EXPECT_EQ(true, b[0]);
    EXPECT_EQ(true, b[1]);
    EXPECT_EQ(true, b[2]);
    EXPECT_EQ(false, b[3]);

    b.resize(5);

    EXPECT_EQ(true, b[0]);
    EXPECT_EQ(true, b[1]);
    EXPECT_EQ(true, b[2]);
    EXPECT_EQ(false, b[3]);
    EXPECT_EQ(false, b[4]);
}

TEST(Bitset, Resize) {
    mtl::Bitset b;
    EXPECT_EQ(0u, b.size());
    EXPECT_EQ(8u, b.capacity());
    EXPECT_EQ(true, b.isZero());
    b.resize(4);
    EXPECT_EQ(4u, b.size());
    EXPECT_EQ(8u, b.capacity());
    EXPECT_EQ(true, b.isZero());
    b.resize(5);
    EXPECT_EQ(5u, b.size());
    EXPECT_EQ(8u, b.capacity());
    EXPECT_EQ(true, b.isZero());
    b.resize(10);
    EXPECT_EQ(10u, b.size());
    EXPECT_EQ(16u, b.capacity());
    EXPECT_EQ(true, b.isZero());

    b[3] = true;
    EXPECT_EQ(false, b.isZero());
}
