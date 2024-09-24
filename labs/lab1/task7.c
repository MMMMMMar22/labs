#include <stdio.h>
#include <stdlib.h>
void displayFileContent(const char *filename) {
    FILE *file = fopen(filename, "r");
    char line[256];
    printf("Содержимое файла '%s':\n", filename);
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}
int main() {
    const char *filename = "example.txt"; // Имя файла
    char newLine[256]; // Массив для новой строки
    // Вывод содержимого файла до изменений
    printf("Содержимое файла перед изменениями:\n");
    displayFileContent(filename);
    // Запрашиваем новую строку у пользователя
    printf("Введите строку для добавления в конец файла: ");
    scanf(" %[^\n]", newLine); // Считываем строку
    // Открываем файл для добавления данных
    FILE *file = fopen(filename, "a"); // Режим "a" - добавление в конец
    fprintf(file, "%s\n", newLine); // Записываем новую строку в файл
    fclose(file); // Закрываем файл после записи
    // Вывод содержимого файла после изменений
    printf("\nСодержимое файла после изменений:\n");
    displayFileContent(filename);
    return 0;
}
