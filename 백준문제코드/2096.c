#include <stdio.h>
#include <stdlib.h>

int bigger(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

int smaller(int x, int y)
{
    if (x > y)
    {
        return y;
    }
    else
    {
        return x;
    }
}

int main()
{
    int N, i, j, num, min, max, max1, max2, max3, min1, min2, min3;
    int **maxDP, **minDP;

    scanf("%d", &N);

    maxDP = (int **)malloc(sizeof(int *) * 1);
    minDP = (int **)malloc(sizeof(int *) * 1);
    maxDP[0] = (int *)malloc(sizeof(int) * 3);
    minDP[0] = (int *)malloc(sizeof(int) * 3);

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &num);
            if (i == 0)
            {
                maxDP[0][j] = num;
                minDP[0][j] = num;
            }
            else if (j == 0)
            {
                max1 = num + bigger(maxDP[0][0], maxDP[0][1]);
                min1 = num + smaller(minDP[0][0], minDP[0][1]);
            }
            else if (j == 1)
            {
                max2 = num + bigger(bigger(maxDP[0][0], maxDP[0][1]), maxDP[0][2]);
                min2 = num + smaller(smaller(minDP[0][0], minDP[0][1]), minDP[0][2]);
            }
            else //(j==2)
            {
                max3 = num + bigger(maxDP[0][1], maxDP[0][2]);
                min3 = num + smaller(minDP[0][1], minDP[0][2]);
            }
        }
        if (i != 0)
        {
            maxDP[0][0] = max1;
            maxDP[0][1] = max2;
            maxDP[0][2] = max3;
            minDP[0][0] = min1;
            minDP[0][1] = min2;
            minDP[0][2] = min3;
        }
    }

    max = maxDP[0][0];
    min = minDP[0][0];
    for (j = 1; j < 3; j++)
    {
        if (max < maxDP[0][j])
        {
            max = maxDP[0][j];
        }
        if (min > minDP[0][j])
        {
            min = minDP[0][j];
        }
    }
    printf("%d %d", max, min);
}