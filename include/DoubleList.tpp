#pragma once
#include"DoubleList.h"

template<typename T>
DNode<T>* DoubleList<T>::node_at(size_t index)const{
    DNode<T>* cur = m_head;

    for(size_t i = 0; i < index; ++i){
        cur = cur->next;
    }

    return cur;
}

template<typename T>
DoubleList<T>::DoubleList(){}

template<typename T>
DoubleList<T>::~DoubleList(){
    clear();
}

template<typename T>
void DoubleList<T>::push_front(const T& v){
    DNode<T>* node = new DNode<T>(v);

    node->next = m_head;

    if(m_head){
        m_head->prev = node;
    }else{
        m_tail = node;
    }

    m_head = node;
    ++m_size;
}

template<typename T>
void DoubleList<T>::push_front(T&& v){
    DNode<T>* node = new DNode<T>(static_cast<T&&>(v));

    node->next = m_head;

    if(m_head){
        m_head->prev = node;
    }else{
        m_tail = node;
    }

    m_head = node;
    ++m_size;
}

template<typename T>
void DoubleList<T>::push_back(const T& v){
    DNode<T>* node = new DNode<T>(v);

    node->prev = m_tail;

    if(m_tail){
        m_tail->next = node;
    }else{
        m_head = node;
    }

    m_tail = node;
    ++m_size;
}

template<typename T>
void DoubleList<T>::push_back(T&& v){
    DNode<T>* node = new DNode<T>(static_cast<T&&>(v));

    node->prev = m_tail;

    if(m_tail){
        m_tail->next = node;
    }else{
        m_head = node;
    }

    m_tail = node;
    ++m_size;
}

template<typename T>
void DoubleList<T>::pop_front(){
    if (!m_head){
        return;
    }

    DNode<T>* node = m_head;
    m_head = m_head->next;

    if (m_head){ 
        m_head->prev = nullptr;
    }else{       
        m_tail = nullptr;
    }

    delete node;
    --m_size;
}

template<typename T>
void DoubleList<T>::pop_back(){
    if(!m_tail){
        return;
    }

    DNode<T>* node = m_tail;
    m_tail = m_tail->prev;

    if(m_tail){
        m_tail->next = nullptr;
    }else{
        m_head = nullptr;
    }

    delete node;
    --m_size;
}

template<typename T>
void DoubleList<T>::clear(){
    for(DNode<T>* current = m_head; current;){
        DNode<T>* next = current->next;
        delete current;
        current = next;
    }
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

template<typename T>
size_t DoubleList<T>::size() const{
    return m_size;
}

template<typename T>
bool DoubleList<T>::empty() const{
    return (m_size == 0);
}

template<typename T>
T& DoubleList<T>::front(){
    return m_head->value;
}

template<typename T>
const T& DoubleList<T>::front() const{
    return m_head->value;
}

template<typename T>
T& DoubleList<T>::back(){
    return m_tail->value;
}

template<typename T>
const T& DoubleList<T>::back() const{
    return m_tail->value;
}

template<typename T>
T& DoubleList<T>::at(size_t index){
    return node_at(index)->value;
}

template<typename T>
const T& DoubleList<T>::at(size_t index) const{
    return node_at(index)->value; 
}

template<typename T>
void DoubleList<T>::insert(size_t index, const T& value){
    if (index == 0) {
        push_front(value);
        return;
    }
    if (index >= m_size) {
        push_back(value);
        return;
    }

    DNode<T>* rigth = node_at(index);
    DNode<T>* left = rigth->prev;

    DNode<T>* node = new DNode<T>(value);
    node->prev = left;
    node->next = rigth;

    left->next = node;
    rigth->prev = node;

    ++m_size;
}

template<typename T>
void DoubleList<T>::insert(size_t index, T&& value){
        if (index == 0) {
        push_front(static_cast<T&&>(value));
        return;
    }
    if (index >= m_size) {
        push_back(static_cast<T&&>(value));
        return;
    }

    DNode<T>* rigth = node_at(index);
    DNode<T>* left = rigth->prev;

    DNode<T>* node = new DNode<T>(static_cast<T&&>(value));
    node->prev = left;
    node->next = rigth;

    left->next = node;
    rigth->prev = node;

    ++m_size;
}

template<typename T>
void DoubleList<T>::remove(size_t index){
    if(index >= m_size){
        return;
    }

    if(index == 0){
        pop_front();
        return;
    }

    if(index == m_size - 1){
        pop_back();
        return;
    }

    DNode<T>* node = node_at(index);
    node->prev->next = node->next;
    node->next->prev = node->prev;

    delete node;
    --m_size;
}

template<typename T>
void DoubleList<T>::swap(size_t i, size_t j){
    if (i == j) {
        return;
    }
    if(i >= m_size || j >= m_size){ 
        return;
    }

    DNode<T>* a = node_at(i);
    DNode<T>* b = node_at(j);

    T tmp = static_cast<T&&>(a->value);

    a->value = static_cast<T&&>(b->value);
    b->value = static_cast<T&&>(tmp);
}

