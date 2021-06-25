/*
    Implement a method to perform basic string compression
    using the counts of repeated characters. For example,
    the string aabcccccaaa would become a2b1c5a3. If the 
    "compressed" string would not become smaller than the
    original string, your method should return the original.
    You can assume the string has only uppercase and lowercase
    letters.
*/
#include <iostream>
using namespace std;

string compressString(string myString);

int main(){
    string example = "aabcccccaaa";
    string example2 = "abc";
    cout << compressString(example) << endl;
    cout << compressString(example2) << endl;
    return 1;
}

/*
    O(n + w) time complexity where
    n is the number of characters in the input string
    w is the number of individual sequences of characters
    This is because we must iterate through the entire string and
    string concatenation takes O(n) time (in c++ with mutable strings -
    other languages with immutable strings take O(n^2) time for string
    concatenation). 

    Another approach would be to use a string builder/buffer/stream to 
    construct the compressed string, and/or to determine the length of the 
    compressed string ahead of time to determine whether it is worth 
    creating in the first place (if its larger than the original, we
    don't need to create it).
*/
string compressString(string myString){

    if(myString.length() < 2){
        return myString;
    }

    string compressed = "";
    int currentCharCount = 1;
    char currentChar = myString[0];
    
    for(int i = 1; i < myString.length(); i++){
        if(myString[i] != currentChar || i == myString.length()-1){
            if(i == myString.length()-1){
                currentCharCount++;
            }
            compressed += currentChar + to_string(currentCharCount);
            currentChar = myString[i];
            currentCharCount = 1;
        } else {
            currentCharCount++;
        }
    }

    if(compressed.length() > myString.length()){
        return myString;
    } else {
        return compressed;
    }
}