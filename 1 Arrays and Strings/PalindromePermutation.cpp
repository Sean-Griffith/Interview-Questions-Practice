/*
    Given a string, write a function to check if it is a permutation of
    a palindrome. A palindrome is a word or phrase that is the same 
    forwards and backwards. A permutation is a rearrangement of letters.
    The palindrome does not need to be limited to just dictionary words.
    You can ignore casing and non-letter characters.
*/
#include <iostream>
using namespace std;

bool checkPermPalindrome(string myString);

int main(){
    string example = "Tact Coa";

    if(checkPermPalindrome(example)){
        cout << "[" << example << "] is a permutation of a palindrome" << endl; 
    } else {
        cout << "[" << example << "] is not a permutation of a palindrome" << endl; 
    }
    
    
    return 1;
}

/*
    O(n) time complexity, O(1) space complexity
    Uses the fact that every palindrome must have at most
    one character with an odd count.
    
    Alternative approaches would be to check the number of odd counts
    while counting characters, or to utilize a bit vector for counting.
*/
bool checkPermPalindrome(string myString){
    char* myArray = &myString[0];
    int charCounter[52] = {0};
    //count alphabetical characters in string
    for(int i = 0; i < myString.length(); i++){
        int charVal = int(tolower(myString[i]));
        if(charVal >= 97 && charVal <= 122){
            charCounter[charVal-97]++;
        }
    }
    
    //check that only one character has an odd count, rest are even
    int numOdd = 0;
    for(int i = 0; i < 52; i++){
        if(charCounter[i] % 2 == 1){
            if(numOdd == 0){
                numOdd++;
            } else {
                return false;
            }
        }
    }
    return true;
}