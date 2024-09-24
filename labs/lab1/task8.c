#include <stdio.h> // работа с файлами
#include <stdlib.h>
#include <string.h> // работа со строками
int main() {
    char filename[100], info[100];
    FILE *fp, *temp; // указатель на файл, хранение его имени и содержимого
    printf("Введите имя файла: ");
    scanf("%s", filename);
    printf("Введите информацию для добавления в начало: ");
    scanf(" %[^\n]", info); // Считываем информацию, включая пробелы
    fclose(fp); // закрытие файла
    // Открываем файл для чтения
    fp = fopen(filename, "r");
    // Открываем временный файл для записи
    temp = fopen("temp.txt", "w");
    // Записываем информацию в начало временного файла
    fprintf(temp, "%s\n", info);
    // Копируем содержимое исходного файла в временный файл
    char line[256];
    while (fgets(line, sizeof(line), fp) != NULL) {
        fprintf(temp, "%s", line);
    }
    // Закрываем файлы
    fclose(fp);
    fclose(temp);
    printf("Информация добавлена в начало файла %s.\n", filename);
    // Выводим содержимое файла в консоль
    printf("\nСодержимое файла %s:\n", filename);
    fp = fopen(filename, "r");
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }
    fclose(fp);
    return 0;
}
