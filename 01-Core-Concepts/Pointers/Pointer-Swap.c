#include <stdio.h>

void swap(int* num1, int* num2);
int main(void) {
    int a;
    int b;
    printf("Enter Number 1 : ");
    scanf("%d", &a);
    printf("Enter Number 2 : ");
    scanf("%d", &b);
    swap(&a, &b);
    printf("After swap Number 1 is : %d and Number 2 is : %d" , a,b);
    return 0;
}
void swap(int* num1, int* num2){
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}