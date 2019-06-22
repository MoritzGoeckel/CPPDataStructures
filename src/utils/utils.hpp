#ifndef UTILS_H
#define UTILS_H

namespace mtl{

template<typename K, typename V>
struct Pair{
    Pair(K k, V v){
        key = k;
        value = v;
    }

    K key;
    V value;
};

template<typename K, typename V>
Pair<K,V> makePair(K key, V value){
    return Pair(key, value);
}

template<typename T>
void swap(T& left, T& right){
    T tmp = left;
    left = right;
    right = tmp;
}

// Todo: Hashing of pointer types?

template<typename IN, typename OUT>
OUT hash(const IN& in){
    OUT out = 0;

    using ptr_t = unsigned char*;
    using cptr_t = const unsigned char*;

    if(sizeof(OUT) > sizeof(IN)){
        // Error?
    }

    cptr_t inStart = reinterpret_cast<cptr_t>(&in);
    ptr_t outStart = reinterpret_cast<ptr_t>(&out);

    for(unsigned i = 0u; i < sizeof(IN); i++){
        cptr_t inByte = inStart + i;
        ptr_t outByte = outStart + (i % sizeof(OUT));
        *outByte = *outByte ^ *inByte;
    }

    return out;
}

} // namespace

#endif
