#include "Checking_Account.h"

bool Checking_Account::deposit(double amount){
    deposit(amount);  
}

bool Checking_Account::withdraw(double amount){
    withdraw(amount);
}

std::ostream& operator<<(std::ostream &os, const Checking_Account &account){
    os << "Checking Name: " << account.name << ", Balance: $" << account.balance
                                            << ", Per Check Fee: " << account.per_check_fee;
}