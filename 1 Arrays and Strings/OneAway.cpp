/*
    There are three types of edits that can be performed on strings:
    (1) insert a character
    (2) remove a character
    (3) replace a character

    Given two strings, write a function to check if they are one edit
    (or zero edits) away.
*/
#include <iostream>
using namespace std;

bool oneAway(string first, string second);

int main(){
    string example1 = "pale";
    string example2 = "ple";
    string example3 = "pales";
    string example4 = "bale";
    string example5 = "bake";
    string example6 = "pake";

    cout << "Example 1/2: " << oneAway(example1, example2) << endl;
    cout << "Example 3/1: " << oneAway(example3, example1) << endl;
    cout << "Example 1/4: " << oneAway(example1, example4) << endl;
    cout << "Example 1/5: " << oneAway(example1, example5) << endl;
    cout << "Example 1/6: " << oneAway(example1, example6) << endl;

    return 1;
}

/*
    O(n) time complexity, O(1) space complexity
    Iterates through both arrays simultaneously to search
    for differences. If a difference is found, the next character
    of both arrays is analyzed to check for another match. If the 
    match is found, move forward, with no more room for error.
*/
bool oneAway(string firstStr, string secondStr){
    int firstLen = firstStr.length();
    int secondLen = secondStr.length();

    if(abs(firstLen - secondLen) > 1){
        return false;
    }

    char* first = &firstStr[0];
    char* second = &secondStr[0];

    int difference = false;
    for(int i = 0, j = 0; i < firstLen && j < secondLen;){
        cout << "Comparing " << first[i] << " and " << second[j] << endl;
        if(first[i] != second[j]){
            if(difference == true){
                return false;
            } else {
                difference = true;
                if(i+1 < firstLen && first[i+1] == second[j]){
                    i++;
                } else if(j+1 < secondLen && second[j+1] == first[i]){
                    j++;
                }
            }
        }
        i++;
        j++;
    }
    return true;
}