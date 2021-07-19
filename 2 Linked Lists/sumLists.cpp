/*
    You have two numbers represented by a linked list, 
    where each node contains a single digit. The digits are
    stored in reverse order, such that the 1's digit is at the
    head of the list. Write a function that adds the two numbers
    and returns the sum as a linked list. (You are not allowed to
    "cheat" and just convert the linked list to an integer).

    EXAMPLE:

    Input: (7 -> 1 -> 6) + (5 -> 9 -> 2). That is, 617+295
    Output: 2 -> 1 -> 9, or 912

    FOLLOW UP:

    Suppose the digits are stored in forward order, repeat the above problem.
*/
#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(){
    
    List<int> example1, example2, example3, example4;
    //617
    example1.insert(7);
    example1.insert(1);
    example1.insert(6);
    //295
    example2.insert(5);
    example2.insert(9);
    example2.insert(2);
    //4827
    example3.insert(7);
    example3.insert(2);
    example3.insert(8);
    example3.insert(4);

    /*
        O(max(n,m)) time complexity where n is the number of elements in value 1
        and m is the number of elements in value 2.
        O(max(n,m)) space complexity to store the resulting sum

        sumList works by walking through each of the value lists and computing the 
        sum at each node. For each sum, a single digit remainder is placed in the 
        result list and any values greater than 10 generate a carry over value to 
        include in the next iteration's summation. This version of the algorithm
        assumes that the value of each number is placed in the lists in reverse order.

        FOLLOW UP

        Assuming the value of each number is placed in the lists in forward order, the 
        same algorithm could be used after first reversing the value lists, or without reversal
        this could be done by simply carrying the carry value over to the previously calculated
        node and recalculating its value (and the values of all prior nodes).
    */

    cout << "Adding same size values" << endl;
    example1.showStructure();
    example2.showStructure();

    cout << "\n" << "sumList result: " << example1.sumLists(example2) << endl;

    cout << "\n" << "Adding different size values" << endl;
    example2.showStructure();
    example3.showStructure();

    cout << "\n" << "sumList result: " << example2.sumLists(example3) << endl;

    cout << "\n" << "Adding different size values with empty value" << endl;
    example3.showStructure();
    example4.showStructure();

    cout << "\n" << "sumList result: " << example3.sumLists(example4) << endl;

    cout << "\n" << "Adding same size values with empty value" << endl;
    example4.showStructure();
    example4.showStructure();

    cout << "\n" << "sumList result: " << example4.sumLists(example4) << endl;
    
    return 1;
}
