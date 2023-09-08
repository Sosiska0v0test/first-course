
#include <stdio.h>  
#include <math.h>  
#include<stdlib.h> 

int main() {
	float x, a, temp;
	const float n = 3, n1 = 4; 
	
	system("chcp 1251 & cls"); 
	printf("f1(x,a) = ((ln(x)+3)^(1/2))/(3*x + a - 4) + (ctg(|x-4|))\n\n");//y-->f1
	printf("f2(x) = ((7/4)*x^3) - ((4/5)*x) + x*e^(3*tg*x)\n\n");//z-->f2
	printf("f3(x) = (7/8)*x^0,7\n\n");//t-->>f3
	printf("-----------------------------------------------------------------\n");

	printf("Ââåä³òü çíà÷åííÿ äëÿ ïàðàìåòðà õ:\n\n");
	scanf_s("%f", &x);

	printf("Ââåä³òü çíà÷åííÿ äëÿ ïàðàìåòðà a:\n\n");
	scanf_s("%f", &a);
	
	double y = (sqrt(log10(x) + n)) / (n * x + a - n1) + cos(fabs(x - n1)) / sin(fabs(x - n1)); //y-->f1
	double z = 1.75 * pow(x, 3) - 0.8 * x + x * exp(-3 * tan(x)); 
	double t = (double)0.875 * pow(x, 0.7); 
	
	printf("f1(x,a) = ((ln(x)+3)^(1/2))/(3*x + a - 4) + (ctg(|x-4|))=%.5f\n\n", y);
	printf("f2(x) = ((7/4)*x^3) - ((4/5)*x) + x*e^(3*tg*x)=%.5f\n\n", z);
	printf("f3(x) = (7/8)*x^0,7=%.5f\n\n", t);
 
	temp = y;
	y = z;
	z = t;
	t = temp;
	printf("\n Ïåðåïðèñâîºíí³ çíà÷åííÿ:\n\n y=%f \n z=%f \n t=%f \n\n", y, z, t);

	system("pause & cls");
	return 0;
}
