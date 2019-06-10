#include "map.hpp"

TEST(Map, Basic) {
    Map<int, int> m;

    m.put(10, 14);
    m.put(11, 17);
    m.put(12, 18);
    m.put(1,  18);

    ASSERT_EQ(m.get(10), 14);
    ASSERT_EQ(m.get(11), 17);
    ASSERT_EQ(m.get(12), 18);
    ASSERT_EQ(m.get(1),  18);
}
