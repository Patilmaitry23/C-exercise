#include <stdio.h>

#define TABSTOP 8   // tab stops every 8 columns

int main() {
    int c, col = 0;       // input char, current column
    int space_count = 0;  // count consecutive spaces

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            // accumulate spaces
            space_count++;
            col++;

            // if we reach a tab stop, insert a tab instead of all those spaces
            if (col % TABSTOP == 0) {
                putchar('-');//put - for tab
                space_count = 0;  // reset space count
            }
        } else {
            // output any pending spaces before printing the next character
            while (space_count > 0) {
                putchar('+'); //put + for space
                space_count--;
            }

            putchar(c);

            if (c == '\n')
                col = 0;   // reset column count at newline
            else
                col++;
        }
    }

    return 0;
}

