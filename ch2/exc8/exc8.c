#include <stdio.h>

unsigned int rightrot(unsigned int x, int n)
{
    int i;

    for ( i = 0; i < n; i++) {
        unsigned int lbit = x & 1;   // get rightmost bit here 0
        x = x >> 1;                 // shift right by 1
        if (lbit)                    // if last bit was 1
            x = x | (1 << 7);       // set leftmost bit 1 if 0 as it is
    }
    return x;
}

int main()
{
    unsigned int x = 0b11110000;
    int n = 2,i; //rotate right by 2 bits

    unsigned int result = rightrot(x, n);

    printf("original : ");
    for ( i = 7; i >= 0; i--)
        printf("%d", (x >> i) & 1);

    printf("\nrotated  : ");
    for ( i = 7; i >= 0; i--)
        printf("%d", (result >> i) & 1);

    return 0;
}

