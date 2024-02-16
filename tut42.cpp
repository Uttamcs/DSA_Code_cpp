/*
#include<bits/stdc++.h>
using namespace std;
class Hero{
    int health;
    char level;
    public:
    int getHealth(){
        return health;
    }
    char getLevel(){
        return level;
    }
    void setHealth(int h){
        health=h;
    }
    void setLevel(char c){
        level=c;
    }
};
int main()
{
    // static allocation
    Hero h1;
    cout<<"Size: "<<sizeof(h1)<<endl;       // why 8 read about padding and greedy alignment
    h1.setHealth(80);
    h1.setLevel('A');
    cout<<"Health of h1 is "<<h1.getHealth()<<endl;
    cout<<"Level of h1 is "<<h1.getLevel()<<endl;


    // dynamic allocation
    Hero *b= new Hero;
    (*b).setHealth(50);  // can also be written as  b->setHealth(50);
    b->setLevel('G');    // can also be written as  b->setLevel('G');
    cout<<"Health of b is "<<(*b).getHealth()<<endl;
    cout<<"Level of b is "<<(*b).getLevel()<<endl;
    cout<<"Health of b is "<<b->getHealth()<<endl;
    cout<<"Level of b is "<<b->getLevel()<<endl;


    return 0;
}
*/






/*
#include<bits/stdc++.h>
using namespace std;
class Hero{
    public:
    // constructor creation
    Hero(){
        cout<<"Constructor Called"<<endl;
    }
};
int main()
{
    // statically object creation
    Hero Uttam;         //BTS!! --> Uttam.Hero() is called

    // dynamically object creation
    Hero *ramesh=new Hero;

    return 0;
}
*/









/*
// User defined constructor--> Whenever we define a new constructor default constructor dies
#include <iostream>
using namespace std;
class Hero
{
private:
    int health;

public:
    char level;
    // parameterised constructor
    Hero(int health){
        this-> health=health;
    }
    Hero(int health, char level){
        this-> health=health;
        this-> level=level;
    }
    void print(){
        cout<<"Health "<<health<<endl;
        cout<<"Level "<<level<<endl;
    }
};
int main()
{
    // Hero Rahul;    //--> this line gives error bcoz we have defined new constructor so default constructor will die

    Hero ramesh(70);
    ramesh.print();

    Hero Uttam(485,'S');
    Uttam.print();
    return 0;
}
*/











/*
// copy constructor
#include<iostream>
using namespace std;
class Hero{
    int health;
    public:
    char level;
    Hero (int health, char level){
        this->health=health;
        this-> level=level;
    }
    // User defined copy constructor  --> Whenever we define some new copy constructor default copy constructor dies
    Hero(Hero& temp){
        cout<<"Apna wala copy constructor chal rha hai "<<endl;
        this->health=temp.health;
        this->level=temp.level;
    }
    void print(){
        cout<<"Health "<<this->health<<endl;
        cout<<"Level "<<this->level<<endl;
    }
};
int main()
{
    Hero S(40,'S');
    S.print();

    // Copy constructor
    Hero R(S);
    R.print();
    return 0;
}
*/








/*
#include<bits/stdc++.h>
using namespace std;
class Hero{
    int health;
    public:
    char level; 
    char *name;

    Hero(){
        cout<<"Default constructor Called"<<endl;
        name=new char[100];
    }
    void setName( char name[]){
        strcpy(this->name, name);
    }
    void setHealth(int h){
        this->health=h;
    }
    void setLevel(char c){
        this->level=c;
    }
    void print(){
        cout<<endl;
        cout<<"[Name: "<<this->name;
        cout<<" , Health: "<<this->health;
        cout<<" , Level: "<<this->level<<"]" <<endl;
    }

};
int main()
{
    Hero hero1;
    char name[6]="Billu";
    hero1.setName(name);
    hero1.setLevel('A');
    hero1.setHealth(90);
    hero1.print();

    Hero hero2(hero1);          //Default copy makes shallow copy it means it doesn't have a copy it points to the same address
    hero2.print();


    hero1.name[0]='D';
    hero1.print();
    
    hero2.print();
    return 0;
}
*/















