#include<stdio.h>
#include<ctype.h>

int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))      /* no white space */
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);                   /* no number */
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-') {
        int d = getch();
        if (!isdigit(d)) {
            ungetch(d);
            ungetch(c);
            return 0;
        }

        c = d;
    }

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

int main(void)
{
    int x;

    printf("Enter number: ");

    if (getint(&x) != 0)
        printf("You entered: %d\n", x);
    else
        printf("Invalid number.\n");

    return 0;
}

