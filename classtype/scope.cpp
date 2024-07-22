#include "scope.h"


Foo::Foo(){

}


Foo::Foo(std::istream& is){}

Foo::~Foo(){}


void Foo::member_func() {
    Foo::Age age;
    Age age;
}