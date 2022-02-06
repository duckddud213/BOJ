#include <stdio.h>
#include <stdlib.h>

int main()
{
    int D, K, i, j, a, b, tmp;

    scanf("%d %d", &D, &K);

    a = 0;
    b = 1;
    for (i = 3; i <= D; i++)
    {
        tmp = b;
        b = a + b;
        a = tmp;
    }

    for (i = 1; i <= K; i++)
    {
        for (j = 1; j <= K; j++)
        {
            if (a * i + b * j == K)
            {
                printf("%d\n%d", i, j);
                return 0;
            }
        }
    }
}