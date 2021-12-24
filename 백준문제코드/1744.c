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
    int N, i, sum, tmp;
    int *arr;

    scanf("%d", &N);

    arr = (int *)malloc(sizeof(int) * N);

    for (i = 0; i < N; i++)
    {
        scanf("%d", arr + i);
    }
    qsort(arr, N, sizeof(int), compare);
    if (N == 1)
    {
        printf("%d", arr[0]);
        return 0;
    }

    sum = 0;
    for (i = 0; arr[i] <= 0;)
    {
        if (arr[i + 1] <= 0)
        {
            sum += (arr[i] * arr[i + 1]);
            i += 2;
        }
        else
        {
            sum += arr[i];
            i++;
        }
    }
    tmp = i;

    for (i = N - 1; i >= tmp;)
    {
        if (i == tmp)
        {
            sum += arr[i];
            i--;
        }
        else
        {
            if (arr[i] == 1)
            {
                sum += arr[i];
                i--;
            }
            else if (arr[i - 1] == 1)
            {
                sum += arr[i];
                i--;
            }
            else
            {
                sum += (arr[i] * arr[i - 1]);
                i -= 2;
            }
        }
    }

    printf("%d", sum);
}