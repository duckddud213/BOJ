#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int num, i, j;
    int *arr;

    arr = (int *)malloc(sizeof(int) * 1000001);

    for (i = 2; i <= 1000000; i++)
    {
        arr[i] = i;
    }

    for (i = 2; i <= 1000000; i++)
    {
        if (arr[i] != -1)
        {
            for (j = 2; i * j <= 1000000; j++)
            {
                arr[i * j] = -1;
            }
        }
    }

    scanf("%d", &num);

    while (num != 0)
    {
        for (i = 2; i <= (num / 2); i++)
        {
            if ((arr[i] != -1) && (arr[num - i] != -1))
            {
                printf("%d = %d + %d\n", num, i, num - i);
                break;
            }
        }
        if (i > num / 2)
            printf("Goldbach's conjecture is wrong.\n");

        scanf("%d", &num);
    }
}