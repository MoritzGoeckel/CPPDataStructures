#include "heap.hpp"

struct less {
    bool operator()(const int& a, const int& b) const noexcept {
        return a < b;
    }
};

TEST(Heap, Basic) {
    mtl::Heap<int, less> h;
    h.put(1);
    EXPECT_EQ(h.top(), 1);

    h.put(2);
    EXPECT_EQ(h.top(), 2);

    h.put(10);
    EXPECT_EQ(h.top(), 10);

    h.put(8);
    EXPECT_EQ(h.top(), 10);

    h.put(6);
    EXPECT_EQ(h.top(), 10);

    h.put(20);
    EXPECT_EQ(h.top(), 20);

    EXPECT_EQ(h.pop(), 20);
    EXPECT_EQ(h.pop(), 10);
    EXPECT_EQ(h.pop(), 8);
    EXPECT_EQ(h.pop(), 6);
    EXPECT_EQ(h.pop(), 2);
    EXPECT_EQ(h.pop(), 1);
}
