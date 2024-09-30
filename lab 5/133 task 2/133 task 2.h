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

enum months{January, February, March, April, May, June, July, August, Septempber, October, November, December};

typedef struct DOB{
        int date;
        months month;
        int year;
} DOB;

class Employee{
    private:

        string name;
        DOB dob;
        int salary;

    public:
        void setName(string nam="John Doe");

        void setDOB(DOB given);

        void setSalary(int sal);
    
        string getName() const;

        DOB getDOB() const;

        int getSalary() const;


};
