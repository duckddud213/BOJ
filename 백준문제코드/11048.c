#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M, i, A_idx, B_idx;
    int *A;
    int *B;
    int *C;

    scanf("%d %d", &N, &M);

    A = (int *)malloc(sizeof(int) * N);
    B = (int *)malloc(sizeof(int) * M);
    C = (int *)malloc(sizeof(int) * (N + M));

    for (i = 0; i < N; i++)
    {
        scanf("%d", A + i);
    }
    for (i = 0; i < M; i++)
    {
        scanf("%d", B + i);
    }

    A_idx = 0;
    B_idx = 0;

    for (i = 0; i < N + M; i++)
    {
        if (A_idx == N)
        {
            C[i] = B[B_idx];
            B_idx++;
        }
        else if (B_idx == M)
        {
            C[i] = A[A_idx];
            A_idx++;
        }
        else if (A[A_idx] > B[B_idx])
        {
            C[i] = B[B_idx];
            B_idx++;
        }
        else if (A[A_idx] <= B[B_idx])
        {
            C[i] = A[A_idx];
            A_idx++;
        }
    }

    for (i = 0; i < N + M; i++)
    {
        printf("%d ", C[i]);
    }
}