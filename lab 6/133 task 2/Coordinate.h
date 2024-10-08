#ifndef Coordinate_H
#define Coordinate_H
#include <iostream>
using namespace std;
class Coordinate{
    private:
        float abs;
        float ord;

    public:
        Coordinate():abs(0),ord(0){};

        Coordinate(float abscissa, float ordinate):abs(abscissa),ord(ordinate){};

        ~Coordinate();

        void display();

        float operator - (Coordinate c);

        float getDistance();

        void move_x(float val);

        void move_y(float val);

        void move(float x_val, float y_val);

        bool operator < (Coordinate c);
        bool operator > (Coordinate c);
        bool operator >=(Coordinate c);
        bool operator <=(Coordinate c);
        bool operator==(Coordinate c);
        bool operator!=(Coordinate c);

};

#endif // Coordinate_H
