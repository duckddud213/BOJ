#include <stdio.h>

int main()
{
    int a, b, start, end, num, i;
    unsigned long long sum;

    scanf("%d %d", &a, &b);

    start = -1;
    end = -1;

    for (i = 1;; i++)
    {
        if (((i * (i + 1) / 2) >= a) && (start == -1))
        {
            start = i;
        }
        if (((i * (i + 1) / 2) >= b) && (end == -1))
        {
            end = i;
            break;
        }
    }

    if (start == end)
    {
        sum = 0;
        sum += (b - a + 1) * start;
        printf("%llu", sum);
    }
    else
    {
        sum = 0;
        sum += ((start * (start + 1) / 2) - a + 1) * start;

        for (i = start + 1; i < end; i++)
        {
            sum += i * i;
        }

        sum += (b - ((end - 1) * end / 2)) * end;
        printf("%llu", sum);
    }
}