#include <stdio.h>
#include <stdlib.h>

int flag = 0; //스도쿠 값을 한번만 출력하기 위한 변수

typedef struct location
{
    int i, j;
} location;

int canInsert(int **sudoku, int i, int j, int newValue) //가로,세로줄에 같은 값이 있는지 & 9칸 내에 같은 수가 있는지 확인하는 함수
{
    int x, y;

    if (i < 3)
    {
        if (j < 3)
        {
            for (x = 0; x < 3; x++)
            {
                for (y = 0; y < 3; y++)
                {
                    if (sudoku[x][y] == newValue)
                    {
                        return 0;
                    }
                }
            }
        }
        else if (j < 6)
        {
            for (x = 0; x < 3; x++)
            {
                for (y = 3; y < 6; y++)
                {
                    if (sudoku[x][y] == newValue)
                    {
                        return 0;
                    }
                }
            }
        }
        else
        {
            for (x = 0; x < 3; x++)
            {
                for (y = 6; y < 9; y++)
                {
                    if (sudoku[x][y] == newValue)
                    {
                        return 0;
                    }
                }
            }
        }
    }
    else if (i < 6)
    {
        if (j < 3)
        {
            for (x = 3; x < 6; x++)
            {
                for (y = 0; y < 3; y++)
                {
                    if (sudoku[x][y] == newValue)
                    {
                        return 0;
                    }
                }
            }
        }
        else if (j < 6)
        {
            for (x = 3; x < 6; x++)
            {
                for (y = 3; y < 6; y++)
                {
                    if (sudoku[x][y] == newValue)
                    {
                        return 0;
                    }
                }
            }
        }
        else
        {
            for (x = 3; x < 6; x++)
            {
                for (y = 6; y < 9; y++)
                {
                    if (sudoku[x][y] == newValue)
                    {
                        return 0;
                    }
                }
            }
        }
    }
    else
    {
        if (j < 3)
        {
            for (x = 6; x < 9; x++)
            {
                for (y = 0; y < 3; y++)
                {
                    if (sudoku[x][y] == newValue)
                    {
                        return 0;
                    }
                }
            }
        }
        else if (j < 6)
        {
            for (x = 6; x < 9; x++)
            {
                for (y = 3; y < 6; y++)
                {
                    if (sudoku[x][y] == newValue)
                    {
                        return 0;
                    }
                }
            }
        }
        else
        {
            for (x = 6; x < 9; x++)
            {
                for (y = 6; y < 9; y++)
                {
                    if (sudoku[x][y] == newValue)
                    {
                        return 0;
                    }
                }
            }
        }
    }

    for (x = 0; x < 9; x++)
    {
        if (sudoku[x][j] == newValue)
        {
            return 0;
        }
        if (sudoku[i][x] == newValue)
        {
            return 0;
        }
    }

    return 1;
}

void backTracking(int **sudoku, location *blank, int blank_cnt, int depth)
{
    int i, j, k;

    for (i = 1; i <= 9; i++)
    {
        if (flag == 1)
        {
            return;
        }

        if (canInsert(sudoku, blank[depth].i, blank[depth].j, i))
        {
            sudoku[blank[depth].i][blank[depth].j] = i;
        }
        else
        {
            continue;
        }

        if (depth == blank_cnt - 1)
        {
            for (j = 0; j < 9; j++)
            {
                for (k = 0; k < 9; k++)
                {
                    printf("%d ", sudoku[j][k]);
                }
                printf("\n");
            }
            flag = 1;
        }
        else
        {
            backTracking(sudoku, blank, blank_cnt, depth + 1);
            sudoku[blank[depth].i][blank[depth].j] = 0;
        }
    }
}

int main()
{
    int **sudoku;
    int i, j, idx;
    location blank[81];

    idx = 0;
    sudoku = (int **)malloc(sizeof(int *) * 9);
    for (i = 0; i < 9; i++)
    {
        sudoku[i] = (int *)malloc(sizeof(int) * 9);
        for (j = 0; j < 9; j++)
        {
            scanf("%d", &sudoku[i][j]);
            if (sudoku[i][j] == 0)
            {
                blank[idx].i = i;
                blank[idx].j = j;
                idx++;
            }
        }
    }

    backTracking(sudoku, blank, idx, 0);
}