/*
    Given two strings, write a method to decide if one is a permutation of the other.
*/
#include <iostream>
using namespace std;

// Assumes we are using ASCII character set
#define CHAR_SET_SIZE 128

bool isPermutation(string first, string second);

int main(){
    string userInput1, userInput2;

    cout << "Enter the first string." << endl;
    cin >> userInput1;
    cout << "Enter the second string." << endl;
    cin >> userInput2;

    if(isPermutation(userInput1, userInput2)){
        cout << "The strings are permutations of one-another." << endl;
    } else {
        cout << "The strings are not permutations of one-another." << endl;
    }

    return 1;
}

/*
    O(f + s + k) time complexity where
    f = size of first string
    s = size of second string
    k = size of character set

    Another possible implementation could be sorting both strings in O(nlogn)
    and then comparing them linearly. If they are identical, they are a permutation.
*/
bool isPermutation(string first, string second){
    if(first.length() < 1 || first.length() != second.length()){
        return false;
    }
    int charCounter[CHAR_SET_SIZE] = {0};
    // Add count of each character in first string, then subtract count of
    // each character in second string.
    for(int i = 0; i < first.length(); i++){
        charCounter[int(first.at(i))]++;
        charCounter[int(second.at(i))]--;
    }

    // Check that each character count is 0 
    // (first and second strings will cancel eachother if permutations)
    for(int i = 0; i < CHAR_SET_SIZE; i++){
        if(charCounter[i] != 0){
            return false;
        }
    }
    return true;
}