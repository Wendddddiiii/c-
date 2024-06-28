// Messages are composed by the sender, Interpreted by the receiver, Implemented by methods
// Messages may cause receiver to change state, may return results

//object v.s. class
//object is a class, class defines object
//objects represent things, events or concepts, respond to messages 
// classes define propertities of instances, act like types


#include "TicketMachine.h"
#include <iostream>


using namespace std;

TicketMachine::TicketMachine() : PRICE(50), balance(0), total(0) {
    // Constructor initializes PRICE to 50, balance and total to 0
}

TicketMachine::~TicketMachine() {
    // Destructor
}

void TicketMachine::showPrompt() {
    cout << "Please insert money for a ticket. " << endl;

}

void TicketMachine::insertMoney(int money) {
    balance += money;
}

void TicketMachine::showBalance() {
    cout << balance << endl;
}

