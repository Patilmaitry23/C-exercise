#include <stdio.h>

/* itob: convert integer n into a base b string in s */
void itob(int n, char s[], int b) {
    int i = 0, sign,remainder;
    unsigned int num;

    if ((sign = n) < 0)
        num = -n;  // use unsigned to handle negative properly
    else
        num = n;

    do {
        remainder = num % b;
        if (remainder < 10)
            s[i++] = remainder + '0';
        else
            s[i++] = remainder - 10 + 'A';  // use A-F for hex digits
    } while ((num /= b) > 0); 

    if (sign < 0)
        s[i++] = '-';

}

int main() {
    int n, base;
    char s[10];

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Enter base (2 for binary, 8 for octal, 16 for hex): ");
    scanf("%d", &base);

    itob(n, s, base);
    printf("Base-%d representation: %s\n", base, s);

    return 0;
}

