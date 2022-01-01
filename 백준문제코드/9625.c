#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, K, i, tmp;

    scanf("%d", &K);

    if (K == 1)
    {
        printf("%d %d", 0, 1);
    }
    else if (K == 2)
    {
        printf("%d %d", 1, 1);
    }
    else
    {
        a = 1;
        b = 1;
        for (i = 3; i <= K; i++)
        {
            tmp = b;
            b += a;
            a = tmp;
        }
        printf("%d %d", a, b);
    }
}