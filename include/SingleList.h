// Односвязный список

#pragma once
#include<cstddef>
#include "Node.h"

template<typename T>
class SingleList{
    private:
        Node<T>* m_head = nullptr;
        Node<T>* m_tail = nullptr;
        size_t   m_size = 0;

        Node<T>* node_at(size_t index) const;

    public:
        SingleList();
        ~SingleList();

        void push_front(const T& v);
        void push_front(T&& v);

        void push_back(const T& v);
        void push_back(T&& v);

        void pop_front();
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
        void insert(size_t index, T&&);

        void remove(size_t index);
        void swap(size_t i, size_t j);
};

#include"SingleList.tpp"