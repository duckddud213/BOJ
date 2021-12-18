#include <stdio.h>

int main()
{
    int n;
    unsigned long long a, cnt;

    while (scanf("%d", &n) != -1)
    {
        cnt = 1;
        a = 1;
        while (a % n != 0)
        {
            a %= n;
            a *= 10;
            a += 1;
            cnt++;
        }
        printf("%llu\n", cnt);
    }
}