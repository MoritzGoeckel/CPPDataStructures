#include <iostream>
#include "list.hpp"

int main(){
    List<int> list;
    list.push_front(10);
    list.push_front(15);

    std::cout << list.front() << std::endl;
    std::cout << list.at(1) << std::endl;
}
