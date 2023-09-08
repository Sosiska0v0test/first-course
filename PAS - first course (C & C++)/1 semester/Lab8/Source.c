//����������� ������ �8 "��������� �������� ���������"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void vvid(double* x, double* eps, int* ki);
double fiter(double x, double eps, int ki, int* n);
double ftoch(double x);
void vyvid(int ki, double s, double f, int n);
int main() {
	double x, //����� �
		eps,  //�������� �������
		s,    //���� ����
		f;    //�������� �������
	int ind,  //���������
		n,    //������� ��������
		ki;   //�������� ������� �����
	char vidp; // ³������ ����������� �� ? �� ����� ��������� �������� �� ���
	system("chcp 1251 & cls");
	do {
		printf("\n�������: f(x) = e^x - 1\n");
		printf("��� E: (x^(n+1))/(n+1)!  ��� x � [-10; 10]\n");
		vvid(&x, &eps, &ki);
		s = fiter(x, eps, ki, &n, &s);
		f = ftoch(x);
		vyvid(ki, s, f, n);
		printf("\n������������ ������ (Y - ���)? ");
		while ((vidp = getchar()) == ' ' || vidp == '\n' || vidp == '\t');
		fseek(stdin, 0, SEEK_END);
	} while (vidp == 'Y' || vidp == 'y' || vidp == '�' || vidp == '�');

	return 0;
}
//��������� �� �������, ��� ������ �� � ������� �������
void vvid(double* x, double* eps, int* ki) { //double* x - ������� �, double* eps - �������� �������� ����� ����
	//ki - ����������� �������� ������� ��������
	int ind; // ����� ��� �������� �������
	// ind -  �������� �����
	ind = 1;
	//�������� �
	while (ind) {
		printf(" ������ x ");
		scanf_s("%lf", x);
		fseek(stdin, 0, SEEK_END);
		if (*x < -10 || *x > 10) printf("\t������ �������� x\n");
		else ind = 0;
	}
	//�������� eps
	ind = 1;
	while (ind) {
		printf(" ������ eps ");
		scanf_s("%lf", eps);
		fseek(stdin, 0, SEEK_END);
		if (*eps <= 0) printf("\teps �� ���� >0\n");
		else ind = 0;
	}
	//�������� k�
	ind = 1;
	while (ind) {
		printf(" ������ k� ");
		scanf_s("%d", ki);
		fseek(stdin, 0, SEEK_END);
		if (*ki <= 0) printf("\t�������� ������� �������� �� ���� >0\n");
		else ind = 0;
	}
}//���������� ���������� ����������� ����
double fiter(double x, double eps, int ki, int* n)
//x, eps �� ki ����������� �� ��������� 
//��� ������������ � �����������
//int ki - ����������� ��������� ������� ��������
//n - ��� ��������� ������� ��������, 
//��� ���������� ������� �������� 
{
	double an, s; //an n-�� ���� ����, ����� ��� ���������� ���������� ����� ����
	//an ���������� �� �������. an �������� �����.
	//s - ���������� �� �������, �������� �����
	*n = 0;
	an = x; //������ ���� ����
	s = an;
	do {
		//���������� ���������� ����� ���� �� ����������� ��������
		(*n)++; //����� ��������(������������ �������)
		an *= x / (*n + 1);
		s += an;
	} while ((fabs(an) >= eps) && *n < ki); //����� ����������� ������
	return s;
}
//���������� �������
double ftoch(double x) { //�������� � ���������� �� ���������
	return exp(x) - 1;
}
void vyvid(int ki, double s, double f, int n) { //ki, s, f, n -  ����������� �� ���������
	//ki - ����������� ������� ��������
	//s - �������� �������, ���������� ��������
	//f - ����� �������� �������
	//n - ������� ��������
	if (n == ki)
		printf("��������� ���� ������� ��������\n");
	printf("\n���������:\n");
	printf("  ������� �������� n= %d\n", n);
	printf("  ��������� �������� ������� s= %0.9f\n", s);
	printf("  ����� �������� ������� f= %0.9f\n", f);
	printf("  ������� |f-s|= %0.9f\n", fabs(f - s));
}
