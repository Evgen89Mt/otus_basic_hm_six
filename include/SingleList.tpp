#pragma once
#include"SingleList.h"

template<typename T>
Node<T>* SingleList<T>::node_at(size_t index) const {
    Node<T>* cur = m_head;

    for (size_t i = 0; i < index; ++i) {
        cur = cur->next;
    }

    return cur;
}

template<typename T>
SingleList<T>::SingleList()
{}

template<typename T>
SingleList<T>::~SingleList(){
    clear();
}

template<typename T>
void SingleList<T>::push_front(const T& v){
    Node<T>* node = new Node<T>(v);
    node->next = m_head;
    m_head = node;

    if(!m_tail){
        m_tail = node;
    }

    ++m_size;
}

template<typename T>
void SingleList<T>::push_front(T&& v){
    Node<T>* node = new Node<T>(static_cast<T&&>(v));
    node->next = m_head;
    m_head = node;

    if(!m_tail){
        m_tail = node;
    }

    ++m_size;
}

template<typename T>
void SingleList<T>::push_back(const T& v){
    Node<T>* node = new Node<T>(v);

    if(m_tail){
        m_tail->next = node;
    }else{
        m_head = node;
    }

    m_tail = node;
    ++m_size;
}

template<typename T>
void SingleList<T>::push_back(T&& v){
    Node<T>* node = new Node<T>(static_cast<T&&>(v));
    if(m_tail){
        m_tail->next = node;
    }else{
        m_head = node;
    }

    m_tail = node;
    ++m_size;
}

template<typename T>
void SingleList<T>::pop_front(){
    if(!m_head){
        return;
    }

    Node<T>* node = m_head;
    m_head = m_head->next;

    if(!m_head){
        m_tail = nullptr;
    }

    delete node;
    --m_size;
}

template<typename T>
void SingleList<T>::clear(){
    for(Node<T>* current = m_head; current;){
        Node<T>* next = current->next;
        delete current;
        current = next;
    }

    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

template<typename T>
size_t SingleList<T>::size() const{
    return m_size;
}

template<typename T>
bool SingleList<T>::empty() const{
    return m_size == 0;
}

template<typename T>
T& SingleList<T>::front(){
    return m_head->value;
}

template<typename T>
const T& SingleList<T>::front() const{
    return m_head->value;
}

template<typename T>
T& SingleList<T>::back(){
    return m_tail->value;
}

template<typename T>
const T& SingleList<T>::back() const{
    return m_tail->value;
}

template<typename T>
T& SingleList<T>::at(size_t index){
    return node_at(index)->value;
}

template<typename T>
const T& SingleList<T>::at(size_t index) const{
    return node_at(index)->value;
}

template<typename T>
void SingleList<T>::insert(size_t index, const T& value){
    if (index == 0) {
        push_front(value);
        return;
    }
    if (index >= m_size) {
        push_back(value);
        return;
    }

    Node<T>* left  = node_at(index - 1);
    Node<T>* right = left->next;

    Node<T>* node = new Node<T>(value);
    node->next = right;
    left->next = node;

    ++m_size;
}

template<typename T>
void SingleList<T>::insert(size_t index, T&& value){
    if (index == 0) {
        push_front(static_cast<T&&>(value));
        return;
    }
    if (index >= m_size) {
        push_back(static_cast<T&&>(value));
        return;
    }

    Node<T>* left  = node_at(index - 1);
    Node<T>* right = left->next;

    Node<T>* node = new Node<T>(static_cast<T&&>(value));
    node->next = right;
    left->next = node;

    ++m_size;
}

template<typename T>
void SingleList<T>::remove(size_t index){
    if (index >= m_size) {
        return;
    }

    if (index == 0) {
        pop_front();
        return;
    }

    Node<T>* left = node_at(index - 1);
    Node<T>* node = left->next;

    left->next = node->next;

    if (node == m_tail) {
        m_tail = left;
    }

    delete node;
    --m_size;
}

template<typename T>
void SingleList<T>::swap(size_t i, size_t j){
    if (i == j) {
        return;
    }
    
    if (i >= m_size || j >= m_size){
        return;
    }

    Node<T>* a = node_at(i);
    Node<T>* b = node_at(j);

    T tmp = static_cast<T&&>(a->value);
    a->value = static_cast<T&&>(b->value);
    b->value = static_cast<T&&>(tmp);
}