/*
    Implement an algorithm to determine if a string has all unique characters.
    What if you cannot use additional data structures?
*/
#include <iostream>
using namespace std;

bool isUnique(string myString);

int main(){
    string userInput;
    cout << "Enter a string." << endl;
    cin >> userInput;
    if(isUnique(userInput)){
        cout << "The string entered was unique." << endl;
    } else {
        cout << "The string entered was not unique." << endl;
    }
    return 1;
}

/* 
    O(n) time complexity, O(1) space complexity
    - Takes advantage of an additional datastructure
    - Could also use a bit vector to lower space requirements

    Without an additional datastructure
    - (1) Compare every character in the string with every other character O(n^2)
    - (2) Sort string O(nlogn) and then search for duplicates linearly O(n) -> O(nlogn)
*/
bool isUnique(string myString){

    // Assume only ASCII characters are used in string
    bool myCounter[128] = {0};
    if(myString.length() > 128){
        return false;
    }

    for(int i = 0; i < myString.length(); i++){
        int charVal = int(myString.at(i));
        if(myCounter[charVal] == false){
            myCounter[charVal] = true;
        } else {
            return false;
        }
    }

    return true;
}