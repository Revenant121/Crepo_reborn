///Лабораторная работа №8
///Тема: Рекурсивные функции.
///Вариант №11
///Оформить соответствующий вариант из лабораторной работы №2 в виде рекурсивных функций.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

// Функция для генерации случайных чисел в указанном диапазоне
int generateRandomNumber(int min, int max) {
return rand() % (max - min + 1) + min;
}

// Рекурсивная функция для обнуления положительных элементов массива
void G_recursive(int numbers[], int size, int index) {
if (index < size) {
if (numbers[index] > 0) {
numbers[index] = 0;
}
G_recursive(numbers, size, index + 1);
}
}

int main() {
int numbers[SIZE];

srand(time(0)); // Инициализация генератора случайных чисел

int min = -100;
int max = 100;

printf("Случайные числа:\n");
for (int i = 0; i < SIZE; ++i) {
numbers[i] = generateRandomNumber(min, max);
printf("%d ", numbers[i]);
}
printf("\n");

G_recursive(numbers, SIZE, 0);

printf("\nРезультат:\n");
for (int i = 0; i < SIZE; ++i) {
printf("%d ", numbers[i]);
}
printf("\n");

return 0;
}