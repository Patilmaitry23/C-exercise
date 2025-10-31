#include <stdio.h>
/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
    static int i = 0; // keep index between recursive calls
    int sign;

    if (i == 0 && n < 0)    // handle negative at first call
    {
        sign = n;
        s[i++] = '-';
        n = -n;
    }

    if (n / 10)
        itoa(n / 10, s);    // recursive call for higher digits

    s[i++] = n % 10 + '0';
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

