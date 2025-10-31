#include <stdio.h>
void increment(int *ptr)
{
    *ptr += 10;
}
int main()
{
    int n;
    printf("Enter n: \n");
    scanf("%d", &n);
    int *ptr;
    ptr = &n;
    printf("n = %d before incrementing\n", n);
    increment(ptr);
    printf("n = %d after incrementing\n", n);
}