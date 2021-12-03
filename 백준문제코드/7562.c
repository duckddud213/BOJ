#include <stdio.h>
#include <stdlib.h>

typedef struct Location
{
    int i, j;
} Location;

void goToDest(int **chess, int size, Location start, Location dest)
{
    Location *que;
    int i, idx, flag, depth, check_step, qi, qj, new_in, a, b;

    que = (Location *)malloc(sizeof(Location) * size * size);

    for (i = 0; i < size * size; i++)
    {
        que[i].i = -1;
        que[i].j = -1;
    }

    if ((start.i == dest.i) && (start.j == dest.j))
    {
        printf("%d\n", 0);
        return;
    }

    que[0].i = start.i;
    que[0].j = start.j;
    flag = 0; //발견시 flag = 1로 바꿔 반복문 종료
    i = 0;
    idx = 1;
    depth = 0;
    check_step = 0;
    new_in = 0;

    while ((que[i].i != -1) && (que[i].j != -1) && (flag == 0))
    {
        qi = que[i].i;
        qj = que[i].j;
        chess[qi][qj] = 1;

        if (qi - 2 >= 0)
        {
            if (qj - 1 >= 0)
            {
                if ((qi - 2 == dest.i) && (qj - 1 == dest.j))
                {
                    flag = 1;
                    continue;
                }

                if (chess[qi - 2][qj - 1] == 0)
                {
                    que[idx].i = qi - 2;
                    que[idx].j = qj - 1;
                    idx++;
                    chess[qi - 2][qj - 1] = 1;
                    new_in++;
                }
            }
            if (qj + 1 < size)
            {
                if ((qi - 2 == dest.i) && (qj + 1 == dest.j))
                {
                    flag = 1;
                    continue;
                }

                if (chess[qi - 2][qj + 1] == 0)
                {
                    que[idx].i = qi - 2;
                    que[idx].j = qj + 1;
                    idx++;
                    chess[qi - 2][qj + 1] = 1;
                    new_in++;
                }
            }
        }
        if (qi + 2 < size)
        {
            if (qj - 1 >= 0)
            {

                if ((qi + 2 == dest.i) && (qj - 1 == dest.j))
                {
                    flag = 1;
                    continue;
                }

                if (chess[qi + 2][qj - 1] == 0)
                {
                    que[idx].i = qi + 2;
                    que[idx].j = qj - 1;
                    idx++;
                    chess[qi + 2][qj - 1] = 1;
                    new_in++;
                }
            }
            if (qj + 1 < size)
            {
                if ((qi + 2 == dest.i) && (qj + 1 == dest.j))
                {
                    flag = 1;
                    continue;
                }

                if (chess[qi + 2][qj + 1] == 0)
                {
                    que[idx].i = qi + 2;
                    que[idx].j = qj + 1;
                    idx++;
                    chess[qi + 2][qj + 1] = 1;
                    new_in++;
                }
            }
        }
        if (qj - 2 >= 0)
        {
            if (qi - 1 >= 0)
            {
                if ((qi - 1 == dest.i) && (qj - 2 == dest.j))
                {
                    flag = 1;
                    continue;
                }

                if (chess[qi - 1][qj - 2] == 0)
                {
                    que[idx].i = qi - 1;
                    que[idx].j = qj - 2;
                    idx++;
                    chess[qi - 1][qj - 2] = 1;
                    new_in++;
                }
            }
            if (qi + 1 < size)
            {
                if ((qi + 1 == dest.i) && (qj - 2 == dest.j))
                {
                    flag = 1;
                    continue;
                }
                if (chess[qi + 1][qj - 2] == 0)
                {
                    que[idx].i = qi + 1;
                    que[idx].j = qj - 2;
                    idx++;
                    chess[qi + 1][qj - 2] = 1;
                    new_in++;
                }
            }
        }
        if (qj + 2 < size)
        {
            if (qi - 1 >= 0)
            {
                if ((qi - 1 == dest.i) && (qj + 2 == dest.j))
                {
                    flag = 1;
                    continue;
                }

                if (chess[qi - 1][qj + 2] == 0)
                {
                    que[idx].i = qi - 1;
                    que[idx].j = qj + 2;
                    idx++;
                    chess[qi - 1][qj + 2] = 1;
                    new_in++;
                }
            }
            if (qi + 1 < size)
            {
                if ((qi + 1 == dest.i) && (qj + 2 == dest.j))
                {
                    flag = 1;
                    continue;
                }

                if (chess[qi + 1][qj + 2] == 0)
                {
                    que[idx].i = qi + 1;
                    que[idx].j = qj + 2;
                    idx++;
                    chess[qi + 1][qj + 2] = 1;
                    new_in++;
                }
            }
        }
        if (i == check_step)
        {
            depth++;
            check_step += new_in;
            new_in=0;
        }
        i++;
    }
    printf("%d\n", depth + 1);

    free(que);
}

int main()
{
    Location start, dest;
    int x, T, l, i, j;
    int **chess;

    scanf("%d", &T);

    chess = (int **)malloc(sizeof(int *) * 300);
    for (i = 0; i < 300; i++)
    {
        chess[i] = (int *)malloc(sizeof(int) * 300);
        for (j = 0; j < 300; j++)
        {
            chess[i][j] = 0;
        }
    }

    for (x = 0; x < T; x++)
    {
        scanf("%d", &l);
        scanf("%d %d", &start.i, &start.j);
        scanf("%d %d", &dest.i, &dest.j);

        goToDest(chess, l, start, dest);

        for (i = 0; i < l; i++)
        {
            for (j = 0; j < l; j++)
            {
                chess[i][j] = 0;
            }
        }
    }
}