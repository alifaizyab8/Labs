#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    printf("Enter number of Inputs: ");
    int n;
    scanf("%d", &n);
    int *ptr = (int *)malloc(n * sizeof(int));
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", ptr[i]);
        sum += ptr[i];
    }
    printf("Sum: %d\n", sum);
    free(ptr);
    return 0;
}
