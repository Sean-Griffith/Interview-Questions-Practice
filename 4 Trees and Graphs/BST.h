#ifndef BST_H
#define BST_H

#include <iostream>
#include <stdexcept>
#include <list>
#include <vector>
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

        int GetDepth() const;
        vector<list<DataType>> ListOfDepths() const;
        bool isBalanced() const;
        bool isValidBST() const;

        void ArrayToBST(const int* arr, int size);
        void ArrayToMinBST(const int* arr, int size);

        void ShowStructure();
    private:
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
        int DepthHelper(BinaryNode* currNode) const;
        void ListOfDepthsHelper(BinaryNode* currNode, int depth, vector<list<DataType>>& depthLists) const;
        int isBalancedHelper(BinaryNode* currNode) const;
        bool isValidBSTHelper(BinaryNode* currNode, int min, int max) const;
        void ArrayToMinBSTHelper(const int* p, int size);

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

template <typename DataType>
int BST<DataType>::GetDepth() const {
    return DepthHelper(m_root);
}

template <typename DataType>
int BST<DataType>::DepthHelper(BinaryNode* currNode) const {
    if(!currNode){
        return 0;
    } 
    return 1 + max(DepthHelper(currNode->m_left), DepthHelper(currNode->m_right));
}

template <typename DataType>
vector<list<DataType>> BST<DataType>::ListOfDepths() const {
    vector<list<DataType>> depthLists;
    for(int i = 0; i < GetDepth(); i++){
        list<DataType> currLayerList;
        depthLists.push_back(currLayerList);
    }
    ListOfDepthsHelper(m_root, 0, depthLists);
    return depthLists;
}

template <typename DataType>
void BST<DataType>::ListOfDepthsHelper(BinaryNode* currNode, int depth, vector<list<DataType>>& depthLists) const {
    if(!currNode){
        return;
    }
    ListOfDepthsHelper(currNode->m_left, depth+1, depthLists);
    ListOfDepthsHelper(currNode->m_right, depth+1, depthLists);
    depthLists[depth].push_back(currNode->m_data);
}

template <typename DataType>
bool BST<DataType>::isBalanced() const {
    int heightDiff = isBalancedHelper(m_root);
    cout << "Height Diff: " << heightDiff << endl;
    if(heightDiff == -1){
        return false;
    } else {
        return true;
    }
}

template <typename DataType>
int BST<DataType>::isBalancedHelper(BinaryNode* currNode) const {
    if(!currNode){
        return 0;
    }
    
    int leftHeight = isBalancedHelper(currNode->m_left);
    int rightHeight = isBalancedHelper(currNode->m_right);
    cout << "Current Node: " << currNode->m_data << " LH: " << leftHeight << " RH: " << rightHeight << endl;
    if(abs(leftHeight - rightHeight) <= 1 && leftHeight != -1 && rightHeight != -1){  
        int totalHeight = 1 + max(leftHeight, rightHeight);
        return totalHeight;
    } else {
        //cout << "Unbalanced tree!" << endl;
        return -1;
    }
}

template <typename DataType>
bool BST<DataType>::isValidBST() const {
    return isValidBSTHelper(m_root, INT_MIN, INT_MAX);
}

template <typename DataType>
bool BST<DataType>::isValidBSTHelper(BinaryNode* currNode, int min, int max) const {
    if(!currNode){
        // Leaf node or empty tree
        return true;
    }
    cout << currNode->m_data << endl;
    // Traverse Left with current node as max value
    if(!isValidBSTHelper(currNode->m_left, min, currNode->m_data)){
        return false;
    }

    // Compare current node with min/max values to check for validity
    if(currNode->m_data <= min || currNode->m_data > max){
        return false;
    }

    // Traverse Right with current node as min value
    if(!isValidBSTHelper(currNode->m_right, currNode->m_data, max)){
        return false;
    }

    return true;
}

template <typename DataType>
void BST<DataType>::ArrayToBST(const int* arr, int size){
    for(int i = 0; i < size; i++){
        Insert(arr[i]);
    }
}

template <typename DataType>
void BST<DataType>::ArrayToMinBST(const int* arr, int size){
    ArrayToMinBSTHelper(arr, size);
}

template <typename DataType>
void BST<DataType>::ArrayToMinBSTHelper(const int* p, int size){
    if(size == 0){
        return;
    }

    if(size%2 == 1){
        int middle = (size+1)/2;

        Insert(*(p+middle-1));

        const int* q = p + middle;
        ArrayToMinBSTHelper(q, size-middle);
        ArrayToMinBSTHelper(p, middle-1);
    } else {
        ArrayToMinBSTHelper(p+1, size-1);
        Insert(*p);
    }
}

#endif