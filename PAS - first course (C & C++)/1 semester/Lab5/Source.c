//����������� ������ �5. ��������� �������� ���� 
#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
int main()
{
	float x,
		y,
		a, b;
	int ind;
	system("chcp 1251 & cls");
	/* ��������� ������� ������� �� ����� */
	printf("    = sin(x)       ��� x [-1,6)\n");
	printf("f = 3x^2+bx        ��� x=6\n");
	printf("    = ln(ax-3b)    ��� x (6,8)\n");
	/* �������� ������� ����� */
	printf("\n������ �������� a ");
	scanf_s("%f", &a);
	printf("������ �������� b ");
	scanf_s("%f", &b);
	printf("������ �������� x ");
	scanf_s("%f", &x);
	ind = 0;
	/* ���������� �������� ������� */
	/* �������� � ������ ���� �������� */
	if ((x <= -1) || (x >= 8))
	{
		printf("������� �� ���������");
	}
	/* ������ �������. ��� �� �������� */
	if (x >= -1 && x < 6)
	{
		y = sin(x);
		ind = 1;
	}
	/* ������ �������. ������������ ���� */
	if (x == 6)
	{
		y = x * (3 * x + b);
		ind = 1;
	}
	// ����� �������. ��� ��������
	if ((x > 6) && (x < 8) && (a * x - 3 * b <= 0))
	{
		printf("ϳ������������� ����� ������ ��� ������� ����");
	}
	// ����� �������. ��� �� ��������
	if ((x > 6) && (x < 8) && (a * x - 3 * b > 0))
	{
		y = log(a * x - 3 * b);
		ind = 1;
	}
	/* �������� � ������ ���� �������� */
	if (ind)
		printf("f(%4.2f)=%6.3lf", x, y);
	/* �������� ���� ��������� */
	printf("\n\n");
	system("pause & cls");
	return 0;
}
