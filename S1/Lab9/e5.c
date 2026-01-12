// a program which reads a file and detects the number of lines and prefixes each line with its line number
#include <stdio.h>
int main()
{
    int lineCount = 1;
    char ch;
    FILE *fptr = fopen("e5.txt","r");
    if (fptr != NULL)
    {
    
    
    printf("%d: ",lineCount);
    while ((ch=fgetc(fptr)) != EOF)
    {
        printf("%c",ch);
        if (ch == '\n')
        {
            lineCount++;
            printf("%d: ",lineCount);
        }
        
    }
    }
    else perror("File error\n");
    printf("\n");
    fclose(fptr);
    return 0;

}