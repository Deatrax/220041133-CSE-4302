#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <string>
#include <stack>
#include <queue>

#define nl "\n"
#define spc <<' '<<""
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
typedef long long ll;
using namespace std;

class Artwork{
    protected:
        string title;
        string artist;
        float price;
    public:
        Artwork(string t, string a, float p)
            :title(t)
            ,artist(a)
            ,price(p)
        {}

        virtual void displayDetails(){
            cout<<"Name of Artwork="<<title<<"\nName of the artist="<<artist<<"\nPrice\t="<<price;
        }  
};

class Painting: public Artwork{

    private:
        string medium;

    public:
        Painting(string t, string a, float p, string trd): Artwork(t,a,p), medium(trd){}

        void displayDetails() override{
            cout<<"The kind of artwork= Painting\n";
            Artwork::displayDetails();
            cout<<"\nMedium ="<<medium<<nl<<endl;
        }
};

class Sculpture: public Artwork{

    private:
        string material;

    public:
        Sculpture(string t, string a, float p, string trd): Artwork(t,a,p), material(trd){}

        void displayDetails() override{
            cout<<"The kind of artwork= Sculpture\n";
            Artwork::displayDetails();
            cout<<"\nMeterial ="<<material<<nl<<endl;
        }
};

class DigitalArt: public Artwork{

    private:
        string resolution;

    public:
        DigitalArt(string t, string a, float p, string trd): Artwork(t,a,p), resolution(trd){}

        void displayDetails() override{
            cout<<"The kind of artwork= DigitalArt\n";
            Artwork::displayDetails();
            cout<<"\nresolution ="<<resolution<<nl<<endl;
        }
};


int main(){
    system("clear");
    Artwork* arts[3];

    arts[0]=new Painting("Monalisa","Leonardo Da Vinci",89000000,"oil");
    arts[1]=new Sculpture("Equestrian Statue of Marcus Aurelius", "Marcus Aurelius",2500000,"stone");
    arts[2]=new DigitalArt("In the part","Boris Serdyuk",300,"50x70x2 cm");

    for (int i = 0; i < 3; i++)
    {
        arts[i]->displayDetails();
    }
    
}