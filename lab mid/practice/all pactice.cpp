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
#define KtoC(x) x = ((x) - 273.15)           
#define FtoC(x) x = (((x) - 32) * (5.0 / 9.0))
#define KtoF(x) x=((x - 273.15) * (9.0 / 5.0)) + 32
#define CtoF(x) x = ((x) * (9.0 / 5.0)) + 32 
#define CtoK(x) x=x + 273.15
#define FtoK(x) x=((x - 32) / 1.8) + 273.15
typedef long long ll;
using namespace std;

class myClass{
    private:
        string str;
    public:
        bool compare(myClass c){
            return str>c.str;
        }

        void setSting(string st){
            str=st;
        }

        void display(){
            cout<<str<<nl;
        }
};

void bsort(int *pt,int n){
    int swaps =0;
    for (int i = 0; i < n-1; i++)
    {   
        swaps=0;
        for (int j = 0; j < n-1-i; j++)
        {
            if (pt[j]>pt[j+1])
            {
                int temp=pt[j];
                pt[j]=pt[j+1];
                pt[j+1]=temp;
                swaps++;
            }
        }
        if (!swaps)
        {
            break;
        }
    }
}

void bsort(float *pt, int n) {
    int swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        swaps = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (pt[j] > pt[j + 1]) {
                float temp = pt[j];  // Change int to float
                pt[j] = pt[j + 1];
                pt[j + 1] = temp;
                swaps++;
            }
        }
        if (!swaps) {
            break;
        }
    }
}

void classStingSort(myClass clas[], int n){
    int swaps =0;
    for (int i = 0; i < n-1; i++)
    {   
        swaps=0;
        for (int j = 0; j < n-1-i; j++)
        {
            if(  clas[j].compare(clas[j+1])  ){
                myClass temp=clas[j];
                clas[j]=clas[j+1];
                clas[j+1]=temp;
                swaps++;
            }
        }
        if (!swaps)
        {
            break;
        }
    }
}

void ssort(string s[], int n){
    int swaps =0;
    for (int i = 0; i < n-1; i++)
    {   
        swaps=0;
        for (int j = 0; j < n-1-i; j++)
        {
            if (s[j]>s[j+1])
            {
                string temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
                swaps++;
            }
        }
        if (!swaps)
        {
            break;
        }
    }
}

enum taste {NA ,sour , sweet, salty, bitter, umami };
enum condition {best, better, good, bad};

class Fruit{
    private:
        string name;
        double price;
        taste tst;
        condition cond;

    public:

        Fruit(){}

        Fruit(string nam, double pric):name(nam),price(pric),tst(NA),cond(best){}

        void setVals(string nam, double pric, taste ts, condition cnd){

        }

};

int main(){


    myClass lol[10];
    lol[0].setSting("lol1");
    lol[1].setSting("lol5");
    lol[2].setSting("lol7");
    lol[3].setSting("lol1");
    lol[4].setSting("lol11");
    lol[5].setSting("lol3");
    lol[6].setSting("lol9");
    lol[7].setSting("lol6");
    lol[8].setSting("lol4");
    lol[9].setSting("lol2");

    for (size_t i = 0; i < 10; i++)
    {
        lol[i].display();
    }
    
    classStingSort(lol, 10);

    cout<<"\n\n";
    for (size_t i = 0; i < 10; i++)
    {
        lol[i].display();
    }


    string str[10];

    str[0]="strlol1";
    str[1]="strlol9";
    str[2]="strlol7";
    str[3]="strlol65";
    str[4]="strlol3";
    str[5]="strlol5";
    str[6]="strlol4";
    str[7]="strlol2";
    str[8]="strlol34";
    str[9]="strlol69";

    cout<<"\n\n";
    for (size_t i = 0; i < 10; i++)
    {
        cout<<str[i]<<nl;
    }
    ssort(str, 10);

    cout<<"\n\n";
    for (size_t i = 0; i < 10; i++)
    {
        cout<<str[i]<<nl;
    }
    
}









class Count{

    private:
        int cnt;
        int step;

    public:
        Count():cnt(0),step(1){}
        void setIncrementStep(int step_val);
        int getCount();
        void increment();
        void resetCount(int instep);
        Count operator +(Count c);
        bool operator < (Count c);
        bool operator > (Count c);
        bool operator >=(Count c);
        bool operator <=(Count c);
        bool operator==(Count c);
        bool operator!=(Count c);
};

void Count::setIncrementStep(int step_val=1){
    if(cnt==0 && step_val>0){
        step=step_val;
    }
    else if(step_val<0) cout<<"Cannot set negative stepping value\n";
    else cout<<"cannot set the increment step when Count is more than 1\n";
}

int Count::getCount(){
    return cnt;
}

void Count::increment(){
    cnt+=step;
}

void Count::resetCount(int instep = 1){
    cnt=0;
    step=instep;
}

Count Count::operator +(Count c){
    if(step==c.step){
        Count temp;
        temp.cnt=cnt+c.cnt;
        temp.step=step;
        return temp;
    }
    else{
        cout<<"the increment step is not same, nothing assigned";
        Count c;
        return c;
    }
}

bool Count::operator < (Count c){
    if(cnt<c.cnt) return true;
    else return false;
}

bool Count::operator > (Count c){
    if(cnt > c.cnt) return true;
    else return false;
}

bool Count::operator >=(Count c){
    if(cnt>=c.cnt) return true;
    else return false;
}

bool Count::operator<=(Count c){
    if(cnt<=c.cnt) return true;
    else return false;
}

bool Count::operator ==(Count c){
    if(cnt==c.cnt) return true;
    else return false;
}

bool Count::operator !=(Count c){
    if(cnt!=c.cnt) return true;
    else return false;
}