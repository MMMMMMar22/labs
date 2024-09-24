#include <stdio.h> // для работы с файлами
#include <stdlib.h>
#define MAX_LINE_LENGTH 256 // значение константы, макс длина строки
void copy_first_three_lines(const char *input_filename, const char *output_filename) { // void - функция не возвращает никакое значение, указатели на имена входного и выходного файлов
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");
    char line[MAX_LINE_LENGTH]; // создаем массив для хранения строки
    int line_count = 0; // объявляем счетчик
    while (fgets(line, sizeof(line), input_file) != NULL && line_count < 3) { // читаем строку и храним в line, если конец файла не достигнут и кол-во строк меньше 3, то продолжаем цикл
        fputs(line, output_file); // запись строки из line в output
        line_count++;
    }
}
void print_file_contents(const char *filename) { // const char *filename указание на строку, содержащую имя файла. функция не будет изменять содержимое строки
    FILE *file = fopen(filename, "r");
    char line[MAX_LINE_LENGTH]; // объявляем массив символов фиксированной длины для хранения строки
    while (fgets(line, sizeof(line), file) != NULL) { // читаем строку и храним ее в массиве line с заданным размером во избежание переполнения, и так пока не будет достигнут конец файла
        printf("%s", line); // вывод строки
    }
}
int main() {
    const char *input_filename = "input.txt"; // имя входного файла
    const char *output_filename = "output.txt"; // имя выходного файла
    copy_first_three_lines(input_filename, output_filename); // копируем первые 3 строки из входного файла в выходной файл
    printf("Содержимое входного файла:\n");
    print_file_contents(input_filename);
    printf("\nСодержимое выходного файла:\n");
    print_file_contents(output_filename);
}
