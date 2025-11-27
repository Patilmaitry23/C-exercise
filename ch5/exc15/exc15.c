#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define NUMERIC 1
#define DECR    2
#define FOLD    4
#define LINES   100
#define MAXLEN  1000

int numcmp(char *, char *);
int charcmp(char *, char *);
int getline2(char *, int);

void qsort2(char *v[], int left, int right,
            int (*comp)(void *, void *));
void writelines(char *lineptr[], int nlines, int order);

static char option = 0;

int main(int argc, char *argv[])
{
    char line[LINES][MAXLEN];
    char *lineptr[LINES];
    int nlines = 0;
    int c, rc = 0;

    while (--argc > 0 && (*++argv)[0] == '-') {
        while ((c = *++argv[0]) != '\0') {
            switch (c) {
                case 'f':
                    option |= FOLD;
                    break;
                case 'n':
                    option |= NUMERIC;
                    break;
                case 'r':
                    option |= DECR;
                    break;
                default:
                    printf("sort: illegal option %c\n", c);
                    return 1;
            }
        }
    }

    while (nlines < LINES &&
           getline2(line[nlines], MAXLEN) > 0) {
        lineptr[nlines] = line[nlines];
        nlines++;
    }

    if (nlines == 0)
        return 0;

    if (option & NUMERIC)
        qsort2(lineptr, 0, nlines-1,
               (int (*)(void *, void *)) numcmp);
    else if (option & FOLD)
        qsort2(lineptr, 0, nlines-1,
               (int (*)(void *, void *)) charcmp);
    else
        qsort2(lineptr, 0, nlines-1,
               (int (*)(void *, void *)) strcmp);

    writelines(lineptr, nlines, option & DECR);
    return rc;
}

void writelines(char *lineptr[], int nlines, int decr)
{
    int i;
    if (decr)
        for (i = nlines-1; i >= 0; i--)
            printf("%s", lineptr[i]);
    else
        for (i = 0; i < nlines; i++)
            printf("%s", lineptr[i]);
}

int getline2(char s[], int lim)
{
    int c, i = 0;
    while (--lim > 0 &&
           (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int numcmp(char *s1, char *s2)
{
    double v1 = atof(s1);
    double v2 = atof(s2);
    if (v1 < v2) return -1;
    if (v1 > v2) return 1;
    return 0;
}

int charcmp(char *s, char *t)
{
    for (; tolower(*s) == tolower(*t); s++, t++)
        if (*s == '\0')
            return 0;
    return tolower(*s) - tolower(*t);
}

void qsort2(char *v[], int left, int right,
            int (*comp)(void *, void *))
{
    int i, last;
    void swap(char *v[], int, int);

    if (left >= right)
        return;

    swap(v, left, (left + right)/2);
    last = left;

    for (i = left+1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);

    swap(v, left, last);
    qsort2(v, left, last-1, comp);
    qsort2(v, last+1, right, comp);
}

void swap(char *v[], int i, int j)
{
    char *tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

