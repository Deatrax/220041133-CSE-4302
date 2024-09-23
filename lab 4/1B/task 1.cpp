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


class Calculator{

    private:
        int status;

        void getCalc(){

            cout<<status<<nl;
        }

        void setCalc(int x){
            status=x;
        }
        
    public:
        Calculator():status(0){}

        Calculator(int x):status(x){}

        ~Calculator(){
            display();
            cout<<"Destructor of the Calculator object is called \n";
        }
        void add(int x){
            status+=x;
        }

        void subtract(int x){
            status-=x;
        }

        void multiply(int x){
            status*=x;
        }

        void divideBy(int x){
            if(x==0){
                cout<<"cannot divide by 0";
                return;
            }
            status/=x;
        }

        void clear(){
            status=0;
        }

        void display(){
            cout<<"Calculator Display: "<<status<<nl;
        }
};


int main(){

    cout<<"Initialize constructor? [y/n] >>";
    char ch;
    cin>>ch;
    Calculator* calc;
    if (ch=='y')
    {   
        cout<<"Give initial value >>";
        int x;
        cin>>x;
        calc=new Calculator(x);
    }
    else{
        calc=new Calculator;
    }
    cout<<"Select Operation:\n\t[1]display\n\t[2]add\n\t[3]substract\n\t[4]multiply\n\t[5]divide by\n\t[6]reset\n\t[7]exit\n\n [op code] >>";
    int n;
    while((cin>>n) && n!=7){
        switch (n)
        {
        case 1:
            calc->display();
            break;
        
        case 2:
            cout<<"Give the value >>";
            cin>>n;
            calc->add(n);
            break;

        case 3:
            cout<<"Give the value >>";
            cin>>n;
            calc->subtract(n);
            break;

        case 4:
            cout<<"Give the value >>";
            cin>>n;
            calc->multiply(n);
            break;

        case 5:
            cout<<"Give the value >>";
            cin>>n;
            calc->divideBy(n);
            break;

        case 6:
            calc->clear();
            cout<<"value has been reset\n";
            break;

        default:
            cout<<" [error] invalid opcode\n";
            break;
        }
    }
    
}