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
                QueueNode(const DataType& nodeData, QueueNode* nextNode){
                    m_nextNode = nextNode;
                    m_dataItem = nodeData;
                }

                DataType m_dataItem;
                QueueNode* m_nextNode;
        };
        
        
};

template <typename DataType>
Queue<DataType>::Queue(){
    
}

#endif