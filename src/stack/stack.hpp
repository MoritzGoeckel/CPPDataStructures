#ifndef STACK_H
#define STACK_H

#include "../vector/vector.hpp"

namespace mtl{

template<typename T>
class Stack{

    public:
    Stack() : _vec() {}

    void push(T value){
        _vec.push_back(value); 
    }

    T pop(){
        return _vec.pop_back();
    }

    T peek() const {
        return _vec.back();
    }

    size_t size() const noexcept {
        return _vec.size();
    }

    size_t capacity(){
        return _vec.capacity();
    }

    bool isEmpty() const noexcept {
        return _vec.isEmpty();
    }

    void print() const {
        _vec.print();
    }

    ~Stack() {}

    private:
    Vector<T> _vec;
};

} // namespace

#endif