/*
#include<bits/stdc++.h>
using namespace std;
class Hero{
    int health;
    public:
    char level; 
    char *name;

    Hero(){
        cout<<"Default constructor Called"<<endl;
        name=new char[100];
    }



    // user defined constructor makes deep copy. Deep copy means it actually copy it to new address
    Hero(Hero& temp){
        cout<<"Apna wala copy constructor chal rha hai "<<endl;
        char *ch=new char[strlen(temp.name)+1];
        strcpy(ch, temp.name);
        this-> name= ch;

        this->health=temp.health;
        this->level=temp.level;
    }
    void setName( char name[]){
        strcpy(this->name, name);
    }
    void setHealth(int h){
        this->health=h;
    }
    void setLevel(char c){
        this->level=c;
    }
    void print(){
        cout<<endl;
        cout<<"[Name: "<<this->name;
        cout<<" , Health: "<<this->health;
        cout<<" , Level: "<<this->level<<"]" <<endl;
    }

};
int main()
{
    Hero hero1;
    char name[6]="Billu";
    hero1.setName(name);
    hero1.setLevel('A');
    hero1.setHealth(90);
    hero1.print();

    Hero hero2(hero1);         
    hero2.print();

    hero1.name[0]='D';
    hero1.print();
    
    hero2.print();
    return 0;
}

*/












/*
// Destuructor
#include<bits/stdc++.h>
using namespace std;
class Hero{
    int health;
    public:
    char level;
    void setHealth(int health){
        this->health=health;
    }
    void setLevel(char level){
        this-> level= level;
    }
    int getHealth(){
        return this->health;
    }
    char getLevel(){
        return this->level;
    }
    // Constructor creation
    Hero(){
        cout<<" Simple Constructor called"<<endl;
    }
    // Destructor creation
    ~Hero(){
        cout<<"Destructor called"<<endl;
    }
};
int main()
{
    // Statically  -->iske liye destructor khud call ho jaega but dynamically k liye manually krna pdega
    Hero a;

    //Dynamically
    Hero *b=new Hero;
    // manually destructor call
    delete b;

    return 0;
}

*/














/*
//              Static keyword
#include<bits/stdc++.h>
using namespace std;
class Hero{
    int health;
    public:
    char level;
    static int timeToComplete;
    void setHealth(int health){
        this->health=health;
    }
    void setLevel(char level){
        this-> level= level;
    }
    int getHealth(){
        return this->health;
    }
    char getLevel(){
        return this->level;
    }
    // Constructor creation
    Hero(){
        cout<<" Simple Constructor called"<<endl;
    }
    // Destructor creation
    ~Hero(){
        cout<<"Destructor called"<<endl;
    }
};
int Hero ::timeToComplete=5;
int main()
{
    cout<<Hero::timeToComplete<<endl;
    // Statically  -->iske liye destructor khud call ho jaega but dynamically k liye manually krna pdega
    Hero a;
    cout<<a.timeToComplete<<endl;   // bad practice


    return 0;
}
*/


















/*
//              Static Function  --> it can accesss only static keyword
// --> Object bnane ki koi need nahi hai
// --> this keyword nahi hoti isme qki this keyword point pointer to object and isme to obhject hai hi nahi
#include<bits/stdc++.h>
using namespace std;
class Hero{
    int health;
    public:
    char level;
    static int timeToComplete;
    void setHealth(int health){
        this->health=health;
    }
    void setLevel(char level){
        this-> level= level;
    }
    int getHealth(){
        return this->health;
    }
    char getLevel(){
        return this->level;
    }

    // static function craetion
    static int random(){
        return timeToComplete;
    }

    // Constructor creation
    Hero(){
        cout<<" Simple Constructor called"<<endl;
    }

    // Destructor creation
    ~Hero(){
        cout<<"Destructor called"<<endl;
    }
};
int Hero ::timeToComplete=5;
int main()
{
    cout<<Hero:: random()<<endl;
    return 0;
}
*/
