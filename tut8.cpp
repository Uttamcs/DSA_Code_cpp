/*
#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cout << "Enter the value of a and b:-" << endl;
    cin >> a >> b;
    char op;
    cout << "Enter the operator you want to perform:-" << endl;
    cin >> op;
    switch (op)
    {
    case '+':
        cout << (a + b) << endl;
        break;
    case '-':
        cout << (a - b) << endl;
        break;
    case '*':
        cout << (a * b) << endl;
        break;
    case '/':
        cout << (a / b) << endl;
        break;
    case '%':
        cout << (a % b) << endl;
        break;

    default:
        cout << "INVALID INPUT" << endl;
    }
    return 0;
}
*/





/*
// Calculating Power using user defined function
#include <iostream>
using namespace std;

int uttam_pow(int a, int b)
{
    int ans = 1;
    for (int i = 0; i <= b; i++)
    {
        ans = ans * a;
    }
    return ans;
}
int main()
{
    int a, b;
    cout << "Enter the value of a and b:-" << endl;
    cin >> a >> b;
    cout << uttam_pow(a, b);
    return 0;
}
*/

/*
// WAP to find entered number is even or odd
#include<iostream>
using namespace std;
bool isEven(int n){
    if (n&1){
        return 0;
    }
    return 1;
}
int main(){
    int num;
    cout<<"Enter any number:-"<<endl;
    cin>>num;
    if (isEven(num)){
        cout<<"Number is Even"<<endl;
    }
    else{
        cout<<"Number is Odd"<<endl;
    }
    return 0;
}
*/

/*
// WAP to finf nCr
#include <iostream>
using namespace std;

int factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}

int nCr(int n, int r)
{
    int num = factorial(n);
    int den = factorial(r) * factorial(n - r);
    int nCr = num / den;
    return nCr;
}

int main()
{
    int a, b;
    cout << "Enter the value of n and r:-" << endl;
    cin >> a >> b;
    cout << nCr(a, b) << endl;
    return 0;
}
*/

/*
// WAP to print counting till n
#include<iostream>
using namespace std;

void printcounting(int n){
    for (int i = 1; i <= n; i++)
    {
        cout<<i<<'\t';
    }

}
int main(){
    int n;
    cout<<"Enter the value of n:-"<<endl;
    cin>>n;
    printcounting(n);
    return 0;

}
*/

/*
//  WAP to check given number is prime or not
#include<iostream>
using namespace std;
bool isPrime(int n){
    for (int i = 2; i < n; i++)
    {
        if (n%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n;
    cout<<"Enter any number:-"<<endl;
    cin>>n;
    if (isPrime(n)){
        cout<<"Prime number"<<endl;
    }else{
        cout<<"Not a Prime number"<<endl;
    }
    return 0;
}

*/




/*
// Call by Value
#include <iostream>
using namespace std;
void update(int n)
{
    n++;
    cout << "In Update function\nThe value of n is " << n << endl;
    ;
}
int main()
{
    int n;
    cout << "Enter the value of n:-" << endl;
    cin >> n;
    cout << "In main function\nBefore updating the value of n is " << n << endl;
    update(n);
    cout << "In main function\nAfter updating the value of n is " << n << endl;

    return 0;
}
*/