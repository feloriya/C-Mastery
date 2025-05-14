#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findMax();
int main() {
    FILE *file;
    int snumber;
    char name[50];
    float score;
    
    file = fopen("students.txt", "w+");
    if (file == NULL) {
        printf("File creating error!\n");
        return 1;
    }
 
    printf("Enter the number of students: ");
    scanf("%d", &snumber);
    fprintf(file, "Number of student is: %d \n\n", snumber);
    getchar();

    for (int i = 0; i < snumber; i++) {
        printf("\nStudent %d\n", i+1);
        
        printf(" Name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';
        
        printf(" Score: ");
        scanf("%f", &score);
        getchar();
        
        fprintf(file, "Student %d \n - Name: %s\n - Score: %.2f\n\n", i+1, name, score);
    }

    fclose(file);
    printf("\n----------------------------");
    printf("\nAll data saved successfully!");
    printf("\n----------------------------");
    int flag = findMax();
    if (flag == 1) {
        printf("No student data found!\n");
    }
    return 0;
}

int findMax() {
    FILE *file;
    char name[50], top_names[10][50], line[100];
    float score, max_score = -1.0;
    int count = 0, top_count = 0;
    
    file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        if (sscanf(line, " - Name: %49[^\n]", name) == 1) {

        } else if (sscanf(line, " - Score: %f", &score) == 1) {
            if (score > max_score) {
                max_score = score;
                top_count = 0;
                strcpy(top_names[top_count++], name);
            } else if (score == max_score) {
                if (top_count < 10) {
                    strcpy(top_names[top_count++], name);
                }
            }
            count++;
        }
    }
    
    if (count > 0) {
        printf("\nHighest score: %.2f\n", max_score);
        printf("Students with this score:\n");
        for (int i = 0; i < top_count; i++) {
            printf("- %s\n", top_names[i]);
        }
    } else {
        printf("No valid student data found!\n");
    }
    
    fclose(file);
    return 0;
}