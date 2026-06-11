# Final-Project-TC1030.302-Object-Oriented-Programming

# Proposal: Bank Account Management System 

Problem: A bank needs to manage clients holding multiple account types
(savings, checking, investment), each with different rules for interest,
withdrawals and overdraft, while enforcing the invariant that no balance
ever violates its allowed minimum, and recording every movement as a
transaction.

Why OOP: Account types share a contract (deposit, withdraw, apply
interest) but differ in behavior → a polymorphic hierarchy. Ownership is
hierarchical and clear: the bank owns its clients and clients own their
accounts (composition), while each account keeps a non-owning reference to
its holder (aggregation). The balance is a real invariant protected through
strict encapsulation and exceptions.

Planned classes:
- `Bank` — composition of clients; entry point.
- `Client` — composition of accounts; aggregation back-reference from Account.
- `Account` (abstract) — encapsulated balance, virtual destructor,
  pure virtual `applyInterest()`, `operator<<` and `operator==`.
- `SavingsAccount`, `CheckingAccount`, `InvestmentAccount` — inheritance
  with chained constructors, `override` everywhere, one `final` class.
- `Transaction` — value type with `operator<<` and `operator<`.
- `BankException` → `InsufficientFundsException`, `InvalidAmountException` —
  derived from `std::exception`, caught at the `main` boundary.

Ownership: Rule of Zero: all heap ownership through `std::unique_ptr`
and `std::vector` collections; accounts are non-copyable by domain
semantics (copying a bank account has no meaning).

Scope: Console interface with a demonstrative scenario in `main`.
No persistence, no networking, no STL `<algorithm>`.
