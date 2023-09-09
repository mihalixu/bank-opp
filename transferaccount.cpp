#include "account.hpp"

namespace bank{

void TransferAccount::transfer(Account& target,unsigned int amount){
    target.deposit(this->withdraw(amount));
}

} // bank