#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long n, m, i, j, tmp;
    long long two, five;
    long long two1, two2, five1, five2;

    scanf("%lld %lld", &n, &m);
    if ((n == m) || (m == 0))
    {
        printf("%d", 0);
        return 0;
    }

    two1 = 0;
    five1 = 0;
    two2 = 0;
    five2 = 0;

    for (i = 2; i <= n; i *= 2)
    {
        two1 += (n / i);
    }
    for (i = 5; i <= n; i *= 5)
    {
        five1 += (n / i);
    }

    for (i = 2; i <= m; i *= 2)
    {
        two2 += (m / i);
    }
    for (i = 5; i <= m; i *= 5)
    {
        five2 += (m / i);
    }

    for (i = 2; i <= n - m; i *= 2)
    {
        two2 += ((n - m) / i);
    }
    for (i = 5; i <= n - m; i *= 5)
    {
        five2 += ((n - m) / i);
    }

    two = two1 - two2;
    five = five1 - five2;
    if ((two <= 0) || (five <= 0))
    {
        printf("%d", 0);
    }
    else
    {
        if (two > five)
        {
            printf("%lld", five);
        }
        else
        {
            printf("%lld", two);
        }
    }
}