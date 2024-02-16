

/*
//              ENCAPSULATION-->Wrapping up data members and functions
//  Fully encapsulated class:- those class in which all data memebers are private members
// Advantage:-
// -->(Data hiding)
// -->If we want we can mark data read only
// -->Code reusability
// -->Encapsulated code is better for unit testing

#include<bits/stdc++.h>
using namespace std;
class Student{
    string name;
    int age;
    int marks;
    public:
    void setAge(int age){
        this-> age= age;
    }
    int getAge(){
        return this->age;
    }
};
int main()
{
    Student first;
    cout<<"Sab badhiya chal rha hai guru"<<endl;
    first.setAge(15);
    cout<<first.getAge()<<endl;
    return 0;
}
*/

/*
//                  INHERITANCE
#include<bits/stdc++.h>
using namespace std;
class Human{
    public:
    int height;
    int weight;
    int age;
};

class Male: public Human{
    public:
    string color="Red";
    void Sleep(){
        cout<<"Male sleeping"<<endl;
    }
};
int main()
{
    Male object1;
    object1.weight=45;
    cout<<object1.age<<endl;
    cout<<object1.height<<endl;
    cout<<object1.weight<<endl;
    cout<<object1.color<<endl;
    object1.Sleep();
    cout<<endl;
    return 0;
}
*/

//                                                 TYPES OF INHERITANCE
//                                            -> Single Inheritance
//                                            -> Multi-Level Inheritance
//                                            -> Multiple Inheritance
//                                            -> Hybrid Inheritance
//                                            -> Hierarichal Inheritance

/*

// -> Single Inheritance
#include <bits/stdc++.h>
using namespace std;
class Animal
{
private:
    int age;

public:
    int weight;

    void sleep(){
        cout<<"Animal is sleeping"<<endl;
    }
};
class Dog: public Animal{

};
int main()
{
    Dog d1;
    d1.sleep();
    cout<<d1.weight<<endl;
    return 0;
}
*/

/*
// Multi- Lvel Inheritance
#include <bits/stdc++.h>
using namespace std;
class Animal
{
private:
    int age;

public:
    int weight;

    void sleep(){
        cout<<"Animal is sleeping"<<endl;
    }
};
class Dog: public Animal{
    public:
    int avgDoglife=11;
};

class GermanShepherd: public Dog{

};
int main()
{
    GermanShepherd g1;
    g1.sleep();
    cout<<g1.avgDoglife<<endl;
    return 0;
}
*/

/*
                                        // Multiple Inheritance
#include <bits/stdc++.h>
using namespace std;
class Animal
{
private:
    int age;

public:
    int weight;

    void bark(){
        cout<<"Animal is barking"<<endl;
    }
};
class Human{
    public:
    string color;

    void speak(){
        cout<<"Human is speaking"<<endl;
    }
};

// Multiple Inheritance
class Hybrid: public Animal, public Human{

};
int main()
{
    Hybrid h1;
    h1.bark();
    h1.speak();
    return 0;
}
*/

/*
//      Hierarichal Inheritance --> One class serve as parent class for more than one class
#include<bits/stdc++.h>
using namespace std;
class A{
    public:
    void fun1(){
        cout<<"Inside function 1"<<endl;
    }
};
class B: public A{
    public:
    void fun2(){
        cout<<"Inside function 2"<<endl;
    }
};
class C: public A{
    public:
    void fun3(){
        cout<<"Inside function 3"<<endl;
    }
};
int main(){
    A object1;
    object1.fun1();

    B object2;
    object2.fun1();
    object2.fun2();

    C object3;
    object3.fun1();
//  object3.fun2();         //--> It throws an error bcoz class C inherited only class A not class B too
    object3.fun3();
    return 0;
}
*/

/*
// Hybrid inheritance --> Whenever we inherit more than one class by more than inheritance type
#include<bits/stdc++.h>
using namespace std;
class A{
    public:
    void fun1(){
        cout<<"Inside function 1"<<endl;
    }
};
class B: public A{
    public:
    void fun2(){
        cout<<"Inside function 2"<<endl;
    }
};
class D{
    public:
    void fun3(){
        cout<<"Inside function 3"<<endl;
    }
};

//  Hybrid Inheritance
class C: public A,public D{
    public:
    void fun4(){
        cout<<"Inside function 4"<<endl;
    }
};

int main(){
    C obj1;
    obj1.fun1();
    obj1.fun3();
    obj1.fun4();
    return 0;
}
*/

/*
//                                  INHERITANCE AMBIGUITY
#include<bits/stdc++.h>
using namespace std;
class A{
    public:
    void fun(){
        cout<<"Inside function of class A"<<endl;
    }
};
class B{
    public:
    void fun(){
        cout<<"Inside function of class B"<<endl;
    }
};
class C: public A,public B{
    public:
    void fun3(){
        cout<<"Inside function of class C"<<endl;
    }
};
int main(){
    C obj1;

//    obj1.fun();      // Here fun() function is ambiguous so here we have to deal with scope resolution operator
    obj1.A:: fun();
    obj1.B:: fun();
    return 0;
}
*/

//                  POLYMORPHISM --> exist in multiple forms
//  --> Compile time Polymorphism
//  --> Run time Polymorphism

// Compile time Polymorphism
// It has two types:-    1) Function Overloading   2) Operator Overloading

/*
// Function Overloading
#include<bits/stdc++.h>
using namespace std;
class A{

    public:
    void sayHello(){
        cout<<"Hello Uttam"<<endl;
    }
    int sayHello( char ch){
        cout<<"Hello Uttam Roy"<<endl;
        return 1;
    }
    void sayHello(string name){
        cout<<"Hello "<<name<<endl;
    }


// error: 'int A::sayHello()' cannot be overloaded because with only change in return type in function cann't be overloaded
    // int sayHello(){
    //     cout<<"Hello Uttam"<<endl;
    //     return 1;
    // }


};
int main()
{
    A obj1;
    obj1.sayHello();
    return 0;
}
*/

/*
// Operator overloading
#include<bits/stdc++.h>
using namespace std;
class A{
    public:
    int a;
    int b;
    int add(){
        return a+b;
    }
    void operator+ (A &obj){
        int value1=this->a;
        int value2=obj.a;
        cout<<"Output "<<value2-value1<<endl;
    }
    void operator/ ( A &obj){
        int value1=this->a;
        int value2=obj.a;
        cout<<"Output "<<value2/value1<<endl;
    }
};
int main(){
    A obj1, obj2;
    obj1.a=4;
    obj2.a=24;
    obj1+obj2;
    obj1/obj2;
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
class Animal{
    public:
    void speak(){
        cout<<"Speaking"<<endl;
    }
};
class Dog:public Animal{
    public:
    // if this speaks is not present then speak function of parent class will be called
    void speak(){
        cout<<"Barking"<<endl;
    }
};
int main(){
    Dog d1;
    d1.speak();
    return 0;
}
*/






/*
//                  ABSTRACTION--> Implementation Hiding
#include<bits/stdc++.h>
using namespace std;
class Hero{
    int age;
    int health;
    public:
    void setAge(int age)
    {
        this->age= age;
    }
    void setHealth(int health)
    {
        this->health= health;
    }
    void print()
    {
        cout<<"Age "<<this->age<<endl;
        cout<<"Health "<<this->health<<endl;
    }
};
int main()
{
    Hero h1;
    h1.setAge(15);
    h1.setHealth(45);
    h1.print();
return 0;
}
*/