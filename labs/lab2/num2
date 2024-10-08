#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 15 //  Hазмер массива
#define MAX_RANDOM 1000 // максимальное значение для случайных чисел
void generateRandomArray(int arr[], int size) {
// принимает массив и кол-во элем в нем
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_RANDOM; // генерация случайного числа
// генерируем число и берем осток от деления, чтобы войти в диапазон
    }
}
void writeArrayInReverseToFile(const char *filename, int arr[], int size) {
// const char *filename указатель на неизм строку (имя файла)
    FILE *file = fopen(filename, "w");
    for (int i = size - 1; i >= 0; i--) {
        fprintf(file, "%d\n", arr[i]); // запись в файл в обратном порядке
        // %d - целое число
    }
    fclose(file);
}
int main() {
    int arr[ARRAY_SIZE]; // инициализация генератора случайных чисел
    srand(time(NULL));
/* инициализация генератора случайных чисел, возвращает время с начала
эпохи, stand устанавливает изначальное значение, это все позволяет
генерировать разные последовательности */
    generateRandomArray(arr, ARRAY_SIZE); // генерация случайного массива
// принимает массив и его размер
    writeArrayInReverseToFile("random_numbers.txt", arr, ARRAY_SIZE);
    printf("Массив случайных чисел записан в файл num_numbers.txt в обратном порядке.\n");
    return 0;
}
