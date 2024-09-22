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


class Counter{

    private:
        int count;
        int step;
    public:

        Counter(){
            count=0;
            step=1;
        }

        /// @brief constructor for initial value and increment step
        /// @param x initial value
        /// @param y increment step
        Counter(int x,int y):count(x),step(y)
        {}

        /// @brief constructor for initialized count
        /// @param x initial value for count
        Counter(int x):count(x){
            step=1;
        }

        void setIncrementStep(int x){
            step=x;
        }

        int getCount(){
            return count;
        }

        void increment(){
            count+=step;
        }

        void resetCount(){
            count = 0;
        }


    //end of public
};


int main(){

    Counter cnt;
    int n;
    cout<<"Select OP code:\n\t[1]increment\n\t[2]get count\n\t[3]set increment step\n\t[4]reset count\n\t[5]exit\n>>";
    while ((cin>>n) && n!=5)
    {
        switch (n)
        {
        case 1:
            cnt.increment();
            break;
        case 2:
            cout<<cnt.getCount()<<nl;
            break;
        case 3:
            cout<<"Give value >>";
            cin>>n;
            cout<<"increment step changed to "<<n<<nl;
            cnt.setIncrementStep(n);
            break;
        case 4:
            cnt.resetCount();
            cout<<"Count reset"<<nl;
            break;
        default:
            cout<<"invalid op code"<<nl;
            break;
        }
        cout<<">>";
    }
    cout<<"Exiting program...exited\n\n";
    return 0;
    
}