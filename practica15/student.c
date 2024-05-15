#include "student.h"
#include <stdlib.h>
#include <string.h>

void* infoOutput(void*);
void* saveToBinary(void*);

void* studentInit(void *surname, void *name, void *sex, int age, int group, float mathMark, float physicsMark, float chemistryMark) {
    struct Student* result = (struct Student*)malloc(sizeof(struct Student));
    if (result == NULL) {
        printf("Memory allocation error for student.\n");
        return NULL;
    }

    if (surname != NULL)
        result->surname = strdup((char*)surname);
    else
        result->surname = NULL;

    if (name != NULL)
        result->name = strdup((char*)name);
    else
        result->name = NULL;

    if (sex != NULL)
        result->sex = strdup((char*)sex);
    else
        result->sex = NULL;

    result->age = age;
    result->group = group;
    result->mathMark = mathMark;
    result->physicsMark = physicsMark;
    result->chemistryMark = chemistryMark;
    result->infoOutput = infoOutput;
    result->saveToBinary = saveToBinary;
    return result;
}

void* infoOutput(void* student) {
    if (student == NULL) {
        perror("Error: null pointer passed for student");
        return NULL;
    }

    struct Student* s = (struct Student*)student;
    printf("Surname: %s\n", s->surname);
    printf("Name: %s\n", s->name);
    printf("gender: %s\n", s->sex);
    printf("Age: %d\n", s->age);
    printf("Group: %d\n", s->group);
    printf("Math Mark: %.1f\n", s->mathMark);
    printf("Physics Mark: %.1f\n", s->physicsMark);
    printf("Chemistry Mark: %.1f\n", s->chemistryMark);
    printf("\n");
    return NULL;
}

void* saveToBinary(void* student) {
    if (student == NULL) {
        perror("Error: null pointer passed for student");
        return NULL;
    }

    struct Student* _student = (struct Student*)student;
    FILE* fp = fopen("/Users/egorkirichenko/Projects/C/15bin/data.bin", "ab");

    if (fp == NULL) {
        perror("Error opening file!");
        return NULL;
    }

    int surnameSize = strlen(_student->surname);
    int nameSize = strlen(_student->name);
    int sexSize = strlen(_student->sex);

    fwrite(&surnameSize, sizeof(int), 1, fp);
    fwrite(_student->surname, sizeof(char), surnameSize, fp);
    fwrite(&nameSize, sizeof(int), 1, fp);
    fwrite(_student->name, sizeof(char), nameSize, fp);
    fwrite(&sexSize, sizeof(int), 1, fp);
    fwrite(_student->sex, sizeof(char), sexSize, fp);
    fwrite(&_student->age, sizeof(int), 1, fp);
    fwrite(&_student->group, sizeof(int), 1, fp);
    fwrite(&_student->mathMark, sizeof(float), 1, fp);
    fwrite(&_student->physicsMark, sizeof(float), 1, fp);
    fwrite(&_student->chemistryMark, sizeof(float), 1, fp);

    fclose(fp);

    return NULL;
}

void save_students_to_file(struct Node *head, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    struct Node *current = head;
    while (current) {
        fwrite(&(current->data), sizeof(struct Student), 1, file);
        current = current->next;
    }

    fclose(file);
}
/
void load_students_from_file(struct Node **head_ref, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    struct Student student;
    while (fread(&student, sizeof(struct Student), 1, file)) {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        if (!new_node) {
            printf("Memory allocation error for new node\n");
            fclose(file);
            return;
        }
        new_node->data = student;
        new_node->next = *head_ref;
        *head_ref = new_node;
    }

    fclose(file);
}
