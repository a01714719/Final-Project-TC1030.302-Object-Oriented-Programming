#include "InvestmentAccount.hpp"

InvestmentAccount::InvestmentAccount(int id, const std::string& holderName,
                                     double initialBalance, double annualRate)
    : Account(id, holderName, initialBalance),
      annualRate_(annualRate) {}

void InvestmentAccount::applyInterest() {
   
    credit(balance() * (annualRate_ / 12.0));
}

std::string InvestmentAccount::typeName() const {
    return "InvestmentAccount";
}
