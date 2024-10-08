#include "Coordinate.h"

Coordinate::~Coordinate(){
    cout<<"deatructor was called\n";
};

void Coordinate::display(){
    cout<<"Current coodrnates: "<<abs<<','<<ord<<endl;
}

float Coordinate::operator - (Coordinate c){
    return sqrt( pow( (c.abs-abs) , 2 ) + pow( (c.ord - ord ) , 2) );
}

float Coordinate::getDistance(){
    return sqrt( pow( (0 - abs) , 2 ) + pow( (0 - ord ) , 2) );
}

void Coordinate::move_x(float val){

    abs+=val;
}

void Coordinate::move_y(float val){

    ord+=val;
}

void Coordinate::move(float x_val, float y_val) {
    abs+=x_val;
    ord+=y_val;
}


bool Coordinate::operator < (Coordinate c){
    float a=getDistance();
    float b=c.getDistance();

    if(a < b) return true;
    else return false;
}

bool Coordinate::operator > (Coordinate c){
    float a=getDistance();
    float b=c.getDistance();

    if(a > b) return true;
    else return false;
}

bool Coordinate::operator >=(Coordinate c){
    float a=getDistance();
    float b=c.getDistance();

    if(a >= b) return true;
    else return false;
}

bool Coordinate::operator<=(Coordinate c){
    float a=getDistance();
    float b=c.getDistance();

    if(a <= b) return true;
    else return false;
}

bool Coordinate::operator ==(Coordinate c){
    float a=getDistance();
    float b=c.getDistance();

    if(a == b) return true;
    else return false;
}

bool Coordinate::operator !=(Coordinate c){
    float a=getDistance();
    float b=c.getDistance();

    if(a != b) return true;
    else return false;
}
// Your code implementation goes here
