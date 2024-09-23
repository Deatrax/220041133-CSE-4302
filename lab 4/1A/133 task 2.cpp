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


class flight{

    private:
        int flightNumber;
        string destination;
        float distance;
        float MaxFuelCapacity;

        double CalFuel(){
            if (distance<=1000)
            {
                return 500;
            }
            else if (distance>1000 && distance<=2000)
            {
                return 1100;
            }
            else return 2200;
        }

    public:

        void FeedInfo(){

            string dest;
            int flnam;
            float fuel;
            float dist;
            
            cout<<"Give the flight number >>";
            cin>>flnam;
            cout<<"Give the destination >>";
            fflush(stdin);
            getline(cin, dest);
            cout<<"Give the distance >>";
            cin>>dist;
            cout<<"Give the fuel capacity >>";
            cin>>fuel;


            flightNumber=flnam;
            destination=dest;
            distance=dist;
            MaxFuelCapacity=fuel;
            cout<<"Values initialized\n";
        }

        void ShowInfo(){

            cout<<"The flight number is\t\t="<<flightNumber<<nl;
            cout<<"The destiation is \t\t="<<destination<<nl;
            cout<<"The distance of the flight\t="<<distance<<nl;
            cout<<"The max fuel capasity\t\t="<<MaxFuelCapacity<<nl;

            if(CalFuel()>MaxFuelCapacity)
            {   
                cout<<"Not sufficient Fuel Capacity for this flight.\n";
            }
            else cout<<"Fuel capacity is fit for this flight distance.\n";
            
        }

};
int main(){

    flight fl;
    int n;
    cout<<"Select operation:\n\t[1]Insert data\n\t[2]Show Data\n\t[3]exit\n\n[op code] >>";
    while ((cin>>n) && n!=3)
    {   
        
        switch (n)
        {
        case 1:
            fl.FeedInfo();
            break;
        
        case 2: 
            fl.ShowInfo();
            break;

        default:
            cout<<" [error] Invalid op code entered\n";
            break;
        }
        fflush(stdin);
        cout<<"[op code] >>";
    }
    cout<<"Exiting...exited\n\n";
    return 0;
    
}