#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>
#include <iostream>
using namespace std;

template <typename DataType>
class List {
    public:
        List();
        List(const List& other);
        List& operator=(const List& other);
        ~List();

        void insert(const DataType& newDataValue);
        bool remove();
        bool replace(const DataType& newDataValue);
        void clear();

        bool isEmpty() const;

        void gotoBeginning();
        void gotoEnd();
        bool gotoNext();
        bool gotoPrior();

        DataType getCursorValue() const;

        bool moveToBeginning();

        bool insertBefore(const DataType& newDataValue);

        void showStructure() const;

    private:
        class ListNode {
            public:
                ListNode(const DataType& nodeDataValue, ListNode* nextPtr=NULL);
                int m_dataItem;
                ListNode* m_next;
        };

        ListNode* m_head;
        ListNode* m_cursor;
};

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
    clear();
}

template <typename DataType>
void List<DataType>::insert(const DataType& newDataValue){
    if(isEmpty()){  
        m_head = new ListNode(newDataValue);
        gotoBeginning();
    } else {
        if(m_cursor->m_next == NULL){
            m_cursor->m_next = new ListNode(newDataValue);
            gotoNext();
        } else {
            ListNode* currentNode = m_cursor;
            ListNode* afterNode = m_cursor->m_next;
            m_cursor = new ListNode(newDataValue, afterNode);
            currentNode->m_next = m_cursor;
        }
    }
}

template <typename DataType>
bool List<DataType>::remove(){
    if(isEmpty()){
        throw logic_error("remove() empty list");
        return false;
    } else {
        if(m_cursor == m_head){
            if(m_cursor->m_next){
                m_cursor = m_cursor->m_next;
                delete m_head;
                m_head = m_cursor;
            } else {
                delete m_head;
                m_head = NULL;
                m_cursor = NULL;
            }
        } else {
            ListNode* current = m_cursor;
            gotoPrior();
            if(current->m_next){
                m_cursor->m_next = current->m_next;
            } else {
                m_cursor->m_next = NULL;
            }
            delete current;
        }
        return true;
    }
}

template <typename DataType>
bool List<DataType>::replace(const DataType& newDataValue){
    if(isEmpty()){
        throw logic_error("replace() empty list");
        return false;
    } else {
        if(m_cursor){
            m_cursor->m_dataItem = newDataValue;
            return true;
        } else {
            throw logic_error("replace() invalid cursor");
            return false;
        }
    }
}

template <typename DataType>
void List<DataType>::clear(){
    if(!isEmpty()){
        gotoBeginning();
        ListNode* tmp = m_cursor;
        while(m_cursor->m_next){
            gotoNext();
            delete tmp;
            tmp = m_cursor;
        }
        delete tmp;
        m_cursor = NULL;
        m_head = NULL;
    }
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
        while(m_cursor->m_next){
            m_cursor = m_cursor->m_next;
        }
    }
}

template <typename DataType>
bool List<DataType>::gotoNext(){
    if(isEmpty()){
        throw logic_error("gotoNext() empty list");
        return false;
    } else {
        if(m_cursor->m_next){
            m_cursor = m_cursor->m_next;
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
            while(tmp->m_next && tmp->m_next != m_cursor){
                tmp = tmp->m_next;
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
    if(isEmpty()){
        cout << "Empty list" << endl;
    } else {
        for(ListNode* tmp = m_head; tmp != NULL; tmp = tmp->m_next){
            if(tmp == m_cursor){
                cout << "[";
            }
            cout << tmp->m_dataItem;
            if(tmp == m_cursor){
                cout << "]";
            }
            if(tmp->m_next){
                cout << " -> ";
            }
        }
        cout << endl;
    }
}

#endif