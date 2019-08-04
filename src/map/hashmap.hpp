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
        List<Pair<K, V>>& list = _array[num];

        for(auto it = list.begin(); it != list.end(); ++it){
            if(it->key == key){
                throw "Key already in map";
            }
        }

        Pair<K,V> pair(key, value);
        list.push_back(pair);
        _size++;

        if(_size > _array.size())
            grow();
    }

    V get(K key) const {
        size_t num = hash(key) % _array.size();
        List<Pair<K, V>>& list = _array[num];

        for(auto it = list.begin(); it != list.end(); ++it){
            if(it->key == key)
                return it->value;
        }

        throw "Key not found";
    }

    void clear(){
        if(capacity() > START_SIZE)
            shrink(START_SIZE);

        _size = 0;
        for(size_t i = 0u; i < _array.size(); i++){
            _array[i].clear();
        }
    }

    size_t size() const noexcept { return _size; }
    size_t capacity() const noexcept { return _array.size(); }

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
