#include <stdio.h>
#include <ctype.h>
#include <math.h>

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign,sign2, exp;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
        sign2 = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (exp = 0; isdigit(s[i]); i++)
            exp = 10 * exp + (s[i] - '0');
        val *= pow(10, sign2 * exp);
    }

    return val;
}

int main()
{
    char a[10];
    double n;
    printf("Enter a number(type with e or E): ");
    scanf("%s", a);

    n = atof(a);
    printf("Converted to double value = %f\n", n);

    return 0;
}

