#include <stdio.h>
int main()
{
    int str[10] = {12, 34, 56, 78, 90, 11, 23, 45, 67, 89};
    int target;
    printf("Enter the number to search: ");
    scanf("%d", &target);
    for (int i = 0; i < 10; i++)
    {
        if (str[i] == target)
        {
            printf("Number %d found at index %d\n", target, i);
        }
        
    }
}