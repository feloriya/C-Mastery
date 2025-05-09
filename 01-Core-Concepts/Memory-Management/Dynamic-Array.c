#include <stdio.h>
#include <stdlib.h>

int main() {
    int sum = 0;
    int n;
    do {
    printf("Enter the number of numbers : ");
    scanf("%d", &n);
    } while (n < 1);
    
    int* userArray = (int*) malloc(n * sizeof(int));
    
    if (userArray == NULL) {
        printf("Memory allocation error!\n");
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        printf("Enter number %d : ", i + 1);
        scanf("%d", &userArray[i]);   
        sum += userArray[i];
    }
    printf("The average is : %.2f", (sum/(float)n));
    free(userArray);
    return 0;
}