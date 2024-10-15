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

class rational_number{

    private:
        float p;
        float q;
        float rnum;
    
    public:

        /// @brief two argumented constructor thaking the numerator and denominator of the rational number
        /// @param a 
        /// @param b 
        rational_number(int a, int b):p(a),q(b){
            if(q==0){
                cout<<"Q cannot be 0"<<nl;
                p=1;
                q=2;
                rnum=static_cast<double>(p/q);
                return;
            }
            rnum=static_cast<double>(p/q);
        }

        /// @brief  0 argumented constructor, initializes p=1 and q=2
        rational_number():p(1),q(2){
            rnum=p/q;
        }

        void setNum(int a, int b){
            if(b==0){
                cout<<"Q cannot be 0"<<nl;
                p=1;
                q=2;
                return;
            }

            p=a;
            q=b;
            rnum=(p/q);
        }

        void display(){
            cout<<"the rational number is in the class is (fractional) : "<<p<<'/'<<q<<nl;
        }

        void diaplayDecimal(){
            cout<<"the rational number is in the class is (decimal) : "<<rnum<<nl;
        }

        float operator +(float n){
            //rnum=(p/q);
            return rnum+n;

        }

        float operator -(float n){
            //rnum=(p/q);
            return rnum-n;

        }

        float operator *(float n){
            //rnum=(p/q);
            return rnum*n;

        }

        float operator /(float n){
            //rnum=(p/q);
            return rnum/n;
        }

    
};


int main(){
    cout<<"\n\n";
    int a,b;
    cout<<"Give the value of P  >>";
    cin>>a;
    cout<<"Give the value of Q  >>";
    cin>>b;

    rational_number rnum(a,b);

    cout<<"using fraction 3/4 with the given fraction,do you wnat to change it? [y/n] =";
    char ch;
    cin>>ch;
    float m=3;
    float n=4;
    if(ch=='y'){
        cout<<"Give the value of P  >>";
        cin>>m;
        cout<<"Give the value of Q  >>";
        cin>>n;
    }
    else{
        NULL;
    }
    
    float r=(m/n);
    //cout.setf(ios::fixed);
    rnum.display();
    rnum.diaplayDecimal();
    cout<<"\n\n\n";
    cout<<"sum         :"<<(rnum+r)<<nl;
    cout<<"subtraction:"<<(rnum-r)<<nl;
    cout<<"product     :"<<(rnum*r)<<nl;
    cout<<"quotient    :"<<(rnum/r)<<nl<<nl;
    return 0;
}