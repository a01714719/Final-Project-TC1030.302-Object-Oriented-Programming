#ifndef SAVINGS_ACCOUNT_HPP
#define SAVINGS_ACCOUNT_HPP

#include "Account.hpp"

class SavingsAccount : public Account {
public:
    SavingsAccount(int id, const std::string& holderName,
                   double initialBalance, double interestRate,
                   int monthlyWithdrawalLimit);

    void withdraw(double amount) override;  
    void applyInterest() override;          
    std::string typeName() const override;

private:
    double interestRate_;
    int monthlyWithdrawalLimit_;
    int withdrawalsThisMonth_;
};

#endif
