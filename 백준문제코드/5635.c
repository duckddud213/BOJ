#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    char name[16];
    int day, month, year;
} std;

int compare(const void *x, const void *y)
{
    std a = *(std *)x;
    std b = *(std *)y;

    if (a.year > b.year)
    {
        return 1;
    }
    else if (a.year < b.year)
    {
        return -1;
    }
    else
    {
        if (a.month > b.month)
        {
            return 1;
        }
        else if (a.month < b.month)
        {
            return -1;
        }
        else
        {
            if (a.day > b.day)
            {
                return 1;
            }
            else if (a.day < b.day)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }
    }
}

int main()
{
    int n, i;
    std *class;

    scanf("%d", &n);
    getchar();
    class = (std *)malloc(sizeof(std) * n);

    for (i = 0; i < n; i++)
    {
        scanf("%s %d %d %d", class[i].name, &class[i].day, &class[i].month, &class[i].year);
        getchar();
    }

    qsort(class, n, sizeof(std), compare);

    printf("%s\n%s", class[n - 1].name, class[0].name);
}