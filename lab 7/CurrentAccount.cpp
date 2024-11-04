#include "CurrentAccount.h"

const string CurrentAccount::accountPrefix="200";
int CurrentAccount::nextAccount=001;


string CurrentAccount::nextAccountNo(){
    return to_string(nextAccount++);
}


CurrentAccount::CurrentAccount(){
    string acc=accountPrefix+nextAccountNo();
    accInit(acc);

    cout<<"give the current account name=";
    string name;
    cin>>name;

    cout<<"give the monthy deposit amount  =";
    int Mamout;
    cin>>Mamout;

    cout<<"Give interest rate =";
    float rate;
    cin>>rate;

    cout<<"give initial deposit amount =";
    float initialA;
    cin>>initialA;


    setVals(name, Mamout, rate, initialA );
}

// void CurrentAccount::getvals(string& accnum, float& bal){ 
//     getter(accnum, bal);
// }

void CurrentAccount::setVals(string &accname, int &Mamount, float &rate, float& inival)
{
    account::update(accname, inival);
    interestRate=rate;
    monthlyDepositAmount=Mamount;
}

void CurrentAccount::getvals(string &accnum, string& name, float &bal, float &rate, int &Mdeposit)
{
    getter(accnum, name, bal);
    rate=interestRate;
    Mdeposit=monthlyDepositAmount;

}

void CurrentAccount::deposit(float n) 
{
    if(n<monthlyDepositAmount){
        cout<<"amout less than monthly deposit amout";
        return;
    }
    account::deposit(n);
}
