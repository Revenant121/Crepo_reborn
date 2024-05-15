#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define ROWS 9
#define COLS 5

// Функция для установки положительных элементов массива в ноль
void set_positive_to_zero(int numbers[], int size) {
    for (int i = 0; i < size; ++i) {
        if (numbers[i] > 0) {
            numbers[i] = 0;
        }
    }
}

// Функция для инициализации двумерного массива
void initialize_matrix(int matrix[][COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = 0; // Произвольное значение для каждой ячейки
        }
    }
}

// Функция для подсчета количества нулей в каждой третьей строке массива
void count_zeros_in_third_rows(int matrix[][COLS], int rows, int cols) {
    for (int i = 2; i < rows; i += 3) {
        int count_zeros = 0;
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                count_zeros++;
            }
        }
        printf("kolichestvo nulei v %d stroke: %d\n", i + 1, count_zeros);
    }
}

// Функция для проверки пересечения отрезков
void checkSegmentsIntersection() {
    float x1, x2, x3, x4, y1, y2, y3, y4, k1, k2, b1, b2, x_intersect, y_intersect;

    printf("Enter the coordinates of point A of segment 1: ");
    printf("Enter x: ");
    scanf("%f", &x1);
    printf("Enter y: ");
    scanf("%f", &y1);

    printf("Enter the coordinates of point B of segment 1: ");
    printf("Enter x: ");
    scanf("%f", &x2);
    printf("Enter y: ");
    scanf("%f", &y2);

    printf("Enter coordinates of point A1 of segment 2: ");
    printf("Enter x: ");
    scanf("%f", &x3);
    printf("Enter y: ");
    scanf("%f", &y3);

    printf("Enter the coordinates of point B2 of segment 2: ");
    printf("Enter x: ");
    scanf("%f", &x4);
    printf("Enter y: ");
    scanf("%f", &y4);

    k1 = (y2 - y1) / (x2 - x1);
    b1 = y1 - (k1 * x1);
    k2 = (y3 - y4) / (x4 - x3);
    b2 = y3 - (k2 * x3);

    if (k1 == k2) {
        if (b1 == b2)
            printf("The segments match \n");
        else
            printf("The segments are parallel and do not intersect \n");
    } else {
        x_intersect = (b2 - b1) / (k1 - k2);
        y_intersect = k1 * x_intersect + b1;

        if (((x1 <= x4) || (x4 <= x2)) || ((x1 <= x3) || (x3 <= x2)))
            printf("The segments intersect \n");
        else
            printf("The segments do not intersect \n");
    }
}

// Функция для ввода элементов массива
int* input_numbers(int n) {
    int *numbers = (int *)malloc(n * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    return numbers;
}

// Функция для вывода квадратов чисел
void print_squares(int *numbers, int n) {
    printf("Squares of the entered numbers:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i] * numbers[i]);
    }
    printf("\n");
}

// Функция для освобождения памяти, выделенной для массива чисел
void free_memory(int *numbers) {
    free(numbers);
}

int main() {
    // Пример работы с одномерным массивом
    int numbers[SIZE];
    srand(time(0)); // генератор случайных чисел

    printf("Random numbers:\n");
    for (int i = 0; i < SIZE; ++i) {
        numbers[i] = rand() % (100 - (-100) + 1) + (-100); // генерация случайного числа от -100 до 100
        printf("%d ", numbers[i]);
    }
    printf("\n");

    set_positive_to_zero(numbers, SIZE);

    printf("\nResult:\n");
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n\n");

    // Пример работы с двумерным массивом
    int matrix[ROWS][COLS];
    initialize_matrix(matrix, ROWS, COLS);
    count_zeros_in_third_rows(matrix, ROWS, COLS);

    // Пример работы с динамическим массивом
    int n; // Number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *dynamic_numbers = input_numbers(n);
    print_squares(dynamic_numbers, n);
    free_memory(dynamic_numbers);

    // Вызов функции проверки пересечения отрезков
    checkSegmentsIntersection();

    return 0;
}
