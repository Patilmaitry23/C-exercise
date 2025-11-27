#include <stdio.h>

int atoi_ptr(char *s)
{
    int sign = 1, n = 0;

    while (*s == ' ' || *s == '\t')
        s++;

    if (*s == '-' || *s == '+')
        sign = (*s++ == '-') ? -1 : 1;

    while (*s >= '0' && *s <= '9')
        n = 10 * n + (*s++ - '0');

    return sign * n;
}

int main(void)
{
    char str[50];

    printf("Enter a number: ");
    gets(str);
    int value = atoi_ptr(str);

    printf("Converted integer: %d\n", value);

    return 0;
}

