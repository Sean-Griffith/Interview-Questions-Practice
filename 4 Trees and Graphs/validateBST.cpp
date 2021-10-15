/*
    Implement a function to check if a binary tree is a binary search tree.
*/

#include <iostream>
#include "BST.h"
using namespace std;

int main(){
    BST<int> example1;
    int exampleArr1[7] = {-44, 13, 17, 32, 51, 88, 201};
    example1.ArrayToMinBST(exampleArr1, 7);
    example1.ShowStructure();
    /*
        O(n) time complexity
        O(nlogn) space complexity

        Each node is traversed and compared against the current min/max range. 
        The range is updated upon travelling to a child node, with the max 
        value being updated when travelling to left nodes and the min updated
        when travelling to right nodes. If the node's value falls out of the
        specified range, it returns false and this propogates to the base call.

        O(n) is the best complexity possible as all algorithms will need to touch 
        every node, and O(nlogn) space complexity is due to the recursive calls being made
        creating activation frames on the stack, for which nlogn should be present with a
        balanced tree.
    */
    cout << example1.isValidBST() << endl;
    return 1;
}