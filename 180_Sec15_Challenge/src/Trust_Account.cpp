#include "../headers/Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account{name, balance, int_rate}, withdrawlCount{0} {}

bool Trust_Account::deposit(double amount){
    if(amount >= bonusThreshold){
        amount += bonusAmount;
        return Savings_Account::deposit(amount);
    } else {
        return Savings_Account::deposit(amount);
    }
}

//calculates the max amount user is able to withdrawl at one time
double Trust_Account::calculateMaxWithdraw(double currentBalance){
    return currentBalance*0.2;
}

bool Trust_Account::withdraw(double amount){
    if(withdrawlCount >= max_withdrawls){
        return false;
    } else if(amount >= calculateMaxWithdraw(balance)){
        return false;
    } else { 
        withdrawlCount += 1;
        return Savings_Account::withdraw(amount);
    }
}   

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "% " 
        << account.withdrawlCount << "]";
    return os;
}