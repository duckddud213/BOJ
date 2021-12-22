#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct alphabet
{
    char alpha;
    int num;
} alphabet;

int compare(const void *x, const void *y)
{
    alphabet a = *(alphabet *)x;
    alphabet b = *(alphabet *)y;

    if (a.num < b.num)
    {
        return 1;
    }
    else if (a.num > b.num)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int multiple(int cnt)
{
    int i, tmp;

    if (cnt == 0)
    {
        return 1;
    }
    else
    {
        tmp = 1;
        for (i = 0; i < cnt; i++)
        {
            tmp *= 10;
        }
        return tmp;
    }
}

void addValue(alphabet *alpha, char *str, int j, int length)
{
    alpha[str[j] - 'A'].num += multiple(length - 1 - j);
}

int main()
{
    int i, j, N, tmp;
    long long sum;
    alphabet alpha[26];
    char *str;

    str = (char *)malloc(sizeof(char) * 8);

    scanf("%d", &N);

    for (i = 0; i < 26; i++)
    {
        alpha[i].num = 0;
        alpha[i].alpha = 'A' + i;
    }

    for (i = 0; i < N; i++)
    {
        scanf("%s", str);
        tmp = strlen(str);

        for (j = 0; j < tmp; j++)
        {
            addValue(alpha, str, j, tmp);
            str[j] = '\0';
        }
    }

    qsort(alpha, 26, sizeof(alphabet), compare);
    sum = 0;
    tmp = 9;

    for (i = 0; i < 26; i++)
    {
        if (alpha[i].num != 0)
        {
            sum += (alpha[i].num * tmp);
            tmp--;
        }
    }
    printf("%lld", sum);
}