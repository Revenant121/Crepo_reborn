#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "node.h"

int main() {
    struct Node *head = NULL;

    load_students_from_file(&head, "students.bin");

    struct Student *student1 = (struct Student *)studentInit("Ivanov", "Ivan", "M", 20, 101, 5.0, 4.5, 4.0);
    struct Node *new_node1 = (struct Node *)malloc(sizeof(struct Node));
    new_node1->data = *student1;
    new_node1->next = head;
    head = new_node1;

    struct Student *student2 = (struct Student *)studentInit("Petrov", "Petr", "M", 21, 102, 4.5, 4.0, 3.5);
    struct Node *new_node2 = (struct Node *)malloc(sizeof(struct Node));
    new_node2->data = *student2;
    new_node2->next = head;
    head = new_node2;

    save_students_to_file(head, "students.bin");

    while (head != NULL) {
        struct Node *temp = head;
        head->data.infoOutput(&(head->data));
        head = head->next;
        free(temp);
    }

    free(student1);
    free(student2);

    return 0;
}
