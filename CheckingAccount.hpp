#include "CheckingAccount.hpp"

CheckingAccount::CheckingAccount(int id, const std::string& holderName,
                                 double initialBalance, double overdraftLimit)
    : Account(id, holderName, initialBalance),
      overdraftLimit_(overdraftLimit) {}

void CheckingAccount::applyInterest() {
    // Checking accounts do not earn interest.
}

std::string CheckingAccount::typeName() const {
    return "CheckingAccount";
}

double CheckingAccount::minimumBalance() const {
    return -overdraftLimit_;
}
