
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void vvid(double* x, double* eps, int* ki);
double fiter(double x, double eps, int ki, int* n);
double ftoch(double x);
void vyvid(int ki, double s, double f, int n);
int main() {
	double x, 
		eps,  
		s,   
		f;    
	int ind, 
		n,   
		ki;   
	char vidp;
	system("chcp 1251 & cls");
	do {
		printf("\nÔóíêö³ÿ: f(x) = e^x - 1\n");
		printf("Ðÿä E: (x^(n+1))/(n+1)!  ïðè x º [-10; 10]\n");
		vvid(&x, &eps, &ki);
		s = fiter(x, eps, ki, &n, &s);
		f = ftoch(x);
		vyvid(ki, s, f, n);
		printf("\nÏðîäîâæóâàòè ðîáîòó (Y - òàê)? ");
		while ((vidp = getchar()) == ' ' || vidp == '\n' || vidp == '\t');
		fseek(stdin, 0, SEEK_END);
	} while (vidp == 'Y' || vidp == 'y' || vidp == 'Ò' || vidp == 'ò');

	return 0;
}

void vvid(double* x, double* eps, int* ki) { 
	int ind; 
	
	ind = 1;
	
	while (ind) {
		printf(" ââåä³òü x ");
		scanf_s("%lf", x);
		fseek(stdin, 0, SEEK_END);
		if (*x < -10 || *x > 10) printf("\tíåâ³ðíå çíà÷åííÿ x\n");
		else ind = 0;
	}

	ind = 1;
	while (ind) {
		printf(" ââåä³òü eps ");
		scanf_s("%lf", eps);
		fseek(stdin, 0, SEEK_END);
		if (*eps <= 0) printf("\teps ìàº áóòè >0\n");
		else ind = 0;
	}

	ind = 1;
	while (ind) {
		printf(" ââåä³òü k³ ");
		scanf_s("%d", ki);
		fseek(stdin, 0, SEEK_END);
		if (*ki <= 0) printf("\tãðàíè÷íà ê³ëüê³ñòü ³òåðàö³é ìàº áóòè >0\n");
		else ind = 0;
	}
}
double fiter(double x, double eps, int ki, int* n)

{
	double an, s; 
	
	*n = 0;
	an = x; 
	s = an;
	do {
		
		(*n)++; 
		an *= x / (*n + 1);
		s += an;
	} while ((fabs(an) >= eps) && *n < ki);
	return s;
}

double ftoch(double x) { 
	return exp(x) - 1;
}
void vyvid(int ki, double s, double f, int n) { 
	
	if (n == ki)
		printf("äîñÿãíóòî ë³ì³òó ê³ëüêîñò³ ³òåðàö³é\n");
	printf("\nðåçóëüòàò:\n");
	printf("  ê³ëüê³ñòü ³òåðàö³é n= %d\n", n);
	printf("  íàáëèæåíå çíà÷åííÿ ôóíêö³¿ s= %0.9f\n", s);
	printf("  òî÷íå çíà÷åííÿ ôóíêö³¿ f= %0.9f\n", f);
	printf("  ïîõèáêà |f-s|= %0.9f\n", fabs(f - s));
}
