#include <stdio.h>

/*read a line into s, return length*/
int getline1(char *s, int lim)
{
    int c;
    char *p = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *p++ = c;

    if (c == '\n')
        *p++ = c;

    *p = '\0';

    return p - s;
}

int main(void)
{
    char line[20];
    int len;

    while ((len = getline1(line, 20)) > 0) {
        printf("%d chars: %s", len, line);
    }

    return 0;
}

