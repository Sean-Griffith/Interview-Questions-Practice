#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> test;
    int a = test.front();
    cout << test.size() << " " << a << endl;

    list<int>* ap = new list<int>;
    ap->push_back(1);
    list<int>* bp = new list<int>;
    bp->push_back(2);

    ap->merge(*bp);

    for(auto it: *ap){
        cout << it << " ";
    }
    cout << endl;

    for(auto it: *bp){
        cout << it << " ";
    }
    cout << endl;

    return 0;
}