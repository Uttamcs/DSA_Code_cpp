/*

// Find number of prime number exist till given number n

#include <bits/stdc++.h>
using namespace std;
int countPrimes(int n)
{
    int count = 0;
    vector<bool> prime(n, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            count++;
            for (int j = 2 * i; j < n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    return count;
}
int main()
{
    int num;
    cout << "Enter any number:";
    cin >> num;
    cout << countPrimes(num);
    return 0;
}

*/






/*
//Find GCD of two given numbers
#include<bits/stdc++.h>
using namespace std;
int gcd(int x, int y)
{
    if(x==0)
    return y;

    if(y==0)
    return x;

    while (x!=y)
    {
        if (x>y)
        {
            x=x-y;
        }
        else
        {
            y=y-x;
        }
    }
    return y;
}
int main()
{
    int a,b;
    cout<<"Enter any two number:";
    cin>>a>>b;
    int ans=gcd(a,b);
    cout<<"GCD of "<<a<<" and "<<b<<" is "<<ans<<endl;
    return 0;
}
*/






// You are given a three integers 'X', 'N' and 'M'.Your task is to find ('X' ^ 'N')% 'M'.
// 'A' ^ 'B' is defined as A raise to the power B.

#include<bits/stdc++.h>
using namespace std;
int modularExponentiation(int x, int n, int m)
{
    int res=1;
    if(n&1)
    {//Odd
        res=res*x;
    }
}
int main()
{
    int x,n,m;
    cout<<"Enter the value of X, N and M ";
    cin>>x>>n>>m;
}