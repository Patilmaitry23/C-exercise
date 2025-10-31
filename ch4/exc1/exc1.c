#include <stdio.h>

/* strindex: return position of rightmost occurrence of t in s, or -1 if none */
int strindex(char s[], char t[]) {
    int i, j, k;
    int temp = -1;
    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);

        if (t[k] == '\0')
            temp = i;
    }

    return temp;
}

int main() {
    char s[20], t[20];
    int index;
    printf("Enter main string: ");
    gets(s);

    printf("Enter string to find: ");
    gets(t);

    index = strindex(s, t);
    if (index == -1)
        printf("Substring not found.\n");
    else
        printf("Rightmost occurrence of %s starts at position %d\n", t, index);

    return 0;
}

