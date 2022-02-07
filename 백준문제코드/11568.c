#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, j, max;
    int *card;
    int *LIS;

    scanf("%d", &N);

    card = (int *)malloc(sizeof(int) * (N + 1));
    LIS = (int *)malloc(sizeof(int) * (N + 1));

    for (i = 1; i <= N; i++)
    {
        scanf("%d", card + i);
    }

    LIS[1] = 1;
    max = 1;

    for (i = 2; i <= N; i++)
    {
        LIS[i] = 1;
        for (j = 1; j < i; j++)
        {
            if ((card[j] < card[i]) && (LIS[i] < LIS[j] + 1))
            {
                LIS[i] = LIS[j] + 1;
            }
        }
        if (max < LIS[i])
        {
            max = LIS[i];
        }
    }

    printf("%d", max);
}