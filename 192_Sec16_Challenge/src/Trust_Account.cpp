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

void Trust_Account::print(std::ostream &os) const {
    os << "[Account Name: " << name
        << " | Account Balance: " << balance 
        << " | Account Interest Rate: " << int_rate
         << " | Withdraw Count: " << withdrawlCount
        << "]" << std::endl; 
}

//calculates the max amount user is able to withdrawl at one time
double Trust_Account::calculateMaxWithdraw(double currentBalance){
    return currentBalance*0.2;
}

bool Trust_Account::withdraw(double amount){

    if(withdrawlCount >= max_withdrawls){
        std::cout << "WITHDRAW FAILED FOR: " << name << std::endl 
                << "REASON: MAX ATTEMPTS REACHED" << std::endl;
        return false;
    } else if(amount >= calculateMaxWithdraw(balance)){
        std::cout << "WITHDRAW FAILED FOR: " << name << std::endl
                << "REASON: AMOUNT EXCEEDS WITHDRAWL LIMIT" << std::endl;
        return false;
    } else {
        std::cout << "WITHDRAW SUCCESSFUL" << std::endl;
        withdrawlCount += 1;
        return Savings_Account::withdraw(amount);
    }
}

std::string Trust_Account::getName() const{
    return this->name;
}