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
#include <cstdlib>
#include <ctime>

#define nl "\n"
#define spc <<' '<<""
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
typedef long long ll;
using namespace std;

class CharacterActions{

    public:
        virtual int attack()=0;
        virtual bool defend()=0;
        virtual int useSpecialAbility()=0;
        virtual void displayStats()=0;
        virtual void target(int)=0;
        virtual ~CharacterActions(){};
};



class BaseCharacter: public CharacterActions{
    
    protected:
        string name;
        float health;
        float mana;
        int aPower;
    
    public:
        BaseCharacter(string nam, int helh, int atk)
            :name(nam)
            ,health(helh)
            ,mana(0)
            ,aPower(atk)
            {}

        void target(int receive) override{
            cout<<"Boss attacks "<<name<<" with power "<<receive<<endl;
        }
        
        void displayStats() override {
            std::cout << name << " - Health: " << health << ", Mana: " << mana << std::endl;
        }
};



class warrior : public BaseCharacter{

    protected:
        int sPower;

    public:
        warrior(string nam="Warrior")
            :BaseCharacter(nam, 100, 25)
            ,sPower(35)
            {}
        
        int attack() override {
            cout<<name<<" attacks with power "<<aPower<<endl;
            mana+=50;
            if(mana>=100){
                int big=useSpecialAbility();
                return big+aPower;
            }
            return aPower;
        }

        void target(int receive) override{
            BaseCharacter::target(receive);
            if(defend()){
                cout<<"Warrior defended successfully, No damage taken"<<endl;
            }
            else{
                health-=receive;
                cout<<"Warrior takes "<<receive<<" damage!"<<endl;
            }
            displayStats();
        }

        bool defend() override {
            int chance = rand() %100;
            if (chance < 50){
                return true;
            }else{
                return false;
            }
        }

        int useSpecialAbility() override{
            cout<<"Warrior uses Berserk Rage 💥💥💥 with power 35!"<<endl;
            return sPower;
        }

};



class mage : public BaseCharacter{
    
    protected:
        int sPower;

    public:
        mage(string nam="Mage")
            :BaseCharacter(nam, 120, 20)
            ,sPower(30)
            {}
        
        int attack() override {
            cout<<name<<" attacks with power "<<aPower<<endl;
            mana+=50;
            if(mana>=100){
                int big=useSpecialAbility();
                return big+aPower;
            }
            return aPower;
        }

        void target(int receive) override{
            BaseCharacter::target(receive);
            if(defend()){
                cout<<"Mage defended successfully, No damage taken"<<endl;
            }
            else{
                health-=receive;
                cout<<"Mage takes "<<receive<<" damage!"<<endl;
            }
            displayStats();
        }

        bool defend() override {
            int chance = rand() %100;
            if (chance < 50){
                return true;
            }else{
                return false;
            }
        }

        int useSpecialAbility() override{
            cout<<"Mage uses Arcane Blast 🔥🔥🔥 with power 30!"<<endl;
            return sPower;
        }
};



class archer : public BaseCharacter{
    protected:
        int sPower;

    public:
        archer(string nam="Archer")
            :BaseCharacter(nam, 90, 20)
            ,sPower(35)
            {}
        
        // int attack() override {
        //     if(mana>=100){
        //         return useSpecialAbility();
        //     }
        //     else{
        //         cout<<name<<" attacks with power "<<aPower<<endl;
        //     }
        //     mana+=50;
        //     if(mana>=100){
        //         int big=useSpecialAbility();
        //         return big;
        //     }
        //     return aPower;
        // }

        int attack() override {
            cout<<name<<" attacks with power "<<aPower<<endl;
            mana+=50;
            if(mana>=100){
                int big=useSpecialAbility();
                return big+aPower;
            }
            return aPower;
        }

        void target(int receive) override{
            BaseCharacter::target(receive);
            if(defend()){
                cout<<"Archer defended successfully, No damage taken"<<endl;
            }
            else{
                health-=receive;
                cout<<"Archer takes "<<receive<<" damage!"<<endl;
            }
            displayStats();
        }

        bool defend() override {
            int chance = rand() %100;
            if (chance < 50){
                return true;
            }else{
                return false;
            }
        }

        int useSpecialAbility() override{
            cout<<"Archer uses Fire Arrow 🏹🏹🏹 with power 30!"<<endl;
            return sPower;
        }

};



class GameEngine{

    private:
        vector<CharacterActions*> charecters;
        int BossHealth;

    public:

        GameEngine()
            :BossHealth(150)
        {}

        void addCharacter(CharacterActions* character) {
            charecters.push_back(character);
        }

        void BossAttack(int i){
            charecters[i]->target(30);
        }

        void bossAttacked(int recv){
            BossHealth-=recv;
            if(BossHealth<0) BossHealth=0;
            cout<<"Boss takes "<<recv<<" damage! Health now: "<<BossHealth<<endl;
        }

        bool isBossAlive(){
            if(BossHealth>0) return true;
            else return false;
        }

        void playgame(){

            while (BossHealth>0)
            {
                //charecter's loop
                cout<<"========player's turn: \n";
                for (int i = 0; i < 3 && isBossAlive(); i++)
                {
                    bossAttacked(charecters[i]->attack());
                }
                
                cout<<"\n\n";

                //boss's loop
                if(isBossAlive()) cout<<"========boss's turn: \n";
                for (int i = 0; i < 3  && isBossAlive(); i++)
                {
                    BossAttack(i);
                }

                cout<<"\n\n";
            }
            cout<<"Boss defeated!! Players won!!"<<endl;
            
        }



};



int main(){
    srand(time(0));
    #ifdef _WIND32
        system("cls");
    #else
        system("clear");
    #endif

    GameEngine game;
    game.addCharacter(new warrior("Ulfric warrior"));
    game.addCharacter(new mage("Jadaeim mage"));
    game.addCharacter(new archer("Athena archer"));
    game.playgame();
}










































/*GameEngine(CharacterActions** arr){
            if(arr[0]!=NULL) charecters.push_back(arr[0]);
            else{
                cout<<"Please insert 3 charecters";
                exit;
            }
            if(arr[1]!=NULL) charecters.push_back(arr[1]);
            else{
                cout<<"Please insert 3 charecters";
                exit;
            }
            if(arr[2]!=NULL) charecters.push_back(arr[2]);
            else{
                cout<<"Please insert 3 charecters";
                exit;
            }
            BossHealth=150;
            cout<<"Game charecters received, Boss initialized"<<endl;
        }*/