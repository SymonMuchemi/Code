/* Insertion sort ascending order */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int n, array[1000], c, d, t;
    float start, stop, dur;

    printf("Implementing INSERTION SORT \n Enter number of elements\n");
    scanf("%d", &n);
    // printf("Enter %d integers\n", n);

    for (int x = 0; x < n; x++)
        array[x] = rand() % 50;

    /*for (c = 0; c < n; c++)
        scanf("%d", &array[c]);*/

    start = clock();
    for (c = 1; c <= n - 1; c++)
    {
        d = c;
        while (d > 0 && array[d - 1] > array[d])
        {
            t = array[d];
            array[d] = array[d - 1];
            array[d - 1] = t;
            d--;
        }
    }
    stop = clock();
    dur = (stop - start) / CLOCKS_PER_SEC;

    printf("Sorted list in ascending order:\n");
    for (c = 0; c <= n - 1; c++)
    {
        printf("%d, ", array[c]);
    }
    printf("\nTime taken = %.10f\n", dur);
    return 0;
}