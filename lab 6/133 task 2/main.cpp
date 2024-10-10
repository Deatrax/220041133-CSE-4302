#include "Coordinate.h"


#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

// Function to generate random string
std::string generateRandomString(int length) {
    std::string randomString;
    const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int alphabetSize = sizeof(alphabet) - 1; // Exclude null character

    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    for (int i = 0; i < length; ++i) {
        randomString += alphabet[rand() % alphabetSize];
    }

    return randomString;
}

int randomInRange(int min, int max) {
    // Ensure min is less than or equal to max
    if (min > max) {
        std::swap(min, max); // Swap if min is greater than max
    }

    return rand() % (max - min + 1) + min;
}

// Function to generate a random double within a given range [min, max]
// double randomInRange(double min, double max) {
//     // Ensure min is less than or equal to max
//     if (min > max) {
//         std::swap(min, max); // Swap if min is greater than max
//     }

//     // Generate a random double between 0 and 1
//     double randomFraction = static_cast<double>(rand()) / RAND_MAX;

//     // Scale and shift the random value to the desired range
//     return min + randomFraction * (max - min);
// }



void randomAssignment(Coordinate c[], int size){
    for (size_t i = 0; i < size; i++)
    {
        c[i]=Coordinate(randomInRange(1,30),randomInRange(1,30));
    }
    
}
// void sortcod(Coordinate c[], int size){
//     sort(c,10);
// }

void highest(Coordinate c[],int n ){
    c[n-1].display();
}

void lowest(Coordinate c[],int n ){
    c[0].display();
}

int main(){
    Coordinate coord[10];
    randomAssignment(coord,10);
    //sortcod(coord, )
    //highest(coord,10);
    //lowest(coord,10);
}






