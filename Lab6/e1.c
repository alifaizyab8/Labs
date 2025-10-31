#include<stdio.h>
int main(void)
{
    int n = 142;
    long long arr[142];
    long long a, b, c;
    a = 0;
    b = 1;
    arr[0] = a;
    arr[1] = b;
    for (int i = 2; i < n; i++)
    {
        c = a + b;
        arr[i] = c;
        a = b;
        b = c;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%lld \n", arr[i]);
    }
    printf("\n");
    return 0;
}