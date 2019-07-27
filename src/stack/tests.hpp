#include "stack.hpp"
#include "fixed_stack.hpp"

TEST(Stack, Basic) {
    mtl::Stack<int> s;
    EXPECT_EQ(0u, s.size());

    ASSERT_EQ(10, s.capacity());

    for(size_t i = 0u; i <= 100u; ++i){
        if(i != 0u){
            ASSERT_EQ(i - 1, s.peek());
        }

        ASSERT_EQ(i, s.size());
        s.push(i);
        ASSERT_EQ(i + 1, s.size());
    }

    ASSERT_EQ(118u, s.capacity());

    for(size_t i = 100u; i > 0u; --i){
        ASSERT_EQ(s.peek(), i);
        ASSERT_EQ(i + 1, s.size());
        ASSERT_EQ(s.pop(), i);
        ASSERT_EQ(i, s.size()); 
        ASSERT_EQ(false, s.isEmpty()); 
    }

    ASSERT_EQ(s.pop(), 0); // TODO: Why does that not work in the loop?
    ASSERT_EQ(0u, s.size());
    ASSERT_EQ(12u, s.capacity());
    ASSERT_EQ(true, s.isEmpty());
}

TEST(FixedStack, Basic) {
    mtl::FixedStack<int> s(110);
    EXPECT_EQ(0u, s.size());

    ASSERT_EQ(110, s.capacity());

    for(size_t i = 0u; i <= 100u; ++i){
        if(i != 0u){
            ASSERT_EQ(i - 1, s.peek());
        }

        ASSERT_EQ(i, s.size());
        s.push(i);
        ASSERT_EQ(i + 1, s.size());
    }

    ASSERT_EQ(110, s.capacity());

    for(size_t i = 100u; i > 0u; --i){
        ASSERT_EQ(s.peek(), i);
        ASSERT_EQ(i + 1, s.size());
        ASSERT_EQ(s.pop(), i);
        ASSERT_EQ(i, s.size()); 
        ASSERT_EQ(false, s.isEmpty()); 
    }

    ASSERT_EQ(s.pop(), 0); // TODO: Why does that not work in the loop?
    ASSERT_EQ(0u, s.size());
    ASSERT_EQ(110, s.capacity());
    ASSERT_EQ(true, s.isEmpty());
}
