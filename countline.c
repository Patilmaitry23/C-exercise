#include <stdio.h>
int main()
{
int  i;
for(i=0;getchar() != EOF; ++i);
printf("%d\n",i);
return 0;
}
