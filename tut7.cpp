
/*

// The complement of an integer is the integer you get when you flip all the 0 's to 1 's and all the 1 's to 0 's in its binary
// representation. For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2 .

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n, m, ans;
    cin >> n;
    m = n;
    int mask = 0;

    // Edgecase
    if (m == 0)
    {
        ans=1;
    }
    while (m != 0)
    {
        mask =( (mask << 1) | 1);
        m = m >> 1;
        cout<<m<<endl;
    }
    if (n!=0)
    {
        ans = (~n) & mask;
    }

    // cout<<ans;
    return 0;
}
*/



/*
// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed
// 32- bit integer range [-2^31, 2^31 -1], then return 0

#include <iostream>
using namespace std;
int main()
{
    int n, flag = 0;
    cin >> n;
    int ans = 0;
    while (n != 0)
    {
        int digit = n % 10;
        if (ans >= (2147483648 - digit) / 10)
        {
            ans=0;
            break;
        }else
        {
        ans = (ans * 10) + digit;
        n = n / 10;
        }
    }
    cout << ans;
}
*/





