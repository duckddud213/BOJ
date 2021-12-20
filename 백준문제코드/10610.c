#include <stdio.h>
#include <stdlib.h>

int compare(const void *x, const void *y)
{
    char a = *(char *)x;
    char b = *(char *)y;

    if (a - '0' > b - '0')
    {
        return -1;
    }
    else if (a - '0' < b - '0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int i, tmp, sum;
    char *str;
    char num;

    str = (char *)malloc(sizeof(char) * 100000);

    i = 0;
    scanf("%c", &num);
    while (num != '\n')
    {
        str[i] = num;
        i++;
        scanf("%c", &num);
    }
    tmp = i;

    qsort(str, tmp, sizeof(char), compare);

    sum = 0;

    for (i = 0; i < tmp; i++)
    {
        sum += (str[i] - '0');
    }

    if ((sum % 3 == 0) && (str[tmp - 1] - '0' == 0))
    {
        for (i = 0; i < tmp; i++)
        {
            printf("%d", (str[i] - '0'));
        }
    }
    else
    {
        printf("%d", -1);
    }
}