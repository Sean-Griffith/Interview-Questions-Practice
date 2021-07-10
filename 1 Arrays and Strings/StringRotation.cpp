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
    O(n) time complexity

    Utilizes the fact that a rotated string has a pivot point such that
    s1 = xy, s2 = yx, where s2+s2 = yxyx, which can utilize substring
    to find "xy", which is equivalent to s1's "xy".
*/
bool checkRotation(string s1, string s2){
    if(s1.length() != s2.length()){
        return false;
    }

    if(isSubstring(s1, s2.append(s2))){
        return true;
    } else {
        return false;
    }
}

bool isSubstring(string s1, string s2){
    if(s1.find(s2) != string::npos || s2.find(s1) != string::npos){
        return true;
    } else {
        return false;
    }
}