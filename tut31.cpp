/*
//              RECURSION

// factorial using recursion
#include<bits/stdc++.h>
using namespace std;
int factorial(int n)
{
    if (n==0)
    return 1;
    return n*factorial(n-1);
}
int main()
{
    int n;
    cout<<"Enter any number:"<<endl;
    cin>>n;
    cout<<"Factorial of n is "<<factorial(n)<<endl;
    return 0;
}

*/







/*
// a to the power b using recursion
#include<bits/stdc++.h>
using namespace std;
int power(int m, int n)
{
    if (n==0)
    {
        return 1;
    }
    return m*power(m,n-1);
}
int main()
{
    int m,n;
    cout<<"Enter any two number:"<<endl;
    cin>>m>>n;
    cout<<m <<" to the power "<<n <<" is "<<power(m,n)<<endl;
    return 0;
}
*/






/*
//      printing counting using recursion
#include<bits/stdc++.h>
using namespace std;
void printCount(int n)
{
    if(n==0)
    return ;
    cout<<n<<endl;
    printCount(n-1);
}
int main()
{
    int n;
    cout<<"Enter any number "<<endl;
    cin>>n;
    cout<<endl<<endl;
    printCount(n);
    return 0;
}
*/





/*
// Important concept
#include<bits/stdc++.h>
using namespace std;
void printCount(int n)
{
    if(n==0)
    return ;
    printCount(n-1);
    cout<<n<<endl;
}
int main()
{
    int n;
    cout<<"Enter any number "<<endl;
    cin>>n;
    cout<<endl<<endl;
    printCount(n);
    return 0;
}
*/


