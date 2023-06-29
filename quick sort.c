#include <stdio.h>
#include <time.h>
#include <stdlib.h>
// Function to swap numbers quicksort
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Partition Function quicksort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    int j;
    for (j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot) // if J is less than or equal to the pivot
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
// Quick Sort function
void quicksort(int Arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(Arr, low, high);
        quicksort(Arr, low, pi - 1);
        quicksort(Arr, pi + 1, high);
    }
}
int main()
{
    double start, stop, time, sum;
    int arr[1000], n;

    printf("Implementing QUICK-SORT \nEnter array size:");
    scanf("%d", &n);
    printf("\n Generating random values.....\nThe array:");

    for (int x = 0; x < n; x++)
        arr[x] = rand() % 50;

    for (int x = 0; x < n; x++)
        printf("%d,", arr[x]);

    printf("\n Sorting array.........\nSorted array: ");

    start = clock();
    quicksort(arr, 0, n - 1);
    stop = clock();
    time = (stop - start) / CLOCKS_PER_SEC;

    for (int x = 0; x < n; x++)
        printf("%d,", arr[x]);

    printf("\nTime taken = %.10f\n", time);

    return 0;
}