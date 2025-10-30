#include <stdio.h>

void squeeze(char s1[], char s2[]) {
    int i, j=0, k;
    int same=0;

    for (i = 0; s1[i] != '\0'; i++)
    {
        for (k = 0; s2[k] != '\0'; k++) //if s1 characters appear in s2
        {
            if (s1[i] == s2[k])
            {
                same = 1; //change same =1 if same
                break;
            }
        }

        if (!same)
            s1[j++] = s1[i]; //if not same it keeps the alphabet as it is
    }
    s1[j] = '\0'; // terminate result
}

int main() {
    char s1[] = "hello";
    char s2[] = "world"; // remove all vowels

    squeeze(s1, s2);
    printf("Result: %s\n", s1);

    return 0;
}

