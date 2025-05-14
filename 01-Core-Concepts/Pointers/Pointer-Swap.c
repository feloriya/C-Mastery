#include <stdio.h>
#include <assert.h> // For using assert macro

// Function to swap values of two variables
void swap(int* num1, int* num2);

int main(void) {
    int a;
    int b;
    
    // Get input from user
    printf("Enter Number 1 : ");
    scanf("%d", &a);
    printf("Enter Number 2 : ");
    scanf("%d", &b);
    
    // Store original values for testing
    int original_a = a;
    int original_b = b;
    
    // Pre-swap test - verify initial values
    assert(a == original_a && b == original_b);
    
    // Call swap function
    swap(&a, &b);
    
    // Post-swap tests
    assert(a == original_b && b == original_a); // Verify values were swapped
    assert(a != b || original_a == original_b); // Special case when values are equal
    
    // Display results
    printf("After swap Number 1 is : %d and Number 2 is : %d\n", a, b);
    
    return 0;
}

// Swap function definition
void swap(int* num1, int* num2) {
    // Verify pointers are not NULL
    assert(num1 != NULL && num2 != NULL);
    
    // Standard swap algorithm
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}