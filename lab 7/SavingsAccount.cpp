#include "SavingsAccount.h"

const string SavingsAccount::accountPrefix="100";
int SavingsAccount::nextAccount=001;
const int SavingsAccount::serviceCharge=100;


string SavingsAccount::nextAccountNo(){
    return to_string(nextAccount++);
}


SavingsAccount::SavingsAccount(){
    string acc=accountPrefix+nextAccountNo();
    accInit(acc);

    cout<<"give the savings account name=";
    string name;
    cin>>name;

    cout<<"give initial deposit amount =";
    float initialA;
    cin>>initialA;


    setVals(name, initialA);
}

// void SavingsAccount::getvals(string& accnum, float& bal, string& accName){ 
//     getter(accnum, accName, bal);
// }

void SavingsAccount::setVals(string& accname, float& bal){
    account::update(accname, bal);
}