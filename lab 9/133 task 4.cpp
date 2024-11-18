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
        float discount;
    public:
        Artwork(string t, string a, float p)
            :title(t)
            ,artist(a)
            ,price(p)
        {}

        virtual ~Artwork(){
            cout<<"Base artwork destructor\n";
        }

        virtual void displayDetails(){
            cout<<"Name of Artwork="<<title<<"\nName of the artist="<<artist<<"\nPrice\t="<<price;
            if(discount){
                float np=( price - ( price * (discount / 100 ) ) );
                cout<<"\nDiscount ="<<discount<<"%\nPrice after discount ="<<np;
            }
            else{
                cout<<"\nDiscount = Discount is not applicable";
            }
        }
        virtual void applyDiscount(float i){
            discount=i;
        }
    
};

class Painting: public Artwork{

    private:
        string medium;

    public:
        Painting(string t, string a, float p, string trd): Artwork(t,a,p), medium(trd){}

        ~Painting(){
            cout<<"Painting artwork destructor\n";
        }

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

        ~Sculpture(){
            cout<<"Sculpture artwork destructor\n";
        }

        void displayDetails() override{
            cout<<"The kind of artwork= Sculpture\n";
            Artwork::displayDetails();
            cout<<"\nMeterial ="<<material<<nl<<endl;
        }

        void applyDiscount(float i) override{
            discount=0;
            cout<<"Cannot apply discount to Sculpture\n\n";
        }
        
};

class DigitalArt: public Artwork{

    private:
        string resolution;

    public:
        DigitalArt(string t, string a, float p, string trd): Artwork(t,a,p), resolution(trd){}

        ~DigitalArt(){
            cout<<"DigitalArt artwork destructor\n";
        }

        void displayDetails() override{
            cout<<"The kind of artwork= DigitalArt\n";
            Artwork::displayDetails();
            cout<<"\resolution ="<<resolution<<nl<<endl;
        }
};

void DisplayGalleryDetials(Artwork** arts,int n){
    cout<<"\n\t\t=========Details of the art gallery=========\n\n";
    for (int i = 0; i < n; i++)
    {
        arts[i]->displayDetails();
    }
    
}

int main(){
    system("clear");

    Artwork* arts[3];

    arts[0]=new Painting("Monalisa","Leonardo Da Vinci",89000000,"oil");
    arts[1]=new Sculpture("Equestrian Statue of Marcus Aurelius", "Marcus Aurelius",2500000,"stone");
    arts[2]=new DigitalArt("In the part","Boris Serdyuk",300,"50x70x2 cm");

    for (int i = 0; i < 3; i++)
    {
        arts[i]->applyDiscount(5);
    }
    


    DisplayGalleryDetials(arts,3);

    for (int i = 0; i < 3; i++)
    {
        delete arts[i];
    }
    
    
}