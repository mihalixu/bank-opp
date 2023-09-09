#include "account.hpp"

namespace bank {

unsigned int Account::withdraw(unsigned int amount){
    balance_ -= amount;
    return amount;
}

} // bank