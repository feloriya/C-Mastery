#include <stdio.h>
#include <stdlib.h>

void printArray(int* arr, int size);

int main() {
    int size;
    int* arr = NULL;
    int sum = 0;
    float average;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printArray(arr, size);

    average = (float)sum / size;
    printf("Average: %.2f\n", average);

    free(arr);
    arr = NULL;

    return 0;
}

void printArray(int* arr, int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}