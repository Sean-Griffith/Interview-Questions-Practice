#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>
#include <iostream>
#include <map>
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

        void removeDups();
        void removeDupsNoBuffer();
        DataType kthToLast(int k);
        void removeMiddleNode(const DataType& value);

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
    if(other.isEmpty()){
        clear();
    } else {
        ListNode* tmp = other.m_head;
        m_head = NULL;
        m_cursor = NULL;
        while(tmp != NULL){
            insert(tmp->m_dataItem);
            tmp = tmp->m_next;
        }
    }
}

template <typename DataType>
List<DataType>& List<DataType>::operator=(const List& other){
    if(other == this){
        return *this;
    } else {
        m_head = NULL;
        m_cursor = NULL;
        if(other.isEmpty()){
            clear();
            return *this;
        } else {
            ListNode* tmp = other.m_head;
            while(tmp != NULL){
                insert(tmp->m_dataItem);
                tmp = tmp->m_next;
            }
            return *this;
        }
    }
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
                m_cursor = m_cursor->m_next;
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
    throw logic_error("moveToBeginning() not implemented");
    return false;
}

template <typename DataType>
bool List<DataType>::insertBefore(const DataType& newDataValue){
    throw logic_error("insertBefore() not implemented");
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

template <typename DataType>
void List<DataType>::removeDups(){
    map<DataType, int> counter;
    m_cursor = m_head;

    cout << "Removing duplicates" << endl;

    counter[m_cursor->m_dataItem]++;
    while(m_cursor->m_next != NULL){
        if(counter[m_cursor->m_next->m_dataItem] >= 1){
            // Remove the node
            if(m_cursor->m_next->m_next == NULL){
                //end of list
                delete(m_cursor->m_next);
                m_cursor->m_next = NULL;
            } else {
                //middle of list
                ListNode* after = m_cursor->m_next->m_next;
                delete(m_cursor->m_next);
                m_cursor->m_next = after;
            }
        } else {
            // Increment the counter for that data value
            counter[m_cursor->m_next->m_dataItem]++;
            gotoNext();
        }  
    }
}

template <typename DataType>
void List<DataType>::removeDupsNoBuffer(){
    ListNode* scanner = m_head;

    cout << "Removing duplicates without a buffer" << endl;

    while(scanner != NULL){
        m_cursor = scanner->m_next;
        cout << "Moving Cursor" << endl;
        while(m_cursor->m_next != NULL){
            cout << endl;
            showStructure();
            cout << scanner->m_dataItem << " ? " << m_cursor->m_dataItem << endl;
            if(m_cursor->m_dataItem == scanner->m_dataItem){
                cout << "Removing duplicate " << scanner->m_dataItem << endl;
                remove();
            } else {
                gotoNext();
            }
        }
        if(m_cursor->m_dataItem == scanner->m_dataItem){
            cout << "Removing duplicate " << scanner->m_dataItem << endl;
            remove();
        }

        scanner = scanner->m_next;
    }
}

template <typename DataType>
DataType List<DataType>::kthToLast(int k){
    if(k < 1){
        throw logic_error("K >= 1");
    }
    ListNode* kthToLastPtr = m_head;
    bool tooLarge = false;
    gotoBeginning();
    showStructure();
    for(int i = 0; i < k; i++){
        if(!gotoNext()){
            tooLarge = true;
        }
    }
    showStructure();
    while(gotoNext()){
        kthToLastPtr = kthToLastPtr->m_next;
    }
    
    if(!tooLarge){
        kthToLastPtr = kthToLastPtr->m_next;
    }
    
    return kthToLastPtr->m_dataItem;
}

template <typename DataType>
void List<DataType>::removeMiddleNode(const DataType& value){
    gotoBeginning();
    do {
        if(m_cursor->m_dataItem == value){
            cout << "Found " << m_cursor->m_dataItem << endl;
            if(m_cursor == m_head || m_cursor->m_next == NULL){
                throw logic_error("removeMiddleNode() Attempted to remove non-middle node");
            } else {
                ListNode* next = m_cursor->m_next;
                m_cursor->m_dataItem = next->m_dataItem;
                m_cursor->m_next = next->m_next;
                delete(next);
                break;
            }
        }
        cout << "Exiting" << endl;
    } while(gotoNext());
    
}

#endif