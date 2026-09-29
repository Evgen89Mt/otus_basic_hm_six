// Двусвязанный список, построение на Node, next в сторону хвоста, prev в сторону головы

#pragma once

#include<cstddef>
#include"DNode.h"

template<typename T>
class DoubleList{
    private:
    DNode<T>* m_head = nullptr;
    DNode<T>* m_tail = nullptr;
    size_t m_size = 0;

    DNode<T>* node_at(size_t index)const;

    public:

    DoubleList();
    ~DoubleList();

    void push_front(const T& v);
    void push_front(T&& v);

    void push_back(const T& v);
    void push_back(T&& v);

    void pop_front();
    void pop_back();
    void clear();

    size_t size() const;
    bool empty() const;

    T& front();
    const T& front() const;

    T& back();
    const T& back() const;

    T& at(size_t index);
    const T& at(size_t index) const;

    void insert(size_t index, const T& value);
    void insert(size_t index, T&& value);

    void remove(size_t index);
    void swap(size_t i, size_t j);

};


#include"DoubleList.tpp"