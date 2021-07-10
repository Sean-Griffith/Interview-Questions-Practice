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

        bool insert() throw (logic_error);
        bool remove() throw (logic_error);
        bool replace() throw (logic_error);
        void clear();

        bool isEmpty() const;
        bool isFull() const;

        void gotoBeginning() throw (logic_error);
        void gotoEnd() throw (logic_error);
        bool gotoNext() throw (logic_error);
        bool gotoPrior() throw (logic_error);

        DataType getCursorValue() const throw (logic_error);

        bool moveToBeginning() throw (logic_error);

        bool insertBefore(const DataType& newDataValue) throw (logic_error);

        void showStructure() const;

    private:
        class ListNode {
            public:
                ListNode(const DataType& nodeDataValue, ListNode* nextPtr);
                int m_dataItem;
                ListNode* m_next;
        };

        ListNode* m_head;
        ListNode* m_cursor;
};

#endif