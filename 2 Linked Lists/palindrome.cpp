/*
    Implement a function to check if a linked list is a palindrome
*/
#include <iostream>
#include "LinkedList.h"
using namespace std;

void checkPalindromeTest(List<char> example);

int main(){
    List<char> example1, example2, example3;
    example1.insert('h');
    example1.insert('a');
    example1.insert('n');
    example1.insert('n');
    example1.insert('a');
    example1.insert('h');

    example2.insert('s');
    example2.insert('e');
    example2.insert('a');
    example2.insert('n');

    checkPalindromeTest(example1);
    checkPalindromeTest(example2);
    checkPalindromeTest(example3);

    return 1;
}

void checkPalindromeTest(List<char> example){
    example.showStructure();
    if(example.isPalindrome()){
        cout << "IS a palindrome." << endl;
    } else {
        cout << "IS NOT a palindrome." << endl;
    }
}
