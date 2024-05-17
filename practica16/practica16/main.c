#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h> // Включаем заголовочный файл для использования setjmp и longjmp
#include "student.h"
#include "node.h"

// Объявляем глобальную переменную для хранения информации о исключении
jmp_buf exception_env;

// Функция для обработки ошибок
void handle_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    longjmp(exception_env, 1); // Возвращаемся к точке longjmp
}

int main() {
    // Устанавливаем точку, куда вернуться при обнаружении ошибки
    if (setjmp(exception_env) == 0) {
        struct Node* head = NULL;

        struct Student student1 = {"Ivanov", "Ivan", 'M', 20, "Group 1", 4, 3, 5};
        struct Student student2 = {"Petrov", "Petr", 'M', 21, "Group 2", 3, 4, 5};

        append(&head, &student1);
        append(&head, &student2);

        printf("Initial information of students in the list:\n");
        print_list(head);

        printf("\nIncreasing physics grade for all students...\n");

        struct Node* current = head;
        while (current != NULL) {
            increase_physics_grade(&(current->data));
            current = current->next;
        }

        printf("\nUpdated information of students in the list:\n");
        print_list(head);

        // Save the list to a file
        save_students_to_file("students.dat", head);

        // Free the list
        free_list(head);
        head = NULL;

        // Load the list from the file
        head = load_students_from_file("students.dat");

        printf("\nLoaded information of students from file:\n");
        print_list(head);

        free_list(head);

        return 0;
    } else {
        // Обработка ошибки
        printf("An error occurred. Exiting.\n");
        return 1;
    }
}
