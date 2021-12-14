/*
    Design an algorithm and write code to find the first common ancestor
    of two nodes in a binary tree. Avoid storing additional nodes in a 
    data structure. NOTE: This is not necessarily a binary search tree.
*/

#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main(){
    BinaryNode<int> root(2);
    BinaryNode<int>* q = new BinaryNode<int>(17);
    BinaryNode<int>* p = new BinaryNode<int>(37);

    BinaryNode<int>* a = new BinaryNode<int>(111);
    BinaryNode<int>* b = new BinaryNode<int>(222);

    root.m_left = new BinaryNode<int>(10);
    root.m_right = new BinaryNode<int>(30);
    root.m_left->m_left = new BinaryNode<int>(55);
    root.m_left->m_right = new BinaryNode<int>(15);
    root.m_left->m_right->m_right = q;
    root.m_left->m_left->m_left = new BinaryNode<int>(3);
    root.m_left->m_left->m_right = p;

    BinaryTree<int> example(root);
    /*
        O(n) time complexity - every node may be touched

        This solution finds the first common ancestor of two nodes
        by starting at the root node of a binary tree and recursively searching the left
        and right subtrees for the queried nodes. When a solution is found in both the right
        and left subtree, it means that the current node is the first common ancestor, and the 
        result is then propogated to the original function call. 
        
        This solution requires that the binary tree is searched for both query nodes, otherwise 
        if only one node exists within the tree, that node is faultily returned as the solution.
    */
    BinaryNode<int>* result = example.FirstCommonAncestor(p, q);
    if(result){
        cout << "The common ancestor of " << p->m_data << " and " << q->m_data << " is: " << result->m_data << endl;
    } else {
        cout << "No common ancestor could be found - either p or q does not exist in the tree." << endl;
    }
    

    return 1;
}