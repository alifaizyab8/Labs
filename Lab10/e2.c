#include <stdio.h>
#include <stdlib.h>
int main(void) {
    printf("Enter number of Inputs: ");
    int n;
    scanf("%d", &n);
    //using calloc to allocate memory
    int *ptr = (int *)calloc(n, sizeof(int));
    int max = ptr[0];
    for (int i = 0; i < n; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &ptr[i]);
        if (ptr[i] > max)
        {
            max = ptr[i];
        }

    }
    printf("Max: %d\n", max);
    free(ptr);
    return 0;
}
