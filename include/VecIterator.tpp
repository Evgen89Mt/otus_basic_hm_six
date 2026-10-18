#pragma once
#include"VecIterator.h"

template<typename T, typename U>
VecIterator<T,U>::VecIterator(U* ptr)
    :m_ptr(ptr)
{}

template<typename T, typename U>
U& VecIterator<T,U>::operator*() const{
    return *m_ptr;
}

template<typename T, typename U>
U* VecIterator<T,U>::operator->() const{
    return m_ptr;
}

template<typename T, typename U>
VecIterator<T, U>& VecIterator<T, U>::operator++() {
    ++m_ptr;
    return *this;
}

template<typename T, typename U>
VecIterator<T, U> VecIterator<T, U>::operator++(int) {
    VecIterator tmp = *this;
    ++(*this);
    return tmp;
}

template<typename T, typename U>
VecIterator<T, U>& VecIterator<T, U>::operator--() {
    --m_ptr;
    return *this;
}

template<typename T, typename U>
VecIterator<T, U> VecIterator<T,U>::operator--(int){
    VecIterator tmp = *this;
    --(*this);
    return tmp;
}

template<typename T, typename U>
VecIterator<T, U>& VecIterator<T,U>::operator+=(int n){
    m_ptr += n;
    return *this;
}

template<typename T, typename U>
VecIterator<T, U>& VecIterator<T,U>::operator-=(int n){
    m_ptr -= n;
    return *this;
}

template<typename T, typename U>
VecIterator<T, U> VecIterator<T,U>::operator+(int n) const{
    return VecIterator(m_ptr + n);
}

template<typename T, typename U>
VecIterator<T, U> VecIterator<T,U>::operator-(int n) const{
     return VecIterator(m_ptr - n);
}

template<typename T, typename U>
int VecIterator<T,U>::operator-(const VecIterator& other) const{
    return static_cast<int>(m_ptr - other.m_ptr);
}

template<typename T, typename U>
bool VecIterator<T,U>::operator==(const VecIterator& other) const{
    return m_ptr == other.m_ptr;
}

template<typename T, typename U>
bool VecIterator<T,U>::operator!=(const VecIterator& other) const{
     return m_ptr != other.m_ptr;
}

template<typename T, typename U>
bool VecIterator<T,U>::operator<(const VecIterator& other) const{
     return m_ptr < other.m_ptr;
}

template<typename T, typename U>
bool VecIterator<T,U>::operator>(const VecIterator& other) const{
     return m_ptr > other.m_ptr;
}

template<typename T, typename U>
bool VecIterator<T,U>::operator<=(const VecIterator& other) const{
     return m_ptr <= other.m_ptr;
}

template<typename T, typename U>
bool VecIterator<T,U>::operator>=(const VecIterator& other) const{
     return m_ptr >= other.m_ptr;
}

template<typename T, typename U>
U& VecIterator<T,U>::operator[](int n) const{
    return m_ptr[n];
}