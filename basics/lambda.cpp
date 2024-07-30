#include <iostream>
#include <vector>
#include <algorithm> //for sort
using namespace std;

int main() {

    // a basic definition
    //[] {cout << "Hello world!";}

    // call that lambda
    [] {cout << "Hello world!" << endl;}();

    // assign a lambda to a variable
    auto p = []{cout << "Goodbye world!" << endl;};

    // call func
    p();    

    // add a parameter list to our lambda
    auto q = [](int a, int b){cout << a+b << endl; };

    q(1, 3);

    //lambdas can return values
    auto r = [](int a, int b){return a + b;};
    int x = r(1, 4);
    cout << x << endl;

    cout << r(7,10) << endl;

    auto s = [](int a, int b) -> int {return a + b;};
    cout << s(9,10) << endl;

    vector<int> v{8, 6, 10, 12, 99, 111};
    sort(v.begin(), v.end(), [](int a, int b) -> bool {return a < b;});

    for(int i : v ) {
        cout << i << endl;
    }

    //captures -- access to the outer scope
    int x1 = 4, y = 1;
    //by value, by ref
    auto t = [x1, &y] {
        cout << x1 << endl; 
        cout << y++ << endl;
    };
    t();
    //y increment by 1 after calling t()
    cout << y << endl;
    return 0;
}