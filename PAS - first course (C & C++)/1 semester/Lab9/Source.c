//����������� ������ �9 "��������� ���������"
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
	double eps,  // �������� �������� ��������
		x,       // ����� �
		an,      // ����� ��� ���������� �������
		f,		 // ����� �������� �������
		s;       // �������� ���� (���������)
	int k,       // ������ �����
		//ind,   // ����� ��� �������� ����������� ����� �����
		n;       // �������� ������� ����������� ��������� 
	char vidp;   // ����� ��� ���������� ��������� ������
	system("chcp 1251 & cls");
	do {
		printf("�������:  e^x - 1\n");
		printf("��� � :  (x^(n+1))/(n+1)!\n");
		vvid_x(&x);
		vvid_eps(&eps);
		vvid_k(&k);
		s = fiter(x, eps, k, &n);
		f = ftoch(x);
		vyvid(k, s, f, n);
		printf("\n������������ ������ (Y - ���)? ");
		while ((vidp = getchar()) == ' ' || vidp == '\n' || vidp == '\t');
		fseek(stdin, 0, SEEK_END);
	} while (vidp == 'Y' || vidp == 'y' || vidp == '�' || vidp == '�');
	printf("\n\n");
	system("pause");
	return 0;
}
/* �������� �������� x */
void vvid_x(double* x) {
	printf(" ������ x ");   //x - �������� �����
	scanf_s("%lf", x);
	fseek(stdin, 0, SEEK_END);
	if (*x < -10 || *x > 10) {
		printf("\t������ �������� x\n");
		vvid_x(x);
	}
}
/* �������� �������� eps */
void vvid_eps(double* eps) {
	printf(" ������ eps ");  //�������� �����
	scanf_s("%lf", eps);
	fseek(stdin, 0, SEEK_END);
	if (*eps <= 0) {
		printf("\teps �� ���� >0\n");
		vvid_eps(eps);
	}
}
/* �������� �������� k */
void vvid_k(int* k) {
	printf(" ������ k ");    //������� �����
	scanf_s("%i", k);
	fseek(stdin, 0, SEEK_END);
	if (*k < 0) {
		printf("\t�������� ������� �������� �� ���� >0\n");
		vvid_k(k);
	}
}
/* ���������� ����������� �������� ������� sin(x) */
double fiter(double x, double eps, int k, int* n) {
	*n = 0; // ��� n=0 ������ ���� ���� a0=x, 
	// ��������� �������� ���� s=a0=x,
	return x + recursive(n, x, x, eps, k);
}
// ���������� ���������� �������� �������
double recursive(int* n, double x, double an, double eps, int k) {
	double s; // �������� ��������� ����������
	(*n)++;   // ����� �������� (������������ �������)
	/* ������������ ������� ����� ���� */
	an *= x / (*n + 1);
	if (fabs(an) >= eps && (*n) < k)     // ����� ����������� ������
		s = recursive(n, x, an, eps, k); // ���������� ���������
	else
		s = 0; // ��� ��� ���������� �������� ��������� ����� an
	return s + an;
}
double ftoch(double x) {
	return exp(x) - 1;
}
//��������� ���������� 
void vyvid(int k, double s, double f, int n) {
	if (n == k)
		printf("��������� ���� ������� ��������\n");
	printf("\n���������:\n");
	printf("  ������� �������� n = %d\n", n);
	printf("  ��������� �������� ������� s = %0.9f\n", s);
	printf("  ����� �������� ������� f = %0.9f\n", f);
	printf("  ������� |f-s|= %0.9f\n", fabs(f - s));
}
