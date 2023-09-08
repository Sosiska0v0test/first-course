//Лабораторна робота №9 "Рекурсивні алгоритми"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void vvid_x(double* x);
void vvid_eps(double* eps);
void vvid_k(int* k);
double fiter(double x, double eps, int k, int* n);
double ftoch(double x);
void vyvid(int k, double s, double f, int n);
double recursive(int* n, double x, double an, double eps, int k);

int main() {
	double eps,  // мінімальне граничне значення
		x,       // змінна х
		an,      // змінна для рекурентної формули
		f,		 // точне значення функції
		s;       // значення суми (приблизне)
	int k,       // кількіть кроків
		//ind,   // змінна для перевірки правельності вводу даних
		n;       // лічільник кількості рукурсивних обрахунків 
	char vidp;   // змінна для повторного виконання роботи
	system("chcp 1251 & cls");
	do {
		printf("Функція:  e^x - 1\n");
		printf("Ряд Е :  (x^(n+1))/(n+1)!\n");
		vvid_x(&x);
		vvid_eps(&eps);
		vvid_k(&k);
		s = fiter(x, eps, k, &n);
		f = ftoch(x);
		vyvid(k, s, f, n);
		printf("\nПродовжувати роботу (Y - так)? ");
		while ((vidp = getchar()) == ' ' || vidp == '\n' || vidp == '\t');
		fseek(stdin, 0, SEEK_END);
	} while (vidp == 'Y' || vidp == 'y' || vidp == 'Т' || vidp == 'т');
	printf("\n\n");
	system("pause");
	return 0;
}
/* Введення значення x */
void vvid_x(double* x) {
	printf(" введіть x ");   //x - значення змінної
	scanf_s("%lf", x);
	fseek(stdin, 0, SEEK_END);
	if (*x < -10 || *x > 10) {
		printf("\tневірне значення x\n");
		vvid_x(x);
	}
}
/* Введення значення eps */
void vvid_eps(double* eps) {
	printf(" введіть eps ");  //порогове число
	scanf_s("%lf", eps);
	fseek(stdin, 0, SEEK_END);
	if (*eps <= 0) {
		printf("\teps має бути >0\n");
		vvid_eps(eps);
	}
}
/* Введення значення k */
void vvid_k(int* k) {
	printf(" введіть k ");    //кількість кроків
	scanf_s("%i", k);
	fseek(stdin, 0, SEEK_END);
	if (*k < 0) {
		printf("\tгранична кількість ітерацій має бути >0\n");
		vvid_k(k);
	}
}
/* Обчислення наближеного значення функції sin(x) */
double fiter(double x, double eps, int k, int* n) {
	*n = 0; // при n=0 перший член ряду a0=x, 
	// початкове значення суми s=a0=x,
	return x + recursive(n, x, x, eps, k);
}
// Рекурсивне обчислення значення функції
double recursive(int* n, double x, double an, double eps, int k) {
	double s; // накопичує результат обчислення
	(*n)++;   // номер ітерації (рекурсивного виклику)
	/* Обчислюються наступні члени ряду */
	an *= x / (*n + 1);
	if (fabs(an) >= eps && (*n) < k)     // умова продовження рекурсії
		s = recursive(n, x, an, eps, k); // рекурсивне звернення
	else
		s = 0; // щоб при останньому зануренні повернути тільки an
	return s + an;
}
double ftoch(double x) {
	return exp(x) - 1;
}
//Виведення результатів 
void vyvid(int k, double s, double f, int n) {
	if (n == k)
		printf("досягнуто ліміту кількості ітерацій\n");
	printf("\nрезультат:\n");
	printf("  кількість ітерацій n = %d\n", n);
	printf("  наближене значення функції s = %0.9f\n", s);
	printf("  точне значення функції f = %0.9f\n", f);
	printf("  похибка |f-s|= %0.9f\n", fabs(f - s));
}
