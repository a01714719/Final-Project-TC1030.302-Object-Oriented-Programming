#include "SavingsAccount.hpp"

#include "BankException.hpp"

SavingsAccount::SavingsAccount(int id, const std::string& holderName,
                               double initialBalance, double interestRate,
                               int monthlyWithdrawalLimit)
    : Account(id, holderName, initialBalance),
      interestRate_(interestRate),
      monthlyWithdrawalLimit_(monthlyWithdrawalLimit),
      withdrawalsThisMonth_(0) {}

void SavingsAccount::withdraw(double amount) {
    if (withdrawalsThisMonth_ >= monthlyWithdrawalLimit_) {
        throw BankException("monthly withdrawal limit reached for savings account");
    }
    Account::withdraw(amount); 
    ++withdrawalsThisMonth_;
}

void SavingsAccount::applyInterest() {
    credit(balance() * interestRate_);
}

std::string SavingsAccount::typeName() const {
    return "SavingsAccount";
}
