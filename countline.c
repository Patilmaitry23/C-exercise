#include <stdio.h>
int main()
{
int c,i;
i=0;
while((c=getchar())!=EOF)
{
if(c=='\n')
++i;
}
printf("%d\n",i);
return 0;
}
