
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {
	double x, 
		eps, 
		an,  
		s,  
		f;  
	int k,  
		n,  
		ind; 
	char vidp;
	system("chcp 1251 & cls");
	printf("Ôóíêö³ÿ f = (e^x - 1)\n");
	printf("Ðÿä E(n=0... +00)(x^n+1)/(n+1)!) ïðè õ º [-10, 10]\n");

	do {
		
		ind = 1;
		do {
			printf(" ââåä³òü x: ");
			scanf_s("%lf", &x);
			fseek(stdin, 0, SEEK_END); 
			if (x < -10 || x > 10) printf("\t íåâ³ðíå çíà÷åííÿ x(Ïîçà ïðîì³æêîì)\n");
			else ind = 0;
		} while (ind);
		
		ind = 1;
		do {
			printf("Ââåä³òü eps: ");
			scanf_s("%lf", &eps);
			fseek(stdin, 0, SEEK_END); 
			if (eps <= 0) printf("\t íåâ³ðíå çíà÷åííÿ eps (íå ìîæå áóòè <=0)\n");
			else ind = 0;
		} while (ind);
		//Çíà÷åííÿ k
		ind = 1;
		do {
			printf("Ââåä³òü k: ");
			scanf_s("%d", &k);
			fseek(stdin, 0, SEEK_END); 
			if (k <= 0) printf("\t íåâ³ðíå çíà÷åííÿ k (íå ìîæå áóòè <=0)\n");
			else ind = 0;
		} while (ind);
		
		n = 0;
		an = x; 
		s = an;
		do {
			n++;
			an *= x / (n + 1); 
			s += an;
		} while (fabs(an) >= eps && n < k);
		
		if (n == k)
			printf("Äîñÿãíóòî ë³ì³òó ê³ëüêîñò³ ³òåðàö³é\n");
		printf("Ðåçóëüòàò: \n");
		printf("Ê³ëüê³ñòü ³òåðàö³é n = %d\n", n);
		printf("Íàáëèæåíå çíà÷åííÿ ôóíêö³¿ s=%0.9f\n", s);
		
		f = exp(x) - 1;
		printf("Òî÷íå çàå÷åííÿ ôóíêö³¿ f = %0.9f\n", f);
		printf("Ïîõèáêà |f-s| = %0.9f\n", fabs(f - s));
		fseek(stdin, 0, SEEK_END); 
		printf(" Ïðîäîâæèòè ðîáîòó ( Y - Òàê)?");
		while ((vidp = getchar()) == ' ' || vidp == '\n' || vidp == '\t');
		
		fseek(stdin, 0, SEEK_END);
	} while (vidp == 'Y' || vidp == 'y' || vidp == 'T' || vidp == 'ò');
	printf("\n\n");
	system("pause & cls");
	return 0;
}

