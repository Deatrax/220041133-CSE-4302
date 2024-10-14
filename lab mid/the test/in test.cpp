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

class myclass{
    private:
        static int cnt;

    public:
        void incemrent(){
            cnt++;
        }

        void print(){
            cout<<cnt<<endl;
        }
    
};

int myclass::cnt=0; //ekhane mara keyechi, type deinai


int main(){
    myclass obj;
    obj.incemrent();
    obj.print();

    myclass obj2;
    obj2.incemrent();
    obj2.print();
    
}