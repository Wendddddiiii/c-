#include <iostream>

using namespace std;

//base class or super class
class Chef {
public:
    void makeChicken() {
        cout << "The chef makes chicken" << endl;
    }
    void makeSalad() {
        cout << "The chef makes salad" << endl;
    }
    void makeSpecial() {
        cout << "The chef makes special dishes of ice cream" << endl;
    }
};

//sub class 
class ItalianChef : public Chef {
public:
    void makePasta() {
        cout << "He can make pasta" << endl;
    }
    void makeSpecial() {
        cout << "The chef makes special dishes of risotto" << endl;
    }
};

int main() {
    Chef chef;
    chef.makeSpecial();
    ItalianChef italianchef;
    italianchef.makeSpecial();

    return 0;
}