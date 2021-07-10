

#include <stdexcept>
#include <iostream>
#include "LinkedList.h"
using namespace std;

template <typename DataType>
List<DataType>::ListNode::ListNode(const DataType& nodeData, ListNode* nextPtr=NULL){
    // Constructor for ListNode class, sets data of node and following node address
    m_dataItem = nodeData;
    m_next = nextPtr;
}

template <typename DataType>
List<DataType>::List(){
    m_head = NULL;
    m_cursor = NULL;
}

template <typename DataType>
List<DataType>::List(const List& other){
    
}

template <typename DataType>
List<DataType>& List<DataType>::operator=(const List& other){

}

template <typename DataType>
List<DataType>::~List(){

}

template <typename DataType>
bool List<DataType>::insert() throw (logic_error){

}

template <typename DataType>
bool List<DataType>::remove(){

}

template <typename DataType>
bool List<DataType>::replace(){

}

template <typename DataType>
void List<DataType>::clear(){

}

template <typename DataType>
bool List<DataType>::isEmpty() const {
    
}

template <typename DataType>
bool List<DataType>::isFull() const {

}

template <typename DataType>
void List<DataType>::gotoBeginning(){

}

template <typename DataType>
void List<DataType>::gotoEnd(){

}

template <typename DataType>
bool List<DataType>::gotoNext(){

}

template <typename DataType>
bool List<DataType>::gotoPrior(){

}

template <typename DataType>
DataType List<DataType>::getCursorValue() const {

}

template <typename DataType>
bool List<DataType>::moveToBeginning(){

}

template <typename DataType>
bool List<DataType>::insertBefore(const DataType& newDataValue){

}

template <typename DataType>
void List<DataType>::showStructure(){

}