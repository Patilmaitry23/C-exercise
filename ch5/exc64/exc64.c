#include <stdio.h>

void reverse_ptr(char *s)
{
    char *p = s;
    char *q = s;
    char temp;

    while (*q)
        q++;
    q--;

    while (p < q) {
        temp = *p;
        *p++ = *q;
        *q-- = temp;
    }
}

int main(void)
{
    char str[20];

    printf("Enter a string: ");
    gets(str);

    reverse_ptr(str);

    printf("Reversed: %s\n", str);

    return 0;
}

