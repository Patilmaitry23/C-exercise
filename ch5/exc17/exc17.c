#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define NUMERIC 1
#define DECR    2
#define FOLD    4
#define DIR     8
#define LINES   100
#define MAXLEN  1000
#define MAXSTR  100

int numcmp(char *, char *);
int charcmp(char *, char *);
int getline2(char *, int);
void qsort2(char *v[], int left, int right, int (*comp)(void *, void *));
void writelines(char *lineptr[], int nlines, int order);
void substr(char *s, char *str);
void error(char *msg);

static char option = 0;
static int pos1 = 0; // starting position of sort key
static int pos2 = 0; // ending position (exclusive) of sort key

int main(int argc, char *argv[])
{
    char line[LINES][MAXLEN];
    char *lineptr[LINES];
    int nlines = 0;
    int c;

    while (--argc > 0 && (*++argv)[0] == '-') {
        if (isdigit((*argv)[1])) {  // -pos2
            pos2 = atoi((*argv)+1);
            continue;
        }
        while ((c = *++argv[0]) != '\0') {
            switch (c) {
                case 'd': option |= DIR; break;
                case 'f': option |= FOLD; break;
                case 'n': option |= NUMERIC; break;
                case 'r': option |= DECR; break;
                default:
                    printf("sort: illegal option %c\n", c);
                    error("Usage: sort -dfnr [-pos1] [-pos2]");
            }
        }
    }

    if (pos1 > 0 && pos2 == 0)
        error("Specify pos2 when using pos1");

    while (nlines < LINES && getline2(line[nlines], MAXLEN) > 0) {
        lineptr[nlines] = line[nlines];
        nlines++;
    }

    if (nlines == 0)
        return 0;

    if (option & NUMERIC)
        qsort2(lineptr, 0, nlines-1,
               (int (*)(void *, void *)) numcmp);
    else
        qsort2(lineptr, 0, nlines-1,
               (int (*)(void *, void *)) charcmp);

    writelines(lineptr, nlines, option & DECR);
    return 0;
}

void writelines(char *lineptr[], int nlines, int decr)
{
    int i;
    if (decr)
        for (i = nlines-1; i >= 0; i--)
            printf("%s", lineptr[i]);
    else
        for (i = 0; i < nlines; i++)
            printf("%s", lineptr[i]);
}

int getline2(char s[], int lim)
{
    int c, i = 0;
    while (--lim > 0 && (c=getchar())!=EOF && c!='\n')
        s[i++] = c;
    if (c=='\n') s[i++] = c;
    s[i]='\0';
    return i;
}

int numcmp(char *s1, char *s2)
{
    char sub1[MAXSTR], sub2[MAXSTR];
    substr(s1, sub1);
    substr(s2, sub2);
    double v1 = atof(sub1);
    double v2 = atof(sub2);
    if (v1<v2) return -1;
    if (v1>v2) return 1;
    return 0;
}

int charcmp(char *s, char *t)
{
    char a,b;
    int fold = (option & FOLD) ? 1 : 0;
    int dir  = (option & DIR) ? 1 : 0;
    int i = pos1 ? pos1-1 : 0;
    int end = pos2 ? pos2-1 : strlen(s);

    do {
        if (dir) {
            while (i<end && !isalnum(s[i]) && s[i]!=' ') i++;
            int j = i;
            while (j<end && !isalnum(t[j]) && t[j]!=' ') j++;
            if (i>=end || j>=end) break;
            a = fold ? tolower(s[i]) : s[i];
            b = fold ? tolower(t[j]) : t[j];
            if (a!=b) return a-b;
            i++; j++;
        } else {
            if (i>=end) break;
            a = fold ? tolower(s[i]) : s[i];
            b = fold ? tolower(t[i]) : t[i];
            if (a!=b) return a-b;
            i++;
        }
    } while (i<end);

    return 0;
}

void substr(char *s, char *str)
{
    int i, j;
    int len = strlen(s);
    if (pos2>0 && len>pos2-1) len = pos2-1;
    j=0;
    for(i=pos1?pos1-1:0; i<len; i++, j++)
        str[j] = s[i];
    str[j]='\0';
}

void qsort2(char *v[], int left, int right,
            int (*comp)(void *, void *))
{
    int i, last;
    void swap(char *v[], int, int);
    if (left>=right) return;
    swap(v,left,(left+right)/2);
    last=left;
    for(i=left+1;i<=right;i++)
        if((*comp)(v[i],v[left])<0)
            swap(v,++last,i);
    swap(v,left,last);
    qsort2(v,left,last-1,comp);
    qsort2(v,last+1,right,comp);
}

void swap(char *v[], int i,int j)
{
    char *tmp = v[i];
    v[i]=v[j];
    v[j]=tmp;
}

void error(char *msg)
{
    printf("%s\n",msg);
    exit(1);
}

