#include <stdio.h>

void escape(char s[], const char a[]);

int main()
{
    char a[] = "Hello\tworld\nNew line";
    char escape1[20];

    escape(escape1, a);
    printf("Actual:%s\n",a);
    printf("after escape function:   %s\n", escape1);

    return 0;
}

void escape(char s[], const char a[])  //convert tabs and newlines to visible '\t' and '\n'
{
    int i, j;
    for (i = 0, j = 0; a[i] != '\0'; i++) {
        switch (a[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = a[i];
                break;
        }
    }
}



