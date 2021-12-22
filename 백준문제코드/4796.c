#include <stdio.h>

int smaller(int x, int y)
{
    if (x > y)
    {
        return y;
    }
    else
    {
        return x;
    }
}

int main()
{
    int i, L, P, V, sum;

    scanf("%d %d %d", &L, &P, &V);
    i = 1;

    while ((L != 0) && (P != 0) && (V != 0))
    {
        sum = 0;
        sum += (V / P) * L;
        sum += smaller(L, V - (V / P) * P);

        printf("Case %d: %d\n", i, sum);
        i++;
        scanf("%d %d %d", &L, &P, &V);
    }
}