#include <stdio.h>
#include <stdlib.h>

int compare(const void *x, const void *y)
{
    long long a = *(long long *)x;
    long long b = *(long long *)y;

    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    else
        return 0;
}

int main()
{
    int N, K, i;
    long long *arr;

    scanf("%d %d", &N, &K);

    arr = (long long *)malloc(sizeof(long long) * N);
    for (i = 0; i < N; i++)
    {
        scanf("%lld", arr + i);
    }

    qsort(arr, N, sizeof(long long), compare);

    printf("%lld", arr[K - 1]);
}