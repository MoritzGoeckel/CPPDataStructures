#ifndef HASHMAP_H
#define HASHMAP_H

#include "../array/array.hpp"
#include "../list/list.hpp"
#include "../utils/utils.hpp"

#define START_SIZE 10
#define GROWTH_RATE 1.3

// TODO: Iterator

namespace mtl{

template<typename K, typename V>
class HashMap{

    public:
    HashMap() : _array(START_SIZE), _size(0) { }

    void put(K key, V value){
        size_t num = hash(key) % _array.size();
        Pair<K,V> pair(key, value);
        _array[num].push_back(pair);
        // TODO: Check if list already contains 'key'
        // Contians method in list
        _size++;

        if(_size > _array.size())
            grow();
    }

    V get(K key){
        size_t num = hash(key) % _array.size();
        List<Pair<K, V>>& list = _array[num];

        // TODO: Very inefficient! Need interator
        for(size_t i = 0u; i < list.size(); i++)
            if(list[i].key == key)
                return list[i].value;

        throw "Key not found";
    }

    void clear(){
        if(capacity() > START_SIZE)
            shrink(START_SIZE);

        _size = 0;
        // TODO: Clear array
    }

    size_t size(){ return _size; }
    size_t capacity() { return _array.size(); }

    ~HashMap(){ }

    void reserve(size_t nSize){
        if(nSize <= _size)
            throw "reserve can only grow the size";

        resize(nSize);
    }

    void shrink(size_t nSize){
        if(nSize >= _size)
            throw "shrink can only reduce the size";

        resize(nSize);
    }

    private:

    void grow(){
        resize(_size * GROWTH_RATE);
    }

    void resize(size_t nSize){
        // TODO
    }

    static size_t hash(K key){
        return mtl::hash<K, size_t>(key);
    }

    Array<List<Pair<K,V>>> _array;
    size_t _size;
};

} // namespace

#undef START_SIZE
#undef GROWTH_RATE

#endif
