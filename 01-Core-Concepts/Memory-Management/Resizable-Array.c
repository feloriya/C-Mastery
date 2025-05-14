#include <stdio.h>
#include <stdlib.h>

int* resizeArray(int* arr, size_t currentSize, size_t newCapacity);

int main() {
    size_t capacity = 5;
    size_t size = 0;
    int* arr = (int*)malloc(capacity * sizeof(int));
    
    // Example usage
    if (size == capacity) {
        capacity *= 2; // Double the capacity
        arr = resizeArray(arr, size, capacity);
        if (!arr) {
            printf("Memory allocation failed!\n");
            return 1;
        }
    }
    
    // When array is quarter full, shrink it
    if (capacity > 10 && size < capacity / 4) {
        capacity /= 2;
        arr = resizeArray(arr, size, capacity);
    }
    
    free(arr);
    return 0;
}

int* resizeArray(int* arr, size_t currentSize, size_t newCapacity) {
    if (newCapacity == 0) {
        free(arr);
        return NULL;
    }
    
    int* newArr = (int*)realloc(arr, newCapacity * sizeof(int));
    if (!newArr) {
        // Handle allocation failure
        return NULL;
    }
    
    return newArr;
}