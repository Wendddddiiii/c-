//containers, algorithm, iterators
//top 3 data structure: 
//map: any key type, any value type
//vector: like c array, but auto-extending
//list: doubly-linked list
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> x;
    for(int a=0; a<1000; a++) {
        x.push_back(a);
    } 
    vector<int>::iterator p;
    for(p=x.begin(); p<x.end(); ++p) {
        cout << *p << " ";
    } 

    return 0;
}

