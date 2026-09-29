// реализовываем контейнер new_vector
// организация памяти последовательно
// разделим файл на h tpp

#pragma once

#include<iostream>
#include<cstddef>
#include<new>

template<typename T>
class NewVector{
    private:
    T*                  m_data;         // указатель на начало памяти
    size_t              m_size;         // размер занятой памяти
    size_t              m_capacity;     // размер выделенной памяти

    // освобождаем память
    static void deallocate(T* ptr);

    // выделяем память
    static T* allocate(size_t capacity);

    // выделяем память и копируем
    void reallocate(size_t capacity);

    // удаляем память в ячейках
    void clear();

    // полная очистка
    void destroy();

    public:
    NewVector();
    NewVector(size_t capacity);

    //копирующий конструктор
    NewVector(const NewVector& other);
    // перемещающий конструктор
    NewVector(NewVector&& other);
    ~NewVector();

    //Оператор присваивания копирования
    NewVector& operator = (const NewVector& other);

    //Оператор присвающего перемещения
    NewVector& operator = (NewVector&& other);

    T& operator[](size_t i);
    const T& operator[](size_t i) const;

    T& front();
    const T& front() const;

    T& back();
    const T& back() const;

    T* data();
    const T* data() const;

    size_t size()const;
    size_t capacity() const;
    bool empty() const;

    void push_back(const T& value);
    void push_back(T&& value);

    void pop_back();
    void reserve(size_t capacity);

    void insert(size_t num, const T& value);
    void insert(size_t num, T&& value);

    void erase(const size_t num);
    void swap(const size_t i, const size_t j);

    //==============итераторы=============

    T* begin();
    T* end();

    const T* begin() const;
    const T* end() const;

    const T* cbegin() const;
    const T* cend() const;
};


#include "NewVector.tpp"