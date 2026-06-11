#ifndef CHECKING_ACCOUNT_HPP
#define CHECKING_ACCOUNT_HPP

#include "Account.hpp"

class CheckingAccount : public Account {
public:
    CheckingAccount(int id, const std::string& holderName,
                    double initialBalance, double overdraftLimit);

    void applyInterest() override;  
    std::string typeName() const override;

protected:
    double minimumBalance() const override; 

private:
    double overdraftLimit_;
};

#endif
