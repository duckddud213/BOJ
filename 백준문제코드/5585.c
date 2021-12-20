#include <stdio.h>

int main()
{
    int n, cnt;

    scanf("%d", &n);

    n = 1000 - n;
    cnt = 0;

    while (n > 0)
    {
        if (n >= 500)
        {
            n -= 500;
            cnt++;
        }
        else if (n >= 100)
        {
            n -= 100;
            cnt++;
        }
        else if (n >= 50)
        {
            n -= 50;
            cnt++;
        }
        else if (n >= 10)
        {
            n -= 10;
            cnt++;
        }
        else if (n >= 5)
        {
            n -= 5;
            cnt++;
        }
        else if (n >= 1)
        {
            n -= 1;
            cnt++;
        }
    }

    printf("%d", cnt);
}