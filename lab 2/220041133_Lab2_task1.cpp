#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>

#define nl "\n"
#define spc <<' '<<
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
typedef long long ll;
using namespace std;


int main(){

    int a,b,c,d;
    char buff;
    cout<<"Give 1st fraction:";
    cin>>a>>buff>>b;
    cout<<"Give 2nd fraction:";
    cin>>c>>buff>>d;

    cout<<"The fractional addition is="<<(float)(((float)(a*d)+(b*c))/(float)(b*d))<<nl;
}