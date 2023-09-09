#include "account.hpp"

namespace bank {

unsigned int ChildAccount::withdraw(unsigned int amount){
    if(amount > balance()){
        amount = balance();
    }
    return Account::withdraw(amount);
}

} // bank