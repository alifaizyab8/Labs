#include <stdio.h>
int main()
{
    char name[20];
    int age;
    printf("Enter your name: ");
    scanf("%19[^\n]", name);
    printf("Enter your age: ");
    scanf("%d", &age);
    FILE *fptr;
    fptr = fopen("info.txt", "w");
    if (fptr != NULL)
    {
        fprintf(fptr, "Name: %s, Age: %d", name, age);
    }
    else
        printf("Error opening file");
    fclose(fptr);
    
    FILE *fqptr = fopen("info.txt", "r");char name2[20];
    int age2;
    fscanf(fqptr, "Name: %19[^,], Age: %d", name2, &age2);
    if (fqptr != NULL)
    {
        printf("Name: %s, Age: %d", name2, age2);
    }
    else
        printf("Error opening file");
    fclose(fqptr);
    return 0;
}