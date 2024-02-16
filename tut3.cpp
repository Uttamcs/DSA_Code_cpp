/*#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n > 0)
    {
        cout << "Entered number is positive"<<endl;
    }
    else
    {
        cout<<"Entered number is negative"<<endl;
    }
}
*/
/*
#include <iostream>
using namespace std;
int main()
{
    int a,b ;
    // cin doesn't reads space, tab and enter
    cin >> a>>b;
    if (a>b)
    {
        cout << "A is greater"<<endl;
    }
    if (b>a)
    {
        cout<<"B is greater"<<endl;
    }
}
*/


/*
#include <iostream>
using namespace std;
int main()
{
    int n;
    // cin.get() is used to scan charcter as well
    n=cin.get();
    cout<<"ASCII value of Entered charcter is "<<n<<endl;
}
*/


/*
// Check entered character is uppercase or lowercase or numeric
#include<iostream>
using namespace std;
int main(){
    char ch;
    cout<<"Enter any character:";
    cin>>ch;
    if (ch>='a' && ch<='z'){
        cout<<"This is lowercase";
    }
    else if (ch>='A' && ch<='Z'){
        cout<<"This is uppercase";
    }
    else if (ch>='0' && ch<='9'){
        cout<<"This is numeric";
    }
}
*/


/*
// Printing Pattern
#include <iostream>
using namespace std;
int main() {
    int a;
    cin>>a;
    int i=0;
    while(i<a){
        int j=0;
        while (j<a)
        {
            cout<<"* ";
            j++;
        }
        cout<<endl;
        i++;
    }
}
*/


/*
#include<iostream>
using namespace std;
int main(){
    int num;
    cin>>num;
    int i=1;
    while (i<=num)
    {
        int j=1;
        int value=j;
        while (j<=num-i+1)
        {
            cout<<value<<" ";
            value++;
            j++;
        }
        int j=1;
        while(j<=(2*i)-2)
        {
            cout<<"* ";
            j++;
        }
        j=num-i+1;
        while(j>=1){
            cout<<j<<" ";
            j--;
        }
       i++;
       cout<<endl; 
    }
    
}
*/

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
}