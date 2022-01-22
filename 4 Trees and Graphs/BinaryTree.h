#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <stdexcept>
#include <list>
#include <vector>
using namespace std;

template <typename DataType>
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

template <typename DataType>
class BinaryTree {
    public:
        BinaryTree();
        BinaryTree(BinaryNode<DataType> root);
        BinaryTree(const BinaryTree& other);
        BinaryTree<DataType>& operator=(const BinaryTree<DataType>& other);
        ~BinaryTree();

        void ArrayToBT(DataType* arr, int size);

        void clear();
        bool FindNode(BinaryNode<DataType>* qNode);
        
        BinaryNode<DataType>* FirstCommonAncestor(BinaryNode<DataType>* p, BinaryNode<DataType>* q);

        void ShowStructure();
        
    private:
        BinaryNode<DataType>* ArrayToBTHelper(DataType* arr, int size, int index, BinaryNode<DataType>*& currNode);
        bool FNHelper(BinaryNode<DataType>* currNode, BinaryNode<DataType>* qNode);
        void ShowHelper(BinaryNode<DataType>* currNode, int depth);
        BinaryNode<DataType>* FCAHelper(BinaryNode<DataType>* currNode, BinaryNode<DataType>* p, BinaryNode<DataType>* q);
        BinaryNode<DataType>* m_root;
};

template <typename DataType>
BinaryTree<DataType>::BinaryTree(){
    m_root = NULL;
}

template <typename DataType>
BinaryTree<DataType>::BinaryTree(BinaryNode<DataType> root){
    m_root = &root;
}

template <typename DataType>
BinaryTree<DataType>::BinaryTree(const BinaryTree& other){
    //shallow copy
    m_root = other.m_root;
}

template <typename DataType>
BinaryTree<DataType>& BinaryTree<DataType>::operator=(const BinaryTree<DataType>& other){
    if(other == this){
        return *this;
    }
    clear();
    //shallow copy
    m_root = other.m_root;
    return *this;
}

template <typename DataType>
BinaryTree<DataType>::~BinaryTree(){
    clear();
}

template <typename DataType>
void BinaryTree<DataType>::ArrayToBT(DataType* arr, int size){
    ArrayToBTHelper(arr, size, 0, m_root);
}

template <typename DataType>
BinaryNode<DataType>* BinaryTree<DataType>::ArrayToBTHelper(DataType* arr, int size, int index, BinaryNode<DataType>*& currNode){
    if(index < size){
        // Create node with data at index
        currNode = new BinaryNode<DataType>(arr[index]);

        // Insert Child nodes
        currNode->m_left = ArrayToBTHelper(arr, size, index*2 + 1, currNode->m_left);
        currNode->m_right = ArrayToBTHelper(arr, size, index*2 + 2, currNode->m_right);
    }
    return currNode;
}

template <typename DataType>
void BinaryTree<DataType>::clear(){
    //TODO: delete() tree from leaf nodes to root
}

template <typename DataType>
bool BinaryTree<DataType>::FindNode(BinaryNode<DataType>* qNode){
    return FNHelper(m_root, qNode);
}

template <typename DataType>
bool BinaryTree<DataType>::FNHelper(BinaryNode<DataType>* currNode, BinaryNode<DataType>* qNode){
    if(currNode == NULL){
        return false;
    }
    if(currNode == qNode){
        return true;
    }
    return FNHelper(currNode->m_left, qNode) || FNHelper(currNode->m_right, qNode);
}

template <typename DataType>
BinaryNode<DataType>* BinaryTree<DataType>::FirstCommonAncestor(BinaryNode<DataType>* p, BinaryNode<DataType>* q){
    if(FindNode(p) && FindNode(q)){
        return FCAHelper(m_root, p, q);
    } else {
        return NULL;
    }
}

template <typename DataType>
BinaryNode<DataType>* BinaryTree<DataType>::FCAHelper(BinaryNode<DataType>* currNode, BinaryNode<DataType>* p, BinaryNode<DataType>* q){
    // Base case - return null if inspecting invalid node
    if(currNode == NULL){
        return NULL;
    }
    // return current node if it matches both queried nodes
    if(currNode == p && currNode == q){
        return currNode;
    }

    // Inpsect left subtree for a solution
    BinaryNode<DataType>* lResult = FCAHelper(currNode->m_left, p, q);
    if(lResult && lResult != p && lResult != q){
        // Propogate FCA to original call
        return lResult;
    }

    // Inspect right subtree for a solution
    BinaryNode<DataType>* rResult = FCAHelper(currNode->m_right, p, q);
    if(rResult && rResult != p && rResult != q){
        // Propogate FCA to original call
        return rResult;
    }

    // If a solution exists for both subtrees, the current node is the first common ancestor
    if(lResult && rResult){
        return currNode;
    // If the current node is either queried node, return it
    } else if(currNode == p || currNode == q) {
        return currNode;
    } else {
        // If one subtree has a solution, return that solution (or return NULL if both subtrees lack a solution)
        if(rResult == NULL){
            return lResult;
        } else {
            return rResult;
        }
    }
}

template <typename DataType>
void BinaryTree<DataType>::ShowStructure(){
    if(m_root){
        cout << "BST Structure" << endl;
        ShowHelper(m_root, 0);
        cout << endl;
    } else {
        cout << "Empty BST" << endl;
    }
}

template <typename DataType>
void BinaryTree<DataType>::ShowHelper(BinaryNode<DataType>* currNode, int depth){
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