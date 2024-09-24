#include <stdio.h>
int main(int argc, char *argv[]) { //массив массивов, целые числа
  if (argc <2) { тк num3 нулевой элемент
    printf("Нет аргументов для вывода.\n"); // переход на новую строку
    return 1; //стандарт
    }
  printf("Количество аргументов: %d\n", argc - 1);
  printf("Аргументы для вывода:\n");
  for (int i = 1; i < argc; i++) { // итерирование
    printf("%d: %s\n", i, argv[i]); // вывод число, строка
  }
  return 0; //стандарт
}
