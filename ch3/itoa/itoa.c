#include <stdio.h>
/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
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
    s[i] = '\0';
}

int main()
{
    int num;
    char str[10];

    printf("Enter an integer: ");
    scanf("%d", &num);

    itoa(num, str);
    printf("String representation: %s\n", str);

    return 0;
}

