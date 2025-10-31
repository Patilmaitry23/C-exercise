#include <stdio.h>
void shellsort(int v[], int n)
{
    int gap, i, j, temp;
    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap)
            {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}

int main()
{
    int  n,i;
    n=10;
    int v[10]={10,9,5,3,4,8,7,6,1,2};
    shellsort(v,n);
    printf("Sorted :\n");
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

