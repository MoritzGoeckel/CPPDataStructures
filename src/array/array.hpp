#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdlib.h>

template<typename T>
class Array{
    public:

    Array(size_t size) : _size(size), _array(new T[size]) {}

    size_t size(){
        return _size;
    }

    T& operator[](size_t index) {
        if(index >= _size)
            throw "Index out of bounds";

        return _array[index];     
    }

    void fill(const Array<T>& other){
        for(size_t i = 0u; i < _size && i < other._size; i++)
            _array[i] = other._array[i];
    }

    Array<T>& swap(Array<T>& other){
        T* tmpArray = _array;
        size_t tmpSize = _size;

        _array = other._array;
        _size = other._size;

        other._array = tmpArray;
        other._size = tmpSize;

        return *this;
    }

    ~Array(){
        delete[] _array;
        _array = nullptr;
    }

    private:
    size_t _size;
    T* _array;
};

#endif
