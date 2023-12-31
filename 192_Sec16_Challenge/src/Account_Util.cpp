#include "../headers/Account_Util.h"

std::vector<Account *> createAccounts(){
    std::vector<Account *> ptrToObjs;

    //I HAVEN'T LEARNED SHARED POINTERS YET 
    Account *checking_acc = new Checking_Account("Checking Acc");
    Account *savings_acc = new Savings_Account("Savings Acc", 0, 1.5);
    Account *trust_acc = new Trust_Account("Trust Acc", 0 , 5);

    ptrToObjs.push_back(checking_acc);
    ptrToObjs.push_back(savings_acc);
    ptrToObjs.push_back(trust_acc);

    return ptrToObjs;
}

void displayAll(const std::vector<Account *> &acc){
    for(auto i: acc){
        std::cout << *i << std::endl;
    }
}

void display(const Account &acc){
    std::cout << acc << std::endl;
}

void deposit(const std::vector<Account *> &acc, double amount){
    for(auto i: acc){
        i->deposit(amount);
    }
    displayAll(acc);
}


void withdraw(const std::vector<Account *> &acc, double amount){
    for(auto i: acc){
        i->withdraw(amount);
    }
    displayAll(acc);
}

