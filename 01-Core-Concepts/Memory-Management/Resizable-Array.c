#include <stdio.h>
#include <stdlib.h>

int main(void) {

    const int CAPACITY = 5;
    int newCapacity = 5;
    int i = 0;
    char *name = (char*)malloc(CAPACITY);

    if (name == NULL) {
        printf("Memory allocation error!\n");
        return 1;
    }
    printf("Enter your name : ");
    char input;
    while ((input = getchar()) != '\n') {
        if ((i + 1) >= newCapacity)
        {
            newCapacity += CAPACITY;
            char* temp = (char*)realloc(name, newCapacity);

            if (temp == NULL) {
                printf("Memory allocation error!\n");
                free(name);
                return 1;
            }
            name = temp;
        }
        name[i] = input;
        i++;
    }
    name[i] = '\0';
    printf("Your name: %s\nThe length of your name: %d\nSize of capacity %d\n", name, i, newCapacity);
    free(name);
    return 0;
}
