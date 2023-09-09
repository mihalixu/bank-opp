#pragma once

#include <iostream>
#include <string>

namespace bank { 

class Account{
public:
    Account(std::string owner) : owner_(owner) {
        number_ = next_number_;
        next_number_++;
    }

    Account(std::string owner, unsigned int deposit) : owner_(owner),balance_(deposit) {
        number_ = next_number_;
        next_number_++;
    }

    void deposit(unsigned int ammout) { balance_ += ammout;}
    virtual unsigned int withdraw(unsigned int amount);
    long long balance() const { return balance_; }
    unsigned long number() const { return number_; }
    std::string owner() const { return owner_; }
private:
    std::string owner_;
    unsigned long number_;
    unsigned long next_number_ = 7483919474;
    long long balance_ = 0;
};


class ChildAccount : public Account{
public:
    ChildAccount(std::string owner) : Account(owner) {}
    ChildAccount(std::string owner, unsigned int deposit) : Account(owner,deposit){}
    unsigned int withdraw(unsigned int amount) override;
private:
};

class TransferAccount: public Account{
public:
    TransferAccount(std::string owner): Account(owner) {}
    TransferAccount(std::string owner,unsigned int amount): Account(owner,amount) {}
    void transfer(Account& target, unsigned int amount);
private:
};

std::ostream& operator<<(std::ostream& out,const Account& acc);

} // bank