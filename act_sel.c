
#include <stdio.h>

int main()
{
    int n, start[100], finish[100], temp, i, j;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter start and finish time of activity %d: ", i + 1);
        scanf("%d %d", &start[i], &finish[i]);
    }

    // Sort activities by finishing time
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (finish[j] > finish[j + 1])
            {
                temp = finish[j];
                finish[j] = finish[j + 1];
                finish[j + 1] = temp;

                temp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = temp;
            }
        }
    }

    printf("\nSelected activities: ");

    printf("A1 ");
    int last = 0;

    for (i = 1; i < n; i++)
    {
        if (start[i] >= finish[last])
        {
            printf("A%d ", i + 1);
            last = i;
        }
    }

    return 0;
}
