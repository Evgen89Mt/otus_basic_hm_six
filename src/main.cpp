#include <string>
#include <iostream>

#include "NewVector.h"
#include "DoubleList.h"
#include "SingleList.h"

template<typename T>
std::ostream& operator << (std::ostream& os, const NewVector<T>& vec){

    for(const auto& pos:vec){
        os << pos <<' ';
    }

    return os;
}

template<typename T>
void print(const DoubleList<T>& list){
    for(size_t i = 0; i < list.size(); ++i){
        std::cout << list.at(i) << " ";
    }

    std::cout << std::endl;
}

template<typename T>
void print(const SingleList<T>& list){
    for(size_t i = 0; i < list.size(); ++i){
        std::cout << list.at(i) << " ";
    }

    std::cout << std::endl;
}

int main(int argc, char* argv[]){

    NewVector<int> vec(10);
    std::cout << "------------------------------------------------------" << std::endl;
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

    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "DoubleList push_back" << std::endl;
    DoubleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    std::cout << "view double list : ";
    print(list);

    std::cout << "push_front" << std::endl;
    list.push_front(0);
    print(list);

    std::cout << "front = " << list.front()
              << ", back = " << list.back()
              << ", size = " << list.size()
              << ", empty = " << (list.empty() ? "yes" : "no") << "\n";

    std::cout << "at(2) = " << list.at(2) << "\n";

    std::cout << "pop_front: ";
    list.pop_front();
    print(list);

    std::cout << "pop_back: ";
    list.pop_back();
    print(list);

    std::cout << "insert(1, 99): ";
    list.insert(1, 99);
    print(list);

    std::cout << "remove(0): ";
    list.remove(0);
    print(list);

    std::cout << "swap(0, size-1): ";
    list.swap(0, list.size() - 1);
    print(list);

    std::cout << "after clear: ";
    list.clear();
    print(list);
    std::cout << "size = " << list.size()
              << ", empty = " << (list.empty() ? "yes" : "no") << "\n";


     std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "SingleList push_back" << std::endl;
    SingleList<int> slist;
    slist.push_back(1);
    slist.push_back(2);
    slist.push_back(3);
    slist.push_back(4);
    slist.push_back(5);

    std::cout << "view single list : ";
    print(slist);

    std::cout << "push_front 0: ";
    slist.push_front(0);
    print(slist);

    std::cout << "front = " << slist.front()
              << ", back = " << slist.back()
              << ", size = " << slist.size()
              << ", empty = " << (slist.empty() ? "yes" : "no") << "\n";

    std::cout << "at(2) = " << slist.at(2) << "\n";

    std::cout << "pop_front: ";
    slist.pop_front();
    print(slist);

    std::cout << "insert(1, 500): ";
    slist.insert(1, 500);
    print(slist);

    std::cout << "insert(100, 200) -> push_back: ";
    slist.insert(100, 200);
    print(slist);

    std::cout << "remove(1): ";
    slist.remove(1);
    print(slist);

    std::cout << "swap(0, size-1): ";
    slist.swap(0, slist.size() - 1);
    print(slist);

    std::cout << "after clear: ";
    slist.clear();
    print(slist);
    std::cout << "size = " << slist.size()
              << ", empty = " << (slist.empty() ? "yes" : "no") << "\n";

    return 0;
}
