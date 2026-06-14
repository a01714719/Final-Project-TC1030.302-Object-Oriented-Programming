#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include <iostream>
#include <string>


class Transaction {
public:
    Transaction(int sequence, const std::string& kind, double amount)
        : sequence_(sequence), kind_(kind), amount_(amount) {}

    int sequence() const noexcept { return sequence_; }
    double amount() const noexcept { return amount_; }


    bool operator<(const Transaction& other) const {
        return sequence_ < other.sequence_;
    }

    friend std::ostream& operator<<(std::ostream& os, const Transaction& t) {
        os << "[" << t.sequence_ << "] " << t.kind_ << " $" << t.amount_;
        return os;
    }

private:
    int sequence_;
    std::string kind_;
    double amount_;
};

#endif
