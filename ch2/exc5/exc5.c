#include <stdio.h>

int any(char s1[], char s2[])
{
    int i, j;

    for (i = 0; s1[i] != '\0'; i++)
    {
        for (j = 0; s2[j] != '\0'; j++) //if s1 characters appear in s2
        {
            if (s1[i] == s2[j])
                return i;
        }

        }
    return -1;
}

int main()
{
    char s1[] = "hello";
    char s2[] = "world"; // remove all vowels
    int temp;
    temp = any(s1, s2);
    if (temp == -1)
        printf("Not same\n");
    else
        printf("It is same at %d\n", temp);

    return 0;
}

