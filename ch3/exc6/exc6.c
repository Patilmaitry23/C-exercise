#include <stdio.h>

/* itoa: convert n to characters in s, with minimum width w */
void itoa(int n, char s[], int w) {
    int i, sign;
    if ((sign = n) < 0) /* record sign */
        n = -n; /* make n positive */
    i = 0;
    do   /* generate digits in reverse order */
    {
        s[i++] = n % 10 + '0'; /* get next digit */
    }
    while ((n /= 10) > 0);   /* delete it */
    if (sign < 0)
        s[i++] = '-';

    /* padding blanks(here '*') if width < w */
    while (i < w)
        s[i++] = '*'; //typing * to make space more visible

    s[i] = '\0';
}

int main() {
    int num, width;
    char str[10];

    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter minimum field width: ");
    scanf("%d", &width);

    itoa(num, str, width);
    printf("Output: '%s'\n", str);


    return 0;
}

