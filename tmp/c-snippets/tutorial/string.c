#include <string.h>

int main()
{
    // STRING ARRAY
    char s1[] = "hello";
    char s2[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char s3[10] = "hello";
    char s4[10] =  {'h', 'e', 'l', 'l', 'o', '\0'};
    
    /** NOTE: sizeof() includes \0
    * s1 and s2 => 6
    * s3 and s4 => 10
    */
    // strlen => 5
     

    return 0;
}
