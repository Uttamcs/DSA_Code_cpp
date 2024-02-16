/*
//          MACROS
#include<bits/stdc++.h>
using namespace std;
#define pi 3.14
int main()
{
    int rad;
    cout<<"Enter radius of circle: "<<endl;
    cin>>rad;
    cout<<"Area of circle is "<<pi*rad*rad<<endl;
    return 0;
}
*/





/*
//                  Global variables
#include<bits/stdc++.h>
using namespace std;
int score=15;     //--->Global variable (Don't use it.It's a bad practice)
int a(int i)
{
    cout<<"In a:"<<i<<endl;
    cout<<"Score In a:"<<score<<endl;
    score++;
}
int b(int i)
{
    cout<<"In b:"<<i<<endl;
    cout<<"Score In b:"<<score<<endl;
}
int main()
{
    int i=5;
    a(i);
    b(i);
    cout<<"In main: "<<i<<endl;
    cout<<"Score In main:"<<score<<endl;
    return 0;
}
*/












/*

//                  INLINE FUNCTIONS---> return value is replaced before compilation of code same as macros
// Rules for declaring inline function:-
// if function body is of one line --> can be made inline function always
// if function body is of two to three lines --> may be made inline function it depends on compiler
// if function body is of more than one line --> cann't be made inline function 

#include<bits/stdc++.h>
using namespace std;
int getMax(int a, int b)
{
    return (a>b)?a:b;
}
int main()
{
    int ans;
    int a=1, b=2;
    ans=getMax(a,b);
    cout<<"Maximum of a and b is "<<ans<<endl;
    a+=4;
    b+=1;
    ans=getMax(a,b);
    cout<<"Maximum of a and b is "<<ans<<endl;

    return 0;
}
*/










//                      DEFAULT ARGUMENTS
#include<bits/stdc++.h>
using namespace std;
void print(int arr[], int n, int start=0)
{
    for (int i = start; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[5]={1,2,34,5,6};
    print(arr, 5);
    return 0;
}