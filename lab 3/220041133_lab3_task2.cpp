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


#define CtoK(x) x=x + 273.15
#define FtoK(x) x=((x - 32) / 1.8) + 273.15
#define KtoF(x) x=((x - 273.15) * (9.0 / 5.0)) + 32
#define CtoF(x) x = ((x) * (9.0 / 5.0)) + 32  
#define KtoC(x) x = ((x) - 273.15)           
#define FtoC(x) x = (((x) - 32) * (5.0 / 9.0))

class Temparature{

    private:
        float tempa;
        string arr[3]={" Celcius"," Fahrenheit"," Kelvin"};
        int unit_mode;

        int checkUnit(const string& unit){
            if (unit=="k" || unit=="K" || unit=="kelvin" || unit=="Kelvin")
            return 2;

            else if (unit=="f" || unit=="F" || unit=="fahrenheit" || unit=="Fahrenheit")
            return 1;

            else if (unit=="c" || unit=="C" || unit=="Celsius" || unit=="celsius")
            return 0;

            else return -1;
        }

        

    public:
        Temparature(){
            unit_mode=4;  //initial value to signal print function
            tempa=-25565; //initial value to signal print function
        }

        void assign(string& str){
            char ch[4]={str.back()};
            //DEBUG cout<<"the last char is"<<ch<<nl;
            string pass=ch;
            int u,store;
            store=tempa;
            if((u=checkUnit(pass)) && u==-1)
            {
                cout<<"Invalid unit used, please use K,C or F as unit\n";
                return;
            }
            unit_mode=u;
            str.pop_back();
            tempa=stof(str);
            switch (unit_mode)
            {
            case 0:
                if(tempa<-273.15){
                    cout<<" [error] value cannot be less than -273.15"<<arr[0]<<". Assign failed"<<nl;;
                    tempa=store;
                }
                break;

            case 1:
                if(tempa<-459.67){
                    cout<<" [error] value cannot be less than -459.67"<<arr[1]<<". Assign failed"<<nl;
                    tempa=store;
                }
                break;

            case 2:
                if(tempa<0){
                    cout<<" [error] value cannot be less than 0"<<arr[2]<<". Assign failed"<<nl;
                    tempa=store;
                }
                break;
            }
            return;
        }   

        void print(){

            if(unit_mode!=4 && tempa!=-25565 )
                cout<<"The temparature is "<<tempa<<arr[unit_mode]<<nl;
            else 
                cout<<"There was a problem during value assignment or value was not assigned\nplease assign value and try again\n";
        }

        int convert(const string& unit){

            int x=checkUnit(unit);
            switch (x)
            {
                case 2:
                    switch (unit_mode)
                    {
                    case 0:
                        CtoK(tempa);
                        break;
                    case 1:
                        FtoK(tempa);
                        break;
                    }
                    unit_mode=2;
                    return 1;
                
                case 1:
                    switch (unit_mode)
                    {
                    case 0:
                        CtoF(tempa);
                        break;
                    case 2:
                        KtoF(tempa);
                        break;
                    }
                    unit_mode=1;
                    return 1;

                case 0:
                    switch (unit_mode)
                    {
                    case 1:
                        FtoC(tempa);
                        break;
                    case 2:
                        KtoC(tempa);
                        break;
                    }
                    unit_mode=0;
                    return 1;
                default:
                    cout<<" [error] Invalid unit inputted, conversion failded, try again\n";
                    return 0;
            }
            cout<<"Conversion successful, print to see value\n";
        }

    //END OF PUBLIC   
};

int main(){

    int op;
    Temparature tmp;
    string inp;
    cout<<"Select operation:\n\t[1]assign value\n\t[2]covert value\n\t[3]print value\n\t[4]exit \n\n(op code) >>";
    while ((cin>>op) && op!=4)
    {
        switch (op)
        {
        case 1:
            cout<<"Give the value with unit [use only  K / C / F]\n>>";
            fflush(stdin);
            getline(cin,inp);
            tmp.assign(inp);
            break;
        
        case 3:
            tmp.print();
            break;

        case 2:
            cout<<"Give the new unit\n>>";
            fflush(stdin);
            getline(cin,inp);
            tmp.convert(inp);
            break;
        default:
            cout<<"Invalid op code\n";
            break;
        }
        cout<<"(op code) >>";
        fflush(stdin);
    }
    
}