
#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int main() {
    system("chcp 1251 & cls");
    double x1, x2, h, 
        a, b, x, 
        an, s, 
        res; 
    double eps = 1e-22; 
    char r1[20] = "-------------------", 
        r2[20] = "|   x   |   f(x)   ", 
        r3[20] = "|       |          ", 
        rline[78] = "";
    int ind, 
        i, 
        k,
        n;
    printf("Òàáóëþâàííÿ ôóíêö³¿:\n");
    printf("\tf(x)=ln(x)+3 / x-a * s + sqrt(b-x) \n");
    ind = 1;
    do {
        printf("Âêàæ³òü ê³ëüê³ñòü êîëîíîê òàáëèö³ (â³ä 1 äî 4):");
        scanf_s("%d", &k);
        while (getchar() != '\n'); 
        if (k >= 1 && k <= 4) ind = 0;
        else printf("***Íåïðàâèëüíà ê³ëüê³ñòü êîëîíîê\n");
    } while (ind);
    ind = 1;
    do {
        printf("Âêàæ³òü\n \tÏðîì³æîê õ1, õ2:");
        scanf_s("%lf", &x1);
        scanf_s("%lf", &x2);
        while (getchar() != '\n'); 
        if (x1 < x2) ind = 0;
        else printf("***Ïîìèëêà x1>x2\n");
    } while (ind);
    ind = 1;
    do {
        printf("\têðîê h:");
        scanf_s("%lf", &h);
        while (getchar() != '\n'); 
        if (h <= 0 || h > (x2 - x1)) { printf("***Ïîìèëêà: h>x2-x1 àáî h<=0\n"); }
        else  ind = 0;
    } while (ind);
    printf("\tçíà÷åííÿ ïàðàìåòð³â a i b: ");
    scanf_s("%lf %lf", &a, &b);
    while (getchar() != '\n'); 
   
    for (i = 1; i <= k; i++) {
        printf("%s", r1);
    }
    printf("-\n");
    for (i = 1; i <= k; i++) {
        printf("%s", r2);
    }
    printf("|\n");
    for (i = 1; i <= k; i++) {
        printf("%s", r1);
    }
    printf("-\n");
    
    x = x1; i = 0;
    while (x <= x2 + eps) {
        printf("|%6.2f ", x);
        if (x < eps || fabs(x - a) < eps || b - x < 0) {
            printf("| íå âèçí  ");
        }
        else {
            s = 0;
            an = 4;
            for (n = 3; n <= 5; n++) {
                an *= 2;
                s += (an + x) / (n - 2);
            }
            res = (log(x) + 3) / (x - a) * s + sqrt(b - x);
            if (fabs(res) > 9999.99) {
                printf(("|  ïåðåï   "));
            }
            else {
                printf("| %8.2f ", res);
            }
        }
        i++;
        if (i % k == 0) {
            printf("|\n");
        }
        x += h;
    }
    if (i % k != 0) {
        while (i % k != 0) {
            printf("%s", r3);
            i++;
        }
        printf("|\n");
    }
    for (i = 0; i < k; i++) {
        printf("%s", r1);
    }
    printf("-\n\n");
    system("pause & cls");
    return 0;
}
