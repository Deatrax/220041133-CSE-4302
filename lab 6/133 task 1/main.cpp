#include "count.h"
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

int main() {
    
    Count c1,c2,c3;

    c2.increment();
    c3.increment();

    c1=c2+c3;

    cout<<c1.getCount()<<nl;
    cout<<c2.getCount()<<nl;
    cout<<c3.getCount()<<nl;

    c2.setIncrementStep(5);
    c1=c2+c3;

    if(c1>c2) cout<<"c1 is greater\n";
    else cout<<"c2 is greater\n";

    if(c2==c3) cout<<"c2 and c3 are the same\n";
    else cout<<"they are not the same\n";
    
    return 0;
}
