#include <stdio.h>

void reverse(char *s)
{
    char *p = s;
    char *q = s;
    char temp;

    while (*q)
        q++;
    q--;

    while (p < q) {
        temp = *p;
        *p++ = *q;
        *q-- = temp;
    }
}

/*convert n to characters in s*/
void itoa_ptr(int n, char *s)
{
    char *p = s;
    int sign = n;

    if (n < 0)
        n = -n;

    do {
        *p++ = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
        *p++ = '-';

    *p = '\0';

    reverse(s);
}

int main()
{
    int num;
    char str[10];

    printf("Enter an integer: ");
    scanf("%d", &num);

    itoa_ptr(num, str);
    printf("String representation: %s\n", str);

    return 0;
}

