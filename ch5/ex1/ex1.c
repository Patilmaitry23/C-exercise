#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getint(int *pn);

#define BUFSIZE 100

char buffer[BUFSIZE];
int bufp = 0;


int main()
{
    int num;

    printf("\nEnter an Integer:\n");

    if (getint(&num) != 0)
        printf("\nEntered Integer is : %d\n", num);
    else
        printf("\nInvalid integer input.\n");

    return 0;
}

/* get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch())); // no space

    /* not a digit or sign */
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        printf("\nInvalid Input Entered: %c\n", c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-') {

        int next = getch();

        if (!isdigit(next)) {
            ungetch(next);
            ungetch(c);
            printf("\nReceived Invalid Input after sign: %c\n", next);
            return 0;
        }

        c = next;
    }

    /* for digits */
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

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

