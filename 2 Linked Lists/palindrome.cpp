/*
    Implement a function to check if a linked list is a palindrome
*/
#include <iostream>
#include "LinkedList.h"
using namespace std;

void checkPalindromeTest(List<char>& example);

int main(){
    List<char> example1, example2, example3, example4, example5;
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

    example3.insert('h');
    example3.insert('a');
    example3.insert('n');
    example3.insert('x');
    example3.insert('n');
    example3.insert('a');
    example3.insert('h');

    example4.insert('a');

    checkPalindromeTest(example1);
    checkPalindromeTest(example2);
    checkPalindromeTest(example3);
    checkPalindromeTest(example4);
    checkPalindromeTest(example5);

    return 1;
}

/*
    O(n+x) time complexity where x is the size of the character set
    O(x) space complexity 

    isPalindrome works by counting the number of each character that appears
    within the linked list, and ensuring that at most one character occurs once
    and the rest of the characters occur twice.
*/
void checkPalindromeTest(List<char>& example){
    example.showStructure();
    if(example.isPalindrome()){
        cout << "IS a palindrome." << endl;
    } else {
        cout << "IS NOT a palindrome." << endl;
    }
}
