#ifndef STACKQUEUE_H
#define STACKQUEUE_H

#include "Stack.h"
using namespace std;

template <typename DataType>
class StackQueue {
    public:
        StackQueue();
        StackQueue(const StackQueue& other);
        StackQueue<DataType>& operator=(const StackQueue& other);
        ~StackQueue();

        void Add(DataType data);
        DataType Remove();
        DataType Peek();

        bool isEmpty();

    private:
        Stack<DataType>* m_inStack;
        Stack<DataType>* m_outStack;
};

template <typename DataType>
StackQueue<DataType>::StackQueue(){
    m_inStack = new Stack<DataType>;
    m_outStack = new Stack<DataType>;
}

template <typename DataType>
StackQueue<DataType>::StackQueue(const StackQueue& other){
    m_inStack = other->m_inStack;
    m_outStack = other->m_outStack;
}

template <typename DataType>
StackQueue<DataType>& StackQueue<DataType>::operator=(const StackQueue<DataType>& other){
    if(&other == this){
        return *this;
    }
    m_inStack = other->m_inStack;
    m_outStack = other->m_outStack;
    return *this;
}

template <typename DataType>
StackQueue<DataType>::~StackQueue(){
    delete(m_inStack);
    delete(m_outStack);
}

template <typename DataType>
void StackQueue<DataType>::Add(DataType data){
    while(!m_outStack->isEmpty()){
        m_inStack->Push(m_outStack->Pop());
    }
    m_inStack->Push(data);
}

template <typename DataType>
DataType StackQueue<DataType>::Remove(){
    while(!m_inStack->isEmpty()){
        m_outStack->Push(m_inStack->Pop());
    }
    return m_outStack->Pop();
}

template <typename DataType>
DataType StackQueue<DataType>::Peek(){
    while(!m_inStack->isEmpty()){
        m_outStack->Push(m_inStack->Pop());
    }
    return m_outStack->Peek();
}

template <typename DataType>
bool StackQueue<DataType>::isEmpty(){
    return true;
}

#endif