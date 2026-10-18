// iterator from NewVector
#pragma once

template<typename T>
class NewVector;

template<typename T, typename U>
class VecIterator{
    private:
        U* m_ptr = nullptr;

        template<typename> friend class NewVector;
        
        explicit VecIterator(U* ptr);

    public:
        VecIterator() = default;

        U& operator*() const;
        U* operator->() const;
        VecIterator& operator++();
        VecIterator operator++(int);
        VecIterator& operator--();
        VecIterator operator--(int);

        //арифметика указателя
        VecIterator& operator+=(int n);
        VecIterator& operator-=(int n);
        VecIterator operator+(int n) const;
        VecIterator operator-(int n) const;
        int operator-(const VecIterator& other) const;

        //логические операции
        bool operator==(const VecIterator& other) const;
        bool operator!=(const VecIterator& other) const;
        bool operator<(const VecIterator& other) const;
        bool operator>(const VecIterator& other) const;
        bool operator<=(const VecIterator& other) const;
        bool operator>=(const VecIterator& other) const;
        U& operator[](int n) const;
};

#include"VecIterator.tpp"