/*
    Write code to partition a linked list around a value x, 
    such that all nodes less than x come before all nodes greater 
    than or equal to x. (IMPORTANT: the partition element x can appear
    anywhere in the "right partition"; it does not need to appear
    between the left and right partitions. The additional spacing in
    the example below indicates the partition. Yes, the output below is 
    one of many valid outputs!)

    EXAMPLE:
    Input: 3 -> 5 -> 8 -> 10 -> 2 -> 1 [partition=5]
    Output: 3 -> 1 -> 2      ->      10 -> 5 -> 5 -> 8
*/
#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(){

    List<int> example;
    example.insert(3);
    example.insert(5);
    example.insert(8);
    example.insert(10);
    example.insert(2);
    example.insert(1);

    example.showStructure();
    /*
        O(n) time complexity
        O(1) space complexity

        Partition works by walking through the linked list, 
        ignoring elements less than the partition until an element
        greater than or equal to the partition is found, upon which
        the partition is inserted. From now on, all elements smaller
        than the partition are moved to the front of the list.

        Additional solutions might include making two separate lists
        1 list would include all < partition elements
        1 list would include all >= partition elements
        These two lists could be merged to generate the solution

        Another solution could be to make one separate list with all
        >= parition elements. When these elements are added to the list,
        they can be removed from the original list, and then the two lists
        can be merged with the partition between or after them.
    */
    int partition = 0;
    cout << "Input a number to partition with:" << endl;
    cin >> partition;

    example.partition(partition);
    example.showStructure();
    
    return 1;
}
