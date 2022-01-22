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
        DataType FindSuccessor(DataType value) const;
        
        vector<list<DataType>*>* GenerateArraySequences();

        void ArrayToBST(const int* arr, int size);
        void ArrayToMinBST(const int* arr, int size);

        void ShowStructure();
        
    private:
        class BinaryNode{
            public:
                BinaryNode(DataType data, BinaryNode* parent, BinaryNode* left=NULL, BinaryNode* right=NULL){
                    m_data = data;
                    m_parent = parent;
                    m_left = left;
                    m_right = right;
                }
                BinaryNode* m_left;
                BinaryNode* m_right;
                BinaryNode* m_parent;
                DataType m_data;
        };

        BinaryNode* FindNode(DataType value) const;
        void FindNodeHelper(BinaryNode* currNode, DataType value, BinaryNode*& foundNode) const;
        void InsertHelper(DataType value, BinaryNode*& currNode, BinaryNode*& parentNode);
        void ShowHelper(BinaryNode* currNode, int depth);
        int DepthHelper(BinaryNode* currNode) const;
        void ListOfDepthsHelper(BinaryNode* currNode, int depth, vector<list<DataType>>& depthLists) const;
        int isBalancedHelper(BinaryNode* currNode) const;
        bool isValidBSTHelper(BinaryNode* currNode, int min, int max) const;
        void ArrayToMinBSTHelper(const int* p, int size);
        vector<list<DataType>*>* ArraySequencesHelper(BinaryNode* currNode);
        void MixSequences(list<DataType>*& start, list<DataType>*& middle, list<DataType>*& end, vector<list<DataType>*>*& sequences);
        void printList(list<DataType>* myList);

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
    if(m_root == NULL){
        m_root = new BinaryNode(value, NULL);
    } else {
        InsertHelper(value, m_root, m_root);
    }
}

template <typename DataType>
void BST<DataType>::InsertHelper(DataType value, BinaryNode*& currNode, BinaryNode*& parentNode){
    if(currNode == NULL){
        cout << "Inserting " << value << " with parent " << parentNode->m_data << endl;
        currNode = new BinaryNode(value, parentNode);
        return;
    }
    if(currNode->m_data >= value){
        InsertHelper(value, currNode->m_left, currNode);
    } else {
        InsertHelper(value, currNode->m_right, currNode);
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
    if(currNode->m_parent){
        cout << currNode->m_parent->m_data << endl;
    }
    
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
DataType BST<DataType>::FindSuccessor(DataType value) const{
    // Find the node indicated by value
    BinaryNode* queryNode = FindNode(value);
    // Check for right subtree - if found, return leftmost node in subtree
    // else - go to parent nodes until approaching parent from left child
    if(queryNode->m_right){
        // Travel down left path until leaf found
        queryNode = queryNode->m_right;
        while(queryNode->m_left){
            queryNode = queryNode->m_left;
        }
    } else {
        BinaryNode* child = queryNode;
        queryNode = queryNode->m_parent;
        
        while(child != queryNode->m_left){
            if(queryNode != m_root){
                child = queryNode;
                queryNode = queryNode->m_parent;
            } else {
                throw logic_error("Node has no in-order successor");
            }
        }
    }
    

    // if value was right node, repeat until travelling to parent from left

    // if never travelled to parent from left, value was rightmost node in tree
    return queryNode->m_data;
}

template <typename DataType>
typename BST<DataType>::BinaryNode* BST<DataType>::FindNode(DataType value) const {
    BinaryNode* foundNode = NULL;
    FindNodeHelper(m_root, value, foundNode);
    if(foundNode){
        return foundNode;
    } else {
        throw logic_error("Could not find specified node.");
    }
}

template <typename DataType>
void BST<DataType>::FindNodeHelper(BinaryNode* currNode, DataType value, BinaryNode*& foundNode) const {
    if(!currNode){
        return;
    }
    if(currNode->m_data == value){
        foundNode = currNode;
    } else {
        if(currNode->m_data < value){
            FindNodeHelper(currNode->m_right, value, foundNode);
        } else {
            FindNodeHelper(currNode->m_left, value, foundNode);
        }
    }
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

template <typename DataType>
vector<list<DataType>*>* BST<DataType>::GenerateArraySequences(){
    return ArraySequencesHelper(m_root);
}

template <typename DataType>
vector<list<DataType>*>* BST<DataType>::ArraySequencesHelper(BinaryNode* currNode){
    vector<list<DataType>*>* result = new vector<list<DataType>*>; // DELETE
    if(currNode == NULL){
        list<DataType>* subResult = new list<DataType>; // DELETE
        result->push_back(subResult);
        return result;
    }
    
    list<DataType>* startOf = new list<DataType>; // DELETE
    startOf->push_back(currNode->m_data);
    
    vector<list<DataType>*>* resultLeft = ArraySequencesHelper(currNode->m_left);
    vector<list<DataType>*>* resultRight = ArraySequencesHelper(currNode->m_right);

    cout << "Tracking: " << startOf->front() << endl;
    cout << "Subtrees: " << resultLeft->size() << " " << resultRight->size() << endl;

    for(int i = 0; i < resultLeft->size(); i++){
        for(int j = 0; j < resultRight->size(); j++){
            vector<list<DataType>*>* sequences = new vector<list<DataType>*>;
            list<DataType>* lRP = (*resultLeft)[i];
            list<DataType>* rRP = (*resultRight)[j];
            MixSequences(startOf, lRP, rRP, sequences);
            result->insert(result->end(), sequences->begin(), sequences->end());
        }
    }

    //cout << " Hi4 " << endl;
    
    return result;
}

template <typename DataType>
void BST<DataType>::MixSequences(list<DataType>*& start, list<DataType>*& middle, list<DataType>*& end, vector<list<DataType>*>*& sequences){

    /*cout << "start: ";
    printList(start);
    cout << "middle: ";
    printList(middle);
    cout << "end: ";
    printList(end);
    cout << endl;*/

    cout << "Hi0" << endl;

    if(middle->size() == 0 || end->size() == 0){
        //cout << "Hia" << endl;
        list<DataType>* sequence(start);
        //cout << "Hib" << endl;
        //sequence->merge(*middle);
        for(auto it: *middle){
            sequence->push_back(it);
        }
        //cout << "Hic" << endl;
        //sequence->merge(*end);
        for(auto it: *end){
            sequence->push_back(it);
        }
        //cout << "Hid" << endl;
        printList(sequence);
        sequences->push_back(sequence);
        //cout << "Hie" << endl;
        return;
    }

    //cout << "Hi1, SIZES: START | MIDDLE | END" << endl;
    //cout << start->size() << " " << middle->size() << " " << end->size() << endl;
    
    DataType middleTrim = middle->front();
    middle->pop_front();
    start->push_back(middleTrim);
    MixSequences(start, middle, end, sequences);
    start->pop_back();
    middle->push_front(middleTrim);

    //cout << "Hi2" << endl;

    DataType endTrim = end->front();
    end->pop_front();
    start->push_back(endTrim);
    MixSequences(start, middle, end, sequences);
    start->pop_back();
    end->push_front(endTrim);

    //cout << "Hi3" << endl;
    
}

template <typename DataType>
void BST<DataType>::printList(list<DataType>* myList){
    for(auto it: *myList){
        cout << it << " ";
    }
    cout << endl;
}

#endif