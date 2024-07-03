#include <iostream>
using namespace std;
#include <list>
#include <string>

int main() {
    list<string> s;
    s.push_back("hello");
    s.push_back("world");
    s.push_front("apple");
    s.push_front("orange");
    s.push_front("clair");
    list<string>::iterator p;
    for(p=s.begin(); p!=s.end(); p++) {
        cout << *p << " " << endl;
    }
};

//iterator在vector到末尾用 < 判断， 而在list用 != 判断 因为不一定小于
//You can compare vector iterators using < because the elements in a vector are stored contiguously in memory. This means you can determine the ordering of elements by comparing their memory addresses.

//std::list is a doubly linked list that supports bidirectional iterators. Bidirectional iterators allow moving forwards and backwards but do not support random access operations like <, <=, >, or >=.
// In a linked list, elements are not stored contiguously in memory, so you cannot determine their ordering based on memory addresses.