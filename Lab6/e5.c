#include <stdio.h>
#include <string.h>
#define MAX_LEN 30 
#define MAX_NAMES 5

void sort_names(char names[][MAX_LEN], int count)
{
    char temp[MAX_LEN];
    for (int i = 0; i < count-1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
             if (strlen(names[i]) > strlen(names[j]))
            {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }}}}

int main()
{
    char names[MAX_NAMES][MAX_LEN];
    printf("Enter %d names:\n", MAX_NAMES);
    printf("(Each name should be at most %d characters long)\n", MAX_LEN - 1);
    for (int i = 0; i < MAX_NAMES; i++)
    {
        printf("Name %d: ", i + 1);
        fgets(names[i], MAX_LEN, stdin);
    }
    sort_names(names, MAX_NAMES);
    printf("\nSorted names by length:\n");
    for (int i = 0; i < MAX_NAMES; i++)
    {
        printf("%s", names[i]);
    }
}