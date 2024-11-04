#include "account.h"




void account::accInit(string str, string name){
    accountNo=str;
    accountName=name;
}

void account::accInit(string str){
    accountNo=str;
}

void account::getter(string& acc,string& name, float& bal ){
    acc=accountNo;
    bal=balance;
    name=accountName;
}

void account::update(string& name, float& bal){
    accountName=name;
    balance=bal;
}

void account::deposit(float n){
    if(n<0){
        cout<<"cannot deposit negative value";
        return;
    }

    balance+=n;
}

void account::withdraw(float n){
    if(n<0){
        cout<<"cannot withdraw negative value";
        return;
    }
    if(n<balance){
        cout<<"cannot withdraw, insufficient balance";
        return;
    }

    balance-=n;
}