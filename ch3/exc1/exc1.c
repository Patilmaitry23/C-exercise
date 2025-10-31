#include <stdio.h>

int binsearch(int x, int v[], int n)
{
    int low = 0, high = n - 1;
    int mid;

    while (low < high) {
        mid = (low + high) / 2;

        if (x <= v[mid])
            high = mid;     //mid is the last in the array index
        else
            low = mid + 1;
    }

    if (v[low] == x)
        return low;
    else
        return -1;
}

int main()
{
    int v[] = {1,2,3,4,5,6,7};
    int n = 7;
    int x = 3;

    int result = binsearch(x, v, n);
    if (result == -1)
        printf("%d not found\n", x);

    else
        printf("found %d at index %d\n", x, result);

    return 0;
}

