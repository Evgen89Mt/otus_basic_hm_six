// Iterator to doubleList

#pragma once 

template<typename T>
class DNode;

template<typename T>
class DoubleList;

template <typename T, typename U>
class DoubleListIterator{
    private:

        DNode<T>* m_node = nullptr;

        template<typename> friend class DoubleList;

        explicit DoubleListIterator(DNode<T>* node);

    public:

        DoubleListIterator() = default;

        U& operator*() const;
        U* operator->() const;

        DoubleListIterator& operator++();
        DoubleListIterator operator++(int);
        DoubleListIterator& operator--();
        DoubleListIterator operator--(int);

        bool operator == (const DoubleListIterator& other) const;
        bool operator != (const DoubleListIterator& other) const;
};

#include "DoubleListIterator.tpp"