#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bigger(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

int main()
{
    char *str1;
    char *str2;
    int i, j, cnt_i, cnt_j, max;
    int **match;

    str1 = (char *)malloc(sizeof(char) * 1000);
    str2 = (char *)malloc(sizeof(char) * 1000);

    scanf("%s", str1);
    scanf("%s", str2);

    cnt_i = strlen(str1) + 1;
    cnt_j = strlen(str2) + 1;

    match = (int **)malloc(sizeof(int *) * cnt_i);
    for (i = 0; i < cnt_i; i++)
    {
        match[i] = (int *)malloc(sizeof(int) * cnt_j);
        if (i == 0)
        {
            for (j = 0; j < cnt_j; j++)
            {
                match[i][j] = 0;
            }
        }
        match[i][0] = 0;
    }

    max = 0;
    for (i = 1; i < cnt_i; i++)
    {
        for (j = 1; j < cnt_j; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                match[i][j] = match[i - 1][j - 1] + 1;
            }
            else
            {
                match[i][j] = bigger(match[i - 1][j], match[i][j - 1]);
            }
            if (max < match[i][j])
            {
                max = match[i][j];
            }
        }
    }
    printf("%d", max);
}