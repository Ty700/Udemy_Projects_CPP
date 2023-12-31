#include "../headers/Account.h"

Account::Account(std::string name, double balance) 
    : name{name}, balance{balance} {}

bool Account::deposit(double amount) {
    if (amount < 0) 
        return false;
    else {
        balance += amount;
        return true;
    }
}

bool Account::withdraw(double amount) {
    if (balance - amount >=0) {
        balance -= amount;
        return true;
    } else {
        std::cout << "WITHDRAWL FAILED FOR: " << name << std::endl
                << "REASON: INSUFFICENT FUNDS" << std::endl;
        return false;
    }
}

