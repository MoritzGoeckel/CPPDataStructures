#ifndef HEAP_H
#define HEAP_H

#include "../vector/vector.hpp"
#include "../utils/utils.hpp"

namespace mtl {

template<typename T, typename LESS>
class Heap {
    private:
    Vector<T> _vec; // Maybe use vector
    LESS less;

    void siftUp(size_t index){
        size_t parent_index = (index - 1) / 2;
        while(index != 0u){
            if(less(_vec[parent_index], _vec[index])){
                swap(_vec[parent_index], _vec[index]);
            } else {
                break;
            }

            index = parent_index;
            parent_index = (index - 1) / 2;
        }
    }

    void siftDown(size_t index){
        while(index < _vec.size()){
            const size_t left = index * 2 + 1;
            const size_t right = index * 2 + 2;

            size_t childIndex;

            if(left < _vec.size() && right < _vec.size()){
                if(less(_vec[left], _vec[right]))   { childIndex = right;   }
                else                                { childIndex = left;    }
            } else {
                if(left < _vec.size())              { childIndex = left;    }
                else if(right < _vec.size())        { childIndex = right;   }
                else                                { break;                }
            }

            _vec[index] = _vec[childIndex];
            index = childIndex;

            // TODO:
            // if(index > _vec.size()){
            //      delete the just visited entry from array. How?
            // }
        }
    }

    public:
    Heap() : _vec() {}

    void put(T value){
        _vec.push_back(value);
        siftUp(_vec.size()  - 1);
    }

    T top(){
        if(_vec.isEmpty())
            throw "Heap empty";

        return _vec.front();
    }

    T pop(){
        T tmp = _vec.front();
        siftDown(0u);
        return tmp;
    }

};

} // namespace

#endif
