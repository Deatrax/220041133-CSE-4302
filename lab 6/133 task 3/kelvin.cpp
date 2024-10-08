#include "kelvin.h"

void kelvin::assign(float c){
    if(c<0){
        cout<<" [error] value cannot be less than 0 kelvin. Assign failed"<<nl;
        return;
    }
    temp=c;
}

float kelvin::getVal(){
    return temp;
}

void kelvin::display(){
    cout<<"The temparature is: "<<temp<<" kelvin"<<nl;
}

kelvin kelvin::operator =(celsius c){
    float temp=c.getVal(); 
    CtoK(temp);
    this->temp=temp;
    return *this;
}

kelvin kelvin::operator =(fahrenheit c){
    float temp=c.getVal(); 
    FtoK(temp);
    // kelvin kk;
    // kk.temp=temp
    // return kk;

    this->temp=temp;
    return *this;
    
    //return kelvin(temp);
}