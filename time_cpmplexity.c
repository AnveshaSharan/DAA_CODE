#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Linear Search - O(n)
int linearSearch(int arr[], int n, int target)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (arr[i] == target)
            return i;
    }

    return -1;
}

// Binary Search - O(log n)
int binarySearch(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        else if (arr[mid] < target)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int n, i;
    int target = -1;

    printf("Size\tLinear Time\tBinary Time\n");

    for (n = 10000; n <= 100000; n += 10000)
    {
        int *arr = (int *)malloc(n * sizeof(int));

        // Create sorted array
        for (i = 0; i < n; i++)
        {
            arr[i] = i;
        }

        // -------- Linear Search --------
        clock_t start1 = clock();

        linearSearch(arr, n, target);

        clock_t end1 = clock();

        double linearTime =
            ((double)(end1 - start1)) / CLOCKS_PER_SEC;


        // -------- Binary Search --------
        clock_t start2 = clock();

        binarySearch(arr, n, target);

        clock_t end2 = clock();

        double binaryTime =
            ((double)(end2 - start2)) / CLOCKS_PER_SEC;


        printf("%d\t%f\t%f\n",
               n, linearTime, binaryTime);

        free(arr);
    }

    return 0;
}