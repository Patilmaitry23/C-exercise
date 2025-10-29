#include <stdio.h>

#define TABSTOP 8   // tab stops every 8 columns

int main() {
    int c, col = 0;  // inpput char, current column
    int spaces,i;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            // number of spaces to next tab stop
             spaces = TABSTOP - (col % TABSTOP);
            for ( i = 0; i < spaces; i++) {
                putchar('-');
                col++;
            }
        } else if (c == '\n') {
            putchar(c);
            col = 0; // reset column position
        } else {
            putchar(c);
            col++;
        }
    }

    return 0;
}

