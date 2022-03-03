#ifndef RandomBST_H
#define RandomBST_H

#include <iostream>
#include <stdexcept>
#include <list>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

template <typename DataType>
class BinaryNodeRND{
    public:
        BinaryNodeRND(DataType data, BinaryNodeRND* left=NULL, BinaryNodeRND* right=NULL){
            m_data = data;
            m_left = left;
            m_right = right;
            sizeof_subtree = 1;
        }
        BinaryNodeRND* m_left;
        BinaryNodeRND* m_right;
        DataType m_data;
        int sizeof_subtree;
};

template <typename DataType>
class RandomBST {
    public:
        RandomBST();
        RandomBST(BinaryNodeRND<DataType> root);
        ~RandomBST();

        void ArrayToBT(DataType* arr, int size);

        void clear();
        bool FindNode(BinaryNodeRND<DataType>* qNode);

        void ShowStructure();
        DataType GetRandomNode();
        
    private:
        BinaryNodeRND<DataType>* ArrayToBTHelper(DataType* arr, int size, int index, BinaryNodeRND<DataType>*& currNode);
        bool FNHelper(BinaryNodeRND<DataType>* currNode, BinaryNodeRND<DataType>* qNode);
        void ShowHelper(BinaryNodeRND<DataType>* currNode, int depth);
        DataType GetRandomNodeHelper(BinaryNodeRND<DataType>*& currNode);

        BinaryNodeRND<DataType>* m_root;
};

template <typename DataType>
RandomBST<DataType>::RandomBST(){
    srand(time(NULL));
    m_root = NULL;
}

template <typename DataType>
RandomBST<DataType>::RandomBST(BinaryNodeRND<DataType> root){
    srand(time(NULL));
    //shallow copy
    m_root = &root;
}

template <typename DataType>
RandomBST<DataType>::~RandomBST(){
    clear();
}

template <typename DataType>
void RandomBST<DataType>::ArrayToBT(DataType* arr, int size){
    ArrayToBTHelper(arr, size, 0, m_root);
}

template <typename DataType>
BinaryNodeRND<DataType>* RandomBST<DataType>::ArrayToBTHelper(DataType* arr, int size, int index, BinaryNodeRND<DataType>*& currNode){
    if(index < size){
        // Create node with data at index
        currNode = new BinaryNodeRND<DataType>(arr[index]);

        // Insert Child nodes
        currNode->m_left = ArrayToBTHelper(arr, size, index*2 + 1, currNode->m_left);
        currNode->m_right = ArrayToBTHelper(arr, size, index*2 + 2, currNode->m_right);
    }
    return currNode;
}

template <typename DataType>
void RandomBST<DataType>::clear(){
    //TODO: delete() tree from leaf nodes to root
}

template <typename DataType>
bool RandomBST<DataType>::FindNode(BinaryNodeRND<DataType>* qNode){
    return FNHelper(m_root, qNode);
}

template <typename DataType>
bool RandomBST<DataType>::FNHelper(BinaryNodeRND<DataType>* currNode, BinaryNodeRND<DataType>* qNode){
    if(currNode == NULL){
        return false;
    }
    if(currNode == qNode){
        return true;
    }
    return FNHelper(currNode->m_left, qNode) || FNHelper(currNode->m_right, qNode);
}

template <typename DataType>
void RandomBST<DataType>::ShowStructure(){
    if(m_root){
        cout << "BST Structure" << endl;
        ShowHelper(m_root, 0);
        cout << endl;
    } else {
        cout << "Empty BST" << endl;
    }
}

template <typename DataType>
void RandomBST<DataType>::ShowHelper(BinaryNodeRND<DataType>* currNode, int depth){
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

template <typename DataType>
DataType RandomBST<DataType>::GetRandomNode(){
    return GetRandomNodeHelper(m_root);
}

template <typename DataType>
DataType RandomBST<DataType>::GetRandomNodeHelper(BinaryNodeRND<DataType>*& currNode){
    if(currNode == NULL){
        throw runtime_error("GetRandomNode accessed null value");
    }

    int sizeOfLeftSubtree;
    if(currNode->m_left == NULL){
        sizeOfLeftSubtree = 0;
    } else {
        sizeOfLeftSubtree = currNode->m_left->sizeof_subtree;
    }

    int randVal = rand() % currNode->sizeof_subtree;
    /*
    cout << "randVal: " << randVal << endl;
    cout << "leftSize: " << sizeOfLeftSubtree << endl;
    cout << "currNode: " << currNode->m_data << endl;
    */
   
    if(randVal < sizeOfLeftSubtree){
        return GetRandomNodeHelper(currNode->m_left);
    } else if(randVal == sizeOfLeftSubtree){
        return currNode->m_data;
    } else {
        return GetRandomNodeHelper(currNode->m_right);
    }
}

#endif