#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <typename DataType>
class List {
    public:
        List();
        List(const List& other);
        List& operator=(const List& other);
        ~List();

        bool insert(const DataType& newDataValue);
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

#endif