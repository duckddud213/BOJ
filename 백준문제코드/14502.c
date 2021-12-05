#include <stdio.h>
#include <stdlib.h>

int cnt = -1;

typedef struct location
{
    int i, j;
    int cnt; //cB 배열 backTracking시 중복조합 방지를 위한 변수
} location;

void spreadVirus(int **lab, location *virus, int N, int M, int cB_size, int virus_size) //벽을 세운 뒤 바이러스 퍼지는 bfs 탐색 실행
{
    int i, j, q_index, safe;
    location *que;
    location q;

    que = (location *)malloc(sizeof(location) * (cB_size + virus_size));
    for (i = 0; i < cB_size + virus_size; i++)
    {
        que[i].i = -1;
        que[i].j = -1;
    }

    q_index = 0;
    j = 0;

    for (i = 0; i < virus_size; i++)
    {
        que[q_index].i = virus[i].i;
        que[q_index].j = virus[i].j;
        q_index++;
        while ((que[j].i != -1) && (que[j].j != -1))
        {
            q.i = que[j].i;
            q.j = que[j].j;

            if (q.i - 1 >= 0)
            {
                if (lab[q.i - 1][q.j] == 0)
                {
                    que[q_index].i = q.i - 1;
                    que[q_index].j = q.j;
                    q_index++;
                    lab[q.i - 1][q.j] = 2;
                }
            }
            if (q.i + 1 < N)
            {
                if (lab[q.i + 1][q.j] == 0)
                {
                    que[q_index].i = q.i + 1;
                    que[q_index].j = q.j;
                    q_index++;
                    lab[q.i + 1][q.j] = 2;
                }
            }
            if (q.j - 1 >= 0)
            {
                if (lab[q.i][q.j - 1] == 0)
                {
                    que[q_index].i = q.i;
                    que[q_index].j = q.j - 1;
                    q_index++;
                    lab[q.i][q.j - 1] = 2;
                }
            }
            if (q.j + 1 < M)
            {
                if (lab[q.i][q.j + 1] == 0)
                {
                    que[q_index].i = q.i;
                    que[q_index].j = q.j + 1;
                    q_index++;
                    lab[q.i][q.j + 1] = 2;
                }
            }

            j++;
        }
    }

    safe = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (lab[i][j] == 0)
            {
                safe++;
            }
        }
    }

    if (cnt == -1)
    {
        cnt = safe;
    }
    else if (cnt < safe)
    {
        cnt = safe;
    }
}

void buildWall(int **lab, location *wB, location *virus, int N, int M, int cB_size, int virus_size)
{
    int **copied_lab; //spreadVirus 함수에서 bfs 탐색으로 인해 원래 lab 배열의 값이 달라질것이므로 copy를 만들어 bfs 탐색
    int i, j;

    copied_lab = (int **)malloc(sizeof(int *) * N);
    for (i = 0; i < N; i++)
    {
        copied_lab[i] = (int *)malloc(sizeof(int) * M);
        for (j = 0; j < M; j++)
        {
            copied_lab[i][j] = lab[i][j];
        }
    }

    copied_lab[wB[0].i][wB[0].j] = 1;
    copied_lab[wB[1].i][wB[1].j] = 1;
    copied_lab[wB[2].i][wB[2].j] = 1;
    spreadVirus(copied_lab, virus, N, M, cB_size, virus_size);
    for (i = 0; i < N; i++)
    {
        free(copied_lab[i]);
    }
    free(copied_lab);
}

void selectLocation(int **lab, location *cB, location *wB, location *virus, int N, int M, int cB_size, int virus_size, int depth) //backtracking 방식으로 벽을 세울 위치 선정
{
    int i, j, k;

    for (i = 0; i < cB_size; i++)
    {
        if (depth == 0)
        {
            wB[0].i = cB[i].i;
            wB[0].j = cB[i].j;
            wB[0].cnt = cB[i].cnt;
        }
        else
        {
            for (j = 0; j < depth; j++)
            {
                if (cB[i].cnt <= wB[j].cnt)
                {
                    break;
                }
            }

            if (j == depth)
            {
                wB[depth].i = cB[i].i;
                wB[depth].j = cB[i].j;
                wB[depth].cnt = cB[i].cnt;
            }
            else
            {
                continue;
            }
        }

        if (depth == 2)
        {
            buildWall(lab, wB, virus, N, M, cB_size, virus_size);
        }
        else
        {
            selectLocation(lab, cB, wB, virus, N, M, cB_size, virus_size, depth + 1);
        }
    }
}

int main()
{
    int N, M, i, j, v_index, c_index;
    int **lab;
    location *canBuild;
    location *willBuild;
    location *virus;

    scanf("%d %d", &N, &M);

    lab = (int **)malloc(sizeof(int *) * N);
    virus = (location *)malloc(sizeof(location) * 10);
    canBuild = (location *)malloc(sizeof(location) * ((N * M) - 2));
    willBuild = (location *)malloc(sizeof(location) * 3);

    v_index = 0; //virus 배열 인덱스
    c_index = 0; //canBuild 배열 인덱스

    for (i = 0; i < N; i++)
    {
        lab[i] = (int *)malloc(sizeof(int) * M);
        for (j = 0; j < M; j++)
        {
            scanf("%d", &lab[i][j]);
            if (lab[i][j] == 0)
            {
                canBuild[c_index].i = i;
                canBuild[c_index].j = j;
                canBuild[c_index].cnt = c_index;
                c_index++;
            }
            else if (lab[i][j] == 2)
            {
                virus[v_index].i = i;
                virus[v_index].j = j;
                v_index++;
            }
        }
    }

    selectLocation(lab, canBuild, willBuild, virus, N, M, c_index, v_index, 0);

    printf("%d", cnt);
}