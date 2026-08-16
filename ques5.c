#include <stdio.h>

int main()
{
    int r1, c1, r2, c2;
    int i, j, k;

    printf("Enter rows and columns of the first matrix: ");
    scanf("%d%d", &r1, &c1);

    printf("Enter rows and columns of the second matrix: ");
    scanf("%d%d", &r2, &c2);

    if (c1 != r2)
    {
        printf("Matrix multiplication is not possible.");

        return 0;
    }

    int A[r1][c1], B[r2][c2], C[r1][c2];

    printf("Enter the elements of the first matrix:\n");

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:\n");

    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            C[i][j] = 0;

            for (k = 0; k < c1; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("Resultant matrix:\n");

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            printf("%d ", C[i][j]);
        }

        printf("\n");
    }

    return 0;
}