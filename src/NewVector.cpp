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
        if(!m_data){
            return;
        }

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

    ~NewVector()
    {
        destroy();
    }
    

    //===============funcs=============
    
    //Оператор присваивания копирования
    NewVector& operator = (const NewVector& other){
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

    //Оператор присвающего перемещения
    NewVector& operator = (NewVector&& other){
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

    T& operator[](size_t i){
        return m_data[i];
    }

    const T& operator[](size_t i) const{
        return m_data[i];
    }

    T& front(){
        return m_data[0];
    }

    const T& front() const{
        return m_data[0];
    }

    T& back(){
        return m_data[m_size-1];
    }

    const T& back() const{
        return m_data[m_size-1];
    }

    T* data(){
        return m_data;
    }

    const T* data() const{
        return m_data;
    }

    size_t size()const{
        return m_size;
    }

    size_t capacity() const{
        return m_capacity;
    }

    bool empty() const {
        return (m_size == 0);
    }

    void push_back(const T& value){
        if(m_size == m_capacity){
            reallocate(m_capacity ? m_capacity * 2 : 5);
        }

        new(&m_data[m_size]) T(value);
        ++m_size;
    }

    void push_back(T&& value){
        if(m_size == m_capacity){
            reallocate(m_capacity ? m_capacity * 2 : 5);
        }

        new(&m_data[m_size]) T(static_cast<T&&>(value));
        ++m_size;
    }

    void pop_back(){
        if(m_size == 0){
            std::cout << "NewVector is empty." << std::endl;
            return;
        }

        m_data[m_size-1].~T();
        --m_size;
    }

    void reserve(size_t capacity){
        if(capacity > m_capacity){
            reallocate(capacity);
        }
    }

    void insert(size_t num, const T& value){
        if(num > m_size){
            return;
        }
        if(m_size == m_capacity){
            reallocate(m_capacity ? m_capacity * 2 : 5);
        }

        //начинаем передвигать конец 
        for(size_t i = m_size; num < i;){
            --i;
            m_data[i+1] = m_data[i]; 
        }

        new(&m_data[num]) T(value);
        ++m_size;
    }

    void insert(size_t num, T&& value){
        if(num > m_size){
            return;
        }
        if(m_size == m_capacity){
            reallocate(m_capacity ? m_capacity * 2 : 5);
        }

        //начинаем передвигать конец 
        for(size_t i = m_size; num < i;){
            --i;
            m_data[i+1] = m_data[i]; 
        }

        new(&m_data[num]) T(static_cast<T&&>(value));
        ++m_size;
    }

    //==============итераторы=============

    T* begin(){
        return m_data;
    }

    T* end(){
        return (m_data ? m_data + m_size : nullptr);
    }

    const T* cbegin() const {
        return m_data; 
    }

    const T* cend() const {
        return (m_data ? m_data + m_size : nullptr);
    }
};
