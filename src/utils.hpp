#ifndef UTILS_H
#define UTILS_H

namespace utils{

template<typename T>
void swap(T& left, T& right){
    T tmp = left;
    left = right;
    right = tmp;
}

}

#endif
