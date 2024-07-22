#include <istream>


class Foo {
public:
    using Age = int;

    Foo();
    Foo(std::istream& is);
    ~Foo();

    void member_func();
};