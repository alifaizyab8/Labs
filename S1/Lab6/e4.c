#include <stdio.h>
#include <string.h>
int main(void)
{

    char str1[] = "hell";
    char str2[] = "HELLO";
    char str3[] = "World! ";
    printf("%d\n", strcmpi(str1, str2));
    printf("%d\n", strcmpi(str3, str2));
    printf("%d", strcmpi(str2, str2));
    /**
     * strcmpi (string compare ignore case) - Compares two strings lexicographically,
     * ignoring the case of characters
     *
     * Behavior:
     * - Compares strings character by character without case sensitivity
     * - Returns 0 if strings are equal (ignoring case)
     * - Returns negative value if str1 is less than str2 (ignoring case)
     * - Returns positive value if str1 is greater than str2 (ignoring case)
     * - Comparison continues until:
     *   * A difference is found
     *   * End of either string is reached ('\0')
     *
     * Note: strcmpi is a non-standard function, _stricmp is the standard alternative
     * in Microsoft Visual C++
     */
    // strcmpi example
}
