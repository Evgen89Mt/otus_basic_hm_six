// реализовываем контейнер new_vector
// организация памяти последовательно

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
    static void deallocate(T* ptr){
        ::operator delete(ptr);
    }

    // выделяем память
    static T* allocate(size_t capacity){
        if(capacity == 0){
            return nullptr;
        }
        //T* tmp = ::operator new(capasity * sizeof(T));
        return static_cast<T*>(::operator new(capacity * sizeof(T)));
    }

    // выделяем память и копируем
    void reallocate(size_t capacity){

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

    // удаляем память в ячейках
    void clear(){
        for(size_t i = 0; i < m_size; ++i){
            m_data[i].~T();
        }
        m_size = 0;
    }

    // полная очистка
    void destroy(){
        clear();
        deallocate(m_data);
        m_data = nullptr;
        m_capacity = 0;
    }

    public:
    NewVector()
        :m_data(nullptr)
        ,m_size(0)
        ,m_capacity(0)
    {}

    NewVector(size_t capacity) 
        :m_data(allocate(capacity))
        ,m_size(0)
        ,m_capacity(capacity)
    {}

    //копирующий конструктор
    NewVector(const NewVector& other)
        :m_data(allocate(other.m_capacity))
        ,m_size(other.m_size)
        ,m_capacity(other.m_capacity)
    {
        for(size_t i = 0; i < m_size; ++i){
            new(&m_data[i]) T(other.m_data[i]);
        }
    }

    // перемещающий конструктор
    NewVector(NewVector&& other)
        :m_data(other.m_data)
        ,m_size(other.m_size)
        ,m_capacity(other.m_capacity)
    {
        other.m_data = nullptr;
        other.m_size = 0;
        other.m_capacity = 0;
    }
    ~NewVector(){destroy();}
};
