// count number of characters, words and lines in a file
#include <stdio.h>
int main()
{
    int characters,words,lines;
    characters = words = lines = 0;
    FILE *ptr = fopen("detect.txt", "r");
    if (ptr != NULL)
    {
        char ch;
        while ((ch = fgetc(ptr)) != EOF)
        {
            if ((ch >= 'A' && ch <= 'Z') || ((ch >= 'a' && ch <= 'z')))
            {
                characters++;
            }
            else if (ch == ' ')
            {
                words++;
            }
            else if (ch == '\n')
            {
                lines++;
            }
        }
    }
    else
    {
        perror("Error reading \n");
        return 1;
    }

    printf("Number of characters: %d\n", characters);
    printf("Number of words: %d\n", words + 1); // Adding 1 to count the last word
    printf("Number of lines: %d\n", lines + 1);   // Adding 1 to count the last line
    fclose(ptr);
    return 0;

}