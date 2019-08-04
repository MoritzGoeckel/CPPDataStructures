#ifndef BITSET_H
#define BITSET_H

#include "../array/array.hpp"

namespace mtl{

class Bitset {
    private:
    using BucketType = char;

    Array<BucketType> _array;
    size_t _size;

    public:
    class BitRef{
        friend class Bitset;

        private:
        Bitset& _bitset;
        size_t _index;

        BitRef(Bitset& bitset, short index) : _bitset(bitset), _index(index) { }

        public:
        bool operator=(bool value) {
            _bitset.set(_index, value);
            return value;
        }

        bool operator==(const BitRef& rhs) const {
            return (operator bool() == rhs.operator bool());
        }

        operator bool() const {
            return _bitset.get(_index);
        }
    };

    Bitset() : _array(1, 0), _size(0) { }

    void resize(size_t size){
        if(size > capacity()){
            Array<BucketType> array((size / (sizeof(BucketType) * 8)) + 1u, 0);
            // MAYBE: Would be more efficient to init only the not in next line filled parts

            array.fill(_array);
            _array.swap(array);
        }
        _size = size;
    }

    size_t capacity() const noexcept {
         return _array.size() * sizeof(BucketType) * 8u;
    }

    size_t size() const noexcept {
        return _size;
    }

    BitRef operator[](size_t index){
        return BitRef(*this, index);
    }

    #define CreateBucketOffsetMask  const size_t bucket = index / (8 * sizeof(BucketType)); \
                                    const short offset = index % (8 * sizeof(BucketType)); \
                                    const BucketType mask = (1 << offset)

    void set(size_t index, bool value){
        if(index >= _size)
            throw "Index out of bounds";

        CreateBucketOffsetMask;
        _array[bucket] = _array[bucket] | mask;
        // check endianess
    }

    bool get(size_t index) const {
        if(index >= _size)
            throw "Index out of bounds";

        CreateBucketOffsetMask;
        return (_array[bucket] & mask) != 0;
        // check endianess
    }

    void flip(size_t index){
        if(index >= _size)
            throw "Index out of bounds";

        CreateBucketOffsetMask;
        _array[bucket] = _array[bucket] ^ mask;
    }

    bool isZero(){ // Could also cache with numSet
        for(size_t i = 0u; i < _array.size(); ++i){
            if(_array[i] != 0) return false;
        }
        return true;
    }

    // size_t numSet{ } // With caching

    void print() const {
        std::cout << "Bitset(len=" << _size << ", val=";
        for(size_t i = 0u; i < _size; ++i){
            std::cout << (get(i) ? '1' : '0');
        }
        std::cout << ")" << std::endl;
        // TODO: Check endianess
    }

    //Bitset& operator=(const Bitset& rhs) { } // TODO
    //void swap(Bitset& rhs) { }
};

}

#endif
