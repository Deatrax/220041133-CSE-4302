#ifndef FAHRENHEIT_H
#define FAHRENHEIT_H

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

#include "celsius.h"
#include "kelvin.h"
#define KtoF(x) x=((x - 273.15) * (9.0 / 5.0)) + 32
#define CtoF(x) x = ((x) * (9.0 / 5.0)) + 32 

class celsius;
class kelvin;

class fahrenheit{
    private:
        float temp;
    public:
        fahrenheit():temp(0){};

        fahrenheit(float c):temp(c){};

        void assign(float c);

        float getVal();

        void display();

        fahrenheit operator =(celsius c);

        fahrenheit operator =(kelvin c);
};
#endif //FAHRENHEIT_H