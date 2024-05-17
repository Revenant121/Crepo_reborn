#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "node.h"  // Include node.h to get the definition of struct Node

void print_student(struct Student *student) {
    printf("Surname: %s\n", student->surname);
    printf("Name: %s\n", student->name);
    printf("Gender: %c\n", student->gender);
    printf("Age: %d\n", student->age);
    printf("Group: %s\n", student->group);
    printf("Math Grade: %d\n", student->math_grade);
    printf("Physics Grade: %d\n", student->physics_grade);
    printf("Chemistry Grade: %d\n", student->chemistry_grade);
    printf("\n");
}

void increase_physics_grade(struct Student *student) {
    if (student->physics_grade < 5) {
        student->physics_grade++;
    }
}


void save_students_to_file(const char *filename, struct Node *head) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Failed to open file for writing");
        exit(EXIT_FAILURE);
    }

    struct Node *current = head;
    while (current != NULL) {
        fwrite(&(current->data), sizeof(struct Student), 1, file);
        current = current->next;
    }

    fclose(file);
}

struct Node* load_students_from_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Failed to open file for reading");
        exit(EXIT_FAILURE);
    }

    struct Node *head = NULL;
    struct Student temp;

    while (fread(&temp, sizeof(struct Student), 1, file)) {
        append(&head, &temp);
    }

    fclose(file);
    return head;
}
