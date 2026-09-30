#pragma once

template<typename T>
class Node{
    public:
        T value;
        Node* next;

        explicit Node(const T&);
        explicit Node(T&&);
};

#include"Node.tpp"