#include "celsius.h"
#include "fahrenheit.h"
#include "kelvin.h"



int main() {
    
    kelvin k,k2;
    celsius c;
    fahrenheit f;

    c.assign(-500);
    f.assign(-500);
    k.assign(-500);

    c.assign(25);
    c.display();

    f=c;
    f.display();

    k=f;
    k.display();
    k2=k;
    k2.display();
    
    return 0;
}
