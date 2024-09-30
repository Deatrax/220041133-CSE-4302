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
#include <algorithm>
#include <random>

#define nl "\n"
#define spc <<' '<<""
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
typedef long long ll;
using namespace std;

class savingsAccount{

    private:
        string name;
        string address;
        double interestRate;
        double balance;
        double minBal;


    public:
        void setInfo(string nam, string add, double rate, double bal);

        void getInfo();

        double calculateInterest(int periodInMonths) const;

        void disburseInterest(int periodInMonths);

        void deposit(double amount);

        void withdraw(double amount);

        string retName();
    //END OF PUBLIC
};
