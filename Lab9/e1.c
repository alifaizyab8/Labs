#include <stdio.h>
int main()
{
    FILE *fptr;
    fptr = fopen("e1_text.txt", "w");
    if (fptr != NULL)
    {
        fprintf(fptr, "Name: Sara, Age: 21, GPA: 3.75\n");
    }
    else
        printf("Error opening file");
    fclose(fptr);
    return 0;
}