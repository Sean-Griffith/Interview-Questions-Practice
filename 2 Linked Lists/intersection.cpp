/*
    Given two (singly) linked lists, determine if the two lists intersect. 
    Return the intersecting node. Note that the intersection is based on
    reference, not value. That is, if the kth node of the first linked list
    is the exact same node (by reference) as the jth node in the second linked
    list, they are intersecting.
*/
#include <iostream>
#include "LinkedList.h"
using namespace std;

#define N 5

void checkIntersection(List<int>& combinationList, List<int>& otherList);

int main(){
    List<int> link1, link2, link3, combined1, combined2, empty;

    /*
    for(int i = 0; i < N; i++){
        link1.insert(i);
        link2.insert(N-i);
        link3.insert(i*2);
        link3.insert(N);
    }
    */
    for(int i = 0; i < N; i++){
        link1.insert(1);
        link2.insert(2);
        link3.insert(3);
    }

    checkIntersection(link2, link3);

    combined1.generateCombinedList(link1, link2);
    checkIntersection(combined1, link2);

    combined2.generateCombinedList(link3, link2);
    checkIntersection(combined2, link3);

    checkIntersection(link1, empty);
    checkIntersection(empty, link1);
    
    return 1;
}

/* 
    O(n) time complexity
    O(1) space complexity

    Finds the length of both lists by moving the cursor until the end.
    If both lists have the same address for the final node, they are 
    intersected. To find the intersecting node, we move the cursor k nodes
    through the longer list, where:
    k = abs(a-b)
    a = length of list 1
    b = length of list 2
*/
void checkIntersection(List<int>& combinationList, List<int>& otherList){
    cout << "[1] Combination: ";
    combinationList.showStructure();
    cout << "[2] Comparison: ";
    otherList.showStructure();
    List<int> result = combinationList.isIntersection(otherList);
    if(!result.isEmpty()){
        cout << "Intersection found. Intersected at node: " << result.getCursorValue() << endl;
    } else {
        cout << "Intersection not found." << endl;
    }
}