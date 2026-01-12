#include <stdio.h>
void arrInput(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void largest(int arr[], int n)
{
    int large = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > large)
        {
            large = arr[i];
        }
    }
    printf("Largest number is: %d\n", large);
}
int main()
{
    int rollNum = 12;
    int arr[rollNum];
    arrInput(arr, rollNum);
    largest(arr, rollNum);
}