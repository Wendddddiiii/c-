#include <iostream>

class Position {
public:
    Position(int km) 
    : km_(km) {};
    Position& operator++(); //prefix
    Position operator++(int); //postfix
    void tick();
    int km() {return km_;};
private:
    int km_;
    void tick_() {++km_;};
};



Position& Position::operator++() {
    tick_();
    return *this;
}

Position Position::operator++(int) {
    Position temp = *this;
    tick_();
    return temp;
}

int main() {
    auto temp = Position(6);
    auto rp = Position(6);
    std::cout << temp.km() << std::endl;
    auto val1 = (temp++).km();
    auto val2 = (++rp).km();
    std::cout << "val1: " << val1 << std::endl;
    std::cout << "val2: " << val2 << std::endl;
}