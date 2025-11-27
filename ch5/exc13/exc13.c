#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFLINES 10     /* default number of lines to print */
#define LINES    100    /* max number of lines to store */
#define MAXLEN   100    /* max length of each input line */

void error(char *);
int getline1(char *, int);

int main(int argc, char *argv[])
{
    char *buf, *bufend;
    char line[MAXLEN];
    char *lineptr[LINES];
    char *p;
    int first, last, n, nlines, len;
    int i;

    /* parse optional "-n" argument */
    if (argc == 1)
        n = DEFLINES;
    else if (argc == 2 && argv[1][0] == '-')
        n = atoi(argv[1] + 1);
    else
        error("usage: tail [-n]");

    if (n < 1 || n > LINES)
        n = LINES;

    for (i = 0; i < LINES; i++)
        lineptr[i] = NULL;

    buf = malloc(LINES * MAXLEN);
    if (buf == NULL)
        error("tail: cannot allocate buffer");

    bufend = buf + LINES * MAXLEN;

    p = buf;
    last = 0;
    nlines = 0;

    /* read lines into circular buffer */
    while ((len = getline1(line, MAXLEN)) > 0) {

        if (p + len + 1 >= bufend)
            p = buf;               /* wrap buffer */

        lineptr[last] = p;
        strcpy(p, line);

        if (++last >= LINES)
            last = 0;

        p += len + 1;

        if (nlines < LINES)
            nlines++;
    }

    if (n > nlines)
        n = nlines;

    first = last - n;
    if (first < 0)
        first += LINES;

    /* print the last n lines */
    for (i = first; n-- > 0; i = (i + 1) % LINES)
        printf("%s", lineptr[i]);

    return 0;
}

/* read a line */
int getline1(char *s, int lim)
{
    int c;
    char *start = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;

    if (c == '\n')
        *s++ = c;

    *s = '\0';
    return s - start;
}

void error(char *s)
{
    printf("%s\n", s);
    exit(1);
}

