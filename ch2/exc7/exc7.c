#include <stdio.h>

unsigned int invert(unsigned int x, int p, int n)
{
    unsigned int mask = ((1U << n) - 1) << (p + 1 - n); //mask n bits to 1 using shift position

    return x ^ mask; //using xor to mask
}

int main()
{
    unsigned int x = 0b10101010;
    int p = 3;
    int n = 4,i;

    unsigned int result = invert(x, p, n);

    printf("original: ");
    for ( i = 7; i >= 0; i--) printf("%d", (x >> i) & 1);

    printf("\ninverted: ");
    for ( i = 7; i >= 0; i--) printf("%d", (result >> i) & 1);

    return 0;
}

