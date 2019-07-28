#include "queue.hpp"

TEST(Queue, Basic) {
    mtl::Queue<int> q;

    q.enqueue(1);
    ASSERT_EQ(q.front(), 1);
    ASSERT_EQ(q.size(), 1);

    q.enqueue(2);
    ASSERT_EQ(q.size(), 2);

    q.enqueue(3);
    ASSERT_EQ(q.size(), 3);

    q.enqueue(4);
    ASSERT_EQ(q.size(), 4);

    q.enqueue(5);
    ASSERT_EQ(q.size(), 5);

    ASSERT_EQ(q.front(), 1);

    ASSERT_EQ(q.dequeue(), 1);
    ASSERT_EQ(q.dequeue(), 2);
    ASSERT_EQ(q.dequeue(), 3);
    ASSERT_EQ(q.dequeue(), 4);
    ASSERT_EQ(q.dequeue(), 5);
}

TEST(Queue, MoreComplex) {
    mtl::Queue<int> q;

    q.enqueue(1);
    ASSERT_EQ(q.front(), 1);
    ASSERT_EQ(q.size(), 1);

    ASSERT_EQ(q.dequeue(), 1);
    ASSERT_EQ(q.size(), 0u);

    q.enqueue(2);
    ASSERT_EQ(q.front(), 2);
    ASSERT_EQ(q.size(), 1u);

    q.enqueue(3);
    ASSERT_EQ(q.front(), 2);
    ASSERT_EQ(q.size(), 2u);

    q.enqueue(4);
    ASSERT_EQ(q.front(), 2);
    ASSERT_EQ(q.size(), 3u);

    ASSERT_EQ(q.dequeue(), 2);
    ASSERT_EQ(q.front(), 3);
    ASSERT_EQ(q.size(), 2u);

    q.enqueue(5);
    ASSERT_EQ(q.front(), 3);
    ASSERT_EQ(q.size(), 3u);

    ASSERT_EQ(q.isEmpty(), false);

    ASSERT_EQ(q.dequeue(), 3);
    ASSERT_EQ(q.dequeue(), 4);
    ASSERT_EQ(q.dequeue(), 5);

    ASSERT_EQ(q.isEmpty(), true);

    try{
        q.dequeue();
        FAIL();
    }
    catch(...){ }
}

TEST(Queue, Many) {
    mtl::Queue<int> q;

    for(size_t i = 1u; i < 70u; i++){
        q.enqueue(i);
        ASSERT_EQ(q.front(), 1);
        ASSERT_EQ(q.size(), i);
    }

    for(size_t i = 1u; i < 50u; i++){
        ASSERT_EQ(q.front(), i);
        ASSERT_EQ(q.dequeue(), i);
        ASSERT_EQ(q.size(), 69u - i);
    }

    for(size_t i = 1u; i < 50u; i++){
        q.enqueue(i);
        ASSERT_EQ(q.size(), i + 20u);
    }

    for(size_t i = 0u; i < 20; i++){
        ASSERT_EQ(q.front(), 50 + i);
        ASSERT_EQ(q.dequeue(), 50 + i);
        ASSERT_EQ(q.size(), 68 - i);
    }

    for(size_t i = 1u; i < 50; i++){
        q.dequeue();
    }
}

TEST(Queue, Many2) {
    mtl::Queue<int> q;

    for(size_t i = 1u; i < 70u; i++){
        q.enqueue(i);
        ASSERT_EQ(q.front(), 1);
        ASSERT_EQ(q.size(), i);
    }

    for(size_t i = 1u; i < 70u; i++){
        ASSERT_EQ(q.front(), i);
        ASSERT_EQ(q.dequeue(), i);
        ASSERT_EQ(q.size(), 69 - i);
    }
}
