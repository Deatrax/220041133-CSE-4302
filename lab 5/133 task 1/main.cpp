#include "133 task 1.h"


void EditInformationByKeyboard(savingsAccount& acc){
    fflush(stdin);
    cout<<"Give the account holder name: ";
    string name;
    getline(cin,name);
    fflush(stdin);
    cout<<"Give the address :";
    string address;
    getline(cin,address);
    fflush(stdin);
    cout<<"Give the initial balance :";
    double balance;
    fflush(stdin);
    cin>>balance;
    cout<<"give the annual interest rate :";
    double rate;
    fflush(stdin);
    cin>>rate;

    acc.setInfo(name, address, rate, balance);

}

void sortAccs(savingsAccount acc[], int n){

    int swaps =0;
    for (int i = 0; i < n-1; i++)
    {   
        swaps=0;
        for (int j = 0; j < n-1-i; j++)
        {
            if (acc[j].retName()>acc[j+1].retName())
            {
                savingsAccount temp =acc[j];
                acc[j]=acc[j+1];
                acc[j+1]=temp;
                swaps++;
            }
        }
        if (!swaps)
        {
            break;
        }
    }
}

void ShowInterestAll(savingsAccount arr[],int n){
    int months;
    cout<<"give the month period=";
    cin>>months;

    for (int i = 0; i < n; i++)
    {
        cout<<"interest for account "<<i<<" "<<arr[i].calculateInterest(months);
    }
    cout<<"disburse interest? [y/n] >>";
    char ch;
    cin>>ch;
    if (ch=='y')
    {
        for (int i = 0; i < n; i++)
        {
            arr[i].disburseInterest(months);
        }
    }
    else cout<<"Cancelled operation\n";
    
}

void showAllAlphabetically(savingsAccount acc[],int n){
    sortAccs(acc,n);
    for (size_t i = 0; i < n; i++)
    {
        acc[i].getInfo();
    }
    
}


int main(){
    savingsAccount acc[100];
    for (int i = 0; i < 5; i++)
    {   
        cout<<"For the no. :"<<i+1<<" account\n";
        EditInformationByKeyboard(acc[i]);
    }
    
    // cout<<"Select operation:\n\t[1] deposit\n\t[2]";
    // int i;
    // while ((cin>>i) && i!=-1)
    // {
    // }

    ShowInterestAll(acc, 5);
    showAllAlphabetically(acc,5);
    
}

// g++ main.cpp "133 task 1.cpp" -o "133 task 1" && ./"133 task 1"