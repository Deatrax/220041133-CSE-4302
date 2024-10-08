#include "celsius.h"
#include "fahrenheit.h"
#include "kelvin.h"



int main() {
    
    kelvin k;
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
    
    
    return 0;
}
