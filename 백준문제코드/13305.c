#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i;
    unsigned long long *road;
    unsigned long long *city;
    unsigned long long cost,min;

    scanf("%d", &N);

    road = (unsigned long long *)malloc(sizeof(unsigned long long) * (N - 1));
    city = (unsigned long long *)malloc(sizeof(unsigned long long) * N);

    for (i = 0; i < N - 1; i++)
    {
        scanf("%llu", road + i);
    }
    for (i = 0; i < N; i++)
    {
        scanf("%llu", city + i);
    }

    cost = 0;
    min = 0;

    for (i = 0; i < N - 1; i++)
    {
        if (i == 0)
        {
            cost = city[i] * road[i];
            min = city[i];
        }
        else
        {
            if (min > city[i])
            {
                cost += city[i] * road[i];
                min = city[i];
            }
            else
            {
                cost += min * road[i];
            }
        }
    }
    printf("%llu", cost);
}