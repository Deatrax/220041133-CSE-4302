#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <string>
#include <stack>
#include <queue>

#define nl "\n"
#define spc <<' '<<""
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
typedef long long ll;
using namespace std;


class BankAccount{

    private:
        int acNum;
        string holder;
        bool type;
        double bal;
        const double minBal=200;
        static double taxCol;

    public:
        
        //void BankAccount::Larger(const BankAccount A, const BankAccount B);

        BankAccount():bal(0),minBal(0),acNum(0){};

        BankAccount(int ac, string& holdr, string typ, double balnc)
            :acNum(ac),
            holder(holdr),
            bal(balnc)
        {   
            if(balnc<minBal){
                cout<<" [error] initial deposit value is less than minimum\nPlease deposit minimum of 200/-\nAccoutn creation failed, please retry\n";
                return;
            }

            if (typ=="current")
            {
                type=1;
            }
            else if(typ=="savings"){
                type=0;
            }
            else cout<<" [error] Invalid account type, please create account again\n";
            
        }

        ~BankAccount(){
            cout<<"Account of Mr."<<holder<<" with account number "<<acNum<<"is destryed with a balance of BDT"<<bal<<nl;
        }

        void createAcc(int ac, string& holdr, string typ, double balnc){
            
            if (typ=="current")
            {
                type=1;
            }
            else if(typ=="savings"){
                type=0;
            }
            else{
                
                cout<<" [error] Invalid account type, please create account again\n";
                return;
            }
            if(balnc<minBal){
                cout<<" [error] Initial deposit value is less than minimum\nPlease deposit minimum of 200/-\nAccoutn creation failed, please retry\n";
                return;
            }
            bal=balnc;
            acNum=ac;
            holder=holdr;
            
        }

        void showInfo(){
            cout<<"Account No\t\t="<<acNum<<nl;
            cout<<"Account Holder Name\t="<<holder<<nl;
            cout<<"Account Type\t\t="<< type? cout<<"Current\n" : cout<<"Savings\n";
            cout<<"Account balance\t\t="<<bal<<nl;
        }

        void showBalance(){
            cout<<"The current balance is ="<<bal<<nl;
        }

        void deposit(double x){
            if (x<0)
            {
                cout<<" [error] Invalid amount entered, negative amount cannot be deposited\n";
                return;
            }
            
            bal+=x;
            cout<<"amout of money depositted=\t"<<x<<"\nThe current balance is\t="<<bal<<nl;
        }

        void withdraw(double x){
            if((bal-x)<minBal){
                cout<<" [error] This amount of money cannot be withdrawn, infuccicient balance\n";
                return;
            }
            bal-=x;
             cout<<"amout of money withdrawn=\t"<<x<<"\nThe current balance is\t="<<bal<<nl;
        }

        

        void giveInterest(double x = .03){

            double interestAmount=bal*x;
            taxCol+=interestAmount*0.1;
            interestAmount=(interestAmount-(interestAmount*0.1));
            bal+=interestAmount;
            cout<<"Interest paid\t\t="<<interestAmount<<nl<<"Current Balance\t\t="<<bal;
        }

        double baln() {
            return bal;
        }
};

void display_stat(){

}

// BankAccount Larger(const BankAccount A, const BankAccount B){
//     if (A.baln>)
//     {
//         /* code */
//     }
    
// }

int main(){
    cout<<"Initialize the constructor? [y/n] >>";
    char ch;
    cin>>ch;
    map<int, BankAccount> accounts;
    BankAccount* account=NULL;
    if (ch=='y')
    {
        int acNum;
        string holder;
        string type;
        double bal;
        cout<<"Give account number >>";
        cin>>acNum;
        cout<<"Give the account holder name >>";
        fflush(stdin);
        getline(cin,holder);
        cout<<"Give the account type [current/savings] >>";
        cin>>type;
        cout<<"Give the initial deposit amount >>";
        cin>>bal;
        BankAccount acc(acNum,holder,type,bal);
        accounts.emplace(acNum,acc);

    }
    else account=new BankAccount;

    cout<<"Select opertation\n\t[1]create account\n\t[2]deposit\n\t[3]withdraw\n\t[4]give interest\n\t[5]diaplay stat\n\t[6]compare \n\n [op code] >>";
    int n;
    while ((cin>>n) && n!=5)
    {   
        int acNum;
        string holder;
        string type;
        double bal;
        BankAccount acc;
        int sel;
        int sel2;
        auto it=find(accounts.begin(),accounts.end(),1);
        switch (n)
        {
        case 1:
            cout<<"Give account number >>";
            cin>>acNum;
            it=find(accounts.begin(),accounts.end(),acNum);
            if(it!=accounts.end()){
                cout<<"account exists";
                return;
            }
            cout<<"Give the account holder name >>";
            fflush(stdin);
            getline(cin,holder);
            cout<<"Give the account type [current/savings] >>";
            cin>>type;
            cout<<"Give the initial deposit amount >>";
            cin>>bal;
            acc.createAcc(acNum,holder,type,bal);
            accounts.emplace(acNum,acc);
            break;
        
        case 2:
            cout<<"Give account number >>";
            cin>>sel;
            cout<<"Give the amount >>";
            cin>>n;
            accounts[sel].deposit(n);
            break;

        case 3:
            cout<<"Give account number >>";
            cin>>sel;
            cout<<"Give the amount >>";
            cin>>n;
            accounts[sel].withdraw(n);
            break;

        case 4:
            cout<<"Give account number >>";
            cin>>sel;
            cout<<"Use default interest? [y/n] >>";
            cin>>ch;
            if(ch=='y') accounts[sel].giveInterest();
            else{
                cout<<"Give interest amount >>";
                double a;
                cin>>a;
                accounts[sel].giveInterest(a);
            }
            break;

        case 5:
            display_stat();

        case 6:
            cout<<"Give 1st account number >>";
            cin>>sel;
            cout<<"Give 2nd account number >>";
            cin>>sel;

        default:
            break;
        }
    }
    
    
}