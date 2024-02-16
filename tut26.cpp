
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {

//     /*
//     int arr[10]={41,12,583,45,56,16,78};
//     cout<<"Address of first memory block is "<<arr<<endl;
//     cout<<arr[0]<<endl;
//     cout<<"Address of first memory block is "<<&arr[0]<<endl;
//     cout<<"4th "<<*arr<<endl;
//     cout<<"5th "<<*arr+2<<endl;
//     cout<<"6th "<<*(arr+1)<<endl;
//     cout<<"7th "<<*(arr)+1<<endl;
//     cout<<"8th "<<arr[3]<<endl;
//     cout<<"9th "<<*(arr+3)<<endl;

//     // Chalaki---> arr[i] can be also written as i[arr] 
//     // Similarly, we know that arr[i]=*(arr+i) and it can also be written as i[arr]=*(i+arr)
//     int i=3;
//     cout<<i[arr]<<endl;
//     */


// /*
//     int temp[10]={1,5,6};
//     cout<<sizeof(temp)<<endl;
//     cout<<sizeof(*temp)<<endl;
//     cout<<sizeof(&temp)<<endl;
//     int *ptr=&temp[0];
//     cout<<sizeof(ptr)<<endl;
//     cout<<sizeof(*ptr)<<endl;
//     cout<<sizeof(&ptr)<<endl;
// */

//     /*
//     int a[20]={1,254,6,15,61};
//     cout<<a<<endl;
//     cout<<&a<<endl;
//     cout<<&a[0]<<endl;

//     int *p=&a[0];
//     cout<<p<<endl;
//     cout<<*p<<endl;
//     cout<<&p<<endl;
//     */


//     int arr[10]={5,1,65,2,1,6};
//     // ERROR
//         // arr=arr+1;

//     int *ptr=&arr[0];
//     cout<<"Before "<<ptr<<endl;
//     cout<<"Before "<<*ptr<<endl;
//     ptr=ptr+1;
//     cout<<"After "<<ptr<<endl;
//     cout<<"After "<<*ptr<<endl;
//     return 0;
// }




/*
//                  CHARACTER ARRAYS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[5]={1,2,3,4,50};
    char ch[6]="abcde";
    cout<<arr<<endl;
    cout<<ch<<endl;
    cout<<*arr<<endl;
    cout<<*ch<<endl;

    char *c=&ch[0];
    // prints entire string
    cout<<c<<endl;
    return 0;
}
*/






//                      POINTERS IN FUNCTIONS
#include<bits/stdc++.h>
using namespace std;
void print(int *p)
{
    cout<< p<<endl;
}

void update(int *p)
{
    p=p+1;
}
void updateVal(int *p)
{
    *p=*p+1;
}
int getsum(int arr[], int n)
{
    cout<<"Size: "<<sizeof(arr)<<endl;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }
    return sum;
}
int main()
{
    /*
    int value=5;
    int *ptr=&value;
    // print(ptr);
    cout<<"Before p ="<<ptr<<endl;
    update(ptr);
    cout<<"After p ="<<ptr<<endl;


    cout<<"Before p value ="<<*ptr<<endl;
    updateVal(ptr);
    cout<<"After p value ="<<*ptr<<endl;

    */
    int arr[5]={1,5,6,4,4};
    cout<<"Sum of array is "<<getsum(arr,5)<<endl;
    return 0;
}