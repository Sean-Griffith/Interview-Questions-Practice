#ifndef TRIPLEARRAYSTACK_H
#define TRIPLEARRAYSTACK_H

#include <stdexcept>
#include <iostream>
#include <map>
#include <math.h>
using namespace std;

template <typename DataType>
class TripleArrayStack {
    public:
        TripleArrayStack();
        TripleArrayStack(const TripleArrayStack& other);
        TripleArrayStack& operator=(const TripleArrayStack& other);
        ~TripleArrayStack();

        void Push(int stackNum);
        DataType Pop(int stackNum);

    private:
        int m_size1, m_size2, m_size3;
        int* m_array;
};

template <typename DataType>
TripleArrayStack<DataType>::TripleArrayStack(){
    m_size1 = m_size2 = m_size3 = 0;
    m_array = new int[m_size1 + m_size2 + m_size3];
}

template <typename DataType>
TripleArrayStack<DataType>::TripleArrayStack(const TripleArrayStack& other){
    m_size1 = other.m_size1;
    m_size2 = other.m_size2;
    m_size3 = other.m_size3;
    m_array = new int[m_size1 + m_size2 + m_size3];

    int totalSize = m_size1 + m_size2 + m_size3;
    for(int i = 0; i < totalSize; i++){
        m_array[i] = other.m_array[i];
    }
}

template <typename DataType>
TripleArrayStack<DataType>& TripleArrayStack<DataType>::operator=(const TripleArrayStack& other){
    if(&other == this){
        return *this;
    }

    m_size1 = other.m_size1;
    m_size2 = other.m_size2;
    m_size3 = other.m_size3;
    m_array = new int[m_size1 + m_size2 + m_size3];

    int totalSize = m_size1 + m_size2 + m_size3;
    for(int i = 0; i < totalSize; i++){
        m_array[i] = other.m_array[i];
    }

    return *this;
}

template <typename DataType>
TripleArrayStack<DataType>::~TripleArrayStack(){
    delete m_array;
}

#endif