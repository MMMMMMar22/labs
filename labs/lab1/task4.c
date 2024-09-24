#include <stdio.h>
int main() {
    float a, b, c, x;
    printf("a: ");
    scanf("%f", &a);
    printf("b: ");
    scanf("%f", &b);
    printf("c: ");
    scanf("%f", &c); //&c - какой переменной будет присвоено занчение
    x = (c - b) / a;
    printf("Решение: x=%.6f\n", x); - вывод числа типа float с 6 знаками после запятой
}
