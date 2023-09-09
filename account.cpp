#include "account.hpp"

namespace bank {

unsigned int Account::withdraw(unsigned int amount){
    balance_ -= amount;
    return amount;
}

std::ostream& operator<<(std::ostream& out,const Account& acc){
    out << "Owner: " << acc.owner() << '\n';
    out << "Number: " << acc.number() << '\n';
    out << "Balance: " << acc.balance() << '\n';
    return out;
}


} // bank