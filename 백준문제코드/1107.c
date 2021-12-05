#include <stdio.h>
#include <stdlib.h>

int smaller(int x, int y)
{
    if (x < y)
        return x;
    else
        return y;
}

int isBroken(int *btn, int num)
{
    int i, div, cnt;

    i = num;
    div = i / 10;
    cnt = 0;
    if (num == 0)
    {
        if (btn[num] == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    while (num != 0)
    {
        if (btn[num % 10] == 1)
        {
            cnt++;
        }
        num /= 10;
    }

    if (cnt == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int click(int num)
{
    int i, cnt;

    if (num < 10)
    {
        return 1;
    }
    else
    {
        i = num;
        cnt = 0;

        while (i > 0)
        {
            cnt++;
            i /= 10;
        }
        return cnt;
    }
}

int main()
{
    int N, M, i, j, num, min;
    int btn[10];

    scanf("%d %d", &N, &M);

    for (i = 0; i < 10; i++)
    {
        btn[i] = 0;
    }

    for (i = 0; i < M; i++)
    {
        scanf("%d", &num);
        btn[num] = 1;
    }

    min = abs(N - 100);

    for (i = 0; i <= 1000000; i++)
    {
        if (isBroken(btn, i))
        {
            min = smaller(min, click(i) + abs(i - N));
        }
    }

    printf("%d", min);
}