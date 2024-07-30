#include <iostream>

using namespace std;

class Foo {
private:
    char x, y, z;
    //to avoid repeat code of initialize x y z
    void init() {
        x = y = z = '!';
    }

public:
    Foo() {
        init();
    }

    Foo(char z) {
        init();
        this->z = z;
    }
    //Foo(char z) : Foo(){this->z = z};

    friend ostream& operator<<(ostream& o, const Foo& f) {
        o << "(" << f.x << ", " << f.y << ", " << f.z << ")" << endl;
        return o;
    }
};


int main() {
    Foo alpha;
    cout << alpha << endl;

    Foo beta('#');
    cout << beta << endl;    
    return 0;
}