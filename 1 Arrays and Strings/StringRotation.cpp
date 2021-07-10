/*
    Assume you have a method isSubstring which checks if one word 
    is a substring of another. Given two strings, s1 and s2, write
    code to check if s2 is a rotation of s1 using only one call
    to isSubstring (e.g., "waterbottle" is a rotation of "erbottlewat").
*/
#include <iostream>
using namespace std;

bool checkRotation(string s1, string s2);
bool isSubstring(string s1, string s2);

int main(){
    string example = "waterbottle";
    string example2 = "erbottlewat";

    if(checkRotation(example, example2) == true){
        cout << "Rotation found" << endl;
    } else {
        cout << "No rotation found" << endl;
    }
    
    return 1;
}

/*
    
*/
bool checkRotation(string s1, string s2){
    return false;
}

bool isSubstring(string s1, string s2){
    if(s1.find(s2) != string::npos || s2.find(s1) != string::npos){
        return true;
    } else {
        return false;
    }
}