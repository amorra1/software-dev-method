#include "Checking_Account.h"

bool Checking_Account::deposit(double amount) {
    Account::deposit(amount);  
}

bool Checking_Account::withdraw(double amount){
    amount = amount + per_check_fee;
    Account::withdraw(amount);
}

