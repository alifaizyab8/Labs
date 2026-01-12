#include <stdio.h>
int main()
{
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[10];
    int *ptr1 = arr1;
    int *ptr2 = arr2;
    for (int i = 0; i < 10; i++)
    {
        *(ptr2 + i) = *(ptr1 + i);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", *(ptr2 + i));
    }
}