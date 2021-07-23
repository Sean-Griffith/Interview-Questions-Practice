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

    for(int i = 0; i < N; i++){
        link1.insert(i);
        link2.insert(N-i);
        link3.insert(i*2);
        link3.insert(N);
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
    
*/
void checkIntersection(List<int>& combinationList, List<int>& otherList){
    combinationList.showStructure();
    otherList.showStructure();
    if(combinationList.isIntersection(otherList)){
        cout << "Intersection found." << endl;
    } else {
        cout << "Intersection not found." << endl;
    }
}