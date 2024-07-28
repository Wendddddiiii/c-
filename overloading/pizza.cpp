#include <iostream>

void bakePizza();
void bakePizza(std::string topping1);
void bakePizza(std::string topping1, std::string topping2);

int main() {
    bakePizza("pepperoni", "mushrooms");
    return 0;
}

void bakePizza() {
    std::cout << "Here is your plain pizza." << std::endl;
}


void bakePizza(std::string topping1) {
    std::cout << "Here is " << topping1  <<  " pizza" << std::endl;
}


void bakePizza(std::string topping1, std::string topping2) {
    std::cout << "Here is " << topping1 << "and" << topping2 <<  " pizza" << std::endl;
}





