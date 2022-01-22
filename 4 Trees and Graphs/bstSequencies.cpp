/*
    A binary tree was created by traversing through an array from left
    to right and inserting each element. Given a binary search tree with
    distinct elements, print all possible arrays that could have led to 
    this tree.

    EXAMPLE
    Input: 2->1
            ->3
    Output: {2, 1, 3}, {2, 3, 1}
*/

#include <iostream>
#include "BST.h"
using namespace std;

int main(){
    //int example[10] = {10,4,11,17,2,55,37,19,5,9};
    int example[4] = {10,1,2,3};
    BST<int> myBST;
    myBST.ArrayToBST(example, 4);
    myBST.ShowStructure();
    vector<list<int>*>* result = myBST.GenerateArraySequences();

    
    cout << "Result Sequencies:" << endl;
    
    for(auto it: *result){
        for(auto bt: *it){
            cout << bt << " ";
        }
        cout << endl;
    }

    return 1;
}