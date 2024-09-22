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


class Time{

    private:
        int H;
        int M;
        int S;
    
    public:
        Time(){
            H=0;
            M=0;
            S=0;
        }

        int hours(){
            return H;
        }

        int minutes(){
            return M;
        }

        int seconds(){
            return S;
        }

        void reset(int h, int m, int s){
            H=h;
            M=m;
            S=s;
        }

        void advance(int h, int m, int s){
            S+=s;
            if(S>=60){
                M+=(S/60);
                S=S%60;
            }
            M+=m;
            if(M>=60){
                H+=(M/60);
                M=M%60;
            }
            H+=h;
            if(H>=24) H=0;
            /*
            -> since no instruction was given to 
               add any kind of day member variable in any of the 
               function parameters, day variable was not implemented 

            */
        }
        
        void print(){
            cout<<"Stored time: "<<H<<":"<<M<<":"<<S<<nl;
        }
};

int main(){

    cout<<"Select operation:\n\t[1]print hour\n\t[2]print minute\n\t[3]print second\n\t[4]reset value\n\t[5]advance value\n\t[6]print full time\n\t[7]exit\n\n>>";
    int op;
    Time t;
    while ((cin>>op) && op!=7)
    {   
        int h,m,s;
        switch (op)
        {
        case 1:
            cout<<"Hour: "<<t.hours()<<nl; 
            break;
        
        case 2:
            cout<<"Minute: "<<t.minutes()<<nl; 
            break; 

        case 3:
            cout<<"Second: "<<t.seconds()<<nl; 
            break;

        case 4:
            cout<<"Give hour >>";
            cin>>h;
            cout<<"Give minute >>";
            cin>>m;
            cout<<"Give second >>";
            cin>>s;
            t.reset(h,m,s);
            cout<<"time reset\n";
            break;

        case 5:
            cout<<"Give hour >>";
            cin>>h;
            cout<<"Give minute >>";
            cin>>m;
            cout<<"Give second >>";
            cin>>s;
            t.advance(h,m,s);
            cout<<"time advanced\n";
            break;

        case 6:
            t.print();
            break;
        default:
            cout<<"Invalid op code\n";
            break;
        }
        cout<<">>";
        fflush(stdin);
    }
    
}