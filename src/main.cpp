#include <string>
#include <iostream>
#include "NewVector.cpp"

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
    for(size_t i = 0; i < 8; ++i){
        vec.push_back(i);
    }

    std::cout << "view container\n"<< vec << std::endl;

    int val = 10;
    vec.insert(0, val);
    vec.insert(8, val);
    vec.insert(9, val);
    vec.insert(11, 30);

    std::cout << "view container\n"<< vec << std::endl;
    std::cout << "size = "<< vec.size() << "; " 
    << "capacity = " << vec.capacity() << std::endl;

    vec.erase(4);
    vec.erase(1);

    std::cout << "view container from erase pos 1 and 4\n"<< vec << std::endl;
    std::cout << "size = "<< vec.size() << "; " 
    << "capacity = " << vec.capacity() << std::endl;

    vec.swap(0,5);

    std::cout << "view container from swap pos 0 and 5\n"<< vec << std::endl;
    std::cout << "size = "<< vec.size() << "; " 
    << "capacity = " << vec.capacity() << std::endl;

    return 0;
}
