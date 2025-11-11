#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Enter number of Inputs: ");
    int n;
    scanf("%d", &n);
    int *ptr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", (ptr + i));
    }
    printf("Allocating 3 more \n");
    ptr = (int *)realloc(ptr, (n + 3) * sizeof(int));
    for (int i = n; i < n + 3; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", (ptr + i));
    }
    printf("The numbers are: \n");
    for (int i = 0; i < n + 3; i++)
    {
        printf("%d\n", ptr[i]);
    }
    free(ptr);

    return 0;
}
