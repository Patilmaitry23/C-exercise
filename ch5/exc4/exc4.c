#include <stdio.h>

/*return 1 if t occurs at end of s, 0 otherwise */
int strend(char *s, char *t)
{
    char *ss = s;
    char *ts = t;

    while (*s)
        s++;
    while (*t)
        t++;

    while (ts < t && ss < s && *--t == *--s)
        ;

    return (t == ts) ? 1 : 0;
}

int main(void)
{
    char s[] = "hello world";
    char t1[] = "world";
    char t2[] = "hello";

    printf("%d\n", strend(s, t1)); // 1
    printf("%d\n", strend(s, t2)); // 0

    return 0;
}

