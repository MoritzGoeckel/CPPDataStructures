#ifndef FIXED_STACK_H
#define FIXED_STACK_H

namespace mtl {

template<typename T>
class FixedStack{

    public:
    FixedStack(size_t capacity) : _size(0), _capacity(capacity) {
        _array = new T[_capacity];
    }

    ~FixedStack(){
        delete[] _array;
    }

    void push(T value){
        if(_size == _capacity)
            throw "Stack full";

        _array[_size++] = value;
    }

    T pop(){
        if(isEmpty())
            throw "Stack empty";

        return _array[--_size];
    }

    T peek(){
        if(isEmpty())
            throw "Stack empty";

        return _array[_size - 1u];
    }

    bool isEmpty() const noexcept {
        return _size == 0u;
    }

    size_t size() const noexcept {
        return _size;
    }

    size_t capacity() const noexcept {
        return _capacity;
    }

    private:
    T* _array;
    size_t _size;
    size_t _capacity;

};

} // namespace

#endif
