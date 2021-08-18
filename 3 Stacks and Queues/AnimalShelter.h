#ifndef ANIMALSHELTER_H
#define ANIMALSHELTER_H

#include "Queue.h"
using namespace std;

template <typename DataType>
class AnimalShelter {
    public:
        AnimalShelter();
        AnimalShelter(const AnimalShelter& other);
        AnimalShelter<DataType>& operator=(const AnimalShelter& other);
        ~AnimalShelter();

        void Clear();
        bool isEmpty() const;

        void Enqueue(DataType myData);
        DataType Dequeue();
        DataType DequeueDog();
        DataType DequeueCat() const;

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
        
        
};

template <typename DataType>
AnimalShelter<DataType>::AnimalShelter(){
    m_top = NULL;
}

#endif