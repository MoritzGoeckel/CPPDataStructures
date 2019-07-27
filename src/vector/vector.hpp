#ifndef VECTOR_H
#define VECTOR_H

#include "../array/array.hpp"

#define MINIMUM_SIZE 10
#define GROWTH_RATE 1.3
#define SHRINK_THRESHOLD 0.7

namespace mtl{

template<typename T>
class Vector{

    public:
    Vector() : _array(MINIMUM_SIZE), _size(0) {}

    // TODO: Iterator

    size_t size() const noexcept {
        return _size;
    }

    bool isEmpty() const noexcept {
        return _size == 0u;
    }

    size_t capacity() const noexcept{
        return _array.size();
    }

    void push_back(T value){
        if(_size >= capacity())
            grow();

        _array[_size++] = value;
    }

    T pop_back(){
        T result = _array[--_size];
        if(_size <= capacity() * SHRINK_THRESHOLD && _size >= MINIMUM_SIZE)
            shrink(_size);

        return result;
    }

    void push_front(T value){
        insert(value, 0u);
    }

    T& operator[](size_t index) const {
        if(index >= _size)
            throw "Index out of bounds";

        return _array[index];
    }

    T& front() const { return operator[](0u); }

    T& back() const { return operator[](_size - 1); }

    void clear(){
        if(capacity() > MINIMUM_SIZE)
            shrink(MINIMUM_SIZE);

        _size = 0u;
    }

    void insert(T value, size_t index){
        if(index > _size)
            throw "Index out of bounds";

        if(capacity() < _size + 1)
            grow();

        // Shift them all back
        for(size_t i = _size - 1; i >= index; i--)
            _array[i + 1]  = _array[i];

        _array[index] = value;

        _size++;
    }

    // TODO:
    //void erase(size_t index){ }

    void shrink(size_t nSize){
        if(nSize > _size)
            throw "Cant expand size by calling shrink";

        resize(nSize);
    }

    void reserve(size_t nSize){
        if(nSize < _size)
            throw "Cant shrink size by calling reserve";

        resize(nSize);
    }

    void print() const {
        std::cout << "Size: " << _size << std::endl;
        for(size_t i = 0u; i < _size; i++)
            std::cout << _array[i] << std::endl;
    }

    ~Vector() {}

    private:
    Array<T> _array;
    size_t _size;

    void grow(){ reserve(capacity() * GROWTH_RATE); }

    void resize(size_t nSize){
        Array<T> nArray(nSize);
        nArray.fill(_array);
        _array.swap(nArray);
    }
};

} // namespace

#undef MINIMUM_SIZE
#undef GROWTH_RATE
#undef SHRINK_THRESHOLD

#endif
