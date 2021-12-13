#include <stdio.h>
#include <stdlib.h>

int biggest(int x, int y, int z)
{
    if ((x > y) && (x > z))
    {
        return x;
    }
    else if ((y > x) && (y > z))
    {
        return y;
    }
    else
    {
        return z;
    }
}

int main()
{
    int N, M, i, j;
    int **maze;

    scanf("%d %d", &N, &M);

    maze = (int **)malloc(sizeof(int *) * N);

    for (i = 0; i < N; i++)
    {
        maze[i] = (int *)malloc(sizeof(int) * M);
        for (j = 0; j < M; j++)
        {
            scanf("%d", &maze[i][j]);
        }
    }

    for (i = 1; i < N; i++)
    {
        maze[i][0] += maze[i - 1][0];
    }
    for (j = 1; j < M; j++)
    {
        maze[0][j] += maze[0][j - 1];
    }

    for (i = 1; i < N; i++)
    {
        for (j = 1; j < M; j++)
        {
            maze[i][j] += biggest(maze[i - 1][j], maze[i - 1][j - 1], maze[i][j - 1]);
        }
    }
    printf("%d", maze[N - 1][M - 1]);
}