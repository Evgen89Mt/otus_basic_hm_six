#pragma once
#include"NewVector.h"

template<typename T>
void NewVector<T>::deallocate(T* ptr){
     ::operator delete(ptr);
}

template<typename T>
T* NewVector<T>::allocate(size_t capacity){
    if(capacity == 0){
        return nullptr;
    }

    return static_cast<T*>(::operator new(capacity * sizeof(T)));
}

template<typename T>
void NewVector<T>::reallocate(size_t capacity){

    if(capacity == 0){
         destroy();
         return;
    }

    T* newData = allocate(capacity);

    for(size_t i = 0; i < m_size; ++i){
        new(&newData[i]) T(m_data[i]);  
        m_data[i].~T();                 
    }

    deallocate(m_data);
    m_data = newData;
    m_capacity = capacity;
}

template<typename T>
void NewVector<T>::clear(){
    if(!m_data){
        return;
    }

    for(size_t i = 0; i < m_size; ++i){
        m_data[i].~T();
    }
    m_size = 0;
}

template<typename T>
void NewVector<T>::destroy(){
    clear();
    deallocate(m_data);
    m_data = nullptr;
    m_capacity = 0;
}


template<typename T>
NewVector<T>::NewVector()
    :m_data(nullptr)
    ,m_size(0)
    ,m_capacity(0)
{}

template<typename T>
NewVector<T>::NewVector(size_t capacity) 
    :m_data(allocate(capacity))
    ,m_size(0)
    ,m_capacity(capacity)
{}

template<typename T>
NewVector<T>::NewVector(const NewVector& other)
    :m_data(allocate(other.m_capacity))
    ,m_size(other.m_size)
    ,m_capacity(other.m_capacity)
{
    for(size_t i = 0; i < m_size; ++i){
        new(&m_data[i]) T(other.m_data[i]);
    }
}

template<typename T>
NewVector<T>::NewVector(NewVector&& other)
    :m_data(other.m_data)
    ,m_size(other.m_size)
    ,m_capacity(other.m_capacity)
{
    other.m_data = nullptr;
    other.m_size = 0;
    other.m_capacity = 0;
}

template<typename T>
NewVector<T>::~NewVector()
{
    destroy();
}
    

template<typename T>
NewVector<T>& NewVector<T>::operator = (const NewVector& other){
    if(this == &other){
        return *this;
    }

    destroy();

    m_data = allocate(other.m_capacity);
    m_capacity = other.m_capacity;
    m_size = other.m_size;

    for(size_t i = 0; i < m_size; ++i){
        new(&m_data[i]) T(other.m_data[i]);
    }

    return *this;
}

template<typename T>
NewVector<T>& NewVector<T>::operator = (NewVector&& other){
    if(this == &other){
        return *this;
    }

    destroy();

    m_data = other.m_data;
    m_capacity = other.m_capacity;
    m_size = other.m_size;

    other.m_data = nullptr;
    other.m_capacity = 0;
    other.m_size = 0;

    return *this;
}

template<typename T>
T& NewVector<T>::operator[](size_t i){
       return m_data[i];
}

template<typename T>
const T& NewVector<T>::operator[](size_t i) const{
    return m_data[i];
}

template<typename T>
T& NewVector<T>::front(){
    return m_data[0];
}

template<typename T>
const T& NewVector<T>::front() const{
    return m_data[0];
}

template<typename T>
T& NewVector<T>::back(){
    return m_data[m_size-1];
}

template<typename T>
const T& NewVector<T>::back() const{
    return m_data[m_size-1];
}

template<typename T>
T* NewVector<T>::data(){
    return m_data;
}

template<typename T>
const T* NewVector<T>::data() const{
    return m_data;
}

template<typename T>
size_t NewVector<T>::size()const{
    return m_size;
}

template<typename T>
size_t NewVector<T>::capacity() const{
    return m_capacity;
}

template<typename T>
bool NewVector<T>::empty() const {
    return (m_size == 0);
}

template<typename T>
void NewVector<T>::push_back(const T& value){
    if(m_size == m_capacity){
        reallocate(m_capacity ? m_capacity * 2 : 5);
    }

    new(&m_data[m_size]) T(value);
    ++m_size;
}

template<typename T>
void NewVector<T>::push_back(T&& value){
    if(m_size == m_capacity){
        reallocate(m_capacity ? m_capacity * 2 : 5);
    }

    new(&m_data[m_size]) T(static_cast<T&&>(value));
    ++m_size;
}

template<typename T>
void NewVector<T>::pop_back(){
    if(m_size == 0){
        std::cout << "NewVector is empty." << std::endl;
        return;
    }

    m_data[m_size-1].~T();
    --m_size;
}

template<typename T>
void NewVector<T>::reserve(size_t capacity){
    if(capacity > m_capacity){
        reallocate(capacity);
    }
}

template<typename T>
void NewVector<T>::insert(size_t num, const T& value){
    if(num > m_size){
        return;
    }
    if(m_size == m_capacity){
        reallocate(m_capacity ? m_capacity * 2 : 5);
    }

    if(num == m_size){
        new(&m_data[m_size])T(value);
        m_size++;
        return;
    }

    new(&m_data[m_size])T(m_data[m_size - 1]);

    for(size_t i = m_size; num < i;){
        --i;
        m_data[i + 1] = m_data[i];
    }

    m_data[num] = value;

    ++m_size;

}

template<typename T>
void NewVector<T>::insert(size_t num, T&& value){
    if(num > m_size){
        return;
    }
    if(m_size == m_capacity){
        reallocate(m_capacity ? m_capacity * 2 : 5);
    }

    if(m_size == num){
        new(&m_data[m_size])T(static_cast<T&&>(value));
        ++m_size;
        return;
    }

    new(&m_data[m_size]) T(static_cast<T&&>(m_data[m_size - 1]));

    for(size_t i = m_size; i < num ;){
        --i;
        m_data[i + 1] = static_cast<T&&>(m_data[i]);
    }

    m_data[num] = static_cast<T&&>(value);
}


template<typename T>
void NewVector<T>::erase(const size_t num){
    if(num >= m_size){
        return;
    }

    for(size_t i = num; i < m_size - 1; ++i){
        m_data[i] = static_cast<T&&>(m_data[i + 1]);
    }
    m_data[m_size - 1].~T();
    --m_size;
}


template<typename T>
void NewVector<T>::swap(const size_t i, const size_t j){
    if(i >= m_size && j >= m_size){
        return;
    }

    if(i == j){
        return;
    }

    T temp = static_cast<T&&>(m_data[i]);
    m_data[i] = static_cast<T&&>(m_data[j]);
    m_data[j] = static_cast<T&&>(temp);
}

template<typename T>
T* NewVector<T>::begin(){
    return m_data;
}

template<typename T>
T* NewVector<T>::end(){
    return (m_data ? m_data + m_size : nullptr);
}

template<typename T>
const T* NewVector<T>::begin() const {
    return m_data;
}

template<typename T>
const T* NewVector<T>::end() const {
    return (m_data ? m_data + m_size : nullptr);
}

template<typename T>
const T* NewVector<T>::cbegin() const {
    return m_data; 
}

template<typename T>
const T* NewVector<T>::cend() const {
    return (m_data ? m_data + m_size : nullptr);
}