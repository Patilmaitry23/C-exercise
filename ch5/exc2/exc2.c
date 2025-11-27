#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getfloat(float *pn);

#define BUFSIZE 100

char buffer[BUFSIZE];
int bufp = 0;


int main()
{
    float num;

    printf("\nEnter an Integer:\n");

    if (getfloat(&num) != 0)
        printf("\nEntered Integer is : %g\n", num);
    else
        printf("\nInvalid integer input.\n");

    return 0;
}

/* get next float from input into *pn */
int getfloat(float *pn)
{
    int c, sign;
    float power;

    while (isspace(c = getch()))      /* skip white space */
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);                   /* not a float */
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-') {
        int d = getch();

        /* sign not followed by digit or '.' */
        if (!isdigit(d) && d != '.') {
            ungetch(d);
            ungetch(c);
            return 0;
        }

        c = d;
    }

    /* read integer part */
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    /* read fractional part */
    if (c == '.') {
        c = getch();
        for (power = 1.0; isdigit(c); c = getch()) {
            *pn = 10 * *pn + (c - '0');
            power *= 10;
        }
        *pn = *pn / power;
    }

    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

int getch(void)
{
    return (bufp > 0) ? buffer[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: buffer full\n");
    else
        buffer[bufp++] = c;
}

