#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void append(struct Node** head_ref, struct Student* student) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = *student;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    struct Node *last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void print_list(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        print_student(&(current->data));
        current = current->next;
    }
}

void free_list(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

void save_students_to_binary_file(struct Node* head, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Could not open file %s for writing\n", filename);
        perror("Error");
        return;
    }

    struct Node* current = head;
    int count = 0;
    while (current != NULL) {
        size_t written = fwrite(&(current->data), sizeof(struct Student), 1, file);
        if (written != 1) {
            printf("Error writing student %s %s to file\n", current->data.surname, current->data.name);
            perror("Error");
        } else {
            printf("Successfully wrote student %s %s to file\n", current->data.surname, current->data.name);
        }
        current = current->next;
        count++;
    }

    fclose(file);
    printf("File %s saved successfully with %d students.\n", filename, count);
}

struct Node* load_students_from_binary_file(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Could not open file %s for reading\n", filename);
        perror("Error");
        return NULL;
    }

    struct Node* head = NULL;
    struct Student student;
    int count = 0;

    printf("Loading students from binary file...\n");
    while (fread(&student, sizeof(struct Student), 1, file) == 1) {
        append(&head, &student);
        printf("Loaded student: %s %s\n", student.surname, student.name);
        count++;
    }

    if (feof(file)) {
        printf("Reached end of file.\n");
    } else if (ferror(file)) {
        printf("Error reading file %s\n", filename);
        perror("Error");
    }

    fclose(file);
    printf("Loaded %d students from %s.\n", count, filename);
    return head;
}
