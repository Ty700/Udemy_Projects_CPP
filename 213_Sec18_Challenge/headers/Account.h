// Fully abstract Account 
#pragma once
#include "I_Printable.h"
#include "IllegalBalanceException.h"
#include "InsufficentFundsException.h"

class Account : public I_Printable, public IllegalBalanceExecption, public InsufficentFundsException{
 
private:
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;

protected:
    std::string name;
    double balance;

public:
    Account(std::string name = def_name, double balance = def_balance);
    
    virtual bool deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual void print(std::ostream &os) const = 0;
    virtual std::string getName() const = 0;
    
    virtual ~Account() {}
};
