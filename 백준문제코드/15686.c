#include <stdio.h>
#include <stdlib.h>

int d = -1;

typedef struct city
{
    int i, j;
} city;

void removeStore(city *home, city *remain, int home_cnt, int M)
{
    int i, j, sum, min, diff_i, diff_j;

    sum = 0;
    for (i = 0; i < home_cnt; i++)
    {
        min = 0;
        for (j = 0; j < M; j++)
        {
            diff_i = abs(home[i].i - remain[j].i);
            diff_j = abs(home[i].j - remain[j].j);
            if (min == 0)
            {
                min = diff_i + diff_j;
            }
            else if (diff_i + diff_j == 1) //치킨집과의 거리가 가능한 최소값인 경우
            {
                min = 1;
                j += M;
            }
            else if (min > diff_i + diff_j)
            {
                min = diff_i + diff_j;
            }
        }
        sum += min;

        if ((d != -1) && (d < sum))
        {
            return;
        }
    }

    if (d == -1)
    {
        d = sum;
    }
    else if (d > sum)
    {
        d = sum;
    }
}

void backTracking(city *home, city *store, city *remain, int home_cnt, int store_cnt, int M, int depth)
{
    int i, j, k, check;

    for (i = 0; i < store_cnt; i++)
    {
        if (depth == 0)
        {
            remain[0].i = store[i].i;
            remain[0].j = store[i].j;
        }
        else
        {
            check = 0;
            for (j = 0; j < depth; j++)
            {
                if ((remain[j].i == store[i].i) && (remain[j].j == store[i].j))
                {
                    break;
                }
                else
                {
                    for (k = i + 1; k < store_cnt; k++) //중복 조합 제거차 확인하는 반복문
                    {
                        if ((store[k].i == remain[j].i) && (store[k].j == remain[j].j))
                        {
                            check++;
                            break;
                        }
                    }
                }
                if (check != 0)
                    break;
            }

            if (j == depth)
            {
                remain[depth].i = store[i].i;
                remain[depth].j = store[i].j;
            }
            else
                continue;
        }

        if (depth == M - 1) //remain배열에 값이 다 들어갔을때
        {
            removeStore(home, remain, home_cnt, M);
        }
        else
        {
            backTracking(home, store, remain, home_cnt, store_cnt, M, depth + 1);
        }
    }
}

int main()
{
    int N, M, i, j, num;
    int home_cnt, store_cnt;
    city *home;
    city *store;
    city *remain;

    scanf("%d %d", &N, &M);
    home = (city *)malloc(sizeof(city) * 2 * N);
    store = (city *)malloc(sizeof(city) * 13);
    remain = (city *)malloc(sizeof(city) * M);
    home_cnt = 0;
    store_cnt = 0;

    for (i = 0; i < 13; i++)
    {
        store[i].i = -1;
        store[i].j = -1;
    }
    for (i = 0; i < 2 * N; i++)
    {
        home[i].i = -1;
        home[i].j = -1;
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &num);
            if (num == 1)
            {
                home[home_cnt].i = i;
                home[home_cnt].j = j;
                home_cnt++;
            }
            else if (num == 2)
            {
                store[store_cnt].i = i;
                store[store_cnt].j = j;
                store_cnt++;
            }
        }
    }

    backTracking(home, store, remain, home_cnt, store_cnt, M, 0);

    printf("%d", d);
}