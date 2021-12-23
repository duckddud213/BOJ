#include <stdio.h>
#include <stdlib.h>

int main()
{
    int zero, one, cnt;
    char befo, num;

    befo = 'X';
    zero = 0;
    one = 0;

    scanf("%c", &num);

    while (num != '\n')
    {
        if (befo == 'X')
        {
            befo = num;
            if (num == '1')
            {
                one++;
            }
            else if (num == '0')
            {
                zero++;
            }
        }
        else
        {
            if (befo != num)
            {
                if (befo == '1')
                {
                    zero++;
                    befo = num;
                }
                else if (befo == '0')
                {
                    one++;
                    befo = num;
                }
            }
        }
        scanf("%c", &num);
    }

    //    printf("%d %d\n", zero, one);

    if (zero == 0)
    {
        printf("%d", zero);
    }
    else if (one == 0)
    {
        printf("%d", one);
    }
    else
    {
        if (zero > one)
        {
            printf("%d", one);
        }
        else
        {
            printf("%d", zero);
        }
    }
}