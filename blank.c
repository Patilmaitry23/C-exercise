#include <stdio.h>

int main() {
    int c;
    int i = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (!i) {
                putchar(c);
                i = 1;
            }
        } else {
            putchar(c);
            i = 0;
        }
    }

    return 0;
}
