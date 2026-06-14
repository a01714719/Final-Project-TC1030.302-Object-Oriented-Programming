#include "Account.hpp"

#include "BankException.hpp"

Account::Account(int id, const std::string& holderName, double initialBalance)
    : id_(id), holderName_(holderName), balance_(initialBalance) {
    if (initialBalance < 0) {
        throw InvalidAmountException("initial balance cannot be negative");
    }
}

void Account::deposit(double amount) {
    if (amount <= 0) {
        throw InvalidAmountException("deposit amount must be positive");
    }
    balance_ += amount;
}

void Account::withdraw(double amount) {
    if (amount <= 0) {
        throw InvalidAmountException("withdrawal amount must be positive");
    }
    if (balance_ - amount < minimumBalance()) {
        throw InsufficientFundsException(
            "withdrawal would leave balance below the allowed minimum");
    }
    balance_ -= amount;
}

void Account::credit(double amount) {
    if (amount < 0) {
        throw InvalidAmountException("credit amount cannot be negative");
    }
    balance_ += amount;
}

double Account::minimumBalance() const {
    return 0.0;
}

int Account::id() const noexcept {
    return id_;
}

double Account::balance() const noexcept {
    return balance_;
}

bool Account::operator==(const Account& other) const {
    return id_ == other.id_;
}

std::ostream& operator<<(std::ostream& os, const Account& account) {
    os << account.typeName() << " #" << account.id_
       << " (" << account.holderName_ << ") balance: $" << account.balance_;
    return os;
}
