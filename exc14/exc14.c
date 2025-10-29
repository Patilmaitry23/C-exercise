#include <stdio.h>

int main() {
    int c; //input character,
    int i,j;
    int count[26];//from a-z

    for (i = 0; i < 26; ++i) {
        count[i] = 0;
    } //all as 0

    printf("Enter text(from a-z(all small): \n");
    while ((c = getchar()) != EOF)
    {
        if (c >= 'a' && c <= 'z')
        {
            count[c - 'a']++;
        }
    }
    //histogram
    printf("Horizontal histogram:\n");
    for (i = 0; i < 26; i++)
    {
        printf("Character '%c' (%2d): ", (char)('a' + i), count[i]);
        for (j = 0; j < count[i]; j++) {
            printf("-");
        }
        printf("\n");
    }
    return 0;

}

