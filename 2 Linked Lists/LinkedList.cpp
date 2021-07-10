

#include <stdexcept>
#include <iostream>
#include "LinkedList.h"
using namespace std;

template <typename DataType>
List<DataType>::ListNode::ListNode(const DataType& nodeData, ListNode* nextPtr){
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
bool List<DataType>::insert(){
    return false;
}

template <typename DataType>
bool List<DataType>::remove(){
    return false;
}

template <typename DataType>
bool List<DataType>::replace(){
    return false;
}

template <typename DataType>
void List<DataType>::clear(){

}

template <typename DataType>
bool List<DataType>::isEmpty() const {
    if(m_head == NULL){
        return true;
    } else {
        return false;
    }
}

template <typename DataType>
void List<DataType>::gotoBeginning(){
    if(isEmpty()){
        throw logic_error("gotoBeginning() empty list");
    } else {
        m_cursor = m_head;
    }
}

template <typename DataType>
void List<DataType>::gotoEnd(){
    if(isEmpty()){
        throw logic_error("gotoEnd() empty list");
    } else {
        while(m_cursor->next){
            m_cursor = m_cursor->next;
        }
    }
}

template <typename DataType>
bool List<DataType>::gotoNext(){
    if(isEmpty()){
        throw logic_error("gotoNext() empty list");
        return false;
    } else {
        if(m_cursor->next){
            m_cursor = m_cursor->next;
            return true;
        } else {
            return false;
        }
    }
}

template <typename DataType>
bool List<DataType>::gotoPrior(){
    if(isEmpty()){
        throw logic_error("gotoPrior() empty list");
        return false;
    } else {
        if(m_cursor == m_head && m_cursor != NULL){
            return false;
        } else {
            ListNode* tmp = m_head;
            while(tmp->next && tmp->next != m_cursor){
                tmp = tmp->next;
            }
            m_cursor = tmp;
            return true;
        }
    }
}

template <typename DataType>
DataType List<DataType>::getCursorValue() const {
    if(isEmpty()){
        throw logic_error("getCursorValue() empty list");
    } else if(m_cursor){
        return m_cursor->m_dataItem;
    } else {
        throw logic_error("getCursorValue() NULL cursor");
    }
}

template <typename DataType>
bool List<DataType>::moveToBeginning(){
    return false;
}

template <typename DataType>
bool List<DataType>::insertBefore(const DataType& newDataValue){
    return false;
}

template <typename DataType>
void List<DataType>::showStructure() const {

}