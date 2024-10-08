#include "Count.h"
#include "count.h"

void Count::setIncrementStep(int step_val=1){
    if(cnt==0 && step_val>0){
        step=step_val;
    }
    else if(step_val<0) cout<<"Cannot set negative stepping value\n";
    else cout<<"cannot set the increment step when Count is more than 1\n";
}

int Count::getCount(){
    return cnt;
}

void Count::increment(){
    cnt+=step;
}

void Count::resetCount(int instep = 1){
    cnt=0;
    step=instep;
}

Count Count::operator +(Count c){
    if(step==c.step){
        Count temp;
        temp.cnt=cnt+c.cnt;
        temp.step=step;
        return temp;
    }
    else{
        cout<<"the increment step is not same, nothing assigned";
        Count c;
        return c;
    }
}

bool Count::operator < (Count c){
    if(cnt<c.cnt) return true;
    else return false;
}

bool Count::operator > (Count c){
    if(cnt > c.cnt) return true;
    else return false;
}

bool Count::operator >=(Count c){
    if(cnt>=c.cnt) return true;
    else return false;
}

bool Count::operator<=(Count c){
    if(cnt<=c.cnt) return true;
    else return false;
}

bool Count::operator ==(Count c){
    if(cnt==c.cnt) return true;
    else return false;
}

bool Count::operator !=(Count c){
    if(cnt!=c.cnt) return true;
    else return false;
}
// Your code implementation goes here
