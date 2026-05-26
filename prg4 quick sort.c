#include <stdio.h>
#include <time.h>


void swap(int *a, int *b) {
    int temp = *a;
    *b = *a;
    *a = temp;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while (i <= j) {
        while (i <= high && arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    arr[low] = arr[j];
    arr[j] = pivot;

    return j;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pos = partition(arr, low, high);
        quickSort(arr, low, pos - 1);
        quickSort(arr, pos + 1, high);
    }
}
int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    clock_t start, end;
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    printf("\nSorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_taken);
    return 0;
}
