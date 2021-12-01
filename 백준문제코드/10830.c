#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix
{
    unsigned long long arr[5][5];
} Matrix;

int main()
{
    Matrix insert;
    Matrix result;
    Matrix *tmp;
    Matrix save;
    int N, i, j, k, flag;
    unsigned long long x, B, cnt, check, sum;

    scanf("%d %llu", &N, &B);

    flag = 0; //result에 값이 써지기 전임을 나타냄
    cnt = 1;
    check = 0;
    while (B >= cnt)
    {
        cnt *= 2;
        check++;
    }
    if (cnt != 1)
    {
        cnt /= 2;
        check--;
    }

    tmp = (Matrix *)malloc(sizeof(Matrix) * (check + 1));

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%llu", &insert.arr[i][j]);
        }
    }

    for (x = 1; x <= check; x++)
    {
        if (x == 1) //2의 1승인 경우
        {
            for (i = 0; i < N; i++)
            {
                for (j = 0; j < N; j++)
                {
                    sum = 0;
                    for (k = 0; k < N; k++)
                    {
                        sum = sum + ((insert.arr[i][k] * insert.arr[k][j]) % 1000);
                        sum %= 1000;
                    }
                    tmp[x].arr[i][j] = sum;
                }
            }
        }
        else
        {
            for (i = 0; i < N; i++)
            {
                for (j = 0; j < N; j++)
                {
                    sum = 0;
                    for (k = 0; k < N; k++)
                    {
                        sum = sum + ((tmp[x - 1].arr[i][k] * tmp[x - 1].arr[k][j]) % 1000);
                        sum %= 1000;
                    }
                    tmp[x].arr[i][j] = sum;
                }
            }
        }
    }

    if (B == 1)
    {
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                printf("%llu ", (insert.arr[i][j]) % 1000);
            }
            printf("\n");
        }
        return 0;
    }

    while (B > 0)
    {
        cnt = 1;
        check = 0;
        while (B >= cnt)
        {
            cnt *= 2;
            check++;
        }
        if (cnt != 1)
        {
            cnt /= 2;
            check--;
        }

        if (B == 1)
        {
            for (i = 0; i < N; i++)
            {
                for (j = 0; j < N; j++)
                {
                    sum = 0;
                    for (k = 0; k < N; k++)
                    {
                        sum = sum + ((result.arr[i][k] * insert.arr[k][j]) % 1000);
                        sum %= 1000;
                    }
                    save.arr[i][j] = sum;
                }
            }

            for (i = 0; i < N; i++)
            {
                for (j = 0; j < N; j++)
                {
                    result.arr[i][j] = save.arr[i][j];
                }
            }

            B = 0;
        }
        else if (B > 1)
        {
            if (flag == 0) //result에 값을 쓰기 전인 경우
            {
                for (i = 0; i < N; i++)
                {
                    for (j = 0; j < N; j++)
                    {
                        result.arr[i][j] = tmp[check].arr[i][j];
                    }
                }
                flag = 1;
            }
            else
            {
                for (i = 0; i < N; i++)
                {
                    for (j = 0; j < N; j++)
                    {
                        sum = 0;
                        for (k = 0; k < N; k++)
                        {
                            sum = sum + ((result.arr[i][k] * tmp[check].arr[k][j]) % 1000);
                            sum %= 1000;
                        }
                        save.arr[i][j] = sum;
                    }
                }

                for (i = 0; i < N; i++)
                {
                    for (j = 0; j < N; j++)
                    {
                        result.arr[i][j] = save.arr[i][j];
                    }
                }
            }
            if (B < cnt)
            { //B가 unsigned long long 형이라 음수가 불가
                B = 0;
            }
            else
            {
                B -= cnt;
            }
        }
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%llu ", result.arr[i][j]);
        }
        printf("\n");
    }
}