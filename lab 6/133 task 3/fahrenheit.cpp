#include "fahrenheit.h"

void fahrenheit::assign(float c){
    if(c<-459.67){
        cout<<" [error] value cannot be less than -459.67 fahrenheit. Assign failed"<<nl;
        return;
    }
    temp=c;
}

float fahrenheit::getVal(){
    return temp;
}

void fahrenheit::display(){
    cout<<"The temparature is: "<<temp<<" fahrenheit"<<nl;
}

fahrenheit fahrenheit::operator =(celsius c){
    float temp=c.getVal(); 
    CtoF(temp);
    this->temp=temp;
    return *this;
}

fahrenheit fahrenheit::operator =(kelvin c){
    float temp=c.getVal(); 
    FtoC(temp);
    this->temp=temp;
    return *this;
}