#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>
#include <iostream>
#include <map>
#include <math.h>
using namespace std;

template <typename DataType>
class Queue {
    public:
        Queue();
        Queue(const Queue& other);
        Queue<DataType>& operator=(const Queue& other);
        ~Queue();

        void Clear();
        bool isEmpty() const;

        void Enqueue(DataType myData);
        DataType Dequeue();
        DataType Peek() const;

        void ShowStructure() const;

    private:
        class QueueNode {
            public:
                QueueNode(const DataType& nodeData, QueueNode* prevNode, QueueNode* nextNode){
                    m_nextNode = nextNode;
                    m_prevNode = prevNode;
                    m_dataItem = nodeData;
                }

                DataType m_dataItem;
                QueueNode* m_nextNode;
                QueueNode* m_prevNode;
        };
        
        QueueNode* m_front;
        QueueNode* m_back;
};

template <typename DataType>
Queue<DataType>::Queue(){
    m_front = NULL;
    m_back = NULL;
}

template <typename DataType>
Queue<DataType>::Queue(const Queue& other){
    QueueNode* tmp = other.m_front;
    while(tmp){
        Enqueue(tmp->m_dataItem);
        tmp = tmp->m_prevNode;
    }
}

template <typename DataType>
Queue<DataType>& Queue<DataType>::operator=(const Queue& other){
    if(&other == this){
        return *this;
    }
    QueueNode* tmp = other.m_front;
    while(tmp){
        Enqueue(tmp->m_dataItem);
        tmp = tmp->m_prevNode;
    }
    return *this;
}

template <typename DataType>
Queue<DataType>::~Queue(){
    Clear();
}

template <typename DataType>
void Queue<DataType>::Clear(){
    while(m_front){
        QueueNode* tmp = m_front;
        m_front = m_front->m_nextNode;
        delete(tmp);
    }
}

template <typename DataType>
bool Queue<DataType>::isEmpty() const {
    if(m_front){
        return false;
    } else {
        return true;
    }
}

template <typename DataType>
void Queue<DataType>::Enqueue(DataType myData){
    if(!m_front || !m_back){
        m_front = new QueueNode(myData, NULL, NULL);
        m_back = m_front;
    } else {
        QueueNode* newBack = new QueueNode(myData, NULL, m_back);
        m_back->m_prevNode = newBack;
        m_back = newBack;
    }
}

template <typename DataType>
DataType Queue<DataType>::Dequeue(){
    if(isEmpty()){
        throw logic_error("Cannot Dequeue empty queue");
    } else if(m_front == m_back){
        // One element in queue
        DataType data = m_front->m_dataItem;
        delete(m_front);
        m_front = NULL;
        m_back = NULL;
        
        return data;
    } else {
        // More than one element in queue
        QueueNode* tmp = m_front;
        m_front = m_front->m_prevNode;
        m_front->m_nextNode = NULL;
        DataType data = tmp->m_dataItem;
        delete(tmp);

        return data;
    }
}

template <typename DataType>
DataType Queue<DataType>::Peek() const {
    if(isEmpty()){
        throw logic_error("Cannoy Peek empty queue");
    }
    return m_front->m_dataItem;
}

template <typename DataType>
void Queue<DataType>::ShowStructure() const {
    cout << "[BACK] {";
    QueueNode* tmp = m_back;
    while(tmp){
        cout << " " << tmp->m_dataItem << " ";
        tmp = tmp->m_nextNode;
    }
    cout << "} [FRONT]" << endl;
}

#endif