#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

// Function prototypes
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
        if (len > 1 || (len == 1 && line[0] != '\n')) {
            reverse(line);
            printf("%s", line);
        }
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

void reverse(char s[]) {
    int i, j;
    int len = 0;

    // Find the length of the string
    while (s[len] != '\0') {
        len++;
    }

    // If the last character is a newline, exclude it from the reversal group
    if (len > 0 && s[len - 1] == '\n') {
        len--;
    }

    // Swap characters from the ends inward
    // i starts at the beginning, j starts at the character before the null terminator (or newline)
    for (i = 0, j = len - 1; i < j; i++, j--) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

