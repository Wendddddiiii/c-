#include <iostream>
#include <string>

using namespace std;

static int objectCount = 0;

class HowMany {

public: 
    HowMany() {objectCount++; print("HowMany()");}
    HowMany(int i) {objectCount++; print("HowMany(int)");}
    void print(const string& msg = " "){
        if(msg.size() != 0 ) cout << msg << ": ";
        cout << "objectCount" << objectCount << endl;
    }

    ~HowMany() {
        objectCount--;
        print("~HowMany()");
    }
};
//pass and return by value
HowMany f(HowMany x) {
    cout << "begin of f" << endl;
    x.print("x argument inside f()");
    cout << "end of f" << endl;
    return x;
}

int main() {
    HowMany h;
    h.print("after construction of h");
    HowMany h2 = 10;
    h.print("after call to f()");
}


//copy ctor guidline
//一旦写了一个类， 一定要给三个函数：1. default constructor 2. virtual destructor 3. copy constructor
//1. create your own copy ctor- not reply on default
//2. if don't need one, declare a private one
//prevents creation of a default copy construction
//generates a compiler error if try to pass-by-value
//don't need a definition

// copy ctor called!
// Person copy_func(char *who) {
//     Person local(who);
//     local.print();
//     return local; 
// }

// no copy needed!
// Person nocopy_func(char *who) {
//     return Person(who);
// } 

//用string,而不是char*

