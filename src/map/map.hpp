#ifndef MAP_H
#define MAP_H

#include "../array/array.hpp"
#include "../list/list.hpp"

#define START_SIZE 10
#define GROWTH_RATE 1.3

template<typename K, typename V>
class Map{

    public:
    Map() : _array(START_SIZE), _size(0) { }

    void put(K key, V value){
        size_t num = hash(key) % _array.size(); 
        Pair pair(key, value);
        _array[num].push_back(pair);
        // TODO: Check if list already contains 'key'
        // Contians method in list
        _size++;
    
        if(_size > _array.size())
            grow();
    }

    V get(K key){
        size_t num = hash(key) % _array.size(); 
        List<Pair>& list = _array[num];

        // TODO: Need interator   
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

    ~Map(){ }

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
        if constexpr (sizeof(K) >= sizeof(size_t))
            return *reinterpret_cast<size_t*>(&key);
        if constexpr (sizeof(K) >= sizeof(long))
            return *reinterpret_cast<long*>(&key);
        if constexpr (sizeof(K) >= sizeof(int))
            return *reinterpret_cast<int*>(&key);
        
        return *reinterpret_cast<char*>(&key);
    }

    struct Pair{
        Pair(K k, V v){ 
            key = k; 
            value = v; 
        }

        K key;
        V value;
    };

    Array<List<Pair>> _array;
    size_t _size;
};

#undef START_SIZE
#undef GROWTH_RATE

#endif
