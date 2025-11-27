#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100     /* maximum line size */
#define TABINC 8        /* default tab increment */
#define YES 1
#define NO  0

void settab(int argc, char *argv[], char *tab);
int  tabpos(int pos, char *tab);

void entab(char *tab);
void detab(char *tab);

int main(int argc, char *argv[])
{
    char tab[MAXLINE + 1];

    settab(argc, argv, tab);


    if (strstr(argv[0], "entab"))
        entab(tab);
    else
        detab(tab);

    return 0;
}

void settab(int argc, char *argv[], char *tab)
{
    int i, pos;

    if (argc <= 1) {
        for (i = 1; i <= MAXLINE; i++)
            tab[i] = (i % TABINC == 0) ? YES : NO;
        return;
    }

    for (i = 1; i <= MAXLINE; i++)
        tab[i] = NO;

    while (--argc > 0) {
        pos = atoi(*++argv);
        if (pos > 0 && pos <= MAXLINE)
            tab[pos] = YES;
    }
}

int tabpos(int pos, char *tab)
{
    if (pos > MAXLINE)
        return YES;
    return tab[pos];
}

void entab(char *tab)
{
    int c, pos = 1;
    int nb = 0;
    int nt = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (tabpos(pos, tab) == NO)
                nb++;
            else {
                nb = 0;
                nt++;
            }
            pos++;
        }

        else {
            while (nt-- > 0)
                putchar('\t');

            while (nb-- > 0)
                putchar(' ');

            if (c == '\t')
                pos++;
            else if (c == '\n')
                pos = 1;
            else
                pos++;

            putchar(c);

            nt = nb = 0;
        }
    }
}

void detab(char *tab)
{
    int c, pos = 1;

    while ((c = getchar()) != EOF) {

        if (c == '\t') {
            do {
                putchar(' ');
                pos++;
            } while (!tabpos(pos, tab));
        }

        else {
            putchar(c);
            if (c == '\n')
                pos = 1;
            else
                pos++;
        }
    }
}

