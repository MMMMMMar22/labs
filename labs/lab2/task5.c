#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100 // макс кол-во хранимых товаров
#define NAME_LENGTH 100 // макс длина названия товара

typedef struct {
// создаем новый тип данных и структуру, содержащую два поля //
    char name[NAME_LENGTH];
/* массив хранит название товара, NAME_LENGTH определяет
макс длину названия */
    float price; // цена товара
} Product; // новый тип данных назв товара + цена

void readProducts(const char *filename, Product products[], int *count) {
// считываем данные из файла, записываем в массив и считаем кол-во считанных строк //
    FILE *file = fopen(filename, "r");
    
    *count = 0; // кол-во считанных товаров
    while (fscanf(file, "%99s %f", products[*count].name, &products[*count].price) == 2) {
/* fscanf считываем данные из файла, %99s строки длинной
99 символов, последний - терминатор, %f тип данных для
цены товара, обращаемся к массиву по номерам *count,
записываем назв товара в поле name, == 2 это проверка, что
считаны оба элемента, ноль терминатор - обозначение
конца строки, обращаемся к товару, получаем его цену,
& - получение адреса переменной */

        (*count)++;
    }

    fclose(file);
}

int compareProducts(const void *a, const void *b) { // функия сортировки товаров
    Product *productA = (Product *)a;
// приводим указатели a и b к типу Product*
    Product *productB = (Product *)b;
    return (productA->price > productB->price) - (productA->price < productB->price);
// получаем доступ к ценам и сравниваем, возвращает отрицательное значение, если первый продукт дешевле
}

void writeProducts(const char *filename, Product products[], int count) {
    FILE *file = fopen(filename, "w");
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %.2f\n", products[i].name, products[i].price); // записываем данные в файл 
    }

    fclose(file);
}

int main() {
    Product products[MAX_PRODUCTS]; // массив товаров
    int count; // счетчик считанных товаров

    // Замените "input.txt" на имя вашего входного файла
    readProducts("num5_2.txt", products, &count);
/* считываем данные из входного файла, помещаем в массив
и считаем, сколько строк поместили */

    qsort(products, count, sizeof(Product), compareProducts);
/* вызываем стандартную функцию сортировки,
принимающую массив, кол-во элем и размер одного элем,
имя функции сравнения - compareProducts */

    // Замените "output.txt" на имя вашего выходного файла
    writeProducts("num5_2(2).txt", products, count);
// функция для записи отсортированных товаров в выходной файл

    return 0;
}
