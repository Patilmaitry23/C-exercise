#include <stdio.h>

char *strncpy(char *s, char *t, int n)
{
    char *p = s;
    while ((n--) > 0 && (*p++ = *t++))
        ;
    while ((n--) > 0)
        *p++ = '\0';
    return s;
}

char *strncat(char *s, char *t, int n)
{
    char *p = s;
    while (*p)
        p++;
    while ((n--) > 0 && (*p++ = *t++))
        ;
    *p = '\0';
    return s;
}

int main(void)
{
    char a[20], b[20] = "Hello", c[20] = "World";

    strncpy(a, b, 3);
    printf("strncpy(a,b,3): %s\n", a);

    strncat(b, c, 2);
    printf("strncat(b,c,2): %s\n", b);

    return 0;
}

