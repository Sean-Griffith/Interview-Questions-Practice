#ifndef SORTSTACK_H
#define SORTSTACK_H

#include <stdexcept>
#include <iostream>
#include "Stack.h"
using namespace std;

template <typename DataType>
class SortStack {
    public:
        SortStack();
        SortStack(const SortStack& other);
        SortStack<DataType>& operator=(const SortStack& other);
        ~SortStack();

        void Clear();
        bool isEmpty() const;

        void Push(DataType myData);
        DataType Pop();
        DataType Peek();

        void ShowStructure() const;

    private:
        Stack<DataType>* m_sortedStack;
};

template <typename DataType>
SortStack<DataType>::SortStack(){
    
}

template <typename DataType>
SortStack<DataType>::SortStack(const SortStack& other){
    
}

template <typename DataType>
SortStack<DataType>& SortStack<DataType>::operator=(const SortStack<DataType>& other){

}

template <typename DataType>
SortStack<DataType>::~SortStack(){

}

template <typename DataType>
void SortStack<DataType>::Clear(){

}

template <typename DataType>
bool SortStack<DataType>::isEmpty() const {

}

template <typename DataType>
void SortStack<DataType>::Push(DataType myData){
    
}

template <typename DataType>
DataType SortStack<DataType>::Pop(){
    
}

template <typename DataType>
DataType SortStack<DataType>::Peek(){
    
}

template <typename DataType>
void SortStack<DataType>::ShowStructure() const {

}

#endif