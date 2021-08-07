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

        void Push(DataType data);
        DataType Pop();
        bool isEmpty();

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
void SetOfStacks<DataType>::Push(DataType data){
    if(m_stackSizes[m_stackList.size()-1] >= m_threshold){
        // Create a new stack
        try {
            Stack<DataType> newStack;
            m_stackSizes[m_stackList.size()] = 0;
            m_stackList.push_back(newStack);
        } catch (...) {
            cout << "" << endl;
            throw runtime_error("Could not generate a new stack for SetOfStacks::Push");
        }
    }

    // Add the data to the most recent stack
    m_stackSizes[m_stackList.size()-1]++;
    m_stackList[m_stackList.size()-1].Push(data);
}

template <typename DataType>
DataType SetOfStacks<DataType>::Pop(){
    if(isEmpty()){
        throw logic_error("Cannot pop an empty SetOfStacks");
    }

    while(m_stackSizes[m_stackList.size()-1] == 0){
        // Remove last stack if empty
        try {
            m_stackSizes.erase(m_stackList.size()-1);
            m_stackList.pop_back();
        } catch (...) {
            cout << "" << endl;
            throw runtime_error("Could not remove an empty stack for SetOfStacks::Pop");
        }
    }
    
    // Remove data from the most recent (non-empty) stack
    m_stackSizes[m_stackList.size()-1]--;
    return m_stackList[m_stackList.size()-1].Pop();
}

template <typename DataType>
bool SetOfStacks<DataType>::isEmpty(){
    if(m_stackSizes[0] <= 0){
        return true;
    } else {
        return false;
    }
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