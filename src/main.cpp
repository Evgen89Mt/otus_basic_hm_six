#include <string>
#include <iostream>
#include "NewVector.cpp"

int main(int argc, char* argv[]){

    NewVector<int> vec(10);
    std::cout << "compilite" << std::endl;
    for(size_t i = 0; i < 8; ++i){
        vec.push_back(i);
    }

    std::cout << "view container"<< std::endl;
    for(auto pos:vec){
        std::cout << pos << " ";
    }

    int val = 10;
    vec.insert(0, val);
    vec.insert(8, val);
    vec.insert(9, val);

    std::cout << "view container"<< std::endl;
    for(auto pos:vec){
        std::cout << pos << " ";
    }
    std::cout << std::endl;

    std::cout << "size = "<< vec.size() << "; " 
    << "capacity = " << vec.capacity() << std::endl;

    return 0;
}