#include<stdio.h>
int main()
{
    //read from source.txt and write to destination.txt
    char data[10];
    int a,b;
    FILE *fptr = fopen("source.txt","r");
    fscanf(fptr,"%[^,],%d,%d",data,&a,&b);
    fclose(fptr);
    fptr = fopen("destination.txt","w");
    fprintf(fptr,"Data: %s, A: %d, B: %d",data,a,b);
    fclose(fptr);
    return 0;

}