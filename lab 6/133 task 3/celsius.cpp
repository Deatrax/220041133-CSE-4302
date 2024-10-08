#include "celsius.h"

void celsius::assign(float c){
    if(c<-273.15){
        cout<<" [error] value cannot be less than -273.15 celsius. Assign failed"<<nl;
        return;
    }
    temp=c;
}

float celsius::getVal() const{
    return temp;
}

void celsius::display() const{
    cout<<"The temparature is: "<<temp<<" celsius"<<nl;
}

celsius celsius::operator =(fahrenheit c){
    float temp=c.getVal(); 
    FtoC(temp);
    this->temp=temp;
    return *this;
}

celsius celsius::operator =(kelvin c){
    float temp=c.getVal(); 
    KtoC(temp);
    this->temp=temp;
    return *this;
}

// Your code implementation goes here
