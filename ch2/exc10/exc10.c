#include <stdio.h>

char lower(char ch)
{
    char temp;

    temp = (ch >= 'A' && ch <= 'Z') ? (ch + 'a' - 'A') : ch;

    return temp;
}

int main()
{
    char ch;

    printf("Enter a character(in capital): ");
    scanf("%c", &ch);

    printf("Lowercase: %c\n", lower(ch));

    return 0;
}

