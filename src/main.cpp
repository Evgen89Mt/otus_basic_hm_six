#include <string>
#include <iostream>
#include "NewVector.cpp"

int main(int argc, char* argv[]){

    NewVector<int> vec(20);
    std::cout << "compilite" << std::endl;
    vec.push_back(1);
    vec.push_back(4);
    vec.push_back(100);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);

    for(auto ptr:vec){
        std::cout << ptr << " ";
    }

    std::cout << std::endl;

    vec.reserve(1000);

    std::cout << "size = "<< vec.size() << "; " 
    << "capacity = " << vec.capacity() << std::endl;

    return 0;
}