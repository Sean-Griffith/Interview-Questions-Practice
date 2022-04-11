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
        string ToString();

        void clear();
        bool FindNode(BinaryNode<DataType>* qNode);
        
        BinaryNode<DataType>* FirstCommonAncestor(BinaryNode<DataType>* p, BinaryNode<DataType>* q);
        bool checkSubtree(BinaryTree<DataType> subTree);

        int PathsWithSum(int sum);

        void ShowStructure();
        
    private:
        BinaryNode<DataType>* ArrayToBTHelper(DataType* arr, int size, int index, BinaryNode<DataType>*& currNode);
        bool FNHelper(BinaryNode<DataType>* currNode, BinaryNode<DataType>* qNode);
        string ToStringHelper(BinaryNode<DataType>* currNode);
        bool SubtreeHelper(BinaryNode<DataType>* currNode, string subTreeString);
        void ShowHelper(BinaryNode<DataType>* currNode, int depth);
        int PathsHelper(BinaryNode<DataType>* currNode, int sum);
        int PathSumHelper(BinaryNode<DataType>* currNode, int targetSum, int currSum);
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
string BinaryTree<DataType>::ToString(){
    return ToStringHelper(m_root);
}

template <typename DataType>
bool BinaryTree<DataType>::checkSubtree(BinaryTree<DataType> subTree){
    string subTreeString = subTree.ToString();
    return SubtreeHelper(m_root, subTreeString);
}

template <typename DataType>
bool BinaryTree<DataType>::SubtreeHelper(BinaryNode<DataType>* currNode, string subTreeString){
    if(currNode == NULL){
        return false;
    }
    // Check left and right subtrees first (Post order traversal)
    bool leftR = SubtreeHelper(currNode->m_left, subTreeString);
    bool rightR = SubtreeHelper(currNode->m_right, subTreeString);

    if(leftR || rightR){
        return true;
    }
    // Convert current node data to string
    string currString = to_string(currNode->m_data);
    // Compare current nodes data to root node of subtree string
    if(currString == subTreeString.substr(subTreeString.length() - currString.length())){
        //If the current node matches the root of the subtree, check if match
        if(ToStringHelper(currNode) == subTreeString){
            return true;
        }
    }
    
    return false;
}

template <typename DataType>
string BinaryTree<DataType>::ToStringHelper(BinaryNode<DataType>* currNode){
    string result;
    if(currNode == NULL){
        result = "X";
    } else {
        // String is concatenated as left branch + right branch + current node (post-order traversal)
        string leftR = ToStringHelper(currNode->m_left);
        string rightR = ToStringHelper(currNode->m_right);
        result = leftR + rightR + to_string(currNode->m_data);
    }
    return result;
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
int BinaryTree<DataType>::PathsWithSum(int sum){
    return PathsHelper(m_root, sum);
}

template <typename DataType>
int BinaryTree<DataType>::PathsHelper(BinaryNode<DataType>* currNode, int sum){
    if(currNode == NULL){
        return 0;
    }

    // Check for paths with sum from current node
    int numPaths = PathSumHelper(currNode, sum, 0);

    // Repeat for left and right nodes
    numPaths += PathsHelper(currNode->m_left, sum);
    numPaths += PathsHelper(currNode->m_right, sum);

    // Sum left/right + current and return
    return numPaths;
}

template <typename DataType>
int BinaryTree<DataType>::PathSumHelper(BinaryNode<DataType>* currNode, int targetSum, int currSum){
    if(currNode == NULL){
        return 0;
    }

    // Add current value to sum
    currSum += currNode->m_data;

    int sumPaths = 0;
    // Check if sum reached
    if(currSum == targetSum){
        sumPaths++;
    }

    // Repeat for left and right nodes
    sumPaths += PathSumHelper(currNode->m_left, targetSum, currSum);
    sumPaths += PathSumHelper(currNode->m_right, targetSum, currSum);

    return sumPaths;
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