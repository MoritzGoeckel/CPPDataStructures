#ifndef ARRAY_H
#define ARRAY_H

#include "../utils/utils.hpp"

namespace mtl{

template<typename T>
class Array{
    public:

    Array(size_t size) : _size(size), _array(new T[size]) {}

    Array(size_t size, T value) : _size(size), _array(new T[size]) {
        for(size_t i = 0u; i < size; ++i){
            _array[i] = value;
        }
    }

    size_t size() const noexcept {
        return _size;
    }

    T& operator[](size_t index) const {
        if(index >= _size)
            throw "Index out of bounds";

        return _array[index];
    }

    void fill(const Array<T>& other){
        for(size_t i = 0u; i < _size && i < other._size; ++i)
            _array[i] = other._array[i];
    }

    Array<T>& swap(Array<T>& other){
        mtl::swap(_array, other._array);
        mtl::swap(_size, other._size);

        return *this;
    }

    Array<T>& operator=(Array<T>& other) = delete;

    ~Array(){
        delete[] _array;
        _array = nullptr;
    }

    void print() const {
        std::cout << "Array(len=" << _size << ", val=";
        for(size_t i = 0u; i < _size; ++i){
            std::cout << _array[i] << ", ";
        }
        std::cout << ")" << std::endl;
    }

    private:
    size_t _size;
    T* _array;
};

} // namespace

#endif
