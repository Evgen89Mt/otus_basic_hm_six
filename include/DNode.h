// Нод для двусвязанного списка

#pragma once

template<typename T>
class DNode{
    public:
    T value;
    DNode* prev;
    DNode* next;

    explicit DNode(const T& v);
    explicit DNode(T&& v);

};

#include"DNode.tpp"