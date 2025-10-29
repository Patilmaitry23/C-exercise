#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getlen(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main()
{
    int len; // current line length
    int max; // maximum length seen so far
    char line[MAXLINE]; // current input line
    char longest[MAXLINE]; // longest line saved here

    max = 0;
    while ((len = getlen(line, MAXLINE)) > 0) {
        // Check if the current line is the longest one seen so far
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    // If input was provided, print the longest line
    if (max > 0) {
        printf("The longest line found (length %d) is:\n", max);
        printf("%s", longest);
    } else {
        printf("No input\n");
    }

    return 0;
}

/* get_line_length: read a line into s, return its length */
int getlen(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    // Terminate the string with the null character
    s[i] = '\0';
    return i;
}

/* copy_string: copy 'from' into 'to'; assumes 'to' is large enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    // Copy character by character until the null terminator is reached
    while ((to[i] = from[i]) != '\0')
        ++i;
}

