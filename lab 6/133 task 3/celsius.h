#ifndef CELCIUS_H
#define CELCIUS_H

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

#include "fahrenheit.h"
#include "kelvin.h"
#define KtoC(x) x = ((x) - 273.15)           
#define FtoC(x) x = (((x) - 32) * (5.0 / 9.0))

class fahrenheit;
class kelvin;

class celsius{
    private:
        float temp;
    public:
        celsius():temp(0){};

        celsius(float c):temp(c){};

        void assign(float c);

        float getVal() const;

        void display() const;

        celsius operator =(fahrenheit c);

        celsius operator =(kelvin c);

        
};

#endif // CELCIUS_H
