#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (1) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(&arr[i], &arr[j]);
    }
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int part = partition(arr, low, high);
        quicksort(arr, low, part);
        quicksort(arr, part + 1, high);
    }
}

int main() {
    printf("\nEnter number of elements: ");
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    clock_t start = clock();
    quicksort(arr, 0, n - 1);

    clock_t end = clock();
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("quicksort() took %f seconds to execute \n", time_taken);
    
    free(arr);

    return 0;
}
