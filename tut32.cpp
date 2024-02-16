/*
//                      RECURSUION PART-2
// Source destination Problem
#include<bits/stdc++.h>
using namespace std;
void reachHome(int src, int dest)
{
    cout<<"Source "<<src<<" Destination "<<dest<<endl;
    if(src==dest)
    {
        cout<<"Bahot badhiya!!! \n Pahuch gyee "<<endl;
        return ;
    }
    src++;
    reachHome(src, dest);
}
int main()
{
    int source=1;
    int destination=10;
    reachHome(source, destination);
    return 0;
}
*/




/*
#include <bits/stdc++.h>
using namespace std;
int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
    {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
    int n;
    cout << "Enter any number: " << endl;
    cin >> n;
    cout << n << "th fibonacci term is " << fibonacci(n);
    return 0;
}
*/






/*

// You have been given a number of stairs. Initially, you are at the 0th stair, and ypu need to reacg the Nth stair. Each time 
// you can either climb one step or two steps. You are supposed to return the number of distinct ways in which you can climb from 
// the 0th step to Nth step.
#include<bits/stdc++.h>
using namespace std;
int countDistinctways(long long nStairs )
{
    if(nStairs<0)
    return 0;
    if(nStairs==0)
    return 1;

    int ans=countDistinctways(nStairs-1)+countDistinctways(nStairs-2);
    return ans;
}
int main()
{
    int n;
    cout<<"Enter number of stairs: "<<endl;
    cin>>n;
    cout<<"Total number of distinct ways is "<<countDistinctways(n);
    return 0;
}

*/






/*

// Say digit
#include<bits/stdc++.h>
using namespace std;
void sayDigit(string arr[], int num)
{
    if(num==0)
    return;
    
    int digit=num%10;
    num=num/10;

    // Recursive Call
    sayDigit(arr, num);
    cout<<arr[digit]<<" ";
}
int main()
{
    string arr[10]={"Zero", "One", "Two", "Three", "Four", "Five",
    "Six","Seven","Eight", "Nine"};
    int num;
    cout<<"Enter any number: "<<endl;
    cin>>num;
    cout<<endl<<endl;
    sayDigit(arr, num);
    cout<<endl<<endl;

    return 0;
}
*/