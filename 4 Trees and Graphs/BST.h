#ifndef BST_H
#define BST_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename DataType>
class BST {
    public:
        BST();
        BST(const BST& other);
        BST<DataType>& operator=(const BST<DataType>& other);
        ~BST();

        void Insert(DataType value);
        DataType Delete(DataType value);
        bool Search(DataType value) const;

        void Clear();

        void PreOrder() const;
        void InOrder() const;
        void PostOrder() const;

        void ShowStructure();
    protected:
        class BinaryNode{
            public:
                BinaryNode(DataType data, BinaryNode* left=NULL, BinaryNode* right=NULL){
                    m_data = data;
                    m_left = left;
                    m_right = right;
                }
                BinaryNode* m_left;
                BinaryNode* m_right;
                DataType m_data;
        };
        void InsertHelper(DataType value, BinaryNode*& currNode);
        void ShowHelper(BinaryNode* currNode, int depth);
        BinaryNode* m_root;
};

template <typename DataType>
BST<DataType>::BST(){
    m_root = NULL;
}

template <typename DataType>
BST<DataType>::BST(const BST& other){
    
}

template <typename DataType>
BST<DataType>& BST<DataType>::operator=(const BST<DataType>& other){
    
}

template <typename DataType>
BST<DataType>::~BST(){
    Clear();
}

template <typename DataType>
void BST<DataType>::Clear(){
    // Delete nodes bottom up (Post-order)

    m_root = NULL;
}

template <typename DataType>
void BST<DataType>::Insert(DataType value){
    InsertHelper(value, m_root);
}

template <typename DataType>
void BST<DataType>::InsertHelper(DataType value, BinaryNode*& currNode){
    if(currNode == NULL){
        currNode = new BinaryNode(value);
        return;
    }
    if(currNode->m_data >= value){
        InsertHelper(value, currNode->m_left);
    } else {
        InsertHelper(value, currNode->m_right);
    }
}

template <typename DataType>
DataType BST<DataType>::Delete(DataType value){

}

template <typename DataType>
bool BST<DataType>::Search(DataType value) const {
    return false;
}

template <typename DataType>
void BST<DataType>::PreOrder() const {
    
}

template <typename DataType>
void BST<DataType>::InOrder() const {

}

template <typename DataType>
void BST<DataType>::PostOrder() const {

}

template <typename DataType>
void BST<DataType>::ShowStructure(){
    if(m_root){
        cout << "BST Structure" << endl;
        ShowHelper(m_root, 0);
        cout << endl;
    } else {
        cout << "Empty BST" << endl;
    }
}

template <typename DataType>
void BST<DataType>::ShowHelper(BinaryNode* currNode, int depth){
    if(!currNode){
        return;
    }
    ShowHelper(currNode->m_right, depth+1);
    // Tab over to current depth
    for(int i = 0; i < depth; i++){
        cout << "\t";
    }
    // Output current node value
    cout << " " << currNode->m_data;
    // Output lines to child nodes (if any)
    if(currNode->m_right && currNode->m_left){
        cout << "<";
    } else if(currNode->m_right){
        cout << "/";
    } else if(currNode->m_left){
        cout << "\\";
    }
    cout << endl;
    ShowHelper(currNode->m_left, depth+1);
}

#endif