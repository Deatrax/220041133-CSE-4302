#ifndef count_H
#define count_H

#include <iostream>
using namespace std;

class Count{

    private:
        int cnt;
        int step;

    public:
        Count():cnt(0),step(1){}
        void setIncrementStep(int step_val);
        int getCount();
        void increment();
        void resetCount(int instep);
        Count operator +(Count c);
        bool operator < (Count c);
        bool operator > (Count c);
        bool operator >=(Count c);
        bool operator <=(Count c);
        bool operator==(Count c);
        bool operator!=(Count c);
};

#endif // count_H
