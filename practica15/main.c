#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "node.h"

int main() {
    struct Node* head = NULL;

    FILE* file = fopen("students.bin", "rb");
    if (file) {

        fclose(file);
        printf("Loading data from students.bin...\n");
        head = load_students_from_binary_file("students.bin");
    } else {

        printf("File students.bin does not exist. Creating initial data...\n");
        struct Student student1 = {"Ivanov", "Ivan", 'M', 20, "Group 1", 4, 3, 5};
        struct Student student2 = {"Petrov", "Petr", 'M', 21, "Group 2", 3, 4, 5};

        append(&head, &student1);
        append(&head, &student2);

        printf("Initial information of students in the list:\n");
        print_list(head);

        save_students_to_binary_file(head, "students.bin");
    }

    if (head == NULL) {
        printf("No students to display.\n");
        return 0;
    }

    printf("\nIncreasing physics grade for all students...\n");

    struct Node* current = head;
    while (current != NULL) {
        increase_physics_grade(&(current->data));
        current = current->next;
    }

    printf("\nUpdated information of students in the list:\n");
    print_list(head);

    save_students_to_binary_file(head, "students.bin");

    free_list(head);

    return 0;
}
