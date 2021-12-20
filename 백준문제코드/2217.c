#include <stdio.h>
#include <stdlib.h>

int compare(const void *x, const void *y)
{
    int a = *(int *)x;
    int b = *(int *)y;

    if (a > b)
    {
        return 1;
    }
    else if (a < b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n, i, max, sum;
    int *arr;

    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }

    qsort(arr, n, sizeof(int), compare);
    max = 0;

    for (i = 0; i < n; i++)
    {
        sum = arr[i] * (n - i);
        if (max < sum)
        {
            max = sum;
        }
    }
    printf("%d", max);
}