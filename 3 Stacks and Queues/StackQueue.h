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

    private:
        Stack<DataType> m_stack1;
        Stack<DataType> m_stack2;
};

template <typename DataType>
StackQueue<DataType>::StackQueue(){
    
}

template <typename DataType>
StackQueue<DataType>::StackQueue(const StackQueue& other){
    
}

template <typename DataType>
StackQueue<DataType>& StackQueue<DataType>::operator=(const StackQueue<DataType>& other){
    
}

template <typename DataType>
StackQueue<DataType>::~StackQueue(){
    
}

#endif