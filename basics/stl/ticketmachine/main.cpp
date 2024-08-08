
#include "TicketMachine.h"
#include <iostream>

int main() {
    TicketMachine tm;
    tm.showPrompt();
    tm.insertMoney(50);
    tm.insertMoney(590);
    tm.showBalance();
    return 0;
}