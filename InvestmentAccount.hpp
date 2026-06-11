#ifndef INVESTMENT_ACCOUNT_HPP
#define INVESTMENT_ACCOUNT_HPP

#include "Account.hpp"

class InvestmentAccount final : public Account {
public:
    InvestmentAccount(int id, const std::string& holderName,
                      double initialBalance, double annualRate);

    void applyInterest() override; 
    std::string typeName() const override;

private:
    double annualRate_;
};

#endif
