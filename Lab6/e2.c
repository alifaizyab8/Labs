#include <stdio.h>
#include <stdlib.h>
int main()
{

    // Compiler automatically determines size (implicitly sized)
    // Or explicitly sized (size must be >= string length + 1 for null terminator)
    // char str[32] = "Today's temperature is 24 degrees";
    
    
    // First use case
    char str[] = "Today's temperature is 24 degrees";
    int amount = atoi(&str[23]);
    printf("%d\n", amount);
    
    
    // Second use case
    char str2[] = "24 degrees";
    int amount2 = atoi(str2);
    printf("%d\n", amount);
}