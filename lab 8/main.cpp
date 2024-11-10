#include "SavingsAccount.h"
#include "CurrentAccount.h"

// #include "LoanAccount.h"
// #include "MonthlyDepositScheme.h"
// #include "LoanAccount.h"

int main() {
    
    SavingsAccount acc1;
    CurrentAccount acc2;

    string name;
    string accnumber;
    float balance;
    float rate;
    int Mdiposit;
    acc1.getter(accnumber, name, balance);   
    cout<<"for the savings accout\naccount number="<<accnumber<<"\naccount holder="<<name<<"\naccount balance="<<balance<<nl;

    acc2.getvals(accnumber, name, balance, rate, Mdiposit);
    cout<<"for the savings accout\naccount number="<<accnumber<<"\naccount holder="<<name<<"\naccount balance="<<balance<<nl;
  

    return 0;
}
