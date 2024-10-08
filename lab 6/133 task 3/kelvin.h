#ifndef KELVIN_H
#define KELVIN_H

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
#include "fahrenheit.h"
#define CtoK(x) x=x + 273.15
#define FtoK(x) x=((x - 32) / 1.8) + 273.15

class fahrenheit;
class celsius;

class kelvin{

    private:

        float temp;
    
    public:
        kelvin():temp(0){};

        kelvin(float c):temp(c){};

        void assign(float c);

        float getVal();

        void display();

        kelvin operator =(celsius c);

        kelvin operator =(fahrenheit c);

    //END_OF_PUBLIC        
};
#endif //KELVIN_H