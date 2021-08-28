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
        bool Search(DataType value);

        void Clear();

        void PreOrder() const;
        void InOrder() const;
        void PostOrder() const;

    private:
        class BinaryNode{
            BinaryNode(DataType data, BinaryNode* left=NULL, BinaryNode* right=NULL){
                
            }
            BinaryNode* m_left;
            BinaryNode* m_right;
            DataType m_data;
        };

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

}

template <typename DataType>
DataType BST<DataType>::Delete(DataType value){

}

template <typename DataType>
bool BST<DataType>::Search(DataType value){

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

#endif