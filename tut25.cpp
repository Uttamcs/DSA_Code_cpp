/*
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num = 5;
    cout << num << endl;

    // Address of operator - &

    cout << "Address of num is " << &num << endl;
    int *ptr = &num;
    cout<<"Address is stored in ptr= "<< ptr<<endl;
    cout << "Value is " << *ptr << endl;



    double d=4.3;
    cout<<"Address of d is "<<&d<<endl;
    double *dt=&d;
    cout<<"Address stored int dt is "<<dt<<endl;
    cout<<"Value at dt is "<<*dt<<endl;



    cout<<"Size of int is "<<sizeof(num)<<endl;
    cout<<"Size of ptr is "<<sizeof(ptr)<<endl;
    return 0;
}
*/





// Let's play with pointer


/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    // pointer to int is created, and pointed to some garbage address
    int *ptr;
    // Although it's a bad practice when we have to initialise a pointer then assign it to 0 which gives us segmentation fault--> int *ptr=0;
    cout<<"Value in ptr is "<<ptr<<endl;
    cout<<"Value at which pointer is pointed "<<*ptr<<endl;
    return 0;
}





#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i=5;
    int *ptr=0;
    ptr=&i;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;
    return 0;
}

*/



#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num=5;
    int a=num;
    cout<<"a Before "<<num<<endl;
    a++;
    cout<<"a After "<<num<<endl;


    int *p=&num;
    cout<<"Before "<<num<<endl;
    (*p)++;
    cout<<"After "<<num<<endl;

    // Copying a pointer
    int *q=p;
    cout<<p<<"  --  "<<q<<endl;
    cout<<*p<<"  --  "<<*q<<endl;


    // Important Concept
    int i=3;
    int *t=&i;
    *t=*t+1;
    cout<<*t<<endl;
    cout<<"Before t "<<t<<endl;
    t=t+1;
    cout<<"After t "<<t<<endl;
    return 0;
}