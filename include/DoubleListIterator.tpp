#pragma once
#include "DoubleListIterator.h"
#include "DNode.h"

template<typename T, typename U>
DoubleListIterator<T, U>::DoubleListIterator(DNode<T>* node)
    :m_node(node)
{}

template<typename T, typename U>
U& DoubleListIterator<T, U>::operator*() const{
    return m_node->value;
}

template<typename T, typename U>
U* DoubleListIterator<T, U>::operator->() const{
    return &m_node->value;
}

template<typename T, typename U>
DoubleListIterator<T, U>& DoubleListIterator<T, U>::operator++(){
    m_node = m_node->next;
    return *this;
}

template<typename T, typename U>
DoubleListIterator<T, U> DoubleListIterator<T, U>::operator++(int){
    DoubleListIterator tmp = *this;
    ++(*this);
    return tmp;
}

template<typename T, typename U>
DoubleListIterator<T, U>& DoubleListIterator<T, U>::operator--(){
    m_node = m_node->prev;
    return *this;
}

template<typename T, typename U>
DoubleListIterator<T, U> DoubleListIterator<T, U>::operator--(int){
    DoubleListIterator tmp = *this;
    --(*this);
    return tmp;
}

template<typename T, typename U>
bool DoubleListIterator<T, U>::operator == (const DoubleListIterator& other) const{
    return m_node == other.m_node;
}

template<typename T, typename U>
bool DoubleListIterator<T, U>::operator != (const DoubleListIterator& other) const{
    return m_node != other.m_node;
}