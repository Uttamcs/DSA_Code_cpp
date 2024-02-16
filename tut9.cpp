/*
#include<iostream>
using namespace std;
int main(){
    int number[15];
    cout<<"Value at 14 index is "<<number[14]<<endl;     //It prints some garbage value
    int second[3]={3,5,285};
    cout<<"Value at 2 index is "<<second[2]<<endl;
    int third[15]={2,7};
    int thirdsize=sizeof(third)/sizeof(int);   // It shows original size of the array
    cout<<"Size of third is "<<thirdsize<<endl;
    int fourth[10]={0};
    cout<<"Printing all element of fourth array"<<endl;
    for (int i = 0; i < 10; i++)
    {
        cout<<fourth[i]<<" ";
    }
    cout<<endl<<"Printing Done"<<endl;
    int n=10;
    int fifth[10]={1};
    int fifthsize=sizeof(fifth)/sizeof(int);
    cout<<"Size of fifth is "<<fifthsize<<endl;
    char ch[5]={'a', 'b','c','d','e'};
    cout<<ch[3]<<endl;
    cout<<"Printing the array "<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<ch[i]<< " ";
    }
    cout<<endl<<"Printing Done"<<endl;

    cout<<endl<<"Everything is fine"<<endl;
    return 0;
}
*/








/*
// If we intialize an array with a same number
#include<iostream>
using namespace std;
int main(){
    int arr[10]={5};
    cout<<"Printing an array"<<endl;
    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Printing Done"<<endl;

    cout<<endl<<endl<<endl;
    cout<<"Upper method fails"<<endl;
    for (int i = 0; i < 10; i++)
    {
        arr[i]=5;
    }
    
    cout<<"Printing an array"<<endl;
    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Printing Done"<<endl;
    
    return 0;
}
*/





