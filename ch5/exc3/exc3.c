#include <stdio.h>

void strcat(char *s, char *t)
{
    /* move s to end of string */
    while (*s)
        s++;

    /* copy t*/
    while (*s++ = *t++)
        ;
}

int main(void)
{
    char s[20] = "Hello";
    char t[20] = " World";

    strcat(s, t);

    printf("%s\n", s);
    return 0;
}

