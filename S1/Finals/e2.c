#include <stdio.h>
#include <stdlib.h>
void print_array(int *start_ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *start_ptr++);
    }
    printf("\n");
}
int difference(int *ptr1, int *ptr2)
{
    return ptr2 - ptr1;
}
int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int *p1 = &arr[1]; // points to 20
    int *p2 = &arr[4]; // points to 50
    print_array(arr, 5);
    int diff = difference(p1, p2);
    printf("Difference between p2 and p1: %d\n", diff);
    return 0;
}