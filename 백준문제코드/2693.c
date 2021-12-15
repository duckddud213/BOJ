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
    int x, T, i;
    int *arr;

    arr = (int *)malloc(sizeof(int) * 10);

    scanf("%d", &T);

    for (x = 0; x < T; x++)
    {
        for (i = 0; i < 10; i++)
        {
            scanf("%d", arr + i);
        }
        qsort(arr, 10, sizeof(int), compare);
        printf("%d\n", arr[7]);
    }
}