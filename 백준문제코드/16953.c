#include <stdio.h>

int main()
{
    int A, B, cnt;

    scanf("%d %d", &A, &B);
    cnt = 1;

    while (B > A)
    {
        if (B % 2 == 0)
        {
            cnt++;
            B /= 2;
        }
        else if (B % 10 == 1)
        {
            cnt++;
            B /= 10;
        }
        else
        {
            B = A - 1;
        }
    }

    if (B < A)
    {
        printf("%d", -1);
    }
    else if (B == A)
    {
        printf("%d", cnt);
    }
}