//          CREATING A 2D ARRAY BY USING DYNAMIC MEMORY ALLOCATION
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    int **arr=new int*[n];

    // Creating a 2-D array
    for (int i = 0; i < m; i++)
    {
        arr[i]= new int[n];
    }
    
    // taking input
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
    }
    
    // printing array
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    // Memory releasing
    for (int i = 0; i < m; i++)
    {
        delete [] arr[i];
    }
    delete []arr;
    
    return 0;
}