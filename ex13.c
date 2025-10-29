#include <stdio.h>

int main()
{
    int c, length=0, ccount=0; //input character, length of the current word typed, total count of words in input
    int wlen[10]; // length of each word go upto 10
    int tcount  = 3; //i want total 3 words as input only
    int i,j;

    for (i = 0; i < 10; ++i) {
        wlen[i] = 0;
    } //all as 0

    while ((c = getchar()) != EOF)
    {
        if(c==' ' || c=='\t' || c=='\n') //checking if the character entered begins a new word or not
        {
            if(length > 0 && ccount < tcount)
            {
                wlen[ccount]=length; //storing in current word length
                ccount++;//incrementing the word count
                length = 0;//resent length for next word

                if(ccount >=tcount)
                    break;
            }
        } //if it is not word seperator increment word length
        else
            length++;
    }


    printf("\nWord lengths:\n");
    for (i = 0; i < ccount; i++) {
        printf("Word %d: %d\n", i + 1, wlen[i]);
    }

    //for histogram
    printf("Horizontal Histogram\n");
    for (i = 0; i < ccount; i++) {
        printf("Word %d (%d) : ", i + 1, wlen[i]); // aboout the word written

        for (j = 0; j < wlen[i]; j++) {  //histo lines
            printf("-");
        }

        printf("\n");
    }

    return 0;

}

