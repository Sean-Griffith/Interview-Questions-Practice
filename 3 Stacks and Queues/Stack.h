#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include <iostream>
#include <map>
#include <math.h>
using namespace std;

template <typename DataType>
class Stack {
    public:
        Stack();
        Stack(const Stack& other);
        Stack<DataType>& operator=(const Stack& other);
        ~Stack();

        void Clear();
        bool isEmpty() const;

        void Push(DataType myData);
        DataType Pop();
        DataType Peek();
        DataType GetMinimum() const;

        void ShowStructure() const;

    private:
        class StackNode {
            public:
                StackNode(const DataType& nodeData, StackNode* lowerNode){
                    m_lowerNode = lowerNode;
                    m_dataItem = nodeData;
                    if(lowerNode){
                        if(lowerNode->m_minLowerVal < nodeData){
                            m_minLowerVal = lowerNode->m_minLowerVal;
                        } else {
                            m_minLowerVal = nodeData;
                        }
                        
                    } else {
                        m_minLowerVal = nodeData;
                    }
                }

                DataType m_dataItem;
                StackNode* m_lowerNode;
                int m_minLowerVal;
        };
        
        StackNode* m_top;
};

template <typename DataType>
Stack<DataType>::Stack(){
    m_top = NULL;
}

template <typename DataType>
Stack<DataType>::Stack(const Stack& other){
    m_top = NULL;
    StackNode* tmp = other.m_top;
    Stack<DataType> intermediateStack;
    while(tmp){
        intermediateStack.Push(tmp->m_dataItem);
        tmp = tmp->m_lowerNode;
    }

    tmp = intermediateStack.m_top;
    while(tmp){
        Push(tmp->m_dataItem);
        tmp = tmp->m_lowerNode;
    }
}

template <typename DataType>
Stack<DataType>& Stack<DataType>::operator=(const Stack<DataType>& other){
    if(&other == this){
        return *this;
    }
    m_top = NULL;
    StackNode* tmp = other.m_top;
    Stack<DataType> intermediateStack;
    while(tmp){
        intermediateStack.Push(tmp->m_dataItem);
        tmp = tmp->m_lowerNode;
    }

    tmp = intermediateStack.m_top;
    while(tmp){
        Push(tmp->m_dataItem);
        tmp = tmp->m_lowerNode;
    }
    return *this;
}

template <typename DataType>
Stack<DataType>::~Stack(){
    Clear();
}

template <typename DataType>
void Stack<DataType>::Clear(){
    while(!isEmpty()){
        StackNode* tmp = m_top;
        m_top = m_top->m_lowerNode;
        delete(tmp);
    }
}

template <typename DataType>
bool Stack<DataType>::isEmpty() const {
    if(m_top == NULL){
        return true;
    } else {
        return false;
    }
}

template <typename DataType>
void Stack<DataType>::Push(DataType myData){
    StackNode* newTop = new StackNode(myData, m_top);
    m_top = newTop;
}

template <typename DataType>
DataType Stack<DataType>::Pop(){
    StackNode* oldTop = m_top;
    m_top = m_top->m_lowerNode;

    DataType topData = oldTop->m_dataItem;
    delete(oldTop);
    return topData;
}

template <typename DataType>
DataType Stack<DataType>::Peek(){
    if(isEmpty()){
        throw logic_error("Cannot Peek empty stack!")
    }
    
    return m_top->m_dataItem;
}

template <typename DataType>
DataType Stack<DataType>::GetMinimum() const {
    if(this->isEmpty()){
        throw logic_error("MinStack:GetMinimum on empty stack");
    }
    DataType minValue;
    
    return this->m_top->m_minLowerVal;
}

template <typename DataType>
void Stack<DataType>::ShowStructure() const {
    cout << "[TOP] {";
    StackNode* tmp = m_top;
    while(tmp){
        cout << " " << tmp->m_dataItem << " ";
        tmp = tmp->m_lowerNode;
    }
    cout << "} [BOT]" << endl;
}

#endif