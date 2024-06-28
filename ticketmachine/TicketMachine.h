#ifndef TICKETMACHINE_H_
#define TICKETMACHINE_H_

class TicketMachine { 
public: 
    TicketMachine();  // Constructor
    virtual ~TicketMachine();  // Destructor
    void showPrompt();  // Function to show prompt
    void insertMoney(int amount);  // Function to insert money
    void showBalance();  // Function to show balance
    void printTicket();  // Function to print a ticket
    void showTotal();  // Function to show total amount collected

private:
    const int PRICE;  // Price of one ticket
    int balance;  // Current balance
    int total;  // Total amount collected
};

#endif  // TICKETMACHINE_H_
