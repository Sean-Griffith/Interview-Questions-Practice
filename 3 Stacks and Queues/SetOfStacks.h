#ifndef SETOFSTACKS_H
#define SETOFSTACKS_H

#include "Stack.h"
#include <map>
#include <vector>
using namespace std;

template <typename DataType>
class SetOfStacks {
    public:
        SetOfStacks();
        SetOfStacks(int threshold);
        SetOfStacks(const SetOfStacks& other);
        SetOfStacks<DataType>& operator=(const SetOfStacks& other);
        ~SetOfStacks();

        void Push();
        DataType Pop();

        void ShowStructure(int stackNumber=-1);
    private:
        int m_threshold;
        map<int, int> m_stackSizes;
        vector<Stack<DataType>> m_stackList;
};

template <typename DataType>
SetOfStacks<DataType>::SetOfStacks(){
    m_threshold = 0;
    Stack<DataType> newStack;
    m_stackSizes[0] = 0;
    m_stackList.push_back(newStack);
}

template <typename DataType>
SetOfStacks<DataType>::SetOfStacks(int threshold){
    m_threshold = threshold;
    Stack<DataType> newStack;
    m_stackSizes[0] = 0;
    m_stackList.push_back(newStack);
}

template <typename DataType>
SetOfStacks<DataType>::SetOfStacks(const SetOfStacks& other){
    
}

template <typename DataType>
SetOfStacks<DataType>& SetOfStacks<DataType>::operator=(const SetOfStacks& other){

}

template <typename DataType>
SetOfStacks<DataType>::~SetOfStacks(){
    m_threshold = 0;
}

template <typename DataType>
void SetOfStacks<DataType>::Push(){
    
}

template <typename DataType>
DataType SetOfStacks<DataType>::Pop(){
    
}

template <typename DataType>
void SetOfStacks<DataType>::ShowStructure(int stackNumber){
    cout << "{" << endl;
    if(stackNumber < 0){
        for(int i = 0; i < m_stackList.size(); i++){
            cout << "\t";
            m_stackList[i].ShowStructure();
        }
    } else {
        if(stackNumber >= m_stackList.size()){
            // Invalid stack specified - throw error
            throw logic_error("Invalid stack requested in SetOfStacks::ShowStructure()");
        }
        // Show the structure of a specific stack
        cout << "\t";
        m_stackList[stackNumber].ShowStructure();
    }
    cout << "}" << endl;
}

#endif