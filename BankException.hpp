#ifndef BANK_EXCEPTION_HPP
#define BANK_EXCEPTION_HPP

#include <exception>
#include <string>

class BankException : public std::exception {
public:
    explicit BankException(const std::string& message) : message_(message) {}
    const char* what() const noexcept override { return message_.c_str(); }

private:
    std::string message_;
};

class InsufficientFundsException : public BankException {
public:
    explicit InsufficientFundsException(const std::string& message)
        : BankException(message) {}
};

class InvalidAmountException : public BankException {
public:
    explicit InvalidAmountException(const std::string& message)
        : BankException(message) {}
};

#endif
