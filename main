#include <iostream>
#include <memory>
#include <vector>

#include "Account.hpp"
#include "BankException.hpp"
#include "CheckingAccount.hpp"
#include "InvestmentAccount.hpp"
#include "SavingsAccount.hpp"

int main() {
    // A polymorphic collection of accounts owned through unique_ptr.
    std::vector<std::unique_ptr<Account>> accounts;
    accounts.push_back(
        std::make_unique<SavingsAccount>(101, "Ana Torres", 1000.0, 0.04, 2));
    accounts.push_back(
        std::make_unique<CheckingAccount>(102, "Ana Torres", 500.0, 300.0));
    accounts.push_back(
        std::make_unique<InvestmentAccount>(201, "Luis Mejia", 2000.0, 0.12));

    std::cout << "=== Initial state ===\n";
    for (const auto& account : accounts) {
        std::cout << *account << "\n";
    }

    std::cout << "\n=== Normal operations ===\n";
    accounts[0]->deposit(250.0);
    accounts[1]->withdraw(700.0);  // valid: overdraft covers it
    std::cout << "deposit and overdraft withdrawal done\n";

    std::cout << "\n=== Invalid operations (caught) ===\n";
    try {
        accounts[1]->withdraw(5000.0);
    } catch (const BankException& e) {
        std::cout << "rejected: " << e.what() << "\n";
    }
    try {
        accounts[0]->deposit(-50.0);
    } catch (const BankException& e) {
        std::cout << "rejected: " << e.what() << "\n";
    }

    std::cout << "\n=== Polymorphic interest ===\n";
    for (const auto& account : accounts) {
        account->applyInterest();  // each type applies its own rule
        std::cout << *account << "\n";
    }

    return 0;
}
