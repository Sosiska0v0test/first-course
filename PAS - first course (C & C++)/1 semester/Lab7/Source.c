//����������� ������ �7 "������������ ����������� ���������"
//������ �������, ����� ��-22, ������ �8.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {
	double x, //�������� �������
		eps, //�������
		an,  //n-�� ���� ����
		s,   //����
		f;   //�������� �������
	int k,   //�������� ������� ��������
		n,   //������� ��������� ��������
		ind; //���������
	char vidp;
	system("chcp 1251 & cls");
	printf("������� f = (e^x - 1)\n");
	printf("��� E(n=0... +00)(x^n+1)/(n+1)!) ��� � � [-10, 10]\n");
	//������� ������� ����� 
	do {
		//�������� �
		ind = 1;
		do {
			printf(" ������ x: ");
			scanf_s("%lf", &x);
			fseek(stdin, 0, SEEK_END); // ������� ������
			if (x < -10 || x > 10) printf("\t ������ �������� x(���� ��������)\n");
			else ind = 0;
		} while (ind);
		//��� �������
		ind = 1;
		do {
			printf("������ eps: ");
			scanf_s("%lf", &eps);
			fseek(stdin, 0, SEEK_END); // ������� ������
			if (eps <= 0) printf("\t ������ �������� eps (�� ���� ���� <=0)\n");
			else ind = 0;
		} while (ind);
		//�������� k
		ind = 1;
		do {
			printf("������ k: ");
			scanf_s("%d", &k);
			fseek(stdin, 0, SEEK_END); // ������� ������
			if (k <= 0) printf("\t ������ �������� k (�� ���� ���� <=0)\n");
			else ind = 0;
		} while (ind);
		//���������� �������� ����������� ����
		n = 0;
		an = x; //������ ���� ����
		s = an;
		do {
			n++;
			an *= x / (n + 1); // ������������ ������� ���������
			s += an;
		} while (fabs(an) >= eps && n < k);
		//��������� ����������
		if (n == k)
			printf("��������� ���� ������� ��������\n");
		printf("���������: \n");
		printf("ʳ������ �������� n = %d\n", n);
		printf("��������� �������� ������� s=%0.9f\n", s);
		//���������� �������� �������
		f = exp(x) - 1;
		printf("����� �������� ������� f = %0.9f\n", f);
		printf("������� |f-s| = %0.9f\n", fabs(f - s));
		fseek(stdin, 0, SEEK_END); // ������� ������
		printf(" ���������� ������ ( Y - ���)?");
		while ((vidp = getchar()) == ' ' || vidp == '\n' || vidp == '\t');// ������� ��������� �������
		//� ��������� ������
		fseek(stdin, 0, SEEK_END);// ��� �������� ������ �� ����� ����������
	} while (vidp == 'Y' || vidp == 'y' || vidp == 'T' || vidp == '�');// � ����������� ������� � �� �
	printf("\n\n");
	system("pause & cls");
	return 0;
}

