#include <stdio.h> // ввод-вывод
#include <stdlib.h> // стандартные функции
#include <time.h> // работа с временем

int compare(const void *a, const void *b) {
// функция для сортировки, принимающая два элемента массива (границы) //
    float num1 = *(const float *)a;
// преобразует в float и заменяет имя элем на num1, мы указываем на элем а, не имеющий типа
    float num2 = *(const float *)b; // преобразует в float и заменяет имя элем на num2
    return (num1 > num2) - (num1 < num2);
// если равенство в скобке выполняется, то возвращается 0, таким образом мы сравниваем элем-ы //
}

float* createRandomArray(int size, float arg1, float arg2) { // создание случайного массива, принмает размер и два числа (диапазон)
    float *array = malloc(size * sizeof(float));
//malloc выделяет блок памяти size * sizeof(float), size - кол-во элем масс,
sizeof(float) возвращает размер одного элем в байтах //
    
    for (int i = 0; i < size; i++) {
        array[i] = arg1 + ((float)rand() / RAND_MAX) * (arg2 - arg1);
// генерируется случайное число [0; RAND_MAX], приводится к float,
((float)rand() / RAND_MAX) нормируем число к [0;1], умножив на диапазон получаем
число в [0, arg2 - arg1], прибавляем arg1, чтобы получить число в [arg1, arg2] //
    }
    
    return array; // возвращает указатель на массив
}

void writeArrayToFile(const char *filename, float *array, int size) {
// функция для записи массива в файл, принимает имя файла, массив и его размер //
    FILE *file = fopen(filename, "w");

    for (int i = 0; i < size; i++) {
        fprintf(file, "%.2f\n", array[i]); // запись каждого элемента массива файла с точностью 0,01
    }

    fclose(file);
}

int main(int argc, char *argv[]) { // принимает кол-во арг команд строки и массив строковых арг
    if (argc != 4) {
        fprintf(stderr, "Использование: %s <size> <arg1> <arg2>\n", argv[0]);
// если не введено имя программы и 3 арг, то выдаст ошибку, stderr - стандартный поток
ошибок, %s заменится на argv[0], содержащий имя программы, fprintf - запись в поток ошибок,
3 аргумента вводятся пользователем //
        return 1;
    }

    int size = atoi(argv[1]); // преобразование строкового арг в целое число
    float arg1 = atof(argv[2]); // преобразование строкового арг в float
    float arg2 = atof(argv[3]); // преобразование строкового арг в float

    srand(time(NULL));
    // инициализация генератора случайных чисел,
    возвращает время с начала эпохи, stand
    устанавливает изначальное значение, это
    все позволяет генерировать разные последовательности //

    float *array = createRandomArray(size, arg1, arg2); // вызов функции для создания массива случайных чисел

    printf("Сгенерированный массив:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");

    qsort(array, size, sizeof(float), compare);
// вызов функции сортировки массива, sizeof(float) - размер
одного элем в байтах, compare - указатель на функцию сортировки //

    writeArrayToFile("sorted_array.txt", array, size); // запись массива в файл

    free(array); // освобождение памяти, выделенной под массив

    return 0;
}
