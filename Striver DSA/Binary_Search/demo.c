#include <stdio.h>
int main()
{
    int i, n, j;
    int x = 12;
    int count = 0;
    printf("enter the no of elements in array:");
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        printf("the element no  %d =", i + 1);
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if ((a[i] + a[j]) == x)
            {
                count++;
                printf("the pair are=%d,%d\n", a[i], a[j]);
            }
        }
    }
    printf("the no of pair which sum's is equal to x = %d", count);
    printf("\n");
    return 0;
}