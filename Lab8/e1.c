#include <stdio.h>
int main()
{
    int x, y;
    int *ptr;
    ptr = &x;
    *ptr = 5;
    printf("x = %d\n", x);
    ptr = &y;
    *ptr = 10;
    printf("y = %d\n", y);
}