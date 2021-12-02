#include <stdio.h>

int main()
{
    int n, i;
    unsigned long long sum;

    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            sum = 1;
        }
        else if (i % 2 == 0)
        {
            sum *= 2;
            sum++;
            sum %= 10007;
        }
        else if (i % 2 != 0)
        {
            sum *= 2;
            sum--;
            sum %= 10007;
        }
    }

    printf("%llu", sum % 10007);
}