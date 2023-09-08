
#include <stdio.h>  //<-- у програмі використовуються функції printf();
#include <math.h>  //<--Для виконання звичайних математичних операцій;
#include<stdlib.h> //<-- у програмі використовується функція перекладу на іншу мову system("chcp 1251 & cls")
//Декларативна частина

int main() {
	float x, a, temp;
	const float n = 3, n1 = 4; //в функції №1 є дві константи 3 і 4
	
	system("chcp 1251 & cls"); //Переклад рядка на кирилицю,   cls-не виводить на екран процеси процесора
	printf("f1(x,a) = ((ln(x)+3)^(1/2))/(3*x + a - 4) + (ctg(|x-4|))\n\n");//y-->f1
	printf("f2(x) = ((7/4)*x^3) - ((4/5)*x) + x*e^(3*tg*x)\n\n");//z-->f2
	printf("f3(x) = (7/8)*x^0,7\n\n");//t-->>f3
	printf("-----------------------------------------------------------------\n");

	printf("Введіть значення для параметра х:\n\n");
	scanf_s("%f", &x);

	printf("Введіть значення для параметра a:\n\n");
	scanf_s("%f", &a);
	
	double y = (sqrt(log10(x) + n)) / (n * x + a - n1) + cos(fabs(x - n1)) / sin(fabs(x - n1)); //y-->f1
	double z = 1.75 * pow(x, 3) - 0.8 * x + x * exp(-3 * tan(x)); //з мінімумом операцій //z-->f2
	double t = (double)0.875 * pow(x, 0.7); //t-->>f3
	
	printf("f1(x,a) = ((ln(x)+3)^(1/2))/(3*x + a - 4) + (ctg(|x-4|))=%.5f\n\n", y);
	printf("f2(x) = ((7/4)*x^3) - ((4/5)*x) + x*e^(3*tg*x)=%.5f\n\n", z);
	printf("f3(x) = (7/8)*x^0,7=%.5f\n\n", t);
 
	temp = y;
	y = z;
	z = t;
	t = temp;
	printf("\n Переприсвоєнні значення:\n\n y=%f \n z=%f \n t=%f \n\n", y, z, t);

	system("pause & cls");
	return 0;
}