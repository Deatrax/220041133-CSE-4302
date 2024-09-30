#include "133 task 1.h"

void savingsAccount::setInfo(string nam, string add, double rate, double bal){
    if(bal<0)
    {
        cout<<"initial balance cannot be 0"<<nl;
        return;
    }
    if (rate<0)
    {
        cout<<"interest rate cannot be 0"<<nl;
        return;
    }
    
    name=nam;
    address=add;
    interestRate=rate;
    balance=bal;
    minBal=bal;
}

void savingsAccount::getInfo(){
    cout<<"The name of the account= "<<name<<nl;
    cout<<"Address of accountee=    "<<address<<nl;
    cout<<"Interest rate of account="<<interestRate<<nl;
    cout<<"Balance of account=      "<<balance<<nl;
}

double savingsAccount::calculateInterest(int periodInMonths) const {
    double monthlyInterestRate = interestRate / 12.0;
    return minBal * (monthlyInterestRate / 100.0) * periodInMonths;
}

void savingsAccount::disburseInterest(int periodInMonths){
    double intrestAmount=calculateInterest(periodInMonths);
    balance+=intrestAmount;
    minBal=balance;
}

void savingsAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        minBal = min(minBal, balance);
    } else {
        cout << "Deposit amount must be positive.\n";
    }
}

void savingsAccount::withdraw(double amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
        minBal = min(minBal, balance); 
    } else {
        cout << "Invalid withdrawal amount.\n";
    }
}

string savingsAccount::retName()
{
    return name;
}
