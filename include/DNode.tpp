#pragma once
#include"DNode.h"

template<typename T>
DNode<T>::DNode(const T& v)
    : value(v)
    , prev(nullptr)
    , next(nullptr)
{}

template<typename T>
DNode<T>::DNode(T&& v)
    : value(static_cast<T&&>(v))
    , prev(nullptr)
    , next(nullptr)
{}