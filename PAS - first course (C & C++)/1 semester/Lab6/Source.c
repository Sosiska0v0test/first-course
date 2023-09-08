//Лабораторна робота №6. Проектування алгоритмів і програм циклічної структури
//(цикли з параметром, передумовою і післяумовою).Робота з дійсними числами.
/* Підключення бібліотек;*/
#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int main() {
    system("chcp 1251 & cls");
    double x1, x2, h, // границі проміжка і крок
        a, b, x, // параметри a і b і змінна х
        an, s, // степінь числа, сума
        res; // обчислене значення функції
    double eps = 1e-22; // точність обчислень
    char r1[20] = "-------------------", // риска 19
        r2[20] = "|   x   |   f(x)   ", // заголовки колонок 19
        r3[20] = "|       |          ", // порожні клітинки 19
        rline[78] = ""; //границя таблиці — риска 77
    int ind, // чи правильно задано вхідні дані
        i, // номер обчисленого значення
        k,
        n;
    printf("Табулювання функції:\n");
    printf("\tf(x)=ln(x)+3 / x-a * s + sqrt(b-x) \n");// виведення вигляду функції
    ind = 1;
    do {
        printf("Вкажіть кількість колонок таблиці (від 1 до 4):");
        scanf_s("%d", &k);
        while (getchar() != '\n'); // очистка буфера ввод
        if (k >= 1 && k <= 4) ind = 0;
        else printf("***Неправильна кількість колонок\n");
    } while (ind);
    ind = 1;
    do {
        printf("Вкажіть\n \tПроміжок х1, х2:");
        scanf_s("%lf", &x1);
        scanf_s("%lf", &x2);
        while (getchar() != '\n'); // очистка буфера ввод
        if (x1 < x2) ind = 0;
        else printf("***Помилка x1>x2\n");
    } while (ind);
    ind = 1;
    do {
        printf("\tкрок h:");
        scanf_s("%lf", &h);
        while (getchar() != '\n'); // очистка буфера ввод
        if (h <= 0 || h > (x2 - x1)) { printf("***Помилка: h>x2-x1 або h<=0\n"); }
        else  ind = 0;
    } while (ind);
    printf("\tзначення параметрів a i b: ");
    scanf_s("%lf %lf", &a, &b);
    while (getchar() != '\n'); // очистка буфера вводу
    // виведення шапки таблиці
    for (i = 1; i <= k; i++) {
        printf("%s", r1);
    }
    printf("-\n");
    for (i = 1; i <= k; i++) {
        printf("%s", r2);
    }
    printf("|\n");
    for (i = 1; i <= k; i++) {
        printf("%s", r1);
    }
    printf("-\n");
    // обрахунок значення функції та заповнення таблиці
    x = x1; i = 0;
    while (x <= x2 + eps) {
        printf("|%6.2f ", x);
        if (x < eps || fabs(x - a) < eps || b - x < 0) {
            printf("| не визн  ");
        }
        else {
            s = 0;
            an = 4;
            for (n = 3; n <= 5; n++) {
                an *= 2;
                s += (an + x) / (n - 2);
            }
            res = (log(x) + 3) / (x - a) * s + sqrt(b - x);
            if (fabs(res) > 9999.99) {
                printf(("|  переп   "));
            }
            else {
                printf("| %8.2f ", res);
            }
        }
        i++;
        if (i % k == 0) {
            printf("|\n");
        }
        x += h;
    }
    if (i % k != 0) {
        while (i % k != 0) {
            printf("%s", r3);
            i++;
        }
        printf("|\n");
    }
    for (i = 0; i < k; i++) {
        printf("%s", r1);
    }
    printf("-\n\n");
    system("pause & cls");
    return 0;
}
