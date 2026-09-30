#pragma once
#include "Node.h"

template<typename T>
Node<T>::Node(const T& v)
    :value(v)
    ,next(nullptr)
{}

template<typename T>
Node<T>::Node(T&& v)
    :value(static_cast<T&&>(v))
    ,next(nullptr)
{}