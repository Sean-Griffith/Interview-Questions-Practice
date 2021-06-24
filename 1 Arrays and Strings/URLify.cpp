/*
    Write a method to replace all spaces in a string with '%20'. You may
    assume that the string has sufficient space at the end to hold the
    additional characters, and that you are given the "true" length of the
    string.

    EXAMPLE:
    Input: "Mr John Smith    ", 13
    Output: "Mr%20John%20Smith"
*/
#include <iostream>
using namespace std;

string urlify(char* myString, int length);
int countCharacters(const char* myString, int length, char myChar);

int main(){
    string example = "Mr John Smith    ";

    cout << "Result from urlify: [" << urlify(&example[0], 13) << "]" << endl; 

    return 1;
}

string urlify(char* myString, int length){
    int numSpaces = countCharacters(myString, length, ' ');
    // Modified index is the end of the string after '%20' has been
    // inserted at each ' ' character.
    int modifiedIndex = length - 1 + (numSpaces*2);

    for(int originalIndex = length-1; originalIndex >= 0; originalIndex--){
        if(myString[originalIndex] != ' '){
            //Move non-space chars to new index
            myString[modifiedIndex] = myString[originalIndex];
            modifiedIndex--;
        } else {
            //replace space with '%20'
            myString[modifiedIndex] = '0';
            myString[modifiedIndex-1] = '2';
            myString[modifiedIndex-2] = '%';
            modifiedIndex -= 3;
        }
    }

    string modifiedString(myString);
    return modifiedString;
}

int countCharacters(const char* myString, int length, const char myChar){
    int charCount = 0;
    for(int i = length-1; i >= 0; i--){
        if(myString[i] == myChar){
            charCount++;
        }
    }
    return charCount;
}