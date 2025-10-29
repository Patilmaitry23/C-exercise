#include <stdio.h>



#define MAXLINE 1000  // maximum input line length



int getlen(char line[], int maxline);



int main() {

    int len;                 // current line length

    char line[MAXLINE];      // current input line



    while ((len = getlen(line, MAXLINE)) > 0) {

        if (len > 5) {       // print only lines longer than 5 characters

            printf("%s", line);

        }

    }



    return 0;

}



/* getlen: read a line into s, return its length */

int getlen(char s[], int lim) {

    int c, i;



    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)

        s[i] = c;



    if (c == '\n') {

        s[i] = c;

        ++i;

    }



    s[i] = '\0';  // terminate string

    return i;

}


