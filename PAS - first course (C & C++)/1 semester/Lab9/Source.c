
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
	double eps,  
		x,      
		an,     
		f,		
		s;      
	int k,       
		n;      
	char vidp;   
	system("chcp 1251 & cls");
	do {
		printf("Ôóíêö³ÿ:  e^x - 1\n");
		printf("Ðÿä Å :  (x^(n+1))/(n+1)!\n");
		vvid_x(&x);
		vvid_eps(&eps);
		vvid_k(&k);
		s = fiter(x, eps, k, &n);
		f = ftoch(x);
		vyvid(k, s, f, n);
		printf("\nÏðîäîâæóâàòè ðîáîòó (Y - òàê)? ");
		while ((vidp = getchar()) == ' ' || vidp == '\n' || vidp == '\t');
		fseek(stdin, 0, SEEK_END);
	} while (vidp == 'Y' || vidp == 'y' || vidp == 'Ò' || vidp == 'ò');
	printf("\n\n");
	system("pause");
	return 0;
}
void vvid_x(double* x) {
	printf(" ââåä³òü x ");  
	scanf_s("%lf", x);
	fseek(stdin, 0, SEEK_END);
	if (*x < -10 || *x > 10) {
		printf("\tíåâ³ðíå çíà÷åííÿ x\n");
		vvid_x(x);
	}
}
void vvid_eps(double* eps) {
	printf(" ââåä³òü eps "); 
	scanf_s("%lf", eps);
	fseek(stdin, 0, SEEK_END);
	if (*eps <= 0) {
		printf("\teps ìàº áóòè >0\n");
		vvid_eps(eps);
	}
}
void vvid_k(int* k) {
	printf(" ââåä³òü k ");    
	scanf_s("%i", k);
	fseek(stdin, 0, SEEK_END);
	if (*k < 0) {
		printf("\tãðàíè÷íà ê³ëüê³ñòü ³òåðàö³é ìàº áóòè >0\n");
		vvid_k(k);
	}
}
double fiter(double x, double eps, int k, int* n) {
	*n = 0; 
	return x + recursive(n, x, x, eps, k);
}
double recursive(int* n, double x, double an, double eps, int k) {
	double s; 
	(*n)++;  

	an *= x / (*n + 1);
	if (fabs(an) >= eps && (*n) < k)    
		s = recursive(n, x, an, eps, k); 
	else
		s = 0; 
	return s + an;
}
double ftoch(double x) {
	return exp(x) - 1;
}
void vyvid(int k, double s, double f, int n) {
	if (n == k)
		printf("äîñÿãíóòî ë³ì³òó ê³ëüêîñò³ ³òåðàö³é\n");
	printf("\nðåçóëüòàò:\n");
	printf("  ê³ëüê³ñòü ³òåðàö³é n = %d\n", n);
	printf("  íàáëèæåíå çíà÷åííÿ ôóíêö³¿ s = %0.9f\n", s);
	printf("  òî÷íå çíà÷åííÿ ôóíêö³¿ f = %0.9f\n", f);
	printf("  ïîõèáêà |f-s|= %0.9f\n", fabs(f - s));
}
