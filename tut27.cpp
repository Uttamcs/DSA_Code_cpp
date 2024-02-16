/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i=5;
    int *p=&i;
    int **p2=&p;
    cout<<endl<<endl<<"Sab badhiya hai yha tak tohh..."<<endl<<endl;
    cout<<"Printing p "<<p<<endl;
    cout<<"Printing address of p "<<&p<<endl;
    cout<<"Printing *p2 "<<*p2<<endl;
    cout<<endl<<endl<<"PRINTING THE VALUE OF I "<<endl<<endl;
    cout<<"Printing i: "<<i<<endl;
    cout<<"Printing *p: "<<*p<<endl;
    cout<<"Printing **p2: "<<**p2<<endl;
    cout<<endl<<endl<<"PRINTING ADDRESS OF I "<<endl<<endl;
    cout<<"Printing &i: "<<&i<<endl;
    cout<<"Printing p: "<<p<<endl;
    cout<<"Printing *p2: "<<*p2<<endl;
    cout<<endl<<endl<<"PRINTING ADDRESS OF P "<<endl<<endl;
    cout<<"Printing &p: "<<&p<<endl;
    cout<<"Printing p2: "<<p2<<endl;
    return 0;
}
*/

//                      DOUBLE POINTERS IN FUNCTIONS
#include <bits/stdc++.h>
using namespace std;
void update(int **p2)
{
    // p2 = p2 + 1;
    // Kuxx change hoga??--> NO

    // *p2 = *p2 + 1;
    // Kuxx change hoga??--> YES

    **p2 = **p2 + 1;
    // Kuxx change hoga??--> YES

}
int main()
{
    int i = 5;
    int *p = &i;
    int **p2 = &p;
    cout << "Before :" << i << endl;
    cout << "Before :" << p << endl;
    cout << "Before :" << p2 << endl;
    update(p2);
    cout << "After :" << i << endl;
    cout << "After :" << p << endl;
    cout << "After :" << p2 << endl;
    return 0;
}