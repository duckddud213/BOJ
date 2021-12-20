#include <stdio.h>

int main()
{
    int N, cnt;

    scanf("%d", &N);
    cnt = 0;

    while (N > 0)
    {
        if (N % 5 == 0)
        {
            cnt++;
            N -= 5;
        }
        else if (N % 3 == 0)
        {
            cnt++;
            N -= 3;
        }
        else if (N > 5)
        {
            cnt++;
            N -= 5;
        }
        else
        {
            cnt = -1;
            N = 0;
        }
    }
    printf("%d", cnt);
}