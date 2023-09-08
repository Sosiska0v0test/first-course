//Лабораторна робота №8 "Алгоритми модульної структури"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void vvid(double* x, double* eps, int* ki);
double fiter(double x, double eps, int ki, int* n);
double ftoch(double x);
void vyvid(int ki, double s, double f, int n);
int main() {
	double x, //змінна х
		eps,  //значення похибки
		s,    //сума ряду
		f;    //значення функції
	int ind,  //індикатор
		n,    //кількість ітерацій
		ki;   //обмежена кількість кроків
	char vidp; // Відповідь користувача на ? чи треба запускати алгоритм ще раз
	system("chcp 1251 & cls");
	do {
		printf("\nФункція: f(x) = e^x - 1\n");
		printf("Ряд E: (x^(n+1))/(n+1)!  при x є [-10; 10]\n");
		vvid(&x, &eps, &ki);
		s = fiter(x, eps, ki, &n, &s);
		f = ftoch(x);
		vyvid(ki, s, f, n);
		printf("\nПродовжувати роботу (Y - так)? ");
		while ((vidp = getchar()) == ' ' || vidp == '\n' || vidp == '\t');
		fseek(stdin, 0, SEEK_END);
	} while (vidp == 'Y' || vidp == 'y' || vidp == 'Т' || vidp == 'т');

	return 0;
}
//Параметри за адресою, щоб змінити їх в середині функції
void vvid(double* x, double* eps, int* ki) { //double* x - начення х, double* eps - мінімальне значення члену ряду
	//ki - максимальна доступна кількість ітерацій
	int ind; // змінна для перевірки проміжків
	// ind -  локальна змінна
	ind = 1;
	//введення х
	while (ind) {
		printf(" введіть x ");
		scanf_s("%lf", x);
		fseek(stdin, 0, SEEK_END);
		if (*x < -10 || *x > 10) printf("\tневірне значення x\n");
		else ind = 0;
	}
	//введення eps
	ind = 1;
	while (ind) {
		printf(" введіть eps ");
		scanf_s("%lf", eps);
		fseek(stdin, 0, SEEK_END);
		if (*eps <= 0) printf("\teps має бути >0\n");
		else ind = 0;
	}
	//введення kі
	ind = 1;
	while (ind) {
		printf(" введіть kі ");
		scanf_s("%d", ki);
		fseek(stdin, 0, SEEK_END);
		if (*ki <= 0) printf("\tгранична кількість ітерацій має бути >0\n");
		else ind = 0;
	}
}//Обчислення загального степеневого ряду
double fiter(double x, double eps, int ki, int* n)
//x, eps та ki передаються за значенням 
//для використання в обчисленнях
//int ki - саксимальна допустима кількість ітерацій
//n - для підрахунку кількості ітерацій, 
//щоб підрахувати кількість ітерацій 
{
	double an, s; //an n-ий член суми, змінна для обчислення наступного члена ряду
	//an передається за адресою. an локальна змінна.
	//s - передається за адресою, локальна змінна
	*n = 0;
	an = x; //перший член ряду
	s = an;
	do {
		//Обчислення наступного члену ряду за рекурентною формулою
		(*n)++; //Номер ітерації(рекурсивного виклику)
		an *= x / (*n + 1);
		s += an;
	} while ((fabs(an) >= eps) && *n < ki); //умова продовження рекурсії
	return s;
}
//обчислення функції
double ftoch(double x) { //Параметр х передається за значенням
	return exp(x) - 1;
}
void vyvid(int ki, double s, double f, int n) { //ki, s, f, n -  передаються за значенням
	//ki - максимальна кількість ітерацій
	//s - значення функції, обчислення ітерації
	//f - точне значення функції
	//n - кількість ітерацій
	if (n == ki)
		printf("досягнуто ліміту кількості ітерацій\n");
	printf("\nрезультат:\n");
	printf("  кількість ітерацій n= %d\n", n);
	printf("  наближене значення функції s= %0.9f\n", s);
	printf("  точне значення функції f= %0.9f\n", f);
	printf("  похибка |f-s|= %0.9f\n", fabs(f - s));
}
