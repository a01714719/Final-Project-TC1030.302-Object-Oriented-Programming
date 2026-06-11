#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>
#include <string>

class Account {
public:
    Account(int id, const std::string& holderName, double initialBalance);
    virtual ~Account() = default;

    Account(const Account&) = delete;
    Account& operator=(const Account&) = delete;

    void deposit(double amount);
    virtual void withdraw(double amount);
    virtual void applyInterest() = 0;
    virtual std::string typeName() const = 0;

    int id() const noexcept;
    double balance() const noexcept;

    bool operator==(const Account& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Account& account);

protected:
    void credit(double amount);
    virtual double minimumBalance() const;

private:
    int id_;
    std::string holderName_;
    double balance_;
};

#endif
