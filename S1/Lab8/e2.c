#include <stdio.h>
int main()
{
    float arr[4] = {1.1, 2.2, 3.3, 4.4};
    float *ptr = arr;
    float sum = 0.0;
    for (int i = 0; i < 4; i++)
    {
        printf("%.1f\n", *(ptr + i));
        sum += *(ptr + i);
    }
    printf("sum = %.1f\n", sum);
}