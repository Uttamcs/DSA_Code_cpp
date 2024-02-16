/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i=5;
    // Creating a reference variable
    int &j=i;
    cout<<i<<endl;
    i++;
    cout<<i<<endl;
    j++;
    cout<<i<<endl;
    cout<<j<<endl;
    cout<<&i<<endl;
    cout<<&j<<endl;
    return 0;
}
*/



/*
#include<bits/stdc++.h>
using namespace std;
void update1(int n)
{
    n++;
}

void update2(int & n)
{
    n++;
}
int main()
{
    int n=5;
    cout<<"Before "<<n<<endl;
    update1(n);
    cout<<"After "<<n<<endl;
    cout<<endl<<"AFTER USING REFERENCE VARIABLE"<<endl<<endl;
    cout<<"Before "<<n<<endl;
    update2(n);
    cout<<"After "<<n<<endl;
    return 0;
}
*/







/*
#include<bits/stdc++.h>
using namespace std;
int& func(int a)
{
    int num=a;
    int &ans=num;
    ans++;
    return ans;
}

int* doubl(int a)
{
    int num=a;
    int *ans=&num;
    *ans=(*ans) *2;
    return ans;
}

int main()
{
    int n=5;
    cout<<func(n)<<endl;
    cout<<*(doubl(n))<<endl;
    return 0;
}
*/





/*

//          CREATING A 1D ARRAY BY USING DYNAMIC MEMORY ALLOCATION AND FINDING IT'S SUM

#include<bits/stdc++.h>
using namespace std;
int getSum(int *arr, int n)
{
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];            //arr[i] can also be written as *(arr+i)
    }
    return sum;
}
int main()
{
    int n;
    cout<<"Enter the size of an array "<<endl;
    cin>>n;
    // array creation
    int *arr=new int[n];

    // taking input
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    // Finding sum
    int ans=getSum(arr,n);
    cout<<"Sum of given Array is "<<ans<<endl;

    // Releasing memory
    delete []arr;    
    return 0;
}
*/








