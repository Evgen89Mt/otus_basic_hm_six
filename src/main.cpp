#include <string>
#include <iostream>
#include "NewVector.h"
#include "DoubleList.h"

template<typename T>
std::ostream& operator << (std::ostream& os, const NewVector<T>& vec){

    for(const auto& pos:vec){
        os << pos <<' ';
    }

    return os;
}

int main(int argc, char* argv[]){

    NewVector<int> vec(10);
    std::cout << "init vector" << std::endl;
    for(size_t i = 0; i < 10; ++i){
        vec.push_back(i);
    }

    std::cout << "view container\n"<< vec << std::endl;

    vec.erase(3);
    vec.erase(5);
    vec.erase(7);
    std::cout << "view container erase 3,5,7\n"<< vec << std::endl;

    vec.insert(0, 10);
    std::cout << "view container insert pos 0 value 10\n"<< vec << std::endl;

    vec.insert(3, 20);
    std::cout << "view container insert pos 3 value 20\n"<< vec << std::endl;

    vec.push_back(30);
    std::cout << "view container push back value 30\n"<< vec << std::endl;
    std::cout << "size = "<< vec.size() << "; " 
    << "capacity = " << vec.capacity() << std::endl;

    vec.pop_back();
    std::cout << "view container pop back\n"<< vec << std::endl;
    std::cout << "size = "<< vec.size() << "; " 
    << "capacity = " << vec.capacity() << std::endl;

    vec.swap(0,5);
    std::cout << "view container from swap pos 0 and 5\n"<< vec << std::endl;
    std::cout << "size = "<< vec.size() << "; " 
    << "capacity = " << vec.capacity() << std::endl;

    vec.push_back(10);
    vec.push_back(10);
    vec.push_back(10);
    vec.push_back(10);
    std::cout << "view container capacite update\n"<< vec << std::endl;
    std::cout << "size = "<< vec.size() << "; " 
    << "capacity = " << vec.capacity() << std::endl;

    std::cout << "DoubleList push_back" << std::endl;
    DoubleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    std::cout << "view list : ";
    for(size_t i = 0; i < list.size(); i++){
        std::cout << list.at(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
