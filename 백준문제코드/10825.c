#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct score
{
    int kor, eng, math;
    char name[10];
} score;

int compare(const void *x, const void *y)
{
    score a = *(score *)x;
    score b = *(score *)y;

    if (a.kor < b.kor)
    {
        return 1;
    }
    else if (a.kor > b.kor)
    {
        return -1;
    }
    else
    {
        if (a.eng > b.eng)
        {
            return 1;
        }
        else if (a.eng < b.eng)
        {
            return -1;
        }
        else
        {
            if (a.math < b.math)
            {
                return 1;
            }
            else if (a.math > b.math)
            {
                return -1;
            }
            else
            {
                return strcmp(a.name, b.name);
            }
        }
    }
}
int main()
{
    int N, i;
    score *std;

    scanf("%d", &N);
    getchar();
    std = (score *)malloc(sizeof(score) * N);

    for (i = 0; i < N; i++)
    {
        scanf("%s %d %d %d", std[i].name, &std[i].kor, &std[i].eng, &std[i].math);
        getchar();
    }

    qsort(std, N, sizeof(score), compare);

    for (i = 0; i < N; i++)
    {
        printf("%s\n", std[i].name);
    }
}