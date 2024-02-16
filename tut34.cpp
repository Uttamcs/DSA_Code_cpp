/*
// Find reverse of  a string using recursion
#include<bits/stdc++.h>
using namespace std;
void reverse(string &str, int i, int j)
{
    if (i>j)
    {
        return ;
    }
    swap(str[i], str[j]);
    i++;
    j--;
    reverse(str, i,j);
}
int main()
{
    string name="Uttam";
    cout<<"Before : "<<name<<endl;
    reverse(name , 0,name.length()-1);
    cout<<"After : "<<name<<endl;
    return 0;
}
*/






/*
// Check given string is Pallindrome or not using recursion
#include<iostream>
using namespace std;
bool chkPallindrome(string name, int i , int j)
{
    if (i>j)
    {
        return true;
    }
    if (name[i]!=name[j])
    {
        return false;
    }
    else{
        return chkPallindrome(name,i+1, j-1);
    }
    
}
int main()
{
    string name="abbcba";
    bool isPallindrome=chkPallindrome(name,0,name.length()-1);
    if (isPallindrome)
    {
        cout<<"It's a pallindrome string "<<endl;
    }else{
        cout<<"It's not a pallindrome string "<<endl;
    }
    
    return 0;
}
*/






/*
//Find a to the power b with the help of recursion
#include<bits/stdc++.h>
using namespace std;
int power(int a, int b)
{
    if (b==0)
    return 1;
    if(b==1)
    return a;
    int ans =power(a,b/2); 
    if(b%2==0)
    {
        return ans*ans;
    }
    else{
        return a*ans*ans;
    }
}
int main()
{
    int a,b;
    cout<<"Enter any two number: "<<endl;
    cin>>a>>b;
    cout<<"Answer is "<<power(a,b)<<endl;
    return 0;
}
*/















/*
// Bubble sort using recursion
#include<iostream>
using namespace std;
void sortArray(int arr[], int size)
{
    if(size==0 || size==1)
    {
        return ;
    }
    for (int i = 0; i < size-1; i++)
    {
        if (arr[i]>arr[i+1])
        {
            swap(arr[i],arr[i+1]);
        }
    }
    sortArray(arr, size-1);
}
int main()
{
    int arr[5]={51,18,40,365,754};
    int size=5;
    sortArray(arr,size);
    cout<<"After sorting array will be like this "<<endl<<endl<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
*/